/*
 * Player.h
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <cstdlib>
#include "Land.h"

using std::string;

class Player {
protected:
	string name;
	Land* land;
	int ownedlands;
	int troopPool;
	Player* nextPlayer;

public:
	Player();
	Player(string namer, Player* next);
	virtual ~Player();
	string getName();
	void attack(Land* from, Land* to);
	int obtainTroops();
	int obtainTroops(int n);
	int putTroops(Land* land, int n);
	void takeLand(Land* newLand);
	void removeLand(Land* thisLand);
	bool has(Land* thisLand);

	Player* next() {
		return nextPlayer;
	}

	void setNext(Player* newNext) {
		nextPlayer = newNext;
	}

	virtual void putTroops() {
		return;
	}

	virtual void makeTurn() {
		return;
	}

	bool checkWinCondition() {
		return ownedlands>24;
	}
};


#endif /* PLAYER_H_ */
