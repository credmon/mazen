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
#include <stdlib.h>
#include "ai.h"
#include "mazen.h"

void ai_generator(struct MAZE *smaze)
{
   int init, spacing, num, i, j;

   init = rand() % (smaze->rows * smaze->cols);
   spacing = rand() % (smaze->rows * smaze->cols);

   for (i = 0; i < smaze->rows; i++)
   {
      for (j = 0; j < smaze->cols; j++)
      {
         if ((num =
              (random() % 2) * (random() % 2) * (random() % 2) * (random() %
                                                                  2) *
              (random() % 2)) == 1)
         {
            if (smaze->maze[i][j] == ' ')
            {
               smaze->maze[i][j] = MONEY1;
            }
         }
      }
   }

}
