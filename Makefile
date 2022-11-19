c-: lexer.o parser.o symtab.o ast.o
	$(CC) -o $@ $^

parser.c parser.h: parser.y lexer.h ast.h 
	bison -d -Wcounterexamples -o parser.c parser.y

lexer.l: lexer.h parser.h symtab.h
ast.o: ast.c ast.h

.PHONY: clean run
clean:
	rm -f *.o lexer.c parser.c parser.h c-

run: c-
	./c-
