#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw(ofColor pColor);
        void timer(float _time, float _posx, float _posy, float _radius, float _angle);
        void bounceOffWalls();
    
	
	
		float damping;
        float startTime;
        bool fire;
        bool colorOpen;
    float pct;

        protected:
        private:
};

#endif // PARTICLE_H
