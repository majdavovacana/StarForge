# StarForge: A 2D Space Puzzle-Strategy Game

## Overview
StarForge is a unique 2D puzzle-strategy game built in C++ using the SFML library. Players navigate a spaceship through treacherous asteroid fields by manipulating gravity wells to alter the ship's trajectory and avoid collisions. The game combines physics-based mechanics with strategic decision-making, offering a fresh take on space exploration puzzles.

This project is open-source and designed for developers and enthusiasts interested in game development, C++ programming, and physics-based gameplay. By sponsoring this project, you support ongoing development, new features, and educational content for the community.

## Features
- **Dynamic Gravity Mechanics**: Place and adjust gravity wells to guide the spaceship through asteroid mazes.
- **Procedural Asteroid Fields**: Each level generates unique asteroid patterns for endless replayability.
- **Minimalist Art Style**: Clean vector graphics with a focus on gameplay over visual clutter.
- **Cross-Platform**: Built with SFML for compatibility on Windows, macOS, and Linux.
- **Modular Codebase**: Well-documented C++ code, ideal for learning and extending.

## Getting Started

### Prerequisites
- **C++ Compiler**: GCC, Clang, or MSVC with C++17 support.
- **SFML Library**: Version 2.5.1 or later (install via package manager or download from [SFML's official site](https://www.sfml-dev.org/)).
- **CMake**: Version 3.10 or later for building the project.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/starforge.git
   cd starforge
   ```
2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```
3. Configure with CMake:
   ```bash
   cmake ..
   ```
4. Build the project:
   ```bash
   cmake --build .
   ```
5. Run the game:
   ```bash
   ./StarForge
   ```

## Gameplay
- **Objective**: Guide the spaceship to the exit portal in each level.
- **Controls**:
  - **WASD**: Move the cursor to place gravity wells.
  - **Left Click**: Place or adjust a gravity well's strength.
  - **Space**: Start/stop the spaceship's movement.
  - **R**: Reset the level.
  - **Esc**: Pause or exit.
- **Mechanics**: Gravity wells attract the spaceship and asteroids. Strategically place wells to curve the ship's path while avoiding collisions.

## Project Structure
- `src/main.cpp`: Entry point and game loop.
- `src/GameObject.hpp`: Base class for game entities (spaceship, asteroids, gravity wells).
- `src/Game.hpp`: Core game logic and rendering.
- `assets/`: Placeholder for textures and fonts (not included; add your own or use SFML defaults).

## Contributing
Contributions are welcome! Please fork the repository, create a feature branch, and submit a pull request. For major changes, open an issue to discuss your ideas.

## Sponsorship
Support StarForge's development through [GitHub Sponsors](https://github.com/sponsors/yourusername)! Your contributions help fund:
- New levels and mechanics.
- Improved physics simulations.
- Tutorials and documentation for aspiring game developers.
- Cross-platform optimizations and testing.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Acknowledgments
- Built with [SFML](https://www.sfml-dev.org/) for graphics and input handling.
- Inspired by physics-based puzzle games and space exploration themes.
- Thanks to the open-source community for feedback and inspiration!

---

**Sponsor StarForge today and help bring this unique game to life!**