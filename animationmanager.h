#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "animation.h"

#include <string>
#include <map>

using ::std::string;
using ::std::map;

class AnimationManager
{
public:
    AnimationManager();

    void Create(string name, Texture &t, int x, int y, int w, int h, int count, double _speed, int step);
    void Draw(RenderWindow &window, double x = 0, double y = 0);
    void Set(string name);
    void Flip(bool to_flip);
    void Tick(double time);
    void Play();
    void Pause();

private:
    string current_animation;
    map<string, Animation> animations_list;

};

#endif // ANIMATIONMANAGER_H
