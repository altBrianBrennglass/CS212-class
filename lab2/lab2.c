/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lab2.h"//contains the functions used to print decimal numbers as binary

int main(){
//Project 2, Part 1: find Fibonacci numbers	
	printf("\n\nPROJECT 2, PART 1-----------------------------------------------\n");

	int count_how_many;//To what Fibonacci number should count to
	printf("How many Fibonacci numbers would you like to count? Type 0 to choose the default: 20\n");
	scanf("%d", &count_how_many);//asks user how many fib numbers he would like to be displayed
	if(!count_how_many)count_how_many = 20;
	int i;
	int fib_queue[3] = {0, 1, 1};//holds previous values required for counting fibonacci sequence
	for(i = 0; i < count_how_many; i++){
		printf("The %d Fibonacci number is: %d\n", i, fib_queue[i % 3]);
		fib_queue[i % 3] = fib_queue[(i + 1) % 3] + fib_queue[(i + 2) % 3];
	}

//Project 2, Part 2: Bits & Bytes

//-----------Part A: Binary Printer----------------------------------------------------
	printf("\n\nPROJECT 2, PART 2, PART A-----------------------------------------------\n");

	printf("Would you like to insert custom values to convert into binary[Y/N]\n");
	char user_answer;
	scanf(" %c", &user_answer);
	int input_part2[5] = {0};//holds user input

	if(user_answer == 'N'){
		printf("Default values will be used: 2, 255, 32, -1, -255?\n");
		input_part2[0] = 2;
		input_part2[1] = 255;
		input_part2[2] = 32;
		input_part2[3] = -1;
		input_part2[4] = -255;
	}
	else{
		printf("Type in 5 space seperated number to be evaluated.\n");
		scanf("%d %d %d %d %d", &input_part2[0], &input_part2[1], &input_part2[2], &input_part2[3], &input_part2[4]);
	}

	
	int binary_holder[BITS_IN_INT] = {0};//holds array of 1s and 0s to be printed to the console
	for(i = 0; i < 5; i++){
		convert_2_binary(binary_holder, input_part2[i]);
		printf("The decimal number is: %d. In binary, the number is: ",input_part2[i]);
		print_binary(binary_holder);
	}

//------------Part B: Printing a Random Binary Value-----------------------------------
	printf("\n\nPROJECT 2, PART 2, PART B-----------------------------------------------\n");

	int random_number = rand() % INT_MAX + rand() % INT_MIN;
	convert_2_binary(binary_holder, random_number);
	printf("Your random number is: %d. In binary, the number is: ", random_number);
	print_binary(binary_holder);
}
