#ifndef _GAMESPECS_H
#define _GAMESPECS_H


const int GRIDSIZE = 20; // size of the square grid
const int HUMANS = 100; // # of humans, initially
const int ZOMBIES = 5; // # of zombies, initially
const int HUMAN = 1; // value of the status flag for a human
const int ZOMBIE = 2; // value of the status flag for a zombie
const int HUMAN_BREED = 3; // steps until an human breeds/recruits
const int ZOMBIE_BREED = 8; // steps until an zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a zombie dies unless it ate a human
const char HUMAN_CH = 72;//79 "H"// ascii Human
const char SPACE_CH = 45; // char to display for a space
const char ZOMBIE_CH = 90;//90 "Z"// ascii zombie
const int PAUSE_SECONDS = 1; // pause between steps
const int ITERATIONS = 100; // max number of steps

//Colors
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquoise			//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow
const int SPACE_COLOR = 15; // bright white

class Organism;
class Zombie;
class Human;

#endif