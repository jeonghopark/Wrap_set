#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup(){
    
    sizeFactor = 1;
    
    
    
    positionSet();
    
    img.load("test_background.png");
    
    fboMain.allocate(1024 * sizeFactor, 384 * sizeFactor);
    
    warpersL = * new ofxGLWarper();
    warpersR = * new ofxGLWarper();
    warpersL.setup(0, 0, 512 * sizeFactor, 384 * sizeFactor);
    warpersR.setup(512 * sizeFactor, 0, 512 * sizeFactor, 384 * sizeFactor);
    
    
    ofSetVerticalSync(true);
 
    
    _dir.listDir("dataMovies/snapshot/");
    _dir.allowExt("png");
    _dir.sort();
    
    silhoutteImg.resize(_dir.size());
    indexPositionWD.resize(_dir.size());
    for(int i = 0; i<silhoutteImg.size(); i++){
        silhoutteImg[i].load(_dir.getPath(i));
        indexPositionWD[i] = floor( ofRandom( positionsWD.size() ) );
    }
    

    
}




//--------------------------------------------------------------
void ofApp::update(){
    
    cout << mouseX * 2 << " : " << mouseY * 2 << endl;
    

 
    
    fboMain.begin();
    
    ofClear(0, 0);
    
    
    ofPushMatrix();
    ofPushStyle();
    
    if (ofGetFrameNum() % 60 == 0) {
        for(int i = 0; i<silhoutteImg.size(); i++){
            silhoutteImg[i].load(_dir.getPath(i));
        }
    }

    if (ofGetFrameNum() % 120 == 0) {
        for(int i = 0; i<silhoutteImg.size(); i++){
            indexPositionWD[i] = floor( ofRandom( positionsWD.size() ) );
        }
    }

    ofSetRectMode(OF_RECTMODE_CENTER);
    
    float _size = 0.175 * 0.5 * sizeFactor;
    
    ofSetColor(255);
    for(int i = 0; i<silhoutteImg.size(); i++){
        ofPushMatrix();
        ofTranslate( positionsWD[ indexPositionWD[i] ] * 0.5 * sizeFactor);
        silhoutteImg[i].draw(0, 0, silhoutteImg[i].getWidth() * _size, silhoutteImg[i].getHeight() * _size);
        ofPopMatrix();
    }
    ofPopStyle();
    
    ofPopMatrix();

    
    img.resize(1024 * sizeFactor, 384 * sizeFactor);
    img.draw(0, 0);
    
    
//    ofPushStyle();
//    ofSetColor(0,255,0);
//    for(int i=0; i<ofGetWidth(); i+=10) {
//        for(int j=0; j<ofGetHeight(); j+=10) {
//            ofDrawLine(i, 0, i, ofGetHeight());
//            ofDrawLine(0, j, ofGetWidth(), j);
//        }
//    }
//    ofPopStyle();
    
    fboMain.end();
    
    
    
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    
    
    
    
    
    
    
    ofImage _main;
    _main.allocate(1024 * sizeFactor, 384 * sizeFactor, OF_IMAGE_COLOR_ALPHA);
    ofPixels _pMain;
    _pMain.allocate(1024 * sizeFactor, 384 * sizeFactor, OF_PIXELS_BGRA);
    fboMain.readToPixels(_pMain);
    _main.setFromPixels(_pMain.getData(), 1024 * sizeFactor, 384 * sizeFactor, OF_IMAGE_COLOR_ALPHA);
    
    
    warpersL.begin();
    warpersL.draw();
    _main.drawSubsection(0, 0, 512 * sizeFactor, 384 * sizeFactor, 0, 0);
    warpersL.end();
    
    warpersR.begin();
    warpersR.draw();
    _main.drawSubsection(512 * sizeFactor, 0, 512 * sizeFactor, 384 * sizeFactor, 512 * sizeFactor, 0);
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



//--------------------------------------------------------------
void ofApp::positionSet(){
    
    positionsWD.push_back(ofPoint(57, 733));
    positionsWD.push_back(ofPoint(140, 733));
    positionsWD.push_back(ofPoint(290, 733));
    positionsWD.push_back(ofPoint(494, 733));
    positionsWD.push_back(ofPoint(634, 733));
    positionsWD.push_back(ofPoint(754, 733));
    positionsWD.push_back(ofPoint(848, 733));
    positionsWD.push_back(ofPoint(981, 733));
    positionsWD.push_back(ofPoint(1173, 733));
    positionsWD.push_back(ofPoint(1286, 733));
    positionsWD.push_back(ofPoint(1427, 733));
    positionsWD.push_back(ofPoint(1542, 733));
    positionsWD.push_back(ofPoint(1740, 733));
    positionsWD.push_back(ofPoint(1964, 733));
    
    positionsWD.push_back(ofPoint(382, 618));
    positionsWD.push_back(ofPoint(628, 618));
    positionsWD.push_back(ofPoint(678, 466));
    positionsWD.push_back(ofPoint(1420, 574));
    positionsWD.push_back(ofPoint(1904, 422));
    
}
