#include "ofApp.h"
#include "ofMain.h"
#include "ofAppGLFWWindow.h"
//========================================================================
int main( ){
    
    //    ofAppGLFWWindow win;
    
    ofGLFWWindowSettings settings;
    settings.multiMonitorFullScreen = true;
    
    ofCreateWindow(settings)->setFullscreen(false);
    ofRunApp(new ofApp());
}
