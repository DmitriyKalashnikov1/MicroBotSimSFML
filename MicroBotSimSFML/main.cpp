#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "MicroBot.h"
#include "Walls.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(Vector2u( SCREEN_HEIGHT, SCREEN_WEIGHT)), "MicroBotSim");

    window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);
    Texture backGT;
    backGT.loadFromFile(PATH_TO_BACKGROUND_TEXTURE);

    Sprite background(backGT);
    background.setScale(Vector2f(SCREEN_HEIGHT / background.getLocalBounds().size.x,
        SCREEN_WEIGHT / background.getLocalBounds().size.y
    ));

    float backgroundOffsetX = -1;
    float bOffsetIncrement = -0.5;

    MicroBot mBot = MicroBot(PATH_TO_MAGNIT_TEXTURE, PATH_TO_MICROBOT_TEXTURE,500.f, 500.f, 100.f, 200.f, 0.3);
    Walls walls = Walls(PATH_TO_WALLS_TEXTURE, SCREEN_WEIGHT, SCREEN_HEIGHT);
    walls.testUpdate(SCREEN_WEIGHT, SCREEN_HEIGHT);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
            if (event->is<Event::MouseMoved>()) {
                Vector2i mousePose = Mouse::getPosition(window);
                mBot.update(mousePose.x, mousePose.y, FPSDelay);
                // background animation section
                //background.move(Vector2f(bOffsetIncrement, 0));

                //backgroundOffsetX += bOffsetIncrement;

                //if ((backgroundOffsetX < -10) || (backgroundOffsetX > 0)) {
                //    bOffsetIncrement *= -1;
                //}
            }
        }

        window.clear();
        window.draw(background);
        window.draw(walls.upWall);
        window.draw(walls.downWall);
        window.draw(*mBot.magnit);
        window.draw(*mBot.bot);
        window.display();
    }
}