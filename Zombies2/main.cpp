#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Human.h"
#include "Zombie.h"

using namespace std;

void wait (int seconds);

int main()
{
    srand(time(nullptr));
    int gen = 0;

    City city;
    City *cityPtr;
    cityPtr = &city;

    int humanCount = 0;
    while (humanCount < HUMANS)
    {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (city.getOrg(x, y) == nullptr)
        {
            humanCount++;
            Human *h = new Human(&city, x, y);
        }
    }

    int zombieCount = 0;
    while (zombieCount < ZOMBIES)
    {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        if (city.getOrg(x, y) == nullptr)
        {
            zombieCount++;
            Zombie *z = new Zombie(&city, x, y);
        }
    }

    chrono:: milliseconds interval(PAUSE_SECONDS);

    while(gen <= ITERATIONS){
        gen++;
        city.Display();
        city.MoveStep();
        wait(1);
        cout << endl;
        this_thread::sleep_for(interval);
    }

    return 0;
}


void wait ( int seconds )
{
    clock_t end;
    end = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < end) {}
}