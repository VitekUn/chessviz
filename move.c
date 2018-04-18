#include <stdio.h>
#include "board.h"
#include <stdlib.h>
void coordinates(board * mass){
        char letter1, letter2;
        int number1, number2;
        int fl = 1;
        int * index;
        char tire;
        while (fl != 0){
        scanf("%c%d", &letter1, &number1);
        scanf ("%c", &tire);
        scanf("%c%d", &letter2, &number2);
        while(getchar() != '\n');
        fl = data_checking(letter1, letter2, tire, number1, number2);
        }
        index = decode(letter1, number1, letter2, number2);
        move(mass, index);
}

void move(board * mass, int * index){
        char buffer;
        int index_letter1, index_number1, index_letter2, index_number2;
        index_letter1 = index[0];
        index_number1 = index[1];
        index_letter2 = index[2];
        index_number2 = index[3];
        if (mass[index_number1*8 + index_letter1].tip != 'p' && mass[index_number1*8 + index_letter1].tip != 'q'){
            printf("Вы ходите не пешкой\n");
            return;
        }
        buffer = mass[index_number1*8 + index_letter1].tip;
        mass[index_number1*8 + index_letter1].tip = mass[index_number2*8 + index_letter2].tip;
        mass[index_number2*8 + index_letter2].tip = buffer;
}

int data_checking(char letter1, char letter2, char tire, int number1, int number2){
        int i, flag = 0;
        char abc[8] = {'A','B','C','D','E','F','G','H'};
        int numb[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        if(tire != '-')
        {
            printf ("Ошибка введённых данных\n");
            printf("\n");
            return -1;
        }
        for (i = 0; i < 8; i++){
                if (letter1 == abc[i]) 
                        flag++;
                if  (letter2 == abc[i])
                        flag++;
                if (number1 == numb[i])
                        flag++;
                if (number2 == numb[i])
                        flag++;
        }
        if (flag != 4)
           return -1;      
        else
            return 0;
}
