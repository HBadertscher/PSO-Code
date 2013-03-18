//
//  main.cpp
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#include <iostream>
#include <float.h>
#include "Particle.h"
#include "Position.h"

using namespace std;

#define NumberOfParticles 5
#define Interations 1000

int main(int argc, const char * argv[])
{
    Position pGlobalBest;
    double fGlobalBest = DBL_MAX;
    
    
    cout << "Initialise:" << endl;
    Particle* swarm = new Particle[NumberOfParticles];  // Init is done automatically by Constructor
    
    //----------------------------------------------------------------------------------
    // Initialise
    for(int j=0; j<NumberOfParticles; j++) {            // Set initial Values for Global Best
        if(swarm[j].calcFitness() < fGlobalBest) {
            fGlobalBest = swarm[j].getFitness();
            pGlobalBest = swarm[j].getPosition();
        }
    }
    cout << "Global Best: " << fGlobalBest << endl << endl;
   
    //----------------------------------------------------------------------------------
    // Iterate
    for(int i=0; i<Interations; i++) {
        cout << "Iteration #" << i << ":" << endl;
        
        // Calculate new Position and Velocity
        for(int j=0; j<NumberOfParticles; j++) {
            swarm[j].newVelocity(pGlobalBest);
            swarm[j].newPosition();
        }
        
        
        // Calculate Fitness
        for(int j=0; j<NumberOfParticles; j++) {
            if(swarm[j].calcFitness() < fGlobalBest) {
                fGlobalBest = swarm[j].getFitness();
                pGlobalBest = swarm[j].getPosition();
            }
        }
        
        // Print
        for(int j=0; j<NumberOfParticles; j++) {
            swarm[j].printParticle();
        }
        cout << "Global Best: " << fGlobalBest << endl << endl;
    }
    
    //----------------------------------------------------------------------------------
    // End!
    cout << "End!!!" << endl;
    delete[] swarm;
}

