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
#include <strings.h>
#include <signal.h>
#include "mazen.h"
#include "signals.h"
#include "nocurses.h"

#if defined(NO_CURSES) && (NO_CURSES > 0)
void print_maze(struct MAZE *smaze)
{
   int i;

   /* print off maze */
   for (i = 0; i < smaze->rows; i++)
   {
      printf("%s", smaze->maze[i]);
   }
}

void print_ingame_maze(struct MAZE *smaze, struct PLAYER *splayer)
{
   int i, j;

   /* print off maze and player location */
   for (i = 0; i < smaze->rows; i++)
   {
      if (splayer->row == i)
      {
         for (j = 0; j <= smaze->cols; j++)
         {
            if (splayer->col == j)
            {
               printf("%c", splayer->symbol);
            }
            else
            {
               printf("%c", smaze->maze[i][j]);
            }
         }
      }
      else
      {
         printf("%s", smaze->maze[i]);
      }
   }
}

void print_ingame_stats(struct PLAYER *splayer)
{
   printf("HP: %d/%d\n", splayer->hp, splayer->max_hp);
}

void *ingame_console(struct MAZE *smaze, struct PLAYER *splayer)
{
   char input[32];

   bzero(input, 32);
   printf("move> ");
   fflush(stdout);
   while (read(0, input, 32) >= 0)
   {
      printf("read: %s", input);
      switch (input[0])
      {
   /****************************/
            /* Movement                 */
   /****************************/
         case 'l':             /* move right */
            if ((splayer->col + 1) < smaze->cols)
               splayer->col += 1;
            break;
         case 'h':             /* move left */
            if ((splayer->col - 1) >= 0)
               splayer->col -= 1;
            break;
         case 'k':             /* move up */
            if ((splayer->row - 1) >= 0)
               splayer->row -= 1;
            break;
         case 'j':             /* move down */
            if ((splayer->row + 1) < smaze->rows)
               splayer->row += 1;
            break;
   /****************************/
         case 'a':             // alarm
            signal(SIGALRM, mazen_sigalrm);
            alarm(2);
            break;
         case 'q':             /* quit */
            return 0;
            break;
      }
      print_ingame_maze(smaze, splayer);
      print_ingame_stats(splayer);
      printf("move> ");
      fflush(stdout);
      bzero(input, 32);
   }

   return 0;
}
#endif
