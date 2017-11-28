#include "Pawn.hpp"
#include "World.hpp"
#include <memory>

//constructor must call base class constructor EXPLICITELY in initializer list
Pawn::Pawn(Side s, std::shared_ptr<World> w)
	: Piece(w, s)
{}

Pawn::Pawn(Side s, Location loc, std::shared_ptr<World> w) 
	: Piece(w, s, loc)
{}

Pawn::~Pawn() {}

std::shared_ptr<Piece> Pawn::remove() { 
	return std::make_shared<Piece>(*this);
}

Location & Pawn::getLoc() {
	return getLoc();
}

std::vector<Location> & Pawn::getValidLocs() {
	std::vector<Location> locVector{};
	Location tmp = getLoc();
	if (getWhichSide() == BLACK) {
		tmp.setY(tmp.getY() + 1);
	}
	else {
		tmp.setY(tmp.getY() - 1);
	}
	locVector.push_back(tmp);
	return locVector;
}

Location & Pawn::move(Location l) {
	setLoc(l);
	return l;
}