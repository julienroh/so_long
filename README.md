so_long

A 2D game project developed in C as part of the 42 School curriculum.

📖 About

so_long is a 2D game in which the player navigates through a map, collects all collectibles, and reaches the exit.

The project introduces graphical programming, event handling, map parsing, path validation, and memory management in C using the MiniLibX graphics library.

🎯 Objectives

Create a simple 2D game using MiniLibX.

Parse and validate maps stored in .ber files.

Handle keyboard input and player movement.

Collect every collectible before reaching the exit.

Validate map accessibility and detect invalid configurations.

Manage memory and graphical resources correctly.

🎮 Gameplay Elements

Element

Description

1

Wall — blocks the player's movement

0

Empty space — a walkable tile

P

Player — starting position

C

Collectible — must be collected

E

Exit — reachable after collecting all collectibles

🛠️ Technologies

Language: C

Graphics library: MiniLibX

Build system: Make

Environment: Unix / Linux

Libraries: libft and ft_printf

🚀 Getting Started

Prerequisites

You need a C compiler, make, and the dependencies required by MiniLibX for your system.

Compilation

Clone the repository and enter the project directory:

git clone https://github.com/julienroh/so_long.git
cd so_long

Compile the project:

make

This should generate the so_long executable.

Usage

Run the game with a valid map file:

./so_long map/map.ber

You can use another .ber map by replacing map/map.ber with its path.

Example Map

111111
1P0C01
100001
1C0E01
111111

A valid map must follow the project's validation rules:

The map must be rectangular.

The map must be surrounded by walls.

It must contain exactly one player.

It must contain at least one collectible.

It must contain exactly one exit.

All collectibles and the exit must be reachable by the player.

Controls

Key

Action

W / ↑

Move up

A / ←

Move left

S / ↓

Move down

D / →

Move right

ESC

Close the game

Adjust these controls if your implementation uses different keys.

🧹 Available Make Commands

Command

Description

make

Compile the project

make clean

Remove object files

make fclean

Remove object files and generated build outputs

make re

Rebuild the project from scratch

📁 Project Structure

so_long/
├── includes/
│   └── so_long.h
├── libft/
├── ft_printf/
├── minilibx-linux/
├── map/
│   ├── map.ber
│   └── grande_map.ber
├── src/
│   ├── check_map.c
│   ├── initialize_map.c
│   ├── main.c
│   ├── print_error.c
│   ├── render_map.c
│   ├── utils.c
│   └── window_mlx.c
├── text/
│   ├── c.xpm
│   ├── esc.xpm
│   ├── f.xpm
│   ├── p_d.xpm
│   ├── p_l.xpm
│   ├── p_r.xpm
│   ├── p_u.xpm
│   └── w.xpm
├── Makefile
└── README.md

🧠 Skills Developed

C programming and memory management

Graphical programming with MiniLibX

Map parsing and validation

Event handling and keyboard input

Path validation and algorithmic reasoning

Compilation and project organization with Make

👤 Author

Julien Roh

Computer Science student at 42 Lausanne.

GitHub Profile
