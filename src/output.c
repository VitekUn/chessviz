#include "board.h"
#include <stdio.h>
void outputGL(board * mass){
	int i, j;
    printf ("   A B C D E F G H\n");
    printf ("  _________________\n");
    for (i = 0; i < 8; i++)
    {
		printf("%d |", i + 1);
		for (j = 0; j < 8; j++)
		{
    		printf("%c|", mass[i*8+j].tip);
    	}
        printf (" %d\n", i + 1);
    }
    printf ("  _________________\n");
    printf ("   A B C D E F G H\n");
}