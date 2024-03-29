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
#include "mazen.h"
#include "weapons.h"

void switch_weapon(struct PLAYER *splayer, int action)
{
   if (action == WEP_NEXT)
   {
      if ((splayer->curr_weapon << 1) & splayer->weapons)
      {
         splayer->curr_weapon = splayer->curr_weapon << 1;
      }
   }

   if (action == WEP_PREV)
   {
      if ((splayer->curr_weapon >> 1) & splayer->weapons)
      {
         splayer->curr_weapon = splayer->curr_weapon >> 1;
      }
   }
}
