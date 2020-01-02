#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Part 1------------------------------------------------------

//Structures-------------
struct Data{
	int number;
};

struct tree{
	struct node *root;
	int depth;
};

struct node{
	struct node *left;
	struct node *right;
	struct node *parent;
	struct Data *data;
};

//Functions---------------
/*Initializes a tree struct
	How to use:
		1. struct tree *newtree = createTree();
*/
struct tree *createTree(){
	struct tree *temp = malloc(sizeof(struct tree));
	temp->root = NULL;
	return temp;
}

/*Creates initial tree node
	How to use:
		1. declare a tree struct using createTree()
		2. tree->left = createNode(tree);
*/
struct node* createNode(struct node* parent_node, int number){	
	struct node* temp = malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = malloc(sizeof(struct Data));
	temp->data->number = number;
	temp->parent = parent_node;
	return temp;
}

//Part 2------------------------------------------------------

/*Creates inserts value into binary tree
	How to use:
		1. declare a tree struct using createTree()
		2. insert(tree, number);
*/
void insert(struct tree *tree, int number){
	if(!tree->root){//If the root node has not been initialized, initialize it
		tree->root = createNode(NULL, number);
	}
	else{//Traverse the tree until it finds the appropriate spot to insert a node.
		struct node *temp = tree->root;
		while(1){
			if(temp->data->number == number){
				printf("The number is already on the tree\n");
				break;
			}
			else if(temp->data->number > number){			
				if(!temp->left){
					temp->left = createNode(temp, number);
					break;
				}
				temp = temp->left;
			}
			else{
				if(!temp->right){
					temp->right = createNode(temp, number);
					break;
				}
				temp = temp->right;
			}
		}
	}
}

/*searches a tree for a value
	How to use:
		1. declare a tree struct using createTree()
		2. search(number, tree);
*/
struct node *search(int number, struct tree *tree){
	struct node *temp = tree->root;
	while(temp){//will search tree until it finds the value or cannot go any deeper
		if(temp->data->number == number){
			printf("Found number (%i). \n \
			        0 is shorthand for NULL.\n \
				It's parent node holds the value %i.\n \
				Its right child node holds the value %i\n \
				Its left child node holds the value %i\n",
				temp->data->number, 
				(temp->parent)?temp->parent->data->number: 0, 
				(temp->right)?temp->right->data->number: 0, 
				(temp->left)?temp->left->data->number:0 );
			break;
		}
		else if(temp->data->number > number){
			if(!temp->left){temp=NULL;break;}
			temp = temp->left;
		}
		else {
			if(!temp->right){temp=NULL;break;}
			temp = temp->right;
		}
	}
	if(!temp)printf("Couldn't find value\n");
	return temp;
}


//Miscellaneous functions


/*frees a tree from memory
	How to use:
		1. free_tree(tree);
*/
void free_tree(struct tree *tree){
	struct node *temp = tree->root;
	struct node *parent;
	int i = 0;
	int j = 0;
	while(1){
		if(temp->right){
			temp = temp->right;
		}
		else if(temp->left){
			temp = temp->left;
		}
		else if(!temp->left && !temp->right){
			if(temp == tree->root){
				free(temp->data);
				free(temp);
				break;
			}
			parent = temp->parent;;
			if(temp == parent->right){	
				free(temp->data);
				free(temp);
				parent->right = NULL;
			}
			else{
				free(temp->data);
				free(temp);
				parent->left = NULL;
			}	
			temp = parent;
		}
	}
	free(tree);
}
