//
//  VertexController.cpp
//  GridBuilder
//
//  Created by Torehan Sharman on 3/25/14.
//
//

#include "VertexController.h"

#include <iostream>
#include "cinder/Rand.h"

using namespace std;

VertexController::VertexController() {
    cout << ci::app::getWindowHeight()  << endl;
    vertexDistance = 10.0f;
    rows = 40;
    columns = 40;
    
    
    // initializing grid
    grid = new Vertex**[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new Vertex*[columns];
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = NULL;
        }
    }
    
    // creating first Vertex
    grid[0][0] = new Vertex(Vec2f(calculateCoord(Rand::randInt(0, rows)), Rand::randInt(0, columns)));
}

float VertexController::calculateCoord(float gridIndex) {
    float distance = this->vertexDistance;
    return (gridIndex * distance) + (distance / 2);
}

void VertexController::addVertex() {
    bool foundVertex = false;
    for(int i = Rand::randInt(0, rows); i < rows; i++) {
        for(int k = Rand::randInt(0, columns); k < columns; k++) {
            if(Rand::randBool()) {
                continue;
            }
            Vertex *currentVertex = grid[i][k];
            if((currentVertex == NULL) && Rand::randBool()) {
                grid[i][k] = new Vertex(Vec2f(calculateCoord(i), calculateCoord(k)));
                foundVertex = true;
            }
            if(foundVertex) {
                break;
            }
        }
        if(foundVertex) {
            break;
        }
    }
}


void VertexController::drawVertexes() {
    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            Vertex *currentVertex = grid[i][k];
            if(currentVertex == NULL) {
                continue;
            }
            
            Vertex *inspectingVertex;
            // check top tile
            if(i > 0) {
                
                inspectingVertex = grid[i - 1][k];
                if(inspectingVertex != NULL) {
                    currentVertex->drawTo(inspectingVertex);
                }
            }
            
            // check left tile
            if(k > 0) {
                inspectingVertex = grid[i][k - 1];
                if(inspectingVertex != NULL) {
                    currentVertex->drawTo(inspectingVertex);
                }
            }
            
        }
    }
}
