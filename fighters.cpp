#include <string>
#include <iostream>
#include <stdexcept>
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
    int dmg=0;
    if (!knockedOut)
    {
        int dmg=randomGenerator(offensePoints);
        if (randomGenerator(6,1)==6)
        {
            dmg*=2;
        }
    }
    return dmg;
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

void tank::takesDamage(int damage)
{
    lifePoints-=damage;
    if (lifePoints<=0)
    {
        knockedOut=true;
    }
    else
    {
        if (randomGenerator(6,1))
        {
            lifePoints+=randomGenerator(defensePoints/4, defensePoints*2);
        }
    }
    return;
}

int pinkFluffyUnicorn::dealsDamage()
{
    int dmg=0;
    if (!knockedOut)
    {
        dmg=randomGenerator(offensePoints);
        if (dmg-2>=offensePoints)
        {
            dmg=lifePoints;
            lifePoints=0;
            cout << endl << "Pink Fluffy Unicorn exploded in the face of its opponent." << endl;
            knockedOut=true;
        }

    }
    return dmg;
}
void pinkFluffyUnicorn::takesDamage(int damage)
{
    lifePoints-=damage;
    if (lifePoints<=0)
    {
        knockedOut=true;
    }
    else if (randomGenerator(75)==1)
    {
        cout << endl << "The pink fluffy unicorn "<< mname << " didn't want to fight anymore and danced away on rainbows."
        << endl << "The judge decided that counts as a loss for " << mname;
        lifePoints=0;
        knockedOut=true;
    }
}

int pinkFluffyUnicorn::returnsDamage()
{
    if (lifePoints > 0)
    {
        if (randomGenerator(1000)==1)
        {
            //Keine Ahnung von wegen ob das Memory Leaks erzeugt ...
            cout << endl << "The pink fluffy unicorn " << mname << " went into a rage after it was attacked and destroyed the whole fight club, killing everyone including you in the process." << endl << endl;
            throw std::invalid_argument("The fight club and you ceased to exist");
        }
        else
        {
            return randomGenerator(defensePoints);
        }

    }
}
