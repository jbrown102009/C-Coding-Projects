/* Author: Johnathan Brown (JohnathanBrown@my.unt.edu)jqb0015@my.unt.edu
 Date:9/13/2019
 Instructor: Thompson, Computer Science 1 CSCE1030
 Description: In this assignment, we will create a program to compute the time required for an object to reach
the ground when dropped from a user specified height, the velocity at which it hits the ground
and the kinetic energy at the moment of impact.
*/

#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	double time; //This is the variable for time
	double mass; // This is the variable for mass in kg
	double height; //Variable for height
	double kinetic; //Variable for kinetic energy
	const double acceleration = 9.8; //Variable for gravity
	double velocity; //Variable for velocity

	cout << "Please enter the height from which the object is being dropped (in ft) ";
	cin >> height; //user input height
	height = height * .3048; //Converting feet to meters
	cout << "Please enter the mass of the object (in kg) "; // Just regular mass
	cin >> mass; //User inut mass

	time = sqrt(2*height/acceleration); //Formula for time taken by object to reach ground
	velocity = acceleration * time; // Formula for velocity
	kinetic = .5 * mass *(pow(velocity,2)); // Formula for kinetic energy

	cout << "The time taken by the object to reach the ground is " << time << endl;
	cout << "The velocity at which the object strikes the ground is " << velocity << endl;
	cout << "The kinetic energy at which the moment of the impact with the ground is " << kinetic << " Joules."  << endl;


	return 0;

}
