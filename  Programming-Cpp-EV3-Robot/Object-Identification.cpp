#include <iostream>
#include "ev3dev.h"

using namespace std;
using namespace ev3dev;

int main () {
    // Initialize sensors and motors with specific ports.
    touch_sensor touch = touch_sensor(INPUT_1); 
    motor leftMotor = motor(OUTPUT_A, motor::motor_large); 
    motor rightMotor = motor(OUTPUT_B, motor::motor_large);
    motor ultrasonicMotor = motor(OUTPUT_D, motor::motor_medium);
    ultrasonic_sensor ultrasonic = ultrasonic_sensor(INPUT_4);
    
    // Greeting message displayed at the start of the program.
    std::cout<<"Press main button to leave ..."<<std::endl;
    
    // Initial state for control flags and sensor readings.
    bool active = false, pressed = false;
    bool wasPressed = false;
    float distance = 0.0;
    float pos = 0.0;

    // set_duty_cycle_sp() is used to set the speed of the motor
    leftMotor.set_duty_cycle_sp(60);          
    rightMotor.set_duty_cycle_sp(60);
    
    // Main control loop, continues until the enter button is pressed.
    do{
        // Check the current state of the touch sensor.
        pressed = touch.is_pressed();

        // Toggle active state on rising edge of the touch sensor signal.
        if(pressed && !wasPressed) {
            active = !active;
        }
        // Update the touch sensor state.
        wasPressed = pressed;

        // Read the current distance from the ultrasonic sensor.
        distance = ultrasonic.distance_centimeters();
        // Read the current position of the ultrasonic motor.
        pos = ultrasonicMotor.position();

        // Control logic for the motors based on the active state.
        if(active){
        leftMotor.run_direct();
        rightMotor.run_direct();

        cout << "Status: Active" << endl;
        } else {
            leftMotor.stop();
            rightMotor.stop();

            cout << "Status: Standby" << endl;
        }

        // Position and speed settings for the ultrasonic motor.
        ultrasonicMotor.set_position_sp(90);
        ultrasonicMotor.set_speed_sp(20);
        ultrasonicMotor.run_to_abs_pos();

        // Output the sensor readings to standard output.
        std::cout<<"Distance = "<<distance<<std::endl;
        std::cout<<"Position = "<<pos<<std::endl;
        
    } while(!button::enter.pressed());

    return 0;
}