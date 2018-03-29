#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in3,    gyroSens,       sensorGyro)
#pragma config(Sensor, dgtl1,  ,               sensorDigitalOut)
#pragma config(Sensor, dgtl2,  pistonTwo,      sensorDigitalOut)
#pragma config(Sensor, dgtl3,  pistonOne,      sensorDigitalOut)
#pragma config(Sensor, dgtl4,  gyro,           sensorDigitalIn)
#pragma config(Sensor, dgtl12, ,               sensorTouch)
#pragma config(Sensor, I2C_1,  leftDrive,      sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  rightDrive,     sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  mobileCapture,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  liftHelp,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           liftRight,     tmotorVex393HighSpeed_HBridge, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port2,           mobileCapture1, tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port6,           backRight,     tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393_MC29, openLoop, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port8,           frictionDrum2, tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           mobileCapture2, tmotorVex393TurboSpeed_MC29, openLoop, driveRight, encoderPort, I2C_4)
#pragma config(Motor,  port10,          liftLeft,      tmotorVex393HighSpeed_HBridge, openLoop, encoderPort, I2C_4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#define C1LX vexRT[Ch4]
#define C1LY vexRT[Ch3]
#define C1RX vexRT[Ch1]
int Program;
int varU;



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton()
{
	//// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	//// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	//bStopTasksBetweenModes = true;
	////Leave this value alone
	//int lcdScreenMin = 1;
	////This keeps track of which program you want to run
	//int lcdScreen = 1;
	////Change this value to be the maximum number of programs you want on the robot
	//int lcdScreenMax = 4;
	////Turns on the Backlight
	//bLCDBacklight = true;

	////Copied from someone's sample code because the documentation for RobotC won't tell me anything useful
	////These should logically work, but I'm not 100% sure
	//const short leftButton = 1;
	//const short centerButton = 2;
	//const short rightButton = 4;

	//while (vrDisabled == 1) { //Ensures this code will run ONLY when the robot is disabled
	//	if (nLCDButtons == leftButton) { //Scrolls to the left
	//		if (lcdScreenMin == lcdScreen) {
	//			lcdScreen = lcdScreenMax;
	//			wait1Msec(250);
	//			} else {
	//			lcdScreen --;
	//			wait1Msec(250);
	//		}
	//	}
	//	if (nLCDButtons == rightButton) { //Scrolls to the right
	//		if (lcdScreenMax == lcdScreen) {
	//			lcdScreen = lcdScreenMin;
	//			wait1Msec(250);
	//			} else {
	//			lcdScreen++;
	//			wait1Msec(250);
	//		}
	//	}
	//	if (lcdScreen == 1 && Program != 1) {
	//		displayLCDCenteredString (0, "Program"); //Name the first program here
	//		displayLCDCenteredString (1, "1"); //Name the first program here
	//		if (nLCDButtons == centerButton) {
	//			Program = lcdScreen; //Sets the Program to the one on-screen
	//			displayLCDCenteredString (0, "Autonomous Has");
	//			displayLCDCenteredString (1, "Been Selected!");
	//			wait1Msec(1500);
	//		}
	//		} else if (lcdScreen == 1 && Program == 1) {
	//		displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
	//		displayLCDCenteredString (1, "[1]"); //So that while we're scrolling, we can have one marked
	//		} else if (lcdScreen == 2 && Program != 2) {
	//		displayLCDCenteredString (0, "Program"); //Name the second program here
	//		displayLCDCenteredString (1, "2"); //Name the second program here
	//		if (nLCDButtons == centerButton) {
	//			Program = lcdScreen; //Sets the Program to the one on-screen
	//			displayLCDCenteredString (0, "Autonomous Has");
	//			displayLCDCenteredString (1, "Been Selected!");
	//			wait1Msec(1500);
	//		}
	//		} else if (lcdScreen == 2 && Program == 2) {
	//		displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
	//		displayLCDCenteredString (1, "[2]"); //So that while we're scrolling, we can have one marked
	//		} else if (lcdScreen == 3 && Program != 3) {
	//		displayLCDCenteredString (0, "Program"); //Name the third program here
	//		displayLCDCenteredString (1, "3"); //Name the third program here
	//		if (nLCDButtons == centerButton) {
	//			Program = lcdScreen; //Sets the Program to the one on-screen
	//			displayLCDCenteredString (0, "Autonomous Has");
	//			displayLCDCenteredString (1, "Been Selected!");
	//			wait1Msec(1500);
	//		}
	//		} else if (lcdScreen == 3 && Program == 3) {
	//		displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
	//		displayLCDCenteredString (1, "[3]"); //So that while we're scrolling, we can have one marked
	//		} else if (lcdScreen == 4 && Program != 4) {
	//		displayLCDCenteredString (0, "Program"); //Name the fourth program here
	//		displayLCDCenteredString (1, "4"); //Name the fourth program here
	//		if (nLCDButtons == centerButton) {
	//			Program = lcdScreen; //Sets the Program to the one on-screen
	//			displayLCDCenteredString (0, "Autonomous Has");
	//			displayLCDCenteredString (1, "Been Selected!");
	//			wait1Msec(1500);
	//		}
	//		} else if (lcdScreen == 4 && Program == 4) {
	//		displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
	//		displayLCDCenteredString (1, "[4]"); //So that while we're scrolling, we can have one marked
	//	}
	//}

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//if(Program == 1){
	SensorValue[pistonOne] = 0;
	SensorValue[pistonTwo] = 0;
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	SensorValue[I2C_3] = 0;
	while((SensorValue[I2C_3] >= -720))
	{
		motor[liftLeft] = 125;
		motor[liftRight] = 125;
	}
	motor[liftLeft] = 80;
	motor[liftRight] = 80;
	wait1Msec(100);
	motor[frictionDrum2] = 10;

	//first forward to score preload
	while((SensorValue[I2C_1] <= 450))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

	//Pre-Load score
	SensorValue[pistonOne] = 1;
	SensorValue[pistonTwo] = 1;
	wait1Msec(100);
	wait1Msec(500);
	motor[frictionDrum2] = -127;
	wait1Msec(200);
	motor[frictionDrum2] = 0;
	wait1Msec(2000);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	//first backward to the back bar
	while((SensorValue[I2C_1] >= -280))
	{
		motor[frontLeft] = -60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = 60;
	}
	motor[liftLeft] = 80;
	motor[liftRight] = 80;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;



	//first turn to line up with the mobile base
	while((SensorValue[I2C_2] >= 115))
	{
		motor[frontLeft] = -30;
		motor[frontRight] = -30;
		motor[backRight] = 30;
		motor[backLeft] = 30;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	//extend mobile capture
	while(SensorValue[I2C_4] > -575){
		motor[mobileCapture1] = 100;
		motor[mobileCapture2] = 100;
	}

	motor[mobileCapture1] = 0;
	motor[mobileCapture2] = 0;
	wait1Msec(100);
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;


	//second forward to grab the mobile goal
	while((SensorValue[I2C_1] < 1000))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	motor[liftLeft] = 0;
	motor[liftRight] = 0;
	wait1Msec(600);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	wait1Msec(100);

	//second turn to correct
	while((SensorValue[I2C_2] <= -100))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

	motor[liftLeft] = 0;
	motor[liftRight] = 0;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	////thirdnforward tio grab the mobile goal
	//	while((SensorValue[I2C_2] >= -400)) {
	//		motor[frontLeft] 	= 60;
	//		motor[frontRight] = -60;
	//		motor[backLeft]		= -60;
	//		motor[backRight]	= 60;
	//	}

	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	//third forward to score the second cone
	while((SensorValue[I2C_1] <= 400))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	//retract mobile capture
	while(SensorValue[I2C_4] < -300){
		motor[mobileCapture1] = -100;
		motor[mobileCapture2] = -100;
	}
	motor[mobileCapture1] = 10;
	motor[mobileCapture2] = 10;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;

	//turn to align with the bar
	while((SensorValue[I2C_1] <= 1000))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	//motor[mobileCapture1] = 100;
	//motor[mobileCapture2] = 100;
	//wait1Msec(700);
	motor[mobileCapture1] = 0;
	motor[mobileCapture2] = 0;

	SensorValue[I2C_1] = 0;
	SensorValue[I2C_2] = 0;
	//fourth forward to get to the bar
	while((SensorValue[I2C_1] <= 1500))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = -60;
		motor[backRight] = 60;
		motor[backLeft] = -60;
	}
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;

	//back up to score
	while((SensorValue[I2C_1] <= 185))
	{
		motor[frontLeft] = 60;
		motor[frontRight] = 60;
		motor[backRight] = -60;
		motor[backLeft] = -60;
	}
	//extend the mobile capture
	while(SensorValue[I2C_4] > -600){
		motor[mobileCapture1] = 100;
		motor[mobileCapture2] = 100;
	}
	motor[mobileCapture1] = 0;
	motor[mobileCapture2] = 0;
	wait1Msec(100);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	motor[frontLeft] = -125;
	motor[frontRight] = 125;
	motor[backRight] = 125;
	motor[backLeft] = -125;
	wait1Msec(400);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	wait1Msec(100);
	//	//second backward to get close to the third cone
	//	while((SensorValue[I2C_1] > -240))
	//	{
	//		motor[frontLeft] = -60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = -60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	//third turn to line up with the third cone

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while((SensorValue[I2C_1] < 360))
	//	{
	//		motor[frontLeft] = -60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = -60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//fifth forward to grab the third cone
	//	while((SensorValue[I2C_1] < 250))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//Fourth turn to align with the high goal
	//	while (SensorValue[I2C_1] > 150)
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backLeft] = 60;
	//		motor[backRight] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backLeft] = 0;
	//	motor[backRight] = 0;
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] <=750))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}

	//	wait1Msec(100);
	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//sixth forward to score the third cone
	//	while((SensorValue[I2C_1] > -150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(500);
	//	motor[frictionDrum2] = 0;

	//	//fifth turn to align with the fourth cone
	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while (SensorValue[I2C_1] > 150)
	//	{
	//		motor[frontLeft] = -60;
	//		motor[frontRight] = -60;
	//		motor[backLeft] = -60;
	//		motor[backRight] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backLeft] = 0;
	//	motor[backRight] = 0;
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] > 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	wait1Msec(100);
	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//seventh forward to get closer to the fourth cone
	//	while((SensorValue[I2C_1] < 300))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//sixth turn to align with the fourth cone
	//	while((SensorValue[I2C_1] < 250))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//eigth forward to grab the fourth cone
	//	while((SensorValue[I2C_1] < 250))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;as

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//seventh turn to align with the high goal
	//	while (SensorValue[I2C_1] > 15
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backLeft] = 60;
	//		motor[backRight] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backLeft] = 0;
	//	motor[backRight] = 0;
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] <=750))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}

	//	wait1Msec(100);
	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//nineth forward to score the fourth cone
	//	while((SensorValue[I2C_1] < 260))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(500);
	//	motor[frictionDrum2] = 0;

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//eigth turn to align with the fifth cone
	//	while((SensorValue[I2C_1] < 250))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//tenth forward to get within range of the fifth cone
	//	while((SensorValue[I2C_1] < 260))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	wait1Msec(100);
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//nineth turn to align with the fifth cone
	//	while((SensorValue[I2C_1] < 150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//eleventh forward to grsb the fifth cone
	//	while((SensorValue[I2C_1] < 100))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//tenth turn to align with the high goal
	//	while((SensorValue[I2C_1] < 150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//twelfth forward to score the fifth cone
	//	while((SensorValue[I2C_1] < 260))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(500);
	//	motor[frictionDrum2] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	//eleventh turn to align with the mobile goal
	//	while((SensorValue[I2C_1] < 150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	//thirtenth forward to grab the mobile goal
	//	while((SensorValue[I2C_1] < 100))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while((SensorValue[I2C_3] <= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	//twelventh turn to align with the six cone
	//	while((SensorValue[I2C_1] < 150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	SensorValue(pistonOne) = 0;
	//	SensorValue(pistonTwo) = 0;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	while((SensorValue[I2C_3] <= 150))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	SensorValue(pistonOne) = 1;
	//	SensorValue(pistonTwo) = 1;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(1000);

	//	//fourtenth forward to align with seven cone
	//	while((SensorValue[I2C_1] < 100))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	SensorValue(pistonOne) = 0;
	//	SensorValue(pistonTwo) = 0;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	while((SensorValue[I2C_3] <= 150))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	SensorValue(pistonOne) = 1;
	//	SensorValue(pistonTwo) = 1;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(1000);

	//	//fiftenth forward to align with eighth cone
	//	while((SensorValue[I2C_1] < 100))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	SensorValue(pistonOne) = 0;
	//	SensorValue(pistonTwo) = 0;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = 127;
	//	wait1Msec(1000);
	//	motor[frictionDrum2] = 10;

	//	while((SensorValue[I2C_3] <= 150))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	SensorValue(pistonOne) = 1;
	//	SensorValue(pistonTwo) = 1;
	//	while((SensorValue[I2C_3] >= 0))
	//	{
	//		motor[liftLeft] = -125;
	//		motor[liftRight] = -125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;
	//	wait1Msec(600);
	//	motor[frictionDrum2] = -127;
	//	wait1Msec(1000);

	//	//thirtenth turn to go to the mobile goal
	//	while((SensorValue[I2C_1] < 150))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	//sixtenth forward to get to the mobile goal
	//	while((SensorValue[I2C_1] < 1000))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while((SensorValue[I2C_3] <= 150))
	//	{
	//		motor[liftLeft] = 125;
	//		motor[liftRight] = 125;
	//	}
	//	motor[liftLeft] = 0;
	//	motor[liftRight] = 0;

	//	//Section with the mobile goal grabbing mechanism
	//	while((SensorValue[I2C_1] < 1000))
	//	{
	//		motor[frontLeft] = 60;
	//		motor[frontRight] = -60;
	//		motor[backRight] = 60;
	//		motor[backLeft] = -60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;

	//	while(SensorValue[I2C_5] > -10)
	//	{
	//		motor[mobileCapture1] = -10;
	//	}
	//	motor[mobileCapture1] = 0;
	//	//third backward to not muck up the lift and lower said lift
	//	while((SensorValue[I2C_1] <= 0) && (SensorValue[I2C_1] >= -200))
	//	{
	//		motor[frontLeft] = -60;
	//		motor[frontRight] = 60;
	//		motor[backRight] = -60;
	//		motor[backLeft] = 60;
	//	}
	//	motor[frontLeft] = 0;
	//	motor[frontRight] = 0;
	//	motor[backRight] = 0;
	//	motor[backLeft] = 0;
	//	wait1Msec(100);
	//	wait1Msec(100);

	//	SensorValue[I2C_1] = 0;
	//	SensorValue[I2C_2] = 0;
	//	//}
}




