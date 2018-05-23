#include "board.h"
#include <stdio.h>

void move(board * mass, int index_letter1, int index_number1, int index_letter2, int index_number2){
        board buffer;
        if (mass[index_number2*8 + index_letter2].tip == ' ')
        {
            buffer = mass[index_number1*8 + index_letter1];
            mass[index_number1*8 + index_letter1] = mass[index_number2*8 + index_letter2];
            mass[index_number2*8 + index_letter2] = buffer;
        }
        else
        {
            mass[index_number2*8 + index_letter2] = mass[index_number1*8 + index_letter1];
            mass[index_number1*8 + index_letter1].tip = ' ';
            mass[index_number1*8 + index_letter1].color = 2;
        }
}


