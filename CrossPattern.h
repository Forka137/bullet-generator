#pragma once
#include "BulletPattern.h"
#include "raylib.h"
class CrossPattern : public BulletPattern
{
public:
	CrossPattern(Texture2D texture, Vector2 mousePos, unsigned int amount);

private:
	Vector2 _mousePos;
};

