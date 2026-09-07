# 🪨📄✂️ Stone Paper Scissors

A console-based **Stone Paper Scissors game written in C**.

This project started as a simple beginner C program and has been gradually upgraded with multiple features including game modes, player statistics, game history, a main menu, and persistent statistics.

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
* 🔄 **Load previous statistics automatically**
* 📜 Game history saved to `game_history.txt`
* 📖 Rules section
* 🏠 Main menu
* 🔄 Reset statistics
* 🚪 Exit option

---

## 🆕 Latest Feature — Load Previous Statistics

The game can now remember your statistics even after the program is closed.

When the program starts, it reads the saved data from:

```text
stats.txt
```

It restores:

* Total matches
* Wins
* Losses
* Win rate

### Example

If the previous session ended with:

```text
Matches: 10
Wins: 7
Losses: 3
```

When the game is opened again, the statistics are automatically loaded.

This makes the game statistics **persistent between sessions**.

---

## 🛠️ Technologies Used

* **C Programming**
* GCC Compiler
* Standard C Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`
  * `string.h`

---

## 📁 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── README.md
├── stats.txt
└── game_history.txt
```

### Files

| File               | Purpose                      |
| ------------------ | ---------------------------- |
| `stone_paper.c`    | Main game source code        |
| `README.md`        | Project documentation        |
| `stats.txt`        | Stores player statistics     |
| `game_history.txt` | Stores previous game results |

---

## ▶️ How to Compile

Open the terminal inside the project folder and run:

```bash
gcc stone_paper.c -o stone_paper.exe
```

---

## ▶️ How to Run

In PowerShell:

```powershell
.\stone_paper.exe
```

---

## 🏠 Main Menu

After entering your name, the game displays:

```text
=================================
           MAIN MENU
=================================

1. 🎮 Play Game
2. 📊 Statistics
3. 📜 Game History
4. 📖 Rules
5. 🔄 Reset Statistics
6. 🚪 Exit
```

### Menu Options

**1. Play Game**

Starts a new Stone Paper Scissors match.

**2. Statistics**

Displays your saved game statistics.

**3. Game History**

Displays previous matches stored in `game_history.txt`.

**4. Rules**

Displays the rules of Stone Paper Scissors.

**5. Reset Statistics**

Resets the current statistics.

**6. Exit**

Closes the program.

---

## 🎮 How to Play

Choose one of the following:

```text
1. Stone
2. Paper
3. Scissors
```

The computer randomly selects its move.

The winner is determined using the standard rules.

---

## 📖 Rules

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

## 🏆 Game Modes

### Best of 3

The first player to reach **2 round wins** wins the match.

```text
Winning Score = 2
```

### Best of 5

The first player to reach **3 round wins** wins the match.

```text
Winning Score = 3
```

---

## 📊 Statistics

The game tracks:

* Total matches
* Wins
* Losses
* Win rate

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
```

---

## 💾 Persistent Statistics

Statistics are saved in:

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
```

When the program starts again, the `loadStatistics()` function reads this file and restores the previous values.

This means your statistics don't disappear when you close the game.

---

## 📜 Game History

Every match is saved in:

```text
game_history.txt
```

The history contains:

* Player name
* Game mode
* Round results
* Final result
* Final score

This allows previous matches to be viewed later.

---

## 🔄 Reset Statistics

The **Reset Statistics** option sets:

```text
Matches = 0
Wins = 0
Losses = 0
```

The program also updates `stats.txt`.

A confirmation is required before resetting.

---

## 🧠 C Concepts Used

This project demonstrates several important C concepts:

* Variables
* Data types
* `if-else`
* `switch`
* `do-while`
* Functions
* Pointers
* Arrays
* Strings
* Structures of program logic
* Random number generation
* File handling
* `fopen()`
* `fprintf()`
* `fscanf()` / `sscanf()`
* `fgets()`
* `fclose()`
* Command-line compilation

---

## 📚 What I Learned

Through this project I practiced:

* Writing functions
* Passing variables using pointers
* Working with strings
* Generating random numbers
* Using loops and conditions
* Creating menu-driven programs
* Reading and writing files
* Saving application data
* Loading saved data when the program starts
* Organizing a larger C program into separate functions

---

## 🚀 Future Improvements

Possible future features:

* 🤖 Difficulty levels
* 🏆 Leaderboard
* 👥 Two-player mode
* 🔥 Win streak tracking
* 🏅 Achievements
* ⚙️ Settings menu
* 🎨 Colored console interface
* 📅 Date and time in game history
* 📈 More detailed statistics
* 🥇 Highest win streak
* 🎯 Player vs Player mode
* 🧠 Smarter computer AI
* 🔐 Multiple player profiles

---

## 👨‍💻 Project Status

**Current Version:** Feature 9

The project has evolved from a basic Stone Paper Scissors program into a menu-driven C application with:

```text
Gameplay
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
```

More features will be added progressively.

---

## 📌 Author

**Dushyant Kumar**

Built as a beginner/intermediate C programming project while learning programming fundamentals.

---

## 📄 License

This project is open for learning and educational purposes.
