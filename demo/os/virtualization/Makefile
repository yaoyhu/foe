CFLAGS := -Wall -O0

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=)

# Default target
all: $(OBJS)

%: %.c
	cc $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) a.out
	rm -rf *.dSYM

.PHONY: all clean
