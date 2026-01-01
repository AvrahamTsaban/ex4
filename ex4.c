/******************
Name:Avraham Tsaban
ID: 207088733
Assignment: 4
*******************/

#include <stdio.h>
#include <string.h>

/***************************
******** Menu Items ********
****************************/

#define REVERSE 1
#define PALINDROME 2
#define SENTENCES 3
#define ZIP 4
#define SUDOKU 5
#define EXIT 6


/***************************
*** DIMENSION PARAMETERS ***
****************************/

#define LONGEST_TERM 20
#define LONGEST_SENTENCE 62
#define MAX_NUMBER_OF_TERMS 10

#define ZIP_MAX_GRID_SIZE 20

#define SUDOKU_GRID_SIZE 9
#define SUDOKU_SUBGRID_SIZE 3
#define GRID_START 0
#define SUDOKU_MIN_VALUE 1
#define SUDOKU_MAX_VALUE 9


/***************************
* USER INTERFACE PROTOTYPES *
****************************/

/**
 * @brief User interface for Task 1: Reverse a phrase
 * 
 * Prompts the user to enter a phrase and displays its reversed version.
 */
void task1ReversePhrase();

/**
 * @brief User interface for Task 2: Check if a phrase is a palindrome
 * 
 * Prompts the user for the phrase length and the phrase itself,
 * then checks and displays whether it is a palindrome.
 */
void task2CheckPalindrome();

/**
 * @brief User interface for Task 3: Generate sentences from word lists
 * 
 * Prompts the user for lists of subjects, verbs, and objects,
 * then generates and displays all possible sentence combinations.
 */
void task3GenerateSentences();

/**
 * @brief User interface for Task 4: Solve a Zip Board puzzle
 * 
 * Prompts the user for the board size and grid values,
 * then attempts to solve the Zip Board and displays the solution.
 */
void task4SolveZipBoard();

/**
 * @brief User interface for Task 5: Solve a Sudoku puzzle
 * 
 * Prompts the user to enter a Sudoku board,
 * then attempts to solve it and displays the solution.
 */
void task5SolveSudoku();


/****************************
* IMPLEMENTATION PROTOTYPES *
*****************************/

/**
 * @brief Implementation of Task 1: Recursively reads and reverses a phrase
 * 
 * Reads characters from stdin one by one until newline is encountered.
 * Upon unwinding, prints the characters in reverse order.
 */
void task1ReversePhraseImplementation();

/**
 * @brief Implementation of Task 2: Recursively checks if a phrase is a palindrome
 * 
 * @param length The length of the phrase to check
 * @return 1 if the phrase is a palindrome, 0 otherwise
 * 
 * Recursively reads characters from stdin and compares first and last characters
 * at each level of recursion.
 */
int task2CheckPalindromeImplementation(int);

/**
 * @brief Implementation of Task 3: Generates all possible sentence combinations
 * 
 * @param subjects 2D array of subject strings
 * @param subjectsCount Number of subjects
 * @param verbs 2D array of verb strings
 * @param verbsCount Number of verbs
 * @param objects 2D array of object strings
 * @param objectsCount Number of objects
 * 
 * Uses recursion to generate and print all possible combinations of
 * subject + verb + object.
 */
void task3GenerateSentencesImplementation(char[][LONGEST_TERM+1], int, char[][LONGEST_TERM+1], int,
                                           
                                            char[][LONGEST_TERM+1], int);

/**
 * @brief Recursive helper function to print sentences
 * 
 * @param subjects 2D array of subject strings
 * @param subjectsCount Number of subjects
 * @param verbs 2D array of verb strings
 * @param verbsCount Number of verbs
 * @param objects 2D array of object strings
 * @param objectsCount Number of objects
 * @param printed Number of sentences printed so far
 * 
 * Recursively generates sentences by calculating which subject, verb,
 * and object to use based on the number of sentences already printed.
 */
void sentencePrinter(char[][LONGEST_TERM+1], int, char[][LONGEST_TERM+1], int,
                                            char[][LONGEST_TERM+1], int, int);

