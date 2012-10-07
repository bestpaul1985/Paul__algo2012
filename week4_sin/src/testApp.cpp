#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(30, 30, 30);
	
//	for (int i = 0; i < 50; i++){
//		particle myParticle;
//		myParticle.setInitialCondition(300,300,ofRandom(-10,10), ofRandom(-10,10));
//		// more interesting with diversity :)
//		//myParticle.damping = ofRandom(0.001, 0.05);
//		particles.push_back(myParticle);
//	}
	startTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
  
    
    
    

    if (ofGetElapsedTimeMillis()- startTime> 100) {
        
       
            float angle = TWO_PI/10;
            float radius = 10;
            angle*=b;
            b+=1;
            particle myParticle;
            myParticle.setInitialCondition(mouseX,mouseY, radius*cos(angle), radius*sin(angle));
            particles.push_back(myParticle);

        
        
        startTime = ofGetElapsedTimeMillis();
    }
    
    
    for (int i = 0; i < particles.size(); i++){
        
        float angle = TWO_PI/10;
        float force = 0.01;
		particles[i].resetForce();
		particles[i].addForce(force*cos(angle*i),force*sin(angle*i));
		particles[i].addDampingForce();
		particles[i].update();
	}
    

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255,0,225);


	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
    cout<< ofToString(sin(ofGetElapsedTimef()))<<endl;
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
