# Dino-Game
Created a Google Dino game clone using oop in C++

Introduction
This documentation provides an overview of the C++ code for a simple console-based Dino Run game. The game includes a dinosaur character that can jump to avoid obstacles (hurdles) and accumulate points. The user interacts with the game through keyboard inputs.

Table of Contents
Prerequisites
Code Overview
Header Files
Global Variables
Class: DinoGame
Public Methods
gotoxy
setcursor
displayScore
init
moveDino
drawHurdle
play
instructions
LoadingBar
Main Function
User Interface
Game Flow
Conclusion
Prerequisites
Before running the Dino Run game, ensure that a C++ compiler is installed on your system. The code uses standard C++ libraries and does not have external dependencies.

Code Overview
Header Files
The code includes several standard C++ header files for input/output, console manipulation, time handling, and file operations. These include <iostream>, <conio.h>, <time.h>, <windows.h>, <stack>, <queue>, <cstdlib>, and <fstream>.

Global Variables
scoreStack: A stack to store and manage the player's scores.
score: The current score of the player.
console: Handle to the console for cursor manipulation.
CursorPosition: Represents the cursor position on the console.
dinoY: Represents the vertical position of the dinosaur.
speed: Controls the speed of the game.
gameover: Indicates whether the game is over.
Class: DinoGame
Public Methods
gotoxy
Description: Positions the cursor at a specified console coordinate.
Parameters: int x, int y - X and Y coordinates.
Usage: Used for drawing and positioning elements on the console.
setcursor
Description: Sets the cursor visibility and size.
Parameters: bool visible, DWORD size - Visibility and size of the cursor.
Usage: Configures the console cursor.
displayScore
Description: Displays the current score on the console and writes it to a file.
Parameters: stack<int> scoreStack, int score - The stack of scores and the current score.
Usage: Updates and shows the score during gameplay.
init
Description: Initializes the game by drawing the boundaries and title on the console.
Usage: Called at the beginning of the game.
moveDino
Description: Moves the dinosaur character on the console.
Parameters: int jump - Controls the dinosaur's jump.
Usage: Animates the dinosaur's movement.
drawHurdle
Description: Draws hurdles on the console and handles collisions.
Usage: Animates and manages the hurdles in the game.
play
Description: Main game loop that processes user input and updates the game state.
Usage: Controls the flow of the game.
instructions
Description: Displays game instructions on the console.
Usage: Called when the user selects the instruction option.
LoadingBar
Description: Displays a loading bar while simulating a loading process.
Usage: Provides visual feedback during initialization.
Main Function
The main function serves as the entry point for the program. It initializes the game, displays a menu, and processes user input to start the game, show instructions, or quit.

User Interface
The user interface is text-based and displayed in the console. It includes a menu with options to start the game, view instructions, or quit. During gameplay, the dinosaur and hurdles are represented using ASCII characters.

Game Flow
The user is presented with a menu to start the game, view instructions, or quit.
If the user chooses to start the game, a loading bar is displayed.
The main game loop initiates, allowing the player to control the dinosaur's movement and jump to avoid hurdles.
The game updates the score, displays it on the console, and writes it to a file.
If the player collides with a hurdle, the game ends, and a game-over message is displayed.
The user can choose to view instructions, which provide details on controls and gameplay.
The user can exit the game at any time by selecting the quit option.
Conclusion
The Dino Run game provides a simple yet entertaining console-based experience. Players can control a dinosaur character, jump to avoid hurdles, and accumulate scores. The code is structured using a class-based approach, making it modular and easy to understand.
