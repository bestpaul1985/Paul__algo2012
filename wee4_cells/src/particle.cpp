#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.1f;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
    
    
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    
    
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    
    float r;
    float b;
    if (pos.x<ofGetWidth()/2) {
        
         r = ofMap(pos.x,0, ofGetWidth()/2, 0, 255);
    }else{
    
         r = ofMap(pos.x, ofGetWidth()/2, ofGetWidth(), 0 , 255);
        
         r = 255-r;
    
    }
   
    if (pos.y<ofGetHeight()/2) {
        
        b = ofMap(pos.y,0, ofGetHeight()/2, 0, 255);
    }else{
        
        b = ofMap(pos.y, ofGetHeight()/2, ofGetHeight(), 0, 255);
        b = 255-b;
    }
    
    
    ofColor color(r,0,b,128);
    ofColor color2(255,255,0);
    ofSetColor(color);
    ofCircle(pos.x, pos.y, 10);
    ofSetColor(r,0,b,50);
    ofCircle(pos.x, pos.y, 15);
    ofSetColor(color2);
    ofCircle(pos.x, pos.y, 2);
}

