#pragma once

enum class LightColor {
	RED,
	YELLOW,
	GREEN
};

struct LightOutputs {
  bool red_ns;
  bool yellow_ns;
  bool green_ns;
  bool red_ew;
  bool yellow_ew;
  bool green_ew;
};

struct LightInputs {
  int time;
  bool car_sensor_n;
  bool car_sensor_s;
};


class StateMachine {
public:
	StateMachine();
	LightOutputs update(LightInputs in);


private:
	int time;
	LightColor nsColor, ewColor;
};