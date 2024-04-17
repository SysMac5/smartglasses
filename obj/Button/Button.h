#ifndef BUTTON_H
#define BUTTON_H

#include <functional>

/**
 * @class Button
 * @brief Takki á skjá.
*/
class Button {
public:
    /** @brief Næsti takki fyrir ofan. */
    Button* up = nullptr;
    /** @brief Næsti takki fyrir neðan. */
    Button* down = nullptr;
    /** @brief Næsti takki til vinstri. */
    Button* left = nullptr;
    /** @brief Næsti takki til hægri. */
    Button* right = nullptr;

    /** @brief Smiður fyrir takka. */
    Button() = default;

    /** 
     * @brief Ræsir aðgerð takkans.
    */
    void press();

    /**
     * @brief Tengir takka fyrir ofan.
    */
    void connect_up(Button* button);
    /**
     * @brief Tengir takka fyrir neðan.
    */
    void connect_down(Button* button);
    /**
     * @brief Tengir takka til vinstri.
    */
    void connect_left(Button* button);
    /**
     * @brief Tengir takka til hægri.
    */
    void connect_right(Button* button);

private:
    std::function<int()> action;
};

#endif