/**
 * @brief Implementation of Task 4: Solves a Zip Board puzzle
 * 
 * @param board The input board with numbered cells
 * @param solution The output solution board with directions (U/D/L/R)
 * @param size The size of the board (size x size)
 * @param startR Starting row position
 * @param startC Starting column position
 * @param highest The highest number on the board
 * @return 1 if solution found, 0 otherwise
 * 
 * Initializes the solving process and calls the recursive solver.
 */
int task4SolveZipBoardImplementation(int[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                       
                                            char[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int, int, int, int);

/**
 * @brief Recursive function to solve the Zip Board using backtracking
 * 
 * @param board The input board with numbered cells
 * @param solution The solution board being constructed
 * @param size Board size
 * @param startR Current row position
 * @param startC Current column position
 * @param highest Highest number on the board
 * @param nextNumber Next required number to visit
 * @param currentStep Current step number in the path
 * @return 1 if solution found from this position, 0 otherwise
 * 
 * Tries all four directions (U/D/L/R) recursively with backtracking
 * to find a valid path that visits all cells in order.
 */
int solveZipBoardLoop(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], int, 
                                            int, int, int, int, int);

/**
 * @brief Validates the current position in the Zip Board
 * 
 * @param board The input board
 * @param solution The solution board
 * @param size Board size
 * @param startR Row to check
 * @param startC Column to check
 * @param nextNumber Expected next number
 * @return 1 if position is invalid, 0 if valid
 * 
 * Checks for out-of-bounds, already visited cells, and incorrect numbers.
 */
int raisePositionErrors(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], int, int, int, int);

/**
 * @brief Implementation of Task 5: Solves a Sudoku puzzle
 * 
 * @param board The Sudoku board (9x9) with 0 for empty cells
 * @return 1 if solution found, 0 otherwise
 * 
 * Initializes the solving process starting from position (0,0).
 */
