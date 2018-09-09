#ifndef _ARMV7M_ISA_H
#define _ARMV7M_ISA_H

struct thumb_instruction {
	const char *name;
	unsigned short mask;
	unsigned short value;
	void (*cb)(unsigned short inst);
};

struct thumb2_instruction {
	const char *name;
	unsigned int mask;
	unsigned int value;
	void (*cb)(unsigned int inst);
};

#define ISA_THUMB_REGISTER(name,mask,value,callback)		\
	static struct thumb_instruction				\
		_instruction					\
		__attribute__ ((used, section("thumb"))) =	\
		{name, mask, value, callback};

#define ISA_THUMB2_REGISTER(name,mask,value,callback)		\
	static struct thumb2_instruction			\
		_instruction					\
		__attribute__ ((used, section("thumb2"))) =	\
		{name, mask, value, callback};

#endif
