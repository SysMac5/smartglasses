#include "Overlay.h"
#include <stdio.h>

void Overlay::display(ssd1306_t *ssd1306_display) {
    int error_code = graphic(ssd1306_display);
    if (error_code != 0) {
        printf("Error in Scene::display, returned %d\n", error_code);
    }
}
