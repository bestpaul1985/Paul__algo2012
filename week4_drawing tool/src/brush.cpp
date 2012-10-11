//
//  brush.cpp
//  singleParticle
//
//  Created by PengCheng on 10/8/12.
//
//

#include "brush.h"

brush::brush(){
    
    forcX =0;
    forcY =0;
    mouseInRect = false;
    rectC.set(255, 220, 0);
}


//------------------------------------------------------------------------------

void brush::update(){
    

    
    for (int i =0; i<p.size(); i++) {
        
        p[i].resetForce();
        p[i].addForce(forcX, forcY);
        p[i].addDampingForce();
        p[i].bounceOffWalls();
        p[i].update();

       
    }
    
    for (int i =0; i<p.size(); i++) {
    
        outLine.getData(p[i].pos.x, p[i].pos.y, p.size());
    
    
    }

    outLine.update();
    
}

//------------------------------------------------------------------------------
void brush::draw(bool _rectDraw){
    
    ofFill();
//    ofSetColor(0, 0, 0);
    for (int i =0; i<p.size(); i++) {
        p[i].draw();
    }
    
    ofNoFill();
    ofSetColor(rectC);
    if (_rectDraw) {
        outLine.draw();
    }
    
    
}

//------------------------------------------------------------------------------
void brush::mousedown(int _x, int _y){

    
    for (int i =0; i<20; i++) {
        particle temp;
        temp.setInitialCondition(_x, _y, ofRandom(0.01,0.1), ofRandom(0.01,0.1) );
        p.push_back(temp);

        if (p.size()>10000) {
            p.erase(p.begin());
        }
    }
    
    
    
}


//------------------------------------------------------------------------------

void brush::getForce(float _forcX, float _forcY){

    if(doorOpen){
        forcX = _forcX;
        forcY = _forcY;
    }
    
}

//--------------------------------------------------------------------------------

void brush::clear(){
    p.clear();
    outLine.Pos.clear();
    outLine.Max.set(0, 0);
    outLine.Min.set(0, 0);
}
//----------------------------------------------------------------------------------------
void brush::mouseDetect(int _mouseX, int _mouseY){

    if (outLine.rect.inside(_mouseX,_mouseY)) {
        doorOpen = !doorOpen;
        mouseInRect = true;
        rectC.set(255, 0, 220);
        
    }else{
        
        mouseInRect = false;
        rectC.set(255, 220, 0);

    }
}
