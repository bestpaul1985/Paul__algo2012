//
//  hero.h
//  exlposion
//
//  Created by PengCheng on 9/24/12.
//
//

#ifndef __exlposion__hero__
#define __exlposion__hero__

#include <ofMain.h>

class hero{

public:
    
    hero();
    void draw();
    void update();
    float pct;
    float speed;
    ofPoint pos;
    ofPoint posa;
    ofPoint posb;
    float radius;
    float xorig;
    float yorig;
    float angle;
    float num;
    ofPoint p;
    ofPoint prevP;
    float Vibrator;
    float current;
    float timeup;
    float vspeed;
    bool timeswich;
    bool swichonce;
};

#endif /* defined(__exlposion__hero__) */
