#ifndef CAMERA_H
#define CAMERA_H

#include <ArduCAM.h>

class Camera {
public:
    Camera();

    void give_color();

private:
    ArduCAM arducam;
};

#endif
