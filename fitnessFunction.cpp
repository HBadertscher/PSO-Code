#ifndef __fitnessFunction_CPP
#define __fitnessFunction_CPP

#include "Position.h"
#include <math.h>

double fitnessFunction(Position* curPos) {
    double x = curPos->getDim(0);
    double y = curPos->getDim(1);
	
	// Ackley's Function
    return -20*exp(-0.2*sqrt(0.5*(x*x+y*y))) - exp(0.5*(cos(2*M_PI*x)+cos(2*M_PI*y)))+20+exp(1);
}

#endif