c-: lexer.o parser.o symtab.o
	$(CC) -o $@ $^

parser.c parser.h: parser.y
	yacc -dy -o parser.c parser.y

lexer.l: parser.h

.PHONY: clean run
clean:
	rm -f *.o lexer.c parser.c parser.h c-

run: c-
	./c-
