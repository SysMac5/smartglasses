#ifndef SCREEN_H
#define SCREEN_H

#define OLED_ADDRESS 0x3D
#define SDA_PIN 26
#define SCL_PIN 27

#include <ssd1306.h>

class Scene;
class Overlay;

/**
 * @class Screen
 * @brief Skjár sem sýnir sviðsmyndir og yfirlög.
*/
class Screen {
public:
    /**
     * @brief Smiður fyrir skjáinn.
    */
    Screen();

    /**
     * @brief Opna sviðsmynd og setja núverandi á hlaða.
     * @param scene Sviðsmyndin til að opna.
    */
    void open(Scene* scene);

    /**
     * @brief Loka núverandi sviðsmynd og sækja sviðsmynd af hlaða.
    */
    void go_back();

    /**
     * @brief Sýna yfirlag á skjánum
     * @param overlay Yfirlag til að birta.
    */
    void show(Overlay* overlay);

    /**
     * @brief Fela yfirlag á skjánum.
     * @param overlay Yfirlag til að fela.
    */
    void hide(Overlay* overlay);

private:
    ssd1306_t ssd1306_display;

    Scene* scene;
    Overlay* overlays;

    void update();
};

#endif
