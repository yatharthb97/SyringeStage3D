#pragma once


//Stepper Pins
	
	// Syringe
	const unsigned int SYRINGE_EN = 0;
	const unsigned int SYRINGE_DIR = 0;
	const unsigned int SYRINGE_PULSE = 0;

	// X
	const unsigned int X_EN_PIN = 0;
	const unsigned int X_DIR_PIN = 0;
	const unsigned int X_PULSE_PIN = 0;

	// Y
	const unsigned int Y_EN_PIN = 0; 
	const unsigned int Y_DIR_PIN = 0; 
	const unsigned int Y_PULSE_PIN = 0;

	// Z
	const unsigned int Z_EN_PIN = 0;
	const unsigned int Z_DIR_PIN = 0; 
	const unsigned int Z_PULSE_PIN = 0;





// Not applied here ↓


// LED Pins
	const unsigned int PULSE_PIN = 6;


//IR Sensor
	const unsigned int IR_SENSOR1_RDPIN = 3;
	const unsigned int IR_SENSOR2_RDPIN = 2;


	const unsigned int IR_SENSOR1_VCCPIN = 4;
	const unsigned int IR_SENSOR2_VCCPIN = 5;




//Limit Switch Interrupt
	const unsigned int LIMIT_SW_X2 = 3;


//PMT Control Pins
	const int PMT_CS_PIN = 53;





#define SAMPLE_DIST 1300
#define STAGE_LEN 9100

#define NO_SAMPLES 8


#define EDGE_LEN 0
#define STRIP_LEN 0
#define WHITE_FIELD 700
#define BLACK_FIELD 600