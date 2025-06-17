# Sudoku Solver

A C++ program that solves 9x9 Sudoku puzzles using backtracking algorithm.

## Features
- Validates input Sudoku grid
- Solves puzzles using recursive backtracking
- Checks row, column and 3x3 box constraints
- Handles invalid inputs
- Clear output of solved grid or error message

## How to Use
1. Compile:
   ```bash
   g++ sudoku_solver.cpp -o sudoku_solver
   ```
2. Run:
   ```bash
   ./sudoku_solver
   ```
3. Input your Sudoku Grid:
   - Enter 9 rows of 9 numbers each (0 for empty cells)
   - Separate numbers with spaces

## Example Input
```
  5 3 0 0 7 0 0 0 0
  6 0 0 1 9 5 0 0 0
  0 9 8 0 0 0 0 6 0
  8 0 0 0 6 0 0 0 3
  4 0 0 8 0 3 0 0 1
  7 0 0 0 2 0 0 0 6
  0 6 0 0 0 0 2 8 0
  0 0 0 4 1 9 0 0 5
  0 0 0 0 8 0 0 7 9
```

## Code Structure
  - **print_final_grid():** Prints solved grid
  - **checking_row()/column()/box():** Validate constraints
  - **can_insert_num():** Checks if number can be placed
  - **find_the_place():** Finds next empty cell
  - **solve_the_grid():** Main solving function

## Requirements
  C++ compiler (g++ recommended)

## Limitations
  - Only for standard 9x9 Sudoku
  - Requires complete 81-number input
