# 🪨📄✂️ Stone Paper Scissors

A beginner-friendly **Stone Paper Scissors game written in C**, progressively upgraded with game modes, player statistics, persistent data, game history, achievements, XP, levels, difficulty-based AI, and a persistent leaderboard system.

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
* Play Again option

### 📊 Statistics

Tracks:

* Total Matches
* Wins
* Losses
* Win Rate
* Current Win Streak
* Best Win Streak
* XP
* Player Level

### 💾 Persistent Data

Player statistics are saved in:

```text
stats.txt
```

Statistics are automatically loaded when the program starts.

---

## 📜 Game History

Every match is stored in:

```text
game_history.txt
```

The history contains:

* Player name
* Difficulty
* Game mode
* Round results
* Final score
* Current streak
* XP
* Level

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

The computer has a 50% chance of choosing a random move and a 50% chance of choosing the move that beats the player's choice.

### Hard

```text
75% Counter Player
25% Random
```

The computer usually counters the player's move but still has a 25% chance of making a random move.

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

## ⭐ XP & Level System

The game includes a progression system.

### XP Rewards

| Event      |      XP |
| ---------- | ------: |
| Match Win  | +100 XP |
| Match Loss |  -25 XP |

XP cannot fall below zero.

### Level Formula

```text
Level = (XP / 500) + 1
```

Therefore:

```text
0–499 XP     → Level 1
500–999 XP   → Level 2
1000–1499 XP → Level 3
1500–1999 XP → Level 4
```

---

## 🔥 Win Streak System

The game tracks consecutive match victories.

It stores:

* Current Win Streak
* Best Win Streak

A loss resets the current streak.

---

## 🏅 Achievements

The game includes several achievements.

### Available Achievements

* 🥇 First Victory
* 🔥 3-Win Streak
* 🔥 5-Win Streak
* 🔥 10-Win Streak
* ⭐ Level 5
* ⭐ Level 10

Achievements are automatically shown as:

```text
[UNLOCKED]
```

or

```text
[LOCKED]
```

---

# 🏆 Leaderboard System

## Feature 13

The game now includes a persistent **Top 10 Leaderboard**.

Players are ranked based on their total XP.

### Leaderboard Displays

* Rank
* Player Name
* XP
* Level
* Wins
* Best Streak

Example:

```text
===============================================================
                     LEADERBOARD
===============================================================
Rank  Player                XP       Level    Wins     Streak
---------------------------------------------------------------
1     Dushyant              1200     3        13       5
2     Alex                  900      2        10       4
3     Rahul                 650      2        8        3
===============================================================
```

### Leaderboard Storage

Leaderboard data is permanently stored in:

```text
leaderboard.txt
```

The leaderboard automatically:

1. Loads existing players
2. Finds the current player
3. Updates their statistics
4. Adds new players
5. Sorts players by XP
6. Keeps the Top 10
7. Saves the updated leaderboard

---

## 🧠 Leaderboard Algorithm

Players are stored using a C structure:

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

The program uses:

```c
qsort()
```

to sort players according to XP.

The player with the highest XP receives:

```text
Rank 1
```

---

## 🖥️ Main Menu

The current main menu contains:

```text
=================================
           MAIN MENU
=================================

1. Play Game
2. Statistics
3. Game History
4. Rules
5. Achievements
6. Leaderboard
7. Reset Statistics
8. Exit
```

---

## 🔄 Game Flow

```text
Start Program
      ↓
Enter Player Name
      ↓
Load Previous Statistics
      ↓
Main Menu
      ↓
Choose Play Game
      ↓
Select Difficulty
      ↓
Select Best of 3 / Best of 5
      ↓
Choose Stone / Paper / Scissors
      ↓
Computer AI
      ↓
Round Result
      ↓
Match Result
      ↓
Update XP
      ↓
Update Level
      ↓
Update Win Streak
      ↓
Save Statistics
      ↓
Update Leaderboard
      ↓
Play Again / Main Menu
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

### File Description

| File               | Purpose                    |
| ------------------ | -------------------------- |
| `stone_paper.c`    | Main C source code         |
| `README.md`        | Project documentation      |
| `stats.txt`        | Personal player statistics |
| `game_history.txt` | Match and round history    |
| `leaderboard.txt`  | Top 10 player leaderboard  |

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

### PowerShell

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
* Progression systems
* Leaderboard algorithms

---

## 🚀 Future Improvements

Possible future features:

* 👥 Two-Player Mode
* 🏆 Advanced Leaderboard
* 🏟️ Tournament Mode
* 👤 Multiple Player Profiles
* ⚙️ Game Settings
* 🎨 Colored Console Interface
* 🕒 Date & Time in Game History
* 📊 Advanced Statistics
* 🪙 Coins and Rewards
* 🎵 Sound Effects
* ⏱️ Timed Challenge Mode
* 🌐 Online Multiplayer
* 🧠 Adaptive AI
* 🎖️ More Achievements

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
🏆 Leaderboard System
```

### Current Version

**Feature 13 — Leaderboard System**

---

## 👨‍💻 Author

**Dushyant Kumar**

Built as a learning project to improve practical C programming, problem-solving, file handling, algorithms, and software development skills.
