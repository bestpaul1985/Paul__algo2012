//
//  texture.h
//  singleParticle
//
//  Created by PengCheng on 10/8/12.
//
//

#ifndef __singleParticle__texture__
#define __singleParticle__texture__

#include "ofMain.h"

class texture{

public:
    
    texture();
    void draw(float _posx, float _posy);
    void update();
    ofColor c1;
    ofColor c2;
    float alpha;


};

#endif /* defined(__singleParticle__texture__) */
