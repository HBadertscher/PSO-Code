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
#include "Swarm.h"

using namespace std;


int main(int argc, const char * argv[])
{
    const int NumberOfParticles = 5;
    const int Iterations = 100;
    
    Swarm mySwarm(NumberOfParticles, Iterations);
    mySwarm.executeSwarm();

    return 0;
}

