# Dino Run Game

Dino Run is a console-based game implemented in C++. The game features a dinosaur character that can jump to avoid hurdles and accumulate points. It provides a simple and entertaining experience for users.

## Table of Contents
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
  - [Installation](#installation)
  - [Running the Game](#running-the-game)
- [Gameplay](#gameplay)
- [Code Structure](#code-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Prerequisites
Ensure that you have a C++ compiler installed on your system to compile and run the game.

## Getting Started

### Installation
Clone the repository to your local machine using the following command:
```bash
git clone https://github.com/your-username/dino-run-game.git
```

### Running the Game
1. Navigate to the project directory.
2. Compile the source code using a C++ compiler.
   ```bash
   g++ dino_run_game.cpp -o DinoRunGame
   ```
3. Run the executable.
   ```bash
   ./DinoRunGame
   ```

## Gameplay
- Use the spacebar to make the dinosaur jump and avoid hurdles.
- Press 'p' to pause the game.
- Press 'Escape' to exit the game.

## Code Structure
The code is organized using a class-based approach. Here are some key components:
- **DinoGame Class**: Manages game-related functions such as initializing the game, moving the dinosaur, drawing hurdles, and handling gameplay logic.
- **Main Function**: Serves as the entry point for the program. It displays a menu, processes user input, and starts the game or shows instructions.

## Contributing
Contributions are welcome! If you'd like to enhance the game or fix any issues, feel free to fork the repository and submit a pull request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements
- Inspired by the classic Google Chrome offline dinosaur game.
- ASCII art for the dinosaur character and hurdles.
