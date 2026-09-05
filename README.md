# 🪨📄✂️ Stone Paper Scissors

A console-based **Stone Paper Scissors game written in C**, where the player competes against the computer in Best of 3 or Best of 5 matches.

The project is designed as a beginner-friendly C programming project and demonstrates concepts such as loops, conditions, functions, random numbers, strings, and file handling.

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
* 🎯 Final match result

## 🛠️ Technologies Used

* **C Programming Language**
* GCC Compiler
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

## 🕹️ How to Play

First enter your name:

```text
Enter your name: Dushyant
```

Then select the match format:

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

The computer randomly selects its move.

### Rules

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

The game keeps track of your performance during the current program session.

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

The program saves statistics in:

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

Every round and match result is stored in:

```text
game_history.txt
```

Example:

```text
=================================
Player: Dushyant
Mode: Best of 3
=================================
Round: You = Stone | Computer = Scissors | Result = WIN
Round: You = Paper | Computer = Stone | Result = WIN
FINAL RESULT: Dushyant WON
Final Score: Dushyant 2 - Computer 0
```

## 📚 C Concepts Practiced

This project helps practice:

* Variables and data types
* `if-else` statements
* `while` and `do-while` loops
* User input with `scanf()` and `fgets()`
* Character arrays and strings
* Random number generation
* Input validation
* Score calculation
* File handling
* `FILE` pointers
* `fopen()`
* `fprintf()`
* `fclose()`
* Basic game logic

## 🔮 Future Improvements

Planned features:

* [ ] Load previous statistics when the game starts
* [ ] Difficulty levels
* [ ] Main menu
* [ ] Leaderboard
* [ ] Reset statistics option
* [ ] Improved input validation
* [ ] Multiplayer mode
* [ ] Colored console interface
* [ ] Game statistics menu

## 👨‍💻 Author

**Dushyant Kumar**

A beginner C programming project created to practice programming fundamentals and build a small console-based game.

---

⭐ **If you like the project, consider giving the repository a star!**
