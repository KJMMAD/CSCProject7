#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

const string fileNameStud = "C:\\Users\\cmmsk\\Downloads\\Teams.txt", fileNameExam = "C:\\Users\\cmmsk\\Downloads\\WorldSeriesWinners.txt";

/*
* Func: getTeams
* Purpose: Opens files of a given name, verifies if they opened correctly, and puts the data into a reference of a vector
* - string fileTeams: name of full file location for the team names
* - string fileWinners: name of full file location for the world series winners
* - string vector teamNames: vector with the names of major league baseball teams
* - string vector seriesWinners: vector with the names of winners for each year in order
* Return:
* - None
* Preconditions:
* - None
* Postconditions:
* - Modify two vectors using values from the files
*/
string getTeams(string fileTeams, string fileWinners, string teamNames[], string seriesWinners[]);

/*
* Func: findWinner
* Purpose: Takes user inputted team name and uses it to compare to the vector containing the winners, any matches between the selected name and vector add to a counter tracking
* world series wins for that team
* Parameters:
* - string teamName: name of team user wants to check
* - string vector seriesWinners[]: list of world series winners in chronological order
* Return:
* - int: number of wins for the selected team
* Precondition:
* - A valid team name is inputted to be used
* Postcondition:
* - Returns an int
*/
int findWinner(string teamName, string seriesWinners[]);

int main()
{
    return 0;
}

string getTeams(string fileTeams, string fileWinners, string teamNames[], string seriesWinners[]) {
    ifstream fileTeams;
}
