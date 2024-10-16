#include "gui.h"

bool coolingEnabled = true;
bool heatingEnabled = false;
uint16_t  temperature = 22;

// Define the temperature screen objects
lv_obj_t* temperatureScreen = NULL;
lv_obj_t* tempControlLabel = NULL;
lv_obj_t* temperautreArc = NULL;
lv_obj_t* ui_Panel1 = NULL;
lv_obj_t* ui_Panel2 = NULL;
lv_obj_t* temperatureLabel = NULL;
lv_obj_t* celciusLabel = NULL;
lv_obj_t* coolingButton = NULL;
lv_obj_t* coolingButtonLabel = NULL;
lv_obj_t* heatingButton = NULL;
lv_obj_t* heatingButtonLabel = NULL;


//Temperature Screen Callbacks
void temperatureArcCallback(lv_event_t* e)
{
	temperature = lv_arc_get_value(temperautreArc);
	lv_label_set_text_fmt(temperatureLabel, "%d", temperature);
}

void coolingButtonCallback(lv_event_t* e)
{
	lv_event_code_t coolingCode = lv_event_get_code(e);
	if (coolingCode == LV_EVENT_VALUE_CHANGED) {
		if (heatingEnabled)
		{
			lv_obj_clear_state(heatingButton, LV_STATE_CHECKED);
			heatingEnabled = false;
			coolingEnabled = true;
		}
		else
		{
			if(coolingEnabled)
			{
				coolingEnabled = false;
			}
			else
			{
				coolingEnabled = true;
			}
		}
	}
}

void heatingButtonCallback(lv_event_t* e)
{
	lv_event_code_t heatingCode = lv_event_get_code(e);
	if (heatingCode == LV_EVENT_VALUE_CHANGED) {
		if (coolingEnabled)
		{
			lv_obj_clear_state(coolingButton, LV_STATE_CHECKED);
			heatingEnabled = true;
			coolingEnabled = false;
		}
		else
		{
			if(heatingEnabled)
			{
				heatingEnabled = false;
			}
			else
			{
				heatingEnabled = true;
			}
		}
	}
}

