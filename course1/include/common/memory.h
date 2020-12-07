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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Moves a length of values fron src to dst. 
 *
 * Given a source and destination pointer to a uint8_t data set
 * of known lenght, this will move the data from soruce to the
 * new destination.
 * This function handles overlaps of source and destination too.
 *
 * @param src Pointer to source data
 * @param dest Pointer to data destination
 * @param length Number of bytes to move
 *
 * @return Pointer to destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a length of values fron src to dst. 
 *
 * Given a source and destination pointer to a uint8_t data set
 * of known lenght, this will copy the data from soruce to the
 * new destination.
 * The behaviour is undefined for overlap between source and destination.
 *
 * @param src Pointer to source data
 * @param dest Pointer to data destination
 * @param length Number of bytes to move
 *
 * @return Pointer to destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a lenght och bytes to value. 
 *
 * Given a pointer this will set a length of bytes to the provided value.
 *
 * @param src Pointer to source data
 * @param length Number of bytes to set
 * @param value Value to set
 *
 * @return Pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a lenght och bytes to zero.
 *
 * Given a pointer this will set a length of bytes to zero.
 *
 * @param src Pointer to source data
 * @param length Number of bytes to set
 *
 * @return Pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of a lentgh of bytes.
 *
 * Given a pointer and length of data, this will reverse the
 * order of bytes in the data length.
 *
 * @param src Pointer to source data
 * @param length Number of bytes to reverse
 *
 * @return Pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates words of dynamic memory 
 *
 * Given a length it will allocate that number of words in
 * the dynamic memory space.
 *
 * @param length Number of words to allocate
 *
 * @return Pointer to first word
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Will free a length of words in dynamic memory.
 *
 * Given a source pointer, it will free length number of words
 * in the dynamic memory space. 
 *
 * @param src Pointer to memory to free
 *
 * @return Pointer to first word
 */
void free_words(uint32_t * src);

/**
 * @brief Sets a value of a data array.
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array.
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array.
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value.
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array.
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
