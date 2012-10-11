//
//  outlines.cpp
//  singleParticle
//
//  Created by PengCheng on 10/9/12.
//
//

#include "outlines.h"


outlines::outlines(){

    mouseInsideRect = false;

}
//----------------------------------

void outlines::getData(int _x, int _y, int _size){
    
    ofPoint tempPos;
    tempPos.x= _x;
    tempPos.y= _y;
    Pos.push_back(tempPos);
    
    if(Pos.size()>_size){
        Pos.erase(Pos.begin());
    }
        
    }
//----------------------------------
void outlines::update(){

    if (Pos.size()>1) {
        
        
        Min.set(ofGetWidth(), ofGetHeight());
        Max.set(0, 0);
        
        for (int i=0; i<Pos.size()-1; i++) {
            
            Min.x = MIN(Min.x, Pos[i].x);
            Min.y = MIN(Min.y, Pos[i].y);
            Max.x = MAX(Max.x, Pos[i].x);
            Max.y = MAX(Max.y, Pos[i].y);
            
        }
    }
    
    
    rect.set(Min.x, Min.y, Max.x-Min.x, Max.y-Min.y);
}
//----------------------------------
void outlines::draw(){
    
    
    ofRect(rect);

}

//-----------------------------------

