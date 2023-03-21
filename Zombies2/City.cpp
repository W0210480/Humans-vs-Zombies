//
// Created by RyanG on 2022-12-09.
//

#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Windows.h"


City::City()
{
    int i,j;
    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            grid[i][j]=NULL;
        }
    }
}

City::~City()
{
    int i,j;
    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL) delete (grid[i][j]);
        }
    }
}

Organism* City::getOrg(int x, int y)
{
    if ((x>=0) && (x < GRIDSIZE) && (y >= 0) && (y < GRIDSIZE))
        return grid[x][y];
    return NULL;
}

void City::setOrg(int x, int y, Organism *org)
{
    if ((x>=0) && (x < GRIDSIZE) && (y >= 0) && (y < GRIDSIZE))
    {
        grid[x][y] = org;
    }
}

void City::Display()
{
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j;
    int countH=0, countZ=0;
    cout << endl << endl;
    for (j=0; j < GRIDSIZE; j++)
    {
        for (i=0; i < GRIDSIZE; i++)
        {
            if (grid[j][i]==NULL)
            {
                SetConsoleTextAttribute(hConsole, SPACE_COLOR);
                cout << SPACE_CH;
            }


            else if (grid[j][i]->getType() == HUMAN)
            {
                countH++;
                SetConsoleTextAttribute(hConsole, HUMAN_COLOR);
                cout << HUMAN_CH;
            }
            else if (grid[j][i]->getType() == ZOMBIE)
            {
                countZ++;
                SetConsoleTextAttribute(hConsole, ZOMBIE_COLOR);
                cout << ZOMBIE_CH;
            }
            else
            {
                SetConsoleTextAttribute(hConsole, SPACE_COLOR);
                cout << SPACE_CH;
            }
            cout << "  ";
        }
        cout << endl;
    }
    cout << endl << HUMAN_CH << " = " << countH << "\t  " << ZOMBIE_CH << " = " << countZ;
}

void City::MoveStep()
{
    int i,j;
    //reset organisms to not moved
    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if (grid[i][j]!=NULL)
            {
                grid[i][j]->moved = false;
            }
        }
    }

    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getType() == ZOMBIE))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getType() == HUMAN))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && (grid[i][j]->getType() == ZOMBIE))
            {
                if (grid[i][j]->starve())
                {
                    (grid[i][j]) = (Organism *) HUMAN;
                    grid[i][j] = NULL;
                }
            }
        }
    }

    for (i=0; i < GRIDSIZE; i++)
    {
        for (j=0; j < GRIDSIZE; j++)
        {
            if ((grid[i][j]!=NULL) && grid[i][j]->moved)
            {
                grid[i][j]->breed();
            }
        }
    }
}
