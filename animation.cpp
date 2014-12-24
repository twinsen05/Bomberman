#include "animation.h"

Animation::Animation() {

}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, double _speed, int step) {
    speed = _speed;
    sprite.setTexture(t);

    current_frame = 0;
    is_playing = true;
    flip = false;

    for (int i = 0; i < count; ++i) {
        frames.push_back(IntRect(x + (i * step), y, w, h));
        frames_flip.push_back(IntRect(x + (i * step) + w, y, -w, h));
    }

}

void Animation::Tick(double time) {
    if (!is_playing)
        return;

    current_frame += speed * time;

    if (current_frame > frames.size())
        current_frame -= frames.size();

    int i = current_frame;
    if (!flip) {
        sprite.setTextureRect(frames[i]);
    } else {
        sprite.setTextureRect(frames_flip[i]);
    }
}
