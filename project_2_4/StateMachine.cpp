#include "StateMachine.h"

StateMachine::StateMachine() : time(0), nsColor(LightColor::RED), ewColor(LightColor::RED) { }


LightOutputs StateMachine::update(LightInputs in) {

	if(nsColor == LightColor::RED && ewColor == LightColor::RED) { //base state
		if(time < 0) { //lights haven't been red for long enough
			time++;
		} else { //lights have been red for long enough, decide which direction to make green
			if(in.car_sensor_n || in.car_sensor_s) {
				nsColor = LightColor::GREEN;
				time = 0;
			} else {
				ewColor = LightColor::GREEN;
				time = 0;
			}
		}

	} else {
		if(nsColor == LightColor::GREEN) {
			if(time < 4) {
				time++;
			} else {
				nsColor = LightColor::YELLOW;
				time = 0;
			}
		} else if(nsColor == LightColor::YELLOW) {
			if(time < 1) {
				time++;
			} else {
				nsColor = LightColor::RED;
				time = 0;
			}
		} else if(ewColor == LightColor::GREEN) {
			if(time < 4) {
				time++;
			} else {
				ewColor = LightColor::YELLOW;
				time = 0;
			}
		} else {
			if(time < 1) {
				time++;
			} else {
				ewColor = LightColor::RED;
				time = 0;
			}
		}
	}

	//formulate output
	LightOutputs out = {false, false, false, false, false, false};


	//CHANGE THIS TO LIGHTOUTPUTS FORMAT
	//ns lights
	if(nsColor == LightColor::RED) {
		out.red_ns = true;
	} else if(nsColor == LightColor::YELLOW) {
		out.yellow_ns = true;
	} else {
		out.green_ns = true;
	}

	//ew lights
	if(ewColor == LightColor::RED) {
		out.red_ew = true;
	} else if(ewColor == LightColor::YELLOW) {
		out.yellow_ew = true;
	} else {
		out.green_ew = true;
	}

	return out;
}