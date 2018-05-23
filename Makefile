all: bin/prog bin/test

bin/prog: build/main.o build/board_initialization.o build/move.o build/decode.o build/output.o build/checking.o
	gcc -Wall -Werror build/checking.o build/main.o build/board_initialization.o build/move.o build/decode.o build/output.o -o bin/prog

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

build/board_initialization.o: src/board_initialization.c
	gcc -Wall -Werror -c src/board_initialization.c -o build/board_initialization.o 

build/move.o: src/move.c
	gcc -Wall -Werror -c src/move.c -o build/move.o 

build/decode.o: src/decode.c
	gcc -Wall -Werror -c src/decode.c -o build/decode.o

build/output.o: src/output.c
	gcc -Wall -Werror -c src/output.c -o build/output.o

build/checking.o: src/checking.c
	gcc -Wall -Werror -c src/checking.c -o build/checking.o

bin/test: build/test.o build/checking.o build/board_initialization.o build/ctest.o build/move.o build/output.o
	gcc -Wall build/test.o build/checking.o build/board_initialization.o build/ctest.o build/move.o build/output.o -o bin/test

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o build/ctest.o -Ithirdparty

test: bin/test
	bin/test

.PHONY: clean
clean:
	rm -rf build/*.o
