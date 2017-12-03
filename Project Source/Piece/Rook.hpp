#ifndef ROOK
#define ROOK

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Rook : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:

	Rook(std::shared_ptr<World>, Side s);
	Rook(std::shared_ptr<World>, Side s, Location);
	~Rook();

	std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
	Location getLoc() override;
	std::vector<Location> getValidLocs() override;
	Location & move(Location) override;
private:
	bool hasMoved = false;
};
#endif
