/*
 * Continent.h
 *
 *  Created on: 27 feb 2017
 *      Author: david
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <iostream>

using std::string;

class Player;
class Land;

class Continent {
	string name;
	int totalLands;
	Player** playerArray;
	int playerNumber;
	int* ownershipArray;
	int givenTroops;
	int find(Player* he);
public:
	Continent(string name, Player** playerList, int playerNumber, int landNumber, int givenTroops);
	virtual ~Continent();
	string getName();
	void giveLand(Player* from, Player* to);
	int troops(Player* requester);
};

#endif /* CONTINENT_H_ */
