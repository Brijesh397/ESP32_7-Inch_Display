/*
 * gui.h
 *
 *  Created on: Oct. 13, 2024
 *      Author: Brijesh
 */

#ifndef MAIN_GUI_GUI_H_
#define MAIN_GUI_GUI_H_

#include "main.h"

void createTemperatureScreen(void);

/***************LVGL********************************/
//Screen Objects
extern lv_obj_t* temperatureScreen;

//Temperature Screen Objects
extern lv_obj_t* tempControlLabel;
extern lv_obj_t* temperautreArc;
extern lv_obj_t* ui_Panel1;
extern lv_obj_t* ui_Panel2;
extern lv_obj_t* temperatureLabel;
extern lv_obj_t* celciusLabel;
extern lv_obj_t* coolingButton;
extern lv_obj_t* coolingButtonLabel;
extern lv_obj_t* heatingButton;
extern lv_obj_t* heatingButtonLabel;

#endif /* MAIN_GUI_GUI_H_ */
