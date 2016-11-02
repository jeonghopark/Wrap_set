#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    sizeFactor = 1;
    
    positionSet();
    
    img.load("backgroundWD.png");
    
    arch01.load("imageSource/03_plastgarten_IMG_2000.png");
    arch02.load("imageSource/04_Garden_P1000895_06.png");
    door01.load("imageSource/DomPlatz_P1010110_11.png");
    
    
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
//    indexPositionWD.resize(_dir.size());
    for(int i = 0; i<silhoutteImg.size(); i++){
        silhoutteImg[i].load(_dir.getPath(i));
//        indexPositionWD[i] = floor( ofRandom( positionsWD.size() ) );
    }
    
    palastGarten.setup(_dir.size(), arch01, positionsPlastgarten);
    palastGarten.sizeFactor = sizeFactor;
    palastGarten.silhoutteImg = silhoutteImg;

    garten.setup(_dir.size(), arch02, positionsPlastgarten);
    garten.sizeFactor = sizeFactor;
    garten.silhoutteImg = silhoutteImg;
    
    
    door.setup(_dir.size(), door01, positionsPlastgarten);
    door.sizeFactor = sizeFactor;
    door.silhoutteImg = silhoutteImg;
    
    
    bColorDesolve = false;
    

    
}




//--------------------------------------------------------------
void ofApp::update(){
    

//    if (sizeFactor == 1) {
//        cout << mouseX * 2 << " : " << mouseY * 2 << endl;
//    } else {
//        cout << mouseX * 1 << " : " << mouseY * 1 << endl;
//    }
    
    
    if (ofGetFrameNum() % 60 == 0) {
        
        for(int i = 0; i<silhoutteImg.size(); i++){
            silhoutteImg[i].load(_dir.getPath(i));
        }

        palastGarten.reload(silhoutteImg);
        garten.reload(silhoutteImg);
        door.reload(silhoutteImg);
    }


//    float _size = 0.175 * 0.5 * sizeFactor;

    

    
    fboMain.begin();
    

    ofClear(0, 0);
    

    
//    ofPushMatrix();
    
//    ofPushStyle();
    

//    if (ofGetFrameNum() % 60 == 0) {
//        for(int i = 0; i<silhoutteImg.size(); i++){
//            silhoutteImg[i].load(_dir.getPath(i));
//        }
//    }
//
//
//    if (ofGetFrameNum() % 120 == 0) {
//        bColorDesolve = true;
//        for(int i = 0; i<silhoutteImg.size(); i++){
//            indexPositionWD[i] = floor( ofRandom( positionsWD.size() ) );
//        }
//    }
//
//    
//    
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    
//    for(int i = 0; i<silhoutteImg.size(); i++){
//        ofPushMatrix();
//        ofTranslate( positionsWD[ indexPositionWD[i] ] * 0.5 * sizeFactor);
//        ofSetColor(255);
//        silhoutteImg[i].draw(0, 0, silhoutteImg[i].getWidth() * _size, silhoutteImg[i].getHeight() * _size);
//        
//        ofSetColor(255, _f);
//        ofDrawRectangle(0, 0, silhoutteImg[i].getWidth() * _size, silhoutteImg[i].getHeight() * _size);
//        ofPopMatrix();
//    }
//    ofPopStyle();
    
//    ofPopMatrix();

    
    
    
    
//    img.resize(1024 * sizeFactor, 384 * sizeFactor);
//    img.draw(0, 0);
    

    palastGarten.update(310);
    palastGarten.drawArchShadow();

    garten.update(260);
    garten.drawArchShadow();
    
    door.update(300);
    door.drawArchShadow();

    
    
    fboMain.end();
    
    
    
    
}



////--------------------------------------------------------------
//void ofApp::drawArchShadow(int _timeFrame, ofImage _img){
//
//        
//    ofPushMatrix();
//    ofPushStyle();
//    
//    
//    float _fA = MIN( abs( sin(ofDegToRad((ofGetFrameNum() % _timeFrame) * 360.0/_timeFrame)) ) * 255, 100 ) * 2.55;
//    
//    
//    if (_fA < 10) {
//        bArch01Draw = true;
//        if (bArch01Draw) {
//            _xPos = ofRandom(1024 * sizeFactor);
//            _sizeImage = ofRandom(0.35, 0.65);
//            _colorFactor = ofRandom(0.75, 1.0);
//            for(int i = 0; i<silhoutteImg.size(); i++){
//                indexPositionWD[i] = floor( ofRandom( positionsPlastgarten.size() ) );
//            }
//            bArch01Draw = false;
//        }
//    }
//    
//    
//    ofTranslate(_xPos, 384 * sizeFactor, 0);
//    
//    
////    ofPushStyle();
////    
////    float _sizePalastFactor = 0.125;
////    for(int i = 0; i<silhoutteImg.size(); i++){
////        ofPushMatrix();
////        ofSetRectMode(OF_RECTMODE_CENTER);
////        ofSetColor(255);
////        ofTranslate( positionsPlastgarten[indexPositionWD[i]] * _sizeImage);
////        silhoutteImg[i].draw(0, -arch01.getHeight() * _sizeImage, silhoutteImg[i].getWidth() * _sizePalastFactor, silhoutteImg[i].getHeight() * _sizePalastFactor);
////        
////        ofSetColor(255, 255-_fA);
////        ofDrawRectangle(0, -arch01.getHeight() * _sizeImage, silhoutteImg[i].getWidth() * _sizePalastFactor, silhoutteImg[i].getHeight() * _sizePalastFactor);
////        ofPopMatrix();
////    }
////    
////    ofPopStyle();
//    
//    
//    ofPushMatrix();
//    ofPushStyle();
//    
//    ofSetRectMode(OF_RECTMODE_CORNER);
//    ofSetColor(255, _fA);
//    _img.draw(0, -_img.getHeight() * _sizeImage, _img.getWidth() * _sizeImage, _img.getHeight() * _sizeImage);
//    
//    ofPopStyle();
//    ofPopMatrix();
//    
//    
//    ofPopStyle();
//    ofPopMatrix();
//
//    
//}




//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
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
    
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 2), 10, 10);
    ofPopStyle();
    ofPopMatrix();
    
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
            
            
        case 'c':
            bColorDesolve = true;
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
    
    
    positionsPlastgarten.push_back(ofPoint(78, 747));
    positionsPlastgarten.push_back(ofPoint(204, 747));
    positionsPlastgarten.push_back(ofPoint(329, 747));
    positionsPlastgarten.push_back(ofPoint(461, 747));
    positionsPlastgarten.push_back(ofPoint(585, 747));
    
    positionsPlastgarten.push_back(ofPoint(78, 575));
    positionsPlastgarten.push_back(ofPoint(203, 575));
    positionsPlastgarten.push_back(ofPoint(329, 575));
    positionsPlastgarten.push_back(ofPoint(461, 575));
    positionsPlastgarten.push_back(ofPoint(585, 575));

}


//--------------------------------------------------------------
void ofApp::exit(){
    
//    system("osascript -e 'tell app \"System Events\" to shut down'");
    
}










