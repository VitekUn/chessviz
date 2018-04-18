#ifndef BOARD_H
#define BOARD_H

typedef struct board {
	char s[2];
    char tip;
    int location[2];	
}board;

void output(board * mass);

void outputGL(board * mass);

void coordinates(board * mass);

int * decode(char letter, int number, char letter2, int number2);

void move(board * mass, int * index);

int data_checking(char letter1, char letter2, char tire, int number1, int number2);

#endif
