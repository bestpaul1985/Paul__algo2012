//
//  fireworks2.cpp
//  firework
//
//  Created by PengCheng on 9/24/12.
//
//

#include "fireworks2.h"

fireworks2::fireworks2(){
    
  
    origpos.set(500,300);
    size = 1;
    speed = 0.01f;

    
}

void fireworks2::update(){
    
    
    
    
   
    
    
    

}


void fireworks2::draw(){
    
    
    ofRect(origpos.x, origpos.y,10,10);
    
//    for(int i = 0; i< 4; i++){
//    
//        
//      	float radius = 50 + i * 20;
//        
//        for(int k=0; k < 5; k++){
//            
//            float angle = ofGetElapsedTimef() * (1 + i/5);
//            float x = origpos.x + radius * cos(angle+PI*2/5*k);
//            float y = origpos.y + radius * -sin(angle+PI*2/5*k);
//		
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofSetColor(255,255,255);
//        
//            ofRect(x,y,10,10);
//        }
    
    
        for(int i = 0; i< 30; i++){
            
              
                
           
            
            space += speed*10;
            if(space > 100){
                space = 0;
            }
            
                float radius = ofRandom(0,space);
                float angle = ofGetElapsedTimef() * (1 + (i+1)/float(ofRandom(0,2)));
                float x = origpos.x + radius * cos(angle);
                float y = origpos.y + radius * -sin(angle);
                
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
                ofRect(x,y,10,10);
            

    }
    
  
    
    
    
    
}