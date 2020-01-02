char *won = "WON";//Constant string for displaying who is the winner in a simulated battle
char *lost = "LOST";//Constant string for displaying who is the loser in a simulated battle

/*Defines the team structure for holding information about teams in a simulated tournament*/
typedef struct Team{
		char team_name[12];
		int score;
		char *victor;
		int handyCap;
	}Team;

//Searches a string of text(haystack) for the presence of another smaller string(needle). Returns a copy of the needle if it is found as the buffer.
int myStrStr(char haystack[], char needle[], char buffer[]);

/*Takes two team structure pointers. Decides a winner between the two teams based on the random funciton and the team's handycap.
  Prints information about the match. Returns winning team structure.*/
Team *game(Team *home, Team *visiting);

//Takes an array of the team structs and simulates a tournament. Prints values about the matches. Returns winning team struct
Team *tournament(Team **competitors);
