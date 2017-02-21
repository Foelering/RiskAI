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
	new (landlist+2) Land("New Guinea");
	new (landlist+3) Land("Indonesia");
	new (landlist+4) Land("Siam");
	new (landlist+5) Land("India");
	new (landlist+6) Land("China");
	new (landlist+7) Land("Afghanistan");
	new (landlist+8) Land("Ural");
	new (landlist+9) Land("Siberia");
	new (landlist+10) Land("Yakutsk");
	new (landlist+11) Land("Irkutsk");
	new (landlist+12) Land("Mongolia");
	new (landlist+13) Land("Japan");
	new (landlist+14) Land("Kamchatka");
	new (landlist+15) Land("Alaska");
	new (landlist+16) Land("North West Territory");
	new (landlist+17) Land("Greenland");
	new (landlist+18) Land("Quebec");
	new (landlist+19) Land("Ontario");
	new (landlist+20) Land("Alberta");
	new (landlist+21) Land("Western United States");
	new (landlist+22) Land("Eastern United States");
	new (landlist+23) Land("Central America");
	new (landlist+24) Land("Venezuela");
	new (landlist+25) Land("Peru");
	new (landlist+26) Land("Argentina");
	new (landlist+27) Land("Brasil");
	new (landlist+28) Land("North Africa");
	new (landlist+29) Land("Congo");
	new (landlist+30) Land("South Africa");
	new (landlist+31) Land("Madagascar");
	new (landlist+32) Land("East Africa");
	new (landlist+33) Land("Egypt");
	new (landlist+34) Land("Middle East");
	new (landlist+35) Land("Ukraine");
	new (landlist+36) Land("Scandinavia");
	new (landlist+37) Land("Iceland");
	new (landlist+38) Land("Great Britain");
	new (landlist+39) Land("Western Europe");
	new (landlist+40) Land("Southern Europe");
	new (landlist+41) Land("Northern Europe");
	(landlist+1)->addNear(landlist);
	(landlist+2)->addNear(landlist);
	(landlist+2)->addNear(landlist+1);
	(landlist+3)->addNear(landlist+1);
	(landlist+3)->addNear(landlist+2);
	(landlist+4)->addNear(landlist+3);
	(landlist+4)->addNear(landlist+5);
	(landlist+4)->addNear(landlist+6);
	(landlist+6)->addNear(landlist+5);
	(landlist+6)->addNear(landlist+7);
	(landlist+6)->addNear(landlist+8);
	(landlist+6)->addNear(landlist+9);
	(landlist+6)->addNear(landlist+12);
	
	int n = landlist->getLandNumber();
	
	for (int i = 0; n-1-i; i++) {
		(landlist+i)->setNext(landlist+i+1);
	}
	
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
	Player* rotator = activePlayer;
	cout << "distributing lands..." << endl;
	int n = list->getLandNumber();
	cout << n << endl;
	int r;
	Land* bookmark;
	Land* out;

	for ( ; n>1; --n ) {
		cout << "counter: " << n << endl;
		bookmark = list;
		
		r = rand()%n;
		
		cout << r << endl;
		
		if(r){
			while(--r) {
				//cout << r << " " << bookmark->getName() << endl;
				bookmark = bookmark->next();
			}
			//cout << "0 " << bookmark->getName()
			out = bookmark->next();
			bookmark->setNext(out->next());
			
		} else {
			
			out = list;
			list = list->next();
			cout << list->getName() << endl;
			
		}
		
		cout << out-> getName() << endl;
		
		rotator->takeLand(out);
		rotator = rotator->next();
		cout << rotator->getName() << endl;
	}
	
	rotator->takeLand(list);

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
