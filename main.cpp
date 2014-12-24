#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "animationmanager.h"

using namespace sf;



int main(){
    RenderWindow window(VideoMode(640, 480), "Poop");

    Texture q;
    if (!q.loadFromFile("bomberman.png"))
        return 0;

    AnimationManager animation;
    animation.Create("walk-down", q, 48, 0, 48, 72, 7, 0.005, 48);
    animation.Create("walk-up", q, 0, 96, 48, 72, 8, 0.005, 48);
    animation.Create("walk", q, 0, 192, 48, 72, 8, 0.005, 48);
    animation.Create("stay", q, 0, 0, 48, 72, 1, 0.005, 0);


    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time/500;

        if (time > 20) time = 20;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        animation.Set("stay");
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            animation.Set("walk-up");
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            animation.Set("walk-down");
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            animation.Set("walk");
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            animation.Set("walk");
        }


        animation.Tick(time);
        window.clear(Color(255,255,255));
        animation.Draw(window, 50, 100);

        window.display();
    }

    return 0;
}
