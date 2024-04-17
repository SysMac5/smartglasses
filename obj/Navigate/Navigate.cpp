#include "Navigate.h"
#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/gpio.h>

void select(uint gpio, uint32_t events);
void up(uint gpio, uint32_t events);
void down(uint gpio, uint32_t events);
void left(uint gpio, uint32_t events);
void right(uint gpio, uint32_t events);

Navigate::Navigate() {
    reset();
}

void Navigate::init() {
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

    gpio_set_irq_enabled_with_callback(BUTTON_SELECT, GPIO_IRQ_EDGE_RISE, true, &select);
    gpio_set_irq_enabled_with_callback(BUTTON_UP, GPIO_IRQ_EDGE_RISE, true, &up);
    gpio_set_irq_enabled_with_callback(BUTTON_DOWN, GPIO_IRQ_EDGE_RISE, true, &down);
    gpio_set_irq_enabled_with_callback(BUTTON_LEFT, GPIO_IRQ_EDGE_RISE, true, &left);
    gpio_set_irq_enabled_with_callback(BUTTON_RIGHT, GPIO_IRQ_EDGE_RISE, true, &right);
}

void Navigate::reset() {
    select_pressed = false;
    up_pressed = false;
    down_pressed = false;
    left_pressed = false;
    right_pressed = false;
}

Navigate navigate = Navigate();

void select(uint gpio, uint32_t events) {
    navigate.select_pressed = true;
}

void up(uint gpio, uint32_t events) {
    navigate.up_pressed = true;
}

void down(uint gpio, uint32_t events) {
    navigate.down_pressed = true;
}

void left(uint gpio, uint32_t events) {
    navigate.left_pressed = true;
}

void right(uint gpio, uint32_t events) {
    navigate.right_pressed = true;
}
