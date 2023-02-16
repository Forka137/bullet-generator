#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include <string>
#include <iostream>

Bullet::Bullet(Texture2D texture) {
	_texture = texture;
}

Bullet::Bullet(Texture2D texture, Vector2 position) {
	_texture = texture;
	Position = position;
	_initPos = Position;
}

void Bullet::Update(float deltaTime) {
	if (Angle > 0.0 && Angle <= PI/2) {
		// Change direction slightly
		Vector2 relativePos = Vector2Subtract(Position, _initPos);
		Vector2 deviation = Vector2Normalize(relativePos);
		deviation = Vector2Rotate(deviation, Angle);

		Velocity.x += (Acceleration.x * deltaTime) + deviation.x * SpinIntensity;
		Velocity.y += (Acceleration.y * deltaTime) + deviation.y * SpinIntensity;
	}
	else {
		Velocity.x += Acceleration.x * deltaTime;
		Velocity.y += Acceleration.y * deltaTime;
	} 
	if (Vector2Length(Velocity) > MaxSpeed) {
		Velocity = Vector2Scale(Vector2Normalize(Velocity), MaxSpeed);
	}
	Position.x += Velocity.x * deltaTime;
	Position.y += Velocity.y * deltaTime;

	Vector2 viewPort = { GetScreenWidth(), GetScreenHeight() };

	if (Position.x < 0 || Position.x > viewPort.x || Position.y < 0 || Position.y > viewPort.y) {
		OutsideViewPort = true;
	}
}

void Bullet::Draw() {
	DrawTexture(_texture, (int)Position.x, (int)Position.y, Tint);
}