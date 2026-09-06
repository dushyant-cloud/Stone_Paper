# 🪨📄✂️ Stone Paper Scissors

A console-based **Stone Paper Scissors game written in C**, where the player competes against the computer in Best of 3 or Best of 5 matches.

This beginner-friendly project demonstrates C programming concepts including **loops, conditions, functions, strings, random number generation, and file handling**.

## 🎮 Features

* 🪨 Stone, 📄 Paper, and ✂️ Scissors gameplay
* 👤 Player name support
* 🤖 Random computer choices
* 🏆 Automatic winner detection
* 📊 Score tracking
* 🔄 Play Again option
* 🥉 Best of 3 mode
* 🏆 Best of 5 mode
* ⚠️ Invalid input handling
* 📈 Game statistics
* 🏅 Win rate calculation
* 💾 Save statistics to `stats.txt`
* 📜 Game history saved to `game_history.txt`
* 📖 Rules section
* 🏠 Interactive Main Menu
* 🔄 Reset Statistics option
* 🚪 Exit option

## 🛠️ Technologies Used

* **C Programming Language**
* **GCC Compiler**
* Standard C Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`
  * `string.h`

## 📂 Project Structure

```text
stpgame/
│
├── stone_paper.c
├── README.md
├── stats.txt
└── game_history.txt
```

> `stone_paper.exe` is the compiled Windows executable and does not need to be included in the source-code repository.

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Open the Project Folder

```bash
cd stpgame
```

### 3. Compile the Program

Using GCC:

```bash
gcc stone_paper.c -o stone_paper.exe
```

### 4. Run the Game

On Windows PowerShell:

```powershell
.\stone_paper.exe
```

## 🏠 Main Menu

After starting the game, you will see:

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

Enter your choice:
```

### Menu Options

**1. Play Game**
Starts a new Stone Paper Scissors match.

**2. Statistics**
Displays your current wins, losses, matches, and win rate.

**3. Game History**
Displays previously recorded games from `game_history.txt`.

**4. Rules**
Shows the rules of Stone Paper Scissors and the Best of 3/5 modes.

**5. Reset Statistics**
Resets the current statistics after confirmation.

**6. Exit**
Closes the game.

## 🕹️ How to Play

First enter your name:

```text
Enter your name: Dushyant
```

Then select the game mode:

```text
Choose Game Mode:
1. Best of 3
2. Best of 5
```

Choose your move:

```text
1. Stone
2. Paper
3. Scissors
```

The computer will randomly select its move.

## 📜 Rules

| Player      | Computer    | Result           |
| ----------- | ----------- | ---------------- |
| Stone       | Scissors    | 🏆 Player Wins   |
| Paper       | Stone       | 🏆 Player Wins   |
| Scissors    | Paper       | 🏆 Player Wins   |
| Same Choice | Same Choice | 🤝 Draw          |
| Otherwise   | —           | 💻 Computer Wins |

## 🥇 Game Modes

### Best of 3

The first player to reach **2 round wins** wins the match.

```text
===== BEST OF 3 =====

Dushyant: 2
Computer: 1

🎉 YOU WIN THE MATCH!
```

### Best of 5

The first player to reach **3 round wins** wins the match.

```text
===== BEST OF 5 =====

Dushyant: 3
Computer: 2

🎉 YOU WIN THE MATCH!
```

## 📊 Statistics

The game tracks:

* Total matches
* Wins
* Losses
* Win rate

Example:

```text
===== STATISTICS =====
Player: Dushyant
Matches: 5
Wins: 3
Losses: 2
Win Rate: 60.00%
```

## 💾 Saved Statistics

Statistics are saved in:

```text
stats.txt
```

Example:

```text
STONE PAPER SCISSORS - STATISTICS
Player: Dushyant
Matches: 5
Wins: 3
Losses: 2
Win Rate: 60.00%
```

## 📜 Game History

Game results are stored in:

```text
game_history.txt
```

Example:

```text
=================================
Player: Dushyant
Mode: Best of 3
=================================
Round: YOU WIN
Round: DRAW
Round: COMPUTER WINS
FINAL RESULT: Dushyant WON
Final Score: Dushyant 2 - Computer 1
```

## 📚 C Concepts Practiced

This project demonstrates:

* Variables and data types
* `if-else` statements
* `switch-case`
* `while` loops
* `do-while` loops
* Functions
* Pointers
* Arrays and strings
* `scanf()` and `fgets()`
* Random number generation
* Input validation
* File handling
* `FILE` pointers
* `fopen()`
* `fprintf()`
* `fgets()`
* `fclose()`
* Basic game logic

## 🔮 Future Improvements

Planned features:

* [ ] Load previous statistics when the game starts
* [ ] Difficulty levels
* [ ] Leaderboard
* [ ] Two-player mode
* [ ] Achievement system
* [ ] Win streak system
* [ ] Detailed statistics
* [ ] Settings menu
* [ ] Improved input validation
* [ ] Colored console interface

## 👨‍💻 Author

**Dushyant Kumar**

A beginner C programming project created to practice programming fundamentals and develop a console-based game.

---

⭐ **If you like the project, consider giving the repository a star!**