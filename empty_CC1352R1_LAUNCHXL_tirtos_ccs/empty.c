#include <time.h> 
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <ti/drivers/GPIO.h>
#include "ti_drivers_config.h"


void *mainThread(void *arg0) {
    uint8_t rand_time = time(0);
    uint8_t counter = 0;

    GPIO_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);

    while (1) {
        GPIO_toggle(CONFIG_GPIO_LED_1);
            
        srand(rand_time);
        rand_time = rand() % 10 - 1;
        sleep(rand_time);
    }
}


