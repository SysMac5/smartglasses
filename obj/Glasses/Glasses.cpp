#include "Glasses.h"

Glasses::Glasses() {
    screen = Screen();
    navigate = Navigate();

    Button *button_ptr = new Button();

    Scene *scene = new Scene([] (ssd1306_t *ssd1306_display) -> int {
        ssd1306_clear(ssd1306_display);
        ssd1306_draw_empty_square(ssd1306_display, 32, 16, 64, 32);
        ssd1306_draw_empty_square(ssd1306_display, 30, 14, 60, 28);

        ssd1306_draw_string(ssd1306_display, 30, 14, 1, "Halló!");

        ssd1306_show(ssd1306_display);

        return 0;
    });

    scene->first_button = button_ptr;
}