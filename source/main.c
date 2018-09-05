#include <simulator.h>

int main(int argc, char *argv[])
{
	/* initialize from known signal sections
	 * - bus
	 * - clock
	 * - reset	
	 */
	ip_attach();
	
	/* one loop = one cycle */
	while (1) {
		clock_posedge();
	}
	
	return 0;
}