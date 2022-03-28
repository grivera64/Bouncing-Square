#ifndef BOUNCING_SQUARE
#define BOUNCING_SQUARE
#include "raylib.h"
#include <cmath>

class BouncingSquare
{

    float xPosition;
    float yPosition;
    float size;

    float dx = 4;
    float dy = 3;

    Color color = WHITE;

public:

    /* Constructors and Destructors */
    BouncingSquare(float xPosition=::GetRandomValue(0, ::GetScreenWidth()), float yPosition=::GetRandomValue(0, ::GetScreenHeight()), float size=GetRandomValue(10, 40));
    ~BouncingSquare() {}

    /* Logic Member Functions */
    void Update();
    void Draw();

    /* Accessors */
    float GetX() const { return this -> xPosition; };
    float GetY() const { return this -> yPosition; };
    float GetSize() const { return this -> size; };

};

#endif