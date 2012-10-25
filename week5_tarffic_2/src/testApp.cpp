#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 3; i++){
		particle myParticle;
		myParticle.setInitialCondition(30,300+100*i,ofRandom(5,10),0, 0.15+0.03f*i);
		particles.push_back(myParticle);
	}
	
	VF.setupField(80,60,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	direction =0;
	drawingStyle = 4;
	bFade = false;
    bVf = false;
    
    backgroundImage.loadImage("map2.jpg");
    
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    myRoad.update();
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofSetColor(255);
    backgroundImage.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
    
    
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	
    if (bVf)VF.draw();
    if (!bVf)myRoad.draw();
	
	ofSetColor(0,0,0);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
    
    
	ofSetColor(0,130,130, 200);
	ofRect(180,70,300,75);
	ofSetColor(255,255,255);
	ofDrawBitmapString("space to clear\  vector field 'd'\ntoggle fade 'f'", 50, 50);	
	ofSetColor(255,255,130);
	switch (drawingStyle){
		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
			break;
		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
			break;
		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
			break;
		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
			break;
        case 4: ofDrawBitmapString("drawing mode: Road", 50, 90);
			break;
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 5;
	} else if (key == 'f'){
		bFade = !bFade;
	}else if (key == 'd'){
        bVf =! bVf;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (button == 0) {
		switch (drawingStyle){
			case 0: VF.addInwardCircle((float)x, (float)y, 50, 0.3f);
				break;
			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
            case 4:
                float diffx = x - prevMouseX;
                float diffy = y - prevMouseY;
                    
                ofPoint diff(diffx, diffy);
                diff.normalize();
                
//                cout<<"diffx= "+ofToString(diff)<<endl;
                
                if (x>prevMouseX&&y==prevMouseY) {
                    direction = 0;
                }else if(x>prevMouseX&&y>prevMouseY){
                    direction = 1;
                }else if(x==prevMouseX&&y>prevMouseY){
                    direction = 2;
                }else if(x<prevMouseX&&y>prevMouseY){
                    direction = 3;
                }else if(x<prevMouseX&&y==prevMouseY){
                    direction = 4;
                }else if(x<prevMouseX&&y<prevMouseY){
                    direction = 5;
                }else if(x==prevMouseX&&y<prevMouseY){
                    direction = 6;
                }else if(x>prevMouseX&&y<prevMouseY){
                    direction = 7;
                }
                
                VF.addVectorRect((float)x, (float)y, diff.x*10, diff.y*10, 30, 0.9f, direction);
               
                prevMouseX = x;
                prevMouseY = y;
                
                myRoad.mouseDragged(x, y);
                   
                
            break;
        }
    }
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    prevMouseX = x;
	prevMouseY = y;
    myRoad.mousePressed(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    myRoad.mouseReleased();
}
