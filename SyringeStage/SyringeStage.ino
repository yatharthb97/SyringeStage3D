
#include "sequence_file.hpp"


//StepperGroup variables
StepperGroup3D stepper;
Grid grid(XLEN, YLEN);


//SyrengeMotor variables
SyringeMotor syringe(20, 2000);	//!< Syringe-motor object.
unsigned int seq_id = 0;		//!< Current Sequence ID.
unsigned int sample_id = 0;		//!< Current Sample ID.
bool dispensation_over = false; //!< Flag to indicate if the dispensation sequences are over.





void setup()
{
	
	//Stepper setups
	SyringeMotor.init_motor(SYRINGE_EN, SYRINGE_DIR, SYRINGE_PULSE);

	stepperg.add_motor(stepperg.x, X_EN_PIN, X_DIR_PIN, X_PULSE_PIN);
	stepperg.add_motor(stepperg.y, Y_EN_PIN, Y_DIR_PIN, Y_PULSE_PIN);
	stepperg.add_motor(stepperg.z, Z_EN_PIN, Z_DIR_PIN, Z_PULSE_PIN);

}




void loop()
{
	//blink(LED_BUILTIN, next_dispence());
	//delay(5000);
	
	//digitalWrite(LED_BUILTIN, HIGH);
	//delay(200);
	//digitalWrite(LED_BUILTIN, LOW);
	//delay(200);


	xy_procedure(); //
	delay(500);
	z_procedure();
	delay(500);

}




/** @brief Returns the volume of liquid to be dispensed for 
 * the current sample by reading the `sequence_file.cpp` .*/
float dispence_next()
{
	if(!dispensation_over)
	{
		float dispence_val = SEQ_LIST[seq_id][sample_id];

		sample_id++;

		if(sample_id >= NO_SAMPLES)
		{
			sample_id = 0;
			seq_id++;
		}

		if(seq_id >= NO_SEQUENCES)
		{
			if(DO_REPEAT)
			{
				seq_id = 0;
				sample_id = 0;
			}

			else
			{
				dispensation_over = true;
			}
		}

		return dispence_val;
	}

	else { return 0; } //If dispensation is over, always return 0.
	
}


/** @brief Dispence liquid using stepper[z] and syringemotor.*/
void z_procedure()
{
	//Lower syringe
	stepperg[stepperg.z].forward(Z_LENGTH);
	delay(500);

	//Dispense set mL of liquid
	syringe.dispense_mL(dispence_next());
	delay(500); //Water clearing delay might have to be higher


	//Hoist the syrenge back
	stepperg[stepperg.z].reverse(Z_LENGTH);
}



/** @brief Move to the next sample position. */
void xy_procedure()
{
	unsigned int* new_pos = grid.next();

	new_pos[0] *= X_LENGTH;
	new_pos[1] *= Y_LENGTH;

	stepperg[stepperg.x].goto(new_pos[0]);
	delay(500);
	stepperg[stepperg.y].goto(new_pos[1]);

}



//Test blink_function
void blink(unsigned int pin, unsigned int pulses)
{
	pinMode(pin, OUTPUT);
	for(unsigned int i = 0; i < pulses; i++)
	{
		digitalWrite(pin, HIGH);
		delay(500);
		digitalWrite(pin, LOW);
		delay(500);
	}
}