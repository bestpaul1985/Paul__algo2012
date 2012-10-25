#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0,0.2f);
	
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
void particle::setInitialCondition(float px, float py, float vx, float vy,float damp){
    pos.set(px,py);
	vel.set(vx,vy);
    prevPos.set(px, py);
    car.loadImage("car.png");
    damping = damp;
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
//    ofCircle(pos.x, pos.y, 3);
    ofSetRectMode(OF_RECTMODE_CENTER); 
    ofSetColor(198,246,55);
    float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);
    
    ofPushMatrix();
    
    
    ofTranslate(pos.x, pos.y, 0);
//    if (angle>PI/2||angle<(PI/2*-1)) {
//        ofScale(1, -1);
//    }
    
    
    ofRotateZ(angle * RAD_TO_DEG);
    ofRect( 0,0, 5,5);
    ofSetColor(255);
    car.draw(0,-10,102*0.5,82*0.5);
	ofPopMatrix();
    
    prevPos.x = pos.x;
	prevPos.y = pos.y;
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
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
		vel *= 0.3;
	}
	
}
