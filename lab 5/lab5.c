/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lab5.h"

#define JEDI_NAME_LENGTH 6

int heap_usage = 0;//part 2b
char temp[25];
char temp2[25];


int main(){
//part 1a-----------------------------------------------
	printf("Part 1a---------------------------------------------------------\n");
	struct Names userName;

	//Asks user for first name
	printf("Please insert your first name\n");
	scanf("%s", temp);
	while(!test_name_length(temp)){//ensures name is at least 3 char
		printf("Name must be at least 3 characters. resubmit first name\n");
		scanf("%s", temp);
	}
	userName.first_name = allocate(sizeof(temp));//part 2c | use dynamic memory to assign names to variables
	strcpy(userName.first_name, temp);//copies user submitted name into userName struct

	//Asks user for last name
	printf("Please insert your last name\n");
	scanf("%s", temp);
	while(!test_name_length(temp)){//ensures name is at least 3 char
		printf("Name must be at least 3 characters. resubmit last name\n");
		scanf("%s", temp);
	}
	userName.last_name = allocate(sizeof(temp));
	strcpy(userName.last_name, temp);

	jedi_name(&userName);//part 2cb | use structure in jedi_name function
	printf("Your Jedi Name is: '%s'\n", userName.jedi_name);

	deallocate(userName.first_name, sizeof(temp));//deallocates memory
	deallocate(userName.last_name, sizeof(temp));
	deallocate(userName.jedi_name, JEDI_NAME_LENGTH);
//part 1b--------------------------------------------------

	printf("Part 1b---------------------------------------------------------\n");
	//Appends user submitted name to the file
	FILE *ptr = fopen("nameFile.txt", "a");
	printf("Please insert a unique first and last name | Example: HENRY FORD'\n");
	scanf("%s %s", temp, temp2);
	fprintf(ptr, "%s %s\n", temp, temp2);
	fclose(ptr);
	
	//reads the file into dynamic memory | produces a Jedi name | deallocates the memory
	FILE *name_file_pointer = fopen("nameFile.txt", "r");
	char c;
	int i = 0;
	do{
		c = fgetc(name_file_pointer);
		temp[i] = c;
		if(feof(name_file_pointer)) break;


		if(c == ' '){
			temp[i] = '\0';
			userName.first_name = allocate(sizeof(temp));
			strcpy(userName.first_name, temp);
			i = -1;//At the end of the loop, the -1 will be incremented up to 0
		}
		else if(c == '\n'){
			temp[i] = '\0';
			userName.last_name = allocate(sizeof(temp));
			strcpy(userName.last_name, temp);
			jedi_name(&userName);
			printf("\n\nName = %s %s | Jedi name = %s\n\n",userName.first_name, userName.last_name, userName.jedi_name);
			deallocate(userName.first_name, sizeof(temp));
			deallocate(userName.last_name, sizeof(temp));
			deallocate(userName.jedi_name, JEDI_NAME_LENGTH);
			i = -1;
		}
		i++;
	}while(1);
	fclose(name_file_pointer);
			
}




/*-------------------------------------------------------------
	Creates and returns a pointer from dynamic memory
--------------------------------------------------------------*/
void *allocate(unsigned int size){//part 2a
	heap_usage+= size;//part 2b
	void *temp = malloc(size);
	assert(temp != NULL && "No more memory in heap\n");
	printf("\t\tBYTES ALLOCATED = %i | BYTES IN USE = %i\n",size, heap_usage);//part 2b
	return temp;
}	

/*-------------------------------------------------------------
	-Frees memory in the heap
	-Changes variable that tracks dynamic memory
	-Prints Message about dynamic memory freed and still in use
--------------------------------------------------------------*/
void deallocate(void *toBeFreed, int size){//part 2a
		heap_usage-=size;//part 2b
		free(toBeFreed);
		toBeFreed = NULL;
		printf("\t\tBYTES FREED = %i | BYTES STILL IN USE = %i\n", size, heap_usage);//part 2b
}

/*-------------------------------------------------------------
	-Takes a struct Names pointer as an argument
	-Takes first_name and last_name from Names structure to create a jedi name
	-allocates memory from heap for jedi_name property on the structure and copies the jedi name into it
--------------------------------------------------------------*/
void jedi_name(struct Names *name){
		char temp[JEDI_NAME_LENGTH] = {0};
		strncpy(temp, name->last_name, 3);
		temp[3] = name->first_name[0];
		temp[4] = name->first_name[1];
		name->jedi_name = allocate(sizeof(temp));
		strcpy(name->jedi_name, temp);
}

/*-------------------------------------------------------------
	-Tests to see if a name string is long enough
--------------------------------------------------------------*/
int test_name_length(char *name){
	int i = 0;
	while(name[i] != '\0')i++;
	return (i > 2)? 1: 0;
}

