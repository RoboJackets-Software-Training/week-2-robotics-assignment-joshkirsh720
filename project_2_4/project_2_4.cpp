#include <iostream>  // Gives us access to std::cin and std::cout
#include <string>  // Gives us access to std::string and std::getline()

#include "StateMachine.h"

// TODO Define your light controller state machine class here

int main()
{
    // TODO Initialize your state machine class here
    StateMachine controller;

    int t = 0;
    while(true)
    {
        std::string input;
        std::getline(std::cin, input);
        if(input.size() != 2)
            break;

        // TODO Parse the input digits
        LightInputs in;
        in.time = t;
        in.car_sensor_n = (input[0] == '1');
        in.car_sensor_s = (input[1] == '1');

        // TODO Update your state machine based on input
        LightOutputs out = controller.update(in);

        // TODO Output your state machine's light controls to std::cout
        std::cout << out.red_ns << out.yellow_ns << out.green_ns << out.red_ew << out.yellow_ew << out.green_ew << std::endl;

        t++;
    }
    return 0;
}
