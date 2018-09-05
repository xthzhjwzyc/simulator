#define DEBUG

#include <simulator.h>

extern unsigned int __start_bus;
extern unsigned int __stop_bus;

static struct signal_bus *bus_begin = (void *)&__start_bus;
static struct signal_bus *bus_end = (void *)&__stop_bus;

void signal_bus_init(void)
{
}

int bus_read32(unsigned int addr, unsigned int *value)
{
	assert(NULL != value);

	struct signal_bus *item;
	unsigned char buffer[4];

	for (item = bus_begin; item < bus_end; item++) {
		if ((item->addr <= addr) && (item->addr + item->size > addr)) {
			if (item->read) {
				DBG("read @%08x: %s\n", addr, item->name);
				item->read(addr - item->addr, buffer, 4);

				// TODO endian
				*value = *(unsigned int *)buffer;

				return 0;
			}
		}
	}

	return -1;
}

