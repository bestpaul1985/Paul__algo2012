#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
    startTime = ofGetElapsedTimeMillis();
    fire = false;
    colorOpen = false;
    pct = 1;
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
void particle::draw(ofColor pColor){
    
    
    pct-=0.01f;
    
    if (pct<0) {
        pct = 0;
    }
    ofColor temp;    
    temp.r = pct*pColor.r;
    temp.g = pct*255+(1-pct)*pColor.g;
    temp.b = pct*255+(1-pct)*pColor.b;
    ofSetColor(temp);
    ofCircle(pos.x, pos.y, 3);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit... for now, we don't
	bool bDampedOnCollision = false;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.9;
	}
	
}

void particle::timer(float _time, float _posx, float _posy, float _radius, float _angle){
    
    if(ofGetElapsedTimeMillis()-startTime>_time){
        fire = true;
        startTime = ofGetElapsedTimeMillis();
        colorOpen = true;
    }
    
    if (fire) {
        pos.set(_posx,_posy);
        vel.set(_radius*cos(_angle),_radius*sin(_angle));
        fire = false;
        pct = 1;
    }
    
    
}
