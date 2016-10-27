#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    img.load("test_background.png");
    
    fboMain.allocate(2048, 768);
    
    warpersL = * new ofxGLWarper();
    warpersR = * new ofxGLWarper();
    warpersL.setup(0, 0, 1024, 768);
    warpersR.setup(1024, 0, 1024, 768);
    
    
    ofSetVerticalSync(true);
    
}




//--------------------------------------------------------------
void ofApp::update(){
    
    
    fboMain.begin();
    ofClear(0,0);
    img.resize(2048, 768);
    img.draw(0, 0);
    
    
    ofPushStyle();
    ofSetColor(0,255,0);
    for(int i=0; i<ofGetWidth(); i+=10) {
        for(int j=0; j<ofGetHeight(); j+=10) {
            ofDrawLine(i, 0, i, ofGetHeight());
            ofDrawLine(0, j, ofGetWidth(), j);
        }
    }
    ofPopStyle();
    
    fboMain.end();
    
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    ofImage _main;
    _main.allocate(2048, 768, OF_IMAGE_COLOR_ALPHA);
    ofPixels _pMain;
    _pMain.allocate(2048, 768, OF_PIXELS_BGRA);
    fboMain.readToPixels(_pMain);
    _main.setFromPixels(_pMain.getData(), 2048, 768, OF_IMAGE_COLOR_ALPHA);
    
    
    warpersL.begin();
    warpersL.draw();
    _main.drawSubsection(0, 0, 1024, 768, 0, 0);
    warpersL.end();
    
    warpersR.begin();
    warpersR.draw();
    _main.drawSubsection(1024, 0, 1024, 768, 1024, 0);
    warpersR.end();
    
    
    
    
    //    for (int i =0; i<2; i++){
    //        warpers[i].begin();
    //        warpers[i].draw();
    //
    //        ofImage _L;
    //        _L.allocate(512, 384, OF_IMAGE_COLOR_ALPHA);
    //        ofPixels _pL;
    //        _pL.allocate(512, 384, OF_PIXELS_BGRA);
    //        fboL.readToPixels(_pL);
    //        _L.setFromPixels(_pL.getData(), 512, 384, OF_IMAGE_COLOR_ALPHA);
    //
    //        fboR.draw(512, 0);
    //        warpers[i].draw();
    //        warpers[i].end();
    //    }
    
    
}





//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bool bDeactivateOthers = false;
    int activeWarper = -1;

    switch (key) {
        case '1':
            activeWarper = 0;
            warpersL.toogleActive();
            bDeactivateOthers = true;
            break;
            //*
        case '2':
            activeWarper = 1;
            warpersR.toogleActive();
            bDeactivateOthers = true;
            break;
            
        default:
            break;
    }
    
    if (bDeactivateOthers) {
        if (activeWarper == 0) {
            warpersR.deactivate();
        } else if (activeWarper == 1){
            warpersL.deactivate();
        }
    }
    
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}



//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}




//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}



//--------------------------------------------------------------
void ofApp::mouseReleased(){

}
