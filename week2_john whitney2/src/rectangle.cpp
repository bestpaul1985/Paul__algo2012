#include "rectangle.h"

//------------------------------------------------------------------------
rectangle::rectangle(float mySpeed){
    pct = 0;
    speed = mySpeed;
}


//------------------------------------------------------------------------

void rectangle::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255, 255, 255);
    ofRect(pos.x, pos.y, 1, 1);
    
    ofPoint temp;
    temp.x = pos.x;
    temp.y = pos.y;
    points.push_back(temp);
    
    if (points.size() > 500){
		points.erase(points.begin());
	}
    
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    ofNoFill();
    ofBeginShape();
    for (int k = 0; k < points.size(); k++){
        ofVertex(points[k].x, points[k].y);
    }
    ofEndShape();
    


}

//------------------------------------------------------------------------

void rectangle::interplateBypct(){
    
   
    
    
    if (pct > 1) {
		speed *= -1;
	} else if (pct < 0) {
		speed *= -1;
	} 
    
    pct += speed;
    
    
  
    
    pos.x = (1-pct)*posa.x + pct*posb.x;
    pos.y = (1-pct)*posa.y + pct*posb.y;
    
   


}




