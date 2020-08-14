/*Author: Johnathan Brown (JohnathanBrown@my.unt.edu)
	Date: Dec / 3 /2019
	Instructor: Thompson
	Description: This is a game displaying anthonys ant army  */

#include <iostream> // basic C++ input and output
#include <stdlib.h> // uses the rand() and srand () function
#include <time.h> // uses the srand() function
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10; // global size

enum Colony		// enum for ant colony

{
A, B, C, D, E, F, G, H, I, J
};

void initA(int A[SIZE][SIZE]) // to initalize 2d matrix that stores pheno values
{
	srand(time(0)); //seed rand()

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{

			if(i == j) // for diagonal
				A[i][j] = 0;
			else
				A[i][j] = ((rand() % 20) + 1); //stores random numbers
		}
	}
}

void printA(int A[][SIZE])//print 2D matrix
{

	cout << endl;
	cout << "Ant Colonies : \n ";

	for(int i = 0; i < 10; i++)
		cout<< setw(6)<< (char)('A'+i);
	cout << "\n --------------------------------------------------------- \n";

	for (int i = 0; i < SIZE; i++)
	{
		cout <<setw(6) <<(char)('A'+i) << "  |  ";
		for(int j = 0; j < SIZE; j++)
		{
			cout << setw(6) << A[i][j];
		}

	        cout << endl;

	}
	cout << endl;
}

bool checkVisit (int B[], int col) // to check whic one has been visited
{

	for(int i = 0; i < SIZE; i++)
	{

		if(B[i] == col) // visited array
			return true;
	}
	return false; // if not visited
}

int findLowest (int A[][SIZE], int B[], int col) // find lowest pheno
{
	int ans = INT_MAX;
	int ind = -1;
	for(int i = 0; i < SIZE; i++)
	{

	if(i == col)
		continue;
	if(checkVisit(B, i)) // if already visited
		continue;
	if(A[col][i] < ans) // already selected
	{
		ans = A[col][i];
		ind = i;
	}
     }
     return ind;
}

void printB(int X[]) // prints visited array
{

	cout << endl;
	cout << "The results are! :\n";
	for(int i = 0; i < SIZE; i++)
	{

		Colony c = (Colony)X[i];
		switch(c)
		{

			case A: cout << "A";
			break;
			case B: cout << "B";
			break;
			case C: cout << "C";
			break;
			case D: cout << "D";
			break;
			case E: cout << "E";
			break;
			case F: cout << "F";
			break;
			case G: cout << "G";
			break;
			case H: cout << "H";
			break;
			case I: cout << "I";
			break;
			case J: cout << "J";
			break;
		}
		if(i != SIZE-1)
			cout << "--> ";
	}
	cout << endl;
}

int main ()
{


cout << "		+----------------------------------------------+" << endl;
cout << "		| Computer Science and Engineering             |" << endl;
cout << "		| CSCE 1030 - Computer Science I               |" << endl;
cout << "		| Student Name EUID jqb0015@my.unt.edu         |" << endl;
cout << "		+----------------------------------------------+" << endl;
cout << endl;
cout <<"            		Welcome to Anthony's Battle!                     " << endl;
cout <<"		***********************************************************" << endl;
cout <<"		Anthony the ant has decided that he wants to take over all   " << endl;
cout <<"		the adjacent ant colonies with his army of ants from colony " << endl;
cout <<"		'A'. To do this, Anthony's army will attempt to capture " << endl;
cout <<"		ants from columns 'B' through 'J', with at least 1 ant " << endl;
cout <<"		remaining when the column 'J' ant colony is found. Each column's ant colony is identified " << endl;
cout <<"		with a 0 in one of the rows for that column, while patrols are represented by integers " << endl;
cout <<"		between 1 and 10 for the number of ants in that particular " << endl;
cout <<"		patrol. On the way to column 'J' if Anthony's army encounters a patrol " << endl;
cout <<"		the number in the patrol is subtracted from Anthony's army total. " << endl;
cout <<"		Once his army finds the colony, however, any patrols not confronted will be added to his army " << endl;
cout <<"		total. If Anthony makes really good decisions, then he can take over all of the adjacent ant colonies; " << endl;
cout <<"		otherwise, his army will be defeated!" << endl;
cout <<"		+--------------------------------------------------+ " << endl;
cout <<"		***********************************************************" << endl;

	cout << "Ant Colonies " << endl;
	cout << endl;

	int A[SIZE][SIZE];
	int B[SIZE]; // 1D array
	memset(B, -1, sizeof(B));

	initA(A); // initalizes 2D array with random values
	printA(A); // print 2D array

	B[0]=0; // start
	int curr = 0;
	int i = 1;
	while(B[SIZE-1] == -1) // not all colonies are visited
	{

	int nextInd = findLowest(A, B,curr);
	curr = nextInd;
	B[i] = nextInd;
	i++;

	}

	printB(B);

	return 0;
}
