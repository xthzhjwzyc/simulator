#ifndef _ARMV7M_FP_H
#define _ARMV7M_FP_H

struct fp_single_precision_registers {
	unsigned int S0;
	unsigned int S1;
	unsigned int S2;
	unsigned int S3;
	unsigned int S4;
	unsigned int S5;
	unsigned int S6;
	unsigned int S7;
	unsigned int S8;
	unsigned int S9;
	unsigned int S10;
	unsigned int S11;
	unsigned int S12;
	unsigned int S13;
	unsigned int S14;
	unsigned int S15;
	unsigned int S16;
	unsigned int S17;
	unsigned int S18;
	unsigned int S19;
	unsigned int S20;
	unsigned int S21;
	unsigned int S22;
	unsigned int S23;
	unsigned int S24;
	unsigned int S25;
	unsigned int S26;
	unsigned int S27;
	unsigned int S28;
	unsigned int S29;
	unsigned int S30;
	unsigned int S31;
};

struct fp_double_precision_registers {
	unsigned long long D0;
	unsigned long long D1;
	unsigned long long D2;
	unsigned long long D3;
	unsigned long long D4;
	unsigned long long D5;
	unsigned long long D6;
	unsigned long long D7;
	unsigned long long D8;
	unsigned long long D9;
	unsigned long long D10;
	unsigned long long D11;
	unsigned long long D12;
	unsigned long long D13;
	unsigned long long D14;
	unsigned long long D15;
};

#endif

