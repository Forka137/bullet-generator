#pragma once
#include "GUIElement.h"
#include "raylib.h"
#include <string>

class TextButton :
    public GUIElement
{
public:
    TextButton(std::string label, Font font);
    TextButton(std::string label, Vector2 position, Font font);
    std::string Label = "Button";
    Color BorderColor = Color{ 200, 200, 200, 255 };
    Color BackgroundColor = DARKGRAY;
    Color TextColor = RAYWHITE;
    Color HoverTextColor = GOLD;
    Color ClickedTextColor = Color{ 200, 200, 200, 255 }; 

    unsigned int FontSize = 16;
    unsigned int FontSpacing = 2;

    unsigned int LeftPadding = 4;
    unsigned int RightPadding = 4;
    unsigned int TopPadding = 2;
    unsigned int BottomPadding = 2;

    void Update(float deltaTime);
    void Draw();

    bool IsClicked();
    bool IsMouseOver();
    Font ttfFont;

private:
    Vector2 _textPosition = { 0, 0 };
    Color _textColor;

    void MouseListening();
    unsigned int _minHeight = 0;
    unsigned int _minWidth = 0;
    void FitInRectangle();

    bool _mouseEntered = false;
    bool _buttonClicked = false;
};

