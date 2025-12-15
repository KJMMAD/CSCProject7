#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

const string fileNameTeams = "C:\\Users\\cmmsk\\Downloads\\Teams.txt", fileNameWinners = "C:\\Users\\cmmsk\\Downloads\\WorldSeriesWinners.txt";

/*
* Func: getTeams
* Purpose: Opens files of a given name, verifies if they opened correctly, and puts the data into a reference of a vector
* - string fileName: name of full file location for the team names
* - string vector fileArr[]: vector holding data from the file
* Return:
* - None
* Preconditions:
* - None
* Postconditions:
* - Modify vector indices using information from the file
*/
int getTeams(string fileName, vector <string> &fileVect);

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
int findWinner(string teamName, vector <string> seriesWinners);

int main()
{
    vector <string> teamNames;
    vector <string> seriesWinners;
    string inName;

    getTeams(fileNameTeams, teamNames);
    getTeams(fileNameWinners, seriesWinners);

    cout << "Team names:" << endl;
    for (int i = 0; i < teamNames.size(); i++) {
        cout << teamNames[i] << endl;
    }

    cout << endl;

    do {
        cout << "Enter the name of a team (enter quit to end)" << endl;
        getline (cin, inName);
        cout << endl;

        if (inName != "quit" && inName != "Quit") {
            int wins = findWinner(inName, seriesWinners);
            cout << "The " << inName << " won the world series " << wins << " times." << endl;
        }
    } while (inName != "quit" && inName != "Quit");

    return 0;
}

int getTeams(string fileName, vector <string> &fileVect) {
    string name;
    ifstream infile(fileName);
    if (!infile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    while (getline(infile, name)) {
        fileVect.push_back(name);
    }
    infile.close();
    return 0;
}

int findWinner(string teamName, vector <string> seriesWinners) {
    int winCount = 0;
    for (string name : seriesWinners) {
        if (teamName == name) {
            winCount++;
        }
    }
    return winCount;
}