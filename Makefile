GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = mystring.o main.o
HDRS = mystring.h
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --verbose --log-file=

mystring: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f mystring $(OBJS) outputs/output_* logs/log* *~

testall: test0 test1 test2

test0: mystring
	$(VAL)logs/log0 ./mystring strlen inputs/input outputs/output_length
	diff -q outputs/output_length expected/expected_length

test1: mystring
	$(VAL)logs/log1 ./mystring countchar inputs/input outputs/output_countchar
	diff -q outputs/output_countchar expected/expected_countchar

test2: mystring
	$(VAL)logs/log2 ./mystring strup inputs/input outputs/output_upper
	diff -q outputs/output_upper expected/expected_upper
