#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"

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

		vector <particle *> myParticles;
        vector<particle *> goals;
        ofPoint orginPos;
        particle ship;
        particle goal;
        ofImage backgroundImage;
        ofImage saver;
        ofImage asteroid;
        ofImage shipImag;
        ofImage shipImagFire;
        ofPoint bgPos;
        float lastTime;
        float firstTime;
        bool bStartTime;
        bool bWaitTowin;
        bool bGameStatus;
        float shipForce;
        float shipAngle;
        float shipPct;
        bool shipMoveForward;
        bool shipMoveBack;
        bool shipRotateLeft;
        bool shipRotateRight;
        bool shipExplode;
        float shipFrcX;
        float shipFrcY;
        int score;
        float shipRadiance;
        ofTrueTypeFont verdana;
        ofTrueTypeFont verdana2;
        ofSoundPlayer bgMusic;
        int shield;
    
    
};

#endif

