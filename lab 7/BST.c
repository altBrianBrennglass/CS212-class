/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/


#include "BST.h"

int main(){
//part 1
	struct tree *tree = createTree();
	FILE *data = fopen("data.txt", "r");

//part 3: the below code reads a file and inserts its content into a tree
	char temp[20] = {0};
	int i = 0;
	char num_from_file;
	while(!feof(data)){
		num_from_file = fgetc(data);
		if(isdigit(num_from_file)){
			temp[i++] = num_from_file;
		}
		else if(data){
			insert(tree, atoi(temp));//function made in part 2
			while(i)temp[i--] = '\0';
		}
	}
	fclose(data);
	i = 1;
	//asks user to search the tree
	while(i){
		printf("try to guess a number in the tree. Type 0 to exit\n");
		scanf("%i", &i);
		search(i, tree);//function made in part 2
	}
	free_tree(tree);
}
