#ifndef _ARMV7M_PSEUDO_H
#define _ARMV7M_PSEUDO_H

#define LOCAL_VAR(x)	volatile unsigned int x=0; (void)(x)

#define ISA_LOCAL_VARS					\
	LOCAL_VAR(i);					\
	LOCAL_VAR(S);					\
	LOCAL_VAR(type);				\
	LOCAL_VAR(shift_t);				\
	LOCAL_VAR(shift_n);				\
	LOCAL_VAR(shifted);				\
	LOCAL_VAR(imm2);				\
	LOCAL_VAR(imm3);				\
	LOCAL_VAR(imm8);				\
	LOCAL_VAR(imm32);				\
	LOCAL_VAR(d);					\
	LOCAL_VAR(n);					\
	LOCAL_VAR(m);					\
	LOCAL_VAR(setflags);				\
	LOCAL_VAR(result);				\
	LOCAL_VAR(carry);				\
	LOCAL_VAR(overflow);

#define ISA_SET_FLAGS						\
	do {							\
		if (setflags) {					\
			APSR.N = BITGET(result, 31, 31);	\
			APSR.Z = result ? 1 : 0;		\
			APSR.C = carry;				\
			APSR.V = overflow;			\
		}						\
	} while (0)

#define UInt(x)		((unsigned int)(x))
#define SInt(x)		((signed int)(x))

// TODO check if it works
#define AddWithCarry(a, b, c)						\
	do {								\
		volatile unsigned long long unsigned_sum;		\
		volatile signed long long signed_sum;			\
		unsigned_sum = UInt(a) + UInt(b) + UInt(c);		\
		signed_sum = SInt(a) + SInt(b) + UInt(c);		\
		result = unsigned_sum & BITMASK(32);			\
		carry = (UInt(result) == unsigned_sum) ? 0 : 1;		\
		overflow = (SInt(result) == signed_sum) ? 0 : 1;	\
	} while (0);

#define InITBlock()	(false)
#define Shift(reg, a, b, c)
#define DecodeImmShift(type, imm)

#endif

