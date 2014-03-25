//
//  Vertex.h
//  GridBuilder
//
//  Created by Torehan Sharman on 3/25/14.
//
//

#ifndef __GridBuilder__Vertex__
#define __GridBuilder__Vertex__

#include <iostream>
#include "cinder/Vector.h"

using namespace ci;

class Vertex {
public:
    Vertex(Vec2f position);
    Vec2f position;
    Vertex *connections[4];
    enum directions { NORTH, EAST, SOUTH, WEST };
    void draw();
};

#endif /* defined(__GridBuilder__Vertex__) */
