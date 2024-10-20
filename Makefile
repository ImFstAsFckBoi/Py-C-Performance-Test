CFLAGS = -Wall -Wextra
CC = clang


default: main main_t

main: main.c bench.so
	$(CC) $(CFLAGS) main.c bench.so -o $@

main_t: main_t.c bench.so
	$(CC) $(CFLAGS) main_t.c bench.so -lpthread -o $@

bench.so: bench.c
	$(CC) $(CFLAGS) bench.c -lm -fPIC -shared -o $@

.PHONY: clean
clean:
	rm -f bench.so main main_t
