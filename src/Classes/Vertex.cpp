//
//  Vertex.cpp
//  GridBuilder
//
//  Created by Torehan Sharman on 3/25/14.
//
//

#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(Vec2f position) {
    // initializing location
    this->position = position;
    
    // initializing connections
    for (int i = NORTH; i <= WEST; i++) {
        connections[i] = NULL;
    }
}

void Vertex::draw() {
    ci::gl::color(200.0f, 200.0f, 200.0f);
    
    // drawing all points
    for (int i = NORTH; i <= WEST; i++) {
        Vertex *currentVertex = connections[i];
        if(currentVertex != NULL) {
            Vec2f start = this->position;
            Vec2f end = currentVertex->position;
            ci::gl::drawLine(start, end);
            
        }
    }
}
