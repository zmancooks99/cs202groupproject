//
//  Location.cpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/7/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#include "Location.hpp"
using std::vector;

Location::Location(int xLoc, int yLoc)
{
    _loc = vector<int> {xLoc, yLoc};
}

Location::~Location() {}

int Location::getX() const
{
    return _loc[0];
}

int Location::getY() const
{
    return _loc[1];
}

Location& Location::setX(const int x)
{
    _loc[0] = x;
    return *this;
}
Location& Location::setY(const int y)
{
    _loc[1] = y;
    return *this;
}

vector<int> Location::getLoc() const
{
    return _loc;
}

//Overloaded operators
Location operator+(Location& lhs, Location& rhs)
{
    Location temp = Location{(lhs.getX()+rhs.getX()), (lhs.getY()+rhs.getY())};
    return temp;
}
Location operator-(Location& lhs, Location& rhs)
{
    Location temp = Location{(lhs.getX()-rhs.getX()), (lhs.getY()-rhs.getY())};
    return temp;
}
bool operator==(Location& lhs, Location& rhs)
{
    return (lhs.getX()==rhs.getX() && lhs.getY() == rhs.getY());
}
Location& Location::operator+=(const Location& rhs)
{
    this->setX(_loc[0] + rhs.getX());
    return *this;
    
}
Location& Location::operator-=(const Location& rhs)
{
    this->setY(_loc[1] + rhs.getY());
    return *this;
}
Location& Location::operator=(Location& rhs)
{
    this -> setX(rhs.getX());
    this -> setY(rhs.getY());
    return *this;
}
