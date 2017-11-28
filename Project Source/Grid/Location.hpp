//
//  Location.hpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/7/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include <vector>

class Location
{
public:
    
    Location(int x, int y);
    ~Location();
    int getX() const;
    int getY() const;
    Location& setX(const int x);
    Location& setY(const int y);
    std::vector<int> getLoc() const; //x,y
    
    Location& operator+=(const Location&);
    Location& operator-=(const Location&);
    Location& operator=(Location&);
private:
    std::vector<int> _loc; //x,y
};

Location operator+(const Location&, const Location&);
Location operator-(const Location&, const Location&);
bool operator==(Location& lhs, Location& rhs);
#endif /* Location_hpp */
