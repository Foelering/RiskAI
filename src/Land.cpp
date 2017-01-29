/*
 * Land.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */
#include <cstdlib>
#include "Land.h"

Land::Land() {
	// TODO Auto-generated constructor stub

}

Land::~Land() {
	// TODO Auto-generated destructor stub
}

Land* Land::nearTo() {
	return confining;
}

bool Land::nearTo(Land that) {
	int t=0;
	for(int i=0;(confining+i)!=0;i++){//this solution seems faster than using an if. I'm assuming only one land can
		t += (that==confining[i]);
	}
	return t;
}

int putTroops(int many) {
	return Land::troops += many;
}

int attack(Land defender, int attacking) {

	if(0<attacking<=3) {
		Land::troops -= defender.defend(Land::owner, attacking);
		if(defender.putTroops(0)) {
			return putTroops(0);
		}
		if(attacking>=Land::troops){
			int t=Land::troops-1;
			putTroops(-t);
			defender.putTroops(t);
		} else {
		putTroops(-(attacking));
		defender.putTroops(attacking);
		}
		return 0;
	}
	return -1;
}
int defend(Player *attacker, int attacking) {//resolves fight, returns number of troops destroyed
	if(attacking==3) {
		if(Land::troops==1) {

		}
	}
	if(!Land::troops) {
		Land::owner = attacker;
	}
}
