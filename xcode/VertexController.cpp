//
//  VertexController.cpp
//  GridBuilder
//
//  Created by Torehan Sharman on 3/25/14.
//
//

#include "VertexController.h"

#include <iostream>

using namespace std;

VertexController::VertexController() {
    vertexDistance = 20.0f;
}

void VertexController::addVertex() {
    
    // check if the list is empty
    if(vertexes.empty()) {
        Vertex *newVertex = new Vertex(Vec2f(200.0f, 200.0f));
        cout << "adding first vertex" << endl;
        this->vertexes.push_back(newVertex);
        
        return;
    }
    
    // iterating over all existing vertexes
    Vec2f newVertexLoc;
    Vertex *originVertex;
    int connectionIndex;
    std::list<Vertex *>::iterator ptr;
    for(ptr = vertexes.begin(); ptr != vertexes.end(); ++ptr) {
        
        // looking for empty slot
        for(int i = Vertex::directions::NORTH; i <= Vertex::directions::SOUTH; i++) {
            if((*ptr)->connections[i] == NULL) {
                originVertex = (*ptr);
                connectionIndex = i;
                if(i == Vertex::directions::NORTH) {
                    newVertexLoc = Vec2f((*ptr)->position.x, (*ptr)->position.y + vertexDistance);
                }
                else if(i == Vertex::directions::EAST) {
                    newVertexLoc = Vec2f((*ptr)->position.x + vertexDistance, (*ptr)->position.y);
                }
                else if(i == Vertex::directions::SOUTH) {
                    newVertexLoc = Vec2f((*ptr)->position.x, (*ptr)->position.y - vertexDistance);
                }
                else if(i == Vertex::directions::WEST) {
                    newVertexLoc = Vec2f((*ptr)->position.x - vertexDistance, (*ptr)->position.y);
                }
                break;
            }
        }
        
    }
    
    Vertex *newVertex = new Vertex(newVertexLoc);
    this->vertexes.push_back(newVertex);
    
    originVertex->connections[connectionIndex] = newVertex;
    
    //Vertex *newVertex = new Vertex(Vect2f(0.0f, 0.0f));
    //this->vertexes.push_back(newVertex);
}


void VertexController::drawVertexes() {
    std::list<Vertex *>::iterator ptr;
    int counter = 0;
    for(ptr = vertexes.begin(); ptr != vertexes.end(); ++ptr) {
        cout << "woah! " << counter << endl;
        (*ptr)->draw();
        counter++;
        
    }
}
