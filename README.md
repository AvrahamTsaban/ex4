# Exercise 4 — Recursion

## Overview

Five recursive algorithms implemented in C without using any loops. Each task demonstrates different recursive techniques including tail recursion, backtracking, and divide-and-conquer. The exercise enforces a strict no-loops policy — all problem-solving logic must be purely recursive.

## Author

Avraham Tsaban

## Compilation

```bash
gcc -Wall -Wextra -Werror -std=c99 ex4.c -o ex4.out -lm -DNDEBUG
```

## Running

```bash
./ex4.out
```

The program presents a menu:

```
1. Reverse a phrase
2. Check Palindrome
3. Generate sentences
4. Solve Zip Board
5. Solve Sudoku
6. Exit
```

## Tasks

1. **Phrase Reversal** — Reverses a user-entered phrase character by character using recursion, with no theoretical limit on input length.
2. **Palindrome Check** — Recursively compares characters from both ends moving toward the center to determine if a phrase is a palindrome.
3. **Sentence Generator** — Generates all possible sentences from user-provided lists of subjects, verbs, and objects (up to 10 terms per category).
4. **Zip Board Puzzle** — Backtracking solver that finds a path visiting all cells exactly once while passing through numbered cells in ascending order (boards up to 20×20).
5. **Sudoku Solver** — Solves standard 9×9 Sudoku puzzles using recursive backtracking with row, column, and subgrid constraint validation.

## Code Structure

All code is in a single file `ex4.c` (829 lines). The file is split: TA-provided scaffolding above the `IMPLEMENTATION` marker, student recursive implementations below it.

### TA-Provided Scaffolding

| Function | Description |
|----------|-------------|
| `main()` | Menu loop — presents 6 options and dispatches to task UI functions. |
| `task1ReversePhrase()` | UI wrapper — prompts user, calls implementation. |
| `task2CheckPalindrome()` | UI wrapper — reads phrase length, calls implementation, prints result. |
| `task3GenerateSentences()` | UI wrapper — reads term lists via `readTerms`, calls implementation. |
| `task4SolveZipBoard()` | UI wrapper — reads board, finds start cell, calls solver, prints solution. |
| `task5SolveSudoku()` | UI wrapper — reads 9×9 grid, calls solver, prints result. |
| `readTerms(terms, maxNum, type)` | Reads a list of terms (subjects/verbs/objects) from input. |
| `printSudoku(board)` | Pretty-prints a Sudoku board with 3×3 separators. |
| `readIntChecked(errorMessage)` | Reads an integer with recursive error recovery. |
| `discardLineRec()` | Recursively discards remaining characters on the input line. |

### Student Implementation (Recursive)

**Task 1 — Reverse:**

| Function | Description |
|----------|-------------|
| `task1ReversePhraseImplementation()` | Reads chars recursively until `\n`, prints them in reverse on unwind. |

**Task 2 — Palindrome:**

| Function | Description |
|----------|-------------|
| `task2CheckPalindromeImplementation(length)` | Reads chars, compares first and last at each recursion level. Returns 1 if palindrome. |

**Task 3 — Sentence Generator:**

| Function | Description |
|----------|-------------|
| `task3GenerateSentencesImplementation(subjects, sCount, verbs, vCount, objects, oCount)` | Entry point — initializes counter and calls `sentencePrinter`. |
| `sentencePrinter(...)` | Recursively generates all subject×verb×object combinations using modular arithmetic. |

**Task 4 — Zip Board:**

| Function | Description |
|----------|-------------|
| `task4SolveZipBoardImplementation(board, solution, size, startR, startC, highest)` | Entry point — initializes step counter and calls `solveZipBoardLoop`. |
| `solveZipBoardLoop(board, solution, size, r, c, highest, nextNum, step)` | Core backtracking — tries U/D/L/R directions, validates via `raisePositionErrors`, backtracks on failure. |
| `raisePositionErrors(board, solution, size, r, c, nextNum)` | Validates a cell: out-of-bounds, already visited, wrong numbered cell. |

**Task 5 — Sudoku:**

| Function | Description |
|----------|-------------|
| `task5SolveSudokuImplementation(board)` | Entry point — starts `solveSudokuLoop` at (0,0). |
| `solveSudokuLoop(board, row, col)` | Walks cells left-to-right, top-to-bottom; dispatches empty cells to `tryAllNumbers`. |
| `tryAllNumbers(board, row, col, num)` | Recursively tries numbers 1–9 for a cell. Returns 1 on first success. |
| `tryNumber(board, row, col, num)` | Places `num` if legal, advances; backtracks (resets to 0) on failure. |
| `isNumberLegal(board, row, col, num)` | Checks row, column, and 3×3 subgrid constraints. |
| `numberOnRow(board, row, col, num)` | Recursively scans a row for `num`. |
| `numberOnCol(board, row, col, num)` | Recursively scans a column for `num`. |
| `numberInSubgrid(board, row, col, startRow, startCol, num)` | Recursively scans a 3×3 subgrid for `num`. |

## Project Files

| File | Description |
|------|-------------|
| `ex4.c` | Source code |
| `ex4.example` | Reference Linux executable provided by the TA |
| `ex4_instructions.md` | Exercise instructions |
| `tests/` | Test cases organized by task (provided by the TA) |

### Test Structure

```
tests/
├── input/
│   ├── palindrome/
│   ├── reverse/
│   ├── sentence/
│   ├── sudoku/
│   └── zip/
└── output/
    ├── palindrome/
    ├── reverse/
    ├── sentence/
    ├── sudoku/
    └── zip/
```

Run a test with:

```bash
./ex4.out < tests/input/palindrome/1.txt
```

## Code Ownership

The source code contains both the TA's scaffolding and the student's implementation. The student's code is marked by:

```c
/***************************
******* IMPLEMENTATION******
***************************/
```

The student was not allowed to modify any "implementation" function signature but could introduce additional helper functions. Two inline comments mark minor changes made to the TA's code for stricter compiler compliance.

## Attribution

The exercise design, specifications, instructions, scaffolding code, and test cases were created by **Itay Shedlezki**, the Teaching Assistant responsible for this assignment. The instructions file (`ex4_instructions.md`), the reference executable (`ex4.example`), and the `tests/` directory are his work. Any license in this repository applies only to the student's code implementation.
