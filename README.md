# My_runner
Game with a scrolling camera in which the character must stay, while dodging obstacles.

Use command "make" to compile the game.
You must have the csfml v2.x to play the game.

I advice you to lanche binary this way:
./my_runner -m map1 map2 map3 map4 map5

Use Arrow/Space/Enter in the game menu.

USAGE:
         ./my_runner [-FLAG] [MAP ...]
OPTIONS:
         -m        Launch game menu
         -i        Launch game in infinity mode
         -e        Launch game in edit mode
         -m        Launch menu
         -h        Print the usage and quit
         Put [MAP ...] as param with [-i] and [-m]
Welcome to MACRON_RUN
/!\ RULES /!\:
         -RUN
         -Don't get caught by gilet jaune
         COMMANDS:
                  Sprint -> Right
                  Jump   -> Up

.legend : Building a map
A map must contain 108 lines
All map lines must have the same length
Char position in the map represent with a scale of X10, the anchor of sprite in game
All char are allowed, but only those described below represent sprites:
         B = Barrel
         C = Crate
         H = Hail wagon
         W = Well
Background and entities cannot be represented in this file and will be randomly generated in the game
