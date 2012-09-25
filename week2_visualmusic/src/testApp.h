#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "explosion.h"
#include "hero.h"
#include "fireworks2.h"

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

		explosion myExplosion[1000];
        explosion background[100];
        explosion randomexplosion[100];
        explosion finalfire[150];
        hero myHero;
    
        hero npc1;
    
        fireworks2 myfireworks2;
        ofSoundPlayer  sound;
    
        ofTrueTypeFont  verdana;

    
};

#endif

