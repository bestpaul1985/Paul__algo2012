//
//  fireworks2.h
//  firework
//
//  Created by PengCheng on 9/24/12.
//
//

#ifndef __firework__fireworks2__
#define __firework__fireworks2__

#include <ofMain.h>

class fireworks2{

public:
    
    fireworks2();
    
    void update();
    void draw();
    
    ofPoint origpos;
    ofPoint pos;
    float radius;
    float size;
    float angle;
    float space;
    float speed;


};

#endif /* defined(__firework__fireworks2__) */
