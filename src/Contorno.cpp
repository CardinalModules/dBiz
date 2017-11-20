///////////////////////////////////////////
//
//  Based on Befaco Rampage
//
//
/////////////////////////////////////////////

#include "dBiz.hpp"
#include "dsp/digital.hpp"

struct Contorno : Module {
	enum ParamIds {
		RANGE_PARAM,
		TRIGG_PARAM=RANGE_PARAM+4,
		CYCLE_PARAM = TRIGG_PARAM+4,
		SHAPE_PARAM= CYCLE_PARAM+4,
		RISE_PARAM = SHAPE_PARAM+4,
		FALL_PARAM = RISE_PARAM+4,
		NUM_PARAMS = FALL_PARAM+4
	};
	enum InputIds {
		TRIGG_INPUT,
		CYCLE_INPUT = TRIGG_INPUT+4,
		RISE_INPUT = CYCLE_INPUT+4,
		FALL_INPUT = RISE_INPUT+4,
		IN_INPUT = FALL_INPUT+4,
		NUM_INPUTS = IN_INPUT+4
	};
	enum OutputIds {
		OUT_OUTPUT,
		NUM_OUTPUTS = OUT_OUTPUT+4
	};

	enum LightIds
	{
		TRIGG_LIGHT,
		CYCLE_LIGHT=TRIGG_LIGHT+4,
		RISE_LIGHT=CYCLE_LIGHT+4,
		FALL_LIGHT = RISE_LIGHT + 4,
		NUM_LIGHTS = FALL_LIGHT + 4,
	};

	float out[4] {};
	//float in [4] {};
	//float shape [4] {};
	//float rise[4] {};
	//float slew[4] {};
	//float fall[4] {};
	bool gate[4] = {};

	
	SchmittTrigger trigger[4];
	PulseGenerator endOfCyclePulse[4];

	Contorno() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS,NUM_LIGHTS) {
	for (int c = 0; c < 4; c++) {
			trigger[c].setThresholds(0.0, 4.0);
		}
	}
	void step() override;
};

static float shapeDelta(float delta, float tau, float shape) {
	float lin = sgnf(delta) * 10.0 / tau;
	if (shape < 0.0) {
		float log = sgnf(delta) * 40.0 / tau / (fabsf(delta) + 1.0);
		return crossf(lin, log, -shape * 0.95);
	}
	else {
		float exp = M_E * delta / tau;
		return crossf(lin, exp, shape * 0.90);
	}
}

void ::Contorno::step() {

	for (int c=0;c<4;c++)
	{
	
	float in = inputs[IN_INPUT + c].value;
		if (trigger[c].process(params[TRIGG_PARAM + c].value * 10.0 + inputs[TRIGG_INPUT + c].value)) {
			gate[c] = true;
		}
		if (gate[c]) {
			in = 10.0;
		}

		float shape = params[SHAPE_PARAM + c].value;
		float delta = in - out[c];

		// Integrator
		float minTime;
		switch ((int) params[RANGE_PARAM + c].value) {
			case 0: minTime = 1e-2; break;
			case 1: minTime = 1e-3; break;
			default: minTime = 1e-1; break;
		}

		bool rising = false;
		bool falling = false;

		if (delta > 0) {
			// Rise
			float riseCv = params[RISE_PARAM + c].value + inputs[RISE_INPUT + c].value / 10.0;
			riseCv = clampf(riseCv, 0.0, 1.0);
			float rise = minTime * powf(2.0, riseCv * 10.0);
			out[c] += shapeDelta(delta, rise, shape) / engineGetSampleRate();
			rising = (in - out[c] > 1e-3);
			if (!rising) {
				gate[c] = false;
			}
		}
		else if (delta < 0) {
			// Fall
			float fallCv = params[FALL_PARAM + c].value + inputs[FALL_INPUT + c].value / 10.0;
			fallCv = clampf(fallCv, 0.0, 1.0);
			float fall = minTime * powf(2.0, fallCv * 10.0);
			out[c] += shapeDelta(delta, fall, shape) / engineGetSampleRate();
			falling = (in - out[c] < -1e-3);
			if (!falling) {
				// End of cycle, check if we should turn the gate back on (cycle mode)
				endOfCyclePulse[c].trigger(1e-3);
				if (params[CYCLE_PARAM + c].value * 10.0 + inputs[CYCLE_INPUT + c].value >= 4.0) {
					gate[c] = true;
				}
			}
		}
		else {
			gate[c] = false;
			lights[CYCLE_LIGHT+c].value = 0.0;
		}

		if (!rising && !falling) {
			out[c] = in;
		}

		if (params[CYCLE_PARAM + c].value ==1.0) lights[CYCLE_LIGHT+c].value = 1.0;
		
		lights[RISE_LIGHT + c].value = (rising ? 1.0 : 0.0);
		lights[FALL_LIGHT + c].value = (falling ? 1.0 : 0.0);
		outputs[OUT_OUTPUT + c].value = out[c];
		}
		
}


