#ifndef MAIN_H
#define MAIN_H

#define NCURSES_MOUSE_VERSION 2

#include <curses.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <string.h>

using namespace std;

class PLANET
{
public:

    int type; // 0 = aggricultural 1 = mining 2 = manufactuing 3 = hospiatlity 5 = science 6 = uninhabited
    int pImport;
    int pExport;
    int baseFund;

};

class STAR
{
public:

    int x,y,z;
    string Name;
    vector<PLANET> planet;
};

class SHIP
{
public:

    string name;
    int fuel, hull, shield;
    int fuelMax, hullMax, shieldMax;
};

class PLAYER
{
public:

    int ship, money, planet;
    int wep, shld, nav;

    PLAYER(int ship = 0, int money = 100, int planet = 0, int wep = 0, int shld = 0, int nav = 0)
        : ship(ship), money(money), planet(planet), wep(wep), shld(shld), nav(nav)
    {
    }
};
#endif // MAIN_H
