<a name="readme-top"></a>

<p align="center">
  <img src="https://raw.githubusercontent.com/AlexisRodriguezCS/GridWord/main/Images/Grid.jpg" alt="Grid" style="display:block;margin:auto;" height="500">
</p>
<h1 align="center">Grid World</h1>

<!-- TABLE OF CONTENTS -->
<p align="center">
  <a href="#about">About The Project</a> •
  <a href="#getting-started">Getting Started</a> •
  <a href="#usage">Usage</a> •
  <a href="#contact">Contact</a>
</p>

<!-- ABOUT THE PROJECT -->
<a name="about"></a>
## About The Project

Welcome to GridWorld! In this world, every person is represented by a number and lives in a square-shaped district, unless they are dead. The world itself is an RxC grid, where each district is identified by its row and column, denoted by r∈{0..R-1} and c∈{0..C-1}. Sometimes, we may refer to a district as Dr,c.

The people in GridWorld are uniquely identified by an integer ID, similar to a social security number. The person IDs start from zero, and each living person resides in a single district. When a world is created, it has no people in it, and every district is a wasteland with no population. However, there are several operations that can be performed on the world once it's created.

The initial configuration of a world is determined by two things: the number of rows (R) and columns (C) in the grid. Once a world is created, it is possible to perform various operations such as adding people to the world or moving them between districts. GridWorld is an exciting and dynamic place, and by performing different operations, we can observe how the world and its inhabitants evolve over time.

Here's an online demo of the project hosted on [repl.it](https://replit.com/@Alexisrz/Grid-World) for you to try out.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
<a name="getting-started"></a>
## Getting Started

To set up a project locally, follow these simple steps.

### Prerequisites

_Software used to run the program._
* [Visusal Studio Code](https://code.visualstudio.com/)

* [MinGW](https://sourceforge.net/projects/mingw/)

* [Git](https://git-scm.com/)

### Installation
_Here's how to install and set up the program._

From your command line:

```bash
# Clone this repository
$ git clone https://github.com/AlexisRodriguezCS/GridWord.git

# Go into the repository
$ cd GridWorld

# Compile code into an executable
$ make build

# Run the program
$ make run
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE -->
<a name="usage"></a>
## Usage

After running the command "make run", the GridWorld Interactive Frontend program will be executed and the following output will be displayed in the terminal/console:

`Welcome to the GridWorld Interactive Frontend`

`COMMANDS:`

- `birth <row> <col>`
- `death <id>`
- `move <id> <targe-row> <target-col>`
- `members <row> <col>`
- `whereis <id>`
- `population`
- `population <row> <col>`
- `num_rows`
- `num_cols`
- `quit`

The following is a comprehensive list of commands available in the GridWorld Interactive Frontend. Each command has a specific function that allows users to interact with the GridWorld program in various ways, using integer values for arguments such as row, column, ID, target row, and target column. Whether it's manipulating individual cells or determining population statistics. **Additionally, it's worth noting that all functions, except for the 'members' function, have a runtime of O(1), making them highly efficient and fast for any size of the grid.**

| Command | Description |
|---------|-------------|
| `birth <row> <col>` | Create a new member at the specified location |
| `death <id>` | Remove the member with the specified ID |
| `move <id> <target-row> <target-col>` | Move the member with the specified ID to the specified location |
| `members <row> <col>` | List the IDs of all members at the specified location |
| `whereis <id>` | Print the location of the member with the specified ID |
| `population` | List the total number of members in the GridWorld |
| `population <row> <col>` | List the number of members at the specified location |
| `num_rows` | Print the number of rows in the GridWorld |
| `num_cols` | Print the number of columns in the GridWorld |
| `quit` | Exit the program |

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
<a name="contact"></a>
## Contact

Alexis Rodriguez - [LinkedIn](https://www.linkedin.com/in/alexisrodriguezcs/) - alexisrodriguezdev@gmail.com

Project Link: [https://github.com/AlexisRodriguezCS/GridWord](https://github.com/AlexisRodriguezCS/GridWord)

<p align="right">(<a href="#readme-top">back to top</a>)</p>
