#pragma once
#include <vector>
#include "raylib.h"
#include "Bullet.h"
#include "BulletPattern.h"
#include <string>
#include <memory>

enum Patterns {
	Cross, Spiral, MAX
};

class BulletGenerator
{
public:
	BulletGenerator();
	void Process();
	void Update(float deltaTime);
	void Draw();

	void ToggleAutoMode();
	bool AutoMode = false;

	unsigned int bulletsToGenerate = 4;
	unsigned int currentPattern = 0;

	unsigned int ActiveBullets = 0;
	void NextPattern();
	void PreviousPattern();
	void UpdatePattern();
	void IncreaseBullets();
	void DecreaseBullets();

	void ChangeTexture(KeyboardKey key);

	std::string currentColor = "Blue";
	std::string PatternName = "Cross";

private:
	void Generate();
	Vector2 _mousePosition = { 0, 0 };
	Texture2D _selectedTexture;
	
	std::vector<std::unique_ptr<BulletPattern>> _patterns;
	std::vector<Texture2D> _textures;
};

