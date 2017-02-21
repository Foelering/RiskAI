//============================================================================
// Name        : RisikoAI.cpp
// Author      : David Chiappini
// Version     :
// Copyright   : GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

#include "Player.h"
#include "HumanPlayer.h"
#include "Land.h"

using namespace std;

Player* generatePlayerList () {
	string name;
	cout << "First (human) player name: ";
	cin >> name; cout << endl;
	Player* firstPlayer = new HumanPlayer(name, 0);
	cout << "Second (human) player name: ";
	cin >> name; cout << endl;
	firstPlayer->setNext(new HumanPlayer(name, firstPlayer));
	Player* nextinQueue = firstPlayer->next();
	int i=1;

	while (i) {
		cout << "Want to add a new player? (y/N)" << endl;
		char a;
		cin >> a;

		switch (a) {
		case 'y':
			cout << "Name: ";
			cin >> name; cout << endl;
			nextinQueue->setNext(new HumanPlayer(name, firstPlayer));
			cout << nextinQueue->getName() << nextinQueue->next()->getName()<<endl;
			nextinQueue = nextinQueue->next();
			break;
		default:
			cout << "Configuration is:" << endl;
			cout << "\t" << firstPlayer->getName() << "\n";
			for(nextinQueue = firstPlayer->next(); nextinQueue!=firstPlayer; nextinQueue = nextinQueue->next()){
				cout << "\t" << nextinQueue->getName() << "\n";
			}
			char q;
			cout << "End? " << endl;
			cin >> q;
			if (q == 'y') {  i=0; }
			break;
		}


	}

	return firstPlayer;
}

Land* generateLands() {
	cout << "Generating map..." << endl;
	Land* landlist = (Land*) ::operator new (sizeof(Land)*42);
	new (landlist) Land("Eastern Australia");
	new (landlist+1) Land("Western Australia");
	(landlist+1)->addNear(landlist);
//	landlist[1].addNear(landlist);
//	landlist[2].setName("New Guinea");
//	landlist[2].addNear(landlist);
//	landlist[2].addNear(landlist+1);
//	landlist[3].setName("Indonesia");
//	landlist[3].addNear(landlist+2);
//	landlist[3].addNear(landlist+1);
//	landlist+4 = 0;

	return landlist;
}

void distributeLands (Player* activePlayer, Land* list) {
	cout << "distributing lands..." << endl;
	int n = list->getLandNumber();
	cout << n << endl;
	Land* taken;

	for ( ; n>0; --n ) {
		int r = rand()%n;
		int i=0;
		for(; r; ++i) {
			if(!(list+i)->getOwner()) {
				--r;
			}
		}
		activePlayer->takeLand(list+i);
		activePlayer = activePlayer->next();
	}

	return;
}

int main() {
	srand(time(NULL));
	for (int i = 1; i==100; i++) {
		cout << rand()%2 << "." << i << endl;
	}

	Player* activePlayer = generatePlayerList();

	distributeLands(activePlayer, generateLands());

	while (1) {
		activePlayer->makeTurn();
		if(activePlayer->checkWinCondition()) {
			break;
		}
		activePlayer = activePlayer->next();
	}

	cout << activePlayer->getName() << " has gained 24 lands and won!" << endl;

	return 0;
}
