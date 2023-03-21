//
// Created by RyanG on 2022-12-09.
//

#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Human.h"

Human::Human() : Organism()
{

}

Human::~Human() = default;

Human::Human(City *city, int x, int y) : Organism(city, x, y)
{

}

int Human::getType()
{
    return HUMAN;
}

bool Human::starve()
{
    return false;
}

void Human::breed()
{
    if(((this->breedTicks) % HUMAN_BREED == 0 ) &&
       (validMove(x-1,y) || validMove(x+1,y)	||
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
                        auto *h = new Human(city, x - 1, y);
                    }
                    successful = true;
                    break;
                }
                case 1:
                {
                    if(validMove(x+1,y))
                    {
                        auto *h = new Human(city, x + 1, y);
                    }
                    successful = true;
                    break;
                }
                case 2:
                {
                    if(validMove(x,y+1))
                    {
                        auto *h = new Human(city, x, y + 1);
                    }
                    successful = true;
                    break;
                }
                case 3:
                {
                    if(validMove(x,y-1))
                    {
                        auto *h = new Human(city, x, y - 1);
                    }
                    successful = true;
                    break;
                }
            }
        }
    }

    (this->breedTicks)++;
}


