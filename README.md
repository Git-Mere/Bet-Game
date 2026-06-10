# Bet-Game
A small C++ interactive game built with the Doodle library — first-year CS120 course project.

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-not%20specified-lightgrey)

## Description

Bet-Game is a single-assignment project written entirely in C++ as part of the CS120 curriculum. It uses the **Doodle** graphics library (layered on top of **SFML**) to render the game window, handle input, and manage scene transitions. The codebase covers a game loop, scene management, button UI, and keyboard input handling.

> **Demo**
>
> ![demo](<!-- TODO: replace with actual GIF path -->)

## Installation

**Requirements**

- Windows (Visual Studio 2019 or later recommended)
- SFML and Doodle libraries are already bundled under `proto2/external/`

**Steps**

```powershell
# 1. Clone the repository
git clone https://github.com/Git-Mere/Bet-Game.git
cd Bet-Game
```

```
# 2. Open the solution in Visual Studio
proto2/doodle.sln
```

```
# 3. Build the project
# Select Build > Build Solution (Ctrl+Shift+B) in Visual Studio
```

The compiled executable will appear in the output directory configured by the Visual Studio project (`proto2/doodle/`).

## Usage

Run the compiled executable directly from Visual Studio (**Debug > Start Without Debugging**, `Ctrl+F5`) or launch the built binary from the output folder.

Game controls are handled via keyboard input (`keyReleased.cpp`). Refer to `proto2/CS120ReadMe.md` and `proto2/CS120Assignment.md` for course-specific details and assignment requirements.

## License

No license has been specified for this repository.