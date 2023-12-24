// #include "hidden_pairs.h"

// int hidden_pairs(SudokuBoard *p_board)
// {
//     return 0;
// }

// // hidden_pairs.c
// #include "hidden_pairs.h"
// #include <stdlib.h>

// // Function to find hidden pairs in a set of cells
// int find_hidden_pairs(Cell **p_cells, HiddenPair *hidden_pairs) {
//     int num_hidden_pairs = 0;

//     // Iterate through each pair of values (1 to 9)
//     for (int value1 = 1; value1 <= BOARD_SIZE - 1; value1++) {
//         for (int value2 = value1 + 1; value2 <= BOARD_SIZE; value2++) {
//             // Check if the pair is a hidden pair in the current set of cells
//             bool is_hidden_pair = true;

//             for (int i = 0; i < BOARD_SIZE; i++) {
//                 if (p_cells[i]->num_candidates > 2 &&
//                     (is_candidate(p_cells[i], value1) || is_candidate(p_cells[i], value2))) {
//                     is_hidden_pair = false;
//                     break;
//                 }
//             }

//             // If the pair is a hidden pair, add it to the array
//             if (is_hidden_pair) {
//                 hidden_pairs[num_hidden_pairs].p_cells[0] = p_cells[0];  // Modify based on your logic
//                 hidden_pairs[num_hidden_pairs].p_cells[1] = p_cells[1];
//                 hidden_pairs[num_hidden_pairs].value1 = value1;
//                 hidden_pairs[num_hidden_pairs].value2 = value2;
//                 num_hidden_pairs++;
//             }
//         }
//     }

//     return num_hidden_pairs;
// }

