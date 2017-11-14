//
//  World.hpp
//  FourPlayerChess
//
//  Created by Zachary Mason on 11/14/17.
//  Copyright © 2017 Zachary Mason. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include "Board.hpp"
#include "Location.hpp"
#include "Piece.hpp"

class World
{
public:
    World& build(Board&);
    World& update(Board&);
    
private:
    
};

#endif /* World_hpp */