task usercontrol()
{

	SensorValue[liftLeft] = 0;
	SensorValue[liftRight] = 0;
	while (true)
	{
		// Y component, X component, Rotation
		motor[frontLeft] = C1LY + C1LX + C1RX;
		motor[frontRight] =  -C1LY + C1LX + C1RX;
		motor[backRight] =  C1LY + C1LX - C1RX;
		motor[backLeft] = -C1LY + C1LX - C1RX;

		// Lift Controls
		if(vexRT [Btn5U] == 1)
		{
			motor[liftRight] = 127;
			motor[liftLeft] = 127;
		}
		else if(vexRT[Btn5D] == 1)
		{

			motor[liftRight] = -127;
			motor[liftLeft] = -127;

		}
		else
		{
			if(SensorValue[I2C_3] >= -150 ) {
				motor[liftLeft] = -15;
				motor[liftRight] = -15;
			}
			else if((SensorValue[I2C_3] < -150) && (SensorValue[I2C_3] > -200)) {
				motor[liftLeft] = -0;
				motor[liftRight] = -0;
			}
			else {
				motor[liftLeft] = 30;
				motor[liftRight] = 30;
			}
		}
		// Friction Drum Controls
		if(vexRT[Btn6U] == 1)
		{
			motor[frictionDrum2] = 127;

		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[frictionDrum2] = -127;
		}
		else
		{
			motor[frictionDrum2] = 10;
		}
		//Pneumatics
		if (vexRT[Btn8D] == 1)
		{
			SensorValue[pistonOne]=0;
			SensorValue[pistonTwo]=0;

		}
		else if (vexRT[Btn8U] == 1)
		{
			SensorValue[pistonOne]=1;
			SensorValue[pistonTwo]=1;
		}

		//Mobile Goal control
		if (vexRT[Ch2] > 100) {
			motor[mobileCapture1] = 127;
			motor[mobileCapture2] = 127;
		}
		else if (vexRT[Ch2] < -100) {
			motor[mobileCapture1] = -127;
			motor[mobileCapture2] = -127;
		}
		else if (vexRT[Btn8L] == 1){
			varU = 1;
			while (varU == 1){
				if (SensorValue(I2C_4) <= -450){
					motor[mobileCapture1] = -127;
					motor[mobileCapture2] = -127;
				}
				else if (SensorValue(I2C_4) >= -250){
					motor[mobileCapture1] = 127;
					motor[mobileCapture2] = 127;
				}
				else if (SensorValue(I2C_4) <= -400){
					motor[mobileCapture1] = -80;
					motor[mobileCapture2] = -80;
				}
				else if (SensorValue(I2C_4) >= -300){
					motor[mobileCapture1] = 80;
					motor[mobileCapture2] = 80;
				}
				else if (SensorValue(I2C_4) <= -370) {
					motor[mobileCapture1] = -40;
					motor[mobileCapture2] = -40;
				}
				else if (SensorValue(I2C_4) >= -330) {
					motor[mobileCapture1] = 40;
					motor[mobileCapture2] = 40;
				}
				else if (SensorValue(I2C_4) <= -365) {
					motor[mobileCapture1] = -20;
					motor[mobileCapture2] = -20;
				}
				else if (SensorValue(I2C_4) >= -355) {
					motor[mobileCapture1] = 20;
					motor[mobileCapture2] = 20;
				}
				else {
					motor[mobileCapture1] = 0;
					motor[mobileCapture2] = 0;
				}
				// Y component, X component, Rotation
				motor[frontLeft] = C1LY + C1LX + C1RX;
				motor[frontRight] =  -C1LY + C1LX + C1RX;
				motor[backRight] =  C1LY + C1LX - C1RX;
				motor[backLeft] = -C1LY + C1LX - C1RX;

				// Lift Controls
				if(vexRT [Btn5U] == 1)
				{
					motor[liftRight] = 127;
					motor[liftLeft] = 127;
				}
				else if(vexRT[Btn5D] == 1)
				{

					motor[liftRight] = -127;
					motor[liftLeft] = -127;

				}
				else
				{
					if(SensorValue[I2C_3] >= -150 ) {
						motor[liftLeft] = -15;
						motor[liftRight] = -15;
					}
					else if((SensorValue[I2C_3] < -150) && (SensorValue[I2C_3] > -200)) {
						motor[liftLeft] = -0;
						motor[liftRight] = -0;
					}
					else {
						motor[liftLeft] = 30;
						motor[liftRight] = 30;
					}
				}
				// Friction Drum Controls
				if(vexRT[Btn6U] == 1)
				{
					motor[frictionDrum2] = 127;

				}
				else if(vexRT[Btn6D] == 1)
				{
					motor[frictionDrum2] = -127;
				}
				else
				{
					motor[frictionDrum2] = 10;
				}
				//Pneumatics
				if (vexRT[Btn8D] == 1)
				{
					SensorValue[pistonOne]=0;
					SensorValue[pistonTwo]=0;

				}
				else if (vexRT[Btn8U] == 1)
				{
					SensorValue[pistonOne]=1;
					SensorValue[pistonTwo]=1;
				}
				if ((vexRT[Ch2] > 50) || (vexRT[Ch2] < -50)){
					varU = 0;
				}
			}
		}
		else {
			motor[mobileCapture1] = 0;
			motor[mobileCapture2] = 0;
		}
	}
}

