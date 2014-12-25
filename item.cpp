#include "item.h"

Item::Item() {}
Item::Item(AnimationManager &_animation, int _x, int _y) {
    animation = _animation;
    x = _x;
    y = _y;

    direction = 0;
    alive = true;
    dx = dy = 0;
}

void Item::Draw(RenderWindow &window)
{
    animation.Draw(window, x, y);
}
