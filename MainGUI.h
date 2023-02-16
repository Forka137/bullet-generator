#pragma once
#include "BaseGUI.h"
#include "TextButton.h"
#include "TemporalText.h"
#include "StaticText.h"
#include <memory>
#include <iostream>

class MainGUI :
    public BaseGUI
{
public:
    MainGUI();

    std::unique_ptr<TextButton> _helpButton;
    std::unique_ptr<TemporalText> _helpText;
    std::unique_ptr<TemporalText> _autoText;
    std::unique_ptr<TemporalText> _signatureText;

    std::unique_ptr<StaticText> _totalBulletsText;
    std::unique_ptr<StaticText> _selectedPatternText;
    
    void Process();
    
    // User Input
    void ShowHelp();
    void ShowAutoMode(bool value);
private:
    Font _font = LoadFontEx("resources/anonymous_pro_bold.ttf", 16, 0, 256);
};

