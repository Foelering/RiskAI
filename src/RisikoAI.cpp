//============================================================================
// Name        : RisikoAI.cpp
// Author      : David Chiappini
// Version     :
// Copyright   : GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Player.h"
#include "HumanPlayer.h"
#include "Land.h"

using namespace std;

int main() {
	srand(time(NULL));
	for (int i = 1; i==100; i++) {
		cout << rand()%2 << "." << i << endl;
	}
	Land ottawa("Ottawa");
	Land* i[2];
	i[0] = &ottawa;
	i[1] = NULL;
	cout << i[0] << "  " << i[1] << endl;
	Land etruria("Etruria", i);
	Player federico("Barbarossa");
	HumanPlayer lodovico("Il Moro");
	cout << "oi!" << endl;
	lodovico.takeLand(&etruria);
	federico.takeLand(&ottawa);
	ottawa.putTroops(4);
	etruria.putTroops(3);
	lodovico.makeTurn();
	cout << "Ottawa troops: " << ottawa.putTroops(0) << "\t Etruria troops: " << etruria.putTroops(0) << endl;
	cout << "Ottawa near to Etruria: " <<ottawa.nearTo(&etruria)<< endl;
	return 0;

}
