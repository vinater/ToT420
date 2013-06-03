#include <AFMotor.h>

/*
AF_DCMotor motorname(portnum, freq)

    port num - selects which channel (1-4) of the motor controller the motor will be connected to
    freq - selects the PWM frequency.  If no frequency is specified, 1KHz is used by default.

        Frequencies for channel 1 & 2 are:

            MOTOR12_64KHZ
            MOTOR12_8KHZ
            MOTOR12_2KHZ
            MOTOR12_1KHZ

        Frequencies for channel 3 & 4 are:

            MOTOR34_64KHZ
            MOTOR34_8KHZ
            MOTOR34_1KHZ

ex:

    AF_DCMotor motor4(4); // define motor on channel 4 with 1KHz default PWM
    AF_DCMotor left_motor(1, MOTOR12_64KHZ); // define motor on channel 1 with 64KHz PWM


*/

/*
setSpeed(speed)

    Sets the speed of the motor.

Parameters:

      speed- Valid values for 'speed' are between 0 and 255 with 0 being off and 255 as full throttle.

	       motor1.setSpeed(255); // Set motor 1 to maximum speed
    motor4.setSpeed(127); // Set motor 4 to half speed 

*/

/*
run(cmd)

    Sets the run-mode of the motor.

Parameters:

    cmd - the desired run mode for the motor

    Valid values for cmd are:

        FORWARD - run forward (actual direction of rotation will depend on motor wiring)
        BACKWARD - run backwards (rotation will be in the opposite direction from FORWARD)
        RELEASE - Stop the motor.  This removes power from the motor and is equivalent to setSpeed(0).  The motor shield does not implement dynamic breaking, so the motor may take some time to spin down

    motor.run(FORWARD);
    delay(1000); // run forward for 1 second
    motor.run(RELEASE);
    delay(100); // 'coast' for 1/10 second
    motor.run(BACKWARDS); // run in reverse
*/
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR12_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motor4(4, MOTOR12_64KHZ); // create motor #4, 64KHz pwm

void setup() {
//  Serial.begin(9600);           // set up Serial library at 9600 bps
// Serial.println("Motor test!");
  
motor1.setSpeed(200);     // set the speed to 200/255
motor2.setSpeed(200);     // set the speed to 200/255
motor3.setSpeed(200);     // set the speed to 200/255
motor4.setSpeed(200);     // set the speed to 200/255

}


void loop() {
// Serial.print("tick");
//  Serial.print("tock");
//  Serial.print("tack");

motor1.run(FORWARD);      // turn it on going forward
delay(1000);
motor1.run(BACKWARD);     // the other way
delay(1000);
motor1.run(RELEASE);      // stopped
delay(1000);

motor2.run(FORWARD);      // turn it on going forward
delay(1000);
motor2.run(BACKWARD);     // the other way
delay(1000);
motor2.run(RELEASE);      // stopped
delay(1000);

motor3.run(FORWARD);      // turn it on going forward
delay(1000);
motor3.run(BACKWARD);     // the other way
delay(1000);
motor3.run(RELEASE);      // stopped
delay(1000);

motor4.run(FORWARD);      // turn it on going forward
delay(800);
motor4.run(BACKWARD);     // the other way
delay(1000);
motor4.run(RELEASE);      // stopped
delay(1000);

motor1.run(FORWARD);      // turn it on going forward
motor2.run(FORWARD);      // turn it on going forward
motor3.run(FORWARD);      // turn it on going forward
motor4.run(FORWARD);      // turn it on going forward
delay(1000);
motor1.run(BACKWARD);     // the other way
motor2.run(BACKWARD);     // the other way
motor3.run(BACKWARD);     // the other way
motor4.run(BACKWARD);     // the other way
delay(1000);
motor1.run(RELEASE);      // stopped
motor2.run(RELEASE);      // stopped
motor3.run(RELEASE);      // stopped
motor4.run(RELEASE);      // stopped

delay(10000000);

}