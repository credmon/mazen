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
#include <curses.h>
void copyright_notice(int row, int col)
{
   char notice0[] = "mazen  Copyright (C) 2006, 2012  Chris Redmon";
   char notice1[] = "This program comes with ABSOLUTELY NO WARRANTY. This is free software,";
   char notice2[] = "and you are welcome to redistribute it under certain conditions; see";
   char notice3[] = "the GNU General Publiic License as published by the Free Software";
   char notice4[] = "Foundation - version 3 or (at your option) any later version. For more";
   char notice5[] = "information about these matters, see the file named COPYING.";

   mvprintw(row+0, col, "%s", notice0);
   mvprintw(row+1, col, "%s", notice1);
   mvprintw(row+2, col, "%s", notice2);
   mvprintw(row+3, col, "%s", notice3);
   mvprintw(row+4, col, "%s", notice4);
   mvprintw(row+5, col, "%s", notice5);
}
