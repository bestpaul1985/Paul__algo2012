//
//  hero.cpp
//  exlposion
//
//  Created by PengCheng on 9/24/12.
//
//

#include "hero.h"

hero::hero(){
    
    speed = 0.01f;
    timeup = 10;
    current = ofGetElapsedTimef();
    timeswich = false;
    swichonce = true;
    xorig = ofGetWidth()/2;
    yorig = ofGetHeight()/2;
    
    
}

void hero::update(){
    
    
    
    if(ofGetElapsedTimef()-current > timeup && timeswich== false){
        
        timeswich = true;
    }
    
    if(ofGetElapsedTimef()-current > 2 && swichonce == false){
        vspeed = 1;
    }
    
    if(ofGetElapsedTimef() > 3 && swichonce){
        vspeed = 8;
    }
    if(timeswich){
        vspeed = 4;
        current = ofGetElapsedTimef();
        timeswich = false;
        swichonce = false;
        
    }
    
    
    Vibrator = vspeed*sin(ofGetElapsedTimef()*100);
}

void hero::draw(){
    
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
   if(ofGetElapsedTimef()<17){
    for(int i = 0; i<8; i++){
        posb.x= xorig;
        posa.y= ofGetHeight()/2+30*i;
        
        posb.x= xorig;
        posb.y= ofGetHeight()/2+30*(i+1);
        
        
        pct+=speed;
        
        if(pct>1){
            pct = 0;
        }
        pos.x= (1-pct)*posa.x+pct*posb.x;
        pos.y= (1-pct)*posa.y+pct*posb.y;
        
        
        
        ofColor c(255,255,255,128);
        ofSetColor(c);
        ofRect(xorig+Vibrator,pos.y+15,25/(i+2),25/(i+2));
        ofRect(xorig-8+Vibrator,pos.y+15,25/(i+2),25/(i+2));
        ofRect(xorig+8+Vibrator,pos.y+15,25/(i+2),25/(i+2));
        
        ofRect(xorig+Vibrator,pos.y+15,10/(i+2),10/(i+2));
        ofRect(xorig-8+Vibrator,pos.y+15,10/(i+2),10/(i+2));
        ofRect(xorig+8+Vibrator,pos.y+15,10/(i+2),10/(i+2));
    }
    
    
    ofColor d(255,255,255,100);
    ofSetColor(d);
    ofRect(xorig+Vibrator, ofGetHeight()/2, 30, 30);
    ofRect(xorig+Vibrator, ofGetHeight()/2, 25, 25);
    ofColor s(255,255,255);
    ofSetColor(s);
    ofRect(xorig+Vibrator, ofGetHeight()/2, 20, 20);

    }



    
    if(ofGetElapsedTimef()>17){
        
        
        
        for(int i = 0; i<8; i++){
            
            posa.x= xorig-30*i;
            posb.y= ofGetHeight()/2;
            
            posb.x= xorig-30*(i+1);
            posb.y= ofGetHeight()/2;
            
            pct+=speed;
            
            if(pct>1){
                pct = 0;
            }
            pos.x= (1-pct)*posa.x+pct*posb.x;
            pos.y= (1-pct)*posa.y+pct*posb.y;
            
            
            
            ofColor c(255,255,255,128);
            ofSetColor(c);
            ofRect(pos.x-15,ofGetHeight()/2+Vibrator,25/(i+2),25/(i+2));
            ofRect(pos.x-15,ofGetHeight()/2-8+Vibrator,25/(i+2),25/(i+2));
            ofRect(pos.x-15,ofGetHeight()/2+8+Vibrator,25/(i+2),25/(i+2));
            
            ofRect(pos.x-15,ofGetHeight()/2+Vibrator,15/(i+2),15/(i+2));
            ofRect(pos.x-15,ofGetHeight()/2-8+Vibrator,15/(i+2),15/(i+2));
            ofRect(pos.x-15,ofGetHeight()/2+8+Vibrator,15/(i+2),15/(i+2));
        }
        
        
        ofColor d(255,255,255,100);
        ofSetColor(d);
        ofRect(xorig, ofGetHeight()/2+Vibrator, 30, 30);
        ofRect(xorig, ofGetHeight()/2+Vibrator, 25, 25);
        ofColor s(255,255,255);
        ofSetColor(s);
        ofRect(xorig, ofGetHeight()/2+Vibrator, 20, 20);
        
       
        
    }



}