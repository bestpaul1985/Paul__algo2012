//
//  outlines.h
//  singleParticle
//
//  Created by PengCheng on 10/9/12.
//
//

#ifndef __singleParticle__outlines__
#define __singleParticle__outlines__

#include "ofMain.h"
class outlines{
    
public:
    outlines();
    
    void getData(int _x, int _y, int _size);
    void update();
    void draw();
    
    
    ofRectangle rect;
    
    vector<ofPoint> Pos;
    
    ofPoint Max;
    ofPoint Min;
    
    bool mouseInsideRect;


};

#endif /* defined(__singleParticle__outlines__) */
