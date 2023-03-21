//
// Created by RyanG on 2022-12-09.
//

#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Zombie.h"



Zombie::Zombie() : Organism()
{
    starvation = 0;
}

Zombie::Zombie(City *city, int x, int y) : Organism(city, x, y)
{
    starvation = 0;
}

int Zombie::getType()
{
    return ZOMBIE;
}

void Zombie::breed()
{
    if(((this->breedTicks) % ZOMBIE_BREED == 0 ) &&
       (validMove(x-1,y) || validMove(x+1,y) ||
        validMove(x,y-1) || validMove(x,y+1)))
    {
        bool successful = false;
        while (!successful)
        {
            int spot = rand() % 4;
            switch(spot)
            {
                case 0:
                {
                    if(validMove(x-1,y))
                    {
                        Zombie *z = new Zombie(city, x - 1, y);
                    }
                    successful = true;
                    break;
                }
                case 1:
                {
                    if(validMove(x+1,y))
                    {
                        Zombie *z = new Zombie(city, x + 1, y);
                    }
                    successful = true;
                    break;
                }
                case 2:
                {
                    if(validMove(x,y+1))
                    {
                        Zombie *z = new Zombie(city, x, y + 1);
                    }
                    successful = true;
                    break;
                }
                case 3:
                {
                    if(validMove(x,y-1))
                    {
                        Zombie *z = new Zombie(city, x, y - 1);
                    }
                    successful = true;
                    break;
                }
            }
        }
    }
}

bool Zombie::starve()
{
    if(this->starvation == ZOMBIE_STARVE)
        return true;
    else
        return false;
}

void Zombie::move()
{
    // random number generator
    int spot = rand() % 8;

    // Left
    if(city->getOrg(x - 1, y) != NULL && (city->getOrg(x - 1, y))->getType() == HUMAN && spot == 0)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x - 1, y, this);
        this->x -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Right
    else if(city->getOrg(x + 1, y) != NULL && (city->getOrg(x + 1, y))->getType() == HUMAN && spot == 1)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x + 1, y, this);
        this->x += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Up
    else if(city->getOrg(x, y - 1) != NULL && (city->getOrg(x, y - 1))->getType() == HUMAN && spot == 2)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x, y - 1, this);
        this->y -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Down
    else if(city->getOrg(x, y + 1) != NULL && (city->getOrg(x, y + 1))->getType() == HUMAN && spot == 3)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x, y + 1, this);
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Diagonal Up Left
    else if(city->getOrg(x - 1, y - 1) != NULL && (city->getOrg(x - 1, y - 1))->getType() == HUMAN && spot == 4)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x - 1, y - 1, this);
        this->x -= 1;
        this->y -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Diagonal Up Right
    else if(city->getOrg(x + 1, y - 1) != NULL && (city->getOrg(x + 1, y - 1))->getType() == HUMAN && spot == 5)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x + 1, y - 1, this);
        this->x += 1;
        this->y -= 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Diagonal Down Left
    else if(city->getOrg(x - 1, y + 1) != NULL && (city->getOrg(x - 1, y + 1))->getType() == HUMAN && spot == 6)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x - 1, y + 1, this);
        this->x -= 1;
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    // Diagonal Down Right
    else if(city->getOrg(x + 1, y + 1) != NULL && (city->getOrg(x + 1, y + 1))->getType() == HUMAN && spot == 7)
    {
        city->setOrg(x, y, NULL);
        city->setOrg(x + 1, y + 1, this);
        this->x += 1;
        this->y += 1;
        this->starvation = 0;
        (this->breedTicks)++;
    }
    else
    {
        this->starvation++;
    }

}