void createTemperatureScreen(void)
{
	temperatureScreen = lv_obj_create(NULL);
	lv_scr_load(temperatureScreen);

	lv_obj_set_style_bg_color(temperatureScreen, lv_color_hex(0xEAEDF2), LV_PART_MAIN | LV_STATE_DEFAULT);

	tempControlLabel = lv_label_create(temperatureScreen);
	lv_obj_set_width(tempControlLabel, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_height(tempControlLabel, LV_SIZE_CONTENT);    /// 1
	lv_obj_set_x(tempControlLabel, 0);
	lv_obj_set_y(tempControlLabel, 5);
	lv_obj_set_align(tempControlLabel, LV_ALIGN_TOP_MID);
	lv_label_set_text(tempControlLabel, "Temperature Control");
	lv_obj_set_style_text_color(tempControlLabel, lv_color_hex(0x171935), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(tempControlLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(tempControlLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

	temperautreArc = lv_arc_create(temperatureScreen);
	lv_obj_set_width(temperautreArc, 180);
	lv_obj_set_height(temperautreArc, 180);
	lv_obj_set_align(temperautreArc, LV_ALIGN_CENTER);
	lv_arc_set_range(temperautreArc, 16, 35);
	lv_arc_set_value(temperautreArc, temperature);
	lv_arc_set_bg_angles(temperautreArc, 150, 30);
	lv_obj_set_style_pad_left(temperautreArc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(temperautreArc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(temperautreArc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(temperautreArc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(temperautreArc, lv_color_hex(0xA2A9B8), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(temperautreArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(temperautreArc, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_style_arc_color(temperautreArc, lv_color_hex(0x7F85F9), LV_PART_INDICATOR | LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(temperautreArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

	lv_obj_set_style_bg_color(temperautreArc, lv_color_hex(0xF9B23D), LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(temperautreArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(temperautreArc, lv_color_hex(0x7F85F9), LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(temperautreArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(temperautreArc, 5, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(temperautreArc, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(temperautreArc, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(temperautreArc, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(temperautreArc, 3, LV_PART_KNOB | LV_STATE_DEFAULT);

	ui_Panel1 = lv_obj_create(temperatureScreen);
	lv_obj_set_width(ui_Panel1, 140);
	lv_obj_set_height(ui_Panel1, 140);
	lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
	lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
		LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
		LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_scrollbar_mode(ui_Panel1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_style_radius(ui_Panel1, 350, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xF9B23D), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_Panel1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_Panel2 = lv_obj_create(temperatureScreen);
	lv_obj_set_width(ui_Panel2, 120);
	lv_obj_set_height(ui_Panel2, 120);
	lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
	lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
		LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
		LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_scrollbar_mode(ui_Panel2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_set_style_radius(ui_Panel2, 350, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	temperatureLabel = lv_label_create(temperatureScreen);
	lv_obj_set_width(temperatureLabel, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_height(temperatureLabel, LV_SIZE_CONTENT);    /// 1
	lv_obj_set_x(temperatureLabel, 0);
	lv_obj_set_y(temperatureLabel, -10);
	lv_obj_set_align(temperatureLabel, LV_ALIGN_CENTER);
	lv_label_set_text_fmt(temperatureLabel, "%d", temperature);
	lv_obj_clear_flag(temperatureLabel,
		LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
		LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_text_color(temperatureLabel, lv_color_hex(0x7F85F9), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(temperatureLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(temperatureLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

	celciusLabel = lv_label_create(temperatureScreen);
	lv_obj_set_width(celciusLabel, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_height(celciusLabel, LV_SIZE_CONTENT);    /// 1
	lv_obj_set_x(celciusLabel, 0);
	lv_obj_set_y(celciusLabel, 15);
	lv_obj_set_align(celciusLabel, LV_ALIGN_CENTER);
	lv_label_set_text(celciusLabel, "°Celcius");
	lv_obj_clear_flag(celciusLabel,
		LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
		LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_text_color(celciusLabel, lv_color_hex(0x7F85F9), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(celciusLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(celciusLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

	coolingButton = lv_btn_create(temperatureScreen);
	lv_obj_set_width(coolingButton, 100);
	lv_obj_set_height(coolingButton, 50);
	lv_obj_set_x(coolingButton, 8);
	lv_obj_set_y(coolingButton, -8);
	lv_obj_set_align(coolingButton, LV_ALIGN_BOTTOM_LEFT);
	lv_obj_add_flag(coolingButton, LV_OBJ_FLAG_CHECKABLE);     /// Flags
	lv_obj_clear_flag(coolingButton, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
		LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_bg_color(coolingButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(coolingButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(coolingButton, lv_color_hex(0x7F85F9), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(coolingButton, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(coolingButton, lv_color_hex(0x7F85F9), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_bg_opa(coolingButton, 255, LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(coolingButton, lv_color_hex(0x7F85F9), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
	lv_obj_set_style_bg_opa(coolingButton, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
	if (coolingEnabled)
	{
		lv_obj_add_state(coolingButton, LV_STATE_CHECKED);

	}
	else
	{
		lv_obj_clear_state(coolingButton, LV_STATE_CHECKED);
	}

	coolingButtonLabel = lv_label_create(coolingButton);
	lv_obj_set_width(coolingButtonLabel, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_height(coolingButtonLabel, LV_SIZE_CONTENT);    /// 1
	lv_obj_set_align(coolingButtonLabel, LV_ALIGN_CENTER);
	lv_label_set_text(coolingButtonLabel, "Cooling");
	lv_obj_clear_flag(coolingButtonLabel, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
		LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_text_color(coolingButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(coolingButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(coolingButtonLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(coolingButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(coolingButtonLabel, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_color(coolingButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(coolingButtonLabel, 255, LV_PART_MAIN | LV_STATE_PRESSED);

	heatingButton = lv_btn_create(temperatureScreen);
	lv_obj_set_width(heatingButton, 100);
	lv_obj_set_height(heatingButton, 50);
	lv_obj_set_x(heatingButton, -8);
	lv_obj_set_y(heatingButton, -8);
	lv_obj_set_align(heatingButton, LV_ALIGN_BOTTOM_RIGHT);
	lv_obj_add_flag(heatingButton, LV_OBJ_FLAG_CHECKABLE);     /// Flags
	lv_obj_clear_flag(heatingButton, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
		LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_bg_color(heatingButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(heatingButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(heatingButton, lv_color_hex(0xF9B23D), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(heatingButton, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(heatingButton, lv_color_hex(0xF9B23D), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_bg_opa(heatingButton, 255, LV_PART_MAIN | LV_STATE_PRESSED);
	if (heatingEnabled)
	{
		lv_obj_add_state(heatingButton, LV_STATE_CHECKED);
	}
	else
	{
		lv_obj_clear_state(heatingButton, LV_STATE_CHECKED);
	}

	heatingButtonLabel = lv_label_create(heatingButton);
	lv_obj_set_width(heatingButtonLabel, LV_SIZE_CONTENT);   /// 1
	lv_obj_set_height(heatingButtonLabel, LV_SIZE_CONTENT);    /// 1
	lv_obj_set_align(heatingButtonLabel, LV_ALIGN_CENTER);
	lv_label_set_text(heatingButtonLabel, "Heating");
	lv_obj_clear_flag(heatingButtonLabel, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
		LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
		LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
	lv_obj_set_style_text_color(heatingButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(heatingButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(heatingButtonLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(heatingButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(heatingButtonLabel, 255, LV_PART_MAIN | LV_STATE_CHECKED);
	lv_obj_set_style_text_color(heatingButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(heatingButtonLabel, 255, LV_PART_MAIN | LV_STATE_PRESSED);

	//Temperature Arc Event
	lv_obj_add_event_cb(temperautreArc, temperatureArcCallback, LV_EVENT_VALUE_CHANGED, NULL);

	//Cooling Button Event
	lv_obj_add_event_cb(coolingButton, coolingButtonCallback, LV_EVENT_ALL, NULL);

	//Heating Button Event
	lv_obj_add_event_cb(heatingButton, heatingButtonCallback, LV_EVENT_ALL, NULL);
}