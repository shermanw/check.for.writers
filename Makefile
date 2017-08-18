all: check_for_writers

check_for_writers: check_for_writers.c
	gcc -D_GNU_SOURCE -Wall -o check_for_writers check_for_writers.c

install: all
	mkdir -p /usr/local/bin
	install -m 0755 -o root -g root -t /usr/local/bin check_for_writers
	setcap cap_lease+ep /usr/local/bin/check_for_writers

clean:
	rm -f check_for_writers

