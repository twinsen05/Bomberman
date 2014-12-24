#include "bomberman.h"

Bomberman::Bomberman() {
}


Bomberman::Bomberman(AnimationManager &_animation) {
    animation = _animation;
    STATE = STAY;
}

void Bomberman::KeyCheck() {

    // Нажатие клавиш
    if (key["Left"]) {
        direction = 0;
        dx = -0.1;
        if (STATE == STAY) STATE = WALK;
    }

    if (key["Right"]) {
        direction = 1;
        dx = 0.1;
        if (STATE == STAY) STATE = WALK;
    }

    if (key["Up"]) {
        dy = -0.1;
        if (STATE == STAY) STATE = WALK;
    }

    if (key["Down"]) {
        dy = 0.1;
        if (STATE == STAY) STATE = WALK;
    }

//    if (key["Space"]) {
//        place_bomb = true;
//    }


    // Отпускание клавиш
    if (!key["Left"] && !key["Right"]) {
        dx = 0;
        if (STATE == WALK) STATE = STAY;
    }

    if (!key["Up"] && !key["Down"]) {
        dy = 0;
        if (STATE == WALK) STATE = STAY;
    }

//    if (!key["Space"]) {
//        place_bomb = false;
//    }




}

void Bomberman::Update(double time)
{
    KeyCheck();
    if (STATE == STAY) {
        animation.Set("stay");
    } else if (STATE == WALK) {
        animation.Set("walk");
    }

    if (!direction) {
        animation.Flip(true);
    }

    x += dx * time;
//    Collision(0);

    y += dy * time;
//    Collision(1);

    animation.Tick(time);

}
