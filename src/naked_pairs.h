#pragma once

#include "sudoku.h"



typedef struct NakedPair_impl {
    Cell *p_cells[2];
    int value1;
    int value2;
} NakedPair;

// // Function to find naked pairs in a set of cells
// int find_naked_pairs(Cell **p_cells, NakedPair *naked_pairs);

// // Function to apply the constraints of naked pairs to the Sudoku board
// void apply_naked_pair_constraints(Cell **p_cells, NakedPair naked_pair);

// // Function to solve the Sudoku board using naked pairs
// int naked_pairs(SudokuBoard *p_board);

int naked_pairs(SudokuBoard *p_board);
void find_naked_double(Cell **p_cells, NakedPair *p_naked_double, int *p_counter);
int is_naked_pair(Cell **p_cells, int value1, int value2);
bool is_in_naked_pair_cell(NakedPair *p_array, Cell *p);
int is_naked_cell(Cell *p_cells, int value1, int value2);
int find_naked_double_values(Cell **p_cells, int *naked_double_values)