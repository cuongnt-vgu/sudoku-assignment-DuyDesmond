#pragma once

#include "sudoku.h"

typedef struct HiddenTriple_impl {
    Cell *p_cells[3];
    int value1;
    int value2;
    int value3;
} HiddenTriple;

int hidden_triples(SudokuBoard *p_board);

bool is_hidden_triple(Cell **p_cells, int value1, int value2, int value3);
bool check_in_cell(Cell *p_cell, int value1, int value2, int value3);

int find_hidden_triple_values(Cell **p_cells, int *hidden_triple_values);
void find_hidden_triple(Cell **p_cells, HiddenTriple *p_hidden_triple, int *p_counter);
