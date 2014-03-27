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
    vertexDistance = 5.0f;
    rows = 20;
    columns = 20;
    
    
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
    float coordX = calculateCoord(0);
    cout << coordX << endl;
    grid[0][0] = new Vertex(Vec2f(calculateCoord(0), calculateCoord(0)));
}

float VertexController::calculateCoord(float gridIndex) {
    float distance = this->vertexDistance;
    return (gridIndex * distance) + (distance / 2);
}

void VertexController::addVertex() {
    bool foundVertex = false;
    for(int i = 0; i < rows; i++) {
        for(int k = 0; k < columns; k++) {
            cout << k << endl;
            Vertex *currentVertex = grid[i][k];
            if(currentVertex == NULL) {
                cout << "adding vertex" << i  << " " << k << endl;
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
                cout << "drawing " << k << endl;
                inspectingVertex = grid[i][k - 1];
                if(inspectingVertex != NULL) {
                    currentVertex->drawTo(inspectingVertex);
                }
            }
            
        }
    }
}
