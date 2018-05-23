#include "board.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char letter1, letter2, tire;
    int number1, number2, fl = 1;
    int * index;
    int index_letter1, index_number1, index_letter2, index_number2, color = 0, check_win = 0, count = 0, check_move = 0;
	board * mass = (board *)malloc(sizeof(board)*8*8);

	output(mass);

    printf("__________________________________________________________________\n");
    printf("Формат входных данных должен быть в виде:LetterNumber-LetterNumber\n");
    printf ("Введите имя фигуры, которой хотите походить и через тире место куда\n");
    printf("------------------------------------------------------------------\n");        
	outputGL(mass);
	while (check_win == 0)
	{		
		while (color == 0)
		{ 
			while (check_move == 0 && color == 0)
			{
 	        	printf("___________________\n");
    	    	if (count%2 == 0)
					printf ("Ход белых фигур:");
				else
					printf("Ход чёрных фигур:");
				while (fl != 0)
				{
	        		scanf("%c%d", &letter1, &number1);
	        		scanf ("%c", &tire);
	        		scanf("%c%d", &letter2, &number2);
	        		while(getchar() != '\n');
	        		fl = data_checking(letter1, letter2, tire, number1, number2);
	        	}
		    	fl = 1;
	        	index = decode(letter1, number1, letter2, number2);
	        	index_letter1 = index[0];
	        	index_number1 = index[1];
	        	index_letter2 = index[2];
	        	index_number2 = index[3];
				color = color_checking(mass, index_number1, index_letter1, count%2);
				check_move = move_checking(mass, index_number1, index_letter1, index_number2, index_letter2);
				if (check_move == 0)
					printf("Ход не возможен\n");
				if ((check_move == 1 && color == 0) || (check_move == 0 && color == 1))
				{
					check_move = 0;
					color = 0;
				}			
			}
		}		
        if (check_move == 1)
	        move(mass, index_letter1, index_number1, index_letter2, index_number2);
        printf("-------------------\n");
		outputGL(mass);
	    count++;
	    check_move = 0;
	    color = 0;
	    check_win = win_checking(mass);	
	}
	free(mass);
	return 0;
}
