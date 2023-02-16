#pragma once
#include "CrossPattern.h"
#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include <memory>

CrossPattern::CrossPattern(Texture2D texture, Vector2 mousePos, unsigned int amount) {
	_texture = texture;
	_mousePos = mousePos;

	std::vector<std::unique_ptr<Bullet>> bullets;

	if (amount <= 0) amount = 1;

	// Create 4 balls under mouse
	for (int i = 0; i < amount; i++) {
		bullets.push_back(std::make_unique<Bullet>(_texture, Vector2{ _mousePos.x, _mousePos.y }));

		// Las acelera en un angulo distinto segun la cantidad de balas
		bullets[i].get()->Acceleration.x *= cosf(i * 2 * (PI / amount));
		bullets[i].get()->Acceleration.y *= sinf(i * 2 * (PI / amount));
	}

	// Add to queue
	for (int i = 0; i < bullets.size(); i++) {
		_bullets.push_back(std::move(bullets[i]));
	}
}