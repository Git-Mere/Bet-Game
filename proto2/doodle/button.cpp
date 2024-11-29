// Name              : Seungheon Jeon, Sangbeom Kim, Dong - A Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include "button.h"
#include "variables.h"
#include <doodle/doodle.hpp>
#include <iostream>

using namespace doodle;
using namespace std;

CreateButton ::CreateButton(int x2, int y2, int width2, int height2, int R2, int G2, int B2, int A2, string text2, int scene2)
{
    x      = x2;
    y      = y2;
    width = width2;
    height = height2;
    R = R2;
    G = G2;
    B = B2;
    A = A2;
    buttontext = text2;
    scene = scene2;
};

void CreateButton ::SetRangeButton()
{
    double MX = get_mouse_x();
    double MY = get_mouse_y();
    int xsize = x + width;
    int ysize = y + height;
    if ((MX > x && MX < xsize) && (MY > y && MY < ysize))
    {
        mouseon = true;
        if (MouseIsPressed)
        {
            if (gamescene == 2) {
                pressed = true;
                if (turn == 1) {
                    P2guess = scene;
                }
                if (turn == 2) {
                    P1guess = scene;
                }
            }
            else if (gamescene == 1 || gamescene == 3) {
                pressed = true;
                gamescene = scene;
            }
        }
        else
            pressed = false;
    }
    else
        mouseon = false;
};

void CreateButton ::MadeColorButton()
{
    push_settings();
    if (mouseon)
    {
        if (pressed)
        {
            set_fill_color(R / 2, G / 2, B / 2, A);
        }
        else {
            set_fill_color(R, G, B, A / 2);
        }
    }
    else {
        set_fill_color(R, G, B, A);
    }
    draw_rectangle(x, y, width, height);
    pop_settings();
};

void CreateButton ::MadeText()
{
    push_settings();
    set_fill_color(255);
    set_font_size(height / 2);
    set_outline_color(0);
    draw_text(buttontext, x, y);
    pop_settings();
}
