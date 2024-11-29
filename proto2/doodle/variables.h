// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#pragma once

#include "button.h"
#include "doodle/doodle.hpp"
#include "game.h"
#include "Tool.h"
#include <unordered_map>

using namespace doodle;

//seungheon's variables
inline vector<char> store{ 'R', 'R', 'R', 'R', 'S', 'S', 'S', 'P', 'P', 'P'};
inline int Round = static_cast<int>(store.size());
inline vector<string> sentence = make_string();

inline vector<int> choice{};
inline vector<char> choice2{};
inline vector<int> bet{};
inline vector<int> Value{}; 
inline unordered_map<int, string> End{};
inline vector<int>chip1{};
inline vector<int>chip2{};

inline bool power = true;
                                               
//sangbeom's variables

inline int gamescene = 0;
inline int gameround = 0;
inline int turn = 1;

inline int P1rsp = 0;
inline int P2rsp = 0;
inline int Comrsp = Comrsp_deter();

inline int P1result = 0;
inline int P2result = 0;
inline bool P1select = false;
inline bool P2select = false;
inline int P1guess = 0;
inline int P2guess = 0;

inline int P1chip = 1;
inline int P2chip = 1;
inline int P1bet = 0;
inline int P2bet = 0;
inline bool P1nochip = false;
inline bool P2nochip = false;
inline bool P1betting = false;
inline bool P2betting = false;
inline bool P1finish = false;
inline bool P2finish = false;

inline int getchip = 1;

inline std::vector<CreateButton> Button{ CreateButton(-335, -35, 150, 70, 255, 255, 255, 255, "  Win", 2),
                                         CreateButton(-75, -35, 150, 70, 255, 255, 255, 255, "  Lose", 3),
                                         CreateButton(185, -35, 150, 70, 255, 255, 255, 255, "  Draw", 1), 
                                         CreateButton(-150, 0, 300, 80, 255, 255, 255, 255, "      Start", 2),
                                         CreateButton(-150, -170, 300, 80, 255, 255, 255, 255, "      Quit", 10),
                                         CreateButton(-150, 200, 300, 80, 255, 255, 255, 255, "      Main", 1),
                                         CreateButton(-150, 100, 300, 80, 255, 255, 255, 255, "      Quit", 10)};