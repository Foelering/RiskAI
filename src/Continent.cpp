/*
 * Continent.cpp
 *
 *  Created on: 27 feb 2017
 *      Author: david
 */

#include "Continent.h"

using std::cout;
using std::endl;

Continent::Continent(string name, Player** playerList, int players, int landNumber, int givenTroops) : name(name), playerNumber(players), totalLands(landNumber), playerArray(playerList), givenTroops(givenTroops){
	ownershipArray = new int[playerNumber+1];
	for(int i=0; i<=playerNumber; ++i){
		ownershipArray[i] = 0;
	}
	for(int i=0; i< playerNumber; ++i){
		cout << playerArray[i] << endl;
	}
}

Continent::~Continent(){
	delete ownershipArray;
}

int Continent::find(Player* he) {
	for(int i=0; i<playerNumber; ++i) {
		if (he==playerArray[i]){
			return i;
		}
	}
	std::cout << "Error: could not find player" << std::endl;
	return playerNumber;
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
	int index = find(requester);
	int ownedlands = *(ownershipArray+index);
	if(ownedlands==totalLands){
		return givenTroops;
	} else {
		return 0;
	}
}

int Continent::getPlayerNumber(){ return playerNumber; }
