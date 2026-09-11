# 🪨📄✂️ Stone Paper Scissors

A beginner-friendly **Stone Paper Scissors game written in C**, progressively upgraded with game modes, player statistics, persistent data, game history, achievements, XP, levels, difficulty-based AI, a leaderboard system, and two-player gameplay.

This project demonstrates practical C programming concepts through a complete console-based game.

---

## 🎮 Features

### Basic Gameplay

* Stone, Paper and Scissors
* Player vs Computer
* Random computer moves
* Winner detection
* Round scoring
* Draw detection
* Invalid input handling

### 👤 Player System

* Enter player name
* Personalized game messages
* Persistent player statistics

### 🏆 Game Modes

* Best of 3
* Best of 5
* Play Again
* **Two Player Mode**

### 👥 Two Player Mode

Feature 15 adds local multiplayer gameplay.

Two players can enter their names and compete against each other.

Example:

```text
Player 1: Dushyant
Player 2: Rahul
```

Both players independently select:

```text
1. Stone
2. Paper
3. Scissors
```

The game then reveals both choices and determines the round winner.

### Two Player Game Modes

* Best of 3
* Best of 5
* Draw detection
* Round scoring
* Final match winner
* Match history
* Play another match

---

## 🤖 Difficulty-Based Computer AI

The computer has three difficulty levels.

### Easy

```text
100% Random
```

The computer chooses Stone, Paper or Scissors randomly.

### Medium

```text
50% Random
50% Counter Player
```

### Hard

```text
75% Counter Player
25% Random
```

### Counter System

| Player Move | Computer Counter |
| ----------- | ---------------- |
| Stone       | Paper            |
| Paper       | Scissors         |
| Scissors    | Stone            |

The AI is implemented using:

```c
getComputerMove(int player, int difficulty)
```

---

## 📊 Statistics

The computer-game profile tracks:

* Total Matches
* Wins
* Losses
* Win Rate
* Current Win Streak
* Best Win Streak
* XP
* Player Level

Statistics are stored in:

```text
stats.txt
```

---

## 📜 Game History

All matches are stored in:

```text
game_history.txt
```

The history contains information about:

* Player name
* Difficulty
* Game mode
* Round results
* Final score
* Current streak
* XP
* Level

Two-player matches are also saved with:

* Player 1 name
* Player 2 name
* Game mode
* Round winners
* Final winner
* Final score

---

## ⭐ XP & Level System

### XP Rewards

| Event      |      XP |
| ---------- | ------: |
| Match Win  | +100 XP |
| Match Loss |  -25 XP |

### Level Formula

```text
Level = (XP / 500) + 1
```

Example:

```text
0–499 XP       → Level 1
500–999 XP     → Level 2
1000–1499 XP   → Level 3
1500–1999 XP   → Level 4
```

---

## 🔥 Win Streak System

The game tracks consecutive victories.

It stores:

* Current Win Streak
* Best Win Streak

A loss resets the current streak.

---

## 🏅 Achievements

Available achievements:

* 🥇 First Victory
* 🔥 3-Win Streak
* 🔥 5-Win Streak
* 🔥 10-Win Streak
* ⭐ Level 5
* ⭐ Level 10

---

# 🏆 Leaderboard

The project includes a persistent **Top 10 Leaderboard**.

Players are ranked according to XP.

### Leaderboard Displays

* Rank
* Player Name
* XP
* Level
* Wins
* Best Streak

Leaderboard data is stored in:

```text
leaderboard.txt
```

The program uses:

```c
qsort()
```

to rank players by XP.

---

## 🧠 C Structure Used for Leaderboard

```c
struct Player {
    char name[50];
    int wins;
    int losses;
    int xp;
    int level;
    int bestStreak;
};
```

---

## 👥 Two Player Architecture

The Two Player Mode uses separate variables for both players:

