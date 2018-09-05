// The file has been auto generated

//------------------------------------------------------------------------------
//				Header
//------------------------------------------------------------------------------
#include <simulator.h>

#include "config.h"

static unsigned int register_action_dr(unsigned int value, unsigned int option);
static unsigned int register_action_int_en(unsigned int value, unsigned int option);
static unsigned int register_action_int_id(unsigned int value, unsigned int option);
static unsigned int register_action_fifo_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_line_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_modem_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_line_sts(unsigned int value, unsigned int option);
static unsigned int register_action_modem_sts(unsigned int value, unsigned int option);
static unsigned int register_action_divisor0(unsigned int value, unsigned int option);
static unsigned int register_action_divisor1(unsigned int value, unsigned int option);

//------------------------------------------------------------------------------
//				Registers
//------------------------------------------------------------------------------

enum {
	REG_DR,
	REG_INT_EN,
	REG_INT_ID,
	REG_FIFO_CTL,
	REG_LINE_CTL,
	REG_MODEM_CTL,
	REG_LINE_STS,
	REG_MODEM_STS,
	REG_DIVISOR0,
	REG_DIVISOR1
};

#define REG_RESET_VALUE_DR		0
#define REG_RESET_VALUE_INT_EN		0
#define REG_RESET_VALUE_INT_ID		0
#define REG_RESET_VALUE_FIFO_CTL	0
#define REG_RESET_VALUE_LINE_CTL	0
#define REG_RESET_VALUE_MODEM_CTL	0
#define REG_RESET_VALUE_LINE_STS	0
#define REG_RESET_VALUE_MODEM_STS	0
#define REG_RESET_VALUE_DIVISOR0	0
#define REG_RESET_VALUE_DIVISOR1	0

static const unsigned int register_reset_value[] = {
	REG_RESET_VALUE_DR,
	REG_RESET_VALUE_INT_EN,
	REG_RESET_VALUE_INT_ID,
	REG_RESET_VALUE_FIFO_CTL,
	REG_RESET_VALUE_LINE_CTL,
	REG_RESET_VALUE_MODEM_CTL,
	REG_RESET_VALUE_LINE_STS,
	REG_RESET_VALUE_MODEM_STS,
	REG_RESET_VALUE_DIVISOR0,
	REG_RESET_VALUE_DIVISOR1
};

static unsigned int registers[] = {
	REG_RESET_VALUE_DR,
	REG_RESET_VALUE_INT_EN,
	REG_RESET_VALUE_INT_ID,
	REG_RESET_VALUE_FIFO_CTL,
	REG_RESET_VALUE_LINE_CTL,
	REG_RESET_VALUE_MODEM_CTL,
	REG_RESET_VALUE_LINE_STS,
	REG_RESET_VALUE_MODEM_STS,
	REG_RESET_VALUE_DIVISOR0,
	REG_RESET_VALUE_DIVISOR1
};

static register_action_t register_action[] = {
	register_action_dr,
	register_action_int_en,
	register_action_int_id,
	register_action_fifo_ctl,
	register_action_line_ctl,
	register_action_modem_ctl,
	register_action_line_sts,
	register_action_modem_sts,
	register_action_divisor0,
	register_action_divisor1
};

//------------------------------------------------------------------------------
//									Signals
//------------------------------------------------------------------------------

/*
 * 1. send data out
 * 2. receive data
 * 3. send interrupt signal
 */
static void signal_clock(void)
{
	static unsigned int count = 0;
	
	count++;
}

static void signal_reset(void)
{
	memcpy(registers, register_reset_value, sizeof(registers));
}

static unsigned int signal_mmio(unsigned int addr, unsigned int data, unsigned int option)
{
	return register_action[addr](data, option);
}

// TODO register signals here
// TODO how to support multi-instance
SIGNAL_CLOCK_REGISTER("uart", signal_clock);

//------------------------------------------------------------------------------
//									Internals definition
//------------------------------------------------------------------------------

static unsigned int register_action_dr(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_int_en(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_int_id(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_fifo_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_line_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_modem_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_line_sts(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_modem_sts(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_divisor0(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_divisor1(unsigned int value, unsigned int option)
{
	return 0;
}

