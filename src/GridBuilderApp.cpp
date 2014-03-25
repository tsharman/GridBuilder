#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vertex.h"
#include "VertexController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GridBuilderApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    VertexController *controller;
};

void GridBuilderApp::setup()
{
    
    controller = new VertexController();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
    controller->addVertex();
}


void GridBuilderApp::mouseDown( MouseEvent event )
{
}

void GridBuilderApp::update()
{
}

void GridBuilderApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    controller->drawVertexes();
    /*
    Vertex *newVertex = new Vertex(Vec2f(200.0f, 200.0f));
    
    Vertex *newVertexNorth = new Vertex(Vec2f(200.0f, 220.0f));
    Vertex *newVertexWest = new Vertex(Vec2f(220.0f, 200.0f));
    
    newVertex->connections[Vertex::directions::NORTH] = newVertexNorth;
    newVertex->connections[Vertex::directions::WEST] = newVertexWest;
    newVertex->draw();*/
    
}

CINDER_APP_NATIVE( GridBuilderApp, RendererGl )
