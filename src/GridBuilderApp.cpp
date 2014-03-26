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
    void prepareSettings(cinder::app::AppBasic::Settings *settings);
    int counter;
    VertexController *controller;
};


void GridBuilderApp::prepareSettings(cinder::app::AppBasic::Settings *settings){
    settings->setWindowSize(800, 400);
    settings->setFrameRate(100.0f);
}
void GridBuilderApp::setup()
{
    counter = 0;
    controller = new VertexController();
}


void GridBuilderApp::mouseDown( MouseEvent event )
{
}

void GridBuilderApp::update()
{
    if((counter % 10) == 0) {
        controller->addVertex();
        
    }
    counter++;
    
}

void GridBuilderApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    controller->drawVertexes();
    
}

CINDER_APP_NATIVE( GridBuilderApp, RendererGl )
