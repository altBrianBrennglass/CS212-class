#ifndef NULL
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include <time.h>
#endif

struct stack{
	struct node *head;//struct node is defined in lab6_part2.h. This might not work on other processors
	struct node *tail;
};


/*----------------------------------------------------
Identical to createList function, but specific to stack structs
-----------------------------------------------------*/
struct stack *createList_stack(){
	struct stack *buf;
	buf = malloc(sizeof(struct stack));
	buf->head = NULL;
	buf->tail = NULL;
	return buf;
}


/*-----------------------------------------------------
This is identical to createNode in lab6_part2.h. This only exists because I am required to change my linked list struct to stack
------------------------------------------------------*/
void push(struct stack *list, int random_number){
	
	//use if this is the first entry into the list
	if(!list->head){
		list->head = malloc(sizeof(struct node));
		list->head->rndm_num = random_number;
		list->head->next = NULL;
		list->head->prev = NULL;
		list->tail = list->head;
		return ;
	}
	
	list->tail->next = malloc(sizeof(struct node));
	list->tail->next->rndm_num = random_number;
	list->tail->next->prev = list->tail;
	list->tail->next->next = NULL;
	list->tail = list->tail->next;
}

/*-----------------------------------------------------
Reads value off end of stack. Removes node
------------------------------------------------------*/
void pop(struct stack *list){
	struct node *temp = list->tail;
	if(!temp){
		printf("cannot delete anymore");
		return ;
	}
	list->tail->next = NULL;
	list->tail = list->tail->prev;
	printf("pop->rand_num = %i\n", temp->rndm_num);
	free(temp);
}

//Queues--------------------------------------------------


struct queue{
	struct node *head;//struct node is defined in lab6_part2.h. This might not work on other processors
	struct node *tail;
};

/*----------------------------------------------------
Identical to createList function, but specific to queues structs
-----------------------------------------------------*/
struct queue *createList_queue(){
	struct queue *buf;
	buf = malloc(sizeof(struct queue));
	buf->head = NULL;
	buf->tail = NULL;
	return buf;
}


/*-----------------------------------------------------
This is identical to createNode in lab6_part2.h. This only exists because I am required to change my linked list struct to queue
------------------------------------------------------*/
void enqueue(struct queue *list, int random_number){
	
	//use if this is the first entry into the list
	if(!list->head){
		list->head = malloc(sizeof(struct node));
		list->head->rndm_num = random_number;
		list->head->next = NULL;
		list->head->prev = NULL;
		list->tail = list->head;
		return ;
	}
	
	list->tail->next = malloc(sizeof(struct node));
	list->tail->next->rndm_num = random_number;
	list->tail->next->prev = list->tail;
	list->tail->next->next = NULL;
	list->tail = list->tail->next;
}

/*-----------------------------------------------------

/*-----------------------------------------------------
Reads value off current head node in queue. Removes node
------------------------------------------------------*/
void dequeue(struct queue *list){
	struct node *temp = list->head;
	if(!temp){
		printf("cannot delete anymore");
		return ;
	}
	list->head = list->head->next;
	printf("queue->rand_num = %i\n", temp->rndm_num);
	free(temp);
	
}
