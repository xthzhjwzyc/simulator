#ifndef SIGNAL_H
#define SIGNAL_H

struct signal_clock {
	const char *name;
	void (*cb)(void);
};

// used: warning: ‘clock’ defined but not used
// don't use ".clock" as I will use __start_clock
#define SIGNAL_CLOCK_REGISTER(name, callback)			\
	static struct signal_clock				\
		_clock						\
		__attribute__ ((used, section("clock"))) =	\
		{name, callback};

extern void signal_clock_init(void);
extern void signal_bus_init(void);

extern void signal_clock_posedge(void);

#endif

