/**
Grundlagen der Programmierung 2
�bung 5
Gruppe: Johannes Hackl, Christian Filler
*/

#include <iostream>
#include <string>
#include <random>
#include <map>
#include "fighters.h"
#include "fightclub.h"
#include <ctime>

using namespace std;

//GLOBALE K�MPFERLISTE
map <string, fighter*> createdFighters;

bool mapfind(string name) {
	std::map<string, fighter*>::iterator it;
	it = createdFighters.find(name);

	if (it != createdFighters.end())
		return 1;
	return 0;
}

//ZUFALLSGENERATOR
int randomGenerator(int maximum, int minimum)
{
    //default_random_engine rd;
    random_device rd; //Zufallszahl von der Hardware generieren
    mt19937_64 gen(rd()); //64 Bit Mersenne Twister
    uniform_int_distribution<> dis(minimum,maximum); //Bereich von minimum bis maximum festlegen
    return dis(gen);
}

// GIBT EINE FEHLERMELDUNG BEI FALSCHER ZAHLENEINGABE IN MEN�S AUS
void wrongInputNumber()
{
    cout << "What did you say you wanted to do?" <<
    endl << "All you have to do is say a single number." <<
    endl << endl;
}

// MEN� ZUR AUSWAHL WAS MAN IM FIGHT CLUB MACHEN M�CHTE
int main()
{
    cout << "!Welcome to the Fight Club!" << endl << endl;

    string inputS;
    int inputI;

    while (1)
    {
        cout << "Choose what you want: " <<
        endl << " 1) Battlemode: Last Man Standing" <<
        endl << " 2) Battlemode: Single Fight" <<
        endl << " 3) Battlemode: Fight to KO" <<
        endl << " 4) Register new fighter" <<
        endl << " 5) Retire one of the fighters" <<
		endl << " 6) List all fighters" <<
        endl << " 7) Leave the Fight Club" <<
        endl << endl;

        getline(cin, inputS);
        cout << endl;
        inputI=inputS[0]-'0';
        switch (inputI)
        {
            case 1: fightLastManStanding();
                    break;
            case 2: fightOneOnOne(false);
                    break;
            case 3: fightOneOnOne(true);
                    break;
            case 4: createFighter();
                    break;
            case 5: retireFighter();
                    break;
			case 6: listFighters();
					break;
			case 7: destroyFighters();
					return 0;
                    break;
            default:    wrongInputNumber();
                        break;
        }

    }

    return 0;
}
