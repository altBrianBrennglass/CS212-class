/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lab4.h"


int main(){
	//Lab4 Part1a-------------------------------------------------
	printf("Part1a-------------------------------------------------\n");
	char buffer[12] = {0};
	myStrStr("apple", "app", buffer);
	printf("haystack='apple', needle='app', buffer='%s'\n",buffer);
	myStrStr("orange", "ge", buffer);
	printf("haystack='orange', needle='ge', buffer='%s'\n",buffer);
	myStrStr("blueberry", "ueber", buffer);
	printf("haystack='blueberry', needle='ueber', buffer='%s'\n",buffer);
	myStrStr("strawberry", "strawberry", buffer);
	printf("haystack='strawberry', needle='strawberry', buffer='%s'\n",buffer);
	myStrStr("grapefruit", "terrible", buffer);
	printf("haystack='grapefruit', needle='terrible', buffer='%s'\n",buffer);

	//Lab4 Part2a--------------------------------------------------
	printf("\n\nPart2a--------------------------------------------------\n");
	Team one = {"one", .handyCap = 5};
	Team two = {"two", .handyCap = 10};
	Team three = {"three", .handyCap = 1};
	Team four = {"four", .handyCap = 2};
	Team five = {"five", .handyCap = 0};
	Team six = {"six", .handyCap = 20};
	Team seven = {"seven", .handyCap = 12};
	Team eight = {"eight", .handyCap = 4};
	Team *league[8] = { &one, &two, &three, &four, &five, &six, &seven, &eight};
	srand(time(NULL));
	game(league[0], league[4]);

	//Lab4 Part2b--------------------------------------------------
	printf("\n\nPart2b--------------------------------------------------\n");
	tournament(league);
	return 0;
}
	


//Lab4 Part1a--------------------------------------------------
int myStrStr(char haystack[], char needle[], char buffer[]){
	int i;
	int j = 0;
	/*Searches for needle[] string in the haystack*/
	for(i = 0; haystack[i]; i++){
		if(needle[j] == haystack[i]){//If a in haystack matches the first character in needle do the following
			while(needle[++j] == haystack[++i] && haystack[i]);//Increments through haystack while characters match
			if(!needle[j]) strcpy(buffer, needle);//If '\0' present, the needle was found. copy needle to buffer
			else buffer[0] = '\0';//No match was found. "Clear" previous data in the buffer
			break;
		}
	}
	return (buffer[0])? 1: 0;
}

	//Lab4 Part2a---------------------------------------------------
Team *game(Team *home, Team *visiting){
	if(rand() % 2){
		home->score = 20 % rand() + 1 + visiting->handyCap;//the 20 was randomly choosen to increase variablity in score
		home->victor = won;
		visiting->score = 10 % rand() + home->handyCap;
		visiting->victor = lost;
	}
	else{
		visiting->score = 30 % rand() + 1 + visiting->handyCap;
		visiting->victor = won;
		home->score = 10 % rand() + home->handyCap;
		home->victor = lost;
	}
	printf("Home Team: '%s'\n\tscore: '%d'\n\twin?: '%s'\n\thandycap: '%d'\nVisiting Team: '%s'\n\tscore: '%d'\n\twin?: '%s'\n\thandycap: '%d'\n",		home->team_name,
					home->score,
					home->victor,
					home->handyCap,
					visiting->team_name,
					visiting->score,
					visiting->victor,
					visiting->handyCap
	);
	printf("---------------\n");
	return (home->score > visiting->score)? (home->handyCap = rand() % (visiting->handyCap + 10), home) : (visiting->handyCap += home->handyCap, visiting);//A conditional operation to find out which team won and should be returned. Also modifies handycap
}

Team *tournament(Team **competitors){
	Team *temp[4];//stores winning teams
	int i;
	int j;
	int k;
	printf("\nROUND 1----------------------------------------------\n\n");
	for(k = 0, i = 0, j = 1; j < 8; k++, i+=2, j+=2){//increments through competitions between teams
		temp[k] = game(competitors[i], competitors[j]);
	}
	printf("\nROUND 2----------------------------------------------\n\n");
	for(k = 0, i = 0, j = 1; j < 4; k++, i+=2, j+=2){
		temp[k] = game(temp[i], temp[j]);
	}
	printf("\nROUND 3----------------------------------------------\n\n");
	return game(temp[0], temp[1]);
}
	
	
	
		
	
