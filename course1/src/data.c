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

#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include <stdio.h>

// Look-up-table for itoa() and atoi().
static uint8_t chars[16] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
                            0x38, 0x39, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66};
                     
/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t idx = 0; // Keep track of string pos.
	uint8_t neg = 0; // Was the data negative.
	
	// Check if data is just zero (0).
	if (data == 0) {
		*ptr = *(chars + 0);
		idx++;
	}
	else {
		// Check if data is negative
		if (data < 0) {
			data *= -1;  // Change data to positive.
			neg = 1;
		}
		// This will hold the characters in backwards order.
		uint8_t ascii[32];
		// Convert digtits to ascii.
		while (data>0) {
			uint8_t rem = data % base;
			data /= base;
			*(ascii+idx) = *(chars+rem);
			idx++;
		}
		// Assemble the output string.
		if (neg) {
			*ptr = 0x2d; // Add negative sign (-)
		}
		// Put the characters in the correct order.
		for (uint8_t pos = 0; pos<=idx; pos++) {
			*(ptr+neg+pos) = *(ascii+idx-pos-1);
		}
	}
	// Add null termination
	*(ptr+neg+idx) = 0x00;
	idx++;
	
	return neg+idx;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	uint8_t pos = 0;
	uint8_t neg = 0;
	int32_t result = 0;
	
	// Check for negative
	if (*ptr == 0x2d) {
		neg = 1;
		pos++;
	}
	// Convert digits
	for (; pos<digits-1; pos++) {
		for (uint8_t num=0; num<=base; num++) {
			if (*(ptr+pos) == *(chars+num)) {
				result = result*base + num;
				num = base;
				break;
			}
			// If char is not in chars[], it is not a valid base 2-16 number.
			if ((num == base) && (*(ptr+pos) != 0x00)) {
				return 0;
			}
		}
	}
	if (neg) {
		result *= -1;
	}

	return result;
}


