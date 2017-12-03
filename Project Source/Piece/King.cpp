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
				Location tmpLoc{ tmp.getX() + col, tmp.getY() + row };
				if (getWorld()->isOccupied(tmpLoc)) {
					if (getWorld()->get(tmpLoc)->getSide() != getSide()) {
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
	int tmpA = 0;
	if (!hasMoved) {
		if (getSide() == 0) {
			tmpA = -1;
		}
		else {
			tmpA = 1;
		}
		if (getWorld()->isOccupied(Location{ tmp.getX() + (3 * tmpA), tmp.getY() })) {
			if (getWorld()->getBoard().get(Location{ tmp.getX() + (3 * tmpA), tmp.getY() })->getType() == 1) {
				if (!getWorld()->isOccupied(Location{ tmp.getX() + tmpA, tmp.getY() }) && !getWorld()->isOccupied(Location{ tmp.getX() + (2 * tmpA), tmp.getY() })) {
					locVector.push_back(Location{ tmp.getX() + (2 * tmpA), tmp.getY() });
				}
			}
		}
		if (getWorld()->isOccupied(Location{ tmp.getX() - (4 * tmpA), tmp.getY() })) {
			if (getWorld()->get(Location{ tmp.getX() - (4 * tmpA), tmp.getY() })->getType() == 1) {
				if (!getWorld()->isOccupied(Location{ tmp.getX() - tmpA, tmp.getY() }) && !getWorld()->isOccupied(Location{ tmp.getX() - (2 * tmpA), tmp.getY() }) && !getWorld()->isOccupied(Location{ tmp.getX() - (3 * tmpA), tmp.getY() })) {
					locVector.push_back(Location{ tmp.getX() - (3 * tmpA), tmp.getY() });
				}
			}
		}
	}
	return locVector;
}

Location & King::move(Location l) {
	std::vector<Location> locVector = getValidLocs();
	bool isValid;
	Location tmp = getLoc();
	int tmpA = 0;
	std::shared_ptr<World> tmpW = getWorld();
	if (getSide() == 0) {
		tmpA = -1;
	}
	else {
		tmpA = 1;
	}
	for (int i = 0; i < locVector.size(); i++) {
		if (l == locVector[i])
			isValid = true;
	}
	
	if (l == Location{ tmp.getX() + (2 * tmpA), tmp.getY() }) {
		Location tmpR { tmp.getX() + (3 * tmpA), tmp.getY() };
		tmpW->add(l, std::make_shared<Piece>(this));
		tmpW->add(getLoc(), 0);
		tmpW->add(Location{ tmp.getX() + tmpA, tmp.getY() }, getWorld()->get(tmpR));
		tmpW->add(tmpR, 0);
	}
	else if (l == Location{ tmp.getX() - (3 * tmpA), tmp.getY() }) {
		Location tmpR{ tmp.getX() - (4 * tmpA), tmp.getY() };
		tmpW->add(l, std::make_shared<Piece>(this));
		tmpW->add(getLoc(), 0);
		tmpW->add(Location{ tmp.getX() + (2 *tmpA), tmp.getY() }, getWorld()->get(tmpR));
		tmpW->add(tmpR, 0);
	}
	else {
		if (tmpW->isOccupied(l))
			tmpW->remove(l);
		tmpW->add(l, std::make_shared<Piece>(this));
		tmpW->add(getLoc(), 0); // this part is to remove the pointer to this piece at the location where this piece used to be.
		setLoc(l);
	}
	return l;
}