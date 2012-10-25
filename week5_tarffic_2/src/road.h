//
//  road.h
//  vectorField_wParticles
//
//  Created by PengCheng on 10/22/12.
//
//

#ifndef __vectorField_wParticles__road__
#define __vectorField_wParticles__road__

#include "ofMain.h"

class road{
public:
    road();
    void setup();
    void update();
    void mouseDragged(int x, int y);
    void mousePressed(int x, int y);
    void mouseReleased();
    void draw();
    
ofPoint pos;
float angle;
ofPoint prevPos;
float w1, w2;



vector<ofPolyline> stroke;
ofPolyline tempStroke;
    
};

#endif /* defined(__vectorField_wParticles__road__) */
