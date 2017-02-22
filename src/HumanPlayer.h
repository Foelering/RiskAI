/*
 * HumanPlayer.h
 *
 *  Created on: Feb 5, 2017
 *      Author: david
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include <cstdlib>

#include "Player.h"

class HumanPlayer: public Player {
protected:
	void attackPrompt();
	string generateCallToArms();
public:
	HumanPlayer(string namer, Player* next);
	virtual ~HumanPlayer();

	void makeTurn();
	void initialTroopSet();
	void populateLands();
};

#endif /* HUMANPLAYER_H_ */
