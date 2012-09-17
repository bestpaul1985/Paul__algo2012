#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	click = true;
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofBackground(30,30,30);
	
	
	// set the "a" and "b" positions of the rectangle...
	
	myRectangle.posa.x = 50;
	myRectangle.posa.y = 50;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = 500;
	
	
	myRectangle.radiusa = 30;
	myRectangle.radiusb = 200;
	
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter...
    
    ofSetCircleResolution(100);
} 

//--------------------------------------------------------------
void testApp::update(){
	
    printf("%f \n", pct);
	
	pct = pct + 0.01;
		if (pct > 1){
			pct = 0;	
		}
	
	myRectangle.interpolateByPct(pct);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	    
    ofSetColor(174,9,111);
    ofCircle(myRectangle.posa.x, myRectangle.posa.y, 3);
    ofCircle(myRectangle.posb.x, myRectangle.posb.y, 3);
    ofNoFill();
    ofCircle(myRectangle.posa.x, myRectangle.posa.y, 10);
    ofCircle(myRectangle.posb.x, myRectangle.posb.y, 10);
    ofDrawBitmapString("1", myRectangle.posa.x+10, myRectangle.posa.y+10);
    ofDrawBitmapString("2", myRectangle.posb.x+10, myRectangle.posb.y+10);
    ofLine(myRectangle.posa.x, myRectangle.posa.y, myRectangle.posb.x, myRectangle.posb.y);
	
    
    
    myRectangle.draw();
    
    
	ofSetColor(255,255,255);
	ofDrawBitmapString("mouse height controls interpolation (pct = " + ofToString(pct) + ")", 20, 20);
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
    
    if (click) {
        myRectangle.posa.x = x;
        myRectangle.posa.y = y;
        click = false;
    }else {
        myRectangle.posb.x = x;
        myRectangle.posb.y = y;
        click = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