int task5SolveSudokuImplementation(int[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);

/**
 * @brief Recursive function to solve Sudoku using backtracking
 * 
 * @param board The Sudoku board being solved
 * @param row Current row position
 * @param col Current column position
 * @return 1 if solution found, 0 otherwise
 * 
 * Iterates through cells, attempting to fill empty cells with valid numbers.
 */
int solveSudokuLoop(int[][SUDOKU_GRID_SIZE], int, int);

/**
 * @brief Tries all possible numbers (1-9) for a Sudoku cell
 * 
 * @param board The Sudoku board
 * @param row Row of the cell
 * @param col Column of the cell
 * @param num Starting number to try
 * @return 1 if a valid number leads to a solution, 0 otherwise
 * 
 * Recursively tries each number from num to 9.
 */
int tryAllNumbers(int[][SUDOKU_GRID_SIZE], int, int, int);

/**
 * @brief Attempts to place a specific number in a Sudoku cell
 * 
 * @param board The Sudoku board
 * @param row Row of the cell
 * @param col Column of the cell
 * @param num Number to try placing
 * @return 1 if placing this number leads to a solution, 0 otherwise
 * 
 * Checks legality, places the number, continues solving, and backtracks if needed.
 */
int tryNumber(int[][SUDOKU_GRID_SIZE], int, int, int);

/**
 * @brief Checks if a number can be legally placed in a Sudoku cell
 * 
 * @param board The Sudoku board
 * @param row Row of the cell
 * @param col Column of the cell
 * @param num Number to check
 * @return 1 if legal, 0 if illegal
 * 
 * Verifies the number doesn't already exist in the same row, column, or 3x3 subgrid.
 */
int isNumberLegal(int[][SUDOKU_GRID_SIZE], int, int, int);

/**
 * @brief Recursively checks if a number exists in a given row
 * 
 * @param board The Sudoku board
 * @param row Row to check
 * @param col Starting column
 * @param num Number to search for
 * @return 1 if number found in row, 0 otherwise
 */
int numberOnRow(int[][SUDOKU_GRID_SIZE], int, int, int);

/**
 * @brief Recursively checks if a number exists in a given column
 * 
 * @param board The Sudoku board
 * @param row Starting row
 * @param col Column to check
 * @param num Number to search for
 * @return 1 if number found in column, 0 otherwise
 */
int numberOnCol(int[][SUDOKU_GRID_SIZE], int, int, int);

/**
 * @brief Recursively checks if a number exists in a 3x3 subgrid
 * 
 * @param board The Sudoku board
 * @param row Current row in subgrid
 * @param col Current column in subgrid
 * @param startRow Starting row of the subgrid
 * @param startCol Starting column of the subgrid
 * @param num Number to search for
 * @return 1 if number found in subgrid, 0 otherwise
 */
int numberInSubgrid(int[][SUDOKU_GRID_SIZE], int, int, int, int, int);


/******************************
* HELPER FUNCTIONS PROTOTYPES *
*******************************/

/**
 * @brief Reads a list of terms from the user
 * 
 * @param terms 2D array to store the terms
 * @param maxNumOfTerms Maximum number of terms allowed
 * @param type Description of term type (e.g., "subjects", "verbs")
 * @return The actual number of terms read
 * 
 * Prompts the user for the number of terms and then reads each term.
 * Validates that the count is within valid range.
 */
int readTerms(char[][LONGEST_TERM+1], int, const char[]);

/**
 * @brief Prints a Sudoku board in a formatted grid
 * 
 * @param board The Sudoku board to print (9x9)
 * 
 * Displays the board with proper grid lines separating 3x3 subgrids.
 * Empty cells (0) are shown as dots followed by spaces.
 */
void printSudoku(int[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);



/******************************
********** MAIN MENU **********
*******************************/

/**
 * @brief Main function - displays menu and handles user task selection
 * 
 * @return 0 on successful completion
 * 
 * Presents a menu of 5 tasks plus an exit option.
 * Loops until user chooses to exit.
 * Each task is implemented using recursive functions.
 */
int main() {
    int task;
    do {
        printf("Please choose a task (1-5) or 6 to exit:\n");
        printf("%d. Reverse a phrase\n", REVERSE);
        printf("%d. Check Palindrome\n", PALINDROME);
        printf("%d. Generate sentences\n", SENTENCES);
        printf("%d. Solve Zip Board\n", ZIP);
        printf("%d. Solve Sudoku\n", SUDOKU);
        printf("%d. Exit\n", EXIT);

        scanf(" %d", &task);
        scanf("%*c");
        switch (task)
        {
        case REVERSE:
            task1ReversePhrase();
            break;
        case PALINDROME:
            task2CheckPalindrome();
            break;
        case SENTENCES:
            task3GenerateSentences();
            break;
        case ZIP:
            task4SolveZipBoard();
            break;
        case SUDOKU:
            task5SolveSudoku();
            break;
        case EXIT:
            printf("Goodbye!\n");
            break;
        default:
            printf("Please choose a task number from the list.\n");
            break;
        }
        printf("\n=============================\n\n");
    } while (task != EXIT);

    return 0;
}


/***************************
****** USER INTERFACE ******
****************************/


void task1ReversePhrase() {
    printf("Please insert the phrase to reverse:\n");
    task1ReversePhraseImplementation();
    printf("\n");
}


void task2CheckPalindrome() {
    printf("Please insert the phrase length:\n");
    int n;
    scanf("%d", &n);
    printf("Please insert the phrase to check:\n");
    scanf(" ");
    if (task2CheckPalindromeImplementation(n))
        printf("The phrase is a palindrome.\n");
    else
        printf("The phrase is not a palindrome.\n");
}


void task3GenerateSentences() {
    char subjects[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    char verbs[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    char objects[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    int subjectsCount, verbsCount, objectsCount;

    subjectsCount=readTerms(subjects, MAX_NUMBER_OF_TERMS, "subjects");
    verbsCount=readTerms(verbs, MAX_NUMBER_OF_TERMS, "verbs");
    objectsCount=readTerms(objects, MAX_NUMBER_OF_TERMS, "objects");
    printf("List of Sentences:\n");
    task3GenerateSentencesImplementation(subjects, subjectsCount, verbs, verbsCount, objects, objectsCount);
}


void task4SolveZipBoard() {
    int size;
    int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE] = {0};
    char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE] = {0};
    int row=0, col=0; // previously: int row, col;
    int highest=0;
    printf("Please enter the board size:\n");
    scanf("%d", &size);
    if (size < 1 || size > ZIP_MAX_GRID_SIZE) {
        printf("Invalid board size.\n");
        return;
    }

    printf("Please enter the grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                row = i;
                col = j;
            }
            if (board[i][j]>highest) {
                highest=board[i][j];
            }
        }
    }
    if (task4SolveZipBoardImplementation(board, solution, size, row, col, highest)) {
        printf("Solution:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%c ", solution[i][j] ? solution[i][j] : 'X');
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }
}


void task5SolveSudoku() {
    printf("Please enter the sudoku board:\n");
    int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE] = {0};
    for (int i = 0; i < SUDOKU_GRID_SIZE; i++) {
        for (int j = 0; j < SUDOKU_GRID_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (task5SolveSudokuImplementation(board)) {
        printf("Solution found:\n");
        printSudoku(board);
    } else {
        printf("No solution exists.\n");
    }
}


/***************************
********* HELPERS **********
****************************/

int readTerms(char terms[][LONGEST_TERM+1], int maxNumOfTerms, const char type[]) { // added const to type
    int termsCount;
    printf("Please insert number of %s:\n", type);
    scanf("%d", &termsCount);
    if(termsCount < 1 || termsCount > maxNumOfTerms) {
        termsCount = maxNumOfTerms;
    }
    printf("Please insert the list of %s:\n", type);
    for(int i=0;i<termsCount;i++){
        printf("%d. ",i+1);
        scanf(" %[^\n]",terms[i]);
    }
    return termsCount;
}


void printSudoku(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]) {
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < SUDOKU_GRID_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SUDOKU_GRID_SIZE; j++) {
            if (board[i][j] == 0)
                printf(". ");
            printf("%d ", board[i][j]);

            if ((j + 1) % SUDOKU_SUBGRID_SIZE == 0)
                printf("| ");
        }
        printf("\n");
        if ((i + 1) % SUDOKU_SUBGRID_SIZE == 0)
            printf("+-------+-------+-------+\n");
    }
}

