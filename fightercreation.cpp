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
            while (createdFighters[inputS])
            {
                cout << endl << "I'm sorry, another fighter already uses this name. Please choose another one." << endl;
                getline (cin, inputS);
            }
        }

        switch (inputI)
        {
            case 1: createdFighters[inputS] = new warrior(inputS);
                    break;
            case 2: createdFighters[inputS] = new ninja(inputS);
                    break;
            case 3: createdFighters[inputS] = new tank(inputS);
                    break;
            case 4: createdFighters[inputS] = new pinkFluffyUnicorn(inputS);
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