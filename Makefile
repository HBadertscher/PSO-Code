#----------------------------------------------------------------------------------------
# Makefile for ParticleSwarmOptimization

CXX=g++
CC=gcc
CXXFLAGS=-c
CFLAGS=-c
RM=rm -f

SRCS=main.cpp Random.cpp Position.cpp Particle.cpp Swarm.cpp fitnessFunction.cpp
DEPS=Random.h Position.h Particle.h Swarm.h
OBJS=$(subst .cpp,.o,$(SRCS))
EXECUTABLE=ParticleSwarm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXECUTABLE)

%.o: %.c $(DEPS)
	$(CXX) ($CXXFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)