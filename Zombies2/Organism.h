#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include "GameSpecs.h"
#include "City.h"

using namespace std;

class Organism
{
    friend class City;
public:
    Organism();
    Organism(City *city, int x, int y);
    ~Organism();
    virtual void breed() = 0;
    virtual void move();
    virtual bool validMove(int xPos, int yPos);
    virtual int getType() = 0;       // Return 1 if human or 0 for zombie
    virtual bool starve() = 0;
protected:
    int x,y;
    bool moved;
    int breedTicks;
    City *city;
};

#endif
