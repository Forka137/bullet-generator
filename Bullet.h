#pragma once
#include "raylib.h"
#include <string>
class Bullet
{
public:
	Bullet(Texture2D texture);
	Bullet(Texture2D texture, Vector2 position);

	Vector2 Position = { 0, 0 };
	Vector2 Velocity = { 0, 0 };
	Vector2 Acceleration = { 500.0f, 500.0f };

	float MaxSpeed = 1000.0f;

	// Angle change
	float Angle = 0.0f;
	float SpinIntensity = 0.0f;

	Color Tint = WHITE;

	void Update(float deltaTime);
	void Draw();

	bool OutsideViewPort = false;

private:
	Vector2 _initPos = { 0, 0 };
	Texture2D _texture;
};

