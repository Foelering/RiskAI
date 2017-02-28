/*
 * Land.h
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#ifndef LAND_H_
#define LAND_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Continent.h"

using std::string;

class Player;
class Continent;

class Land {
	static unsigned int numberoflands;
	string name;
	int troops;
	Player* owner;
	Continent* continent;
	Land* nextLand;
	Land** confining;
public:
	Land(string name, Continent* continent);
	Land(string name, Land* next, Continent* continent);
	virtual ~Land();
	string getName();
	void setName(string newName);
	unsigned int getLandNumber();
	Land** nearTo();
	bool nearTo(Land* that);
	int putTroops(int many);
	int attack(Land* defender);
	int defend(int attacking);
	Player* getOwner();
	void setOwner(Player* newOwner);
	void addNear(Land* newNear);
	void setNext(Land* newNext);
	Land* next();
};

#endif /* LAND_H_ */
