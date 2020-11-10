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
#include <stdbool.h>
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
  printf("\n---------{ INPUT ARRAY }---------\n");
  print_array(test, SIZE);
  printf("---------------------------------\n");
  
  printf("\n---------{ STATISTICS }----------\n");
  print_statistics(test, SIZE);
  printf("\n---------------------------------\n");
  
  sort_array(test, SIZE);
  printf("\n---------{ SORTED ARRAY }--------\n");
  print_array(test, SIZE);
  printf("---------------------------------\n");
}

void print_statistics(unsigned char * ptr, unsigned int len){
  printf("  Minimum value: %i\n", find_minimum(ptr, len));
  printf("  Maximum value: %i\n", find_maximum(ptr, len));
  printf("   Median value: %i\n", find_median(ptr, len));
  printf("     Mean value: %i", find_mean(ptr, len));
}

void print_array(unsigned char * ptr, unsigned int len){
  for(int idx=0; idx<len; idx++){
    // Print padding for allignment.
    if(ptr[idx] < 100){
      printf(" ");
      if(ptr[idx] < 10) printf(" ");
    }
    if(idx%8 == 0) printf( " " );
    if(idx%8 == 7) printf( "%i\n", ptr[idx]);
    else printf("%i ", ptr[idx]);
  }
}

unsigned char find_median(unsigned char * ptr, unsigned int len){
  // This function should not edit the input array.
  // Begin by making a copy.
  unsigned char temp[len];
  for(int idx=0; idx<len; idx++) temp[idx] = ptr[idx];
  // Sort the copy.
  sort_array(temp, len);
  
  // Get the median value.
  unsigned int median = temp[len/2];
  if(len%2 == 0){
    median += temp[len/2-1];
    median /= 2;
  }
  return( (unsigned char)median );
}

unsigned char find_mean(unsigned char * ptr, unsigned int len){
  unsigned int sum = 0;
  for(int idx=0; idx<len; idx++){
    sum += ptr[idx];
  }
  // Calculate mean.
  sum /= len;
  return((unsigned char)sum);
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
  bool done_sorting = false;
  unsigned char swap = 0;
  
  while(!done_sorting){
    done_sorting = true;
    for(int idx=0; idx<len-1; idx++){
      if(ptr[idx] < ptr[idx+1]){
        swap = ptr[idx];
        ptr[idx] = ptr[idx+1];
        ptr[idx+1] = swap;
        done_sorting = false;
      }
    }
  }
}

