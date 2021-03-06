#include "particle.h"
#include "ofMain.h"

//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.015f;
    drawWhat = 0;
    _posx=0;
    _posy=0;
    radius = 30;
    prevPos.set(0, 0);
    catchUpSpeed = 0.03f;
    
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
void particle::addRepulsionForce(float x, float y, float radius, float scale){
    
	// ----------- (1) make a vector of where this position is: 
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addAttractionForce(float x, float y, float radius, float scale){
    
	// ----------- (1) make a vector of where this position is: 
	
	ofVec2f posOfForce;
	posOfForce.set(x,y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addRepulsionForce(particle &p, float radius, float scale){
	
	// ----------- (1) make a vector of where this particle p is: 
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
		p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addAttractionForce(particle & p, float radius, float scale){
	
	// ----------- (1) make a vector of where this particle p is: 
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
		p.frc.x = p.frc.x + diff.x * scale * pct;
        p.frc.y = p.frc.y + diff.y * scale * pct;
    }
	
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
    
    switch (drawWhat) {
        case 0:
            
           
        break;
       
    }
    
    switch (drawWhat){
		case 0:
        
        {
            float dx = vel.x-prevPos.x;
            float dy = vel.y-prevPos.y;
            myAngle = atan2(dy,dx);
            prevPos.set(vel);
        }
            
			break;
		
        case 1:
            
        {

            if (pos!=prevPos) {
                
                ofPoint p;
                p = pos;
                points.push_back(p);
                
            }
            
            if (points.size()>100) {
                points.erase(points.begin());
            }
        }
            
			break;
	}
   
}

//------------------------------------------------------------
void particle::draw(){

    switch (drawWhat) {
        case 0:
            ofEnableAlphaBlending();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofFill();
            ofPushMatrix();
                
                ofTranslate(pos.x,pos.y);
                ofRotateZ((myAngle+ofGetElapsedTimef())*RAD_TO_DEG);
                ofSetColor(255, 255, 255);
                asteroid->draw(0,0, asteroid->width/3*scale, asteroid->height/3*scale);

            ofPopMatrix();
            ofSetRectMode(OF_RECTMODE_CORNER);
            ofDisableAlphaBlending();
            
            break;
            
        case 1:
            ofEnableAlphaBlending();
            ofSetRectMode(OF_RECTMODE_CENTER);
            
            
            ofPushMatrix();
            
                ofTranslate(pos.x, pos.y);
                ofRotateZ(angle);
                alpha = ofMap(alpha, 0, 0.05, 0, 255);
                ofSetColor(255, alpha);
                imgFire->draw(-30, 0);
                ofSetColor(255, 255, 255);
                img->draw(0, 0);
            
            ofPopMatrix();
            
            
            
            ofDisableAlphaBlending();
            ofSetRectMode(OF_RECTMODE_CORNER);
            break;
            
        case 2:
            ofEnableAlphaBlending();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofNoFill();
            ofPushMatrix();
            ofTranslate(pos.x, pos.y);
            ofSetColor(255);
            saver->draw(0, 0,saver->width/2,saver->height/2);
            ofPopMatrix();
            ofSetRectMode(OF_RECTMODE_CORNER);
            ofDisableAlphaBlending();
            break;
    }
        
    
    
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
    bool bDidICollide = false;
	
	// what are the walls
	float minx = -ofGetWidth()*1.5;
	float miny = -ofGetWidth()*1.5;
	float maxx = ofGetWidth()*2.5;
	float maxy = ofGetWidth()*2.5;
	
	if (_posx > maxx){
		pos.x = ofGetWidth()/2+90;
		vel.x *= -1;
		bDidICollide = true;
	} else if (_posx < minx){
		pos.x = ofGetWidth()/2-90;
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (_posy > maxy){
        pos.y = ofGetHeight()/2+90;
        vel.y *= -1;
		bDidICollide = true;
	} else if (_posy < miny){
        pos.y = ofGetHeight()/2-90;
		vel.y *= -1;
		bDidICollide = true;
	}
	
    if (bDidICollide == true && bDampedOnCollision == true){
        
        bDidICollide2 = false;
        
	}else{
        
        bDidICollide2 = true;
    }
	
}


//----------------------------------------------------------
void particle::moveOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
    
	
	// what are the walls
	float minx = ofGetWidth()/2-100;
	float miny = ofGetHeight()/2-100;
	float maxx = ofGetWidth()/2+100;
	float maxy = ofGetHeight()/2+100;
	
	if (pos.x > maxx&&bDidICollide2){
        pos.x= maxx; // move to the edge, (important!)
		bDidICollide2 = true;
	} else if (pos.x < minx&&bDidICollide2){
		pos.x = minx; // move to the edge, (important!)
		bDidICollide2 = true;
	}
	
	if (pos.y > maxy&&bDidICollide2){
		pos.y = maxy; // move to the edge, (important!)
		bDidICollide2 = true;
	} else if (pos.y < miny&&bDidICollide2){
		pos.y = miny; // move to the edge, (important!)
		bDidICollide2 = true;
	}
    
//    ofPoint mid;
//    mid.set(ofGetWidth()/2, ofGetHeight()/2);
//    ofPoint diff = pos- mid;
//    if (diff.length()>200) {
//        pos = mid+diff;
//    }
    
 
	
	
}

