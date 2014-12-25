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
        STATE = WALK;
    }

    if (key["Right"]) {
        direction = 1;
        dx = 0.1;
        STATE = WALK;
    }

    if (key["Up"]) {
        dy = -0.1;
        if (STATE == STAY) STATE = WALK_UP;
    }

    if (key["Down"]) {
        dy = 0.1;
        if (STATE == STAY) STATE = WALK_DOWN;
    }

//    if (key["Space"]) {
//        place_bomb = true;
//    }


    // Отпускание клавиш
    if (!key["Left"] && !key["Right"] && !key["Up"] && !key["Down"]) {
        dx = 0;
        dy = 0;
        if (STATE != STAY) STATE = STAY;
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
    } else if (STATE == WALK_UP) {
        animation.Set("walk-up");
    } else if (STATE == WALK_DOWN) {
        animation.Set("walk-down");
    }

    if (!direction) {
        animation.Flip(true);
    } else {
        animation.Flip(false);
    }


    x += dx * time;
//    Collision(0);

    y += dy * time;
//    Collision(1);

    animation.Tick(time);
    key["Left"] = key["Right"] = key["Up"] = key["Down"] = false;
    key["Space"] = false;
}
