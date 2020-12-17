/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h> 
#include <stdlib.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>

/* Driver configuration */
#include "ti_drivers_config.h"


/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0) {
    /* 1 second delay */
    uint8_t rand_time = time(0);
    uint8_t counter = 0;

    /* Call driver init functions */
    GPIO_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);

    while (1) {
        GPIO_toggle(CONFIG_GPIO_LED_1);
            
        srand(rand_time);
        rand_time = rand() % (10 - 1 + 1) - 1;
        sleep(rand_time);
    }
}


