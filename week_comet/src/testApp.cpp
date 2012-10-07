#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofBackground(30, 30, 30);
	
	p.setInitialCondition(300,300,ofRandom(-1,1), ofRandom(-1,1));
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	p.resetForce();
    
    
	p.addForce(0, 0.2);
	p.addDampingForce();
	p.update();
    
    
    ofPoint temp;
    temp.x = p.pos.x;
    temp.y = p.pos.y;
    points.push_back(temp);
    if (points.size()>30) {
        points.erase(points.begin());
    }
    
    
   
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   ofNoFill();
   
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
        
       float alpha = ofMap(i, 0, points.size(), 0, 128);
        ofSetColor(255,255,0,alpha);
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
    ofFill();
	ofSetColor(255,0,225);
	p.draw();

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	p.setInitialCondition(x,y,ofRandom(-15,15), ofRandom(-15,15));
    points.resize(0);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
