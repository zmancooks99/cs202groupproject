#include "Queen.hpp"
#include "World.hpp"
#include <memory>
#include<iostream>

//constructor must call base class constructor EXPLICITELY in initializer list
Queen::Queen(std::shared_ptr<World> w, Side s)
	: Piece(w, s, queen)
{}

Queen::Queen(std::shared_ptr<World> w, Side s, Location loc)
	: Piece(w, s, queen, loc)
{}

Queen::~Queen() {}

std::shared_ptr<Piece> Queen::remove() { 
	return getWorld()->remove(getLoc());
}

Location Queen::getLoc() {
	return getLocation();
}

std::vector<Location> Queen::getValidLocs() {
	std::vector<Location> locVector{};
	Location tmp = getLoc();
	tmp.setX(tmp.getX() - 1);
	tmp.setY(tmp.getY() - 1);
	for (int row = 0; row < 3; row++) {
		int px = -1;
		int py = -1;
		py += row;
		for (int col = 0; col < 3; col++) {
			Location tmpLoc{ tmp.getX() + col, tmp.getY() + row };
			px += col;
			if (tmpLoc == getLoc()) {

			}
			else {
				while (tmpLoc.getX() >= 0 && tmpLoc.getY() >= 0 && tmpLoc.getX() <= 7 && tmpLoc.getY() <= 7) {
					if (getWorld()->isOccupied(tmpLoc)) {
						if (getWorld()->get(tmpLoc)->getSide() == getSide()) {
							break;
						}
						else {
							locVector.push_back(tmpLoc);
						}
					}
					else {
						locVector.push_back(tmpLoc);
					}
					tmpLoc.setX(tmpLoc.getX() + px);
					tmpLoc.setY(tmpLoc.getY() + py);
				}
			}
		}
	}
	
	return locVector;
}

Location & Queen::move(Location l) {
	std::vector<Location> locVector = getValidLocs();
	bool isValid;
	for (int i = 0; i < locVector.size(); i++) {
		if (l == locVector[i])
			isValid = true;
	}
	getWorld()->add(l, std::make_shared<Piece>(this));
	getWorld()->getBoard().put(getLoc(), 0); // this part is to remove the pointer to this piece at the location where this piece used to be.
	setLoc(l);
	return l;
}