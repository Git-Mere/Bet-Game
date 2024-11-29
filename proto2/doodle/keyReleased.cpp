// Name              : Seungheon Jeon, Sangbeom Kim, Dong - A Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include <doodle/doodle.hpp>
#include "variables.h"

void on_key_released(KeyboardButtons button) {
    if (button == KeyboardButtons::Escape) {
        close_window();
    }
    if (turn == 1) {
        if (button == KeyboardButtons::A) {
            P1rsp = 1;
            choice.push_back(P1rsp);
        }
        if (button == KeyboardButtons::S) {
            P1rsp = 2;
            choice.push_back(P1rsp);
        }
        if (button == KeyboardButtons::D) {
            P1rsp = 3;
            choice.push_back(P1rsp);
        }
        if (P2betting == true) {
            if (P2chip > 0) {
                if (button == KeyboardButtons::Up) {
                    P2bet += 1;
                    P2chip -= 1;
                }
            }
            if (P2bet > 0) {
                if (button == KeyboardButtons::Down) {
                    P2bet -= 1;
                    P2chip += 1;
                }
                if (button == KeyboardButtons::Enter) {
                    bet.push_back(P2bet);
                    Value.push_back(P1result);
                    P2betting = false;
                    P2finish = true;
                }
            }
        }
        if (P1nochip == true) {
            if (button == KeyboardButtons::Enter) {
                bet.push_back(P2bet);
                Value.push_back(P1result);
                P2finish = true;
            }
        }
    }
    if (turn == 2) {
        if (button == KeyboardButtons::J) {
            P2rsp = 1;
            choice.push_back(P2rsp);
        }
        if (button == KeyboardButtons::K) {
            P2rsp = 2;
            choice.push_back(P2rsp);
        }
        if (button == KeyboardButtons::L) {
            P2rsp = 3;
            choice.push_back(P2rsp);
        }
        if (P1betting == true) {
            if (P1chip > 0) {
                if (button == KeyboardButtons::Up) {
                    P1bet += 1;
                    P1chip -= 1;
                }
            }
            if (P1bet > 0) {
                if (button == KeyboardButtons::Down) {
                    P1bet -= 1;
                    P1chip += 1;
                }
                if (button == KeyboardButtons::Enter) {
                    bet.push_back(P1bet);
                    Value.push_back(P2result);
                    P1betting = false;
                    P1finish = true;
                }
            }
        }
        if (P2nochip == true) {
            if (button == KeyboardButtons::Enter) {
                bet.push_back(P1bet);
                Value.push_back(P2result);
                P1finish = true;
            }
        }
    }
}