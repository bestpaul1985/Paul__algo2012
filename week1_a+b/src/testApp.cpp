#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	verdana30.loadFont("verdana.ttf", 80, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
    
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	pctSpeed = 0.001f;
	ofSetVerticalSync(true);
    ofSetFrameRate(60); 
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 10;
	myRectangle.posa.y = ofGetHeight()/2;
	myRectangle.posb.x = ofGetWidth();
	myRectangle.posb.y = ofGetHeight()/2;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
	
	
	
} 

//--------------------------------------------------------------
void testApp::update(){
	
	// to see pct in the console
	//printf("%f \n", pct);
	 
	pct += pctSpeed;							// increase by a certain amount
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}	
	myRectangle.interpolateByPct(pct);		// go between pta and ptb
    
    sqSpeed = 10*pctSpeed*60*3600/63360;

}

//--------------------------------------------------------------
void testApp::draw(){
	    
    ofSetColor(20);
    verdana30.drawString(ofToString(sqSpeed,3) + "/MPH", ofGetWidth()/2-310, ofGetHeight()/2+20);
    ofSetColor(50);
    verdana30.drawString(ofToString(sqSpeed,3) + "/MPH", ofGetWidth()/2-309, ofGetHeight()/2+21);

    
    myRectangle.draw();
    ofSetColor(200, 50, 11);
    
     ofDrawBitmapString("Press =/- increase or decrease speed. pctSpeed = " + ofToString(pctSpeed), 40, ofGetHeight()-30);
     ofDrawBitmapString("Press m to have the fastest motion be imperceptible", 40, ofGetHeight()-20);
     ofDrawBitmapString("Press n to have the fastest motion be still perceived as continuous", 40, ofGetHeight()-10);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    switch (key) {
    
        case '=':
            pctSpeed += 0.001f;
            break;
        case '-':
            pctSpeed -= 0.001f;
            break;
        case 'm':
            pctSpeed = 0.0003f;
            break;
        case 'n':
            pctSpeed = 0.05f;
            break;
            
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