//if (vexRT[Btn7L] == 1)
//{
//	varD = 0;
//	varL = 1;
//	varU = 0;
//	if((SensorValue[I2C_4] > -300)) {
//		motor[mobileCapture1] = 127;
//		motor[mobileCapture2] = 127;
//	}
//	else if((SensorValue[I2C_4] < -300)) {
//		motor[mobileCapture1] = -127;
//		motor[mobileCapture2] = -127;
//	}
//	else if ((SensorValue[I2C_4] < -325)) {
//		motor[mobileCapture1] = -50;
//		motor[mobileCapture2] = -50;
//	}
//	else if ((SensorValue[I2C_4] > -325)) {
//		motor[mobileCapture1] = 50;
//		motor[mobileCapture2] = 50;
//	}
//	else {
//		motor[mobileCapture1] = 0;
//		motor[mobileCapture2] = 0;
//	}

//}
//else if (vexRT[Btn7U] == 1) {
//	varD = 0;
//	varL = 0;
//	varU = 1;
//	if((SensorValue[I2C_4] > -600)) {
//		motor[mobileCapture1] = 127;
//		motor[mobileCapture2] = 127;
//	}
//	else if((SensorValue[I2C_4] < -600)) {
//		motor[mobileCapture1] = -127;
//		motor[mobileCapture2] = -127;
//	}
//	else if ((SensorValue[I2C_4] < -625)) {
//		motor[mobileCapture1] = -50;
//		motor[mobileCapture2] = -50;
//	}
//	else if ((SensorValue[I2C_4] > -625)) {
//		motor[mobileCapture1] = 50;
//		motor[mobileCapture2] = 50;
//	}
//	else {
//		motor[mobileCapture1] = 0;
//		motor[mobileCapture2] = 0;
//	}
//}
//else if (vexRT[Btn7D] == 1) {
//	varD = 1;
//	varL = 0;
//	varU = 0;
//	if((SensorValue[I2C_4] < 0)) {
//		motor[mobileCapture1] = -127;
//		motor[mobileCapture2] = -127;
//	}
//	else {
//		motor[mobileCapture1] = -127;
//		motor[mobileCapture2] = -127;
//	}
//}
//else {
//	motor[mobileCapture1] = 0;
//	motor[mobileCapture2] = 0;
//}
