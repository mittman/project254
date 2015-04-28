CC = g++
CFLAGS += -g
CFLAGS += -Wall
INSTALL = install
PREFIX := /usr/bin

.PHONY: all parser clean install uninstall

all: parser

parser:  parser.o
	$(CC) -o $@ $^

clean: 
	$(RM) parser *.o *~

install: all
	$(INSTALL) -d $(DESTDIR)$(PREFIX)
	$(INSTALL) -m 755 parser $(DESTDIR)$(PREFIX)/parser

uninstall:
	$(RM) $(DESTDIR)$(PREFIX)/parser
