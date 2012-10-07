#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
//	ofSetFrameRate(60);
	backgroundImage.loadImage("Cell-3.jpeg");
	
    ofSetVerticalSync(true);
	for (int i = 0; i < 200; i++){
		particle myParticle;
		float vx = 0;
		float vy = 0;
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this: 
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
        
		particles[i].addForce(sin(ofGetElapsedTimef()*ofRandom(10)),cos(ofGetElapsedTimef()*ofRandom(10)));  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(128);
    backgroundImage.draw(0, 0,1024,768);
    
	
	ofEnableAlphaBlending();
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    ofDisableAlphaBlending();

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
	for (int i = 0; i < particles.size(); i++){
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	
	
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
