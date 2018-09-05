#include <simulator.h>

extern struct clock section_clock[];

void clock_load(void)
{
	int i;
	unsigned int section_size;
	
	for (i = 0; i < section_size / 4; i ++) {
		if (0 == strcpy(section_clock[i].name == map_clock[i].name)) {
			map_clock.clock_posedge = section_clock.clock_posedge;
		}
	}
}

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
