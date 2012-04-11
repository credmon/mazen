/*
    This is mazen, a maze oriented adventure game.

    Copyright (C) 2006, 2012 Christopher Redmon.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include <stdio.h>
#include <curses.h>
#include "mazen.h"
#include "tty.h"

char *weapon_list[] = {
   "fists      ",
   "knife      ",
   "pistol     ",
   "rifle      ",
   "shotgun    ",
   "machine gun",
   "bazooka    "
};

int tty_break()
{
   initscr();
   cbreak();
   noecho();
   //nonl();
   //intrflush(stdscr,FALSE);
   //keypad(stdscr,TRUE);
   return 0;
}

int tty_getchar()
{
   return getch();
}

int tty_fix()
{
   endwin();
   return 0;
}

int tty_border()
{
   border('|', '|', '-', '-', '+', '+', '+', '+');
   return 0;
}

int tty_print_ingame_maze(struct MAZE *smaze, struct PLAYER *splayer)
{
   int i, j;

   /* print off maze and player location */
   for (i = 0; i < smaze->rows; i++)
   {
      /* if the player's piece is on the current row */
      if (splayer->row == i)
      {
         for (j = 0; j < smaze->cols; j++)
         {
            if (splayer->col == j)
            {
               mvprintw(i + 2, j + 2, "%c", splayer->symbol);
            }
            else
            {
               mvprintw(i + 2, j + 2, "%c", smaze->maze[i][j]);
            }
         }
      }
      else
      {
         for (j = 0; j < smaze->cols; j++)
         {
            mvprintw(i + 2, j + 2, "%c", smaze->maze[i][j]);
         }
      }
   }

   return 0;
}

int tty_print_ingame_stats(struct PLAYER *splayer)
{
   mvprintw(1, 2, "HP: %d/%d", splayer->hp, splayer->max_hp);
   mvprintw(1, 17, "Weapon: %s", weapon_list[splayer->curr_weapon]);
   mvprintw(1, 37, "Money: $%d", splayer->money);
   mvprintw(1, 57, "Level: %d", splayer->level);

   return 0;
}
