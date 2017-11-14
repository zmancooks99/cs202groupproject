//
//  World.cpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/14/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#include "World.hpp"

using std::shared_ptr;
using std::vector;

//Constructor
World::World(Board& board) : _board(board)
{
}

World& World::build(Board& b)
{
    //Build the graphics etc for the world
}


void World::show()
{
    //this should handle displaying the world
}


World& World::update(Board& b)
{
    //this will update the graphics when changes are made
}

Location World::locationClicked()
{
    //When the user clicks inside the world it should trigger a call to this function.
}

void World::add(Location& loc, std::shared_ptr<Piece> p)
{
    //This should add a piece to the world at the given location.
    
    _board.put(loc, p);
}

std::shared_ptr<Piece> World::remove(Location& loc)
{
    //This removes a piece from the world
    
    _board.remove(loc);
}
