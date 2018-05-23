#include <ctest.h>
#include <board.h>
#include <stdlib.h>

CTEST(move_suite, dizertirstvo) // Проверка на возможность атаки на свои же фигуры
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	const int n1 = 0, l1 = 0, n2 = 1, l2 = 0;
	int check = move_checking(mass, n1, l1, n2, l2); 
	
	//THEN
	const int expected = 0;

	ASSERT_EQUAL(expected, check);
}

CTEST(move_suite, move_pawn) // Ход пешки 
{	
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	int check1 = move_checking(mass, 1, 0, 2, 0); //вперёд 
	
	int check3 = move_checking(mass, 1, 0, 2, 1); //по диагонали
	
	int n1 = 1, l1 = 0, n2 = 2, l2 = 0;
	move(mass, l1, n1, l2, n2);
	n1 = n2;
	n2 = 1;
	int check2 = move_checking(mass, n1, l1, n2, l2); //назад
	
	output(mass);
	move (mass, 0, 1, 0, 3); 					//проверка на возможность рубить пешкой
    move(mass, 1, 6, 1, 4);
	int check4 = move_checking(mass, 3, 0, 4, 1); 

	//THEN
	const int expected1 = 1;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
}

CTEST(move_suite, move_slon) // Ход слона
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	move(mass, 0, 1, 1, 2); 	
	int check1 = move_checking(mass, 0, 0, 4, 0); //Ход вперёд 
	move(mass, 0, 0, 0, 4); 	
	int check2 = move_checking(mass, 4, 0, 4, 4); //Ход вправо
	move(mass, 0, 4, 4, 4); 	
	int check3 = move_checking(mass, 4, 4, 4, 3); //Ход назад
	move(mass, 4, 4, 3, 4); 	
	int check4 = move_checking(mass, 4, 3, 4, 2); //Ход влево
	move(mass, 3, 4, 2, 4); 	
	int check5 = move_checking(mass, 4, 2, 6, 2); //Атака
	move(mass, 2, 4, 2, 6);
	int check6 = move_checking(mass, 6, 2, 4, 4); //Ход по диагонале 

	//THEN
	const int expected1 = 1;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 1;
	const int expected5 = 1;
	const int expected6 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
	ASSERT_EQUAL(expected6, check6);
}
CTEST(move_suite, move_hourse) // Ход коня
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	int check1 = move_checking(mass, 0, 1, 2, 0); //ход 
	move(mass, 1, 0, 0, 2);
	int check2 = move_checking(mass, 2, 0, 3, 2); //ход
	move(mass, 0, 2, 2, 3);
	move(mass, 2, 3, 4, 4);
	int check3 = move_checking(mass, 4, 4, 6, 3); //атака
	move(mass, 4, 4, 3, 6);
	move(mass, 3, 6, 4, 4);
	int check4 = move_checking(mass, 4, 4, 5, 4); //ложный ход
	int check5 = move_checking(mass, 4, 4, 5, 5); //ложный ход
	
	//THEN
	const int expected1 = 1;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 0;
	const int expected5 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_ferz) // Ход ферзь
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	move(mass, 1, 1, 1, 2);
	int check1 = move_checking(mass, 0, 2, 2, 0); //ход по диаголи  
	move(mass, 2, 0, 0, 2);
	int check2 = move_checking(mass, 2, 0, 6, 4); //атака 
	move(mass, 0, 2, 4, 6);
	int check3 = move_checking(mass, 6, 4, 4, 6); //атака
	move(mass, 4, 6, 6, 4);
	int check4 = move_checking(mass, 4, 6, 4, 4); //ложный ход
	int check5 = move_checking(mass, 4, 6, 3, 6); //ложный ход
	
	//THEN
	const int expected1 = 1;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 0;
	const int expected5 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_ladya) // Ход ладья
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	move(mass, 4, 1, 4, 3);
	int check1 = move_checking(mass, 0, 4, 2, 4); //ход вперёд  
	move(mass, 4, 0, 4, 2);
	int check2 = move_checking(mass, 2, 4, 5, 7); //по диагонали 
	move(mass, 4, 2, 7, 5);
	int check3 = move_checking(mass, 5, 7, 6, 7); //атака
	move(mass, 7, 5, 7, 6);
	int check4 = move_checking(mass, 6, 7, 6, 6); //атака влево
	move(mass, 7, 6, 6, 6);
	int check5 = move_checking(mass, 6, 6, 6, 4); //проверка на ложный ход
	move(mass, 6, 6, 4, 6);
	
	//THEN
	const int expected1 = 1;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 1;
	const int expected5 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_king) // Ход король
{
	//GIVEN
	board * mass = (board *)malloc(sizeof(board)*8*8);
	output(mass);
	
	//WHEN
	move(mass, 3, 1, 3, 3);
	int check1 = move_checking(mass, 0, 3, 1, 3); //ход вперёд  
	move(mass, 3, 0, 3, 1);
	move(mass, 3, 1, 3, 2);
	int check2 = move_checking(mass, 2, 3, 3, 2); //по диагонали 
	move(mass, 3, 2, 2, 3);
	int check3 = move_checking(mass, 3, 2, 4, 3); //по диагонали
	move(mass, 2, 3, 3, 4);
	move(mass, 3, 4, 3, 5);
	int check4 = move_checking(mass, 5, 3, 6, 3); //атака прямо
	move(mass, 3, 5, 3, 6);
	int check5 = move_checking(mass, 6, 3, 6, 2); //атака влево
	move(mass, 3, 6, 2, 6);
	int check6 = move_checking(mass, 6, 2, 4, 2); //ложный ход
		
	//THEN
	const int expected1 = 1;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 1;
	const int expected5 = 1;
	const int expected6 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
	ASSERT_EQUAL(expected6, check6);
}