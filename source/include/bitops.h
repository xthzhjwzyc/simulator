#ifndef BITOPS_H
#define BITOPS_H

#include <assert.h>

#define BIT(nr)				(1ULL<<(nr))

#define BITMASK(width)			(BIT(width) - 1)

#define BITCLR(reg,offset,width)					\
	((reg) & (~(BITMASK(width) << (offset))))

#define BITSET(reg, offset, width, value)				\
	do {								\
		assert(BITMASK(width) >= value);			\
		reg = 	(BITCLR(reg, offset, width)) |			\
			(((value) & BITMASK(width)) << (offset));	\
	} while (0)

#define BITGET(reg, offset, width)					\
	(((reg) >> (offset)) & BITMASK(width))

#endif
