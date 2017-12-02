//
//  Knight.hpp
//  Chess
//
//  Created by Joseph Byam on 12/1/17.
//  Copyright © 2017 Joseph Byam. All rights reserved.
//

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Knight : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
{
public:
    
    Knight(Side s, std::shared_ptr<World>);
    Knight(Side s, Location, std::shared_ptr<World>);
    ~Knight();
    
    std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
    Location getLoc() override;
    std::vector<Location> getValidLocs() override;
    Location & move(Location) override;
private:
    bool hasMoved = false;
};
#endif
