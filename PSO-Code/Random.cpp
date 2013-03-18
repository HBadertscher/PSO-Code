//
//  Random.cpp
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#include "Random.h"
#include <stdlib.h>

double getRand(double min, double max) {
    double delta = max - min;
    double j = rand() * delta / RAND_MAX + min;
    return j;
}
