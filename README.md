# Bet-Game

A small C++ betting game built with the Doodle library for a first-year CS course (CS120).

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-not%20specified-lightgrey)

## Features

- Scene-based game flow managed through a dedicated `GameScene` system
- Interactive button UI rendered via the Doodle drawing API
- Keyboard-driven input handled through an event hook (`keyReleased.cpp`)
- Self-contained build: SFML and Doodle are bundled — no external install needed
- Single Visual Studio solution for straightforward one-click builds

## Demo

![screenshot](./screenshot.png)

## Built With

- **C++** — course language requirement; used for all game logic, UI, and state management
- **Doodle** — thin graphics wrapper over SFML that simplified window creation and 2D drawing for a first project
- **SFML** — underlying multimedia library providing windowing, events, and rendering; bundled under `proto2/external/`
- **Visual Studio 2019+** — project targets Windows and ships a `.sln` file for zero-config IDE setup

## Getting Started

### Prerequisites

- Windows OS
- Visual Studio 2019 or later

> SFML and Doodle are already bundled under `proto2/external/` — no separate installation required.

### Installation

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

The compiled binary will appear in `proto2/doodle/`.

### Running

Launch from Visual Studio with **Debug › Start Without Debugging** (`Ctrl+F5`), or run the compiled binary directly from the output folder.

Game controls are keyboard-based; see `keyReleased.cpp` for the input mappings. Course-specific context is documented in `proto2/CS120ReadMe.md` and `proto2/CS120Assignment.md`.

## What I Learned

**Splitting a game into scenes before knowing how to do it properly.**
The trickiest part was figuring out how to transition between a menu, a game round, and a result screen without the code collapsing into a single sprawling `main()`. I ended up separating each screen into its own `GameScene` unit (`gameScene.cpp/h`) and driving transitions from a top-level `Game` object (`game.cpp/h`). The approach was crude — no polymorphism, just explicit state checks — but working through *why* that became messy was the real lesson: state needs a single owner, and mixing rendering logic with transition logic makes both harder to change.

**Building a reusable button before knowing what "reusable" means.**
`button.cpp/h` started as copy-pasted draw calls. Pulling it into its own file forced me to decide what data a button actually needs (position, label, hit area) versus what it borrows from the caller (the active Doodle context). Getting that boundary wrong the first time — and then fixing it — made the concept of encapsulation concrete in a way that a lecture slide hadn't.

## License

No license has been specified for this repository.