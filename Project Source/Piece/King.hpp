#ifndef KING
#define KING

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class King : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:

	King(std::shared_ptr<World>, Side s);
	King(std::shared_ptr<World>, Side s, Location);
	~King();

	std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
	Location getLoc() override;
	std::vector<Location> getValidLocs() override;
	Location & move(Location) override;
private:
	bool hasMoved = false;
};
#endif
