# so_long

A small 2D game developed in C as part of the 42 School curriculum.

## 📖 About

**so_long** is a 2D game project in which the player must navigate a map, collect all collectibles, and reach the exit while avoiding obstacles.

The project introduces graphical programming, event handling, map parsing, path validation, and memory management in C using the MiniLibX graphics library.

## 🎮 Gameplay

The objective is to collect every collectible on the map and reach the exit using as few moves as possible.

- 🧍 **Player:** Control the character and navigate the map.
- 💎 **Collectibles:** Collect all items before reaching the exit.
- 🚪 **Exit:** Unlock the exit by collecting every item.
- 🧱 **Walls:** Walls block the player's movement.
- 🗺️ **Map:** Explore a map made of walls, empty spaces, collectibles, the player, and the exit.

## ✨ Features

- 2D graphical window using MiniLibX.
- Keyboard input and real-time player movement.
- Map parsing from a `.ber` file.
- Map validation and error handling.
- Collectible tracking and exit conditions.
- Move counter displayed in the terminal.
- Memory management and resource cleanup.

## 🛠️ Technologies

- **Language:** C
- **Graphics:** MiniLibX
- **Build system:** Make
- **Platform:** Unix/Linux
- **Version control:** Git

## 📋 Requirements

Before building the project, make sure you have:

- A C compiler, such as `cc` or `gcc`.
- `make`.
- The MiniLibX library and its required system dependencies.
- A Unix/Linux environment supported by your MiniLibX version.

## 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/julienroh/so_long.git
cd so_long
```

Build the project:

```bash
make
```

This should generate the game executable.

## 🕹️ Usage

Run the game with a valid map file:

```bash
./so_long maps/map.ber
```

Replace `maps/map.ber` with the path to your own valid map.

## 🗺️ Map Format

Maps are stored in `.ber` files and consist of the following characters:

| Character | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player starting position |
| `C` | Collectible |
| `E` | Exit |

A valid map must satisfy the project's validation rules, including:

- The map must be rectangular.
- The map must be surrounded by walls.
- It must contain exactly one player starting position.
- It must contain at least one collectible.
- It must contain exactly one exit.
- Every collectible and the exit must be reachable by the player.

### Example Map

```text
111111
1P0C01
100001
1C0E01
111111
```

## 🎮 Controls

| Key | Action |
|---|---|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Close the game |

*Controls may vary depending on the implementation.*

## 🧰 Makefile Commands
