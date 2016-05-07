/**
Grundlagen der Programmierung 2
Übung 5
Gruppe: Johannes Hackl, Christian Filler
*/

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

fighter::~fighter()
{

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
			cout << mname << " hit pretty hard!" << endl;
        }
    }
    return dmg;
}

void ninja::takesDamage(int damage)
{
    if (randomGenerator(6,1)==6)
    {
        //Kein Schaden
		cout << mname << " evaded the attack!" << endl;
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
        if (randomGenerator(6,1)==1)
        {
			int max = damage * 2;
				if (max > defensePoints * 2)
				{
					max = defensePoints * 2;
				}
            lifePoints+=randomGenerator(max, defensePoints/4);
			cout << mname << " is standing a little bit stronger than expected!" << endl;
        }
    }
    return;
}

int pinkFluffyUnicorn::dealsDamage()
{
    int dmg=-1;
    if (!knockedOut)
    {
        dmg=randomGenerator(offensePoints);
        if (dmg+1>=offensePoints)
        {
            dmg=lifePoints;
            lifePoints=0;
            cout  << "Pink Fluffy Unicorn exploded in the face of its opponent." << endl;
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
        cout << "The pink fluffy unicorn "<< mname << " didn't want to fight anymore and thus danced away on rainbows."
        << endl << "The judge decided that counts as a loss for " << mname;
        lifePoints=0;
        knockedOut=true;
    }
    return;
}

int pinkFluffyUnicorn::returnsDamage()
{
    if (lifePoints > 0)
    {
        if (randomGenerator(75)==1)
        {
            cout << mname << " used its rainbow beam to defend itself and thus did over 9000 damage!" << endl;
            return 9001;
			/*
            //Keine Ahnung von wegen ob das Memory Leaks erzeugt ...
            cout << endl << "The pink fluffy unicorn " << mname << " went into a rage after it was attacked and destroyed the whole fight club, killing everyone including you in the process." << endl << endl;
            //throw std::invalid_argument("The fight club and you ceased to exist");
			destroyFighters();
			cout << "The fight club and you ceased to exist" << ;*/
        }
        else
        {
            return randomGenerator(defensePoints);
        }

    }
	return -1;
}
