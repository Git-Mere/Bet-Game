// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include <doodle/doodle.hpp>
#include <iostream>
#include "variables.h"
#include "button.h"
#include "game.h"
#include "put.h"
#include "gameScene.h"

using namespace doodle;
using namespace std;

gameScene doGame;

int main(int argc, char** argv)
try{
    if (argc != 1) {
        store.clear();
        store = Store(argc, argv);
        Round = static_cast<int>(store.size());
        sentence = make_string();
    }
    constexpr int WIDTH = 1280;
    constexpr int HEIGHT = 720;
    create_window("Dovengers", WIDTH, HEIGHT);
    const Image DigiPen{ "Image/DigiPen.png" };
    set_image_mode(RectMode::Center);
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        if (gamescene == 0) {
            if (doGame.TimeElapsed < 3 && doGame.alp > 1) {
                doGame.alp -= 1;
            }
            clear_background(255);
            draw_image(DigiPen, 0, 50, 482.5 * doGame.alp, 250 * doGame.alp);
        }
        doGame.sceneManage();
    }
    write();
    return 0;
}catch (const exception& e)
{
    cerr << "Error : " << e.what() << '\n';
    return -1;
}
