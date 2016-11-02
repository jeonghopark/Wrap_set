#pragma once

#include "ofMain.h"
#include "ofxGLWarper.h"

#include "ArchShadow.hpp"



class ofApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
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
    
    float xPos;
    
    
    float colorDesolve;
    bool bColorDesolve;
    
    ofImage arch01;
    ofImage arch02;
    ofImage door01;
    float desolveArch01;

    vector<ofPoint> positionsPlastgarten;
    
    
    ArchShadow palastGarten;
    ArchShadow garten;
    ArchShadow door;
    
//    bool bArch01Draw;
//    float _xPos;
//    float _sizeImage;
//    float _colorFactor;

    
//    void drawArchShadow(int _timeFrame, ofImage _img);
    
    
    
};





