#include "Pawn.hpp"
#include "World.hpp"
#include <memory>
#include<iostream>
using std::vector;

//constructor must call base class constructor EXPLICITELY in initializer list
Pawn::Pawn(std::shared_ptr<World> w, Side s)
	: Piece(w, s, pawn)
{}

Pawn::Pawn(std::shared_ptr<World> w, Side s, Location loc)
	: Piece(w, s, pawn, loc)
{}

Pawn::~Pawn() {}

std::shared_ptr<Piece> Pawn::remove() { 
	return getWorld()->remove(getLoc());
}

Location Pawn::getLoc() {
	return getLocation();
}

vector<Location> Pawn::getValidLocs() {
	vector<Location> locVector{};
	Location tmp = getLoc();
	int tmpY = 0;
	if (getSide() == 0) {
		tmpY = 1;
	}
	else {
		tmpY = -1;
	}
	if (!getWorld()->isOccupied(Location{ tmp.getX(), tmp.getY() + tmpY })) {
		locVector.push_back(Location{ tmp.getX(), tmp.getY() + tmpY });
	}
	if ((getLoc().getX() != 7) && (getLoc().getY() != 7) && (getLoc().getY() != 0)) {
		if (getWorld()->isOccupied(Location{ tmp.getX() + 1,tmp.getY() + tmpY })) {
			if (getWorld()->getBoard().get(Location{ tmp.getX() + 1,tmp.getY() + tmpY })->getSide() != getSide()) {
				locVector.push_back(Location{ tmp.getX() + 1, tmp.getY() + tmpY });
			}
		}
	}
	if ((getLoc().getX() != 0) && (getLoc().getY() != 7) && (getLoc().getY() != 0)) {
		if (getWorld()->isOccupied(Location{ tmp.getX() - 1,tmp.getY() + tmpY })) {
			if (getWorld()->getBoard().get(Location{ tmp.getX() + 1,tmp.getY() + tmpY })->getSide() != getSide()) {
				locVector.push_back(Location{ tmp.getX() - 1, tmp.getY() + tmpY });
			}
		}
	}
	if (!hasMoved) {
		locVector.push_back(Location{ tmp.getX(), tmp.getY() + (2 * tmpY) });
	}
	return locVector;
}

Location & Pawn::move(Location l) {
	bool isValid = false;
	vector<Location> validLocs = getValidLocs();
	for (int i = 0; i < validLocs.size(); i++) {
		if (validLocs[i] == l)
			isValid = true;
	}
	if (isValid) {
		if (getWorld()->isOccupied(l))
			getWorld()->remove(l);
		getWorld()->getBoard().put(l, std::make_shared<Piece>(this));
		getWorld()->getBoard().put(getLoc(), 0); // this part is to remove the pointer to this piece at the location where this piece used to be.
		setLoc(l);
	}
	else {
		std::cout << "Location invalid.";
	}
	return l;
}