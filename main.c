#include "board.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int moves, count = 1;
	printf("Введите количество ходов:");
	if(scanf("%d",&moves)!=1){
		printf("Неверные данные\n");
		return 0;
	}
	getchar();

	board * mass = (board *)malloc(sizeof(board)*8*8);

	output(mass);

    printf("__________________________________________________________________\n");
    printf("Формат входных данных должен быть в виде:LetterNumber-LetterNumber\n");
    printf ("Введите имя пешки, которой хотите походить и через тире место куда\n");
    printf("------------------------------------------------------------------\n");        
	outputGL(mass);
	while (moves > 0)
	{
        printf("___________________\n");
		printf ("Ход№%d:", count);
		coordinates(mass);
        printf("-------------------\n");
		outputGL(mass);
	    moves--;
	    count++;
	}
	return 0;
}
