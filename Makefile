c-: lexer.o parser.o symtab.o
	$(CC) -o $@ $^

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

lexer.l: parser.h

.PHONY: clean run
clean:
	rm -f *.o lexer.c parser.c parser.h c-

run: c-
	./c-
