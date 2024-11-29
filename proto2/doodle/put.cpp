// Name              : Seungheon Jeon, Sangbeom Kim, Donga Choi
// Assignment Name   : Game Prototype 2
// Course            : CS120
// Term & Year       : fall/2020

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "variables.h"
#include "Tool.h"

using namespace std;

vector<char> Store(int argc, char** argv) {
	vector<char> result{};
	int check = 0;
	if (argc != 1) {
		ifstream input{ argv[1] };
		if (!input)
			throw runtime_error{ "Failed to read file" };
		if (argv[2])
			throw runtime_error{ "Please input only 1 file." };
		char value;
		while (input >> value) {
			if (value <= 83 && value >= 80) {
				result.push_back(value);
				check++;
			}
		}
		if (check < 10 || check > 20)
			throw runtime_error{ "Check your round range" };
	}
	return result;
}

void write() {
	ofstream result{ "result.txt" };
	tool::choice_change();
	tool::value_change();
	for (int i = 0; i < gameround; i++) {
		result << "Round" << '\t' << i + 1 << '\n' << '\n';
		result << "Open" << '\t' << store[i] << '\n';
		if (i % 2 == 0) {
			result << "P1 RSP" << '\t' << choice2[i] << '\n';
			result << "P2 bet" << '\t' << bet[i] << '\n';
		}
		else if (i % 2 == 1) {
			result << "P1 bet" << '\t' << bet[i] << '\n';
			result << "P2 RSP" << '\t' << choice2[i] << '\n';
		}
		result << "Result" << '\t' << End[i] << '\n';
		result << "P1 Chip" << '\t' << chip1[i] << '\n';
		result << "P2 Chip" << '\t' << chip2[i] << '\n' << '\n';
	}
	if (gameround == Round - 1) {
		result << "Round" << '\t' << gameround + 1 << '\n' << '\n';
		result << "Open" << '\t' << store[gameround] << '\n';
		if (gameround % 2 == 0) {
			result << "P1 RSP" << '\t' << choice2[gameround] << '\n';
			result << "P2 bet" << '\t' << bet[gameround] << '\n';
		}
		else if (gameround % 2 == 1) {
			result << "P1 bet" << '\t' << bet[gameround] << '\n';
			result << "P2 RSP" << '\t' << choice2[gameround] << '\n';
		}
		result << "Result " << '\t' << End[gameround] << '\n';
		result << "P1 Chip" << '\t' << chip1[gameround] << '\n';
		result << "P2 Chip" << '\t' << chip2[gameround] << '\n' << '\n';
	}
}