#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ofMain.h"

class explosion {

	public:
	
		explosion();
	
		void update();
		void draw();
        ofPoint pos;
        ofPoint posa;
        ofPoint posb;
        float radius;
        float speed;
        float angle;
        float pct;
        ofColor c1;
        ofColor c2;
        ofColor c3;
        float myPct;
        float shaper;
        float num;
        float current;
        bool explode;
        float rectsize;
    

};

#endif // RECTANGLE_H
