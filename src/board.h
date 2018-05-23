#ifndef  BOARD_H
#define  BOARD_H

typedef struct board {
    char tip;
    int color;
}board;


void output(board * mass);

void outputGL(board * mass);

void coordinates(board * mass);

int * decode(char letter, int number, char letter2, int number2);

void move(board * mass, int index_letter1, int index_number1, int index_letter2, int index_number2);

int data_checking(char letter1, char letter2, char tire, int number1, int number2);

int color_checking(board * mass, int str, int stl, int color);

int win_checking(board * mass);

int move_checking(board * m, int n1, int l1, int n2, int l2);

#endif