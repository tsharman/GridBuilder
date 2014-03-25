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
    float vertexDistance;
    std::list<Vertex *> vertexes;
    
};

#endif /* defined(__GridBuilder__VertexController__) */
