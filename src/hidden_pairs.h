// #pragma once

// #include "sudoku.h"

// int find_hidden_pairs(Cell **p_cells, HiddenPair *hidden_pairs);
// void apply_hidden_pair_constraints(Cell **p_cells, HiddenPair hidden_pair);
// int hidden_pairs(SudokuBoard *p_board);
#pragma once

#include "sudoku.h"

typedef struct HiddenPair_impl {
    Cell *p_cells[2];
    int value1;
    int value2;
} HiddenPair;


// int find_and_eliminate_pairs(Cell **unit);
// int are_pairs(Cell *cell1, Cell *cell2);
// int eliminate_candidates(Cell **unit, Cell *pair1, Cell *pair2);

// // Function to find hidden pairs in a set of cells
// int find_hidden_pairs(Cell **p_cells, HiddenPair *hidden_pairs);

// // Function to apply the constraints of hidden pairs to the Sudoku board
// void apply_hidden_pair_constraints(Cell **p_cells, HiddenPair hidden_pair);

// Function to solve the Sudoku board using hidden pairs
int hidden_pairs(SudokuBoard *p_board);

bool is_hidden_pair(Cell **p_cells, int value1, int value2);
bool is_in_cell(Cell *p_cell, int value1, int value2);

int find_hidden_double_values(Cell **p_cells, int *hidden_double_values);
void find_hidden_double(Cell **p_cells, HiddenPair *p_hidden_double, int *p_counter);
