#include <cmath>
#include "../include/BouncingSquare.hpp"

BouncingSquare::BouncingSquare(float xPosition, float yPosition, float size)
{

    this -> xPosition = xPosition;
    this -> yPosition = yPosition;
    this -> size = size;

    this -> dx = ::GetRandomValue(2, 4);
    this -> dy = ::GetRandomValue(3, 5);

}

void BouncingSquare::Update()
{

    if (::GetScreenWidth() - GetSize() <= GetX())
    {

        this -> dx = -this -> dx;

    }
    else if (GetX() <= 0)
    {

        this -> dx = abs(this -> dx);

    }

    if (::GetScreenHeight() - GetSize() <= GetY())
    {

        this -> dy = -this -> dy;

    }
    else if (GetY() <= 0)
    {

        this -> dy = abs(this -> dy);

    }

    this -> xPosition += dx;
    this -> yPosition += dy;

}

void BouncingSquare::Draw()
{

    DrawRectangle(this -> xPosition, this -> yPosition, this -> size, this -> size, this -> color);

}