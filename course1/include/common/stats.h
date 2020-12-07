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
 * @file stats.h
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
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the c1m1 deliverable.
 *
 * Runs and prints the tests for the c1m1 assignment.
 *
 * @return void.
 */
void stats();

/**
 * @brief Prints array statistics.
 *
 * Given a pointer to a data array and length, this will print the statistics.
 * Including minimum, maximum, median, and mean.
 *
 * @param ptr Pointer to char array
 * @param len Array length
 *
 * @return void.
 */
void print_statistics(unsigned char * ptr, unsigned int len);

/**
 * @brief Prints an array to the screen.
 *
 * Given a pointer to a char array and a length, it prints the array to
 * the screen.
 *
 * @param ptr Pointer to char array
 * @param len Array lenght
 *
 * @return void.
 */
void print_array(unsigned char * ptr, unsigned int len);

/**
 * @brief Finds and returns the median value from a data array.
 *
 * Given a pointer to a char array and a length, it finds and returns the
 * median value.
 *
 * @param prt Pointer to char array
 * @param len Array length
 *
 * @return Median value.
 */
unsigned char find_median(unsigned char * ptr, unsigned int len);

/**
 * @brief Finds and returns the mean value from a data array.
 *
 * Given a pointer to a char array and a length, it finds and returns the
 * mean value.
 *
 * @param prt Pointer to char array
 * @param len Array length
 *
 * @return Mean value.
 */
unsigned char find_mean(unsigned char * ptr, unsigned int len);
 
/**
 * @brief Finds and returns the maximum value from a data array.
 *
 * Given a pointer to a char array and a length, it finds and returns the
 * maximum value.
 *
 * @param prt Pointer to char array
 * @param len Array length
 *
 * @return Maximum value.
 */
unsigned char find_maximum(unsigned char * ptr, unsigned int len);
 
/**
 * @brief Finds and returns the minimum value from a data array.
 *
 * Given a pointer to a char array and a length, it finds and returns the
 * minimum value.
 *
 * @param prt Pointer to char array
 * @param len Array length
 *
 * @return Minimum value.
 */
unsigned char find_minimum(unsigned char * ptr, unsigned int len);

/**
 * @brief Sorts a data array from largest to smalest.
 *
 * Given a pointer to a char array and a length, it will sort the array
 * in descending order (lowest index will have the largest value).
 *
 * @param prt Pointer to char array
 * @param len Array length
 *
 * @return void.
 */
void sort_array(unsigned char * ptr, unsigned int len);

#endif /* __STATS_H__ */
