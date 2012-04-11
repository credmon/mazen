
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
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include "ai.h"
#include "init.h"
#include "mazen.h"

void read_maze(char *fmaze, struct MAZE *smaze)
{
   int fd, len, rows, cols, i;
   char buffer[COLSMAX + 1];
   char **maze;

   /* open maze data file */
   fd = open(fmaze, O_RDONLY);
   /* assert(fd != -1); */
   if (fd <= 0)
   {
      fprintf(stderr, "error: file %s does not exist.", fmaze);
      exit(0);
   }

   /* scan in rows specification */
   bzero(buffer, COLSMAX + 1);
   len = read(fd, buffer, ROWSMAX_READ);
   assert(len == ROWSMAX_READ);
   sscanf(buffer, "%d", &rows);

   /* scan in columns specification */
   bzero(buffer, COLSMAX + 1);
   len = read(fd, buffer, COLSMAX_READ);
   assert(len == COLSMAX_READ);
   sscanf(buffer, "%d", &cols);

   /* malloc maze */
   maze = (char **) malloc(sizeof(char *) * rows);
   assert(maze != (void *) -1);

   /* read in maze row by row */
   for (i = 0; i < rows; i++)
   {
      maze[i] = (char *) malloc(sizeof(char) * cols + 2);
      assert(maze[i] != (void *) -1);
      read(fd, maze[i], cols + 1);
      //maze[i][cols+1] = '\0';
   }

   smaze->maze = maze;
   smaze->rows = rows;
   smaze->cols = cols;

   /* then randomly place objects/enemies */
   ai_generator(smaze);

   close(fd);
}

void init_player(struct PLAYER *splayer)
{
   splayer->hp = 10;
   splayer->max_hp = 10;
   splayer->ammo = 1000000;
   splayer->keys = 0;
   splayer->max_ammo = 1000000;
   splayer->money = 10;
   splayer->curr_weapon = WEP0;
   splayer->weapons = WEP0 | WEP1;
   splayer->symbol = '^';
   splayer->level = 1;

   splayer->row = 1;
   splayer->col = 1;
}
