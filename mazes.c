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
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include "mazes.h"
#include "mazen.h"
#include "init.h"

void goto_next_level(struct MAZE *smaze, struct PLAYER *splayer)
{
   char level[36];
   int i;

   bzero(level, 36 * sizeof(char));
   strcat(level, MAZEFILE);

   /* hmm, well I am expecting the maze files to be like this ...
    *   maze_1.dat  -> level 1
    *   maze_2.dat  -> level 2
    *   maze_3.dat  -> level 3
    *    ....
    */
   switch (splayer->level)
   {
      case 1:
         level[5] = '2';
         break;
      case 2:
         level[5] = '3';
         break;
      case 3:
         level[5] = '4';
         break;
      case 4:
         level[5] = '5';
         break;
   }

   splayer->level += 1;

   clear_maze(smaze);

   for (i = 0; i < smaze->rows; i++)
   {
      free(smaze->maze[i]);
   }
   free(smaze->maze);


   read_maze(level, smaze);
}

void goto_prev_level(struct MAZE *smaze, struct PLAYER *splayer)
{
   char level[36];
   int i;

   bzero(level, 36 * sizeof(char));
   strcat(level, MAZEFILE);

   /* hmm, well I am expecting the maze files to be like this ...
    *   maze_1.dat  -> level 1
    *   maze_2.dat  -> level 2
    *   maze_3.dat  -> level 3
    *    ....
    */
   switch (splayer->level)
   {
      case 1:
         level[5] = '1';
         break;
      case 2:
         level[5] = '1';
         splayer->level -= 1;
         break;
      case 3:
         level[5] = '2';
         splayer->level -= 1;
         break;
      case 4:
         level[5] = '3';
         splayer->level -= 1;
         break;
   }

   clear_maze(smaze);

   for (i = 0; i < smaze->rows; i++)
   {
      free(smaze->maze[i]);
   }
   free(smaze->maze);

   read_maze(level, smaze);
}

void clear_maze(struct MAZE *smaze)
{
   int i, j;
   for (i = 0; i < smaze->rows; i++)
   {
      for (j = 0; j < smaze->cols; j++)
      {
#if defined(NO_CURSES) && (NO_CURSES > 0)
         //printf(i+2,j+2," ");
         //fflush(stdout);
#else
         mvprintw(i + 2, j + 2, " ");
#endif
      }
   }
}
