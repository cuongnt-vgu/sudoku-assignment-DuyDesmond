#pragma once

#include "sudoku.h"



typedef struct NakedPair_impl {
    Cell *p_cells[2];
    int value1;
    int value2;
} NakedPair;

// Function to find naked pairs in a set of cells
int find_naked_pairs(Cell **p_cells, NakedPair *naked_pairs);

// Function to apply the constraints of naked pairs to the Sudoku board
void apply_naked_pair_constraints(Cell **p_cells, NakedPair naked_pair);

// Function to solve the Sudoku board using naked pairs
int naked_pairs(SudokuBoard *p_board);

