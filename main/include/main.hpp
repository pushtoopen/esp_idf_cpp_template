/**
 * @file main.hpp
 *
 * @brief Basic main includes to allow for esp-idf FreeRTOS task usage
 *
 * @author jmccrory
 *
 * Contact: github:pushtoopen
 *
 */
//#pragma once //forces compiler to include this file once ever... its the same as the #ifndef
#ifndef MAIN_INCLUDE_MAIN_HPP_
#define MAIN_INCLUDE_MAIN_HPP_


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//component/application includes
#include "gpio.hpp"

//set your gpio here
#define BLINK_GPIO GPIO_NUM_27

class Main final
{
	public:
		esp_err_t setup(void);
		void loop(void);

	Gpio::GpioOutput led{BLINK_GPIO,true}; //app example addition: put pin number in and if login should be inverted, so if inverted = true (0 = on, 1 = off)
};




#endif /* MAIN_INCLUDE_MAIN_HPP_ */
