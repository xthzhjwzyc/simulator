#ifndef SIGNAL_H
#define SIGNAL_H

struct signal_clock {
	const char *name;
	void (*cb)(void);
};

struct signal_bus {
	const char *name;
	unsigned int addr;
	unsigned int size;
	int (*read)(unsigned int addr, unsigned char *buf, unsigned int len);
	int (*write)(unsigned int addr, unsigned char *buf, unsigned int len);
};

// used: warning: ‘clock’ defined but not used
// don't use ".clock" as I will use __start_clock
#define SIGNAL_CLOCK_REGISTER(name, callback)			\
	static struct signal_clock				\
		_clock						\
		__attribute__ ((used, section("clock"))) =	\
		{name, callback};

#define SIGNAL_BUS_REGISTER(name, start, size, read, write)	\
	static struct signal_bus				\
		_io						\
		__attribute__ ((used, section("bus"))) =	\
		{name, start, size, read, write};

extern void signal_clock_init(void);
extern void signal_bus_init(void);

extern void signal_clock_posedge(void);

extern int bus_read32(unsigned int addr, unsigned int *value);

#endif

