# Copyright (C) 2020 by Johan Jensen
No Rights Reserved.

This is just some practise material for the Coursera Specialization of
Embedded Sorftware and Essentials.
Course 1 - Introduction to Embedded Software and Development Environments.
https://www.coursera.org/learn/introduction-embedded-systems

## Week 4 Expanded Build System and Memory

### *Notes to the reviewer*

The **source tree** is not the same as in *c1m2*. I updatet the tree to match
what is expected in this module, and corrected my Makefile/sourses.mk to
handle this.

The **my_itoa()** function is expected to include the null-termination in the
returned length. This is NOT how C normally handles this. Thus I also
included logic to hande the deviating behaviour in **my_atoi()**.

The instructons says nothing about error handling in **my_atoi()**. Thoug I
added the bare minimum, where it will return 0 (zero) if the string contains
characters that are not valid for the given base (excluding null-terminator).

I could not find the **zip-file** with provided material, I had to dig these
files out of the git-repo and I am not completely sure I have the correct
files. For instance the course1.c would recast the the pointer when calling
free\_words((uint32\_t \*) instead of the expected int32\_t \* as per the
instruction. I chose to stick to de specifivation in the instruction and
insted edit the cours1.c file to recast as (int32\_t \*).

Other than that,
## Thank you for your time and honest feedback!
