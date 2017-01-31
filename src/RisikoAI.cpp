//============================================================================
// Name        : RisikoAI.cpp
// Author      : David Chiappini
// Version     :
// Copyright   : GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Player.h"
#include "Land.h"

using namespace std;

int main() {
	srand(time(NULL));
	Land ottawa;
	Land etruria;
	cout << "oi!" << endl;
	ottawa.putTroops(4);
	etruria.putTroops(3);
	ottawa.attack(&etruria,3);
	ottawa.addNear(&etruria);
	ottawa.attack(&etruria, 4);
	ottawa.attack(&etruria, 3);
	cout << "Ottawa troops: " << ottawa.putTroops(0) << "\t Etruria troops: " << etruria.putTroops(0) << endl;
	cout << "Ottawa near to Etruria: " <<ottawa.nearTo(&etruria)<< endl;
	return 0;

}
