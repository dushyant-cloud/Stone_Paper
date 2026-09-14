# 🪨📄✂️ Stone Paper Scissors

A feature-rich **Stone Paper Scissors game built in C**.

This project started as a simple console-based game and has gradually evolved into a complete game system with profiles, statistics, XP, levels, achievements, AI difficulty, leaderboards, multiplayer and tournaments.

---

## 🎮 Features

### Core Gameplay

* 🪨 Stone
* 📄 Paper
* ✂️ Scissors
* Random computer moves
* Best of 3
* Best of 5
* Round-by-round scoring
* Play against computer

### 👤 Player Profiles

* Create player profiles
* Select active profile
* Multiple profiles
* Persistent profile data
* Individual statistics
* Individual XP
* Individual levels
* Individual win streaks
* Individual best streak
* Persistent profiles using `profiles.txt`

### 🤖 Computer AI

Three difficulty levels:

**Easy**

* Completely random moves

**Medium**

* Combination of random moves and counters

**Hard**

* Higher probability of countering the player's move

### 📊 Statistics

Each player profile stores:

* Matches played
* Wins
* Losses
* Win rate
* Current streak
* Best streak
* XP
* Level

### 🔥 Win Streak System

* Current win streak
* Best win streak
* Streak achievements
* Streak data saved permanently

### ⭐ XP & Level System

Players earn:

* **+100 XP** for winning a match
* **-25 XP** for losing a match

Level calculation:

```text
Level = (XP / 500) + 1
```

### 🏆 Achievements

Current achievements include:

* First Victory
* 3 Win Streak
* 5 Win Streak
* 10 Win Streak
* Level 5
* Level 10

### 🏅 Leaderboard

The game maintains a persistent leaderboard.

Leaderboard includes:

* Rank
* Player
* XP
* Level
* Wins
* Best streak

The top 10 players are displayed.

Leaderboard data is stored in:

```text
leaderboard.txt
```

### 👥 Two Player Mode

Play locally with another player.

Features:

* Player 1 vs Player 2
* Best of 3
* Best of 5
* Hidden player choices
* Independent scoring
* Match history

### 🏆 Tournament Mode

Four-player elimination tournament.

Structure:

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
* Semi-finals
* Final
* Best of 3
* Best of 5
* Tournament champion
* Tournament history

### 💾 Persistent Data

The game automatically stores important information.

Files:

```text
profiles.txt
leaderboard.txt
game_history.txt
```

This means your player progress remains available after closing the program.

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

> `.txt` files are generated automatically when the game saves data.

---

# 🖥️ Main Menu

```text
1. Play Game
2. Profile Manager
3. Two Player Mode
4. Tournament Mode
5. Statistics
6. Game History
7. Rules
8. Achievements
9. Leaderboard
10. Reset Profile Statistics
11. Exit
```

---

# ⚙️ How to Compile

Make sure GCC is installed.

Open the terminal inside the project folder and run:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

# ▶️ How to Run

### Windows PowerShell

```powershell
.\stone_paper.exe
```

### CMD

```cmd
stone_paper.exe
```

---

# 🧠 Concepts Used

This project demonstrates several important C programming concepts:

* Variables
* Data types
* `if/else`
* `switch`
* Loops
* Functions
* Arrays
* Strings
* Structures
* Pointers
* File handling
* `struct`
* `typedef`
* `qsort()`
* Random number generation
* `time()`
* Modular programming
* Persistent data storage
* Basic AI logic
* Menu-driven applications

---

# 📈 Project Progression

The project was developed incrementally:

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
```

---

# 🚀 Future Improvements

Possible future features:

* 🎨 Colored console interface
* 🧠 Adaptive AI that learns player patterns
* 📊 Advanced statistics
* 📈 Win-rate graphs
* 🎮 Custom game settings
* 💾 Save/load complete game state
* 🏆 More tournament formats
* 👤 Profile deletion/rename
* 🔐 Profile PIN/password
* 🌐 Online multiplayer
* 🖥️ GUI version
* 🔊 Sound effects
* 🎵 Background music

---

# 👨‍💻 Author

**Dushyant Kumar**

GitHub:

**dushyant-cloud**

---

# ⭐ Project Goal

The goal of this project is to continuously improve a beginner-level C program into a more complete software project while learning:

```text
C Programming
      ↓
Data Structures
      ↓
File Handling
      ↓
Game Logic
      ↓
AI Logic
      ↓
Persistent Data
      ↓
Software Design
```

This project is being developed feature-by-feature as part of my programming portfolio.
