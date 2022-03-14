
#pragma once
#include "stepper.hpp"


/** @brief A composite object of 3 stepper motors.*/
class StepperGroup3D
{
public:

	Stepper stepper[3]; //!< 3 stepper motors for 3 axes.


	/** @brief Definations of `axis` parameters. */
	enum axis : unsigned int
	{
		x = 0, y = 1, z = 2
	};


	/** @brief Add a motor along a given axis. */
	void add_motor(unsigned int axis, unsigned int enPIN, unsigned int dirPIN, unsigned int pulsePIN)
	{
		if(axis <= axis::z)
		{
			stepper[axis].init(enPIN, dirPIN, pulsePIN);
		}
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
	void move(unsigned int axis, int steps)
	{
		if(axis <= axis::z)
		{
			stepper[axis].set_dir(steps);
			stepper[axis].move(steps);
		}
		
	}

	/** @brief Operator for direct access of motors. */
	Stepper operator[](unsigned int axis_id)
	{
		if(axis_id < axis::z)
		{
			return stepper[axis_id];
		}
	}

};