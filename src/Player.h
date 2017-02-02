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
private:
	string name;
	Land* land;
	int ownedlands;
	int troopPool;
public:
	Player(string namer);
	virtual ~Player();
	string getName();
	void attack(Land* from, Land* to);
	int obtainTroops();
	int obtainTroops(int n);
	int putTroops(Land* land, int n);
	void takeLand(Land* newLand);
	void removeLand(Land* thisLand);
	bool has(Land* thisLand);
};


#endif /* PLAYER_H_ */
