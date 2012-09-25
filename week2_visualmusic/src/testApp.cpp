#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    verdana.loadFont("verdana.ttf", 30, true, true);
    
	sound.loadSound("enthsiastsmall.mp3");
    sound.setVolume(0.9f);
	ofSetVerticalSync(true);
	sound.play();
	
	ofBackground(30,30,30);
	ofEnableAlphaBlending();
	
    //start fireworks
    for(int i =0; i < 1000; i++){
        
        float posx = ofMap(ofRandom(0,100),0,100,10,1014);
        float posy = ofMap(ofRandom(0,100),0,100,10,758);
        myExplosion[i].posa.x = posx;
        myExplosion[i].posa.y = posy;
        myExplosion[i].current = ofGetElapsedTimef() + ofRandom(0,4);
        myExplosion[i].speed = ofRandom(0.0002f,0.0005f);
        myExplosion[i].c1.set(ofRandom(255),ofRandom(255),ofRandom(255));
        myExplosion[i].c3.set(ofRandom(255),ofRandom(255),ofRandom(255));
    }
    
    //background rectangles
    for(int i =0; i < 100; i++){
        float posx = ofMap(ofRandom(0,100),0,100,10,1014);
        float posy = ofMap(ofRandom(0,100),0,100,10,758);
        background[i].posa.x = posx;
        background[i].posa.y = posy;
        background[i].current = ofRandom(2000,3000);
        background[i].speed = ofRandom(0.001f,0.002f);
        
        
    }
    
    //background random fireworks
    for(int i =0; i < 100; i++){
        float posx = ofMap(ofRandom(0,100),0,100,10,1014);
        float posy = ofMap(ofRandom(0,100),0,100,10,758);
        randomexplosion[i].posa.x = posx;
        randomexplosion[i].posa.y = posy;
        randomexplosion[i].current = ofRandom(15,100);
        randomexplosion[i].speed = ofRandom(0.001f,0.002f);
        randomexplosion[i].shaper = 0.1;
        randomexplosion[i].radius = 200;
        randomexplosion[i].rectsize =15;
    }
    //final fireworks
    for(int i =0; i < 150; i++){
        
        float posx = ofMap(ofRandom(0,100),0,100,10,1014);
        float posy = ofMap(ofRandom(0,100),0,100,10,758);
        finalfire[i].posa.x = posx;
        finalfire[i].posa.y = posy;
        finalfire[i].current = ofGetElapsedTimef() + float(ofRandom(34,43));
        finalfire[i].speed = ofRandom(0.001f,0.005f);
        finalfire[i].shaper = 0.1;
        finalfire[i].radius = ofRandom(200,400);
        finalfire[i].rectsize =ofRandom(15,25);
        finalfire[i].c3.set(ofRandom(255),ofRandom(255),ofRandom(255));

        
    }
    //fireworks2
    
        
//        myfireworks2.origpos.set(ofGetWidth()-100,ofRandom(0,ofGetHeight()));
    
    //hero
    myHero.timeup= 10;
    
    
    
	
}

//--------------------------------------------------------------
void testApp::update(){
    
   
    
     ofSoundUpdate();
    
    
    
    
    for(int i =0; i < 1000; i++){

        myExplosion[i].update();
    
    }
    
    for(int i =0; i < 100; i++){
    
        background[i].update();
        
    }
    
    for(int i =0; i < 100; i++){
        
        randomexplosion[i].update();
        
    }
    
    for(int i =0; i < 150; i++){
        
        finalfire[i].update();
        
    }
    
    
    myfireworks2.update();
    
    myHero.update();
    npc1.update();
    
    
    
    
}



//--------------------------------------------------------------
void testApp::draw(){
    
    
    for(int i =0; i < 1000; i++){
        
        myExplosion[i].draw();
    
    }
    
    for(int i =0; i < 100; i++){
        
        background[i].draw();
        
    }
    
    for(int i =0; i < 100; i++){
        
        randomexplosion[i].draw();
        
    }
    
    for(int i =0; i < 150; i++){
        
        finalfire[i].draw();
        
    }
    
    
    
    
    myHero.draw();
    npc1.draw();
    
    if(ofGetElapsedTimef()>47){
        sound.stop();
        ofSetColor(10);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRect(ofGetWidth()/2,ofGetHeight()/2,ofGetWidth(),ofGetHeight());
        ofSetColor(30,120,255);
        verdana.drawString("Music:  'Enthusiast' --- Tours", 190, 364);
        verdana.drawString("Animation: 'Fireworks' --- Paul", 170, 430);

    }
    
    cout<<ofGetElapsedTimef()<<" "<<endl;
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
	// in class we looked at this -- click = new position
	//myRectangle.pos.x = ofRandom(0,ofGetWidth());
	//myRectangle.pos.y =  ofRandom(0,ofGetHeight());
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
