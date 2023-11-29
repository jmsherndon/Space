#include "Main.h"

int gHeight = 25, gWidth = 50;

void Render(PLAYER player, SHIP ship, STAR star[50], bool check);

int main()

{
    bool isrunning = true;
    char ch = '\0';
    srand(time(0));
    initscr();
    start_color();
    keypad(stdscr,0);
    noecho();
    cbreak();
    raw();
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    bool check = false;
    MEVENT event;



    PLAYER player;
    SHIP ships;
    STAR star[50];



    ships.name = "Wasp";
    ships.hull = 150;
    ships.shield = 0;
    ships.fuel = 20;
    ships.fuelMax = 20;
    ships.hullMax = 150;
    ships.shieldMax = 0;



    for(int i = 0; i < 50; i++)
    {
        int randY = (rand() % 23) + 1 ;
        int randX = (rand() % 48) + 1;

        for(int j = i; j >= 0; j--)
        {
            if (randX == star[j].x && randY == star[j].y)
            {
                i--;
                break;
            }
            else
            {
                star[i].x = randX;
                star[i].y = randY;
            }
        }
    }




    do
{

    if(ch == 27)
    {
        isrunning = false;
    }
    else if(ch == KEY_MOUSE)
    {
        if(nc_getmouse(&event) == OK)
        {
            if(event.bstate & BUTTON1_CLICKED)
            {
                        printw("click");

                        check = true;


            }
        }
    }

    Render(player, ships, star, check);

    ch = '\0';
    ch = getch();

}while(isrunning);

    endwin();
    return 0;
}


void Render(PLAYER player, SHIP ship, STAR star[50], bool check)
{

    WINDOW *game = subwin(stdscr, gHeight,gWidth,0,0);
    WINDOW *info = subwin(stdscr, 13, 25, 0, gWidth);
    WINDOW *data = subwin(stdscr, 12, 25, 13, gWidth);

    box(game, 0, 0);
    box(info, 0, 0);
    box(data, 0, 0);

    for(int y = 1; y < 24; y++)
    {
        for(int x = 1; x < 49; x++)
        {
            mvwprintw(game, y, x," ");
        }
    }

    for(int i = 0; i < 50; i++)
    {
        mvwprintw(game, star[i].y, star[i].x, ".");
    }

    mvwprintw(info, 1, 1, "Ship: %s", ship.name.c_str());
    mvwprintw(info, 2, 1, "Hull: %d / %d", ship.hull, ship.hullMax);
    mvwprintw(info, 3, 1, "Shield: %d / %d", ship.shield, ship.shieldMax);
    mvwprintw(info, 4, 1, "Fuel: %d / %d", ship.fuel, ship.fuelMax);

    if(check == true)
    {
        mvwprintw(data, 1, 1, "STAR!");
    }

    wrefresh(game);
    wrefresh(info);
    wrefresh(data);
}
