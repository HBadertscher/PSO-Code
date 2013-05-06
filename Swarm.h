//
//  Swarm.h
//  PSO-Code
//
//  Created by Hannes Badertscher on 19.03.13.
//  Licensed under CC-BY-NC-SA
//

#ifndef __PSO_Code__Swarm__
#define __PSO_Code__Swarm__

#include "Position.h"
#include "Particle.h"

class Swarm {
public:
    Swarm(int NumberOfParticles, int Iterations);
    ~Swarm();
    void executeSwarm(void);
    
private:
    int NumOfIterations;
    int NumOfParticles;
    
    Particle* particleSwarm;
    Position pGlobalBest;
    double fGlobalBest;
};


#endif /* defined(__PSO_Code__Swarm__) */
