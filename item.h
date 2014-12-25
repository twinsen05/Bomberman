#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "animationmanager.h"

class Item
{
public:
    AnimationManager animation;
    double x, y;
    double dx, dy;
    double w, h;
    bool alive;
    bool direction;

    Item();
    Item(AnimationManager &_animation, int _x, int _y);

    virtual void Update(double time) = 0;

    void Draw(RenderWindow &window);
};

#endif // ITEM_H
