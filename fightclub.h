/**
Grundlagen der Programmierung 2
Übung 5
Gruppe: Johannes Hackl, Christian Filler
*/

#ifndef FIGHTCLUB_H_INCLUDED
#define FIGHTCLUB_H_INCLUDED

#include <map>
#include <string>
#include "fighters.h"

// IN FIGHTS.CPP
void fightLastManStanding();
void fightOneOnOne(bool toKO);

// IN FIGHTERCREATION.CPP
void createFighter();
void destroyFighters();
void deleteKOedFighter(fighter* fighter1);
void retireFighter();

// IN FIGHTCLUB.CPP
void wrongInputNumber();
bool mapfind(string name);
int randomGenerator(int maximum, int minimum=0);
extern map <string, fighter*> createdFighters;

#endif // FIGHTCLUB_H_INCLUDED
