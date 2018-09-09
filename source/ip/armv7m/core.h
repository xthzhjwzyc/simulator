#ifndef ARMV7M_CORE_H
#define ARMV7M_CORE_H

#include <simulator.h>

#include "config.h"
#include "isa.h"
#include "pseudo.h"

/* refer to D8.1: ARM core registers */
struct core_registers {

	/* deprecated */
        volatile unsigned int r0;
        volatile unsigned int r1;
        volatile unsigned int r2;
        volatile unsigned int r3;
        volatile unsigned int r4;
        volatile unsigned int r5;
        volatile unsigned int r6;
        volatile unsigned int r7;
        volatile unsigned int r8;
        volatile unsigned int r9;
        volatile unsigned int r10;
        volatile unsigned int r11;
        volatile unsigned int r12;
        volatile unsigned int sp;
        volatile unsigned int lr;
        volatile unsigned int pc;

	volatile unsigned int reg[16];

        volatile unsigned int apsr;
        volatile unsigned int epsr;
        volatile unsigned int ipsr;

        volatile unsigned int msp;
        volatile unsigned int psp;

	volatile unsigned int primask;
	volatile unsigned int faultmask;
	volatile unsigned int basepri;
	volatile unsigned int control;
};

extern struct core_registers regfile;

#define APSR_N	((regfile.apsr & BIT(31)) ? 1 : 0)
#define APSR_Z	((regfile.apsr & BIT(30)) ? 1 : 0)
#define APSR_C	((regfile.apsr & BIT(29)) ? 1 : 0)
#define APSR_V	((regfile.apsr & BIT(28)) ? 1 : 0)

#define APSR_N_SET(x)	do {					\
		BITCLR(regfile.apsr, 31, 31);			\
		BITSET(regfile.apsr, 31, 31, x ? 1 : 0);	\
	} while (0);

#define APSR_Z_SET(x)	do {					\
		BITCLR(regfile.apsr, 30, 30);			\
		BITSET(regfile.apsr, 30, 30, x ? 1 : 0);	\
	} while (0);

#define APSR_C_SET(x)	do {					\
		BITCLR(regfile.apsr, 29, 29);			\
		BITSET(regfile.apsr, 29, 29, x ? 1 : 0);	\
	} while (0);

#define APSR_V_SET(x)	do {					\
		BITCLR(regfile.apsr, 28, 28);			\
		BITSET(regfile.apsr, 28, 28, x ? 1 : 0);	\
	} while (0);

// TODO this is a register in SCS
#define VECTOR_BASE    (0)

// TODO refer to ARM_ARM
#define CORE_EXCEPTION_RETURN_ADDR        (0xFFFFFFF9)

static inline unsigned int core_read32(unsigned int addr)
{
	int ret;
	unsigned int result;

	ret = bus_request(addr, (unsigned char *)&result, sizeof(unsigned int), BUS_DIR_READ);
	if (0 != ret) {
		DBG("MemFault\n");
	}

        return result;
}

static inline void core_write32(unsigned int addr, unsigned int value)
{
	int ret;

	ret = bus_request(addr, (unsigned char *)&value, sizeof(unsigned int), BUS_DIR_WRITE);
	if (0 != ret) {
		DBG("MemFault\n");
	}
}

static inline unsigned short core_read16(unsigned int addr)
{
	int ret;
	unsigned short result;

	ret = bus_request(addr, (unsigned char *)&result, sizeof(unsigned short), BUS_DIR_READ);
	if (0 != ret) {
		DBG("MemFault\n");
	}

        return result;
}

static inline void core_write16(unsigned int addr, unsigned short value)
{
	int ret;

	ret = bus_request(addr, (unsigned char *)&value, sizeof(unsigned short), BUS_DIR_WRITE);
	if (0 != ret) {
		DBG("MemFault\n");
	}
}

extern bool core_isa_is_thumb(unsigned short instruction);
extern void core_isa_thumb_execute(unsigned short instruction);
extern void core_isa_thumb2_execute(unsigned short instruction);

#endif
