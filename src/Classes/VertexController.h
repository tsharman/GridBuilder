//
//  VertexController.h
//  GridBuilder
//
//  Created by Torehan Sharman on 3/25/14.
//
//

#ifndef __GridBuilder__VertexController__
#define __GridBuilder__VertexController__

#include <iostream>
#include <list>
#include "Vertex.h"
#include "cinder/Vector.h"

using namespace ci;

class VertexController {
public:
    VertexController();
    
    void drawVertexes();
    void addVertex();
    float calculateCoord(float gridIndex);
    float vertexDistance;
    Vertex ***grid;
    int rows;
    int columns;
    
    
};

#endif /* defined(__GridBuilder__VertexController__) */
