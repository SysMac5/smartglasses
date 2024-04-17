#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/i2c.h>
#include <ssd1306.h>

#define BUTTON_UP 13
#define BUTTON_DOWN 14
#define BUTTON_LEFT 12
#define BUTTON_RIGHT 15
#define BUTTON_SELECT 11

#define OLED_ADDRESS 0x3D
#define SDA_PIN 26
#define SCL_PIN 27

bool select_pressed = false;
bool up_pressed = false;
bool down_pressed = false;
bool left_pressed = false;
bool right_pressed = false;

void select(uint gpio, uint32_t events) {
    select_pressed = true;
}

void up(uint gpio, uint32_t events) {
    up_pressed = true;
}

void down(uint gpio, uint32_t events) {
    down_pressed = true;
}

void left(uint gpio, uint32_t events) {
    left_pressed = true;
}

void right(uint gpio, uint32_t events) {
    right_pressed = true;
}

ssd1306_t disp;

int x = 32;
int y = 16;

void update() {
    ssd1306_clear(&disp);
    ssd1306_draw_empty_square(&disp, y, x, 64, 32);
    ssd1306_draw_empty_square(&disp, y + 2, x + 2, 60, 28);
    ssd1306_draw_string(&disp, y + 10, x + 10, 1, "Hallo!");
    ssd1306_show(&disp);
}

void setup() {
    stdio_init_all();

    sleep_ms(500);

    gpio_init(BUTTON_UP);
    gpio_init(BUTTON_DOWN);
    gpio_init(BUTTON_LEFT);
    gpio_init(BUTTON_RIGHT);
    gpio_init(BUTTON_SELECT);
    gpio_set_dir(BUTTON_UP, GPIO_IN);
    gpio_set_dir(BUTTON_DOWN, GPIO_IN);
    gpio_set_dir(BUTTON_LEFT, GPIO_IN);
    gpio_set_dir(BUTTON_RIGHT, GPIO_IN);
    gpio_set_dir(BUTTON_SELECT, GPIO_IN);
    gpio_pull_up(BUTTON_UP);
    gpio_pull_up(BUTTON_DOWN);
    gpio_pull_up(BUTTON_LEFT);
    gpio_pull_up(BUTTON_RIGHT);
    gpio_pull_up(BUTTON_SELECT);

    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    sleep_ms(500);

    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, OLED_ADDRESS, i2c1);

    sleep_ms(100);

    update();

    sleep_ms(100);
}

void loop() {

    if (!gpio_get(BUTTON_SELECT)) { 
        ssd1306_clear(&disp);
        ssd1306_draw_empty_square(&disp, y, x, 64, 32);
        ssd1306_show(&disp);
        sleep_ms(1000);
        ssd1306_draw_empty_square(&disp, y + 2, x + 2, 60, 28);
        ssd1306_show(&disp);
        sleep_ms(1000);
        ssd1306_draw_string(&disp, y + 10, x + 10, 1, "villa");
        ssd1306_show(&disp);
        sleep_ms(1000);
    }
    if (!gpio_get(BUTTON_UP)) { y++; up_pressed=false; update(); }
    if (!gpio_get(BUTTON_DOWN)) { y--; down_pressed=false; update(); }
    if (!gpio_get(BUTTON_LEFT)) { x++; left_pressed=false; update(); }
    if (!gpio_get(BUTTON_RIGHT)) { x--; right_pressed=false; update(); }

    sleep_ms(100); // Small delay to debounce buttons (simplistic approach)
}

int main() {
    setup();
    while (true) {
        loop();
    }
}
