#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;

int ground = 150;

const int H = 12;
const int W = 40;

char **map_array = new char*[H];

class Player {
    public:
        float dx, dy;
        FloatRect rect;
        bool on_ground;
        Sprite sprite;
        float current_frame;

        Player(Texture &image){
            sprite.setTexture(image);
            rect = FloatRect(0, 920, 110, 110);
            sprite.setTextureRect(IntRect(rect));
            dx = dy = 0;
            current_frame = 0;
        }

        void update(float time) {
            rect.left += dx*time;
            if (!on_ground)
                dy += 0.0005*time;
            rect.top += dy*time;
            on_ground = false;
            if (rect.top > ground) {
                rect.top = ground;
                dy = 0;
                on_ground = true;
            };

            current_frame += 0.005*time;
            if (current_frame > 10)
                current_frame -= 10;
            if (dx > 0)
                sprite.setTextureRect(IntRect(121*int(current_frame), 920, 110, 110));
            if (dx < 0)
                sprite.setTextureRect(IntRect(121*int(current_frame)+121, 920, -110, 110));

            sprite.setPosition(rect.left, rect.top);

            dx = 0;
        }
};

int main(){
    std::ifstream map_file("map.txt");
    char *tmp = new char [W+1];

    RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    
    for (int i = 0; i < H; ++i){
        map_file.getline(tmp, W + 1);
        map_array[i] = tmp;
        tmp = new char [W+1];
    };

    RectangleShape rectangle;

    Texture t;
    t.loadFromFile("sprite.jpg");

    float currentFrame = 0;

    Player p(t);

    Clock clock;

    while (window.isOpen()) {
        Event event;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time/500;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            p.dx = -0.1;
        };

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            p.dx = 0.1;
        };

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (p.on_ground) {
                p.dy = -0.4;
                p.on_ground = false;
            };
        };  

        p.update(time);

        window.clear();
        
        rectangle.setSize(sf::Vector2f(32, 32));

        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j) {
                if (map_array[i][j] == 'B')
                    rectangle.setFillColor(Color::White);
                if (map_array[i][j] == '0')
                    rectangle.setFillColor(Color::Green);
                if (map_array[i][j] == ' ')
                    continue;
                rectangle.setPosition(i*32, j*32);
                window.draw(rectangle);
            };

        window.draw(p.sprite);
        window.display();
    }
    return 0;
}
