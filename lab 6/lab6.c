/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/

#include "lab6_part1.h"
#include "lab6_part2.h"
#include "lab6_part3.h"

int main(){
//part1-------------------------------------------------------------
	printf("PART 1---------------------------------------\n");
	struct train head = {0, NULL};
	printf("Insert how many trains do you want\n");
	
	int user_response;
	scanf("%i", &user_response);
	allocate_trains(&head, user_response);
	printf("How much would you like your trains to weigh must be 0 or 1.\n");
	scanf("%i", &user_response);
	cycle_weigth(&head, user_response);
	read_deallocate(&head);

//part2--------------------------------------------------------------
	printf("\nPART 2A---------------------------------------\n");
	struct linked_list *list = createList();
	int i = 0;
	srand(time(NULL));
	while(i++ <= 10){
		createNode(list, rand());
	}
	printf("A linked list was created. It's values are printed above\n");
	i = 0;
	delete_all(list);


	printf("\nPART 2B---------------------------------------\n");
	struct linked_list *doubly_list = createList();
	i = 0;
	srand(time(NULL));
	iterate(doubly_list);
	while(i++ <= 10){
		createNode(doubly_list, rand());
	}
	printf("A list of ten numbers was created above in a linked list. Guess what the number is\n");
	scanf("%i", &user_response);
	searchFront(doubly_list, user_response);
	searchBack(doubly_list, user_response);
	delete_all(doubly_list); 


//part3--------------------------------------------------------------
	
	printf("\nPART 3A---------------------------------------\n");

	int response[5];
	printf("Insert 5 space seperated values and press enter\n");
	scanf("%i %i %i %i %i", &response[0], &response[1], &response[2], &response[3], &response[4]);

	struct stack *a_stack= createList_stack();
	int j = 0;
	while(j < 5){
		push(a_stack, response[j]);
		printf("An element(%i) has been added to the stack\n", response[j]);
		j++;
	}
	while(j--){
		pop(a_stack);
		printf("the %i element in the stack has been removed\n", j);
	}
	free(a_stack);
	
	printf("\nPart 3B----------------------------------------\n");
	struct queue *a_queue = createList_queue();
	j = 0;
	printf("Insert 5 space seperated values and press enter\n");
	scanf("%i %i %i %i %i", &response[0], &response[1], &response[2], &response[3], &response[4]);

	while(j< 5){
		printf("response[%i] = %i\n", j, response[j]);
		enqueue(a_queue, response[j]);
		j++;
	}
	printf("Your values are:\n");
	while(j--){
		dequeue(a_queue);
	}
	free(a_queue);

}
