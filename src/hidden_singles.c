#include "hidden_singles.h"

<<<<<<< HEAD
int hidden_singles(SudokuBoard *p_board)
{
    return 0;
=======
// Helper function to check if a candidate is hidden in the group
bool is_hidden_candidate(Cell *cell, int candidate) {
    return (cell->num_candidates > 1) && is_candidate(cell, candidate);
}

// Helper function to count the occurrences of each candidate in the group
void count_candidates(Cell **p_cells, int *candidate_count) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                int candidate = k + 1;
                if (is_hidden_candidate(p_cells[i], candidate)) {
                    candidate_count[candidate - 1]++;
                }
            }
        }
    }
}

int find_hidden_single_values(Cell **p_cells, int *hidden_single_values) {
    // Fill the hidden_single_values array with the found values
    // Return the number of hidden single values found

    int candidate_count[BOARD_SIZE] = {0};

    // Count the occurrences of each candidate in the group
    count_candidates(p_cells, candidate_count);

    int counter = 0;

    // Check for hidden singles
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (candidate_count[i] == 1) {
            hidden_single_values[counter++] = candidate_count[i];
        }
    }

    return counter;
}

void find_hidden_single(Cell **p_cells, HiddenSingle **p_hidden_singles, int *p_counter) {
    // Fill the p_hidden_singles array with the found hidden singles
    // Update the p_counter with the number of hidden single cells found
    int candidate_count[BOARD_SIZE] = {0};

    // Count the occurrences of each candidate in the group
    count_candidates(p_cells, candidate_count);

    // Check for hidden singles 
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (candidate_count[i] == 1) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int candidate = i + 1;
                if (is_hidden_candidate(p_cells[j], candidate)) {
                    p_hidden_singles[*p_counter] = malloc(sizeof(HiddenSingle));
                    p_hidden_singles[*p_counter]->p_cell = p_cells[j];
                    p_hidden_singles[*p_counter]->value = candidate;
                    (*p_counter)++;
                }
            }
        }
    }
}

int hidden_singles(SudokuBoard *p_board) {
    int total_solved = 0;

    // Check hidden singles in rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        HiddenSingle *p_hidden_singles[BOARD_SIZE];
        int counter = 0;
        find_hidden_single(p_board->p_rows[i], p_hidden_singles, &counter);

        for (int j = 0; j < counter; j++) {
            Cell *cell = p_hidden_singles[j]->p_cell;
            int value = p_hidden_singles[j]->value;
            // set_cell_value(cell, value);
            set_candidates(cell, &value, 1);
            total_solved++;
        }
    }

    // Check hidden singles in columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        HiddenSingle *p_hidden_singles[BOARD_SIZE];
        int counter = 0;
        find_hidden_single(p_board->p_cols[i], p_hidden_singles, &counter);

        for (int j = 0; j < counter; j++) {
            Cell *cell = p_hidden_singles[j]->p_cell;
            int value = p_hidden_singles[j]->value;
            // set_cell_value(cell, value);
            set_candidates(cell, &value, 1);
            total_solved++;
        }
    }

    // Check hidden singles in boxes
    for (int i = 0; i < BOARD_SIZE; i++) {
        HiddenSingle *p_hidden_singles[BOARD_SIZE];
        int counter = 0;
        find_hidden_single(p_board->p_boxes[i], p_hidden_singles, &counter);

        for (int j = 0; j < counter; j++) {
            Cell *cell = p_hidden_singles[j]->p_cell;
            int value = p_hidden_singles[j]->value;
            // set_cell_value(cell, value);
            set_candidates(cell, &value, 1);
            total_solved++;
        }
    }

    return total_solved;
>>>>>>> e7704c9 (removed static in hidden_singles.c)
}

// // By BingAI
// int find_hidden_single_values(Cell **p_cells, int *hidden_single_values)
// {
//     int counter = 0;
//     int candidate_counts[BOARD_SIZE] = {0};

//     // Count the occurrences of each candidate
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         int *candidates = get_candidates(p_cells[i]);
//         for (int j = 0; j < p_cells[i]->num_candidates; j++)
//         {
//             candidate_counts[candidates[j] - 1]++;
//         }
//         free(candidates);
//     }

//     // Find the candidates that occur only once
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         if (candidate_counts[i] == 1)
//         {
//             hidden_single_values[counter++] = i + 1;
//         }
//     }

//     return counter;
// }

// void find_hidden_single(Cell **p_cells, HiddenSingle *p_hidden_singles, int *p_counter)
// {
//     int hidden_single_values[BOARD_SIZE];
//     int num_hidden_single_values = find_hidden_single_values(p_cells, hidden_single_values);

//     for (int i = 0; i < num_hidden_single_values; i++)
//     {
//         for (int j = 0; j < BOARD_SIZE; j++)
//         {
//             if (is_candidate(p_cells[j], hidden_single_values[i]))
//             {
//                 p_hidden_singles[*p_counter].p_cell = p_cells[j];
//                 p_hidden_singles[*p_counter].value = hidden_single_values[i];
//                 (*p_counter)++;
//                 break;
//             }
//         }
//     }    
// }
// int hidden_singles(SudokuBoard *p_board)
// {
//     int counter = 0;
//     HiddenSingle hidden_singles[BOARD_SIZE * BOARD_SIZE];

//     // Iterate over each row, column, and box
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         find_hidden_single(p_board->p_rows[i], hidden_singles, &counter);
//         find_hidden_single(p_board->p_cols[i], hidden_singles, &counter);
//         find_hidden_single(p_board->p_boxes[i], hidden_singles, &counter);
//     }

//     // For each hidden single found, set the value of the cell and increment the solved counter
//     for (int i = 0; i < counter; i++)
//     {
//         HiddenSingle hs = hidden_singles[i];
//         hs.p_cell->value = hs.value;
//         p_board->solved_counter++;
//     }

//     return counter;
// }
