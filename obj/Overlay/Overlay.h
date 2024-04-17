#ifndef OVERLAY_H
#define OVERLAY_H

#include <ssd1306.h>

#include <vector>
#include <memory>
#include <functional>

class Button;

/**
 * @class Overlay
 * @brief Yfirlag á skjá sem birtist ofan á sviðsmynd.
*/
class Overlay {
public:
    /** @brief Takkinn sem fókusað er á í upphafi. */
    Button *first_button;
    /** @brief Hvort yfirlag sé falið. */
    bool is_hidden = false;

    /**
     * @brief Smiður fyrir yfirlag.
    */
    Overlay(std::function<int(ssd1306_t*)> graphic) : graphic(graphic) {};

    /**
     * @brief Birtir myndefni yfirlags.
    */
    void display(ssd1306_t *ssd1306_display);

private:
    std::function<int(ssd1306_t*)> graphic;
};

#endif