```text
Player 1
   ↓
Choose Move
   ↓
Player 2
   ↓
Choose Move
   ↓
Compare Moves
   ↓
Round Winner
   ↓
Update Score
   ↓
Match Winner
```

The two-player mode is implemented using:

```c
twoPlayerMode()
```

---

## 🖥️ Main Menu

The current main menu contains:

```text
=================================
           MAIN MENU
=================================

1. Play Game
2. Two Player Mode
3. Statistics
4. Game History
5. Rules
6. Achievements
7. Leaderboard
8. Reset Statistics
9. Exit
```

---

## 🔄 Complete Game Flow

```text
Start Program
      ↓
Enter Player Name
      ↓
Load Previous Statistics
      ↓
Main Menu
      ↓
 ┌───────────────┬────────────────┐
 ↓               ↓
Play Game     Two Player Mode
 ↓               ↓
Difficulty     Player Names
 ↓               ↓
Best of 3/5    Best of 3/5
 ↓               ↓
Player Move    P1 + P2 Moves
 ↓               ↓
Computer AI    Compare Moves
 ↓               ↓
Round Result   Round Result
 ↓               ↓
Match Result   Match Result
 ↓               ↓
XP / Level     Save History
 ↓
Streak
 ↓
Save Statistics
 ↓
Update Leaderboard
```

---

## 📁 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── README.md
├── stats.txt
├── game_history.txt
└── leaderboard.txt
```

| File               | Purpose                |
| ------------------ | ---------------------- |
| `stone_paper.c`    | Main C source code     |
| `README.md`        | Project documentation  |
| `stats.txt`        | Personal statistics    |
| `game_history.txt` | Game and match history |
| `leaderboard.txt`  | Top 10 leaderboard     |

---

## ⚙️ Requirements

* C Compiler
* GCC / MinGW / MSYS2
* Windows, Linux or macOS
* Terminal / Command Prompt

---

## 🛠️ Compilation

Using GCC:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

## ▶️ Run

### Windows PowerShell

```powershell
.\stone_paper.exe
```

### Linux/macOS

```bash
./stone_paper
```

---

## 📚 C Concepts Used

This project demonstrates:

* Variables
* Data types
* Operators
* Conditional statements
* `if-else`
* `switch`
* Loops
* Functions
* Arrays
* Strings
* Structures
* Pointers
* File handling
* `fopen()`
* `fclose()`
* `fprintf()`
* `fscanf()`
* `fgets()`
* `sscanf()`
* Random number generation
* `rand()`
* `srand()`
* `time()`
* String handling
* Sorting
* `qsort()`
* Persistent data
* Randomized algorithms
* Basic AI logic
* Multiplayer game logic
* Progression systems
* Leaderboard algorithms

---

## 🚀 Future Improvements

Possible future features:

* 🏟️ Tournament Mode
* 📊 Advanced Statistics
* 👤 Multiple Player Profiles
* ⚙️ Game Settings
* 🕒 Date & Time in Game History
* 🪙 Coins and Rewards
* 🎨 Colored Console Interface
* 🎵 Sound Effects
* ⏱️ Timed Challenge Mode
* 🧠 Adaptive AI
* 🌐 Online Multiplayer

---

## 📈 Project Progress

```text
Basic Gameplay
      ↓
Best of 3 / Best of 5
      ↓
Player Name
      ↓
Statistics
      ↓
Game History
      ↓
Main Menu
      ↓
Reset Statistics
      ↓
Persistent Statistics
      ↓
Win Streak
      ↓
Achievements
      ↓
XP System
      ↓
Level System
      ↓
Difficulty Levels
      ↓
Smarter Computer AI
      ↓
Leaderboard
      ↓
👥 Two Player Mode
```

### Current Version

**Feature 15 — Two Player Mode**

---

## 👨‍💻 Author

**Dushyant Kumar**

Built as a learning project to improve practical C programming, problem-solving, file handling, algorithms, AI logic, and software development skills.
