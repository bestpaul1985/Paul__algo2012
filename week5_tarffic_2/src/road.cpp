//
//  road.cpp
//  vectorField_wParticles
//
//  Created by PengCheng on 10/22/12.
//
//

#include "road.h"

road::road(){
    
    prevPos.set(0, 0);
    w1= 0;
    w2=7.5;

}

void road::setup(){
    
   
}

void road::update(){

}

void road::draw(){
    
//    tempStroke.draw();
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    vector < ofPoint > tempPts = tempStroke.getVertices();
    
    for (int i = 0; i < tempPts.size(); i++){
        
        int i_m_1 = MAX(i-1,0);
        int i_p_1 = MIN(i+1, tempPts.size()-1);
        
        ofPoint pta = tempPts[i_m_1];
        ofPoint ptb = tempPts[i];
        ofPoint ptc = tempPts[i_p_1];
        
        ofPoint diff = ptc - pta;
        
        float angle = atan2(diff.y, diff.x);
        
        angle += PI/2;
        float width = 30; //diff.length();
        float width2 = 5;
        
        ofPoint offsetA;
        offsetA.x = ptb.x + width * cos(angle);
        offsetA.y = ptb.y + width * sin(angle);
        
        ofPoint offsetB;
        offsetB.x = ptb.x - width * cos(angle);
        offsetB.y = ptb.y - width * sin(angle);
        
//        ofLine(offsetA, offsetB);
        
        ofPoint offsetC;
        offsetC.x = ptb.x + width2 * cos(angle+PI/4);
        offsetC.y = ptb.y + width2 * sin(angle+PI/4);
        ofSetColor(255, 209, 9);
        ofLine(offsetC, ptb);
        
        ofPoint offsetD;
        offsetD.x = ptb.x - width2 * cos(angle-PI/4);
        offsetD.y = ptb.y - width2 * sin(angle-PI/4);
        ofSetColor(255, 209, 9);
        ofLine(offsetD, ptb);
        
        //ofColor col;
        //col.setHsb(ofMap(angle, -PI/2, 3*PI/2, 0,255, true), 100,255, ofMap(angle, -PI/2, 3*PI/2, 0,255, true));
        //mesh.addColor(col);
        tempMesh.addVertex(offsetA);
        //mesh.addColor(col);
        tempMesh.addVertex(offsetB);
    }
    
    // draw the mesh
    ofEnableAlphaBlending();
    ofSetColor(52,52,52,150);
    ofFill();
    tempMesh.draw();






//    ofSetColor(255,255,255);
//    for (int i =0; i<stroke.size(); i++) {
//         stroke[i].draw();
//    }
    
   
    
    for (int i =0; i<stroke.size(); i++) {
        
        
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vector < ofPoint > pts = stroke[i].getVertices();
    
        for (int i = 0; i < pts.size(); i++){
        
            int i_m_1 = MAX(i-1,0);
            int i_p_1 = MIN(i+1, pts.size()-1);
            
            ofPoint pta = pts[i_m_1];
            ofPoint ptb = pts[i];
            ofPoint ptc = pts[i_p_1];
            
            ofPoint diff = ptc - pta;
            
            float angle = atan2(diff.y, diff.x);
            
            angle += PI/2;
            
            float width = 30; //diff.length();
            ofPoint offsetA;
            offsetA.x = ptb.x + width * cos(angle);
            offsetA.y = ptb.y + width * sin(angle);
            
            ofPoint offsetB;
            offsetB.x = ptb.x - width * cos(angle);
            offsetB.y = ptb.y - width * sin(angle);
            
//          ofLine(offsetA, offsetB);

            mesh.addVertex(offsetA);
            //mesh.addColor(col);
            mesh.addVertex(offsetB);
        }
    
        // draw the mesh
        ofEnableAlphaBlending();
        ofSetColor(52,52,52);
        ofFill();
        mesh.draw();
        float alpha;
        for (int i = 0; i < pts.size(); i++){
            
            
           
            int i_m_1 = MAX(i-1,0);
            int i_p_1 = MIN(i+1, pts.size()-1);
            
            ofPoint pta = pts[i_m_1];
            ofPoint ptb = pts[i];
            ofPoint ptc = pts[i_p_1];
            
            ofPoint diff = ptc - pta;
        
            float angle = atan2(diff.y, diff.x);
            angle += PI/2;
            float width2 = 5;
            ofPoint offsetC;
            offsetC.x = ptb.x + width2 * cos(angle+PI/4);
            offsetC.y = ptb.y + width2 * sin(angle+PI/4);
            
            ofSetColor(255, 209, 9);
            ofLine(offsetC, ptb);
            
            ofPoint offsetD;
            offsetD.x = ptb.x - width2 * cos(angle-PI/4);
            offsetD.y = ptb.y - width2 * sin(angle-PI/4);
            
            ofSetColor(255, 209, 9 );
            ofLine(offsetD, ptb);
        
        }

    }
    

        

}

void road::mouseDragged(int x, int y){
        
    pos.set(x,y);
    angle = atan2(x, y);
    
    
    ofPoint prevPt = tempStroke.getVertices()[tempStroke.getVertices().size()-1];
    
    float distance = (prevPt - ofPoint(x,y)).length();
    
    if (distance > 10){
        tempStroke.addVertex(x,y);
    }
    
}


void road::mousePressed(int x, int y){
    
    tempStroke.addVertex(x,y);
}

void road::mouseReleased(){
    
    stroke.push_back(tempStroke);
    tempStroke.clear();
    
}