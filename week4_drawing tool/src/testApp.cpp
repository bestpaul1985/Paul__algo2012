#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);	
	ofBackground(255, 255, 255);

    doorHalfOpen = false;
    ofSetCircleResolution(10);
}

//--------------------------------------------------------------
void testApp::update(){
    
    tempBrush.update();
    
    

/////////////////////////draw particals
    for (int i=0; i<brushs.size(); i++) {
            brushs[i].update();
            brushs[i].mouseDetect(mouseX, mouseY);
    }
    
    
    
   
    
    
///////////////////////detect collisions
    if(brushs.size()>1){
        
        for (int i=0; i<brushs.size()-1; i++) {
            
            
            if (brushs[i].outLine.rect.inside(brushs[i+1].outLine.rect.getCenter())) {
                
                
                for (int k=0; k< brushs[i].p.size(); k++) {
                    float x =brushs[i].p[k].pos.x;
                    float y = brushs[i].p[k].pos.y;
                    brushs[i].p[k].setInitialCondition(x,y, ofRandom(-10,10), ofRandom(-10,10));
                    
                }
            }
            
            cout<<ofToString(brushs[i].outLine.rect.getCenter()) <<endl;
            cout<<ofToString(brushs[i+1].outLine.rect.getCenter()) <<endl;
            
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    tempBrush.draw(rectDraw);
    for (int i=0; i<brushs.size(); i++) {
        brushs[i].draw(rectDraw);
    }
    
      
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    switch (key) {
        case 'e':
            rectDraw = true;
            break;
            
        case 'r':
            rectDraw = false;
            break;
    }
    

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
   
    if(doorHalfOpen ==false){
        tempBrush.mousedown(x, y);
    }
    
    
   
    
       if (doorOpen) {
           
           for (int i=0; i<brushs.size(); i++) {
               
               if (brushs[i].doorOpen==true) {
                   
               
               float dx = x - prevMouseX;
               float dy = y - prevMouseY;
               ofPoint tempForc;
               tempForc.x = dx*0.001;
               tempForc.y = dy*0.001;
               
               brushs[i].getForce(tempForc.x, tempForc.y);
               
               brushs[i].doorOpen = false;

               }
    
            }
       }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	 
    if(doorHalfOpen==false){
        tempBrush.mousedown(x, y);
        
//        for (int i=0; i<brushs.size(); i++) {
//            
//            ofPoint tempForc;
//            tempForc.x = 0;
//            tempForc.y = 0;
//            forc.push_back(tempForc);
//            
//        }
    }
    
    
    if(doorHalfOpen==true){
        doorOpen = true;
    }
    
    
    
    
    
   
    
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    
    if(doorHalfOpen==false){
    brushs.push_back(tempBrush);
    tempBrush.clear();
    }
    doorHalfOpen = true;
    if(doorOpen){
        doorHalfOpen = false;
        doorOpen = false;
    }
   
    
    
    
}
