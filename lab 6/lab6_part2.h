#ifndef NULL
	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include <time.h>
#endif

struct node{
	int rndm_num;
	struct node *next;	
	struct node *prev;
};
struct linked_list{
	struct node *head;
	struct node *tail;
};


/*----------------------------------------------------
Creates linked list
	How to use:
	1. stuct linked_list *start = createList();

-----------------------------------------------------*/
struct linked_list *createList(){
	struct linked_list *buf;
	buf = malloc(sizeof(struct linked_list));
	buf->head = NULL;
	buf->tail = NULL;
	return buf;
}
	

/*-----------------------------------------------------
Creates a node for a doubly linked list. Will assign node to end of the list
	How to use:
	1. Must have previously created a linked list structure
	2. createNode(list, random_number)
------------------------------------------------------*/
void createNode(struct linked_list *list, int random_number){
	random_number %= 22;
	//use if this is the first entry into the list
	if(!list->head){
		list->head = malloc(sizeof(struct node));
		list->head->rndm_num = random_number;
		list->head->next = NULL;
		list->head->prev = NULL;
		list->tail = list->head;
	}
	else{
		list->tail->next = malloc(sizeof(struct node));
		list->tail->next->rndm_num = random_number;
		list->tail->next->prev = list->tail;
		list->tail->next->next = NULL;
		list->tail = list->tail->next;
		printf("random_number = %i\n", random_number);
	}
}

/*-----------------------------------------------------
Inserts a node at the specified index of a linked list. The node's rndm_num element will be assigned random_number
	How to use:
	1. Create a linked list pointer structer
		a. struct linked_list *list 
	2. Set up the list with the createList function
		a. list = createList();
	3. insert(list, 3, 444);
------------------------------------------------------*/
void insert(struct linked_list *list, int index, int random_number){
	struct node *space_left = list->head;
	
	if(!space_left){
		assert(0 && "Error, going outside the boundry of the list");
	}
	while(--index){
		if(!space_left->next){
			assert(0 && "Error, going outside the boundry of the list");
		}
		space_left = space_left->next;
	}
	struct node *new = malloc(sizeof(struct node));
	new->next = space_left->next;
	new->prev = space_left;
	space_left->next = new;
	new->rndm_num = random_number;
	if(!new->next){
		list->tail = new;
	}		
}
/*-----------------------------------------------------
Iterates list. Prints out random number from each node
	How to use:
	1. iterate(list);
------------------------------------------------------*/

void iterate(struct linked_list *list){
	struct node *temp = list->head;
	while(temp){
		printf("random number = %i\n", temp->rndm_num);
		temp = temp->next;
	}
}

/*-----------------------------------------------------
Deletes a node at the specified index
	How to use:
	1. delete(list, 3);
------------------------------------------------------*/
void delete(struct linked_list *list, int index){
	struct node *head = list->head;
	index--;
	while(--index){
		if(head == NULL){
			printf("Cannot delete. Index does not exist\n");
			return;
		}
		head = head->next;
	}
	struct node *temp = head->next;
	head->next = head->next->next;
	free(temp);
}
/*-----------------------------------------------------
Front is a useless and redundant function that only exists to satisfy requirements. It will return the list's head
	How to use:
	1. struct node *head = Front(list);
------------------------------------------------------*/
struct node *Front(struct linked_list *list){
	return list->head;
}

/*-----------------------------------------------------
Searches list from head to tail for value
	How to use:
	1. searchFront(list, 5);
------------------------------------------------------*/
struct node *searchFront(struct linked_list *list, int search_val){
	struct node *temp = list->head;
	int i = 0;
	while(temp){
		if(temp->rndm_num == search_val){
			printf("found %i in list at step: %i\n", search_val, i);
			return temp;
		}
		temp = temp->next;
		i++;
	}
	printf("searchFront: could not find value\n");
}

/*-----------------------------------------------------
Searches list from tail to head for value
	How to use:
	1. searchBack(list, 5);
------------------------------------------------------*/
struct node *searchBack(struct linked_list *list, int search_val){
	struct node *temp = list->tail;
	int i = 0;
	while(temp){
		if(temp->rndm_num == search_val){
			printf("found %i in list at step: %i\n", search_val, i);
			return temp;
		}
		if(temp == list->head)break;
		temp = temp->prev;
		i++;
	}
	printf("searchBack: could not find value\n");
}

/*-----------------------------------------------------
deletes linked lists
	How to use:
	1. delete_all(list);
------------------------------------------------------*/
void delete_all(struct linked_list *list){
	struct node *temp = list->head;
	struct node *temp2;
	free(list);
	while(temp){
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
