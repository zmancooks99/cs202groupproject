//
//  World.hpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/14/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <vector>

#include "Board.hpp"
#include "Location.hpp"
#include "Piece.hpp"

class World
{
public:
    //Constructor. World MUST take a grid.
    World(Board&);
    
    //This should handle all SFML associated with building the world and initializing the graphics.
    World& build(Board&);
    
    //This should handle the output and display the world.
    void show();
    
    //This should update the graphics (eg. when moves take place etc.).
    World& update(Board&);
    
    //When a user clicks in the world frame, it should trigger this function call and return a valid location in the Board.
    Location locationClicked();
    
    //This should add a piece to the world at the given location.
    void add(Location&, std::shared_ptr<Piece>);
    
    //This removes a piece from the world
    std::shared_ptr<Piece> remove(Location&);
    
    //get location of a piece
    Location getLoc(const Piece&);
    
    //returns the board
    Board& getBoard();
    
private:
    Board _board;
};
#endif /* World_hpp */
