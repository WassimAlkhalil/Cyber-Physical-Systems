#include <iostream>
#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

/* 
 * Main function for an EV3 robot program which controls two motors based on the state of a touch sensor.
 * The program executes in a non-blocking manner, allowing for other operations to be performed concurrently.
 * The robot will start moving when the touch sensor is initially pressed and stop when it is pressed again.
 * If the robot encounters an obstacle, the touch sensor will trigger a stop to the movement.
 */

int main () {
    // Initialize the touch sensor on input port 1
    touch_sensor touch = touch_sensor(INPUT_1); 

    // Initialize motors on output ports A and B as large motors
    motor leftMotor = motor(OUTPUT_A, motor::motor_large); 
    motor rightMotor = motor(OUTPUT_B, motor::motor_large);

    // Prompt displayed to indicate exit mechanism
    std::cout<<"Press main button to leave ..."<<std::endl;
    
    // Control flags for the robot's state
    bool active = 0;
    bool pressed = 0;
    bool wasPressed = 0;
    
    // set_duty_cycle_sp() is used to set the speed of the motor
    leftMotor.set_duty_cycle_sp(60);
    rightMotor.set_duty_cycle_sp(60);
    
    // Main loop continues until the enter button is pressed
    do{
         // Check the current state of the touch sensor
        pressed = touch.is_pressed();
        
        // Toggle active state only on state change from unpressed to pressed
        if(pressed && !wasPressed) {
            active = !active;
        }

        // Update wasPressed to the current state
        wasPressed = pressed;

        // Control motors based on the active state
        if(active){
            // Run both motors directly using the preset duty cycle
            leftMotor.run_direct();
            rightMotor.run_direct();
            cout << "Status: Active" << endl;
        } else {
            // Stop both motors
            leftMotor.stop();
            rightMotor.stop();
            cout << "Status: Standby" << endl;
        }
        
    } while(!button::enter.pressed());

    return 0;
}

