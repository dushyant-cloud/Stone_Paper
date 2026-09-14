# 🪨📄✂️ Stone Paper Scissors

A beginner-friendly **Stone Paper Scissors game written in C**, progressively upgraded with multiple game modes, player statistics, persistent data, game history, achievements, XP, levels, difficulty-based AI, leaderboard rankings, two-player gameplay, and tournament mode.

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

* Player name
* Personalized game messages
* Persistent statistics

### 🏆 Game Modes

* Best of 3
* Best of 5
* Play Again
* Player vs Computer
* Two Player Mode
* **Tournament Mode**

---

# 👥 Two Player Mode

Two players can compete locally on the same computer.

Example:

```text
Player 1: Dushyant
Player 2: Rahul
```

Both players choose:

```text
1. Stone
2. Paper
3. Scissors
```

The program hides Player 1's selection before Player 2 chooses and then reveals both moves.

### Available Formats

* Best of 3
* Best of 5

Two-player matches are automatically stored in the game history.

---

# 🏟️ Tournament Mode

## Feature 16

The project now includes a **4-player knockout tournament system**.

Four players enter the tournament and compete through:

```text
Semi-Final 1
      ↓
Semi-Final 2
      ↓
    FINAL
      ↓
  CHAMPION
```

### Tournament Bracket

```text
Player 1 ───┐
            ├── Winner ───┐
Player 2 ───┘             │
                          ├── 🏆 Champion
Player 3 ───┐             │
            ├── Winner ───┘
Player 4 ───┘
```

### Tournament Features

* 4 players
* Two semi-finals
* One final
* Best of 3
* Best of 5
* Round scoring
* Draw handling
* Automatic advancement
* Champion announcement
* Tournament history
* Match results saved to `game_history.txt`

### Tournament Flow

```text
Register 4 Players
        ↓
Choose Best of 3 / Best of 5
        ↓
Semi-Final 1
        ↓
Semi-Final 2
        ↓
Final
        ↓
Tournament Champion
```

Tournament matches use the same Stone Paper Scissors rules as the normal game.

---

# 🤖 Difficulty-Based Computer AI

The computer has three difficulty levels.

### Easy

```text
100% Random
```

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

# 📊 Statistics

The computer-game profile tracks:

* Total Matches
* Wins
* Losses
* Win Rate
* Current Win Streak
* Best Win Streak
* XP
* Level

Statistics are stored in:

```text
stats.txt
```

---

# 📜 Game History

All game activity is stored in:

```text
game_history.txt
```

The history can contain:

### Computer Matches

* Player name
* Difficulty
* Game mode
* Round results
* Final score
* XP
* Level
* Streak

### Two Player Matches

* Player 1
* Player 2
* Game mode
* Round winners
* Final winner
* Final score

### Tournament Matches

* Tournament players
* Tournament format
* Semi-final results
* Final result
* Tournament champion

---

# ⭐ XP & Level System

### XP Rewards

| Event               |   XP |
| ------------------- | ---: |
| Computer Match Win  | +100 |
| Computer Match Loss |  -25 |

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

# 🔥 Win Streak System

The game tracks consecutive computer-game victories.

It stores:

* Current Win Streak
* Best Win Streak

A loss resets the current streak.

---

# 🏅 Achievements

Available achievements:

* 🥇 First Victory
* 🔥 3-Win Streak
* 🔥 5-Win Streak
* 🔥 10-Win Streak
* ⭐ Level 5
* ⭐ Level 10

Achievements are displayed as:

```text
[UNLOCKED]
```

or:

```text
[LOCKED]
```

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

to sort players according to XP.

---

# 🧠 Data Structure

Leaderboard players are represented using a C structure:

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

# 🖥️ Main Menu

The current main menu contains:

```text
=================================
           MAIN MENU
=================================

1. Play Game
2. Two Player Mode
3. Tournament Mode
4. Statistics
5. Game History
6. Rules
7. Achievements
8. Leaderboard
9. Reset Statistics
10. Exit
```

---

# 🔄 Complete Game Architecture

```text
                    START
                      ↓
               Enter Player Name
                      ↓
             Load Saved Statistics
                      ↓
                  MAIN MENU
                      ↓
       ┌──────────────┼──────────────┐
       ↓              ↓              ↓
   Play Game      Two Player      Tournament
       ↓              ↓              ↓
   Difficulty      P1 vs P2       4 Players
       ↓              ↓              ↓
   Best of 3/5     Best of 3/5   Semi-Finals
       ↓              ↓              ↓
   Computer AI     Round Result      Final
       ↓              ↓              ↓
   Match Result    Match Winner     Champion
       ↓
   XP / Level
       ↓
    Streak
       ↓
Save Statistics
       ↓
Update Leaderboard
       ↓
Game History
```

---

# 📁 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── README.md
├── stats.txt
├── game_history.txt
└── leaderboard.txt
```

| File               | Purpose                     |
| ------------------ | --------------------------- |
| `stone_paper.c`    | Main C source code          |
| `README.md`        | Project documentation       |
| `stats.txt`        | Personal statistics         |
| `game_history.txt` | Game and tournament history |
| `leaderboard.txt`  | Top 10 leaderboard          |

---

# ⚙️ Requirements

* C Compiler
* GCC / MinGW / MSYS2
* Windows, Linux or macOS
* Terminal / Command Prompt

---

# 🛠️ Compilation

Using GCC:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

# ▶️ Run

### Windows PowerShell

```powershell
.\stone_paper.exe
```

### Linux/macOS

```bash
./stone_paper
```

---

# 📚 C Concepts Used

This project demonstrates:

* Variables
* Data types
* Operators
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
* Multiplayer logic
* Tournament algorithms
* Game progression systems
* Leaderboard algorithms

---

# 🚀 Future Improvements

Possible future features:

* 📊 Advanced Statistics
* 👤 Multiple Player Profiles
* ⚙️ Game Settings
* 🕒 Date & Time in History
* 🪙 Coins and Rewards
* 🎨 Colored Console Interface
* 🎵 Sound Effects
* ⏱️ Timed Challenge Mode
* 🧠 Adaptive AI
* 🌐 Online Multiplayer

---

# 📈 Project Progress

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
Two Player Mode
      ↓
🏟️ Tournament Mode
```

## Current Version

**Feature 16 — Tournament Mode**

---

# 👨‍💻 Author

**Dushyant Kumar**

Built as a learning project to improve practical C programming, problem-solving, file handling, algorithms, AI logic, multiplayer systems, and software development skills.
