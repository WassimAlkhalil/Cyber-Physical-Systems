# Programming the EV3 Robot Projects

## Overview
This repository contains three projects for programming the LEGO Mindstorms EV3 robot. Each project explores different programming environments to control the EV3 robot, namely C++, LabVIEW, and Matlab/Simulink.

## Projects

### 1. EV3 Robot Programming in C++
In this project, the EV3 robot is programmed using C++ with the ev3dev library. The goal is to make the robot autonomously drive towards and follow a moving object.

#### Tasks:
2. **Drive on Command**: Implement a program that allows the robot to start and stop driving when the touch sensor is pressed.
3. **Modeling**: Design state machines and flow diagrams for object identification and robot control.
4. **Object Identification**: Implement a program to detect the nearest object using the ultrasonic sensor.
5. **Tracking a Moving Object**: Program the robot to follow the nearest moving object smoothly.

#### Key Classes and Functions:
- `motor(PORT, MOTOR_TYPE)`: Controls the EV3 motors.
- `touch_sensor(PORT)`: Reads the state of the touch sensor.
- `ultrasonic_sensor(PORT)`: Reads distance measurements from the ultrasonic sensor.

### 2. EV3 Robot Programming in LabVIEW
This project uses LabVIEW, a graphical programming environment, to program the EV3 robot. The focus is on implementing a line-following algorithm with distance control.

#### Tasks:
2. **Light Sensor**: Display light sensor values and perform calibration.
3. **Driving on a Line**: Implement a controller for line-following based on the calibrated values.
4. **Completing the Functionality**: Extend the program to meet all functional requirements, including state transitions and error handling.
5. **Report**: Document the algorithms, implementation, and any issues encountered.

#### Functional Description:
- The robot follows a line and maintains a minimum distance of 20 cm from the robot ahead.
- Calibration of color values is performed at startup.
- State transitions between Ready and Active states are controlled by the touch sensor.
- Error handling is implemented for scenarios where the line edge is lost.

### 3. EV3 Robot Programming with Matlab/Simulink
In this project, Matlab/Simulink is used to equip the EV3 robot with similar functionality as described in the first project, but using a PI-controller.

#### Tasks:
1. **Toggling between Modes**: Use the touch sensor to toggle the robot between Standby and Active modes.
2. **Object Detection**: Read values from the ultrasonic sensor and motor encoder to plot distance and angle in an X-Y diagram.
3. **Tracking a Moving Object**: Implement object detection and control algorithms to track and follow a moving object.
4. **Controller**: Implement PI-controllers for distance and angle control, simulate various scenarios, and adjust controller parameters.
5. **Presentation**: Refine the control system and demonstrate the robot's tracking capability.

#### Key Concepts:
- **Simulink Blocks**: Use blocks like Constant, Switch, Integrator, and Saturation to build the control system.
- **Feedback Control Loop**: Implement PI-controllers to maintain the desired distance and angle.
- **Simulation**: Test the control system in a simulated environment before deploying it to the robot.

## Requirements
- LEGO Mindstorms EV3 robot kit
- EV3dev OS (for C++ project)
- LabVIEW software
- Matlab/Simulink with EV3 support package
