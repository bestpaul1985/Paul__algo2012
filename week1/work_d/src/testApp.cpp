#include "testApp.h"


class circleSpot {
    
    
public: 
    float innerRadius;
    float outerRadius;
    ofPoint pos;
    ofColor colorA;
    ofColor colorB;
    float pct;
    
    void setup(ofPoint weizhi){
        pos.set(weizhi);
        innerRadius = 25;
        outerRadius = innerRadius + 250;
        colorA.setHsb(ofRandom(0,60),255,255);
        colorB.setHsb(ofRandom(0,255), 200,200);
        
        
    }
    
    void update(ofPoint mouse){
        float distance = (pos - mouse).length();
        pct = (distance - innerRadius) / (outerRadius - innerRadius);
        pct = ofClamp(pct, 0,1);
        
    }
    
    void draw(){
        ofColor mix;
        mix.r = (1-pct) * colorA.r + (pct) * colorB.r;
        mix.g = (1-pct) * colorA.g + (pct) * colorB.g;
        mix.b = (1-pct) * colorA.b + (pct) * colorB.b;
        ofSetColor(mix);
        ofCircle(pos, innerRadius * (pct));
    }
    
    
    
};

circleSpot s;
vector < circleSpot > spots;

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing;
    ofSetCircleResolution(100);
    
    for (int i = 0; i < 30; i++){
        for (int k =0; k<30; k++) {
            
            circleSpot c;
            ofPoint d;
            d.set(i*40, k*40);
            c.setup(d);
            spots.push_back(c);
       }  
    }

}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < 900; i++){
        spots[i].update(ofPoint(mouseX, mouseY));
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(176,223,108);
    for (int i = 0; i < 900; i++){
            spots[i].draw();
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