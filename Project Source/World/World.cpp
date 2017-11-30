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
	//0 = White || 1 = Black
	//Textures
	Texture PawnTexture;
	if (!PawnTexture.loadFromFile("Chess Pieces\\Pawn\\l0_ChessPieces6.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	Texture RookTexture;
	if (!RookTexture.loadFromFile("Chess Pieces\\Rook\\l0_ChessPieces3.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	Texture BishopTexture;
	if (!BishopTexture.loadFromFile("Chess Pieces\\Bishop\\l0_ChessPieces4.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	Texture KnightTexture;
	if (!KnightTexture.loadFromFile("Chess Pieces\\Knight\\l0_ChessPieces5.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	Texture QueenTexture;
	if (!QueenTexture.loadFromFile("Chess Pieces\\Queen\\l0_ChessPieces2.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	Texture KingTexture;
	if (!KingTexture.loadFromFile("Chess Pieces\\King\\l0_ChessPieces1.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	vector <Texture> TileTexture(2);
	if (!TileTexture[0].loadFromFile("Chess Pieces\\CheckerBoardWhite.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	if (!TileTexture[1].loadFromFile("Chess Pieces\\CheckerBoardBlack.png"))
	{
		std::cout << "Failure" << std::endl;
	}
	//Sprite
	//First Number is Color (0 = White || 1 = Black)
	//Second Number is onscreen Number
	vector <vector <Sprite>> PawnSprite(2, vector <Sprite>(8));
	for (int loop = 0; loop < PawnSprite[0].size(); loop++)
	{
		PawnSprite[0][loop].setTexture(PawnTexture);
		PawnSprite[1][loop].setTexture(PawnTexture);
		PawnSprite[1][loop].setColor(Color(50, 50, 50));
	}
	vector <vector <Sprite>> RookSprite(2, vector <Sprite>(2));
	for (int loop = 0; loop < RookSprite[0].size(); loop++)
	{
		RookSprite[0][loop].setTexture(RookTexture);
		RookSprite[1][loop].setTexture(RookTexture);
		RookSprite[1][loop].setColor(Color(50, 50, 50));
	}
	vector <vector <Sprite>> BishopSprite(2, vector <Sprite>(2));
	for (int loop = 0; loop < BishopSprite[0].size(); loop++)
	{
		BishopSprite[0][loop].setTexture(BishopTexture);
		BishopSprite[1][loop].setTexture(BishopTexture);
		BishopSprite[1][loop].setColor(Color(50, 50, 50));
	}
	vector <vector <Sprite>> KnightSprite(2, vector <Sprite>(2));
	for (int loop = 0; loop < KnightSprite[0].size(); loop++)
	{
		KnightSprite[0][loop].setTexture(KnightTexture);
		KnightSprite[1][loop].setTexture(KnightTexture);
		KnightSprite[1][loop].setColor(Color(50, 50, 50));
	}
	vector <Sprite> QueenSprite(2);
	QueenSprite[0].setTexture(QueenTexture);
	QueenSprite[1].setTexture(QueenTexture);
	QueenSprite[1].setColor(Color(50, 50, 50));
	vector <Sprite> KingSprite(2);
	KingSprite[0].setTexture(KingTexture);
	KingSprite[1].setTexture(KingTexture);
	KingSprite[1].setColor(Color(50, 50, 50));
	vector <Sprite> TileSprite(64);
    return *this;
}


void World::show()
{
    //this should handle displaying the world
}


World& World::update(Board& b)
{
    //this will update the graphics when changes are made
    return *this;
}

Location World::locationClicked()
{
    //When the user clicks inside the world it should trigger a call to this function.
    Location temp = {-1,-1};
    
    return temp;
}

void World::add(const Location& loc, shared_ptr<Piece> p)
{
    //This should add a piece to the world at the given location.
    
    _board.put(loc, p);
}

shared_ptr<Piece> World::remove(const Location& loc)
{
    //This removes a piece from the world
    
    return _board.remove(loc);
}

Location World::getLoc(const Piece& p)
{
    return _board.getLocation(p);
}

Board& World::getBoard()
{
    return _board;
}
bool World::isOccupied(const Location& loc)
{
    return _board.isOccupied(loc);
}

std::shared_ptr<Piece> World::get(const Location& loc)
{
    return _board.get(loc);
}
