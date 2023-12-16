c-: lexer.o parser.o symtab.o ast.o codegen.o main.o
	$(CC) -o $@ $^

parser.c parser.h: parser.y lexer.h ast.h 
	bison -d -Wcounterexamples -o parser.c parser.y

lexer.l: lexer.h parser.h symtab.h
ast.o: ast.c ast.h lexer.h
codegen.o: codegen.c codegen.h ast.h
main.o: main.c lexer.h parser.h ast.h codegen.h

.PHONY: clean run
clean:
	rm -f *.o lexer.c parser.c parser.h c-

run: c-
	./c-
