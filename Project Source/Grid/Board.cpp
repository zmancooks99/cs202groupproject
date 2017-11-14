//
//  Board.cpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/7/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#include "Board.hpp"
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

int Board::_LENGTH = 8;
int Board::_NUMPIECES = 32;

//constructor
//Initializes the game board and the removed piece vectors to 0s
Board::Board() : _gameBoard(_LENGTH, vector< shared_ptr<Piece>>(_LENGTH) ), _removedPiecesBlack(_NUMPIECES/2), _removedPiecesWhite(_NUMPIECES/2)
{
    for(vector<shared_ptr<Piece>> ptrvecPiece : _gameBoard)
    {
        for(shared_ptr<Piece> ptrPiece : ptrvecPiece)
            ptrPiece = 0;
    }
    for(int cc = 0; cc < _NUMPIECES/2; cc++)
    {
        _removedPiecesWhite[cc] = 0;
        _removedPiecesBlack[cc] = 0;
    }
        
}

//destructor
Board::~Board()
{
}

//get()
shared_ptr<Piece> Board::get(Location& loc)
{
    return _gameBoard[ loc.getX() ][ loc.getY() ];
}

//put()
shared_ptr<Piece> Board::put(Location& loc, shared_ptr<Piece> piece)
{
    _gameBoard[ loc.getX() ][ loc.getY() ] = piece;
    return _gameBoard[ loc.getX() ][ loc.getY() ];
}

//remove()
shared_ptr<Piece> Board::remove(Location& loc)
{
    (get(loc)->getSide() == 0) ? _removedPiecesBlack.push_back( get(loc) ):_removedPiecesWhite.push_back( get(loc) );
    shared_ptr<Piece> ptr = get(loc);
    _gameBoard[ loc.getX() ][ loc.getY() ] = 0;
    return ptr;
}

//exchangePieces()
shared_ptr<Piece> Board::exchangePieces(Location &loc, shared_ptr<Piece> p)
{
    shared_ptr<Piece> old = remove(loc);
    put(loc, p);
    return old;
}

//move()
Location& Board::move(Location& from, Location& to)
{
    put(to, remove(from));
    return to;
}

//IsOccupied()
bool Board::isOccupied(Location& loc)
{
    return (get(loc) != 0);
}
