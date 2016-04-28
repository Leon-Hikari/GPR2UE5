#include <iostream>
#include "fighters.h"
#include "fightclub.h"

void commenceFightOneOnOne(fighter * fighter1, fighter * fighter2)
{
    int dmg1=-1;
    int dmg2=-1;
    fighter * winner=nullptr;
    fighter * looser=nullptr;
    string noattack="that did not happen and thus did not inflict any";
    int * winnerdmg = nullptr;
    string *looserdmg =nullptr;

    //ZUFÄLLIGER KÄMPFER BEGINNT
    if (randomGenerator(1))
    {
        dmg1=fighter1->dealsDamage();
        fighter2->takesDamage(dmg1);
        dmg2=fighter2->returnsDamage();
        fighter1->takesDamage(dmg2);
    }
    else
    {
        dmg2=fighter2->dealsDamage();
        fighter1->takesDamage(dmg2);
        dmg1=fighter1->returnsDamage();
        fighter2->takesDamage(dmg1);
    }
    //Eruierung des Siegers: Jener der mehr Schaden ausgeteilt hat oder der der letzte noch stehende ist
    if ((dmg1 > dmg2 && fighter1->getLifePoints()>0) || fighter2->getLifePoints()<=0)
    {
        * winnerdmg=dmg1;
        if (dmg2==-1)
            *looserdmg=noattack;
        else
            *looserdmg=dmg2;
        winner=fighter1;
        looser=fighter2;
    }
    else if ((dmg2 > dmg1 && fighter2->getLifePoints()>0) || fighter1->getLifePoints()<=0)
    {
        *winnerdmg=dmg2;
        if (dmg1==-1)
            *looserdmg=noattack;
        else
            *looserdmg=dmg1;
        winner=fighter2;
        looser=fighter1;
    }

    cout << endl << "The fight round between " << fighter1->mname << " and " << fighter2->mname << " ended." << endl;
    if (winner)
    {
        cout <<"The winner of this round is ";
        cout << winner->mname << " with an attack " << *winnerdmg << " damage and " << winner->getLifePoints() << " lifepoints remaining." <<
        endl << "The loser is " << looser->mname << " with an attack " << *looserdmg << " damage and " << looser->getLifePoints() << " lifepoints remaining." << endl;
    }
    else
    {
        cout << "The round ended in a draw." << endl;
        cout << fighter1->mname << " has " << fighter1->getLifePoints() << " lifepoints remaining, " << fighter2->mname << " has " << fighter2->getLifePoints()<< " lifepoints remaining." << endl;
    }
}

// EINER GEGEN EINEN KAMPF MIT DEN KLASSEN DER KÄMPFERN ÜBERGEBEN FINDET STATT
void commenceFightOneOnOneToKO(fighter * fighter1, fighter * fighter2)
{
    while (fighter1->getLifePoints()>0 && fighter2->getLifePoints()>0)
    {
        commenceFightOneOnOne(fighter1, fighter2);
    }
    cout << endl << "And the winner in the fight between " <<
    fighter1->mname << " and " << fighter2->mname << "is: " << endl;
    if (fighter1->getLifePoints()<=0)
        cout << fighter2->mname << " with " << fighter2->getLifePoints() << " lifepoints remaining";
    else if (fighter2->getLifePoints()<=0)
        cout << fighter1->mname << " with " << fighter1->getLifePoints() << " lifepoints remaining";
    cout  << "!" << endl << endl;
}

// MENÜ ZUR AUSWAHL DER KÄMPFER UND ZUM INITIALISIEREN DES KAMPFES
void fightOneOnOne()
{
    string fighter1, fighter2;
    cout << "So you have come to the battle ring." <<
    endl << "Tell me the names of the fighters you wish to see a fight between:"<<
    endl << endl << " Fighter 1: ";
    getline (cin, fighter1);
    cout << endl << " Fighter 2: ";
    getline (cin, fighter2);
    cout << endl;

    commenceFightOneOnOne(createdFighters[fighter1], createdFighters[fighter2]);
}

// BESTÄTIGUNG DER LAST MAN STANDING AUSWAHL UND ERKLÄRUNG VON DIESER UND INITIALISIERUNG DES KAMPFES
void fightLastManStanding()
{
    cout << "So you have come to the big battle arena." <<
    endl << "Here all the registered fighters will fight each other randomly one by one until only one of them is last standing." <<
    endl << "Let the battle begin!" <<
    endl << endl;


}
