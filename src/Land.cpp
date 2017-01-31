/*
 * Land.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Land.h"

using namespace std;

Land::Land() : owner(0), troops(0){
	confining = new Land* [15];
	confining[0] = NULL;
}

Land::Land(Land* list[]): owner(0), troops(0) {
	confining = new Land* [15];
	int i;
	for(i=0 ; list[i]!=0 && i<=15 ; i++){
		confining[i]=list[i];
	}
	confining[i]=NULL;
}

Land::~Land() {
	delete [] confining;
}

Player* Land::getOwner(){
	return owner;
}

Land** Land::nearTo() {//Returns the near
	return confining;
}

bool Land::nearTo(Land* that) {//Checks if "that" is near to this land
	int t=0;
	for(int i=0;confining[i];i++){//this solution seems faster than using an if. I'm assuming only one land can be equal to that
		t += (that==confining[i]);
	}
	return t;
}

void Land::addNear(Land* newNear) {
	int i=0;
	while(confining[i]){
		cout << "i++" << i;
		i++;
	}
	confining[i] = newNear;
}

int Land::putTroops(int many) {
	return troops += many;
}

int Land::attack(Land* defender, int attacking) {
	cout << "Attacking..." << endl;
	if(!nearTo(defender)){
		std::cout << "not near!" << std::endl;
		return 0;
	}
	int max = 3;
	if(troops<4){
		max = troops-1;
	}
	if((0<attacking)&&(attacking<=max)) {
		troops -= defender->defend(owner, attacking);
		if(defender->putTroops(0)) {
			return putTroops(0);
		}
		if(attacking>=troops){
			int t=troops-1;
			putTroops(-t);
			defender->putTroops(t);
		} else {
		putTroops(-(attacking));
		defender->putTroops(attacking);
		}
		return 0;
	}
	cout << "Can't attack with so many troops (max " << max << ")" << endl;
	return -1;
}
int Land::defend(Player *attacker, int attacking) {//resolves fight, removes required number of troops, returns number of enemy troops destroyed

	int r = rand() % 999;
	int o = 0;
	switch(attacking) {
		case (3):
				switch (troops){
				case (1):
						if(r<659){
							putTroops(-1);
							o = 0;
						} else {
							o = 1;
						}
						break;
				default:
					if(r<372){
						putTroops(-2);
						o = 0;
					} else if (r<664) {
						putTroops(-1);
						o = 1;
					} else {
						o = 2;
					}
				}
				break;

		case (2):
				switch (troops){
						case (1):
								if(r<579){
									putTroops(-1);
									o = 0;
								} else {
									o = 1;
								}
								break;
						default:
							if(r<228){
								putTroops(-2);
								o = 0;
							} else if (r<676) {
								putTroops(-1);
								o = 1;
							} else {
								o = 2;
							}
						}
						break;

		case (1):
				if(r<417){
					putTroops(-1);
					o = 0;
				} else {
					o = 1;
				}
				break;
	}
	if(!troops) {//changes owner if the land has no troops on it
		owner = attacker;
	}
	cout << "Attacker lost: " << o << "troops. Defender has now: " << this->putTroops(0) << endl;
	return o;
}
