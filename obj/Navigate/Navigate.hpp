#ifndef NAVIGATE_H
#define NAVIGATE_H

#define BUTTON_UP 13
#define BUTTON_DOWN 14
#define BUTTON_LEFT 12
#define BUTTON_RIGHT 15
#define BUTTON_SELECT 11

/**
 * @class Navigate
 * @brief Sér um takkana.
*/
class Navigate {
public:
    bool select_pressed;
    bool up_pressed;
    bool down_pressed;
    bool left_pressed;
    bool right_pressed;

    /**
     * @brief Smiður fyrir takkana.
    */
    Navigate();

    /**
     * @brief Upphafsstillir takkana.
    */
    void init();

    /**
     * @brief Breytir öllum flöggum í false.
    */
    void reset();
};

#endif
