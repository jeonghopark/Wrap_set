//
//  ArchShadow.hpp
//  Wrap_set
//
//  Created by JeongHo Park on 02/11/2016.
//
//

#ifndef ArchShadow_hpp
#define ArchShadow_hpp

#include <ofMain.h>

class ArchShadow{
    
public:
    
    
    void setup(int _size, ofImage _img, vector<ofPoint> _p);
    void update(int _timeFrame);
    void reload(vector<ofImage> & _img);
    void draw();
    
    
    float sizeFactor;
    
    vector<ofImage> silhoutteImg;

    vector<int> indexPositionWD;
    vector<ofPoint> positionsWD;

    
    float _fA;
    
    ofImage arch01;
    bool bArch01Draw;
    float _xPos;
    float _sizeImage;
    float _colorFactor;
    vector<ofPoint> positionsPlastgarten;
    
    float colorAlphaFactor;
    
    void drawArchShadow();

};

#endif /* ArchShadow_hpp */
