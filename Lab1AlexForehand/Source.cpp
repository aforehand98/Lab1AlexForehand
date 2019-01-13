/*************************************************************************************
Programmer: Alex Forehand
Organization: Rogue Community College - CS233
Filename: main.cpp
Date: JAN92019 10:00 PM
Modifications:

Lab #: 1
Abstract: A menu driven database application that holds personal information.

Inputs: employee_data.txt which will take in information entered by the user and store it.
Keyboard input to navigate the menu.

Output: employee_data.txt; program will store information input by the user and display/modify when requested
using the menu provided by said program.
**************************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::setprecision;
using std::setw;
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::showbase;

const unsigned short NAME_LENGTH = 20;
const unsigned short MAX_EMPLOYEES = 15;

void DisplayMenu();
void ReadFile(char fname[][NAME_LENGTH], char lname[][NAME_LENGTH], char phoneNum[][13], char dateOfBirth[][11], int numEmployees,
    ofstream employeeOut, ifstream employeeIn); // read file into related arrays
void SortUsers(char fname[][NAME_LENGTH], char lname[][NAME_LENGTH], char phoneNum[][13], char dateOfBirth[][11], int numEmployees, 
    ofstream employeeOut); // sorts arrays by last name and then writes changes back to data file
void MenuChoice(char fname[][NAME_LENGTH], char lname[][NAME_LENGTH], char phoneNum[][13], char dateOfBirth[][11],
    int numEmployees, ofstream employeeOut, ifstream employeeIn); // processes user menu choice
void EditUser(char fname[][NAME_LENGTH], char lname[][NAME_LENGTH], char phoneNum[][13], char dateOfBirth[][11]); // Allows user to edit a specific user
void PrintUsers(char fname[][NAME_LENGTH], char lname[][NAME_LENGTH], char phoneNum[][13], char dateOfBirth[][11], int numEmployees);

int main() {

}