//
//  texture.cpp
//  singleParticle
//
//  Created by PengCheng on 10/8/12.
//
//

#include "texture.h"


texture::texture(){
    alpha=128;
    float h1 = ofMap(300, 0, 360, 0, 255);
    float h2 = ofMap(66, 0, 360, 0, 255);

    c1.setHsb(h1, 255, 255);
    c2.setHsb(h2, 255, 255);
}


void texture::draw(float _posx, float _posy){

    ofEnableAlphaBlending();
    ofSetColor(c1, alpha);
    ofCircle(_posx+ofRandom(-10,10), _posy+ofRandom(-10,10), 2);
//    ofSetColor(c2, alpha);
//    ofCircle(_posx+ofRandom(-5,5), _posy+ofRandom(-5,5), 2);
    ofDisableAlphaBlending();
}