//
//  Piece.hpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/7/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <vector>
#include <memory>
#include "Location.hpp"

//To use a World pointer
class World;

class Piece /*Abstract*/
{
    
    //Using protected for the enum and constructors gives access to the functions by derived classes but not other classes
    //Makes the fact it's an abstract class more clear
protected:
    enum Side {BLACK, WHITE, NONE};   //NONE only exists for initializations sake in the abstract class constructor
    
    /*
     *ALL derived class constructors must call base class constructor EXPLICITELY in initializer list
     *
     *eg:
     *Derived::Derived(side whichSide) :Piece(whichSide), _whichSide(whichSide) {}
     *Derived::Derived(side whichSide, Location loc) :Piece(whichSide, loc), _whichSide(whichSide), _position(loc) {}
     *
     */
    
    //All peices need to know what side they're on.
    Piece(std::shared_ptr<World> w, Side) :_Pworld(w), _position(Location{0, 0}), _whichSide(Side::NONE), _poisoned(false){}
    
    //Ability to set an initial location for a piece.
    Piece(std::shared_ptr<World> w, Side, Location loc) :_Pworld(w), _position(loc), _whichSide(Side::NONE), _poisoned(false) {}
    
public:
    //Virtual destructor
    virtual ~Piece() {}
    
    //Pieces remove themselves when the program calls their remove function.
    //This should be done by calling the WORLD remove function on it's own current location.
    //This is implemented in the piece class in case of contingencies etc.
    virtual std::shared_ptr<Piece> remove() = 0;
    
    //Returns current location of the piece
    virtual Location  getLoc() = 0;
    
    //Returns a vector filled with all available locations for the piece to move to.
    virtual std::vector<Location> getValidLocs() = 0;
    
    //Takes the location to move to.
    //Location must be a valid location and piece should do it's own checking for validity.
    //Returns new location. Should call WORLD move function to do actual board movement.
    virtual Location& move(Location) = 0;
    
    //Returns the static_cast<int>(_whichSide) of the piece
    virtual int getSide() {return static_cast<int>(_whichSide);}
    
    //Returns whether or not the piece is currently poisoned.
    virtual bool isPoisoned(){return _poisoned;}

	std::shared_ptr<World> getPworld() {
		return _Pworld;
	}
	
	Side getWhichSide() {
		return _whichSide;
	}
	bool getPoisoned() {
		return _poisoned;
	}
	void setPWorld(std::shared_ptr<World> p) {
		_Pworld = p;
	}
	void setLoc(Location l) {
		_position = l;
	}
	void setWhichSide(Side s) {
		_whichSide = s;
	}
	void setPoisoned(bool p) {
		_poisoned = p;
	}
private:
    std::shared_ptr<World> _Pworld;
    Location _position;
    Side _whichSide;
    bool _poisoned;
    
};
#endif /* Piece_hpp */






/*
#####           EXAMPLE CODE FOR DERIVED CLASS:         #####

//Pawn.hpp
 #ifndef Pawn
 #define Pawn
 
 #include <vector>
 
 #include "Piece.hpp"
 #include "Location.hpp"
 
 class Pawn : virtual public Piece  //This denotes virtual inheritance. AKA it's coming from an abstract class
 {
 public:
 
    Pawn(side);
    Pawn(side, Location)
    ~Pawn();
 
    std::shared_ptr<Piece> remove() override; //all overwritten functions should have override after them.
    Location getLoc() override;
    std::vector<Location> getValidLocs() override;
    Location move(Location) override;
 private:
    Location _position;
    int _whichSide;
 };
 #endif
 //END Pawn.hpp

##########################################
 
//Pawn.cpp
#include "Pawn.hpp"

//constructor must call base class constructor EXPLICITELY in initializer list
Pawn::Pawn(side whichSide) :Piece(whichSide), _whichSide(whichSide) {}

Pawn::Pawn(side whichSide, Location loc) :Piece(whichSide, loc), _whichSide(whichSide), _position(loc) {}
 
Pawn::~Pawn() {}

std::shared_ptr<Piece> remove() {return make_shared<Piece>(*this)}
 
Location getLoc() {}

std::vector<Location> getValidLocs() {}

Location move(Location) {}

//END Pawn.cpp
*/
