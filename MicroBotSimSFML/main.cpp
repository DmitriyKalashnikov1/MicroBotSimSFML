#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "MicroBot.h"
#include "Walls.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(Vector2u( SCREEN_WEIGHT, SCREEN_HEIGHT)), "MicroBotSim");

    //window.setFramerateLimit(FPS);
    window.setVerticalSyncEnabled(true);
    Texture backGT;
    backGT.loadFromFile(PATH_TO_BACKGROUND_TEXTURE);

    Sprite background(backGT);
    background.setScale(Vector2f(SCREEN_WEIGHT / background.getLocalBounds().size.x,
        SCREEN_HEIGHT / background.getLocalBounds().size.y
    ));

    Vector2f newMgnitPose;
    newMgnitPose.x = 500.f;
    newMgnitPose.y = 500.f;

    float poseIncDec = 25;

    MicroBot mBot = MicroBot(PATH_TO_MAGNIT_TEXTURE, PATH_TO_MICROBOT_TEXTURE, newMgnitPose.x, newMgnitPose.y, 100.f, 200.f, 0.1, 2.f, BOT_MASS);
    Walls walls = Walls(PATH_TO_WALLS_TEXTURE, SCREEN_WEIGHT, SCREEN_HEIGHT);

    Clock timer;
    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();

            // keyboard controls
            if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
                newMgnitPose.y -= poseIncDec;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
                newMgnitPose.y += poseIncDec;
            }
            //else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
            //    newMgnitPose.x -= poseIncDec;

            //}
            else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                newMgnitPose.x += poseIncDec;
            }

        }
        Time elapsed = timer.getElapsedTime();

        if (elapsed.asMilliseconds() > FPSDelay) {
            
            if (newMgnitPose.x > SCREEN_WEIGHT) {
                newMgnitPose.x = 150.f;
                mBot.update(newMgnitPose.x, newMgnitPose.y, elapsed.asMilliseconds(), false);
                walls.update(mBot.botPos, elapsed.asMilliseconds());
            }
            else {
                mBot.update(newMgnitPose.x, newMgnitPose.y, elapsed.asMilliseconds(), true);
            }

           
            float distToRightSide = SCREEN_WEIGHT - mBot.magnitPos.x;
            
            cout << "DistToRightSide: " << distToRightSide << endl;

            //walls.update(mBot.botPos, elapsed.asMilliseconds());
            // background animation section
            //background.move(Vector2f(bOffsetIncrement, 0));

            //backgroundOffsetX += bOffsetIncrement;

            //if ((backgroundOffsetX < -10) || (backgroundOffsetX > 0)) {
            //    bOffsetIncrement *= -1;
            //}
            timer.restart();
        }

        window.clear();
        window.draw(background);
        window.draw(walls.upWall);
       // window.draw(walls.downWall);
        window.draw(*mBot.magnit);
        window.draw(*mBot.bot);
        window.display();
        
    }
}