/*
 * Continent.cpp
 *
 *  Created on: 27 feb 2017
 *      Author: david
 */

#include "Continent.h"

using std::cout;
using std::endl;

Continent::Continent(string name, Player** playerList, int playerNumber, int landNumber, int givenTroops) : name(name), playerNumber(playerNumber), totalLands(landNumber), playerArray(playerList), givenTroops(givenTroops){
	ownershipArray = new int[playerNumber];
}

Continent::~Continent(){
	delete ownershipArray;
}

int Continent::find(Player* he) {
	cout << he << endl;
	cout << playerNumber << endl;
	for(int i=0; i<playerNumber; ++i) {
		cout << playerArray[i] << endl;
		if (he==playerArray[i]){
			return i;
		}
	}
	std::cout << "Error: could not find player" << std::endl;
	return -1;
}

string Continent::getName(){
	return name;
}

void Continent::giveLand(Player* from, Player* to) {
	++ownershipArray[find(to)];
	if(from){
		--ownershipArray[find(from)];
	}
}

int Continent::troops(Player* requester){
	if(ownershipArray[find(requester)]==totalLands){
		return givenTroops;
	} else {
		return 0;
	}
}
