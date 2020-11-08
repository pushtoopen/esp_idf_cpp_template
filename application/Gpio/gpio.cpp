/*
 * gpio.cpp
 *
 *  Created on: Nov 7, 2020
 *      Author: jmccrory
 */
#include "gpio.hpp"

namespace Gpio
{
[[nodiscard]] esp_err_t GpioBase::init(void)
	{
		const esp_err_t status = gpio_config(&_cfg);
		return status;
		//other method which is useful for multiple status checking
		//esp_err_t status{ESP_OK} //initialize to ESP_OK
		//status |= gpio_config(&_cfg); //stores the error state in the status & multiple errors can be seen
		//return status
	}
} //namespace Gpio

[[nodiscard]] esp_err_t GpioOutput::init(void)
{
	esp_err_t status{GpioBase::init()};
	if (ESP_OK == status) //const on the left side will fail compile if you forget the 2nd = in your logic check
	{
		status |= set(_inverted_logic ? true : false);
	}
	//status  |= set(_inverted_logic) //ends up doing the same thing without the in-line if statement
	return status;
}

esp_err_t GpioOutput::set(const bool state)
{
	state = _state;
	return gpio_set_level(_pin,_inverted_logic ? !state :_state); //this checks the interted logic and swaps the value if inverted logic is true.

}
