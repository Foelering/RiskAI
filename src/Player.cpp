/*
 * Player.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#include "Player.h"

using std::string;
using std::cout;
using std::endl;

Player::Player(string namer, Player* next) : name(namer), land(0), ownedlands(0), troopPool(0), nextPlayer(next) {

}

Player::Player() : name("Default"), land(0), ownedlands(0), troopPool(0), nextPlayer(0) {

}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

string Player::getName() {
	return name;
}

void Player::attack(Land* from, Land* to) {

	if(!has(from)){
		cout << "Player " << name << " doesn't own " << from->getName() << "." << endl;
		cout << "Can't attack." << endl;
		return;
	}
	cout << name << " is attacking " << to->getName() << " from " << from->getName() << "!" << endl;
	from->attack(to);
	cout << from->getName() << " now has " << from->putTroops(0) << " troops. " << to->getName() << " has " << to->putTroops(0) << "." << endl;
	if(!to->putTroops(0)) {
		cout << name << " is taking " << to->getName() << " as its own!" << endl;;
		takeLand(to);
	}
}

int Player::obtainTroops() {
	return troopPool += ownedlands/3;
}

int Player::obtainTroops(int n) {
	return troopPool = n;
}

int Player::putTroops(Land* land, int n) {
	if (land->getOwner()!=this) {
		cout << getName() << " hasn't got this land!" << endl;
		return -1;
	} else if (troopPool<n) {
		cout << getName() << " hasn't got enough troops!" << endl;
		return -2;
	}
	troopPool -= n;
	land->putTroops(n);
	return 0;
}

void Player::takeLand(Land* newLand) {

	if(has(newLand)) {
		cout << getName() << " owns this already!" <<endl;
		return;
	}

	if (land==0) {
		land = newLand;
	} else {
		Land* pointer = land;
		while (pointer->next()) {
			pointer = pointer->next();
		}
		pointer->setNext(newLand);
	}

	if (newLand->getOwner()) {
		newLand->getOwner()->removeLand(newLand);
	}

	newLand->setOwner(this);
	cout << getName() << " has taken control of " << newLand->getName() << endl;

	ownedlands++;
}

void Player::removeLand(Land* thisLand) {
	if(!has(thisLand)) {
		cout << "Player " << getName() << " already owns " << thisLand->getName() << "!" << endl;
		return;
	}

	if(land==thisLand){
		land = land->next();
		thisLand->setNext(0);
	} else {

		Land* i;

		for(i=land; i; i=i->next()) {
			if(i->next()==thisLand) { break; }
		}
		i->setNext(thisLand->next());
		thisLand->setNext(0);

	}

	ownedlands--;
}

bool Player::has(Land* thisLand) {
	Land* i=land;
	int t=0;
	while(i){
		t = (i==thisLand);
		i = i->next();
	}
	return t;
}

