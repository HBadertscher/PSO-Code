//
//  Particle.h
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#ifndef PSO_Test_Particle_h
#define PSO_Test_Particle_h

#include "Position.h"

const double InertWeight = 0.721;
const double CogFactor = 1.193;
const double SocFactor = 1.193;

#define InitMin -100
#define InitMax 100

class Particle {
    
private:
    Position pCurrent;    // Current Position
    Position vCurrent;    // Current Velocity
    double fCurrent;      // Current Fitness
    
    Position pPersBest;   // Personal best Position
    double fPersBest;     // Personal best Fitness
    
public:
    Particle();
    
    double getFitness() const;
    Position getPosition() const;
    
    void newVelocity(Position pGlobalBest);  // Calculate new Velocity
    void newPosition(void);
    double calcFitness();     // Calculate Fitness Function
    
    void printParticle() const;
};


#endif
