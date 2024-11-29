// Name              : Seungheon Jeon, Sangbeom Kim, Dong - A Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#pragma once

#include <doodle/doodle.hpp>
#include "variables.h"

using namespace doodle;

class gameScene {
public:
    double time{ 0 };
    double alp{ 10 };
    double TimeElapsed{ 0 };
    void sceneManage();
    void reset();
};