ContornoWidget::ContornoWidget() {

	::Contorno *module = new ::Contorno();
	setModule(module);
	box.size = Vec(15*17, 380);

	{
		SVGPanel *panel = new SVGPanel();
		panel->box.size = box.size;
		panel->setBackground(SVG::load(assetPlugin(plugin, "res/Contorno.svg")));
		addChild(panel);
	}

	addChild(createScrew<ScrewBlack>(Vec(15, 0)));
  	addChild(createScrew<ScrewBlack>(Vec(box.size.x-30, 0)));
  	addChild(createScrew<ScrewBlack>(Vec(15, 365)));
  	addChild(createScrew<ScrewBlack>(Vec(box.size.x-30, 365)));

int space = 64;

	
 
for (int i=0;i<4;i++)
{

	addParam(createParam<MCKSSS>(Vec(space*i+52, 25), module, Contorno::RANGE_PARAM+i, 0.0, 2.0, 0.0));
	addParam(createParam<LEDB>(Vec(space*i+7, 297), module, Contorno::CYCLE_PARAM+i, 0.0, 1.0, 0.0));
	addChild(createLight<BigLight<BlueLight>>(Vec(space * i + 7, 297), module, Contorno::CYCLE_LIGHT + i));
	addInput(createInput<PJ301MLPort>(Vec(35+space*i, 294), module, ::Contorno::CYCLE_INPUT+i));

	addParam(createParam<RoundWhy>(Vec(space*i+12.5, 39), module, ::Contorno::SHAPE_PARAM+i, -1.0, 1.0, 0.0));

	addParam(createParam<SlidePot>(Vec(space*i+10, 100), module, ::Contorno::RISE_PARAM+i, 0.0, 1.0, 0.0));
	addParam(createParam<SlidePot>(Vec(space*i+40, 100), module, ::Contorno::FALL_PARAM+i, 0.0, 1.0, 0.0));

	addInput(createInput<PJ301MCPort>(Vec(space*i+5, 220), module, ::Contorno::RISE_INPUT+i));
	addInput(createInput<PJ301MCPort>(Vec(space*i+35, 220), module, ::Contorno::FALL_INPUT+i));

	addInput(createInput<PJ301MLPort>(Vec(space*i+35, 255), module, ::Contorno::TRIGG_INPUT+i));
	addParam(createParam<BPush>(Vec(space * i + 5, 255), module, ::Contorno::TRIGG_PARAM + i, 0.0, 1.0, 0.0));
	addInput(createInput<PJ301MIPort>(Vec(space*i+5, 335), module, ::Contorno::IN_INPUT+i));
	addOutput(createOutput<PJ301MOPort>(Vec(space*i+35, 335), module, ::Contorno::OUT_OUTPUT+i));


	addChild(createLight<SmallLight<RedLight>>(Vec(space*i+15, 212), module, Contorno::RISE_LIGHT+i));
	addChild(createLight<SmallLight<RedLight>>(Vec(space*i+45, 212), module, Contorno::FALL_LIGHT+i));

	//addParam(createParam<CKD62>(Vec(5+space*i,300 ), module, Contorno::LOOP_PARAM + i, 0.0, 1.0, 0.0));
    //addChild(createLight<HugeLight<CyanLight>>(Vec(7+space*i,302), module, Contorno::BUTTON_LIGHTS + i));
}

}