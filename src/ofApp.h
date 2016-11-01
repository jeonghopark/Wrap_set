#pragma once

#include "ofMain.h"
#include "ofxGLWarper.h"



class ofApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased();
    
    ofxGLWarper warpersL;
    ofxGLWarper warpersR;
    
    ofImage img;
    
    ofFbo fboMain;
    
    vector<ofImage> silhoutteImg;
    vector<ofPoint> positionsWD;
    void positionSet();
    
    ofDirectory _dir;
    
    vector<int> indexPositionWD;
    
    int sizeFactor;
    
};


