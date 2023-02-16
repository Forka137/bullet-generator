#pragma once
#include "SpiralPattern.h"
#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include <memory>
#include <iostream>

SpiralPattern::SpiralPattern(Texture2D texture, Vector2 mousePos, unsigned int amount) {
	_texture = texture;
	_mousePos = mousePos;

	if (amount <= 0) amount = 1;

	std::vector<std::unique_ptr<Bullet>> bullets;

	// Create 4 balls under mouse
	for (int i = 0; i < amount; i++) {
		bullets.push_back(std::make_unique<Bullet>(_texture, Vector2{ _mousePos.x, _mousePos.y }));
		bullets[i].get()->Angle = PI/2;
		bullets[i].get()->SpinIntensity = 50.0f;
		bullets[i].get()->MaxSpeed = 300.0f;

		// Set start position
		bullets[i].get()->Acceleration.x *= cosf(i * 2 * (PI / amount));
		bullets[i].get()->Acceleration.y *= sinf(i * 2 * (PI / amount));
	}

	// Add to queue
	for (int i = 0; i < bullets.size(); i++) {
		_bullets.push_back(std::move(bullets[i]));
	}
}
