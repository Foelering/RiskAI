/*
 * Land.h
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#ifndef LAND_H_
#define LAND_H_

class Land {
	Land *confining[16];
	int troops=0;
	Player *owner=0;
public:
	Land();
	virtual ~Land();
	Player getOwner();
	Land *nearTo();
	bool nearTo(Land that);
	int putTroops(int many);
	int attack(Land defender, int troops);
	int defend(Player *attacker, int attacking);
};

#endif /* LAND_H_ */
