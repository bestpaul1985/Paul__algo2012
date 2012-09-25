#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    posa.x = 10;
    posa.y = 10;
    posb.x = 800;
    posb.y = 100;
    speed = 0.01f;
    pct = 0;
    
    ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
   
    
    
   
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    
    if (pct>1) {
        speed*=-1;
    }else if (pct<0){
        speed*=-1;
    }
    
    pct +=speed;
    
    pos.x = (1-pct)*posa.x+pct*posb.x;
    pos.y = (1-pct)*posa.y+pct*posb.y;
    
    
    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
  
    float var_modulator = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
    float var1 = ofMap(pos.y,0,100,0,120);
    float var2 = ofMap(pos.x,0,800,0,220);
    float var4 = ofMap(pos.x*var_modulator,0,800,50,255);
    float var3 = ofMap(pos.x,0,800,1,5);
    
    color_1.r = var2;
    color_1.g = var1;
    color_1.b = var4;
    
    color_2.r = var1;
    color_2.g = var2;
    color_2.b = var4;
    
    
    
    int num = 10;
    
    for (int i=0; i<num; i++) {
        
       
    
        
        float modulator = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 1);
        float xorig = ofGetWidth()/2;
        float yorig = ofGetHeight()/2;
        float radius = pos.x * modulator;
        float angle = ofGetElapsedTimef();
        float x = xorig + radius * cos(angle+(PI*2/num*i));
        float y = yorig + radius * -sin(angle+(PI*2/num*i));
        ofSetColor(color_1);        
        ofCircle(x,y,10);
        
        int lv2_num = 50;
        for(int k =0; k < lv2_num; k++){
            
        float lv2_modulator = ofMap(-sin(ofGetElapsedTimef()), -1, 1, 0.9, 1);
        float lv2_radius = 50;
        float lv2_x = x + lv2_radius * cos(angle+(PI*2/lv2_num*k));
        float lv2_y = y + lv2_radius * -sin(angle+(PI*2/lv2_num*k));
        ofSetColor(color_2);
        ofCircle(lv2_x,lv2_y, 1);
            
            int lv3_num = 50;
            for(int j =0; j < lv3_num; j++){
                
                float lv3_modulator = ofMap(-sin(ofGetElapsedTimef()), -1, 1, 0.9, 1);
                float lv3_radius = 50;
                float lv3_x = lv2_x + lv3_radius * cos(angle+(PI*2/lv2_num*j));
                float lv3_y = lv2_y + lv3_radius * -sin(angle+(PI*2/lv2_num*j));
                
                ofCircle(lv3_x,lv3_y, 1);
            }
            
        }
        
        
        
        int lv4_num = 50;
        for(int h =0; h < lv4_num; h++){
            
            float lv4_modulator = ofMap(-sin(ofGetElapsedTimef())*0.1, -1, 1, 0, 1);
            float lv4_radius = 300*lv4_modulator;
            float lv4_x = xorig + lv4_radius * cos(angle+(PI*2/lv4_num*h));
            float lv4_y = yorig + lv4_radius * -sin(angle+(PI*2/lv4_num*h))*lv4_modulator;
            
            ofCircle(lv4_x,lv4_y, 1);
            
            int lv5_num = 30;
            for(int g =0; g < lv5_num; g++){
                
                float lv5_modulator = ofMap(-sin(ofGetElapsedTimef())*5, -1, 1, 0, 1);
                float lv5_radius = pos.y;
                float lv5_x = lv4_x + lv5_radius * cos(angle+(PI*2/lv5_num*g));
                float lv5_y = lv4_y + lv5_radius * -sin(angle+(PI*2/lv5_num*g))*lv5_modulator;
                
                ofCircle(lv5_x,lv5_y, 1);
            }
        }
        
        
        
        int lv6_num = 40;
        for(int f =0; f < lv6_num; f++){
            
            float lv6_modulator = ofMap(-sin(ofGetElapsedTimef())*10, -1, 1, 0.3, 1);
            float lv6_radius = 300;
            float lv6_x = x+10*f + lv6_radius * cos(angle+(PI*2/lv6_num*f*lv6_modulator));
            float lv6_y = y+10*f + lv6_radius * -sin(angle+(PI*2/lv6_num*f*lv6_modulator));
            
            ofCircle(lv6_x,lv6_y, 1);
        }
        
        
        
        int lv7_num = 40;
        for(int d =0; d < lv7_num; d++){
            
            float lv7_modulator = ofMap(-sin(ofGetElapsedTimef())*10, -1, 1, 0.3, 1);
            float lv7_radius = 300;
            float lv7_x = x-10*d + lv7_radius * cos(angle+(PI*2/lv7_num*d*lv7_modulator));
            float lv7_y = y-10*d + lv7_radius * -sin(angle+(PI*2/lv7_num*d*lv7_modulator));
            
            ofCircle(lv7_x,lv7_y, 1);
        }
        
        int lv8_num = 40;
        for(int s =0; s < lv7_num; s++){
            
            float lv8_modulator = ofMap(-sin(ofGetElapsedTimef())*10, -1, 1, 0.3, 1);
            float lv8_radius = 300;
            float lv8_x = x-10*s + lv8_radius * cos(angle+(PI*2/lv8_num*s*lv8_modulator));
            float lv8_y = y + lv8_radius * -sin(angle+(PI*2/lv8_num*s*lv8_modulator));
            
            ofCircle(lv8_x,lv8_y, 1);
        }
        
        int lv9_num = 40;
        for(int a =0; a < lv7_num; a++){
            
            float lv9_modulator = ofMap(-sin(ofGetElapsedTimef())*10, -1, 1, 0.3, 1);
            float lv9_radius = 300;
            float lv9_x = x+10*a + lv9_radius * cos(angle+(PI*2/lv9_num*a*lv9_modulator));
            float lv9_y = y-10*a + lv9_radius * -sin(angle+(PI*2/lv9_num*a*lv9_modulator));
            
            ofCircle(lv9_x,lv9_y, 1);
        }
        
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