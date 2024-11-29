// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#pragma once
#include <iostream>

using namespace std;

class CreateButton
{
private:
    bool   mouseon   = false;
    bool   pressed = false;
    bool   clicked = false;

public:
    CreateButton() = default;
    int x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 }, R{ 0 }, G{ 0 }, B{ 0 }, A{ 0 }, scene{ 0 };
    string buttontext;
    CreateButton(int x2, int y2, int width2, int height2, int R2, int G2, int B2, int A2, string text2, int scene2);
    void MadeColorButton();
    void MadeText();
    void SetRangeButton();
    void ButtonControl()
    {
        SetRangeButton();
        MadeColorButton();
        MadeText();
    };
};