// // Function to apply the constraints of hidden pairs to the Sudoku board
// void apply_hidden_pair_constraints(Cell **p_cells, HiddenPair hidden_pair) {
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         if (p_cells[i] != hidden_pair.p_cells[0] && p_cells[i] != hidden_pair.p_cells[1]) {
//             unset_candidate(p_cells[i], hidden_pair.value1);
//             unset_candidate(p_cells[i], hidden_pair.value2);
//         }
//     }
// }

// // Function to solve the Sudoku board using hidden pairs
// int hidden_pairs(SudokuBoard *p_board) {
//     HiddenPair hidden_pairs[BOARD_SIZE * BOARD_SIZE];
//     int num_hidden_pairs = 0;

//     // Iterate through each row, column, and box to find hidden pairs
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         num_hidden_pairs += find_hidden_pairs(p_board->p_rows[i], hidden_pairs);
//         num_hidden_pairs += find_hidden_pairs(p_board->p_cols[i], hidden_pairs);
//         num_hidden_pairs += find_hidden_pairs(p_board->p_boxes[i], hidden_pairs);
//     }

//     // Process the found hidden pairs
//     for (int i = 0; i < num_hidden_pairs; i++) {
//         apply_hidden_pair_constraints(p_board->p_rows[i], hidden_pairs[i]);
//         apply_hidden_pair_constraints(p_board->p_cols[i], hidden_pairs[i]);
//         apply_hidden_pair_constraints(p_board->p_boxes[i], hidden_pairs[i]);
//     }

//     return num_hidden_pairs;
// }

// #include "sudoku.h"
// #include "hidden_pairs.h"

// int hidden_pairs(SudokuBoard *board)
// {
//     int counter = 0;

//     // Iterate through rows, columns, and boxes
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         // Check rows
//         counter += find_and_eliminate_pairs(board->p_rows[i]);

//         // Check columns
//         counter += find_and_eliminate_pairs(board->p_cols[i]);

//         // Check boxes
//         counter += find_and_eliminate_pairs(board->p_boxes[i]);
//     }

//     return counter;
// }

// int find_and_eliminate_pairs(Cell **unit)
// {
//     int counter = 0;

//     // Iterate through pairs of cells
//     for (int i = 0; i < BOARD_SIZE - 1; i++)
//     {
//         for (int j = i + 1; j < BOARD_SIZE; j++)
//         {
//             if (are_pairs(unit[i], unit[j]))
//             {
//                 // Eliminate candidates from other cells in the unit
//                 counter += eliminate_candidates(unit, unit[i], unit[j]);
//             }
//         }
//     }

//     return counter;
// }

// int are_pairs(Cell *cell1, Cell *cell2)
// {
//     // Check if two cells have exactly two common candidates
//     int count = 0;
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         if (cell1->candidates[i] && cell2->candidates[i])
//         {
//             count++;
//         }
//     }

//     return count == 2;
// }

// int eliminate_candidates(Cell **unit, Cell *pair1, Cell *pair2)
// {
//     int counter = 0;

//     // Iterate through cells in the unit
//     for (int i = 0; i < BOARD_SIZE; i++)
//     {
//         // Skip the pair cells
//         if (unit[i] != pair1 && unit[i] != pair2)
//         {
//             // Eliminate candidates that are common to the pair cells
//             for (int j = 0; j < BOARD_SIZE; j++)
//             {
//                 if (pair1->candidates[j] && pair2->candidates[j])
//                 {
//                     if (unset_candidate(unit[i], j + 1))
//                     {
//                         counter++;
//                     }
//                 }
//             }
//         }
//     }

//     return counter;
// }

#include "hidden_pairs.h"
#include "sudoku.h"
#include<stdio.h>
#include<stdlib.h>

bool is_hidden_pair(Cell **p_cells, int value1, int value2){
    int count = 0;
    for (int i =0; i < BOARD_SIZE; i++){
        if(is_candidate(p_cells[i], value1) && is_candidate(p_cells[i], value2)){
            count ++;
        }

    }
    return (count ==2);
}


bool is_in_cell(Cell *p_cells, int value1, int value2){
    return (is_candidate(p_cells, value1) && is_candidate(p_cells, value2));
}

int find_hidden_pair_values(Cell **p_cells, int *hidden_pair_values){
    int hidden_pair_count = 0;
    int hidden_pair_array[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++){
        hidden_pair_array[i] = 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (p_cells[i]->num_candidates >= 2){
            int* candidate_array = get_candidates(p_cells[i]); 
            for (int j = 0; j < p_cells[i]->num_candidates; j++){
                hidden_pair_array[candidate_array[j]-1] += 1; 
            }
            free(candidate_array);
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        if (hidden_pair_array[i] == 2){
                hidden_pair_values[hidden_pair_count++] = i+1;                  
        }
    }
    return hidden_pair_count;
}



// void find_hidden_pair(Cell **p_cells, HiddenPair *p_hidden_pair,
//                         int *p_counter)
// {       
//     int hidden_pair_value_array[BOARD_SIZE];
//     int num_value = find_hidden_pair_values(p_cells, hidden_pair_value_array);

//         for (int i = 0; i < num_value-1; i++){
//             for (int j = i+1; j < num_value; j++){
//                 if(is_hidden_pair(p_cells, hidden_pair_value_array[i], hidden_pair_value_array[j])){
//                     for (int k = 0; k < BOARD_SIZE; k++){
//                         if (is_in_cell(p_cells[k], hidden_pair_value_array[i], hidden_pair_value_array[j])){
//                         HiddenPair hidden_pair_object;
//                         hidden_pair_object.value1 = hidden_pair_value_array[i];
//                         hidden_pair_object.value2 = hidden_pair_value_array[j];
//                         // hidden_pair_object.p_cells = p_cells[k];
//                         hidden_pair_object.p_cells[i] = p_cells[k]; // where i is some valid index
//                         p_hidden_pair[(*p_counter)++] = hidden_pair_object;
//                         }                    
//                     }
//                 }
//             }
//         }
// }

void find_hidden_pair(Cell **p_cells, HiddenPair *p_hidden_pair, int *p_counter)
{
    int hidden_pair_value_array[BOARD_SIZE];
    int num_value = find_hidden_pair_values(p_cells, hidden_pair_value_array);

    for (int i = 0; i < num_value - 1; i++)
    {
        for (int j = i + 1; j < num_value; j++)
        {
            if (is_hidden_pair(p_cells, hidden_pair_value_array[i], hidden_pair_value_array[j]))
            {
                for (int k = 0; k < BOARD_SIZE; k++)
                {
                    if (is_in_cell(p_cells[k], hidden_pair_value_array[i], hidden_pair_value_array[j]))
                    {
                        HiddenPair hidden_pair_object;
                        hidden_pair_object.value1 = hidden_pair_value_array[i];
                        hidden_pair_object.value2 = hidden_pair_value_array[j];
                        hidden_pair_object.p_cells[0] = p_cells[k]; // First cell
                        hidden_pair_object.p_cells[1] = p_cells[k + 1]; // Second cell
                        p_hidden_pair[(*p_counter)++] = hidden_pair_object;
                    }
                }
            }
        }
    }
}


int hidden_pairs(SudokuBoard *p_board)
{
    HiddenPair p_hidden_pair[BOARD_SIZE*BOARD_SIZE];
    int p_counter = 0;
    for (int i = 0; i< BOARD_SIZE; i++){
        find_hidden_pair(p_board->p_cols[i], p_hidden_pair, &p_counter);
        find_hidden_pair(p_board->p_rows[i], p_hidden_pair, &p_counter);
        find_hidden_pair(p_board->p_boxes[i], p_hidden_pair, &p_counter);
    }
    int overlap = p_counter;
    for (int i = 0; i < p_counter; i++){
        int not_overlap = 0;
        Cell **p_cells = p_hidden_pair[i].p_cells;
        int* candidate_array = get_candidates(*p_cells);
        int num_candidates = (*p_cells)->num_candidates;

        for (int index = 0; index < num_candidates; index++){
            if ((candidate_array[index] != p_hidden_pair[i].value1) && (candidate_array[index] != p_hidden_pair[i].value2)){
                // unset_candidate(p_cells[index], candidate_array[index]);
                unset_candidate(*p_cells, candidate_array[index]);
                not_overlap = 1;
            }
        }

        overlap -= not_overlap;
        free(candidate_array);
    }
    return (p_counter - overlap)/2;
}



        // for (int j = 0; j < num_candidates; j++){
        //     if ((candidate_array[j]!= p_hidden_pair[i].value1)&&(candidate_array[j]!=p_hidden_pair[i].value2)){
        //         unset_candidate(p_cells[i], candidate_array[j]);
        //         not_overlap = 1;
        //     }
        // }
