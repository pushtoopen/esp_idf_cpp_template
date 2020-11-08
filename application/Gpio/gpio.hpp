/*
 * gpio.hpp
 *
 *  Created on: Nov 7, 2020
 *      Author: jmccrory
 */

#ifndef APPLICATION_GPIO_HPP_
#define APPLICATION_GPIO_HPP_

#include "driver/gpio.h"

namespace Gpio
{
	class GpioBase //common vars & functions between classes
	{
	protected: //gettable only
		const gpio_num_t _pin;
		const gpio_config_t _cfg;
		const bool _inverted_logic = false;

	public:
		//Constructor - you know this because the method is the same name as the class
		constexpr GpioBase(const gpio_num_t pin, //constexpr is only used because all items passed in are constant or reference/pointer
						   const gpio_config_t &config,
						   const bool _invert_logic = false) :
			_pin{pin},
			_cfg{config}, //TODO this variable does not seem to be declared.
			_inverted_logic{_invert_logic}

		{

		}

		virtual bool state(void) = 0;                //getter - different between output vs input
		virtual esp_err_t set(const bool state) = 0; // setter
		[[nodiscard]] esp_err_t init(void);

	};


	class GpioOutput : public GpioBase // adding the public Gpiobase give you access to all GpioBase public and protected methods in GpioOutput
	{
	private:
		bool _state = false; //maps the users wish

	public:
		constexpr GpioOutput(const gpio_num_t pin, const bool invert = false) : //constexpr is only used because all items passed in are constant
			GpioBase{pin,
					 gpio_config_t{
						.pin_bit_mask = static_cast<uint64_t>(1) << pin,
						.mode		  = GPIO_MODE_OUTPUT,
						.pull_up_en   = GPIO_PULLUP_DISABLE,
						.pull_down_en = GPIO_PULLDOWN_ENABLE,
						.intr_type    = GPIO_INTR_DISABLE
					 },
					 invert}
		{

		}
		bool state(void) {return _state;}
		esp_err_t init(void);
		esp_err_t set(const bool state);
		//esp_err_t toggle(void);

	};
/*
	class GpioInput
	{
	private:
		gpio_num_t _pin;
		const bool _inverted_logic = false;
	public:
		esp_err_t init(void);

		bool state(void);
	};
*/
} //namespace Gpio



#endif /* APPLICATION_GPIO_HPP_ */
