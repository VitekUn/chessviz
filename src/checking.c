#include <stdio.h>
#include "board.h"

int data_checking(char letter1, char letter2, char tire, int number1, int number2){
        int i, flag = 0;
        char abc[8] = {'A','B','C','D','E','F','G','H'};
        int numb[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        if(tire != '-')
        {
            printf ("Ошибка формата\n");
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
        if (flag != 4){
        	printf("Ошибка данных\n");
           return -1;      
        }
        else
            return 0;
}

int color_checking(board * mass, int str, int stl, int color){
		if(mass[str*8 + stl].color == color)
			return 1;
		return 0;
}

int win_checking(board * mass){
    int i, j, flag = 0;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (mass[i*8 + j].tip == 'k' || mass[i*8 + j].tip == 'K')
                flag++;
    if(flag == 2)
        return 0;
    return 1;
}

int move_checking(board * m, int n1, int l1, int n2, int l2){
    int i, j;
    if (m[n1*8 + l1].color == m[n2*8 + l2].color)
        return 0;
//пешка
    if (m[n1*8 + l1].tip == 'p' || m[n1*8 + l1].tip == 'q')
    {
        if((m[n1*8 + l1].color == 1 && m[n2*8 + l2].color == 0) || (m[n1*8 + l1].color == 0 && m[n2*8 + l2].color == 1))
        { 
            if (((l1 + 1) == l2) && ((n1 - 1) == n2))
                return 1;
            if (((l1 + 1) == l2) && ((n1 + 1) == n2))
                return 1;
            if (((l1 - 1) == l2) && ((n1 - 1) == n2))
                return 1;
            if (((l1 - 1) == l2) && ((n1 + 1) == n2))
                return 1;
        }
        if (m[n2*8 + l2].color == 2)
        {
            if (n1 == 1 && n2 < 4 && n2 > 1 && l1 == l2 && m[(n1 + 1)*8 + l1].color == 2)
                return 1;
            if (n1 == 6 && n2 > 3 && n2 < 6 && l1 == l2 && m[(n1 - 1)*8 + l1].color == 2)
                return 1;
            if (m[n1*8 + l1].tip == 'p' && n1 != 6 && n2 == (n1 - 1) && l1 == l2) 
                return 1;
            if (m[n1*8 + l1].tip == 'q' && n1 != 1 && n2 == (n1 + 1) && l1 == l2)
                return 1;
        }
    }    
//слон
    if (m[n1*8 + l1].tip == 's' || m[n1*8 + l1].tip == 'S')
    {        
        if (l1 == l2 && n1 < n2)
        { 
            for (i = n1 + 1; i < n2; i++)
                if (m[i*8 + l1].color != 2)
                    return 0;
            return 1;
        }
        if (l1 == l2 && n1 > n2)
        { 
            for (i = n2 + 1; i < n1; i++)
                if (m[i*8 + l1].color != 2)
                    return 0;
            return 1;
        }
        if (l1 < l2 && n1 == n2)
        {
            for (i = l1 + 1; i < l2; i++)
                if (m[n1*8 + i].color != 2)
                    return 0;
            return 1;
        }
        if (l1 > l2 && n1 == n2)
        {
            for (i = l2 + 1; i < l1; i++)
                if (m[n1*8 + i].color != 2)
                    return 0;
            return 1;
        }
    }
//конь
    if (m[n1*8 + l1].tip == 'h' || m[n1*8 + l1].tip == 'H')
    {
        if(((n2 == (n1 + 1)) || (n2 == (n1 - 1))) && (l2 == (l1 + 2) || (l2 == (l1 - 2))))
            return 1;
        if(((n2 == (n1 + 2)) || (n2 == (n1 - 2))) && ((l2 == (l1 + 1)) || (l2 == (l1 - 1))))
            return 1;
    }
//ферзь
    if (m[n1*8 + l1].tip == 'f' || m[n1*8 + l1].tip == 'F')
    {
        if ((n1 - n2) == (l1 - l2))
        {
            i = n1 - 1;
            j = l1 - 1;
            while (i > n2 && j > l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i--;
                j--;
            }
            return 1;
        }    
        if ((n1 - n2) == (l2 - l1))
        {
            i = n1 - 1;
            j = l1 + 1;
            while (i > n2 && j < l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i--;
                j++;
            }
            return 1;
        }          
        if ((n2 - n1) == (l1 - l2))
        {
            i = n1 + 1;
            j = l1 - 1;
            while (i < n2 && j > l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i++;
                j--;
            }
            return 1;
        }  
        if ((n2 - n1) == (l2 - l1))
        {
            i = n1 + 1;
            j = l1 + 1;
            while (i < n2 && j < l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i++;
                j++;
            }
            return 1;
        }  
   }
//король
    if(m[n1*8 + l1].tip == 'k' || m[n1*8 + l1].tip == 'K')
    {
        if ((((n2 - n1) == 1) || ((n1 - n2) == 1)) && l2 == l1)
            return 1;
        if (n1 == n2 && (((l1 - l2) == 1) || (l2 - l1) == 1))
            return 1;
        if ((n2 - n1 == 1) && (((l2 - l1) == 1) || ((l1 - l2) == 1)))
            return 1;
        if ((n1 - n2 == 1) && (((l2 - l1) == 1) || ((l1 - l2) == 1)))
            return 1;
    }
//ладья
    if(m[n1*8 + l1].tip == 'l' || m[n1*8 + l1].tip == 'L')
    {
        if (l1 == l2 && n1 < n2)
        { 
            for (i = n1 + 1; i < n2; i++)
                if (m[i*8 + l1].color != 2)
                    return 0;
            return 1;
        }
        if (l1 == l2 && n1 > n2)
        { 
            for (i = n2 + 1; i < n1; i++)
                if (m[i*8 + l1].color != 2)
                    return 0;
            return 1;
        }
        if (l1 < l2 && n1 == n2)
        {
            for (i = l1 + 1; i < l2; i++)
                if (m[n1*8 + i].color != 2)
                    return 0;
            return 1;
        }
        if (l1 > l2 && n1 == n2)
        {
            for (i = l2 + 1; i < l1; i++)
                if (m[n1*8 + i].color != 2)
                    return 0;
            return 1;
        }
        if ((n1 - n2) == (l1 - l2))
        {
            i = n1 - 1;
            j = l1 - 1;
            while (i > n2 && j > l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i--;
                j--;
            }
            return 1;
        }    
        if ((n1 - n2) == (l2 - l1))
        {
            i = n1 - 1;
            j = l1 + 1;
            while (i > n2 && j < l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i--;
                j++;
            }
            return 1;
        }          
        if ((n2 - n1) == (l1 - l2))
        {
            i = n1 + 1;
            j = l1 - 1;
            while (i < n2 && j > l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i++;
                j--;
            }
            return 1;
        }  
        if ((n2 - n1) == (l2 - l1))
        {
            i = n1 + 1;
            j = l1 + 1;
            while (i < n2 && j < l2)
            {
                if(m[i*8 + j].color != 2)
                    return 0;
                i++;
                j++;
            }
            return 1;
        }  
    }
    return 0;
}