/***************************
******* IMPLEMENTATION ******
****************************/


void task1ReversePhraseImplementation() {
    // gets a phrase from the user and prints its reversed version using recursion function
    char character = (char)getchar();
    // base case: newline character
    if (character == '\n') {
        printf("The reversed phrase is:\n");
        return;
    // recursive case: continue reading characters; once base case is reached, print characters in reverse order
    } else {
        task1ReversePhraseImplementation();
        printf("%c", character);
        return;
    }
}

int task2CheckPalindromeImplementation(int length) {
    // base case: length 0 or 1. if length 1, consume middle character. Return 1 (true) to start unwinding
    if (length == 1) {
        getchar();
    }
    if (length <= 1) {
        return 1;
    }
    // recursive case: read first character, call recursively for length - 2, read last character, compare
    char firstCharacter = (char)getchar();
    if (!task2CheckPalindromeImplementation(length - 2)) {
        // if inner call returned false, consume last character and propagate false upwards
        getchar();    
        return 0;
    }
    // if inner call returned true, read last character and compare with first to determine return value
    char lastCharacter = (char)getchar();
    return firstCharacter == lastCharacter;
}


void task3GenerateSentencesImplementation(char subjects[][LONGEST_TERM+1], int subjectsCount,
                                            char verbs[][LONGEST_TERM+1], int verbsCount,
                                            char objects[][LONGEST_TERM+1], int objectsCount) {
    /* Call sentence printer with printed = 0.
    Alternate way: copy paste the code here using static "printed" variable */
    int printed = 0;
    sentencePrinter(subjects, subjectsCount, verbs, verbsCount, objects, objectsCount, printed);
}

void sentencePrinter(char subjects[][LONGEST_TERM+1], int subjectsCount,
                                            char verbs[][LONGEST_TERM+1], int verbsCount,
                                            char objects[][LONGEST_TERM+1], int objectsCount, int printed) {
    // base case: all sentences printed
    if (printed >= subjectsCount * verbsCount * objectsCount) {
        return;
    }
    /* Determine which subject, verb, object to print using "printed" and modulus/arithmetic: 
    Objects are the fastest changing, then verbs, then subjects */
    int objectsPrinted = printed % objectsCount;
    int verbsPrinted = (printed / objectsCount) % verbsCount;
    int subjectsPrinted = printed / (verbsCount * objectsCount);
    // print the sentence
    printf("%d. %s ", printed + 1, subjects[subjectsPrinted]);
    printf("%s %s\n", verbs[verbsPrinted], objects[objectsPrinted]);
    // recursive call with printed + 1
    sentencePrinter(subjects, subjectsCount, verbs, verbsCount, objects, objectsCount, ++printed);
}


