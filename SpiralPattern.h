#pragma once
#include "BulletPattern.h"
class SpiralPattern :
    public BulletPattern
{
public:
    SpiralPattern(Texture2D texture, Vector2 mousePos, unsigned int amount);

private:
    Vector2 _mousePos;
};

