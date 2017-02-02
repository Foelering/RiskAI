/*
 * Land.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */



#include "Land.h"

using namespace std;

Land::Land(string name) : name(name), troops(0), owner(0), nextLand(NULL){
	confining = new Land* [15];
	confining[0] = NULL;
}

Land::Land(string name, Land* list[]): name(name), troops(0), owner(0), nextLand(NULL) {
	confining = new Land* [15];
	int i;
	for(i=0 ; list[i]!=NULL && i<15 ; i++){
		confining[i]=list[i];
		confining[i]->addNear(this);
	}
	i++;
	confining[i]=NULL;
}

Land::~Land() {
	delete [] confining;
}

string Land::getName() {
	return name;
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
	if (this==newNear) { cout << "Is it near itself? :P" << endl; return; }
	if (nearTo(newNear)) { cout << "Already near." << endl; return; }

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


//Attacks with most units available
int Land::attack(Land* defender) {
	cout << "Attacking..." << endl;
	if(!nearTo(defender)){
		std::cout << "not near!" << std::endl;
		return 0;
	}
	int attacking = 3;
	if(troops<4){
		attacking = troops-1;
	}

	troops -= defender->defend(attacking);
	if(defender->putTroops(0)) {
		return putTroops(0);
	}
	if(attacking>=troops){
		int t=troops-1;
		putTroops(-t);
		defender->putTroops(t);
	} else {
	putTroops(-attacking);
	defender->putTroops(attacking);
	}
	return 0;
}
int Land::defend(int attacking) {//resolves fight, removes required number of troops, returns number of enemy troops destroyed

	int r = rand() % 9999;
	int o = 0;
	switch(attacking) {
		case (3):
				switch (troops){
				case (1):
						if(r<6597){
							putTroops(-1);
							o = 0;
						} else {
							o = 1;
						}
						break;
				default:
					if(r<3717){
						putTroops(-2);
						o = 0;
					} else if (r<6643) {
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
								if(r<5787){
									putTroops(-1);
									o = 0;
								} else {
									o = 1;
								}
								break;
						default:
							if(r<2276){
								putTroops(-2);
								o = 0;
							} else if (r<6759) {
								putTroops(-1);
								o = 1;
							} else {
								o = 2;
							}
						}
						break;

		case (1):
				if(r<4167){
					putTroops(-1);
					o = 0;
				} else {
					o = 1;
				}
				break;
	}

	cout << "Attacker lost: " << o << "troops. Defender has now: " << this->putTroops(0) << endl;
	return o;
}

Player* Land::getOwner() {
	return owner;
}
void Land::setOwner(Player* newOwner) {
	owner = newOwner;
}

void Land::setNext(Land* newNext) {
	nextLand = newNext;
}

Land* Land::next() {
	return nextLand;
}
