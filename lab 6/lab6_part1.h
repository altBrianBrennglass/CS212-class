#ifndef NULL
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include <time.h>
#endif

struct train{
	int weight;
	struct train *next;
};

/*----------------------------------------------------
Creates a linked list of train structures
	How to use:
	1. allocate_trains(a pointer to your train structure, number of train structs you would like to add to your list)
-----------------------------------------------------*/
void allocate_trains(struct train *head, int number){
	struct train *temp;
	temp = head;
	int i = 1;
	while(i < number){
		temp->next = malloc(sizeof(struct train));
		temp = temp->next;
		i++;
	}
	temp = NULL;
}

/*----------------------------------------------------
Assigns a weight value to the trains in the linked list
	How to use:
	1. cycle_weight(pointer to train struct, any number)
-----------------------------------------------------*/
void cycle_weigth(struct train *head, int weight){
	struct train *temp = head;
	int i = 1;
	while(temp){
		temp->weight = weight % 2;
		printf("cart weight:%i\ncart address: %p\ncart number: %i\n\n", temp->weight, temp, i++);
		temp = temp->next;
	}
}
/*----------------------------------------------------
Deletes train structure(It used to printf each time it deallocated. This was removed)
	How to use:
	1. read_deallocate(a pointer to your train structure)
-----------------------------------------------------*/
void read_deallocate(struct train *head){
	struct train *temp = head->next;
	struct train *temp2;
	int i = 1;
	while(temp){
		temp2 = temp->next;
		free(temp);
		temp = temp2;
		printf("train #%i discarded\n", i++);
	}
	printf("train #%i discarded\n", i);
}

