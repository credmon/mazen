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
#ifndef MAZEN_H
#define MAZEN_H

#define MAZEFILE		"maze_1.dat"
#define COLSMAX			999
#define COLSMAX_READ	4
#define ROWSMAX			999
#define ROWSMAX_READ	4

/* Maze symbols
 *
 *	Structural:
 *	+	corner
 *	|	wall
 *	-	wall
 *	*	tunnel
 *	=	stairs/ladder
 *	E	entrance
 *	X	exit
 *	%	door
 *
 *	Other:
 *	$	money
 *	
 */

/* walls */
#define WALL1	'|'
#define WALL2	'-'
#define WALL3	'+'

/* tunnel */
#define TUNNEL1	'*'

/* door */
#define DOOR1	'%'

/* stairs */
#define STAIRS1 '='
#define STAIRS2 '/'

/* money 
 *	$	$10 */
#define MONEY1	'$'

/* keys */
#define	LEVEL1_KEY	1
#define	LEVEL2_KEY	2
#define	LEVEL3_KEY	4
#define	LEVEL4_KEY	8

/* weapons */
#define WEP0	1	/* fists */
#define	WEP1	2	/* knife */
#define	WEP2	4
#define	WEP3	8
#define	WEP4	16

struct MAZE {
	char**	maze;
	int		rows;
	int		cols;
};

struct PLAYER {
	int		hp;
	int		ammo;
	int		curr_weapon;
	int		weapons;
	int		keys;
	int		money;
	int		max_hp;
	int		max_ammo;
	char	symbol;
	int		level;
	
	/* location information */
	int		row;
	int		col;
};

#endif
