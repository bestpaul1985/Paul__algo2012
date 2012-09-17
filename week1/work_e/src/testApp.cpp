#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	ofBackground(30,30,30);
    
    for(int i =0; i<num; i++){
        myRectangle[i].pos.x = ofRandom(50,100);
        myRectangle[i].pos.y = ofRandom(50,100);
        myRectangle[i].catchUpSpeed = ofRandom(0.0005,0.01);
        myRectangle[i].color.setHsb(ofRandom(168,198),180,180);

    }

    

}

//--------------------------------------------------------------
void testApp::update(){

    
    for(int i =0; i<num; i++){
                myRectangle[i].xenoToPoint(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i =0; i<num; i++){
    myRectangle[i].draw();
    ofSetColor(198,246,55,100);
    ofLine(mouseX, mouseY, myRectangle[i].pos.x, myRectangle[i].pos.y);
    }
    ofNoFill();
    ofCircle(mouseX, mouseY, 7);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}