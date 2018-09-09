#ifndef ARMV7M_CORE_H
#define ARMV7M_CORE_H

#include <simulator.h>

#include "config.h"

struct regfile {
        unsigned int r0;
        unsigned int r1;
        unsigned int r2;
        unsigned int r3;
        unsigned int r4;
        unsigned int r5;
        unsigned int r6;
        unsigned int r7;
        unsigned int r8;
        unsigned int r9;
        unsigned int r10;
        unsigned int r11;
        unsigned int r12;
        unsigned int sp;
        unsigned int lr;
        unsigned int pc;

        unsigned int apsr;
        unsigned int epsr;
        unsigned int ipsr;

        unsigned int msp;
        unsigned int psp;
};

extern struct regfile regfile;

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
