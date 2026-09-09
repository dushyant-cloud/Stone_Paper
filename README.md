# 🪨📄✂️ Stone Paper Scissors

A console-based **Stone Paper Scissors game written in C**.

This project started as a simple beginner C program and has been progressively upgraded with game modes, statistics, persistent data, game history, win streaks, achievements, XP, levels, and now a **multi-level computer AI system**.

---

# 🎮 Features

* 🪨 Stone, Paper and Scissors gameplay
* 👤 Player name input
* 🤖 Computer opponent
* 🎲 Random computer moves
* 🧠 Difficulty-based computer AI
* 🟢 Easy difficulty
* 🟡 Medium difficulty
* 🔴 Hard difficulty
* 🏆 Winner detection
* 📊 Match score tracking
* 🔁 Play again option
* 🥉 Best of 3 mode
* 🏅 Best of 5 mode
* ❌ Invalid input handling
* 📈 Game statistics
* 📊 Win-rate calculation
* 💾 Save statistics to `stats.txt`
* 🔄 Load previous statistics automatically
* 📜 Game history
* 📖 Rules section
* 🏠 Main menu
* 🔄 Reset statistics
* 🔥 Current win streak
* 🏆 Best win streak
* 🎖️ Achievement system
* ⭐ XP system
* 🎮 Player levels
* 🆙 Level-up system
* 🚪 Exit option

---

# 🆕 Latest Feature — Difficulty Levels & Smarter AI

The computer opponent now has **three difficulty levels**.

```text
1. Easy
2. Medium
3. Hard
```

The difficulty is selected before every match.

---

# 🤖 Difficulty System

## 🟢 Easy

The computer makes a completely random choice.

```text
Random = 100%
Counter = 0%
```

This mode is suitable for beginners.

---

## 🟡 Medium

The computer has:

```text
50% chance → Random move
50% chance → Counter player's move
```

Example:

```text
Player → Stone
Computer → Paper
```

The computer does not counter every round, making Medium more balanced.

---

## 🔴 Hard

The computer has:

```text
75% chance → Counter player's move
25% chance → Random move
```

Example:

```text
Player → Paper
Computer → Scissors
```

Hard mode is designed to be much more challenging.

The computer does not always counter, preventing the game from becoming completely predictable.

---

# 🧠 Computer AI Logic

The AI is implemented using the function:

```c
int getComputerMove(int player, int difficulty);
```

The function receives:

* Player's move
* Selected difficulty

and returns the computer's move.

### Counter Logic

| Player      | Computer Counter |
| ----------- | ---------------- |
| 🪨 Stone    | 📄 Paper         |
| 📄 Paper    | ✂️ Scissors      |
| ✂️ Scissors | 🪨 Stone         |

---

# 🎮 Game Flow

The current game flow is:

```text
Start Game
    ↓
Choose Difficulty
    ↓
Choose Best of 3 / Best of 5
    ↓
Choose Stone / Paper / Scissors
    ↓
Computer AI selects move
    ↓
Round Result
    ↓
Match Result
    ↓
XP / Level / Streak Update
    ↓
Save Statistics
```

---

# ⭐ XP System

Players receive XP after each match.

| Action  |      XP |
| ------- | ------: |
| 🏆 Win  | +100 XP |
| 💻 Lose |  -25 XP |

XP cannot go below `0`.

---

# 🎖️ Level System

Players start at:

```text
Level 1
XP 0
```

Every `500 XP` increases the player's level.

```text
0 XP       → Level 1
500 XP     → Level 2
1000 XP    → Level 3
1500 XP    → Level 4
2000 XP    → Level 5
```

---

# 🔥 Win Streak

The game tracks consecutive match victories.

Example:

```text
Win → Win → Win

Current Streak: 3
```

A loss resets the current streak.

The highest streak is permanently saved as the **Best Streak**.

---

# 🏆 Achievements

The current achievement system includes:

| Achievement      | Requirement                  |
| ---------------- | ---------------------------- |
| 🏆 First Victory | Win 1 match                  |
| 🔥 3-Win Streak  | Win 3 matches consecutively  |
| 🔥 5-Win Streak  | Win 5 matches consecutively  |
| 🔥 10-Win Streak | Win 10 matches consecutively |
| ⭐ Level 5        | Reach Level 5                |
| 👑 Level 10      | Reach Level 10               |

Achievements can be viewed from:

```text
5. Achievements
```

---

# 📊 Statistics

The Statistics section displays:

* Total matches
* Wins
* Losses
* Win rate
* Current streak
* Best streak
* XP
* Level

Example:

