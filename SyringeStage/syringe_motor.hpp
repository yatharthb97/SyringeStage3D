#pragma once
#include "stepper.hpp"



/** @brief SyrengeMotor is a composite object that represents a `Syringe` + `Stepper` combibnation.
 *It inherits the `Stepper` class and contains all its functionality as well.*/
class SyringeMotor : public Stepper
{
public:
	double syrenge_vol_mL = 20;        	//!< Total Syrenge Volume in mL.
	unsigned long tot_steps = 1000000; 	//!< Total steps needed to empty the syrenge.
	double delta_vol = 0; 				//!< Volume dispensed per step.


	double rem_vol = syrenge_vol_mL;    //!< State variable - volume remaining.
	

	/** @brief Constructor. */
	constexpr SyringeMotor(double syrenge_vol_mL, unsigned long tot_steps) :
	syrenge_vol_mL(syrenge_vol_mL),
	tot_steps(tot_steps), 
	delta_vol(syrenge_vol_mL/double(tot_steps)),
	rem_vol(syrenge_vol_mL)
	{}


	/** @breif Initalize the inbuilt stepper motor. */
	void init_motor(unsigned int enPIN, unsigned int dirPIN, unsigned int pulsePIN)
	{
		this->init(enPIN, dirPIN, pulsePIN); // Initialize stepper
	}



	/** @brief Move certain `milli Liter` of liquid. */
	inline bool move_mL(double amount)
	{
		unsigned int steps = amount / delta_vol;

		if(rem_vol > 0)
		{
			this->move(steps);
			rem_vol -= amount;
		}
	}


	/** @brief Release certain `milli Liter` of 
	liquid by moving in the forward direction.*/
	inline bool dispense_mL(double amount)
	{
		this->set_dir(direction::fwd);
		move_mL(amount);
	}


	/** @brief Intake certain `milli Liter` of 
	liquid by moving in the reverse direction.
	Resets the direction to forward after completion. */
	inline bool reverse_mL(double amount)
	{
		this->set_dir(direction::rev);
		move_mL(amount);
		this->set_dir(direction::fwd);
	}

};