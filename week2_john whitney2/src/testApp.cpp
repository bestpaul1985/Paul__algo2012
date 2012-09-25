#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    ofBackground(0, 0, 0);
    num = 20;
    
    myRectangle = new rectangle*[num];
    
    for (int i = 0; i <num; i++) {
        
        float x;
        x = 0.01f*i;
        myRectangle[i]= new rectangle(x);
    }

    
}

//--------------------------------------------------------------
void testApp::update(){
    
   
   

    for (int i=0; i<num; i++) {
        
        float xorig = 512;
        float yorig = 384;
        float angle = ofGetElapsedTimef()*0.1;
        float radiusa = 3000;
        float radiusb = 300;
        float xa = xorig + radiusa * cos(angle * 3.4);
        float ya = yorig + radiusa * -sin(angle * 4.7);
        float xb = xorig + radiusb * cos(angle * 3.4);
        float yb = yorig + radiusb * -sin(angle * 4.7);
        
        myRectangle[i]->posa.x = xa;
        myRectangle[i]->posa.y = ya;
        myRectangle[i]->posb.x = xb;
        myRectangle[i]->posb.y = yb;
   
        myRectangle[i]->posa.y +=(i*100);

        myRectangle[i]->posb.y +=(i*10);
        
        myRectangle[i]->interplateBypct();
    }
   
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for (int i; i<num; i++) {
        myRectangle[i]->draw();
        
        


    }
    
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