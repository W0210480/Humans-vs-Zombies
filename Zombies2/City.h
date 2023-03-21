#ifndef _CITY_H
#define _CITY_H

#include "Organism.h"
#include "GameSpecs.h"


using namespace std;

class City
{
    friend class Organism;
    friend class Zombie;
    friend class Human;
public:
    City();
    virtual ~City();
    Organism* getOrg(int x, int y);
    void setOrg(int x, int y, Organism *org);
    void Display();
    void MoveStep();

private:
    Organism* grid[GRIDSIZE][GRIDSIZE];
};

#endif

