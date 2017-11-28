#ifndef PAWN
#define PAWN

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Pawn : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:

	Pawn(Side s, std::shared_ptr<World>);
	Pawn(Side s, Location, std::shared_ptr<World>);
	~Pawn();

	std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
	Location & getLoc() override;
	std::vector<Location> & getValidLocs() override;
	Location & move(Location) override;
private:
};
#endif