```text
=================================
          STATISTICS
=================================

Player: Alex
Matches: 10
Wins: 7
Losses: 3
Win Rate: 70.00%
Current Win Streak: 3
Best Win Streak: 5
XP: 675
Level: 2

XP needed for next level: 325
```

---

# 📜 Game History

Every completed match is saved to:

```text
game_history.txt
```

The history includes:

* Player name
* Difficulty
* Game mode
* Round results
* Final score
* Final result
* Current streak
* Player level
* Player XP

Example:

```text
=================================
Player: Alex
Difficulty: Hard
Mode: Best of 3
=================================

Round: YOU WIN
Round: COMPUTER WINS
Round: YOU WIN
Round: YOU WIN

FINAL RESULT: Alex WON
Final Score: Alex 2 - Computer 1
Current Streak: 3
Level: 2
XP: 675
```

---

# 💾 Persistent Statistics

Player progress is saved to:

```text
stats.txt
```

Saved information includes:

```text
Player
Matches
Wins
Losses
Win Rate
Current Streak
Best Streak
XP
Level
```

When the game starts, the `loadStatistics()` function restores the previous progress.

---

# 🏠 Main Menu

The current main menu is:

```text
=================================
           MAIN MENU
=================================

1. Play Game
2. Statistics
3. Game History
4. Rules
5. Achievements
6. Reset Statistics
7. Exit
```

---

# 📖 Rules

| Choice      | Beats       |
| ----------- | ----------- |
| 🪨 Stone    | ✂️ Scissors |
| 📄 Paper    | 🪨 Stone    |
| ✂️ Scissors | 📄 Paper    |

Same choices result in a draw.

---

# 🏆 Game Modes

## Best of 3

First player to reach 2 round wins wins the match.

```text
Winning Score = 2
```

## Best of 5

First player to reach 3 round wins wins the match.

```text
Winning Score = 3
```

---

# 🔄 Reset Statistics

Resetting statistics clears:

```text
Matches = 0
Wins = 0
Losses = 0
Current Streak = 0
Best Streak = 0
XP = 0
Level = 1
```

A confirmation is required before resetting.

---

# 📁 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── README.md
├── stats.txt
└── game_history.txt
```

| File               | Purpose                |
| ------------------ | ---------------------- |
| `stone_paper.c`    | Main game source code  |
| `README.md`        | Project documentation  |
| `stats.txt`        | Stores player progress |
| `game_history.txt` | Stores match history   |

---

# 🛠️ Technologies Used

* **C Programming**
* GCC Compiler
* Standard C libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`
  * `string.h`

---

# 🧠 C Concepts Used

This project demonstrates:

* Variables
* Data types
* `if-else`
* `switch`
* `do-while`
* Functions
* Function parameters
* Pointers
* Arrays
* Strings
* Random number generation
* File handling
* `fopen()`
* `fprintf()`
* `sscanf()`
* `fgets()`
* `fclose()`
* Persistent data
* Menu-driven programming
* Randomized algorithms
* Basic AI logic
* Game progression systems

---

# 📚 What I Learned

Through this project I practiced:

* Creating functions
* Passing variables using pointers
* Working with strings
* Generating random numbers
* Reading and writing files
* Saving and loading application data
* Building menu-driven applications
* Tracking statistics
* Implementing win streaks
* Creating achievements
* Implementing XP and levels
* Designing simple game AI
* Using probability to create difficulty levels
* Separating AI logic into its own function

---

# ▶️ How to Compile

Open the terminal inside the project folder:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

# ▶️ How to Run

In PowerShell:

```powershell
.\stone_paper.exe
```

---

# 🚀 Future Improvements

Possible future features:

* 👥 Two-player mode
* 🏆 Leaderboard
* 🤖 More advanced adaptive AI
* 🎮 Tournament mode
* 👤 Multiple player profiles
* ⚙️ Settings menu
* 🎨 Colored console interface
* 📅 Date and time in history
* 📈 Advanced statistics
* 💰 Coins/reward system
* 🛍️ Unlockable themes
* 🎵 Sound effects
* ⏱️ Timed challenge mode
* 🌐 Online multiplayer

---

# 📌 Project Status

**Current Version: Feature 12**

The project has evolved from a basic Stone Paper Scissors game into a progressively developed console application:

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
Achievement System
      ↓
XP System
      ↓
Level System
      ↓
Difficulty Levels
      ↓
Smarter Computer AI
```

---

# 👨‍💻 Author

**Dushyant Kumar**

Built as a C programming project while learning programming fundamentals and software development.

---

# 📄 License

This project is open for learning and educational purposes.
