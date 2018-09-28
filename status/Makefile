
all: status

status:
	$(CC) -lX11 status.c -o $@

clean:
	rm -f status

install:
	cp -a status $(PREFIX)/bin/mintangel-status

uninstall:
	rm $(PREFIX)/bin/mintangel-status
