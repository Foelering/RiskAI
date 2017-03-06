/*
 * HumanPlayer.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: david
 */

#include "HumanPlayer.h"
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;

HumanPlayer::HumanPlayer(string namer, Player* next) : Player(namer, next) {

}

HumanPlayer::~HumanPlayer() {
	// TODO Auto-generated destructor stub
}

void HumanPlayer::populateLands() {
	putTroops(land, 1);
	for(Land* pointer = land; pointer; pointer = pointer->next()) {
		putTroops(pointer->next(), 1);
		--troopPool;
	}
}

void HumanPlayer::initialTroopSet() {
	if(!troopPool){
		return;
	}
	cout << getName() << ", tell me where do you want to put a troop?" << endl;
	int i = 1, l=0, n=1;
	Land* pointer;
	for (pointer = land; pointer; pointer=pointer->next()) {
		cout << "\t" << i << ". " << pointer->getName() << endl;
		i++;
	}
	while(1){
		cin >> l;
		if(l<=ownedlands && l>0){
			break;
		}
		cout << "Not valid!" << endl;
	}
	pointer = land;
	for (i = 0; i < l-1; i++) {
		pointer=pointer->next();
	}
	putTroops(pointer, 1);
	cout << getName() << " has put a troop on " << pointer->getName() << "\n" << endl;
}

void HumanPlayer::makeTurn() {
	cout << name << " is on. " << generateCallToArms() << endl;
	obtainTroops();
	while(troopPool) {
		cout << "Where do you want to put these " << troopPool << " troops? Available options are:\n";
		int i = 1, l=0, n=1;
		Land* pointer;
		for (pointer = land; pointer; pointer=pointer->next()) {
			cout << "\t" << i << ". " << pointer->getName() << endl;
			i++;
		}
		cin >> l;
		pointer = land;
		for (i = 0; i < l-1; i++) {
			pointer=pointer->next();
		}
		cout << "How many troops?\n";
		cin >> n;
		if (n > troopPool || n<0) { cout << "Not a valid value!" << endl; }
		else { putTroops(pointer, n); }
	}
	int i = 1;
	while(i){
		cout << "Want to attack? (y/N)" << endl;
		char a;
		cin >> a;
		switch (a) {
		case ('y'):
				attackPrompt();
				break;
		case ('Y'):
				attackPrompt();
				break;
		default:
				i=0;
				break;
		}
	}
}

void HumanPlayer::attackPrompt() {//literally an attack prompt. I know this is messy, if you find a way to fix, tell me!
	cout << "Which land you own do you want to attack from?" << endl;
	int i=1, a = 0, d = 0;
	for(Land* pointer = land; pointer; pointer = pointer->next()) {
		cout << i << ". " << pointer->getName() << endl;
		i++;
	}
	while (1) {
		cout << "Land ( 0 to exit): ";
		cin >> a;
		cout << endl;
		if (!a){
			cout << "Exit";
			return;
		} else if (a >= i) {
			cout << "Not a valid number!" << endl;
		} else {
			break;
		}
	}
	Land* attacker;
	Land * defender;
	for (attacker = land; a-1; attacker = attacker->next()) {
		a--;
	}
	cout << "Choose where to attack!" << endl;
	Land** confiners = attacker->nearTo();

	for (i=0; confiners[i]; i++) {
		cout << i+1 << ". " << confiners[i]->getName() << endl;
	}

	while(1){
		cout << "Land: (0 to exit)";
		cin >> d;
		cout << endl;

		if (d<i+1 && d > 0) {
			attack(attacker, confiners[d-1]);
			return;
		} else if (d == 0) {
			return;
		} else {
			cout << "You put an invalid number, you naughty boy!" << endl;
		}
	}

}

string HumanPlayer::generateCallToArms() {
	int r = rand()%11;
	string s;
	switch (r){
	case (0):
			return "Make them suffer!";
	case (1):
			return "You filthy scumbag!";
	case (2):
			return "There will be no prisoners!";
	case (3):
			return "Sharp your weapons!";
	case (4):
			return "Someone needs a good spanking!";
	case (5):
			return "I'm counting on you!";
	case (6):
			return "...Hey! I thought you were dead already!";
	case (7):
			return "I have no more cringey phrases to tell to you scoundrels...";
	case (8):
			return "C'mon beat them! I need to prepare dinner!";
	case (9):
			return "I haven't got all daaay!";
	case (10):
			return "Take your tanks and beat the crap out of that smartass over there!";
	case (11):
			return "I used to be a player like you, then I took a die in the knee.";
	default:
			return "David probably fucked up with the random counter.";
	}

}
