#ifndef MAIN_MAIN_H_
#define MAIN_MAIN_H_

/***************************INCLUDES******************************/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "lvglInit.h"
#include "lcd.h"
#include "touch.h"
#include "lv_demos.h"
#include "lv_examples.h"
#include "gui.h"
/*****************************EXTERN VARIABLES******************************/
extern const char *TAG;

/************************FUNCTION PROTOTYPE************************/
bool example_lvgl_lock(int timeout_ms);
void example_lvgl_unlock(void);
void example_lvgl_port_task(void *arg);

#endif /* MAIN_MAIN_H_ */
