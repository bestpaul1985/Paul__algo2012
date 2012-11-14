#include "testApp.h"
#include "particle.h"

#include "ofMain.h"

// comparison routine for sort...
bool comparisonFunction(  particle * a, particle * b ) { 
	return a->pos.x < b->pos.x;
    
}              
      

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(30);
    
    //goal
    
    for (int i; i<3; i++) {
        ofImage img;
        img.loadImage("xiaoren"+ofToString(i)+".png");
        xiaoren.push_back(img);
    }
    
//    saver.loadImage("xiaoren.png");
    
    for (int i = 0; i < 30; i++){
        particle * p = new particle();
        goals.push_back(p);
        goals[i]->drawWhat =2;
        goals[i]->setInitialCondition(ofRandom(-ofGetWidth()*0.8,ofGetWidth()*2*0.8),ofRandom(-ofGetWidth()*0.8, ofGetWidth()*2)*0.8,0,0);
        goals[i]->vel.set(0,0);
        goals[i]->saver = & xiaoren[ofRandom(0,2)];
    }
    
    firstTime=ofGetElapsedTimeMillis();
    bStartTime = true;
    bWaitTowin = false;
    bGameStatus = false;
    
	//ship
    shipExplode=false;
    ship.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, 0, 0);
    ship.drawWhat = 1;
    ship.damping = 0.03f;
    shipImag.loadImage("ship001.png");
    shipImagFire.loadImage("fire.png");
    shipRadiance = 40;
    ship.img = &shipImag;
    ship.imgFire = &shipImagFire;
    //particles
    asteroid.loadImage("asteroid.png");
    for (int i = 0; i < 200; i++){
        
        float scale = ofRandom(1,3);
        particle * p = new particle();
        myParticles.push_back(p);
        myParticles[i]->pos.set(ofRandom(-ofGetWidth(),ofGetWidth()*2),ofRandom(-ofGetWidth(),ofGetWidth()*2));
        myParticles[i]->vel.set(0,0);
        myParticles[i]->asteroid =& asteroid;
        myParticles[i]->scale = scale;
    }
    shield=3;
    //bg
    backgroundImage.loadImage("universe.jpg");
    bgPos.set(0, 0);
    bgMusic.loadSound("backgroundMusic.mp3");
    bgMusic.setLoop(true);
    bgMusic.play();
    bgMusic.setVolume(1.5);
    //text
    verdana.loadFont("Visitor-TT1--BRK-.ttf", 15);
    verdana2.loadFont("Visitor-TT1--BRK-.ttf", 40);
    score = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofSoundUpdate();
    //SpaceShip
        
    if(shipMoveForward){
        shipForce+=0.001;
        if(shipForce>=0.05){
            shipForce=0.05;
        }
    }
    if(shipMoveBack){
        shipForce-=0.001;
        if(shipForce<=0.002){
            shipForce=-0.002;
        }
    }
    if (shipRotateLeft) {
        shipAngle+=3;
    }
    if (shipRotateRight) {
        shipAngle-=3;
    }
    
    shipFrcX= cos(ofDegToRad(shipAngle))*shipForce;
    shipFrcY= sin(ofDegToRad(shipAngle))*shipForce;
    ship.alpha = shipForce;
    ship.angle = shipAngle;
    ship.resetForce();
    ship.addForce(shipFrcX, shipFrcY);
    ship.addDampingForce();
    ship.moveOffWalls();
    ship.update();
    orginPos.x += ship.vel.x;
    orginPos.y += ship.vel.y;
    ship._posx = orginPos.x;
    ship._posy = orginPos.y;
    ship.bounceOffWalls();
	cout<<ship.vel<<endl;
    
    //Goal
    for (int i = 0; i < goals.size(); i++){
        goals[i]->resetForce();
        goals[i]->addForce(0, 0);
        goals[i]->addDampingForce();
        goals[i]->update();
        goals[i]->pos-=ship.vel*2;
        ofPoint terminal;
        terminal = goals[i]->pos-ship.pos;
        if (terminal.length()<30) {
            score+=1;
//            goals[i]->setInitialCondition(ofRandom(-ofGetWidth(),ofGetWidth()*2),ofRandom(-ofGetWidth(), ofGetWidth()*2),0,0);
            goals.erase(goals.begin()+i);
            shipRadiance+=10;
            if(shipRadiance>=300){
                shipRadiance=300;
            }
        }

    }
    
    
    
    //bg
    
    bgPos-=ship.vel/4;
    
    
    
	// particle
    
    sort( myParticles.begin(), myParticles.end(), comparisonFunction );               // sort them!
    
    
    for (int i = 0; i < myParticles.size(); i++){
        myParticles[i]->resetForce();
        myParticles[i]->radius = shipRadiance;
    }
    
    
	for (int i = 0; i < myParticles.size(); i++){
		for (int j = i-1; j >= 0; j--){
			if ( fabs(myParticles[j]->pos.x - myParticles[i]->pos.x) >  30) break;
            float speed;
            speed = ofMap(myParticles[i]->scale, 0, myParticles[i]->scale+myParticles[j]->scale, 0, 2.4f);
			myParticles[i]->addRepulsionForce( *myParticles[j],20,speed);
		}
    }
	
    
       
    for (int i = 0; i < myParticles.size(); i++){
        for (int j = 0; j < goals.size(); j++){
    
            myParticles[i]->addRepulsionForce(goals[j]->pos.x,goals[j]->pos.y,70,0.02f);
       
        }
    }
    
    float diffTime2 = ofGetElapsedTimeMillis()- firstTime;
    
    for (int i = 0; i < myParticles.size(); i++){
        myParticles[i]->addForce(0,0);
        myParticles[i]->addAttractionForce(ship.pos.x,ship.pos.y,shipRadiance*myParticles[i]->scale,0.02f/myParticles[i]->scale);
        if (diffTime2<1000) {
            myParticles[i]->addRepulsionForce(ship.pos.x, ship.pos.y, 200, 0.2f);
        }
        
        myParticles[i]->addDampingForce();
        myParticles[i]->update();
        myParticles[i]->pos.x-=ship.vel.x*2;
        myParticles[i]->pos.y-=ship.vel.y*2;

        ofPoint dis;
        dis = ship.pos - myParticles[i]->pos;
        if (dis.length()<23+(myParticles[i]->asteroid->width/6*myParticles[i]->scale)) {
            
            
            orginPos.set(0, 0);
            shipExplode = true;
            ship.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, 0, 0);
            firstTime = ofGetElapsedTimeMillis();
            score =0;
            shipRadiance = 30;
            myParticles.clear();
            for (int i = 0; i < 200; i++){
                
                float scale = ofRandom(1,3);
                particle * p = new particle();
                myParticles.push_back(p);
                myParticles[i]->pos.set(ofRandom(-ofGetWidth(),ofGetWidth()*2),ofRandom(-ofGetWidth(),ofGetWidth()*2));
                myParticles[i]->vel.set(0,0);
                myParticles[i]->asteroid =& asteroid;
                myParticles[i]->scale = scale;
            }
            goals.clear();
            for (int i = 0; i < 30; i++){
                particle * p = new particle();
                goals.push_back(p);
                goals[i]->drawWhat =2;
                goals[i]->setInitialCondition(ofRandom(-ofGetWidth()*0.8,ofGetWidth()*2*0.8),ofRandom(-ofGetWidth()*0.8, ofGetWidth()*2)*0.8,0,0);
                goals[i]->vel.set(0,0);
                goals[i]->saver = & xiaoren[ofRandom(0,2)];
            }
            
            bgPos.set(0, 0);
            shield =3;
            }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //bg
    

	ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    backgroundImage.draw(bgPos.x+400,bgPos.y+370);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    //myParticles
    for (int i = 0; i < myParticles.size(); i++){
        ofFill();
        ofEnableAlphaBlending();
        ofSetColor(255, 220, 0, 10);
        ofCircle(myParticles[i]->pos,myParticles[i]->radius*myParticles[i]->scale);
        ofDisableAlphaBlending();
    }
    
    for (int i = 0; i < myParticles.size(); i++){
		 myParticles[i]->draw();
            
	 }
   
    //ship
    
    
    float diffTime2 = ofGetElapsedTimeMillis()- firstTime;
    if(diffTime2<1000) {
        float buleAlpha = ofMap(diffTime2, 0, 1000, 0, 100);
        ofEnableAlphaBlending();
        ofSetColor(0, 100, 200,100-buleAlpha);
        ofCircle(ship.pos.x, ship.pos.y,100);
        ofDisableAlphaBlending();
    }
    
    ship.draw();

    //goals
    for (int i = 0; i < goals.size(); i++){
        goals[i]->draw();
    }
    
    //score
    if (score>29) {
        ofSetColor(255, 255, 255);
        verdana2.drawString("VICTORY", ofGetWidth()/2-120, ofGetHeight()/2);
    }
    ofSetColor(225);
	verdana.drawString("Survivor: "+ofToString(30-score), 30, 35);
    verdana.drawString("Shield: "+ofToString(shield), 500, 35);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if (key=='w'||key=='W'||key==OF_KEY_UP) {
        
        shipMoveForward = true;
    }else if(key=='s'||key=='S'||key==OF_KEY_DOWN){
        
        shipMoveBack = true;
    }else if(key=='a'||key=='A'||key==OF_KEY_LEFT){
        
        shipRotateLeft =true;
    }else if(key=='d'||key=='D'||key==OF_KEY_RIGHT){
        
        shipRotateRight = true;
    }else if(key==' '){
    
        if (shield>0) {
            firstTime=ofGetElapsedTimeMillis();
            shield-=1;
        }
    }

}
//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    
    if (key=='w'||key=='W'||key==OF_KEY_UP) {

        shipMoveForward = false;
        shipForce = 0;
    }else if(key=='s'||key=='S'||key==OF_KEY_DOWN){
         
        shipMoveBack = false;
        shipForce = 0;
    }else if(key=='a'||key=='A'||key==OF_KEY_LEFT){
         
        shipRotateLeft =false;
    }else if(key=='d'||key=='D'||key==OF_KEY_RIGHT){
         
        shipRotateRight = false;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
}
