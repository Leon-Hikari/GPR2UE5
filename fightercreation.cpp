/**
Grundlagen der Programmierung 2
Übung 5
Gruppe: Johannes Hackl, Christian Filler
*/

#include <string>
#include <iostream>
#include "fighters.h"
#include "fightclub.h"

using namespace std;


//MENÜ ZUR AUSWAHL VON TYP UND NAMEN EINES NEUEN KÄMPFERS
void createFighter()
{
    string inputS;
    int inputI;


    {
        cout << endl << "What kind of fighter is it?" <<
        endl << " 1) Warrior: A brave fighter that sometimes attacks very strongly" <<
        endl << " 2) Ninja: Moving so fast that they can sometimes escape an attack but still launch a counterattack" <<
        endl << " 3) Tank: Someone who can take much more damage than everyone else" <<
        endl << " 4) Pink Fluffy Unicorn: It dances on rainbows" <<
        endl << " 5) Don't register any new fighter" <<
        endl << endl;

        getline(cin, inputS);
        inputI=inputS[0]-'0';

        if (inputI>0 && inputI<=4)
        {
            cout << endl << "I see. And under what name should I register this fighter?" << endl;
            getline (cin, inputS);

            //Überprüfen ob Name bereits vorhanden
            while (mapfind(inputS) == true)
            {
                cout << endl << "I'm sorry, another fighter already uses this name. Please choose another one." << endl;
                getline (cin, inputS);
            }
        }

        switch (inputI)
        {
            case 1: createdFighters[inputS] = new warrior(inputS);
					createdFighters[inputS]->mtype = "Warrior: Sometimes this fighter attacks very fiercely";
                    break;
            case 2: createdFighters[inputS] = new ninja(inputS);
					createdFighters[inputS]->mtype = "Ninja: A Ninja can sometimes evade an enemy attack but still counterattack";
                    break;
            case 3: createdFighters[inputS] = new tank(inputS);
					createdFighters[inputS]->mtype = "Tank: Has a chance of regaining lost hitpoints after being hit and is still standing";
                    break;
            case 4: createdFighters[inputS] = new pinkFluffyUnicorn(inputS);
					createdFighters[inputS]->mtype = "Pink Fluffy Unicorn: Sometimes it attacks with its terrible rainbow-beam, sometimes it looses its will to fight";
                    break;
            case 5: return;
                    break;
            default:    wrongInputNumber();
                        break;
        }

        cout << "The fighter with the name " << inputS << " was successfully registered." <<
        endl << "He has " << createdFighters[inputS]->getLifePoints() << " lifepoints, " << createdFighters[inputS]->getOffensePoints() << " offensepoints and " << createdFighters[inputS]->getDefensePoints() << " defensepoints." << endl << endl;


    }
    return;
}

void destroyFighters() {
	for (map <string, fighter*>::iterator i = createdFighters.begin(); i != createdFighters.end(); i++) {
		delete i->second;
	}
	createdFighters.clear();
}

void listFighters() {
    cout << "This are the registered Fighters:" << endl << endl;
	for (map <string, fighter*>::iterator i = createdFighters.begin(); i != createdFighters.end(); i++) {
		cout << i->second->mname << " is a " << i->second->mtype << endl;
		cout << "This fighter currently has " << i->second->getLifePoints() << " Lifepoints, " << i->second->getOffensePoints() << " Offensepoints and " << i->second->getDefensePoints() << " Defensepoints." << endl;
	}
	cout << endl;
}

void deleteFighter(fighter* fighter1)
{
    //cout << "Number of fighters before deletion: " << createdFighters.size() << endl;
    createdFighters.erase(fighter1->mname);
    delete fighter1;
    fighter1=nullptr;
    //cout << "Number of fighters after deletion: " << createdFighters.size() << endl;
}

void deleteKOedFighter(fighter* fighter1) {
	if (fighter1->getLifePoints() <= 0)
	{
        deleteFighter(fighter1);
	}
}

void retireFighter()
{
    string input;
    cout << "Which fighter do you wish to withdraw from the tournament registration?" << endl;
    getline (cin, input);
    if(mapfind(input) == true)
    {
        deleteFighter(createdFighters[input]);
        cout << "We have withdrawn the registration of " << input << endl << endl;
    }
    else
    {
        cout << "We don't have anyone registered under this name." << endl << endl;
    }
}
