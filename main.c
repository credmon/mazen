
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
/* mazen.c
 * $Id: main.c,v 1.2 2006/01/04 07:28:09 credmon Exp credmon $
 */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <assert.h>
#include <curses.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <termios.h>
#include <unistd.h>
#include "init.h"
#include "mazen.h"
#include "movement.h"
#include "signals.h"
#include "tty.h"
#include "weapons.h"
#include "copyright.h"

/* function prototypes */
void *ingame_console();

int main(int argc, const char *argv[])
{
   struct MAZE maze;
   struct PLAYER player;

   read_maze(MAZEFILE, &maze);
   init_player(&player);
   ingame_console(&maze, &player);

   return 0;
}

#if !defined(NO_CURSES) || (NO_CURSES < 1)
void *ingame_console(struct MAZE *smaze, struct PLAYER *splayer)
{
   int input;

   tty_break();
   tty_border();

   tty_print_ingame_maze(smaze, splayer);
   tty_print_ingame_stats(splayer);
   mvprintw(LINES - 2, 2, "move> ");
   refresh();
   while ((input = tty_getchar()))
   {
      switch (input)
      {
         /****************************/
         /* Movement                 */
         /****************************/

         /*** move right ***/
         case 'l':
            move_to(smaze, splayer, splayer->row, splayer->col + 1, COL, 1);
            break;

         /*** move left ***/
         case 'h':
            move_to(smaze, splayer, splayer->row, splayer->col - 1, COL, -1);
            break;

         /*** move up ***/
         case 'k':
            move_to(smaze, splayer, splayer->row - 1, splayer->col, ROW, -1);
            break;

         /*** move down ***/
         case 'j':
            move_to(smaze, splayer, splayer->row + 1, splayer->col, ROW, 1);
            break;

         /*** move up stairs ***/
         case 'u':
            move_stairs(smaze, splayer, UP);
            break;

         /*** move down stairs ***/
         case 'd':
            move_stairs(smaze, splayer, DOWN);
            break;

         /****************************/
         /* Weapon Related           */
         /****************************/

         /*** next weapon ***/
         case 'n':
            switch_weapon(splayer, WEP_NEXT);
            break;

         /*** previous weapon ***/
         case 'p':
            switch_weapon(splayer, WEP_PREV);
            break;

         /****************************/
         /* Misc Commands            */
         /****************************/

         /*** help ***/
         case '?':
            mvprintw(smaze->rows + 3, 2, "Help:");
            mvprintw(smaze->rows + 4, 2, " (movement) h - left, j - down, k - up, l - right");
            mvprintw(smaze->rows + 5, 2, " (weapons) p - prev, n - next");
            mvprintw(smaze->rows + 6, 2, " (other) c - copyright notice");
            mvprintw(smaze->rows + 7, 2, "         q - quit");
            break;

         /*** copyright notice ***/
         case 'c':
            copyright_notice(smaze->rows + 9, 2);
            break;

         /*** quit ***/
         case 'q':
            tty_fix();
            return 0;
            break;
      }
      tty_print_ingame_maze(smaze, splayer);
      tty_print_ingame_stats(splayer);
      mvprintw(LINES - 2, 2, "move> ");
      refresh();
   }

   return 0;
}
#endif
