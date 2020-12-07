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

//#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void stats() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  const char str_line[] = "---------------------------------\n\n";

	#ifdef VERBOSE
  // Print input array
  PRINTF("---------{ INPUT ARRAY }---------\n");
  print_array(test, SIZE);
  PRINTF("%s",str_line);
	#endif
	
  // Print statistics
  PRINTF("---------{ STATISTICS }----------\n");
  print_statistics(test, SIZE);
  PRINTF("%s",str_line);

	#ifdef VERBOSE
  // Print sorted array
  PRINTF("---------{ SORTED ARRAY }--------\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);
  PRINTF("%s",str_line);
  #endif
}

void print_statistics(unsigned char * ptr, unsigned int len){
  PRINTF("  Minimum value: %i\n", find_minimum(ptr, len));
  PRINTF("  Maximum value: %i\n", find_maximum(ptr, len));
  PRINTF("   Median value: %i\n", find_median(ptr, len));
  PRINTF("     Mean value: %i\n", find_mean(ptr, len));
}

void print_array(unsigned char * ptr, unsigned int len){
#ifdef VERBOSE
  for(int idx=0; idx<len; idx++){
    // Prepend padding for allignment.
    if(ptr[idx] < 100){
      PRINTF(" ");
      if(ptr[idx] < 10){
        PRINTF(" ");
      }
    }
    if(idx%8 == 0) PRINTF( " " );
    // Print array value. Add new line with every 8th item.
    if(idx%8 != 7) PRINTF( "%i ", ptr[idx]);
    else PRINTF("%i\n", ptr[idx]);
  }
#endif
}

unsigned char find_median(unsigned char * ptr, unsigned int len){
  // This function should not edit the input array.
  // Begin by making a copy.
  unsigned char temp[len];
  for(int idx=0; idx<len; idx++) temp[idx] = ptr[idx];

  // Sort the copy.
  sort_array(temp, len);

  // Get the median value.
  float median = temp[len/2];
  // If the matrix has an even number of elements, calculate the
  // median as the "mean of the two center elements".
  if(len%2 == 0){
    median += temp[len/2-1];
    median /= 2;
  }
  // As the input is integers, I choose to round the result and
  // return an integer.
  return((unsigned char)(median+0.5));
}

unsigned char find_mean(unsigned char * ptr, unsigned int len){
  float sum = 0;
  for(int idx=0; idx<len; idx++){
    sum += ptr[idx];
  }
  // Calculate mean.
  sum /= len;
  // As the input is integers, I choose to round the result and
  // return an integer.
  return((unsigned char)(sum+0.5));
}

unsigned char find_maximum(unsigned char * ptr, unsigned int len){
  unsigned char max = 0;
  for(int idx=0; idx<len; idx++){
    if(ptr[idx] > max) max = ptr[idx];
  }
  return(max);
}

unsigned char find_minimum(unsigned char * ptr, unsigned int len){
  unsigned char min = 255;
  for(int idx=0; idx<len; idx++){
    if(ptr[idx] < min) min = ptr[idx];
  }
  return(min);
}

void sort_array(unsigned char * ptr, unsigned int len){
  unsigned char swaps = 1;
  // Keep sorting until no swaps was made.
  while(swaps > 0){
    swaps = 0;
    // Walk through array and swap any adjacent values that
    // are not orderd correctly.
    for(int idx=0; idx<len-1; idx++){
      if(ptr[idx] < ptr[idx+1]){
        unsigned char tmp = ptr[idx];
        ptr[idx] = ptr[idx+1];
        ptr[idx+1] = tmp;
        swaps++;
      }
    }
  }
}

