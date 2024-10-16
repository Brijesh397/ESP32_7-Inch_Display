# ESP32 7-Inch Display + ESP-IDF + LVGL

This is an example code to interface with [ELECROW ESP32 7-Inch Display](https://www.elecrow.com/esp32-display-7-inch-hmi-display-rgb-tft-lcd-touch-screen-support-lvgl.html?gad_source=1&gclid=Cj0KCQjwyL24BhCtARIsALo0fSBaAMmQ7C_cLE85fS1-uQTS3b2zO3twyc6maRgfb644pJqbEFKGG9AaAq5tEALw_wcB) using ESP-IDF + LVGL.

I was not able to find any implementation to use the display on github without using Arduino Libraries. 
However, some guy on elecrow's forum mentioned we could use the example code available with ESP-IDF to interface with a 16-bit parallel RGB Display.

So, I made the necessary changes in that example and also added support for the GT911 Touch Panel (Used an existing touch library provided by ESP-IDF).

I am successfully able to display the LVGL graphics on the display as well as interact with it using the touch panel.

I have uploaded the code on this repo as I did not find any other implementation of this on Github, making it easier for others to use the Display. 
 
