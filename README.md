# 🪨📄✂️ Stone Paper Scissors

A console-based **Stone Paper Scissors game written in C**.

This project started as a simple beginner C program and has been progressively upgraded with game modes, player statistics, game history, persistent data, a main menu, win streaks, and an achievement system.

---

## 🎮 Features

* 🪨 Stone, Paper and Scissors gameplay
* 👤 Player name input
* 🤖 Computer opponent
* 🎲 Random computer moves
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
* 📜 Game history saved to `game_history.txt`
* 📖 Rules section
* 🏠 Main menu
* 🔄 Reset statistics
* 🔥 Current win streak
* 🏆 Best win streak
* 🎖️ Achievement system
* 🚪 Exit option

---

# 🆕 Latest Feature — Win Streak & Achievements

The game now tracks consecutive match victories.

### 🔥 Current Win Streak

The current streak increases whenever the player wins a match.

Example:

```text
Win → Win → Win
🔥 Current Win Streak: 3
```

If the player loses:

```text
💔 Your 3-match win streak ended!
```

The current streak then returns to:

```text
0
```

---

## 🏆 Best Win Streak

The game also remembers the highest number of consecutive wins ever achieved.

Example:

```text
Current Win Streak: 2
Best Win Streak: 7
```

The best streak remains saved even if the current streak is later broken.

---

# 🎖️ Achievement System

The game now includes achievements.

| Achievement      | Requirement                  |
| ---------------- | ---------------------------- |
| 🏆 First Victory | Win 1 match                  |
| 🔥 3-Win Streak  | Win 3 matches consecutively  |
| 🔥 5-Win Streak  | Win 5 matches consecutively  |
| 🔥 10-Win Streak | Win 10 matches consecutively |

Achievements are permanently recorded through the best streak stored in `stats.txt`.

---

## 🏅 Achievement Menu

The main menu now includes:

```text
5. 🏆 Achievements
```

It displays unlocked and locked achievements.

Example:

```text
=================================
          ACHIEVEMENTS
=================================

🏆 [UNLOCKED] First Victory
🔥 [UNLOCKED] 3-Win Streak
🔥 [LOCKED] 5-Win Streak - Win 5 matches in a row
🔥 [LOCKED] 10-Win Streak - Win 10 matches in a row

Current Streak: 3
Best Streak: 3
```

---

# 🛠️ Technologies Used

* **C Programming**
* GCC Compiler
* Standard C Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`
  * `string.h`

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

| File               | Purpose                           |
| ------------------ | --------------------------------- |
| `stone_paper.c`    | Main game source code             |
| `README.md`        | Project documentation             |
| `stats.txt`        | Stores statistics and streak data |
| `game_history.txt` | Stores previous game results      |

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

# 🏠 Main Menu

The current main menu contains:

```text
=================================
           MAIN MENU
=================================

1. 🎮 Play Game
2. 📊 Statistics
3. 📜 Game History
4. 📖 Rules
5. 🏆 Achievements
6. 🔄 Reset Statistics
7. 🚪 Exit
```

### Menu Options

**1. Play Game**

Starts a new match.

**2. Statistics**

Displays matches, wins, losses, win rate and streak information.

**3. Game History**

Displays previous matches saved in `game_history.txt`.

**4. Rules**

Displays the rules of Stone Paper Scissors.

**5. Achievements**

Displays unlocked and locked achievements.

**6. Reset Statistics**

Resets statistics and streak information.

**7. Exit**

Closes the program.

---

# 🎮 How to Play

Choose:

```text
1. Stone
2. Paper
3. Scissors
```

The computer randomly chooses its move.

The game then determines the winner.

---

# 📖 Rules

| Player Choice | Beats       |
| ------------- | ----------- |
| 🪨 Stone      | ✂️ Scissors |
| 📄 Paper      | 🪨 Stone    |
| ✂️ Scissors   | 📄 Paper    |

If both players choose the same option:

```text
DRAW
```

---

# 🏆 Game Modes

## Best of 3

The first player to reach **2 round wins** wins the match.

```text
Winning Score = 2
```

## Best of 5

The first player to reach **3 round wins** wins the match.

```text
Winning Score = 3
```

---

# 📊 Statistics

The program tracks:

* Total matches
* Wins
* Losses
* Win rate
* Current win streak
* Best win streak

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
🔥 Current Win Streak: 3
🏆 Best Win Streak: 5
```

---

# 💾 Persistent Statistics

Statistics are stored in:

```text
stats.txt
```

Example:

```text
STONE PAPER SCISSORS - STATISTICS
Player: Alex
Matches: 10
Wins: 7
Losses: 3
Win Rate: 70.00%
Current Streak: 3
Best Streak: 5
```

When the program starts, the `loadStatistics()` function reads this file and restores the saved values.

Therefore, statistics and streak information remain available after restarting the game.

---

# 📜 Game History

Every match is stored in:

```text
game_history.txt
```

The history contains:

* Player name
* Game mode
* Round results
* Final result
* Final score
* Current win streak

---

# 🔄 Reset Statistics

The Reset Statistics option resets:

```text
Matches = 0
Wins = 0
Losses = 0
Current Streak = 0
Best Streak = 0
```

A confirmation is required before resetting.

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

---

# 📚 What I Learned

Through this project I practiced:

* Creating functions
* Passing variables using pointers
* Working with strings
* Generating random numbers
* Using loops and conditions
* Creating menu-driven programs
* Reading and writing files
* Saving application data
* Loading saved data
* Tracking game statistics
* Implementing win streak logic
* Creating an achievement system
* Structuring a larger C program

---

# 🚀 Future Improvements

Possible future features:

* 🤖 Difficulty levels
* 🏆 Global leaderboard
* 👥 Two-player mode
* ⚙️ Settings menu
* 🎨 Colored console interface
* 📅 Date and time in game history
* 📈 Advanced statistics
* 🥇 Longest winning streak records
* 🧠 Smarter computer AI
* 👤 Multiple player profiles
* 💰 Points/XP system
* 🛍️ Unlockable themes
* 🎮 Tournament mode
* 💾 Separate save files for players

---

# 📌 Project Status

**Current Version: Feature 10**

The project has evolved from a basic Stone Paper Scissors game into a more complete console application:

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
```

More features will be added progressively.

---

# 👨‍💻 Author

**Dushyant Kumar**

Built as a beginner/intermediate C programming project while learning programming fundamentals.

---

# 📄 License

This project is open for learning and educational purposes.
