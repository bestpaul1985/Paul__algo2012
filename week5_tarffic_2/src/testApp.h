#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"
#include "road.h"
class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		// let's make a vector of them
		vector <particle> particles;
        road myRoad;
		vectorField VF;
        
		int drawingStyle;
        int direction;
		bool bFade,bVf;
        int prevMouseX;
        int prevMouseY;
        float dis;
    
    ofImage backgroundImage;
};

#endif
	
