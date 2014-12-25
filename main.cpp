#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "animationmanager.h"
#include "bomberman.h"

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
    Bomberman bomberman(animation);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time/700;

        if (time > 40) time = 40;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        animation.Set("stay");
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            bomberman.key["Up"] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            bomberman.key["Down"] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bomberman.key["Left"] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bomberman.key["Right"] = true;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            bomberman.key["Space"] = true;
        }



        bomberman.Update(time);
        window.clear(Color(255,255,255));
        bomberman.Draw(window);
        window.display();
    }

    return 0;
}
