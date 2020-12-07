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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * ptr = dst;
	uint8_t temp;
	
	if (dst < src) {
		for (; dst < ptr+length; dst++, src++) {
			temp = *dst;
			*dst = *src;
			*src = temp;
		}
	}
	else if (dst > src) {
	  dst += length-1;
	  src += length-1;
		for (; dst >= ptr; dst--, src--) {
			temp = *dst;
			*dst = *src;
			*src = temp;
		}
	}
	return ptr;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * ptr = dst;
	
	if (dst < src) {
		for (; dst < ptr+length; dst++, src++) {
			*dst = *src;
		}
	}
	else if (dst > src) {
	  dst += length-1;
	  src += length-1;
		for (; dst >= ptr; dst--, src--) {
			*dst = *src;
		}
	}
	return ptr;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	uint8_t * ptr = src; // Save for later.
	
	for (; src < ptr+length; src++) {
		*src = value;
	}
	return ptr;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t temp;
	uint8_t * start = src;
	uint8_t * end = src+length-1;
	
	for (; start < end; start++, end--) {
		temp = *end;
		*end = *start;
		*start = temp;
	}
	return src;
}

int32_t * reserve_words(size_t length){
	return (int32_t *)malloc(length*4);
}

void free_words(uint32_t * src){
	free(src);
}

void free_words(int32_t * src){
	free(src);
}

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

