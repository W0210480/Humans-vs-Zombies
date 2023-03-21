#ifndef _Human_H
#define _Human_H

#include "GameSpecs.h"
#include "City.h"

class Human : public Organism
{
public:
    Human();
    Human(City *city, int x, int y);
    virtual ~Human();
    virtual void breed(); // breed is recruit
    virtual int getType();
    virtual bool starve();
};

#endif
