all: simulator

CFLAGS = -g		\
	-O0		\
	-I./include	\
	-Wall

SRC += main.c
SRC += soc.c

SRC += ip/uart/uart.c
SRC += ip/armv7m/core.c

SRC += signals/clock.c
SRC += signals/interrupt.c
SRC += signals/bus.c
SRC += signals/pin.c
SRC += signals/reset.c

simulator: $(SRC)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm simulator
