// naked_triples.h
#pragma once

#include "sudoku.h"

// Structure to represent a Naked Triple
typedef struct NakedTriple_impl {
    Cell *p_cell_1;
    Cell *p_cell_2;
    Cell *p_cell_3;
    Cell **p_cells;
    int value1;
    int value2;
    int value3;
} NakedTriple;

bool is_naked_triple(Cell **p_cells, int value1, int value2, int value3);
void remove_candidates_except_naked_triple(Cell **p_cells, int value1, int value2, int value3);
int find_naked_triple_values(Cell **p_cells, int *naked_triple_values);
void find_naked_triple(Cell **p_cells, NakedTriple *p_naked_triple, int *p_counter);
int naked_triples(SudokuBoard *p_board);