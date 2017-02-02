/*
 * Player.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: david
 */

#include <cstdlib>

#include "Player.h"

using std::string;
using std::cout;
using std::endl;

Player::Player(string namer) :name(namer), land(0), ownedlands(0), troopPool(0) {

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
	from->attack(to);
	if(!to->putTroops(0)) {
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
	cout << "is the problem has?";

	if(has(newLand)) {
		cout << getName() << " owns this already!" <<endl;
		return;
	}
	cout << "is the problem has?";
	Land* pointer = land;
	while(pointer) {
		cout <<"increasing pointer" << endl;
		pointer=pointer->next();
	}
	Land* broken = pointer->next();
	pointer->setNext(newLand);
	newLand->getOwner()->removeLand(newLand);
	newLand->setOwner(this);
	newLand->setNext(broken);
}

void Player::removeLand(Land* thisLand) {
	if(land==thisLand){
		land = land->next();
		return;
	}

	Land* i;

	for(i=land; i; i=i->next()) {
		if(i->next()==thisLand) { break; }
	}
	i->setNext(thisLand->next());
}

bool Player::has(Land* thisLand) {
	cout << "is the problem has?";
	Land* i=land;
	int t=0;
	while(i){
		cout << "is the problem has?";
		t = (i==thisLand);
		i = i->next();
	}
	cout << "is the problem solved?";
	return t;
}

