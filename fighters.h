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
protected:
    bool knockedOut;
    int lifePoints;
    int offensePoints;
    int defensePoints;
};

class warrior : public fighter {
public:
    warrior(const string &name):fighter(name){};
    int dealsDamage();
};

class ninja : public fighter {
public:
    ninja(const string &name):fighter(name){};
    void takesDamage(int damage);
};

class tank : public fighter {
public:
    tank(const string &name):fighter(name){};
    void takesDamage(int damage);
};

class pinkFluffyUnicorn : public fighter {
public:
    pinkFluffyUnicorn(const string &name):fighter(name){};
    void takesDamage(int damage);
    int dealsDamage();
	int returnsDamage();
};

#endif // FIGHTERS_H_INCLUDED
