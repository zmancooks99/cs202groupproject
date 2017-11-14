//
//  Board.hpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/7/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <vector>

#include "Piece.hpp"
#include "Location.hpp"

class Board
{
public:
    Board();
    ~Board();
    
    //Returns a pointer to the piece at the given location.
    std::shared_ptr<Piece> get(Location&);
    
    //Places a piece in the grid at the provided location. Returns the same piece.
    std::shared_ptr<Piece> put(Location&, const std::shared_ptr<Piece>);
    
    //Removes the piece at the given location from the grid and returns it.
    std::shared_ptr<Piece> remove(Location&);
    
    //Exchanges the piece at the given location with the provided piece.
    //Functionally the same as using "put" on an occupied space but it returns the piece that WAS at the location.
    std::shared_ptr<Piece> exchangePieces(Location&, std::shared_ptr<Piece>);
    
    //Moves a piece from the first provided location to the second provided location. Returns the new location.
    Location& move(Location&, Location&);
    
    bool isOccupied(Location&);
    
private:
    static int _LENGTH; //Int representing board length and width
    static int _NUMPIECES;  //The number of peices in the game (total, not per side)
    
    std::vector< std::vector< std::shared_ptr<Piece> > > _gameBoard; //Initialized to 0s
    std::vector< std::shared_ptr<Piece> > _removedPiecesBlack;  //Initialized to 0s
    std::vector< std::shared_ptr<Piece> > _removedPiecesWhite;  //Initialized to 0s
    
};
#endif /* Board_hpp */
