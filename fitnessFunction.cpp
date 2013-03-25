#ifndef __fitnessFunction_CPP
#define __fitnessFunction_CPP

#include "Position.h"
#include <math.h>

double fitnessFunction(Position* curPos) {
    return pow(curPos->getDim(0),2) + pow(curPos->getDim(1),2);
}

#endif