/*
 * Land.h
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#ifndef LAND_H_
#define LAND_H_

#include "Player.h"

class Land {
	Player* owner;
	int troops;
	Land** confining;
public:
	Land();
	Land(Land* list[]);
	virtual ~Land();
	Player* getOwner();
	Land** nearTo();
	bool nearTo(Land* that);
	int putTroops(int many);
	int attack(Land* defender, int troops);
	int defend(Player *attacker, int attacking);
	void addNear(Land* newNear);
};

#endif /* LAND_H_ */
