#include "animationmanager.h"

AnimationManager::AnimationManager() { }

void AnimationManager::Create(string name, Texture &t, int x, int y, int w, int h, int count, double _speed, int step) {
    animations_list[name] = Animation(t, x, y, w, h, count, _speed, step);
}

void AnimationManager::Draw(RenderWindow &window, double x, double y) {
    animations_list[current_animation].sprite.setPosition(x, y);
    window.draw(animations_list[current_animation].sprite);
}

void AnimationManager::Set(std::string name) {
    current_animation = name;
}

void AnimationManager::Flip(bool to_flip) {
    animations_list[current_animation].flip = to_flip;
}

void AnimationManager::Tick(double time) {
    animations_list[current_animation].Tick(time);
}

void AnimationManager::Play() {
    animations_list[current_animation].is_playing = true;
}

void AnimationManager::Pause() {
    animations_list[current_animation].is_playing = false;
}
