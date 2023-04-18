

title:
Pacman Game.

###############################################################################
###############################################################################
Student details:
shimon luria 312189558
###############################################################################
this prgrame is pacman game. it play 3 levels.
for instructions of game see here:
http://www.google.com/doodles/30th-anniversary-of-pac-man

in the first entry in game you will be see more new featchers
e.g. shots, gifts and more.
pay attention to read the instruction there.

###############################################################################
###############################################################################
design:
The game is made up of 2 stages game objects and managers of stages and general.
Inheritance ratio:

Some objects are static on the board and some can move. Pacman classes 
Elves and Shooters are mobile and heirs from the MoveObject class. The states 
that are gifts and walls are inherited from the NonMoveObjects' class.
MoveObjects NonMoveObjects inherit from General Objects class.
There are types of objects that are commands and heirs from the COMMAND class.

Bridal relationship:
Game class contains vector steps.
The phase class contains a vector menu of objects
The menu class contains a vector of commands.

###############################################################################
###############################################################################
class and ruls;
game
A class manage the levels and user interface;

board
manage all user commands.

Menu:
class contian and manange all boards commnds.

Levels:
databace of all objects and manage the game for any level.

Command:
base class of user commands (without move pacman).

Objects:
base class of obgects. contian all common functions.

ManageCollision:
manage all collision between two objects on board.

GiftPoints:
get for pacman points.

GiftLives:
get lives for pacman.

GiftShots:
get shots For pacman.

Wall:
wall and avoid moving objects. pacman can break them by shoting.

Pacman:
manage all information and action of pacman.

Demon:
base class of demons:

RanddomDemon:
demon moving randomly.

SmartDemon:
smart demon move correspondence to pacman location.

Shot:
base class of shots.

PacShot:
shots that created by pacman.

DemonShot:
shots that created by  a demon.

stopRun:
command with button that stop all objects on board.

Plus:
command with button that increases speed of all move objects on board.

Minus
command with button that reduces speed of all move objects on board.





###############################################################################
###############################################################################
special algorithems:
nothing
design pattern:
1. command.
2. collision.
###############################################################################
###############################################################################

notes:

all levels found in file named objects.txt. if you want to change levels and more it is 
may be but you must to keep the file format.
so, i will be explain you the file format.
1. beetwen to levels mast be a limit row "######".
2. first row you write only two numbers row and col. 
3. row already writed befor col.
4. after you write tow numbers of row and col. in a a new row write the objects.
5. any object will be wtite in a specify row.
6. to write a objects you write  type position (row ,col).
7. in end of file you must to leave a empty row (without space).
8. all numbers of position is from 0 to N-1. 
9. type noted by strings. G_P for GiftPoint, G_S for GiftShots, G_L for GiftLives, P for Pacman, D_S for SmartDemon, D_R for RandomDemon,     
   W for Wall.
the programe is safty from memory leakage all allocetions is under smart pointers control.

###############################################################################
###############################################################################
