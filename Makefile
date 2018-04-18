all: src

src: build/main.o build/board_initialization.o build/move.o build/decode.o build/output.o 
	gcc -Wall -Werror build/main.o build/board_initialization.o build/move.o build/decode.o build/output.o -o src

build/main.o: main.c
	gcc -Wall -Werror -c main.c -o build/main.o 

build/board_initialization.o: board_initialization.c
	gcc -Wall -Werror -c board_initialization.c -o build/board_initialization.o 

build/move.o: move.c
	gcc -Wall -Werror -c move.c -o build/move.o 

build/decode.o: decode.c
	gcc -Wall -Werror -c decode.c -o build/decode.o

build/output.o: output.c
	gcc -Wall -Werror -c output.c -o build/output.o

clean: 
	rm -rf build/*.o
