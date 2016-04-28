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

// IN FIGHTCLUB.CPP
void wrongInputNumber();
int randomGenerator(int maximum, int minimum=0);
extern map <string, fighter*> createdFighters;

#endif // FIGHTCLUB_H_INCLUDED
