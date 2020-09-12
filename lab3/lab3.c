/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism or cheating I will have to sign an official form that I have cheated and that this form will be stored in my official university record. I also understand that I will receive a grade of 0 for the involved assignment for my first offense and that I will receive a grade of “F” for the course for any additional offense.*/

#include <stdio.h>

//Lab 3, Part1-----------------------------------------------------
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define TRACE printf("TRACE was called on line: %d\n", __LINE__);

//Converts a time of hours, minutes, and seconds into seconds
int numSeconds(int hours, int minutes, int seconds);
//-----------------------------------------------------------------

//Lab 3, Part2A----------------------------------------------------
struct time{
	int Hours;
	int Minutes;
	int Seconds;
};
//Calculates the difference between two times
struct time difference_in_time(struct time time1, struct time time2);
//------------------------------------------------------------------

//Lab 3, Part2B----------------------------------------------------
enum Months{JAN = 1, FEB, MAR, APR, MAY, JUNE, AUGUST, SEPT, OCT, NOV, DEC};//An enum for organizing dates
char *month_string[13] = {"Ignore", "Jan", "Feb", "Mar", "Apr", "May", "June", "Aug", "Sept", "Oct", "Nov", "Dec"};// This is used to convert enum months into readable month names 
struct DateTime{
	int year;
	enum Months month;
	int day;
	struct time time;
};
//------------------------------------------------------------------

int main(){
	//Lab3, Part2A:---------------------------------------------------------
	struct time temp1 = {1, 30, 45};
	struct time temp2 = {16, 30, 45};
	temp1 = difference_in_time(temp1, temp2);
	printf("the difference in time is: \t%d:%d:%d\n", temp1.Hours, temp1.Minutes, temp1.Seconds);
	
	temp1.Hours = 0; temp1.Minutes = 1; temp1.Seconds = 1;
	temp2.Hours = 23; temp2.Minutes = 59; temp2.Seconds = 59;
	temp1 = difference_in_time(temp1, temp2);
	printf("the difference in time is: \t%d:%d:%d\n", temp1.Hours, temp1.Minutes, temp1.Seconds);

	temp1.Hours = 12; temp1.Minutes = 0; temp1.Seconds = 0;
	temp2.Hours = 12; temp2.Minutes = 0; temp2.Seconds = 0;
	temp1 = difference_in_time(temp1, temp2);
	printf("the difference in time is: \t%d:%d:%d\n", temp1.Hours, temp1.Minutes, temp1.Seconds);
	//----------------------------------------------------------------------

	//Lab3, Part2B----------------------------------------------------------
	struct DateTime example1 = {1809, JAN, 19, {12, 1, 0}};
	printf("Date 1 in Time/Day/Month/Year:\t %d:%d/%d/%s/%d\n",example1.time.Hours, example1.time.Minutes, example1.day, 									  month_string[example1.month], example1.year);

	struct DateTime example2 = {1922, NOV, 11, {6, 0, 0}};
	printf("Date 2 in Time/Day/Month/Year:\t %d:%d/%d/%s/%d\n",example2.time.Hours, example2.time.Minutes, example2.day, 									  month_string[example2.month], example2.year);

	struct DateTime example3 = {2000, JAN, 6, {8, 22, 0}};
	printf("Date 3 in Time/Day/Month/Year:\t %d:%d/%d/%s/%d\n",example3.time.Hours, example3.time.Minutes, example3.day, 									  month_string[example3.month], example3.year);

	//----------------------------------------------------------------------
	return 0;
}


//Lab3, Part1-----------------------------------------------------------------
int numSeconds(int hours, int minutes, int seconds){
	TRACE
	return hours * SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR +
	       minutes * SECONDS_IN_A_MINUTE + seconds;
}
//----------------------------------------------------------------------------

//Lab3, Part2A----------------------------------------------------------------
struct time difference_in_time(struct time time1, struct time time2){
	int time1_sec = numSeconds(time1.Hours, time1.Minutes, time1.Seconds);//stores time1 in seconds
	int time2_sec = numSeconds(time2.Hours, time2.Minutes, time2.Seconds);//stores time2 in seconds
	int total_sec = (time1_sec > time2_sec) ? time1_sec - time2_sec: time2_sec - time1_sec;//finds the difference in times. 												 Returns positive value
	
	struct time time_dif;//struct that is returned when function call is finished
	time_dif.Hours = total_sec / (SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR);//All decimal are truncated
	time_dif.Minutes = total_sec % (SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR) / SECONDS_IN_A_MINUTE;
	time_dif.Seconds = total_sec % (SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR) % SECONDS_IN_A_MINUTE;
	
	return time_dif;
}
//------------------------------------------------------------------------------
