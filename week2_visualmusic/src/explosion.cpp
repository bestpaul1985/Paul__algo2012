#include "explosion.h"


//------------------------------------------------------------------
explosion::explosion(){
    
    speed = 0.001f;
    radius = 70;
    num = 10;
    current = ofGetElapsedTimef();
    explode = false;
    shaper = 1;
    posa.set(0,0);
    c1.set(30,120,255);
    c3.set(30,120,255);
    rectsize = 5;
}

void explosion::update(){
    
    
    
    float timeup = 2;
    
    if(ofGetElapsedTimef()-current > timeup){
        explode = true;
    }
  
 
    
    
    
}

//------------------------------------------------------------------
void explosion::draw() {
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    
    if(explode == false){
        
        if(ofGetElapsedTimef()>17){
            posa.x-=3;
            if(posa.x < 0){
                posa.x = ofGetWidth();
        }
        }
    
        if(ofGetElapsedTimef()<17){
            posa.y+=3;
            if(posa.y > ofGetHeight()){
                posa.y = 0;
        }
        }


        float timer = sin(ofGetElapsedTimef()*ofRandom(10));
        float alph = ofMap(timer,-1,1, 128, 0);
        ofColor c2(c1,alph);
        ofSetColor(c2);
        ofRect(posa.x, posa.y, 15,15);
        
        
    
    }
    
    if(explode == true){
        
        
        for(int i =0; i< num; i++){
        
            posb.x = posa.x+ radius*cos(angle + PI*2/num*i);
            posb.y = posa.y+ radius*-sin(angle + PI*2/num*i);
        
            myPct += speed;
            if(myPct>1)myPct = 1;
            pct = powf(myPct, 1);
            pos.x = (1-pct)*posa.x + pct* posb.x;
            pos.y = (1-pct)*posa.y + pct* posb.y;
        
            
            float alph = ofMap(pct,0,1, 255, 0);
            ofColor c2(c3,alph);
            ofSetColor(c2);
            
            ofRect(pos.x, pos.y, rectsize,rectsize);
        
        
            if(myPct>1)myPct = 0;
            pct = powf(myPct, shaper);
            pos.x = (1-pct)*posa.x + pct* posb.x;
            pos.y = (1-pct)*posa.y + pct* posb.y;

            ofRect(pos.x, pos.y, rectsize,rectsize);

        }
    }


	
}