int task4SolveZipBoardImplementation(int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                    char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                    int size, int startR, int startC, int highest) {
    // initialize nextNumber and currentStep and call the recursive function
    int nextNumber = 1;
    int currentStep = 1;
    return solveZipBoardLoop(board, solution, size, startR, startC, highest, nextNumber, currentStep);
}

int solveZipBoardLoop(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], int size, 
                                    int startR, int startC, int highest, int nextNumber, int currentStep) {
    /* main recursive function to solve the zip board.
    returns 1 if solution found, 0 otherwise.
    uses backtracking. 
    base cases:
        - position errors (out of bounds, already visited, wrong number)
        - reached highest number: check if all steps done
    recursive cases:
        - mark current position with direction
        - try all 4 directions recursively
        - if none work, unmark position and return 0 */
    if (raisePositionErrors(board, solution, size, startR, startC, nextNumber)) {
        return 0;
    }
    // check if reached highest number. Return success if all steps done, failure otherwise
    if (board[startR][startC] == highest) {
        return currentStep == (size * size);
    // if current position contains 'nextNumber', increment nextNumber for next step
    } else if (board[startR][startC] == nextNumber) {
        ++nextNumber;
    }
    // previous step is valid, here starts a new step
    ++currentStep;
    // try all 4 directions recursively with backtracking
    solution[startR][startC] = 'U';
    if (solveZipBoardLoop(board, solution, size, startR - 1, startC, highest, nextNumber, currentStep)) {
        return 1;
    }
    solution[startR][startC] = 'D';
    if (solveZipBoardLoop(board, solution, size, startR + 1, startC, highest, nextNumber, currentStep)) {
        return 1;
    }
    solution[startR][startC] = 'L';
    if (solveZipBoardLoop(board, solution, size, startR, startC - 1, highest, nextNumber, currentStep)) {
        return 1;
    }
    solution[startR][startC] = 'R';
    if (solveZipBoardLoop(board, solution, size, startR, startC + 1, highest, nextNumber, currentStep)) {
        return 1;
    }
    solution[startR][startC] = 0;
    return 0;    
}


int raisePositionErrors(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], 
                                    int size, int startR, int startC, int nextNumber) {
    /* Check for position errors:
    - out of bounds
    - already visited
    - wrong number
    Return 1 if any error found, 0 otherwise. */
    if (startC >= size || startR >= size || startC < 0 || startR < 0) {
        return 1;
    } else if (solution[startR][startC] != 0) {
        return 1;
    } else if (board[startR][startC] != 0 && board[startR][startC] != nextNumber) {
        return 1;
    } else {
        return 0;
    }
}

int task5SolveSudokuImplementation(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]) {
    // call the recursive solving function with initial GRID_START (0,0) row and col
    int row = GRID_START;
    int col = GRID_START;
    return solveSudokuLoop(board, row, col);
}

int solveSudokuLoop(int board[][SUDOKU_GRID_SIZE], int row, int col) {
    /* Iterative recursive function to solve the sudoku board using backtracking.
    Returns 1 if solution found, 0 otherwise.
    Base case: if row is past the last valid index (all rows have been processed), return success */
    if (row >= SUDOKU_GRID_SIZE) {
        return 1;
    }
    /* Recursive case:
    If cell is empty, iterate through all possible numbers and try to place them in the cell.
    In such case, next recursive calls are handled inside tryAllNumbers. */
    if (board[row][col] == 0) {
        return tryAllNumbers(board, row, col, SUDOKU_MIN_VALUE);
    // if cell is not empty, move to next cell and continue solving
    } else {
        if (++col >= SUDOKU_GRID_SIZE) {
            ++row;
            col = GRID_START;
        } 
        return solveSudokuLoop(board, row, col);
    }
}

int tryAllNumbers(int board[][SUDOKU_GRID_SIZE], int row, int col, int num) {
    /* Iterate through all possible numbers (1-SUDOKU_GRID_SIZE) to try to place in the given cell.
    Recursion continues for every possible number (inside tryNumber).
    Returns 1 if solution found, 0 otherwise.    
    Base case: if num is past the last valid number, return failure */
    if (num > SUDOKU_MAX_VALUE) {
        return 0;
    }
    /* Recursive case: try current number (if num is legal, try to place it and continue solving
    (handled inside tryNumber). */
    if (tryNumber(board, row, col, num)) {
        return 1;
    // try next number if current number is not legal or does not lead to solution
    } else {
        return tryAllNumbers(board, row, col, ++num);
    } 
}


