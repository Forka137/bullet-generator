#pragma once
#include "Game.h"
#include "raylib.h"
#include <string>
#include <memory>
#include "MainGUI.h"
#include "StaticText.h"
#include "BulletGenerator.h"
#include <iostream>

Game::Game() {
	// Nada de la raylib puede ir antes de InitWindow, por lo tanto el constructor de Game queda vacío
}

Game::~Game() {

}

void Game::Initialize(std::string title) {
	// FLAG_VSYNC_HINT) Pareciera ayudar con los frame drops
	// Esto es un problema de funciones internas del sistema operativo
	// Una optimización que disminuye el uso de GPU si no es necesario
	// Esto causa que se realentice en ciertos momentos con pocas animaciones en la pantalla
	SetConfigFlags(FLAG_VSYNC_HINT);

	InitWindow(800, 600, title.c_str());
	// SetTargetFPS(60);
	// Si le quito targetFPS dejo que se ajuste a la pantalla con la FLAG de más arriba.
	// SetExitKey(0); // Disables ESC_KEY for Exit
	_mainGUI = std::make_unique<MainGUI>();
	_bGenerator = std::make_unique<BulletGenerator>();
}

void Game::RunLoop() {
	while (!WindowShouldClose()) {
		ProcessInput();
		Update();
		DrawObjects();
	}
}

void Game::Terminate() {
	CloseWindow();
}

void Game::Update() {
	_mainGUI->Process();
	_mainGUI->Update(GetFrameTime());
	_bGenerator->Process();
	_bGenerator->Update(GetFrameTime());
	// std::cout << GetFrameTime() << std::endl;
	UpdateBulletCount();
}

// Private Methods
void Game::DrawObjects() {
	BeginDrawing();
	ClearBackground(BLACK);

	_mainGUI->Draw();
	_bGenerator->Draw();
	EndDrawing();
}

void Game::ProcessInput() {
	// Keyboard and mouse input
	if (IsKeyPressed(KEY_R)) {
		_bGenerator->ToggleAutoMode();
		_mainGUI->ShowAutoMode(_bGenerator->AutoMode);
	}

	if (IsKeyPressed(KEY_UP)) {
		_bGenerator->IncreaseBullets();
	}

	if (IsKeyPressed(KEY_DOWN)) {
		_bGenerator->DecreaseBullets();
	}

	if (IsKeyPressed(KEY_LEFT)) {
		_bGenerator->PreviousPattern();
	}

	if (IsKeyPressed(KEY_RIGHT)) {
		_bGenerator->NextPattern();
	}

	// Colors

	if (IsKeyPressed(KEY_A)) {
		_bGenerator->ChangeTexture(KEY_A);
	}

	if (IsKeyPressed(KEY_S)) {
		_bGenerator->ChangeTexture(KEY_S);
	}

	if (IsKeyPressed(KEY_D)) {
		_bGenerator->ChangeTexture(KEY_D);
	}

	if (IsKeyPressed(KEY_F)) {
		_bGenerator->ChangeTexture(KEY_F);
	}
}

void Game::UpdateBulletCount() {
	StaticText* text = _mainGUI->_totalBulletsText.get();
	StaticText* text2 = _mainGUI->_selectedPatternText.get();
	unsigned int totalBullets = _bGenerator->ActiveBullets;
	unsigned int selectedBullets = _bGenerator->bulletsToGenerate;
	std::string patternName = _bGenerator->PatternName;
	std::string colorName = _bGenerator->currentColor;
	
	text->SetLabel("Total\nBullets: " + std::to_string(totalBullets));
	text2->SetLabel("Pattern: " + patternName + "\nColor: " + colorName + "\nBullets: " + std::to_string(selectedBullets));
}