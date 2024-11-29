// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include "game.h"
#include "variables.h"
#include "button.h"
#include <doodle/doodle.hpp>
#include <iostream>
#include <map>

using namespace doodle;

//1 : rock, 2 : scissors, 3 : paper
//1 : draw, 2 : win, 3 : lose
constexpr void P1res() {
	switch (Comrsp) {
	case 1:
		if (P1rsp == 1) {
			P1result = 1;
		}
		if (P1rsp == 2) { 
			P1result = 3;
		}
		if (P1rsp == 3) {
			P1result = 2;
		}
		break;
	case 2:
		if (P1rsp == 1) {
			P1result = 2;
		}
		if (P1rsp == 2) {
			P1result = 1;
		}
		if (P1rsp == 3) {
			P1result = 3;
		}
		break;
	case 3:
		if (P1rsp == 1) {
			P1result = 3;
		}
		if (P1rsp == 2) {
			P1result = 2;
		}
		if (P1rsp == 3) {
			P1result = 1;
		}
		break;
	}
}

constexpr void P2res() {
	switch (Comrsp) {
	case 1:
		if (P2rsp == 1) {
			P2result = 1;
		}
		if (P2rsp == 2) {
			P2result = 3;
		}
		if (P2rsp == 3) {
			P2result = 2;
		}
		break;
	case 2:
		if (P2rsp == 1) {
			P2result = 2;
		}
		if (P2rsp == 2) {
			P2result = 1;
		}
		if (P2rsp == 3) {
			P2result = 3;
		}
		break;
	case 3:
		if (P2rsp == 1) {
			P2result = 3;
		}
		if (P2rsp == 2) {
			P2result = 2;
		}
		if (P2rsp == 3) {
			P2result = 1;
		}
		break;
	}
}

void game() {
	if (turn == 1) {
		if (P1rsp != 0) {
			P1res();
			P2select = true;
		}
		else if (P1rsp == 0) {
			push_settings();
			set_font_size(20);
			draw_text("P1 Press 'A', 'S', 'D'", -200, -250);
			draw_text("A = Rock S = Scissors D = Paper", -200, -300);
			pop_settings();
		}
		if (P2guess != 0) {
			P2select = false;
			P2betHelper();
		}

	}
	if (turn == 2) {
		if (P2rsp != 0) {
			P2res();
			P1select = true;
		}
		else if (P2rsp == 0) {
			push_settings();
			set_font_size(20);
			draw_text("P2 Press 'J', 'K', 'L'", -200, -250);
			draw_text("J = Rock K = Scissors L = Paper", -200, -300);
			pop_settings();
		}
		if (P1guess != 0) {
			P1select = false;
			P1betHelper();
		}
	}
}

constexpr void P1betHelper() {
	if (turn == 2 && P1finish == false && P1chip > 0) {
		P1betting = true;
		push_settings();
		set_font_size(20);
		draw_text("P1 Bet Coin using 'Arrow key'", -200, -250);
		pop_settings();
	}
	if (turn == 2 && P1finish == false && P1chip == 0) {
		P1nochip = true;
		push_settings();
		set_font_size(20);
		draw_text("P1 Bet Coin using 'Arrow key'", -200, -250);
		pop_settings();
	}
	if (turn == 2 && P1finish == true) {
		if (P1guess == P2result) {
			if (P2result == 2 || P2result == 3) {
				P1chip += P1bet * 2;
			}
			else if (P2result == 1) {
				P1chip += P1bet * 3;
			}
		}
		else {
			if (P2result == 1) {
				P1chip += P1bet;
			}
			if (P2result == 2 || P2result == 3) {
				P1chip = P1chip;
			}
		}
		if (P2result == 2) {
			P2chip += getchip;
		}
		chip2.push_back(P2chip);
		chip1.push_back(P1chip);
		turn = 1;
		P2rsp = 0;
		P1guess = 0;
		P1finish = false;
		P1bet = 0;
		if (gameround != Round - 1) {
			gameround += 1;
			Comrsp = Comrsp_deter();
			tool::getchip_change();
		}
		else { power = false; }
	}
}

constexpr void P2betHelper() {
	if (turn == 1 && P2finish == false && P2chip > 0) {
		P2betting = true;
		push_settings();
		set_font_size(20);
		draw_text("Bet P2 Coin using 'Arrow key'", -200, -250);
		pop_settings();
	}
	if (turn == 1 && P2finish == false && P2chip == 0) {
		P2nochip = true;
		push_settings();
		set_font_size(20);
		draw_text("Bet P2 Coin using 'Arrow key'", -200, -250);
		pop_settings();
	}
	if (turn == 1 && P2finish == true) {
		if (P2guess == P1result) {
			if (P1result == 2 || P1result == 3) {
				P2chip += P2bet * 2;
			}
			else if (P1result == 1) {
				P2chip += P2bet * 3;
			}
		}
		else if (P2guess != P1result) {
			if (P1result == 1) {
				P2chip += P2bet;
			}
			if (P1result == 2 || P1result == 3) {
				P2chip = P2chip;
			}
		}
		if (P1result == 2) {
			P1chip += getchip;
		}
		chip2.push_back(P2chip);
		chip1.push_back(P1chip);
		turn = 2;
		P1rsp = 0;
		P2guess = 0;
		P2finish = false;
		P2bet = 0;
		if (gameround != Round - 1) {
			gameround += 1;
			Comrsp = Comrsp_deter();
			tool::getchip_change();
		}
		else { power = false; }
	}
}

int Comrsp_deter() {
	char c = store[gameround];

	int i = 0;
	if (c == 'R') {
		i = 1;
	}
	else if (c == 'S') {
		i = 2;
	}
	else if (c == 'P') {
		i = 3;
	}
	return i;
}