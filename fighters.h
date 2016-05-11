/**
Grundlagen der Programmierung 2
Übung 5
Gruppe: Johannes Hackl, Christian Filler
*/

#ifndef FIGHTERS_H_INCLUDED
#define FIGHTERS_H_INCLUDED
#include <string>

using namespace std;

class fighter {
public:
    fighter(const string &name);
    const string mname;
    virtual void takesDamage(int damage);
    virtual int dealsDamage();
    virtual int returnsDamage();
    virtual ~fighter();
    int getLifePoints();
    int getOffensePoints();
    int getDefensePoints();
    string getClassDescription();
protected:
    bool knockedOut;
    int lifePoints;
    int offensePoints;
    int defensePoints;
    string mtype;
};

class warrior : public fighter {
public:
    warrior(const string &name):fighter(name){mtype="Warrior: Sometimes this fighter attacks very fiercely";};
    int dealsDamage();
};

class ninja : public fighter {
public:
    ninja(const string &name):fighter(name){mtype="Ninja: A Ninja can sometimes evade an enemy attack but still counterattack";};
    void takesDamage(int damage);
};

class tank : public fighter {
public:
    tank(const string &name):fighter(name){mtype = "Tank: Has a chance of regaining lost hitpoints after being hit and is still standing";};
    void takesDamage(int damage);
};

class pinkFluffyUnicorn : public fighter {
public:
    pinkFluffyUnicorn(const string &name):fighter(name){mtype = "Pink Fluffy Unicorn: Sometimes it attacks with its terrible rainbow-beam, sometimes it looses its will to fight, and sometimes it explodes";};
    void takesDamage(int damage);
    int dealsDamage();
	int returnsDamage();
};

#endif // FIGHTERS_H_INCLUDED
