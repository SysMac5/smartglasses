#include "Button.h"
#include <stdio.h>

void Button::press() {
    int error_code = action();
    if (error_code != 0) {
        printf("Error in Button::press, returned %d\n", error_code);
    }
}

void Button::connect_up(Button* button) {
    up = button;
}

void Button::connect_down(Button* button) {
    down = button;
}

void Button::connect_left(Button* button) {
    left = button;
}

void Button::connect_right(Button* button) {
    right = button;
}