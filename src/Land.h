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
	Land* nextLand;			//next link in the chain
	Land** confining;		//array of confining lands
public:
	Land(string name, Continent* continent);
	Land(string name, Land* next, Continent* continent);
	virtual ~Land();
	string getName();
	void setName(string newName);
	unsigned int getLandNumber();
	Land** nearTo();
	bool nearTo(Land* that);		//checks whether that is near to this
	int putTroops(int many);		//increments troops by many
	int attack(Land* defender);		//checks whether defender is near, then proceeds to prompt him to defend
	int defend(int attacking);		//simulates the roll of dice, decrements troops, returns number of attacking troops destroyed
	Player* getOwner();
	void setOwner(Player* newOwner);
	void addNear(Land* newNear);
	void setNext(Land* newNext);
	Land* next();					//returns nextLand
};

#endif /* LAND_H_ */
