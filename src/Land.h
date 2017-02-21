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

using std::string;

class Player;

class Land {
	static unsigned int numberoflands;
	string name;
	int troops;
	Player* owner;
	Land* nextLand;
	Land** confining;
public:
	Land(string name);
	Land(string name, Land* next);
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
