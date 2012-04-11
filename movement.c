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
#include "mazes.h"
#include "mazen.h"
#include "movement.h"

#define is_stairs(row,col)  (smaze->maze[row][col] == STAIRS1)
#define is_wall(row,col)	(smaze->maze[row][col] == WALL1) ||	\
							(smaze->maze[row][col] == WALL2) ||	\
							(smaze->maze[row][col] == WALL3)
#define is_tunnel(row,col)	(smaze->maze[row][col] == TUNNEL1) || \
							(smaze->maze[row][col] == DOOR1)
#define	is_money(row,col)	(smaze->maze[row][col] == MONEY1)
#define cur_row				splayer->row
#define cur_col				splayer->col

/* generic movement function */
void move_to(struct MAZE *smaze, struct PLAYER *splayer, int to_row, int to_col,
             int row_or_col, int increment)
{
   if ((cur_row + 1) < smaze->rows)
   {
      if (is_wall(to_row, to_col))
      {
         return;
      }
      /* if the player is in a tunnel, and they are not moving
       * to another tunnel or door piece */
      if (smaze->maze[cur_row][cur_col] == TUNNEL1)
      {
         if (is_tunnel(to_row, to_col))
         {
            /* ... */
         }
         else
         {
            return;
         }
      }
      if (is_money(to_row, to_col))
      {
         smaze->maze[to_row][to_col] = ' ';
         splayer->money += 10;
      }
      if (row_or_col == ROW)
      {
         splayer->row += increment;
      }
      if (row_or_col == COL)
      {
         splayer->col += increment;
      }
   }
}

void move_stairs(struct MAZE *smaze, struct PLAYER *splayer, int action)
{
   if (is_stairs(cur_row, cur_col))
   {
      if (action == UP)
         goto_next_level(smaze, splayer);
      else if (action == DOWN)
         goto_prev_level(smaze, splayer);
   }
}
