//
//  ArchShadow.cpp
//  Wrap_set
//
//  Created by JeongHo Park on 02/11/2016.
//
//

#include "ArchShadow.hpp"


//--------------------------------------------------------------
void ArchShadow::setup(int _size, ofImage _img, vector<ofPoint> _p){
    
    arch01 = _img;
    
    positionsPlastgarten = _p;
    
    indexPositionWD.resize(_size);
    
    for(int i = 0; i<_size; i++){
        indexPositionWD[i] = floor( ofRandom( positionsWD.size() ) );
    }
    
    
}


//--------------------------------------------------------------
void ArchShadow::update(int _timeFrame){
    
    _fA = MIN( abs( sin(ofDegToRad((ofGetFrameNum() % _timeFrame) * 360.0/_timeFrame)) ) * 255, 100 ) * 2.55;
    
    
    if (_fA < 10) {
        bArch01Draw = true;
        if (bArch01Draw) {
            
            _xPos = ofRandom(1024 * sizeFactor);
            _sizeImage = ofRandom(0.35, 0.85);
            _colorFactor = ofRandom(0.75, 1.0);
            colorAlphaFactor = ofRandom(0.5, 1.0);
            
            for(int i = 0; i<silhoutteImg.size(); i++){
                indexPositionWD[i] = int(ofRandom( positionsPlastgarten.size()));
            }
            
            bArch01Draw = false;
        }
    }
    
}




//--------------------------------------------------------------
void ArchShadow::reload(vector<ofImage> & _img){
    
    silhoutteImg = _img;
    
}






//--------------------------------------------------------------
void ArchShadow::drawArchShadow(){
    
    
    ofPushMatrix();
    ofPushStyle();
    
    
    
    ofTranslate(_xPos, 384 * sizeFactor, 0);
    
    
    ofPushStyle();
    
    
    float _sizePalastFactor = 0.125;

    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for(int i = 0; i<silhoutteImg.size(); i++){

        ofPushMatrix();
        
        ofSetColor(255, _fA * colorAlphaFactor * 0.97);
        ofTranslate( positionsPlastgarten[indexPositionWD[i]] * _sizeImage);
        
        silhoutteImg[i].draw(0, -arch01.getHeight() * _sizeImage, silhoutteImg[i].getWidth() * _sizePalastFactor, silhoutteImg[i].getHeight() * _sizePalastFactor);
        
//        ofSetColor(255, (255-_fA));
//        ofDrawRectangle(0, -arch01.getHeight() * _sizeImage, silhoutteImg[i].getWidth() * _sizePalastFactor, silhoutteImg[i].getHeight() * _sizePalastFactor);

        ofPopMatrix();
    }
    
    ofPopStyle();
    
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(255, _fA * colorAlphaFactor * 1.2);
    arch01.draw(0, -arch01.getHeight() * _sizeImage, arch01.getWidth() * _sizeImage, arch01.getHeight() * _sizeImage);
    
    ofPopStyle();
    ofPopMatrix();
    
    
    ofPopStyle();
    ofPopMatrix();
    
    
}
