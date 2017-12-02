#include "King.hpp"
#include "World.hpp"
#include <memory>
#include<iostream>

//constructor must call base class constructor EXPLICITELY in initializer list
King::King(std::shared_ptr<World> w, Side s)
	: Piece(w, s, king)
{}

King::King(std::shared_ptr<World> w, Side s, Location loc)
	: Piece(w, s, king, loc)
{}

King::~King() {}

std::shared_ptr<Piece> King::remove() { 
	return getWorld()->remove(getLoc());
}

Location King::getLoc() {
	return getLocation();
}

std::vector<Location> King::getValidLocs() {
	std::vector<Location> locVector{};
	Location tmp = getLoc();
	tmp.setX(tmp.getX() - 1);
	tmp.setY(tmp.getY() - 1);
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (tmp.getX() >= 0 && tmp.getX() <= 7 && tmp.getY() >= 0 && tmp.getY() <= 7) {
				Location tmpLoc{ tmp.getX() + row, tmp.getY() + col };
				if (getWorld()->isOccupied(tmpLoc)) {
					if (getWorld()->getBoard().get(tmpLoc)->getSide() != getSide()) {
						locVector.push_back(tmpLoc);
					}
				}
				else {
					locVector.push_back(tmpLoc);
				}
			}
		}
	}
	tmp = getLoc();
	if (!hasMoved) {
		if (getSide() == 0) {
			if (getWorld()->isOccupied(Location{ tmp.getX() - 3, tmp.getY() })) {
				if (getWorld()->getBoard().get(Location{ tmp.getX() - 3, tmp.getY() })->getType() == 1) {
					if (!getWorld()->isOccupied(Location{ tmp.getX() - 1, tmp.getY() }) && !getWorld()->isOccupied(Location{ tmp.getX() - 2, tmp.getY() })) {
						locVector.push_back(Location{ tmp.getX() - 2, tmp.getY() });
					}
				}
			}
		}
	}
	return locVector;
}

Location & King::move(Location l) {
	std::vector<Location> locVector = getValidLocs();
	bool isValid;
	for (int i = 0; i < locVector.size(); i++) {
		if (l == locVector[i])
			isValid = true;
	}
	getWorld()->getBoard().put(getLoc(), 0); // this part is to remove the pointer to this piece at the location where this piece used to be.
	setLoc(l);
	return l;
}