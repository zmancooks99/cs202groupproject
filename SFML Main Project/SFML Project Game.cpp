#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
/*#include "Board.hpp"
#include "World.hpp"
#include "Location.hpp"*/

using sf::RenderWindow;
using sf::VideoMode;
using sf::RectangleShape;
using sf::CircleShape;
using sf::Color;
using sf::Event;
using sf::Keyboard;
using sf::Vector2f;
using sf::Vector2u;
using sf::Sprite;
using sf::Texture;

using std::vector;

int main()
{
	RenderWindow window(VideoMode(640, 640), "CS202 Chess");
	//0 = White || 1 = Black
	//Textures
	Color chessblack;
	chessblack = Color(100, 100, 100);
	Texture PawnTexture;
	if (!PawnTexture.loadFromFile("Chess Pieces\\Pawn\\l0_ChessPieces6.png"))
	{
		//These cout's are useless, just for debugs
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
	vector <vector <Sprite>> PawnSprite(2, vector <Sprite> (8));
	for (int loop = 0; loop < PawnSprite[0].size(); loop++)
	{
		PawnSprite[0][loop].setTexture(PawnTexture);
		PawnSprite[1][loop].setTexture(PawnTexture);
		PawnSprite[1][loop].setColor(chessblack);
		PawnSprite[0][loop].setScale(2, 2);
		PawnSprite[1][loop].setScale(2, 2);
	}
	vector <vector <Sprite>> RookSprite(2, vector <Sprite> (2));
	for (int loop = 0; loop < RookSprite[0].size(); loop++)
	{
		//Sets the Texture
		RookSprite[0][loop].setTexture(RookTexture);
		RookSprite[1][loop].setTexture(RookTexture);
		//Sets the color to a color that is easily seen on the tiles.
		RookSprite[1][loop].setColor(chessblack);
		//Multiplies the Scale of the Texture by 2x
		RookSprite[0][loop].setScale(2, 2);
		RookSprite[1][loop].setScale(2, 2);
	}
	vector <vector <Sprite>> BishopSprite(2, vector <Sprite>(2));
	for (int loop = 0; loop < BishopSprite[0].size(); loop++)
	{
		BishopSprite[0][loop].setTexture(BishopTexture);
		BishopSprite[1][loop].setTexture(BishopTexture);
		BishopSprite[1][loop].setColor(chessblack);
		BishopSprite[0][loop].setScale(2, 2);
		BishopSprite[1][loop].setScale(2, 2);
	}
	vector <vector <Sprite>> KnightSprite(2, vector <Sprite>(2));
	for (int loop = 0; loop < KnightSprite[0].size(); loop++)
	{
		KnightSprite[0][loop].setTexture(KnightTexture);
		KnightSprite[1][loop].setTexture(KnightTexture);
		KnightSprite[1][loop].setColor(chessblack);
		KnightSprite[0][loop].setScale(2, 2);
		KnightSprite[1][loop].setScale(2, 2);
	}
	vector <Sprite> QueenSprite(2);
	QueenSprite[0].setTexture(QueenTexture);
	QueenSprite[1].setTexture(QueenTexture);
	QueenSprite[1].setColor(chessblack);
	QueenSprite[0].setScale(2, 2);
	QueenSprite[1].setScale(2, 2);
	vector <Sprite> KingSprite(2);
	KingSprite[0].setTexture(KingTexture);
	KingSprite[1].setTexture(KingTexture);
	KingSprite[1].setColor(chessblack);
	KingSprite[0].setScale(2, 2);
	KingSprite[1].setScale(2, 2);
	vector <Sprite> TileSprite(64);
	int xvalue, yvalue; //used for positioning the tiles
	for (int loop = 0; loop < TileSprite.size(); loop++)
	{
		xvalue = (loop % 8);
		yvalue = (loop / 8);
		TileSprite[loop].setPosition((64 * xvalue) + 64, (64 * yvalue) + 64);
		TileSprite[loop].setScale(2, 2);
		if ((xvalue + yvalue) % 2 == 0)
		{
			TileSprite[loop].setTexture(TileTexture[0]); // 0 is white
		}
		else
		{
			TileSprite[loop].setTexture(TileTexture[1]); // 1 is black
		}
	}
	/* This is the code to show the pieces on the board (correctly positioned) 

	//Black
	RookSprite[1][0].setPosition(TileSprite[0].getPosition());
	KnightSprite[1][0].setPosition(TileSprite[1].getPosition());
	BishopSprite[1][0].setPosition(TileSprite[2].getPosition());
	QueenSprite[1].setPosition(TileSprite[3].getPosition());
	KingSprite[1].setPosition(TileSprite[4].getPosition());
	BishopSprite[1][1].setPosition(TileSprite[5].getPosition());
	KnightSprite[1][1].setPosition(TileSprite[6].getPosition());
	RookSprite[1][1].setPosition(TileSprite[7].getPosition());
	for (int loop = 0; loop < PawnSprite[1].size(); loop++)
	{
		PawnSprite[1][loop].setPosition(TileSprite[8+loop].getPosition());
	}
	//White
	RookSprite[0][0].setPosition(TileSprite[63].getPosition());
	KnightSprite[0][0].setPosition(TileSprite[62].getPosition());
	BishopSprite[0][0].setPosition(TileSprite[61].getPosition());
	QueenSprite[0].setPosition(TileSprite[60].getPosition());
	KingSprite[0].setPosition(TileSprite[59].getPosition());
	BishopSprite[0][1].setPosition(TileSprite[58].getPosition());
	KnightSprite[0][1].setPosition(TileSprite[57].getPosition());
	RookSprite[0][1].setPosition(TileSprite[56].getPosition());
	for (int loop = 0; loop < PawnSprite[1].size(); loop++)
	{
		PawnSprite[0][loop].setPosition(TileSprite[55-loop].getPosition());
	}
	*/

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			//if (event.type == Event::Resized)         //locks window size
				//window.setSize(Vector2u(640, 640));
		}

		window.clear();
		for (int loop = 0; loop < TileSprite.size(); loop++)
		{
			window.draw(TileSprite[loop]);
		}
		for (int loop = 0; loop < PawnSprite[0].size(); loop++)
		{
			window.draw(PawnSprite[0][loop]);
			window.draw(PawnSprite[1][loop]);
		}
		for (int loop = 0; loop < RookSprite[0].size(); loop++)
		{
			window.draw(RookSprite[0][loop]);
			window.draw(RookSprite[1][loop]);
		}
		for (int loop = 0; loop < BishopSprite[0].size(); loop++)
		{
			window.draw(BishopSprite[0][loop]);
			window.draw(BishopSprite[1][loop]);
		}
		for (int loop = 0; loop < KnightSprite[0].size(); loop++)
		{
			window.draw(KnightSprite[0][loop]);
			window.draw(KnightSprite[1][loop]);
		}
		window.draw(QueenSprite[0]);
		window.draw(QueenSprite[1]);
		window.draw(KingSprite[0]);
		window.draw(KingSprite[1]);
		window.display();
	}
	return 0;
}