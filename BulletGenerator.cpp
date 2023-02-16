#pragma once
#include "BulletGenerator.h"
#include "Bullet.h"
#include "CrossPattern.h"
#include "SpiralPattern.h"
#include "raylib.h"
#include <vector>
#include <memory>
#include <iostream>

BulletGenerator::BulletGenerator() {
	// Load textures
	std::vector<std::string> textures = {
		"resources/blue_ball.png",
		"resources/purple_ball.png",
		"resources/red_ball.png",
		"resources/green_ball.png"
	};

	for (int i = 0; i < textures.size(); i++) {
		_textures.push_back(LoadTexture(textures[i].c_str()));
	}

	//Initial texture
	_selectedTexture = _textures[0];
}

void BulletGenerator::Process() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && AutoMode || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !AutoMode){
		_mousePosition = GetMousePosition();
		_mousePosition.x -= 16;
		_mousePosition.y -= 16;
		Generate();
	}
}

void BulletGenerator::Update(float deltaTime) {
	// Update patterns and check if ended
	ActiveBullets = 0;
	for (int i = 0; i < _patterns.size(); i++) {
		_patterns[i].get()->Update(deltaTime);
		ActiveBullets += _patterns[i].get()->ActiveBullets;
	}

	// Delete Ended Patterns before next frame
	for (int i = 0; i < _patterns.size(); i++) {
		if (_patterns[i]->PatternEnded) {
			_patterns.erase(_patterns.begin() + i);
		}
	}
}

void BulletGenerator::Draw() {
	for (int i = 0; i < _patterns.size(); i++) {
		if (_patterns[i].get()) {
			_patterns[i].get()->Draw();
		}
	}
}

void BulletGenerator::NextPattern() {
	if (currentPattern < int(Patterns::MAX) - 1) {
		currentPattern++;
		UpdatePattern();
	}
}

void BulletGenerator::PreviousPattern() {
	if (currentPattern > 0) {
		currentPattern--;
		UpdatePattern();
	}
}

void BulletGenerator::IncreaseBullets() {
	if (bulletsToGenerate < 32) {
		bulletsToGenerate++;
	}
}

void BulletGenerator::DecreaseBullets() {
	// Can't have 0 bullets
	if (bulletsToGenerate > 1) {
		bulletsToGenerate--;
	}
}

void BulletGenerator::ChangeTexture(KeyboardKey key) {
	switch (key) {
	case KEY_A:
		_selectedTexture = _textures[0];
		currentColor = "Blue";
		break;

	case KEY_S:
		_selectedTexture = _textures[1];
		currentColor = "Purple";
		break;

	case KEY_D:
		_selectedTexture = _textures[2];
		currentColor = "Red";
		break;

	case KEY_F:
		_selectedTexture = _textures[3];
		currentColor = "Green";
		break;

	default:
		break;
	}
}


void BulletGenerator::Generate() {
	switch (currentPattern) {
	case 0:
		_patterns.push_back(std::make_unique<CrossPattern>(_selectedTexture, _mousePosition, bulletsToGenerate));
		break;
	case 1:
		_patterns.push_back(std::make_unique<SpiralPattern>(_selectedTexture, _mousePosition, bulletsToGenerate));
		break;
	default:
		break;
	}
}

void BulletGenerator::UpdatePattern() {
	switch (currentPattern) {
	case 0:
		PatternName = "Cross";
		break;
	case 1:
		PatternName = "Spiral";
		break;
	default:
		break;
	}
}

void BulletGenerator::ToggleAutoMode() {
	if (AutoMode) {
		AutoMode = false;
	}
	else {
		AutoMode = true;
	}
}

