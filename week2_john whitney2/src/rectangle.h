#ifndef composition_rectangle_h
#define composition_rectangle_h

#include "ofMain.h"
class rectangle {
    
    public:
        rectangle(float mySpeed);
        void draw();
        void interplateBypct();
    
        ofPoint pos;
        ofPoint posa;
        ofPoint posb;
    
        float pct;
        float speed;
    
        vector < ofPoint > points;
};

#endif
