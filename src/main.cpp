#include <iostream>
#include <raylib.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <BouncingSquare.hpp>

int main(int argc, char **argv)
{

    /* Initial Conditions */
    const char *title = "Bouncing DVD Player";
    const int width = GetMonitorWidth(0);
    const int height = GetMonitorHeight(0);
    const Color background = BLACK;
    bool finished = false;
    char timer = 64;
    std::vector<std::shared_ptr<BouncingSquare>> squareVector;
    squareVector.push_back(std::make_unique<BouncingSquare>());

    int tmpX;
    int tmpY;

    InitWindow(width, height, title);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowState(FLAG_WINDOW_MAXIMIZED);
    ToggleFullscreen();
    SetTargetFPS(60);

    unsigned char counter = 255;
    while (!WindowShouldClose())
    {

        int currKey = GetKeyPressed();

        if (currKey == KEY_B)
        {

            printf("This is working\n");
            RestoreWindow();
            SetWindowState(FLAG_WINDOW_RESIZABLE);
            SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
            SetWindowSize(800, 800);

        }

        if (finished)
        {

            timer--;

            if (timer == 0)
            {

                if (squareVector.size() < 1)
                {

                    break;

                }

                squareVector.erase(squareVector.end());
                timer = 64;

            }

        }
        else if (counter == 0)
        {

            if (squareVector.size() > 10)
            {

                squareVector.erase(squareVector.begin());

            }

            squareVector.push_back(std::make_unique<BouncingSquare>());

        }

        BeginDrawing();
        
        {

            ClearBackground(background);

            if (finished)
            {

                DrawText("Thank you for using my screen saver!", 500, 500, 20, WHITE);

            }
            
            for (auto iter = squareVector.begin(); iter < squareVector.end(); iter++)
            {

                tmpX = iter -> get() -> GetX();
                tmpY = iter -> get() -> GetY();

                if (tmpX < 0 - iter -> get() -> GetSize() / 2 || tmpX > GetScreenWidth() + iter -> get() -> GetSize() / 2 
                             || tmpY < 0 - iter -> get() -> GetSize() / 2|| tmpY > GetScreenHeight() + iter -> get() -> GetSize() / 2)
                {

                    iter = squareVector.erase(iter);

                }
                else
                {

                    iter -> get() -> Update();
                    iter -> get() -> Draw();

                }

            }

        }

        EndDrawing();

        counter--;

        if (currKey == KEY_ENTER)
        {

            finished = true;

        }

    }

    CloseWindow();
    squareVector.clear();

    return 0;

}
