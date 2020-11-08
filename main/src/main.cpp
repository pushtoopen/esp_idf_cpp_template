#include "main.hpp"
//#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"




#define LOG_TAG "MAIN"

static Main my_main; //Class instance declaration

//minimum using classes, looks like arduino setup
extern "C" void app_main(void)
{
	ESP_ERROR_CHECK(my_main.setup()); //if setup returns anything other than ESP_OK, then ESP_ERROR_CHECK causes a system fail

	while(true)
	{
		my_main.loop();
	}

}

esp_err_t Main::setup(void)
{

	esp_err_t status{ESP_OK};

	ESP_LOGI(LOG_TAG, "Setup!");

	status |= led.init(); //app example addition, |= is only done for error returns

	return status;
	//return ESP_OK; //can just return this line and be fine
}

void Main::loop(void)
{

	ESP_LOGI(LOG_TAG, "Hello World!");

	ESP_LOGD(LOG_TAG, "LED on!");
	led.set(true);

	vTaskDelay(pdMS_TO_TICKS(1000)); //delays 1000 ms or 1 sec

	ESP_LOGD(LOG_TAG, "LED off!");
	led.set(false);

	vTaskDelay(pdMS_TO_TICKS(1000)); //delays 1000 ms or 1 sec


}


/*//minimum without using a class delete this comment if unneeded
extern "C" void app_main(void)
{
	while(true)
	{
		ESP_LOGI(LOG_TAG, "Hello World!");
		vTaskDelay(1000/portTICK_PERIOD_MS); //delays 1000 ms or 1 sec
		vTaskDelay(pdMS_TO_TICKS(1000)); //delays 1000 ms or 1 sec, same thing as above
	}
}*/
