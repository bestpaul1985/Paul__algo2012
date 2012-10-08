#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	radius = 10;
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
	
	ofBackground(0, 0, 0);
	for (int i = 0; i < 20; i++){
		particle myParticle;
        float angle = TWO_PI/20;
		myParticle.setInitialCondition(300,300,radius*cos(angle*i), radius*sin(angle*i));
//        myParticle.damping = ofRandom(0.01, 0.05);
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
    
    posx = ofRandom(400,ofGetWidth()-400);
    posy = ofRandom(300,ofGetHeight()/2);
    radius = ofRandom(5,15);
    
	
	for (int i = 0; i < particles.size(); i++){
        
        float angle = TWO_PI/particles.size();
        particles[i].timer(2000,posx,posy,radius,angle*i);
		particles[i].resetForce();
		particles[i].addForce(0.0, 0.18);
		particles[i].addDampingForce();
//		particles[i].bounceOffWalls();
		particles[i].update();
        
        if (particles[i].colorOpen) {
            color.set(255, ofRandom(255), ofRandom(255));
            particles[i].colorOpen = false;
        }
       
	}
    
    
//    cout << "frc.y = "<< ofToString(particles[0].frc.y) << endl;

}

//--------------------------------------------------------------
void testApp::draw(){
    

    
    
	
	
	for (int i = 0; i < particles.size(); i++){
        
		particles[i].draw(color);
       
	}

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

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
