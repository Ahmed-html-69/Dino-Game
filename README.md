# Dino-Game
Created a Google Dino game clone using oop in C++

Introduction

This documentation provides an overview of the C++ code for a simple console-based Dino Run game. 
The game includes a dinosaur character that can jump to avoid obstacles (hurdles) and accumulate points. 
The user interacts with the game through keyboard inputs.

Before running the Dino Run game, ensure that a C++ compiler is installed on your system. The code uses standard C++ libraries and does not have external dependencies.

Code Overview
Header Files
The code includes several standard C++ header files for input/output, console manipulation, time handling, and file operations.
These include <iostream>, <conio.h>, <time.h>, <windows.h>, <stack>, <queue>, <cstdlib>, and <fstream>.


User Interface
The user interface is text-based and displayed in the console.
It includes a menu with options to start the game, view instructions, or quit.
During gameplay, the dinosaur and hurdles are represented using ASCII characters.

Game Flow
The user is presented with a menu to start the game, view instructions, or quit.
If the user chooses to start the game, a loading bar is displayed.
The main game loop initiates, allowing the player to control the dinosaur's movement and jump to avoid hurdles.
The game updates the score, displays it on the console, and writes it to a file.
If the player collides with a hurdle, the game ends, and a game-over message is displayed.
The user can choose to view instructions, which provide details on controls and gameplay.
The user can exit the game at any time by selecting the quit option.

Conclusion
The Dino Run game provides a simple yet entertaining console-based experience.
Players can control a dinosaur character, jump to avoid hurdles, and accumulate scores. 
The code is structured using a oop class-based approach, making it modular and easy to understand.
