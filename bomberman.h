#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include <string>
#include <map>
using ::std::string;
using ::std::map;

#include "item.h"
#include "animationmanager.h"

class Bomberman : public Item {
public:
    bool place_bomb;
    int direction;

    enum {STAY, WALK, WALK_UP, WALK_DOWN, PLACE} STATE;
    map<string, bool> key;

    Bomberman();
    Bomberman(AnimationManager &_animation);
    void KeyCheck();
    void Update(double time);
};

#endif // BOMBERMAN_H
