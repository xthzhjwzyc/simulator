#ifndef SIGNAL_H
#define SIGNAL_H

struct clock {
	unsigned int value;
	unsigned int reload;
	void (*clock_posedge)(void);
};

extern void interrupt_raise(void);

extern void pin_write(unsigned char *data);
extern void pin_read(unsigned char *data);

typedef unsigned int (*register_action_t)(unsigned int value);

#endif
