#include <stdio.h>
int * decode(char letter, int number, char letter2, int number2){
	int i, index_letter, index_letter2;
	static int index[4];
	char abc[8] = {'A','B','C','D','E','F','G','H'};
	for (i = 0; i < 8; i++)
	{
		if(letter == abc[i])
			index_letter = i;
		if(letter2 == abc[i])
			index_letter2 = i;
	}
	index[0] = index_letter;
	index[1] = number - 1;
	index[2] = index_letter2;
	index[3] = number2 - 1;
	return index;
}
