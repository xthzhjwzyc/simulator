#define DEBUG

#include <simulator.h>

static void clock_posedge(void)
{
	int ret;
	unsigned int result;

	ret = bus_read32(0x40000000, &result);
	if (0 != ret) {
		DBG("MemFault\n");
	}
	else {
		DBG("read back: %x\n", result);
	}
}

SIGNAL_CLOCK_REGISTER("core", clock_posedge);
