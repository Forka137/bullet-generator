#pragma once
#include "raylib.h"
#include "TextButton.h"
#include <string>
#include <iostream>

TextButton::TextButton(std::string label, Font font) {
	Label = label;
	ttfFont = font;
	FitInRectangle();
}

TextButton::TextButton(std::string label, Vector2 position, Font font) {
	Label = label;
	RectPosition = position;
	ttfFont = font;
	FitInRectangle();
}

void TextButton::Update(float deltaTime) {
	MouseListening();
}

void TextButton::Draw() {
	DrawRectangle(RectPosition.x, RectPosition.y, Width, Height, BackgroundColor);
	DrawRectangleLines(RectPosition.x, RectPosition.y, Width, Height, BorderColor);
	DrawTextEx(ttfFont, Label.c_str(), _textPosition, FontSize, FontSpacing, TextColor);
}

void TextButton::FitInRectangle() {
	_textColor = TextColor;
	Vector2 textSize = MeasureTextEx(ttfFont, Label.c_str(), FontSize, FontSpacing);
	_minWidth = textSize.x;
	_minHeight = textSize.y;

	Width = LeftPadding + _minWidth + RightPadding;
	Height = TopPadding + _minHeight + BottomPadding;

	_textPosition.x = LeftPadding + RectPosition.x;
	_textPosition.y = TopPadding + RectPosition.y;
}

void TextButton::MouseListening() {
	Vector2 mousePos = GetMousePosition();
	// If mouse inside area
	if (mousePos.x < RectPosition.x + Width && mousePos.y < RectPosition.y + Height) {
		TextColor = HoverTextColor;
		if (!_mouseEntered) _mouseEntered = true;

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			// Fire the event
			if (!_buttonClicked) _buttonClicked = true;
			TextColor = ClickedTextColor;
		}
		else 
		{
			if (_buttonClicked) {
				TextColor = _textColor;
				_buttonClicked = false;
			}
		}
	}
	else 
	{
		if (_mouseEntered) {
			TextColor = _textColor;
			_mouseEntered = false;
		}
	}
}

bool TextButton::IsClicked() {
	return _buttonClicked;
}

bool TextButton::IsMouseOver() {
	return _mouseEntered;
}