/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Calculates and prints statistics for a char array.
 *
 * The following statistics is calculated.
 * - Median
 * - Mean
 * - Maximum
 * - Minimum
 *
 * @author Johan Jensen
 * @date 2020-11-08
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_statistics(char * ptr){

}

void print_array(char * ptr, unsigned int len){

}

char find_median(char * ptr, unsigned int len){

}

char find_mean(char * ptr, unsigned int len){

}

char find_maximum(char * ptr, unsigned int len){

}

char find_minimum(char * ptr, unsigned int len){

}

void sort_array(char * ptr, unsigned int len){

}

