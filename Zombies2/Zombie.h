#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism {

public:
    Zombie();

    Zombie(City *city, int x, int y);

    virtual void breed();

    virtual void move();

    virtual int getType();

    virtual bool starve();

private:
    int starvation;
};

#endif
