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

class Main final
{
	public:
		esp_err_t setup(void);
		void loop(void);
};




#endif /* MAIN_INCLUDE_MAIN_HPP_ */
