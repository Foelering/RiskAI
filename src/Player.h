/*
 * Player.h
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <cstdlib>
#include "Land.h"

using std::string;

class Player {
protected:
	static int numberofplayers;
	string name;
	Land* land;			//first link of the chainlist of owned lands
	int ownedlands;		//number of lands owned
	int troopPool;		//a pool of troops to be used when distributing troops
	Player* nextPlayer;	//next player in playing order

public:
	bool inGame;		//a boolean to check whether the player
	Player();
	Player(string namer, Player* next);
	virtual ~Player();
	string getName();
	int getPlayerN();	//returns the number of total players created (has to be equal to the number of players in game).
	void attack(Land* from, Land* to);	//prompts "from" to attack "to"
	int obtainTroops();					//increments troopPool by ownedlands/3 troops
	int obtainTroops(int n);			//increments troopPool by n
	int putTroops(Land* land, int n);	//puts n troops to land from the troopPool
	void takeLand(Land* newLand);		//adds newLand to the chainlist, and increments ownedlands by 1
	void removeLand(Land* thisLand);	//removes thisLand from the list, and decrements ownedlands by 1
	bool has(Land* thisLand);			//checks whether the player owns thisLand

	void populateLands() {				//puts a troop in every owned land; to be used at the start of the game
		Land* pointer = land;
		for(int i = 0; i<ownedlands; ++i){
			putTroops(pointer, 1);
			pointer = pointer->next();
		}
	}

	Player* next() {					//outputs the next active player
		if(nextPlayer->inGame){
			return nextPlayer;
		} else {
			return nextPlayer->next();
		}
	}

	void setNext(Player* newNext) {
		nextPlayer = newNext;
	}

	virtual void putTroops() {			//a method to put troops on the battlefield, to be overridden by subclasses
		return;
	}

	virtual void makeTurn() {			//a method to make a turn
		return;
	}

	virtual void initialTroopSet() {	//a method to put down the initial troopPool, to be overridden, and to be used after the lands have been populated

	}

	bool checkWinCondition() {			//a player wins if it has at least 24 troops
		return ownedlands>=24;
	}
};


#endif /* PLAYER_H_ */
