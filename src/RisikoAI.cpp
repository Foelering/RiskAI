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
		cout << "Want to add a new player (currently "<< firstPlayer->getPlayerN() << ")? (y/N)" << endl;
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
			cout << "End? (y/N)" << endl;
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
	(landlist+5)->addNear(landlist+7);
	(landlist+5)->addNear(landlist+34);
	(landlist+6)->addNear(landlist+5);
	(landlist+6)->addNear(landlist+7);
	(landlist+6)->addNear(landlist+8);
	(landlist+6)->addNear(landlist+9);
	(landlist+6)->addNear(landlist+12);
	(landlist+7)->addNear(landlist+8);
	(landlist+7)->addNear(landlist+35);
	(landlist+8)->addNear(landlist+9);
	(landlist+8)->addNear(landlist+35);
	(landlist+9)->addNear(landlist+10);
	(landlist+9)->addNear(landlist+11);
	(landlist+9)->addNear(landlist+12);
	(landlist+10)->addNear(landlist+11);
	(landlist+10)->addNear(landlist+14);
	(landlist+11)->addNear(landlist+12);
	(landlist+11)->addNear(landlist+13);
	(landlist+13)->addNear(landlist+14);
	(landlist+14)->addNear(landlist+15);
	(landlist+15)->addNear(landlist+16);
	(landlist+15)->addNear(landlist+20);
	(landlist+16)->addNear(landlist+17);
	(landlist+16)->addNear(landlist+19);
	(landlist+16)->addNear(landlist+20);
	(landlist+17)->addNear(landlist+18);
	(landlist+17)->addNear(landlist+19);
	(landlist+17)->addNear(landlist+37);
	(landlist+18)->addNear(landlist+19);
	(landlist+18)->addNear(landlist+22);
	(landlist+19)->addNear(landlist+20);
	(landlist+19)->addNear(landlist+21);
	(landlist+19)->addNear(landlist+22);
	(landlist+20)->addNear(landlist+21);
	(landlist+21)->addNear(landlist+22);
	(landlist+21)->addNear(landlist+23);
	(landlist+22)->addNear(landlist+23);
	(landlist+23)->addNear(landlist+24);
	(landlist+24)->addNear(landlist+25);
	(landlist+24)->addNear(landlist+27);
	(landlist+25)->addNear(landlist+26);
	(landlist+25)->addNear(landlist+27);
	(landlist+26)->addNear(landlist+27);
	(landlist+27)->addNear(landlist+28);
	(landlist+28)->addNear(landlist+29);
	(landlist+28)->addNear(landlist+32);
	(landlist+28)->addNear(landlist+33);
	(landlist+28)->addNear(landlist+39);
	(landlist+28)->addNear(landlist+40);
	(landlist+29)->addNear(landlist+30);
	(landlist+29)->addNear(landlist+32);
	(landlist+30)->addNear(landlist+31);
	(landlist+31)->addNear(landlist+32);
	(landlist+32)->addNear(landlist+33);
	(landlist+32)->addNear(landlist+34);
	(landlist+33)->addNear(landlist+34);
	(landlist+33)->addNear(landlist+40);
	(landlist+34)->addNear(landlist+35);
	(landlist+34)->addNear(landlist+40);
	(landlist+35)->addNear(landlist+36);
	(landlist+35)->addNear(landlist+40);
	(landlist+35)->addNear(landlist+41);
	(landlist+36)->addNear(landlist+37);
	(landlist+36)->addNear(landlist+38);
	(landlist+36)->addNear(landlist+41);
	(landlist+37)->addNear(landlist+38);
	(landlist+38)->addNear(landlist+39);
	(landlist+38)->addNear(landlist+41);
	
	
	int n = landlist->getLandNumber();
	
	for (int i = 0; n-1-i; i++) {
		(landlist+i)->setNext(landlist+i+1);
	}

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

	int troopCounter;
	switch(activePlayer->getPlayerN()){
	case 2:
		troopCounter=40;
		break;
	case 3:
		troopCounter=35;
		break;
	case 4:
		troopCounter=30;
		break;
	case 5:
		troopCounter=25;
		break;
	case 6:
		troopCounter=20;
		break;
	default:
		troopCounter=15;
		break;
	}

	Player* firstPlayer = activePlayer;

	do {
		activePlayer->obtainTroops(troopCounter);
		activePlayer->populateLands();
		activePlayer = activePlayer->next();
	} while (activePlayer!=firstPlayer);

	do {
		activePlayer->initialTroopSet();
		activePlayer = activePlayer->next();
	} while(--troopCounter);

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
