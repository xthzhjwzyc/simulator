#ifndef SIMULATOR_H
#define SIMULATOR_H

// standard c
#include <stdio.h>
#include <string.h>

// linux platform
#include <time.h>
#include <assert.h>

// internal
#include <signal.h>

#define VERSION "0.0.0"

extern unsigned int clock_count;

#ifdef DEBUG
#define DBG(fmt, ...) printf("[Simulator] [%d] " fmt, clock_count, ##__VA_ARGS__);
#else
#define DBG(fmt, ...)
#endif

typedef unsigned int (*register_action_t)(unsigned int val, unsigned int opt);

#endif

