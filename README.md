*This project has been created as part of the 42 curriculum by ldepenne, jleray*

## Description

The objectives of this project are: rigour, the use of the C language, basic algorithms, information retrieval, etc.
Cub3D is a ‘realistic’ 3D graphics project depicting the interior of a maze, viewed from a first-person perspective. This representation is achieved by applying the principles of *ray-casting*.

## Rules

#### The permitted functions are as follows:

• open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday

• All functions in the math library (-lm man man 3 math)

• gettimeofday()

• All functions in the MinilibX library

#### The constraints are as follows for the mandatory part:

• The management of your window must remain smooth: changing to another window minimizing, etc.

• Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).

• the program must be able to set the floor and ceiling colors to two different ones.

• The program displays the image in a window and respects the following rules:<br>

&emsp; -> The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.<br>
&emsp; -> The W, A, S, and D keys must allow you to move the point of view through
the maze.<br>
&emsp; -> Pressing ESC must close the window and quit the program cleanly.<br>
&emsp; -> Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.<br>
&emsp; -> The use of images of the minilibX library is strongly recommended.<br>

• the program must take as a first argument a scene description file with the .cub extension.<br>

&emsp; -> The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.<br>

## Instructions

In order to launch the game you need to have a valid map with valid textures.
A valid map is define by those parameters in the mandatory version :

The map must be a .cub file<br>
4 texture for walls going from NORTH to SOUTH with the .xpm extension<br>
2 color respecting the RBG format in decimal XXX,XXX,XXX for the Ceiling and the Floor<br>
The map must be surrounded by wall and enclose entirely<br>
The map need to contain one player with the letter N,W,E or S.<br>

A valid texture is a texture in .xpm, false xpm will not be accepted.

Once you're map is ready you just need to use the following command in a terminal.

make<br>
```./cub3D ./maps/<your_map>.cub```

In game you have access you the following bindings :

&emsp;W - Forward<br>
&emsp;A - Left<br>
&emsp;D - Right<br>
&emsp;S - Backward<br>
&emsp;← - Rotation Left<br>
&emsp;→ - Rotation Right<br>

If you wish to execute the code with valgrind you can use

```valgrind --leak-check=full --track-fds=yes --track-origin=yes ./cub3D ./maps/<your_map>.cub```


## Ressources

[lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)<br>
The main guide through all the mathematics needed by cub3d, great explanation.

[Gemini](https://gemini.google.com/app?hl=fr)<br>
Used for all type of explanations.

[minilibx](https://github.com/42Paris/minilibx-linux)

## Bonus

### Description

In the bonus section 5 bonus are required in order to get the 125 points. Those bonus are :

&emsp;• Wall collisions.<br>
&emsp;• A minimap system.<br>
&emsp;• Doors which can open and close.<br>
&emsp;• Animated sprites.<br>
&emsp;• Rotate the point of view with the mouse.<br>

In addition to those bonuses we did add some more thing to our bonus.<br>
The first thing beeing the addition of multiple wall from 1 to 6.<br>
The addition of texture for the floor and the ceiling.<br>
The ability for the player to shoot coke bottle to kill the enemies.<br>
Enemies that can kill you if you're to close to you and then make you lose the game.<br>
The door that open if all the enemies are DEAD.<br>

### Instructions

In order to launch the game you need to have a valid map with valid textures.
A valid map is define by those parameters in the mandatory version :

The map must be a .cub file<br>
6 texture for walls going from 1 to 6.<br>
2 texture for the ceiling and the floor.<br>
5 texture in one line for the lutin.<br>
3 texture in one line for the moine.<br>
3 texture in one line for the pirate.<br>
3 texture in one line for the weapon.<br>
All texture must be valid.<br>

The map must be surrounded by wall and enclose entirely
The map need to contain one player with the letter N,W,E or S.

A valid texture is a texture in .xpm, false xpm will not be accepted.

Once you're map is ready you just need to use the following command in a terminal.

make bonus or make reb<br>
```./cub3D_bonus ./maps/<your_map_bonus>.cub```

In game you have access you the following bindings :

&emsp;W - Forward<br>
&emsp;A - Left<br>
&emsp;D - Right<br>
&emsp;S - Backward<br>
&emsp;← - Rotation Left<br>
&emsp;→ - Rotation Right<br>
&emsp;R - Shoot<br>
&emsp;Q - open / close door<br>

mouse rotation left - Rotation Left<br>
mouse rotation right - Rotation Right<br>
left click - Shoot<br>
right click - open / close door<br>

If you wish to execute the code with valgrind you can use

```valgrind --leak-check=full --track-fds=yes --track-origin=yes ./cub3D_bonus ./maps/<your_map_bonus>.cub```