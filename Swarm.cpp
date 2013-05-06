//
//  Swarm.cpp
//  PSO-Code
//
//  Created by Hannes Badertscher on 19.03.13.
//  Licensed under CC-BY-NC-SA
//

#include "Swarm.h"
#include <float.h>
#include <iostream>
using std::cout;
using std::endl;

Swarm::Swarm(int NumberOfParticles, int Iterations) : 
    NumOfParticles(NumberOfParticles), NumOfIterations(Iterations){
    fGlobalBest = DBL_MAX;
    particleSwarm = new Particle[NumberOfParticles];
    
    // Find Global Best
    for(int j=0; j<NumberOfParticles; j++) {
        if(particleSwarm[j].calcFitness() < fGlobalBest) {
            fGlobalBest = particleSwarm[j].getFitness();
            pGlobalBest = particleSwarm[j].getPosition();
        }
    }
    
    // Write to File   
    FILE *pFile = fopen("PSO-Data.txt", "a+");
    fprintf(pFile, "\n");
    fclose(pFile);
}

Swarm::~Swarm() {
    delete[] particleSwarm;
}

void Swarm::executeSwarm(void) {
    for(int i=0; i<NumOfIterations; i++) {
        
        // Calculate new Position and Velocity
        for(int j=0; j<NumOfParticles; j++) {
            particleSwarm[j].newVelocity(pGlobalBest);
            particleSwarm[j].newPosition();
        }
        
        // Calculate Fitness
        for(int j=0; j<NumOfParticles; j++) {
            if(particleSwarm[j].calcFitness() < fGlobalBest) {
                fGlobalBest = particleSwarm[j].getFitness();
                pGlobalBest = particleSwarm[j].getPosition();
            }
        }
        
        // Print
        for(int j=0; j<NumOfParticles; j++) {
            particleSwarm[j].printParticle();
        }
        FILE *pFile = fopen("PSO-Data.txt", "a+");
        fprintf(pFile, "\n");
        fclose(pFile);
    }
}