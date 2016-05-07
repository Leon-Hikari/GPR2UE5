#include <iostream>
#include <vector>
#include <string>
#include "fighters.h"
#include "fightclub.h"

using namespace std;

void commenceFightOneOnOne(fighter * fighter1, fighter * fighter2)
{
    int dmg1=0;
    int dmg2=0;
    string dmgS;
    fighter * winner = nullptr;
    fighter * looser = nullptr;
    string noattack = "not happen and thus did not inflict any";
    int *winnerdmg = nullptr;
    string *looserdmg = nullptr;

    //ZUFÄLLIGER KÄMPFER BEGINNT
    if (randomGenerator(1))
    {
        dmg1=fighter1->dealsDamage();
        cout << fighter1->mname << " attacks with " << dmg1 << " points of damage" << endl;
        fighter2->takesDamage(dmg1);
        dmg2=fighter2->returnsDamage();
		if (dmg2>=0)
        {
            cout << fighter2->mname << " counterattacks with " << dmg2 << " points of damage" << endl;
            fighter1->takesDamage(dmg2);
        }

    }
    else
    {
        dmg2=fighter2->dealsDamage();
        cout << fighter2->mname << " attacks with " << dmg2 << " points of damage" << endl;
        fighter1->takesDamage(dmg2);
        dmg1=fighter1->returnsDamage();
		if (dmg1>=0)
        {
            cout << fighter1->mname << " counterattacks with " << dmg1 << " points of damage" << endl;
            fighter2->takesDamage(dmg1);
        }

    }
    //Eruierung des Siegers: Jener der mehr Schaden ausgeteilt hat oder der der letzte noch stehende ist
    if ((dmg1 > dmg2 && fighter1->getLifePoints()>0) || fighter2->getLifePoints()<=0)
    {
        winnerdmg=&dmg1;
        if (fighter2->getLifePoints()<=0 && dmg2==-1)
            looserdmg=&noattack;
        else
        {
            dmgS=to_string(dmg2);
            looserdmg=&dmgS;
        }
        winner=fighter1;
        looser=fighter2;
    }
    else if ((dmg2 > dmg1 && fighter2->getLifePoints()>0) || fighter1->getLifePoints()<=0)
    {
        winnerdmg=&dmg2;
        if (fighter1->getLifePoints()<=0 && dmg1==-1)
            looserdmg=&noattack;
        else
        {
            dmgS=to_string(dmg1);
            looserdmg=&dmgS;
        }
        winner=fighter2;
        looser=fighter1;
    }

    cout << endl << "The fight round between " << fighter1->mname << " and " << fighter2->mname << " ended." << endl;
    if (winner)
    {
        cout <<"The winner of this round is ";
        cout << winner->mname << " whose attack did " << *winnerdmg << " damage and who has " << winner->getLifePoints() << " lifepoints remaining." <<
        endl << "The loser is " << looser->mname << " whose attack did " << *looserdmg << " damage and who has " << looser->getLifePoints() << " lifepoints remaining." << endl << endl;
    }
    else
    {
        cout << "The round ended in a draw." << endl;
        cout << fighter1->mname << " has " << fighter1->getLifePoints() << " lifepoints remaining, " << fighter2->mname << " has " << fighter2->getLifePoints()<< " lifepoints remaining." << endl << endl;
    }

	deleteKOedFighter(fighter1);
	deleteKOedFighter(fighter2);
	return;
}



// EINER GEGEN EINEN KAMPF MIT DEN KLASSEN DER KÄMPFERN ÜBERGEBEN FINDET STATT
void commenceFightOneOnOneToKO(fighter * fighter1, fighter * fighter2)
{
    string fighter1name=fighter1->mname;
    string fighter2name=fighter2->mname;
    unsigned int countfighters=createdFighters.size();
    while (countfighters==createdFighters.size())
    {
        commenceFightOneOnOne(fighter1, fighter2);
    }
    cout << endl << "And the winner in the fight between " <<
    fighter1name << " and " << fighter2name << " is: " << endl;
    if (createdFighters[fighter1name])
        cout << fighter1->mname << " with " << fighter1->getLifePoints() << " lifepoints remaining";
    else if (createdFighters[fighter2name])
        cout << fighter2->mname << " with " << fighter2->getLifePoints() << " lifepoints remaining";
    cout  << "!" << endl << endl;
}


// MENÜ ZUR AUSWAHL DER KÄMPFER UND ZUM INITIALISIEREN DES KAMPFES
void fightOneOnOne(bool toKO)
{
    bool error=false;
    string fighter1, fighter2;
    do{
        error=false;

        cout << "So you have come to the battle ring." <<
        endl << "Tell me the names of the fighters you wish to see a fight between:"<<
        endl << endl << " Fighter 1: ";
        getline (cin, fighter1);
        cout << endl << " Fighter 2: ";
        getline (cin, fighter2);
        cout << endl;

        if (!createdFighters[fighter1])
        {
            cout << "Fighter " << fighter1 << " isn't registered in the Fight Club!" << endl;
            error=true;
        }
        if (!createdFighters[fighter2])
        {
            cout << "Fighter " << fighter2 << " isn't registered in the Fight Club!" << endl;
            error=true;
        }
        if (error)
        {
            cout << "Please choose existing fighters!" << endl << endl;
            return;
        }

    }while (error);

    if (toKO)
    {
        commenceFightOneOnOneToKO(createdFighters[fighter1], createdFighters[fighter2]);
    }
    else
    {
        commenceFightOneOnOne(createdFighters[fighter1], createdFighters[fighter2]);
    }

}

// BESTÄTIGUNG DER LAST MAN STANDING AUSWAHL UND ERKLÄRUNG VON DIESER UND INITIALISIERUNG DES KAMPFES
void fightLastManStanding()
{
	int nbfighterA;
	int nbfighterB;
    unsigned int numberFighters=createdFighters.size();
	vector<fighter*> v;

	bool fightsremaining = true;

	if (numberFighters > 1)
	{
		cout << "So you have come to the big battle arena." <<
			endl << "Here all the registered fighters will fight each other randomly one by one until only one of them is last standing." <<
			endl << "There is a total of " << numberFighters << " who will compete in this battle. " <<
			endl << "Let the battle begin!" <<
			endl << endl;

		while (fightsremaining)
		{
			for (map <string, fighter*>::iterator it = createdFighters.begin(); it != createdFighters.end(); ++it) {
				v.push_back(it->second);
			}

			numberFighters = v.size();
			if (numberFighters > 1)
			{

				nbfighterA = randomGenerator(numberFighters - 1, 0);



				do {
					nbfighterB = randomGenerator(numberFighters - 1, 0);

				} while (nbfighterA == nbfighterB);

                cout << v[nbfighterA]->mname << " and " << v[nbfighterB]->mname << " step into the ring!" << endl;
				commenceFightOneOnOne(v[nbfighterA], v[nbfighterB]);
			}
			else
			{
				fightsremaining = false;
			}

			v.clear();
			if (!fightsremaining && createdFighters.size() == 1)
			{
				cout << "The winner of the Last Man Standing event is: " << createdFighters.begin()->second->mname << endl << endl;
			}
		}
	}
	else
	{
		cout << "There are not enough fighters registered for this event!" << endl << endl;
	}

}
