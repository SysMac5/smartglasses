#include "Screen.h"

#include <hardware/i2c.h>

#include <Overlay.h>
#include <Scene.h>

Screen::Screen() {
    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    ssd1306_display.external_vcc=false;
    ssd1306_init(&ssd1306_display, 128, 64, OLED_ADDRESS, i2c1);
}

void Screen::open(Scene *scene) {
    //scenes.push(scene);
    update();
}

void Screen::go_back() {
    //scenes.pop();
    update();
}

void Screen::show(Overlay *overlay) {
    overlay->is_hidden = false;
    update();
}

void Screen::hide(Overlay *overlay) {
    overlay->is_hidden = true;
    update();
}

void Screen::update() {
    scene->display(&ssd1306_display);

    /*for (Overlay* overlay : overlays) {
        if (overlay->is_hidden) continue;

        overlay->display(&ssd1306_display);
    }*/

    /*std::vector<std::vector<bool>> temp_bitmap = scenes.top()->bitmap;
    for (Overlay* overlay : overlays) {
        if (overlay->is_hidden) continue;

        int max_row = len(*overlay) + overlay->top_left_row;
        int max_column = len(**overlay) + overlay->top_left_column;

        for (int row = overlay->top_left_row; row <= max_row; row++) {
            for (int column = overlay->top_left_column; column <= max_column; column++) {
                temp_bitmap[row][column] = overlay->bitmap[row - overlay->top_left_row][column - overlay->top_left_column];
            }
        }
    }*/

    
}
