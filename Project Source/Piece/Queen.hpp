#ifndef QUEEN
#define QUEEN

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Queen : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:

	Queen(std::shared_ptr<World>, Side s);
	Queen(std::shared_ptr<World>, Side s, Location);
	~Queen();

	std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
	Location getLoc() override;
	std::vector<Location> getValidLocs() override;
	Location & move(Location) override;
private:
	bool hasMoved = false;
};
#endif
