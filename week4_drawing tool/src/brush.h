//
//  brush.h
//  singleParticle
//
//  Created by PengCheng on 10/8/12.
//
//

#ifndef __singleParticle__brush__
#define __singleParticle__brush__

#include "ofMain.h"
#include "particle.h"
#include "outlines.h"

class brush{

public:
    brush();
    void update();
    void draw(bool _rectDraw);
    void mousedown(int _x, int _y);
    void mouseDetect(int _mouseX, int _mouseY);
    void getForce(float _forcX, float _forcY);
    void clear();
//get particle
    vector<particle> p;
    float forcX, forcY;
//get collication
    outlines outLine;
//get force
    bool mouseInRect;
    bool doorOpen;
    ofColor rectC;
   
};


#endif /* defined(__singleParticle__brush__) */