int tryNumber(int board[][SUDOKU_GRID_SIZE], int row, int col, int num) {
    /* Try to place the given number in the given cell.
    If the number is legal, place it and continue solving (next cell).
    Returns 1 if solution is possible using the given number in the given cell, 0 otherwise. 
    Check legality using isNumberLegal() and position number. */
    if (isNumberLegal(board, row, col, num)) {
        board[row][col] = num;
        // move to next cell, preserving row/col values for backtracking in case of failure
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol >= SUDOKU_GRID_SIZE) {
            ++nextRow;
            nextCol = GRID_START;
        } 
        // return success if solution is possible using this very number
        if (solveSudokuLoop(board, nextRow, nextCol)) {
            return 1;
        // if solution is not possible using this number, backtrack and return failure
        } else {
            board[row][col] = 0;
            return 0;
        }
    } else {
        return 0;
    }
}

int isNumberLegal(int board[][SUDOKU_GRID_SIZE], int row, int col, int num) {
    /* Check if the given number can be legally placed in the given cell.
    Returns 1 if legal, 0 otherwise.
    Check legality using numberOnRow, numberOnCol, numberInSubgrid. 
    Legality functions are called before placing the number, 
    so one occurrence of the number in the cell is enough to determine illegality. 
    First, determine the starting row and column of the subgrid for numberInSubgrid function */
    int subgridStartRow = (row / SUDOKU_SUBGRID_SIZE) * SUDOKU_SUBGRID_SIZE;
    int subgridStartCol = (col / SUDOKU_SUBGRID_SIZE) * SUDOKU_SUBGRID_SIZE;
    // check legality using helper functions
    if (numberOnRow(board, row, GRID_START, num)) {
        return 0;
    } else if (numberOnCol(board, GRID_START, col, num)) {
        return 0;
    } else if (numberInSubgrid(board, subgridStartRow, subgridStartCol, subgridStartRow, subgridStartCol, num)) {
        return 0;
    } else {
        return 1;
    }
}

int numberOnRow(int board[][SUDOKU_GRID_SIZE], int row, int col, int num) {
    /* Check if the given number is present in the given row.
    Returns 1 if number is present, 0 if number is not present.
    Base case: if col is past the last valid index, return success (number not found) */
    if (col >= SUDOKU_GRID_SIZE) {
        return 0;
    }
    /* Recursive case: if number is found, return failure.
    Otherwise, continue checking the rest of the row. */
    if (board[row][col] == num) {
        return 1;
    } else {
        return numberOnRow(board, row, ++col, num);
    }
}

int numberOnCol(int board[][SUDOKU_GRID_SIZE], int row, int col, int num) {
    /* Check if the given number is present in the given column.
    Returns 1 if number is present, 0 if number is not present.
    Base case: if row is past the last valid index, return success (number not found) */
    if (row >= SUDOKU_GRID_SIZE) {
        return 0;
    }
    /* Recursive case: if number is found, return failure.
    Otherwise, continue checking the rest of the column. */
    if (board[row][col] == num) {
        return 1;
    } else {
        return numberOnCol(board, ++row, col, num);
    }    
}

int numberInSubgrid(int board[][SUDOKU_GRID_SIZE], int row, int col, int startRow, int startCol, int num) {
    /* Check if the given number is present in the given subgrid.
    Returns 1 if number is present, 0 if number is not present.
    Base case: if row is past the last valid index of the subgrid, return success (number not found) */
    if (row >= startRow + SUDOKU_SUBGRID_SIZE) {
        return 0;
    }
    /* Recursive case: if number is found, return failure.
    Otherwise, continue checking the rest of the subgrid */
    if (board[row][col] == num) {
        return 1;
    } else {
        if (++col >= startCol + SUDOKU_SUBGRID_SIZE) {
            ++row;
            col = startCol;
        } 
        return numberInSubgrid(board, row, col, startRow, startCol, num);
    }
}