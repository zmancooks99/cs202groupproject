#ifndef PAWN
#define PAWN

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Pawn : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:

	Pawn(std::shared_ptr<World>, Side s);
	Pawn(std::shared_ptr<World>, Side s, Location);
	~Pawn();

	std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
	Location getLoc() override;
	std::vector<Location> getValidLocs() override;
	Location & move(Location) override;
private:
	bool hasMoved = false;
};
#endif
