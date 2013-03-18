//
//  Particle.cpp
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#include "Particle.h"
#include "Random.h"
#include <math.h>
#include <float.h>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

Particle::Particle() {
    for(int i=0; i<PosDimension; i++) {        // Init every Dimension with a Random Value
        pCurrent.setDim(getRand(InitMin, InitMax),i);
        vCurrent.setDim((getRand(InitMin, InitMax) - pCurrent.getDim(i))/2,i);
    }
    pPersBest = pCurrent;
    fPersBest = DBL_MAX;
    this->calcFitness(); 
    this->printParticle();
}

Position Particle::getPosition() const {
    return pCurrent;
}

double Particle::getFitness(void) const {
    return fCurrent;
}

double Particle::calcFitness(void) {
    fCurrent = pow(pCurrent.getDim(0),2);    // Fitness Function: x^2
    if(fCurrent < fPersBest) {
        fPersBest = fCurrent;
        pPersBest = pCurrent;
    }
    return fCurrent;
}

void Particle::newPosition(void) {
    pCurrent = pCurrent + vCurrent;
    return;
}

void Particle::newVelocity(Position pSocBest) {
    // Cognitive Component
    Position cognitive =  pPersBest - pCurrent;
    cognitive = cognitive * CogFactor;
    
    // Social Component
    Position social = pSocBest - pCurrent;
    social = social * SocFactor;

    // Inertial Component
    Position inertia = vCurrent * InertWeight;
    
    // Add Components
    vCurrent = inertia + cognitive + social;
    
    return;
}

void Particle::printParticle() const {
    cout << "Particle: Pos(";
    for(int i=0; i<PosDimension; i++) {
        cout << pCurrent.getDim(i) << " ; ";
    }
    cout << ") / Vel(";
    for(int i=0; i<PosDimension; i++) {
        cout << vCurrent.getDim(i) << " ; ";
    }
    cout << ") / Fit(" << fCurrent << ")" << endl;
}