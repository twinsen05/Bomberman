#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Animation {
friend class AnimationManager;

public:
    Animation();
    Animation(Texture &t, int x, int y, int w, int h, int count, double _speed, int step);
    void Tick(double time);

private:
    Sprite sprite;
    std::vector<IntRect> frames, frames_flip;
    double current_frame, speed;
    bool flip;
    bool is_playing;
};

#endif // ANIMATION_H
