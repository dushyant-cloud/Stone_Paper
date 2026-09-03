# 🪨📄✂️ Stone Paper Scissors

A simple **Stone Paper Scissors game written in C**.
The player competes against the computer, which makes a random choice each round.

## 🎮 Features

## 🎮 Features

- 🪨 Stone, 📄 Paper, and ✂️ Scissors choices
- 🤖 Random computer choice
- 🏆 Winner detection
- 📊 Score tracking
- 🔄 Play Again option
- 🥇 Best of 3 mode
- 🏆 Best of 5 mode
- 👤 Player name support
- 👤 Player Statistics
- ⚠️ Invalid input handling
- 🎯 Final match result

## 🛠️ Technologies Used

* **C**
* Standard C Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`

## 📂 Project Structure

```text
StonePaperScissors/
│
├── stone_paper.c
└── README.md
```

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Open the project folder

```bash
cd StonePaperScissors
```

### 3. Compile the program

Using GCC:

```bash
gcc stone_paper.c -o game
```

### 4. Run the game

**Windows:**

```bash
game.exe
```

**Linux/macOS:**

```bash
./game
```

## 🕹️ How to Play

Choose one of the following:

```text
1. Stone
2. Paper
3. Scissors
```

The computer will randomly select its choice.

### Rules

| Your Choice | Computer Choice | Result           |
| ----------- | --------------- | ---------------- |
| Stone       | Scissors        | 🏆 You Win       |
| Paper       | Stone           | 🏆 You Win       |
| Scissors    | Paper           | 🏆 You Win       |
| Same choice | Same choice     | 🤝 Draw          |
| Otherwise   | —               | 💻 Computer Wins |

## 📸 Example

```text
===== STONE PAPER SCISSORS =====

Enter number of rounds: 3

--- Round 1 ---
1. Stone
2. Paper
3. Scissors

Enter your choice: 1

Computer chose: Scissors
Result: YOU WIN!

===== FINAL RESULT =====

Your Score: 2
Computer Score: 1

🎉 YOU ARE THE WINNER!
```

## 📚 Concepts Practiced

This project was created to practice basic C programming concepts:

* Variables and data types
* `if-else` statements
* `for` loops
* User input/output
* Random number generation
* Input validation
* Score calculation
* Basic game logic

## 🔮 Future Improvements

Possible features for future versions:

* [ ] Play Again option
* [ ] Player name
* [ ] Best of 3 / Best of 5 mode
* [ ] Game statistics
* [ ] Game history
* [ ] Save scores to a file
* [ ] Difficulty levels
* [ ] Leaderboard

## 👨‍💻 Author

**Dushyant Kumar**

A beginner C project created while learning and practicing programming.

---

⭐ If you found this project useful, consider giving the repository a star!
