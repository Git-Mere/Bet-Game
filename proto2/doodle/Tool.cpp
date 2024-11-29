// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include <string>
#include "variables.h"
#include "Tool.h"

std::vector<string> make_string() {
	std::vector<string> sen;
	for (char c : store) {
		if (c == 'R') {
			sen.push_back("Rock");
		}
		else if (c == 'S') {
			sen.push_back("Scissors");
		}
		else if (c == 'P') {
			sen.push_back("Paper");
		}
	}
	return sen;
}

void tool::winner() {
	if (power == false) {
		gamescene = 3;
		push_settings();
		set_font_size(40);

		if (P1chip > P2chip) {
			draw_text("Player1 Win!!", -160, 0);
		}
		else if (P2chip > P1chip) {
			draw_text("Player2 Win!!", -160, 0);
		}
		else if (P1chip == P2chip) {
			draw_text("Draw", -250, 0);
		}
		pop_settings();
	}
}

void tool::choice_change() {
	for (int i : choice) {
		if (i == 1) {
			choice2.push_back('R');
		}
		else if (i == 2) {
			choice2.push_back('S');
		}
		else if (i == 3) {
			choice2.push_back('P');
		}
	}
}

void tool::value_change() {
	for (int i = 0; i < Value.size(); i++) {
		if (Value[i] == 1) {
			End.insert(std::pair<int, string>(i, "Draw"));
		}
		else if (Value[i] == 2) {
			End.insert(std::pair<int, string>(i, "Win"));
		}
		else if (Value[i] == 3) {
			End.insert(std::pair<int, string>(i, "Lose"));
		}
	
	}
}

void tool::getchip_change() {
	int i = Round / 3;
	int j = Round % 3 - 1;
	if (gameround <= (i + j)) {
		getchip = 1;
	}
	if (gameround <= (i * 2 + j) && gameround > (i + j)) {
		getchip = 2;
	}
	else if (gameround <= (i * 3 + j) && gameround > (i * 2 + j)) {
		getchip = 3;
	}
}

void tool::drawtext() {
	draw_text(to_string(P1chip), -340, -195);
	draw_text(to_string(P2chip), 300, -195);
	draw_text(to_string(P1bet), -340, -135);
	draw_text(to_string(P2bet), 300, -135);
	push_settings();
	set_font_size(20);
	draw_text("P1's Chip", -490, -160);
	draw_text("P2's Chip", 370, -160);
	draw_text("P1's Bet", -490, -110);
	draw_text("P2's Bet", 370, -110);
	pop_settings();
	push_settings();
	if ((turn == 1 && P2select == false && P2betting == false) || (turn == 2 && (P1select == true || P1betting == true))) {
		set_outline_color(255, 0, 0);
		set_outline_width(5);
		draw_ellipse(-300, -240, 100, 100);
		set_outline_color(0);
		set_outline_width(1);
		draw_ellipse(300, -240, 100, 100);
	}
	if ((turn == 2 && P1select == false && P1betting == false) || (turn == 1 && (P2select == true || P2betting == true))) {
		set_outline_color(0);
		set_outline_width(1);
		draw_ellipse(-300, -240, 100, 100);
		set_outline_color(255, 0, 0);
		set_outline_width(5);
		draw_ellipse(300, -240, 100, 100);
	}
	pop_settings();
	push_settings();
	set_font_size(20);
	draw_text("P1", -315, -255);
	draw_text("P2", 285, -255);
	pop_settings();
}