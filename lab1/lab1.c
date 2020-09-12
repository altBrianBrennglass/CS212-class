/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/


#include <stdio.h>

int main(){

//Part 1 Part A ----------------------------------------------------------
	printf("Hello_world!\n\n");

//Part 2------------------------------------------------------------
//Part A -----------------------------------------------------------	
	printf("Part 1, evaluate polynomials\n");

	double x = 2.55;
	double first_equation = 3*x*x*x -5*x*x + 6;
	printf("3x^3 + 5x^2 + 6 = %f\n",first_equation);


	double second_equation = (3.31 * 1e-8 * 2.01 * 1e-7)/(7.16 * 1e-6 + 2.01 * 1e-8);
	printf("3.31 * 10^-8 * 2.01 * 10^-7 / (7.16 * 10^-6 + 2.01 * 10^-8) = %e\n\n", second_equation);

//Part B/C ------------------------------------------------------------
	printf("Part 2, finding the next multiples | typecasting\n");

	int i[3] = {365, 12258, 996};
	int j[3] = {7, 28, 4};

	int y;
	for( y = 0; y < 3; y++ ){
		int next_mult = i[y] + j[y] - i[y] % j[y];
		printf("When i = %i and j = %i:\n (int cast) = %i \n (double cast) = %f \n (char cast) = %c\n"\
				, i[y], j[y], (int) next_mult, (double)next_mult, (char) next_mult);

		printf("\n\n");
	}
	
}
