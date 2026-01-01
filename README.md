# Exercise 4 - Recursion

## Author Information
- **Name**: Avraham Tsaban
- **Course**: Introduction to Computer Science (CSI)
- **Exercise**: ex4

## Course Information
- **Teaching Assistant**: Itay Shedlezki
- **Submission Deadline**: 24.12.25 at 23:59:59

## Project Description
This project implements five recursive algorithms without using loops. Each task demonstrates different recursive techniques including tail recursion, backtracking, and divide-and-conquer approaches.

### Implemented Tasks

#### 1. Phrase Reversal
Reverses a user-entered phrase character by character using recursion. The function reads input until a newline is encountered, then prints the characters in reverse order as the recursion unwinds.

**Features:**
- No theoretical limit on input length
- Handles spaces as regular characters
- Pure recursive implementation

#### 2. Palindrome Check
Determines whether a given phrase reads the same forwards and backwards using recursive comparison of first and last characters at each recursion level.

**Features:**
- Compares characters from both ends moving toward center
- Returns true for empty strings and single characters
- Handles phrases of any length up to MAX_INT

#### 3. Sentence Generator
Generates all possible sentences from user-provided lists of subjects, verbs, and objects using recursion to iterate through all combinations.

**Features:**
- Supports up to 10 terms per category
- Maximum term length of 20 characters
- Maintains consistent ordering (subjects → verbs → objects)

#### 4. Zip Board Puzzle Solver
Solves a path-finding puzzle where you must visit all cells exactly once while passing through numbered cells in ascending order.

**Features:**
- Backtracking algorithm with four directions (U/D/L/R)
- Supports boards up to 20×20
- Validates path constraints at each step

#### 5. Sudoku Solver
Solves standard 9×9 Sudoku puzzles using recursive backtracking to fill empty cells while maintaining row, column, and 3×3 subgrid constraints.

**Features:**
- Validates number placement across row, column, and subgrid
- Efficient backtracking with early termination
- Explores solutions left-to-right, top-to-bottom

## Compilation

The project uses a strict compilation command with extensive warnings and optimizations:

```bash
gcc -lm -std=c99 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wstrict-overflow=2 -Wwrite-strings -Wcast-align -Wpointer-arith -Werror -Wconversion -O2 -DNDEBUG ex4.c -o ex4.out
```

### Compilation Flags Explanation:
- `-std=c99`: Use C99 standard
- `-Wall -Wextra -Wpedantic`: Enable all warnings
- `-Wshadow`: Warn on variable shadowing
- `-Wformat=2`: Check printf/scanf format strings
- `-Wwrite-strings`: Warn on string literal modifications
- `-Werror`: Treat all warnings as errors
- `-O2`: Optimization level 2
- `-DNDEBUG`: Disable debug assertions

## Usage

### Running the Program
```bash
./ex4.out
```

### Example Files
The repository includes:
- **ex4.example**: Sample executable for reference (run example with input/output)
- **ex4.out**: Compiled executable from the strict compilation command
- **tests/**: Directory containing test cases organized by task
  - **input/**: Sample input files
  - **output/**: Expected output files

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

### Running Tests
You can test your implementation against the provided test cases:
```bash
./ex4.out < tests/input/palindrome/1.txt
```

## Menu Options
When you run the program, you'll see:
```
1. Reverse a phrase
2. Check Palindrome
3. Generate sentences
4. Solve Zip Board
5. Solve Sudoku
6. Exit
```

## Implementation Notes

### Recursion Requirements
- **NO LOOPS** allowed in implementation (except for menu display and I/O in provided code)
- All problem-solving logic must use recursion
- Helper functions with additional parameters are allowed
- Maximum runtime: 60 seconds per test case

### Code Style Requirements
- **Line Length**: All lines are strictly kept under 120 characters as per course requirements
- This constraint is maintained rigorously, even at the expense of code readability in some cases
- Function declarations and complex expressions may be split across multiple lines to comply

### Code Structure
Each task follows this pattern:
- `task{N}{Name}()`: User interface function (reads input, displays output)
- `task{N}{Name}Implementation()`: Core recursive logic
- Additional helper functions as needed

### Function Signatures
The provided function signatures must not be modified, but helper functions can be added with any appropriate parameters for recursive implementation.

## Performance Considerations
- The program must complete within 60 seconds for any test case
- Efficient backtracking is used to minimize unnecessary recursive calls
- Early termination conditions prevent exploring invalid branches

## Credits
- **Exercise Design**: Itay Shedlezki
- **Course**: Introduction to Computer Science, Bar-Ilan University
- **Year**: 2025/2026


## Code author: 
This code contains Shedlezki's code and mine. My code is under the following sign:
/***************************
******* IMPLEMENTATION******
***************************/
But I was not allowed to edit any "implementation" function signature (I was allowed to introduce my own inner implementation function). So, credits are mixed (hence I cannot allow redistribution of this work).
Two inline comments point to lines I changed insid his code on release version, in order to adhere to stricter compiler guidance.

## Repository
This project is part of the CSI-BIU/ex4 repository.

## Additional Resources
- Full exercise instructions: `ex4 - 2026.md`
- Test cases available in `tests/` directory
- Example executable: `ex4.example`

---

**Note**: This implementation strictly adheres to the course coding standards and recursion requirements. No warnings or errors are produced during compilation with the strict flags listed above.
