#include "Pawn.hpp"
#include "World.hpp"
#include <memory>
#include<iostream>
using std::vector;

//constructor must call base class constructor EXPLICITELY in initializer list
Pawn::Pawn(Side s, std::shared_ptr<World> w)
	: Piece(w, s)
{}

Pawn::Pawn(Side s, Location loc, std::shared_ptr<World> w) 
	: Piece(w, s, loc)
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
	if (getSide() == 0) {
		locVector.push_back(Location{ tmp.getX(), tmp.getY() + 1 });
		if (getWorld()->isOccupied(Location{ tmp.getX() + 1,tmp.getY() + 1 })) {
			locVector.push_back(Location{ tmp.getX() + 1, tmp.getY() + 1 });
		}
		if (getWorld()->isOccupied(Location{ tmp.getX() - 1,tmp.getY() + 1 })) {
			locVector.push_back(Location{ tmp.getX() - 1, tmp.getY() + 1 });
		}
		if (!hasMoved) {
			locVector.push_back(Location{ tmp.getX(), tmp.getY() + 2 });
		}
	}
	else {
		locVector.push_back(Location{ tmp.getX(), tmp.getY() - 1 });
		if (getWorld()->isOccupied(Location{ tmp.getX() + 1,tmp.getY() - 1 })) {
			locVector.push_back(Location{ tmp.getX() + 1, tmp.getY() - 1 });
		}
		if (getWorld()->isOccupied(Location{ tmp.getX() - 1,tmp.getY() - 1 })) {
			locVector.push_back(Location{ tmp.getX() - 1, tmp.getY() - 1 });
		}
		if (!hasMoved) {
			locVector.push_back(Location{ tmp.getX(), tmp.getY() - 2 });
		}
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
		getWorld()->getBoard().put(l, std::make_shared<Piece>(*this));
		setLoc(l);
	}
	else {
		std::cout << "Location invalid.";
	}
	return l;
}