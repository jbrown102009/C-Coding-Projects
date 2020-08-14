#include <iostream>
using namespace std;

int main (){

int distance; //Distance of traveled package
int zipOrgin; //Zipcode orgin
int zipDest; //Zip code Destination
double cost; // Cost of package
float weight; // Weight of package
int mail; // mail user input
const float air = 0.295; // float of air
const float truck =  0.165; // float of truck
const float courier =  0.085; // float of local

enum Service{AIR = 1, TRUCK = 2, COURIER = 3, EXIT = 4}; // Declares the enum for the variables


cout << "+----------------------------------------------+" << endl;
cout << "| Computer Science and Engineering |" << endl;
cout << "| CSCE 1030 - Computer Science I |" << endl;
cout << "| Student Name EUID jqb0015@my.unt.edu |" << endl;
cout << "+----------------------------------------------+" << endl;

cout <<"+******************* M E N U ******************+" << endl;
cout <<"| Choose a Service for Package Delivery: |" << endl;
cout << "| 1. FastShip Air (EXPEDITED) |" << endl;
cout <<"| 1. FastShip Air (EXPEDITED) |" << endl;
cout <<"| 3. FastShip Local Courier (STANDARD) |" << endl;
cout <<"| 4. Exit                              |" << endl;
cout <<"+**********************************************+" << endl;

cin >> mail;

 if (mail == 1) // Declares when mail is set to 1
{
(zipDest >= 0 && zipDest <= 99999);
(zipOrgin >= 0 && zipOrgin <= 99999);

    cout << "Enter the ZIP code of origin." << endl;
    cin >> zipOrgin;
    cout << " ZIP code of destination. " << endl;
    cin >> zipDest;
    cout << " And weight in pounds." << endl;
    cin >> weight;
}
else if (mail == 2)// declares when mail is set to 2
{(zipOrgin >= 0 && zipOrgin <= 99999);
(zipDest >= 0 && zipDest <= 99999);

    cout << "Enter the ZIP code of origin." << endl;
    cin >> zipOrgin;
    cout << " ZIP code of destination. " << endl;
    cout << " And weight in pounds." << endl;
    cin >> weight;
}
else if (mail == 3)// Declares when mail is set to 3
{(zipOrgin >= 0 && zipOrgin <= 99999);
(zipDest >= 0 && zipDest <= 99999);

    cout << "Enter the ZIP code of origin." << endl;
    cin >> zipOrgin;
    cout << " ZIP code of destination. " << endl;
    cin >> zipDest;
    cout << " And weight in pounds." << endl;
    cin >> weight;
}
else if (mail == 4)// Declares when mail is set to 4
{(zipOrgin >= 0 && zipOrgin <= 99999);
(zipDest >= 0 && zipDest <= 99999);
    cout << "Thank you for using the program!" << endl;
}
else
{
    cout << "Invalid option error" << endl; // Declares invalid input
}

                 cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(2);

                                        switch(mail){ // Declares what variables are assigned to where based on the enum

                        case 1: // Assigns the the first variable of the enum to the program
                        distance =abs(zipOrgin - zipDest) /1000;
                        cost = distance * weight * air;
                        cout << "Fastship EXPEDITED Service cost $: " << cost << endl;
                        break; // Ends the program

                        case 2: // assigns second enum
                        distance = abs(zipOrgin - zipDest) /1000;
                        cost = distance * weight * truck;
                        cout << "Fastship PRIORITY Service cost $: "<< cost << endl;
                        break;

                        case 3: // assigns 3rd enum
                        distance =abs(zipOrgin - zipDest) /1000;
                        cost = distance * weight * courier;
                        cout << "Fastship Standard Service cost $: " << cost << endl;
                        break;

                        default: // no input for this case so it gives a default answer
                            cout << "Invalid input." << endl;
                            break;
    }



    return 0;
}

