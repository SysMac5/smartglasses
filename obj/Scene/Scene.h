#ifndef SCENE_H
#define SCENE_H

#include <ssd1306.h>

#include <memory>
#include <functional>

class Button;

/**
 * @class Scene
 * @brief Sviðsmynd á skjá sem nær yfir hann allan.
*/
class Scene {
public:
    /** @brief Takkinn sem fókusað er á í upphafi. */
    Button *first_button;

    /**
     * @brief Smiður fyrir sviðsmynd.
    */
    Scene(std::function<int(ssd1306_t*)> graphic) : graphic(graphic) {};

    /**
     * @brief Birtir myndefni sviðsmyndar.
    */
    void display(ssd1306_t *ssd1306_display);

private:
    std::function<int(ssd1306_t*)> graphic;
};

#endif
