/*
 * Continent.h
 *
 *  Created on: 27 feb 2017
 *      Author: david
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <iostream>

using std::string;

class Player;
class Land;

class Continent {
protected:
	string name;
	int totalLands;			//number of lands constituting the Continent
	Player** playerArray;	//array of pointers to every player
	int playerNumber;		//Invariable number of players in game
	int* ownershipArray;	//An array containing the number of lands owned by every player, in the same order as playerArray
	int givenTroops;		//Number of troops given in case a player owns the whole continent

	int find(Player* he);	//Internal method that returns the position of the player "he" in the playerArray, as to recover the same position on the ownershipArray
public:
	Continent(string name, Player** playerList, int playerNumber, int landNumber, int givenTroops);
	virtual ~Continent();
	string getName();
	void giveLand(Player* from, Player* to);	//increments the number of lands owned by to, and decrements the ones owned by from
	int troops(Player* requester);				//outputs givenTroops if requester owns the continent, 0 otherwise
	int getPlayerNumber();						//returns the number of players, just a check
};

#endif /* CONTINENT_H_ */
