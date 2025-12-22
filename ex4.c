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


/***************************
* USER INTERFACE PROTOTYPES *
****************************/

void task1ReversePhrase();
void task2CheckPalindrome();
void task3GenerateSentences();
void task4SolveZipBoard();
void task5SolveSudoku();


/****************************
* IMPLEMENTATION PROTOTYPES *
*****************************/

void task1ReversePhraseImplementation();
int task2CheckPalindromeImplementation(int);
void task3GenerateSentencesImplementation(char[][LONGEST_TERM+1], int, char[][LONGEST_TERM+1], int,
                                            char[][LONGEST_TERM+1], int);
void sentencePrinter(char[][LONGEST_TERM+1], int, char[][LONGEST_TERM+1], int,
                                            char[][LONGEST_TERM+1], int, int);
int task4SolveZipBoardImplementation(int[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                            char[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int, int, int, int);
int solveZipBoardLoop(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], int, 
                                            int, int, int, int, int);
int raisePositionErrors(int board[][ZIP_MAX_GRID_SIZE], char solution[][ZIP_MAX_GRID_SIZE], int, int, int, int);
int task5SolveSudokuImplementation(int[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
int solveSudokuLoop(int[][SUDOKU_GRID_SIZE], int, int);
int tryAllNumbers(int[][SUDOKU_GRID_SIZE], int, int, int);
int tryNumber(int[][SUDOKU_GRID_SIZE], int, int, int);
int isNumberLegal(int[][SUDOKU_GRID_SIZE], int, int, int);
int numberOnRow(int[][SUDOKU_GRID_SIZE], int, int, int);
int numberOnCol(int[][SUDOKU_GRID_SIZE], int, int, int);
int numberInSubgrid(int[][SUDOKU_GRID_SIZE], int, int, int, int, int);


/******************************
* HELPER FUNCTIONS PROTOTYPES *
*******************************/

int readTerms(char[][LONGEST_TERM+1], int, char[]);
void printSudoku(int[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);



/******************************
********** MAIN MENU **********
*******************************/

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
    int row, col;
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

int readTerms(char terms[][LONGEST_TERM+1], int maxNumOfTerms, char type[]) {
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
*********** TODO ***********
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
        return tryAllNumbers(board, row, col, 1);
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
    if (num > SUDOKU_GRID_SIZE) {
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
        // move to next cell
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