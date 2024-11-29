// Name              : Seungheon Jeon, Sangbeom Kim, Dong - A Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include "gameScene.h"

void gameScene::sceneManage() {
    TimeElapsed += (ElapsedTime - time);
    time = ElapsedTime;
    if (gamescene == 10) {
        close_window();
    }
    if (gamescene == 0) {

        if (TimeElapsed > 3)
        {
            TimeElapsed = 0;
            alp = 0;
            gamescene = 1;
        }
    }
    if (gamescene == 1) {
        reset();
        push_settings();
        set_fill_color(0);
        set_outline_color(255);
        set_font_size(60);
        draw_text("Betting Rock Scissors Paper", -530, 150);
        set_font_size(15);
        draw_text("All content c 2020 DigiPen (USA) Corporation, all rights reserved.", -530, -300);
        draw_text("Team : ", 360, -240);
        draw_text("Dovengers", 430, -240);
        draw_text("Seungheon Jeon", 430, -260);
        draw_text("Sangbeom Kim", 430, -280);
        draw_text("Dong - A Choi", 430, -300);
        pop_settings();
        for (int i = 3; i < 5; i++) {
            Button[i].ButtonControl();
        }
    }
    if (gamescene == 2) {
        if (power == true) {
            draw_text(to_string(gameround + 1), 40, 270);
            draw_text("Round :", -245, 270);
            draw_text(sentence[gameround], 40, 60);
            draw_text("Open :", -200, 60);
            draw_text(to_string(getchip), 40, 130);
            draw_text("Win Bonus :", -390, 130);
            draw_text(to_string(turn), 80, 200);
            draw_text("Turn : P", -195, 200);
            game();
        }
        tool::drawtext();
        if (P1select == true) {
            for (int i = 0; i < 3; i++) {
                Button[i].ButtonControl();
            }
            push_settings();
            set_font_size(20);
            draw_text("P1 Guess P2's result", -200, -250);
            pop_settings();
        }
        if (P2select == true) {
            for (int i = 0; i < 3; i++) {
                Button[i].ButtonControl();
            }
            push_settings();
            set_font_size(20);
            draw_text("P2 Guess P1's result", -200, -250);
            pop_settings();
        }
        tool::winner();
    }
    if (gamescene == 3) {
        tool::drawtext();
        tool::winner();
        for (int i = 5; i < 7; i++) {
            Button[i].ButtonControl();
        }
    }
}

void gameScene::reset() {
    choice = {};
    choice2 = {};
    bet = {};
    Value = {};
    End = {};
    chip1 = {};
    chip2 = {};

    power = true;

    gameround = 0;
    turn = 1;

    P1rsp = 0;
    P2rsp = 0;

    Comrsp = Comrsp_deter();

    P1result = 0;
    P2result = 0;
    P1select = false;
    P2select = false;
    P1guess = 0;
    P2guess = 0;

    P1chip = 1;
    P2chip = 1;
    P1bet = 0;
    P2bet = 0;
    P1nochip = false;
    P2nochip = false;
    P1betting = false;
    P2betting = false;
    P1finish = false;
    P2finish = false;
    getchip = 1;
};
