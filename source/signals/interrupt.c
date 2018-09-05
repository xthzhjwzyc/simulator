#include <simulator.h>

extern struct interrupt section_interrupt[];

void clock_posedge(void)
{
	int i;
	unsigned int section_size;
	
	for (i = 0; i < section_size / 4; i ++) {
		clock[i].value--;
		if (0 == clock[i].value) {
			clock[i].value = clock[i].reload;
			clock[i].clock_posedge();
		}
	}
}
