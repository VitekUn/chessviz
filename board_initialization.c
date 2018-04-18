#include "board.h"
#include <stdio.h>
void output(board * mass){
	int i = 0, j;
	char abc[8] = {'A','B','C','D','E','F','G','H'};
	char whitef[8] = {'s','h','f','k','l','f','h','s'};
	char blackf[8] = {'S','H','F','L','K','F','H','S'};
	char whitep[8] = {'q','q','q','q','q','q','q','q'};
	char blackp[8] = {'p','p','p','p','p','p','p','p'};

       	for (j = 0; j < 8; j++)
	{
			mass[j].tip = whitef[j];
			mass[7*8+j].tip = blackf[j];
			mass[1*8+j].tip = whitep[j];
			mass[6*8+j].tip = blackp[j]; 
			mass[2*8+j].tip = ' ';
			mass[3*8+j].tip = ' ';
			mass[4*8+j].tip = ' ';
			mass[5*8+j].tip = ' ';
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			mass[i*8 + j].s[1] = i+1;
			mass[i*8 + j].s[0] = abc[j];
		}
	}
}

