#include <string>
#include "fighters.h"
#include "fightclub.h"

using namespace std;

/**
Klassenfunktionen von FIGHTER
*/

fighter::fighter(const string &name):mname(name)
{
    lifePoints=100;

    offensePoints=randomGenerator(50, 25);
    defensePoints=randomGenerator(50, 25);
    knockedOut=false;
};

void fighter::takesDamage(int damage)
{
    lifePoints-=damage;
    if (lifePoints<=0)
        knockedOut=true;
    return;
}

int fighter::dealsDamage()
{
    if (!knockedOut)
    {
        return randomGenerator(offensePoints);
    }
    return -1;
}

int fighter::returnsDamage()
{
    if (!knockedOut)
    {
        return randomGenerator(defensePoints);
    }
    return -1;
}

//Hier ein paar GETTER
int fighter::getLifePoints()
{
    return lifePoints;
}
int fighter::getOffensePoints()
{
    return offensePoints;
}
int fighter::getDefensePoints()
{
    return defensePoints;
}


/**
Spezifische Funktionen von UNTERKLASSEN ZU FIGHTER
*/

int warrior::dealsDamage()
{
    if (!knockedOut)
    {
        int dmg=randomGenerator(offensePoints);
        if (randomGenerator(6,1)==6)
        {
            dmg*=2;
        }
        return dmg;
    }
    return -1;
}

void ninja::takesDamage(int damage)
{
    if (randomGenerator(6,1)==6)
    {
        //Kein Schaden
    }
    else
    {
        lifePoints-=damage;
        if (lifePoints<=0)
        {
            knockedOut=true;
        }
    }
    return;
}
