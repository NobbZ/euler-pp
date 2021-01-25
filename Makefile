SRCS = $(shell find src -type f -name '*.cpp')
TARGET = euler
OBJS = $(SRCS:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Wno-unused-parameter -Werror \
	-ansi -pedantic \
	-std=c++20 \
	-DDEBUG -D_GNU_SOURCE \
	-Iinclude
LD = g++
LDLIBS = -lm

.SUFFIXES: .cpp .o

all: $(TARGET)

euler: $(OBJS)
	$(LD) $(OBJS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $*.o $*.cpp

clean:
	rm -fv $(OBJS) $(TARGET)
