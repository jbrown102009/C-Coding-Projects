/*	 Author: Johnathan Brown (JohnathanBrown@my.unt.edu)
	Date: Oct / 27 /2019
	Instructor: Thompson
	Description: Write a C++ program that simulates an ant colony
		optimization problem to help determine an appropriate path
		for an ant to take between adjacent ant colonies.  */




#include <iostream> // basic C++ input and output
#include <stdlib.h> // uses the rand() and srand() function
#include <time.h> // uses the srand() function
#define SIZE 10

using namespace std;

enum E{A,B,C,D,E,F,G,H,I,J};

void initialize (int array[] [SIZE]) // For initializing the 2D array with random values
{

srand (time(0));
	for(int i = 0;i<SIZE;i++)
		for (int j=0; j<SIZE; j++)
		{
			if (i==j)
			{
				array[i][j] = 0;
				continue;

			}
			array[i][j] = rand()%20+1;
		}
	}

void print (int array[][SIZE]) // Prints the 2-D array
{
	cout << endl;
	for(int i=0;i<SIZE;i++)
	{
		for (int j=0; j<SIZE;j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

	bool isVisited(int * array, int val) // To check in the visited array.
{
	for(int i=0;i<SIZE;i++)
		if(array[i]==val)
			return true;
	return false;
}

int lowestPheromone(int array1[][10], int *array2, int row) //To return the index of the colum with lowpheromone in the input row.
{
	int min = array1[row][0];
	int index = 0;
	if (isVisited(array2,row))
	{
		for(int i = 1; i<SIZE; i++)
		{
			if(i!=row) // for path not to go into itself
			{
				if(array1[row][i]<min)
				{
				min = array1[row][i];
				index = i;
				}
			}
		}
	}
	return index;
}

	void displayVisited(int *array) //Used to displaying the final visited list.
{
int ant;
for(int i=0;i<SIZE;i++)
{
	ant = array[i];
	switch(ant)
	{

			case A: cout <<   " A  ----->";
			break;
			case B: cout <<   " B ----->";
			break;
			case C: cout <<   " C ----->";
			break;
			case D: cout <<   " D ----->";
			break;
			case E: cout <<   " E ----->";
			break;
			case F: cout <<   " F ----->";
			break;
			case G: cout <<   " G ----->";
			break;
			case H:  cout <<  " H ----->";
			break;
			case I:  cout <<  " I ----->";
			break;
			case J:  cout <<  " J ----->";
			break;
		}
	}
}

int main()
{

	int array[SIZE][SIZE];
	int visited[SIZE];

	cout << "+----------------------------------------------+" << endl;
cout << "| Computer Science and Engineering |" << endl;
cout << "| CSCE 1030 - Computer Science I |" << endl;
cout << "| Student Name EUID jqb0015@my.unt.edu |" << endl;
cout << "+----------------------------------------------+" << endl;
cout << endl;
cout <<"    W e l c o m e  t o  A n t h o n y's  h u n c h " << endl;
cout <<"***********************************************************" << endl;
cout <<"This program will set up a matrix that represents the pheromone levels " << endl;
cout << "between ant colonies. Anothony's objective is to find a path least " << endl;
cout <<"taken by the other ants in hopes of finding food to last through the " << endl;
cout <<"winter" << endl;
cout <<"***********************************************************" << endl;


cout << "Ant Colonies " << endl;
cout << endl;
cout << "A B C D E F G H I J" << endl;
cout << "-------------------------------------" << endl;

	for (int i=0;i<SIZE;i++)
	{
		visited[i] = 0;
	} 			//For initializing visited[] with zero's because zero is the default starting point
	initialize(array);
	print(array);
	visited[0] = 0;
	int i = 1;
	int minIndex = 0, templ;
	while(i<10)
	{
		minIndex = lowestPheromone(array,visited,minIndex); // For finding the next index
		if(!isVisited(visited,minIndex)) // Because we choose a node that is not visited we get a node tha is visited
	{
		visited[i++] = minIndex;
	}
	else
	{
		int ant = 21;
		int requiredIndex;
		for(int j=0;j<20;j++)
		{
			if(!isVisited(visited,j))
			{
				int ant1 = lowestPheromone(array,visited,j);
				if (ant1<ant)
				{
					ant = ant1;
					requiredIndex = j;
				}
			}
		}
		visited[i++] = requiredIndex; // making nextvisited node from which we got least pheromone value
		minIndex = ant; // making minIndex to ant will follow through with the loop.
	}
}
	cout << "The path followed by Anthony is: " << endl;
	displayVisited(visited);
	return 0;
}
