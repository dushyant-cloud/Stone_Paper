# 🪨📄✂️ Stone Paper Scissors

A feature-rich **Stone Paper Scissors game built in C**.

This project started as a simple console-based game and has gradually evolved into a complete game system with player profiles, persistent statistics, XP, levels, achievements, AI difficulty, leaderboards, multiplayer, tournaments and an advanced statistics dashboard.

---

## 🎮 Features

### Core Gameplay

* 🪨 Stone
* 📄 Paper
* ✂️ Scissors
* Computer opponent
* Best of 3
* Best of 5
* Round-by-round scoring
* Match results

---

## 👤 Player Profiles

* Create profiles
* Select active profile
* Multiple player profiles
* Persistent profile data
* Individual statistics
* Individual XP
* Individual levels
* Individual streaks
* Individual achievements

Profile data is saved in:

```text
profiles.txt
```

---

## 🤖 Computer AI

Three difficulty levels are available.

### Easy

Completely random computer moves.

### Medium

Uses a combination of:

* Random moves
* Counter moves

### Hard

Uses a higher probability of countering the player's move.

---

## 📊 Statistics

Each player has their own statistics:

* Matches played
* Wins
* Losses
* Win rate
* Current streak
* Best streak
* XP
* Level

---

# 📈 Advanced Statistics Dashboard

### Feature 18

A dedicated statistics dashboard provides a detailed overview of the player's performance.

The dashboard includes:

* 🎮 Matches played
* 🏆 Total wins
* ❌ Total losses
* 📈 Win rate
* 📉 Loss rate
* 🔥 Current streak
* 🔥 Best streak
* 🤖 Computer wins
* 🤖 Computer losses
* 👥 Two-player wins
* 🏆 Tournament wins
* ⭐ Current XP
* ⭐ Highest XP
* 📊 Current level
* ⏭️ XP required for next level

Example:

```text
╔══════════════════════════════════════════╗
║       📊 ADVANCED STATISTICS             ║
╠══════════════════════════════════════════╣
║ Player          : Dushyant               ║
║ Level           : 7                      ║
║ XP              : 3425                   ║
║ Highest XP      : 3500                   ║
╠══════════════════════════════════════════╣
║ Matches Played  : 42                     ║
║ Total Wins      : 29                     ║
║ Total Losses    : 13                     ║
║ Win Rate        : 69.05%                 ║
║ Loss Rate       : 30.95%                 ║
╠══════════════════════════════════════════╣
║ Current Streak  : 4                      ║
║ Best Streak     : 9                      ║
╠══════════════════════════════════════════╣
║ Computer Wins   : 29                     ║
║ Computer Losses : 13                     ║
║ 2P Wins         : 3                      ║
║ Tournament Wins : 2                      ║
╚══════════════════════════════════════════╝
```

---

# ⭐ XP & Level System

Players earn:

```text
Match Win  → +100 XP
Match Loss → -25 XP
```

Level calculation:

```text
Level = (XP / 500) + 1
```

The game also tracks the player's highest XP value.

---

# 🔥 Win Streak System

The game tracks:

* Current win streak
* Best win streak

Winning consecutive matches increases the current streak.

Losing resets the current streak.

---

# 🏆 Achievements

Current achievements include:

* 🏆 First Victory
* 🔥 3 Win Streak
* 🔥 5 Win Streak
* 🔥 10 Win Streak
* ⭐ Level 5
* 👑 Level 10

---

# 🏅 Leaderboard

The game maintains a persistent top-10 leaderboard.

Leaderboard displays:

* Rank
* Player
* XP
* Level
* Wins
* Best streak

Leaderboard data is stored in:

```text
leaderboard.txt
```

Players are sorted by XP.

---

# 👥 Two Player Mode

Local multiplayer mode allows two players to compete.

Features:

* Player 1 vs Player 2
* Best of 3
* Best of 5
* Hidden choices
* Round scoring
* Match history
* Two-player statistics

---

# 🏆 Tournament Mode

Four-player elimination tournament.

```text
Player 1 ──┐
           ├── Semi-Final 1 ──┐
Player 2 ──┘                  │
                              ├── 🏆 Champion
Player 3 ──┐                  │
           ├── Semi-Final 2 ──┘
Player 4 ──┘
```

Includes:

* 4 players
* Two semi-finals
* Final
* Best of 3
* Best of 5
* Tournament champion
* Tournament statistics
* Tournament history

---

# 💾 Persistent Data

The project uses file handling to save data.

```text
profiles.txt
leaderboard.txt
game_history.txt
```

### profiles.txt

Stores player profiles and statistics.

### leaderboard.txt

Stores leaderboard data.

### game_history.txt

Stores previous match results.

---

# 📂 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── stone_paper.exe
├── profiles.txt
├── leaderboard.txt
├── game_history.txt
└── README.md
```

The `.txt` files are generated automatically when the game saves data.

---

# 🖥️ Main Menu

```text
1. Play Game
2. Profile Manager
3. Two Player Mode
4. Tournament Mode
5. Statistics
6. Advanced Statistics Dashboard
7. Game History
8. Rules
9. Achievements
10. Leaderboard
11. Reset Profile Statistics
12. Exit
```

---

# ⚙️ Compilation

Make sure GCC is installed.

Open a terminal in the project directory:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

# ▶️ Running the Game

### Windows PowerShell

```powershell
.\stone_paper.exe
```

### Windows CMD

```cmd
stone_paper.exe
```

---

# 🧠 C Programming Concepts Used

This project demonstrates:

* Variables
* Data types
* Conditional statements
* `switch`
* Loops
* Functions
* Arrays
* Strings
* Structures
* `typedef`
* Pointers
* File handling
* `fopen()`
* `fprintf()`
* `fscanf()`
* `fgets()`
* `fclose()`
* `qsort()`
* Random number generation
* `rand()`
* `srand()`
* `time()`
* Persistent data storage
* Basic AI logic
* Menu-driven programming
* Statistics calculations

---

# 📈 Project Progression

```text
1.  Basic Stone Paper Scissors
2.  Play Again
3.  Best of 3 / Best of 5
4.  Player Name
5.  Game Statistics
6.  Game History
7.  Main Menu
8.  Reset Statistics
9.  Persistent Statistics
10. Win Streak
11. Achievements
12. XP System
13. Level System
14. Difficulty Levels
15. Smarter Computer AI
16. Leaderboard
17. Two Player Mode
18. Tournament Mode
19. Player Profiles
20. Advanced Statistics Dashboard
```

---

# 🚀 Future Improvements

Possible future features:

* 🧠 Adaptive AI that learns player patterns
* 🎨 Colored console interface
* ⚙️ Custom game settings
* 👤 Profile rename/delete
* 🔐 Profile PIN/password
* 📊 Statistics graphs
* 🏆 More tournament formats
* 💾 Complete game-state save/load
* 🔊 Sound effects
* 🎵 Background music
* 🌐 Online multiplayer
* 🖥️ GUI version

---

# 👨‍💻 Author

**Dushyant Kumar**

GitHub:

**dushyant-cloud**

---

# 🎯 Project Goal

The project is being developed feature-by-feature to improve C programming and software development skills.

The progression is:

```text
C Fundamentals
       ↓
Functions & Structures
       ↓
File Handling
       ↓
Game Logic
       ↓
AI Logic
       ↓
Persistent Data
       ↓
Player Profiles
       ↓
Statistics
       ↓
Software Design
```

The goal is to turn a simple beginner C game into a polished portfolio project.
