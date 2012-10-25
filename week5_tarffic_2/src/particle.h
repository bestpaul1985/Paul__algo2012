#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        ofPoint prevPos;
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy, float damp);
        void update();
        void draw();
	
		void bounceOffWalls();
	
	
		float damping;
    float angle;

    protected:
    private:
    ofImage car;
};

#endif // PARTICLE_H
