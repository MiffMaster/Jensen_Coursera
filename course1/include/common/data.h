/******************************************************************************
 * Copyright (C) 2020 by Johan Jensen
 *
 * Use at your own risk.
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief 
 *
 * This header file provides an 
 *
 * @author Johan Jensen
 * @date 2020-12-06
 *
 */
 
#ifndef __DATA_H__
#define __DATA_H__

#define BASE_2 2
#define BASE_3 3
#define BASE_4 4
#define BASE_5 5
#define BASE_6 6
#define BASE_7 7
#define BASE_8 8
#define BASE_9 9
#define BASE_10 10
#define BASE_11 11
#define BASE_12 12
#define BASE_13 13
#define BASE_14 14
#define BASE_15 15
#define BASE_16 16

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Converts standart integer into ASCII-string.
 *
 * Given a signed 32-bit integer and a base, this will return
 * a pointer to a null terminated string of the cenverted integer.
 *
 * @param data Pointer to integer
 * @param ptr Pointer to where the string should pe placed
 * @param base Conversion base (2 to 16)
 *
 * @return Pointer to string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts ASCII-string into standart integer.
 *
 * Given a string 32-bit of length digits and a base, this will
 * convert it to a standard integer.
 *
 * @param data Pointer to string
 * @param digits number of digits in the data
 * @param base Conversion base (2 to 16)
 *
 * @return Pointer to integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
