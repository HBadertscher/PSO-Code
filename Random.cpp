//
//  Random.cpp
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#include "Random.h"
#include <stdlib.h>
#if defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0
#include<time.h>
#else
#include<sys/time.h>
#endif

double getRand(double min, double max) {
    
    struct timespec ts;
    #if defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0
        clock_gettime(CLOCK_REALTIME, &ts);
    #else
        struct timeval tv;
        gettimeofday(&tv, NULL);
        ts.tv_sec = tv.tv_sec;
        ts.tv_nsec = tv.tv_usec * 1000;
    #endif
        srandom((int)ts.tv_nsec);
    
    
    double delta = max - min;
    double j = rand() * delta / RAND_MAX + min;
    return j;
}
