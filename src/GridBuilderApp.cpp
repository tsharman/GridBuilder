#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GridBuilderApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void GridBuilderApp::setup()
{
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
}

CINDER_APP_NATIVE( GridBuilderApp, RendererGl )
