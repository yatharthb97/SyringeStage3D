#pragma once
//#include "Adafruit_Motor_Shield_V2_Library-master/Adafruit_MotorShield.h"
#include <AFMotor.h>

/** @brief Adafruit V2 motor shield compatible stepper API. */
class AdafruitStepper : public AF_Stepper
{
public:
	
	int pos = 0;
	int director = FORWARD;
	int mode = SINGLE;
	int motor_rpm = 100;


	AdafruitStepper(unsigned int steps, uint8_t channel): AF_Stepper(steps, channel)
	{
		setSpeed(motor_rpm);
	}


	enum direction : int
	{
		fwd = 1,
		rev = -1
	};


	void set_dir(int dir)
	{
		if(dir < 0)
		{
			this->director = BACKWARD;
		}

		if(dir > 0)
		{
			this->director = FORWARD;
		}
	}


	void move(int steps)
	{
		step(abs(steps), this->director, this->mode);
		this->pos += steps;
	}

	void forward(unsigned int steps)
	{
		set_dir(1);
		move(steps);
	}


	void reverse(unsigned int steps)
	{
		set_dir(-1);
		move(steps);
	}

	void go_to(int new_position)
	{
		int disp = new_position - this->pos;

        
        set_dir(disp);
        move(disp);

	}
};


/** @brief A composite object of 3 stepper motors.*/
class AdafruitStepperGroup3D
{

	bool wire_init = false;
public:

	AdafruitStepper stepper[3] = {AdafruitStepper(200, 1), AdafruitStepper(200, 2), AdafruitStepper(200, 2)}; //!< 3 stepper motors for 3 
	//unsigned int axes[3] = {3};


	/** @brief Definations of `axis` parameters. */
	enum axis : unsigned int
	{
		x = 0, y = 1, z = 2
	};


	/** @brief Add a motor along a given axis. */
	void add_motor(unsigned int axis_id, uint8_t channel, unsigned int steps, unsigned int dummy_var)
	{
		/*if(!wire_init)
		{
			wire_init = true;
			*motor1 = AdafruitStepper(1, 200);
			*motor2 = AdafruitStepper(2, 200);

		}

		if(axis_id <= axis::z)
		{
			axes[axis_id] = channel;
			//*stepper[axis_] = AdafruitStepper(steps, channel);
			//stepper[axis].init(channel, steps, AFMS);
		}*/


	}


	/** @brief Move to a new 3-vector position by sequertial operation of motors. */
	void move(int steps_x, int steps_y, int steps_z)
	{
		// Move x-motor
		stepper[0].set_dir(steps_x);
		stepper[0].move(steps_x);
		
		delay(2);

		// Move y-motor
		stepper[1].set_dir(steps_y);
		stepper[1].move(steps_y);
		
		delay(2);

		// Move z-motor
		stepper[2].set_dir(steps_z);
		stepper[2].move(steps_z);
	}

	/** @brief move a particular motor, defined by `axis` certain steps. */
	void move(unsigned int axis_id, int steps)
	{
		stepper[axis_id].set_dir(steps);
		stepper[axis_id].move(static_cast<unsigned int>(steps));
	}

	/** @brief Operator for direct access of motors. */
	AdafruitStepper operator[](unsigned int axis_id)
	{
		if(axis_id < axis::z)
		{
			return stepper[axis_id];
		}
	}

};






















