#pragma once
#include "MainGUI.h"
#include "TextButton.h"
#include "TemporalText.h"
#include "StaticText.h"
#include <memory>
#include <iostream>


MainGUI::MainGUI() {
	// Help Button
	_helpButton = std::make_unique<TextButton>("Controls", _font);
	_helpText = std::make_unique<TemporalText>(
		"R to toggle full auto mode\n"
		"Up/Down to change number of balls\n"
		"Left/Right to change patterns\n\n"
		"A,S,D,F to change colors",
		Vector2{100.0, 100.0}, 10.0, _font);

	_autoText = std::make_unique<TemporalText>(
		"Full Auto is: ",
		Vector2{ 500.0, 550.0 }, 3.0, _font);

	_totalBulletsText = std::make_unique<StaticText>("Total\nBullets: 0", Vector2{640, 20}, _font);
	_selectedPatternText = std::make_unique<StaticText>("Selected\nBullets: 0", Vector2{ 20, 520 }, _font);

	_signatureText = std::make_unique<TemporalText>(
		"Forka137 - 2022 ",
		Vector2{ 630.0, 580.0 }, 5.0, _font);

	_signatureText->TextColor = GOLD;
	
	_helpText->Opacity = 0;
	_autoText->Opacity = 0;

	AddElement(_helpButton.get());
	AddElement(_helpText.get());
	AddElement(_autoText.get());
	AddElement(_totalBulletsText.get());
	AddElement(_selectedPatternText.get());
	AddElement(_signatureText.get());
}

void MainGUI::Process() {
	ShowHelp();
}

void MainGUI::ShowHelp() {
	if (_helpButton->IsClicked()) {
		_helpText->Show();
	}
}

void MainGUI::ShowAutoMode(bool value) {
	if (value) {
		_autoText->SetLabel("FULL AUTO mode is ON");
		_autoText->TextColor = RED;
	}
	else {
		_autoText->SetLabel("Full auto mode is OFF");
		_autoText->TextColor = WHITE;
	}
	_autoText->Show();
}