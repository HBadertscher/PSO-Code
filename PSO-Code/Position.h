//
//  Position.h
//  PSO-Test
//
//  Created by Hannes Badertscher on 28.02.13.
//  Copyright (c) 2013 Hannes Badertscher. All rights reserved.
//

#ifndef PSO_Test_Position_h
#define PSO_Test_Position_h


enum {
    PosDimension = 1
};


class Position {
    
public:
    Position();
    Position(double* initPos);
    Position(Position* initPos);
    Position& operator= (Position pos1);
    Position operator+ (Position pos1) const;
    Position operator- (Position pos1) const;
    Position operator* (double n) const;
    double skaP (Position pos1) const;
    double abs(void) const;
    
    void setDim(double value, int dimension);
    double getDim(int dimension) const;
    
private:
    double pos[PosDimension];
    
};


#endif
