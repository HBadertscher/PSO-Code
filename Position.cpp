//
//  Position.cpp
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Licensed under CC-BY-NC-SA
//

#include "Position.h"
#include <math.h>

Position::Position() {
    
}

Position::Position(double* initPos) {
    for(int i=0; i<PosDimension; i++) {
        pos[i] = initPos[i];
    }
}

Position::Position(Position* initPos) {
    for(int i=0; i<PosDimension; i++) {
        pos[i] = initPos->getDim(i);
    }
}

double Position::getDim(int dimension) const {
    return pos[dimension];
}

void Position::setDim(double value, int dimension) {
    pos[dimension] = value;
}


Position& Position::operator= (Position pos1) {
    Position Buffer;
    for(int i=0; i<PosDimension; i++) {
        pos[i] = pos1.pos[i];
    }
    return *this;
}

Position Position::operator+ (Position pos1) const  {
    Position Buffer;
    for(int i=0; i<PosDimension; i++) {
        Buffer.pos[i] = pos[i] + pos1.pos[i];
    }
    return Buffer;
}

Position Position::operator- (Position pos1) const {
    Position Buffer;
    for(int i=0; i<PosDimension; i++) {
        Buffer.pos[i] = pos[i] - pos1.pos[i];
    }
    return Buffer;
}

Position Position::operator* (double n) const {
    Position Buffer;
    for(int i=0; i<PosDimension; i++) {
        Buffer.pos[i] = pos[i] * n;
    }
    return Buffer;
}

double Position::skaP (Position pos1) const {
    double buf = 0;
    for (int i=0; i<PosDimension; i++) {
        buf += (pos[i] * pos1.pos[i]);
    }
    return buf;
}

double Position::abs() const {
    return sqrt(this->skaP(*this));
}

