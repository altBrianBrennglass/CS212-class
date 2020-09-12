#include <stdio.h>
#define BITS_IN_INT (int)sizeof(int) * 8

/*---------------------------------------------------------
convert_2_binary: inserts the binary value of the decimal into an array

	Takes 2 arguments:
		-a size 32 int array for holding 1s and 0s
		-a decimal int that is to be converted to binary
-----------------------------------------------------------*/
void convert_2_binary(int binary_holder[], int decimal){
	int i;
	for(i = 0; i < BITS_IN_INT; i++){
		binary_holder[i] = decimal >> (BITS_IN_INT - 1);
		if(binary_holder[i] == -1)binary_holder[i] =1;
		decimal <<= 1;
	}
}

/*---------------------------------------------------------
clear array: sets all values of the array to 0

	Takes 1 argument:
		-an integer array
-----------------------------------------------------------*/
void clear_array(int array[]){
	int x;
	for(x = 0; x < BITS_IN_INT; x++){
		array[x] = 0;
	}
}


/*---------------------------------------------------------
print_binary: prints out value from integer array. Will not print values until it first encounters a non-zero value

	Takes 1 argument:
		-a size 32 int array for holding 1s and 0s
-----------------------------------------------------------*/
void print_binary(int binary_array[]){
	int i = 0;
	while(!binary_array[i])i++;
	for(i; i < BITS_IN_INT; i++){
		printf("%d",binary_array[i]);
	}
	printf("\n");
	clear_array(binary_array);
}
		
		
