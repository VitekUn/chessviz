#include "board.h"
#include <stdio.h>
void output(board * mass){
	int j;
	char whitef[8] = {'s','h','f','k','l','f','h','s'};
	char blackf[8] = {'S','H','F','L','K','F','H','S'};
	char whitep[8] = {'q','q','q','q','q','q','q','q'};
	char blackp[8] = {'p','p','p','p','p','p','p','p'};

    for (j = 0; j < 8; j++)
	{
		mass[j].tip = whitef[j];
		mass[j].color = 0;
		mass[7*8 + j].tip = blackf[j];
		mass[7*8 + j].color = 1;
		mass[1*8 + j].tip = whitep[j];
		mass[1*8 + j].color = 0;
		mass[6*8 + j].tip = blackp[j];
		mass[6*8 + j].color = 1;
		mass[2*8 + j].tip = ' ';
		mass[2*8 + j].color = 2;
		mass[3*8 + j].tip = ' ';
		mass[3*8 + j].color = 2;
		mass[4*8 + j].tip = ' ';
		mass[4*8 + j].color = 2;
		mass[5*8 + j].tip = ' ';
		mass[5*8 + j].color = 2;
	}
}

