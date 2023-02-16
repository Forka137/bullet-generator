#pragma once
#include <string>
#include "MainGUI.h"
#include "BulletGenerator.h"
#include <memory>

class Game
{
public:
	Game();
	~Game();

	void Initialize(std::string title);
	void RunLoop();
	void Terminate();

private:
	void ProcessInput();
	void Update();
	void DrawObjects();
	void UpdateBulletCount();

	std::unique_ptr<MainGUI> _mainGUI;
	std::unique_ptr<BulletGenerator> _bGenerator;
	// std::unique_ptr<Bullet> _bullet;
};

