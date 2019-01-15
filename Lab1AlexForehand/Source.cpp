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

#define _CRT_SECURE_NO_WARNINGS
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
using std::ios;

const unsigned short NAME_LENGTH = 20;
const unsigned short MAX_EMPLOYEES = 15;

void DisplayMenu();
void ReadFile(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13],
    char dateOfBirth[MAX_EMPLOYEES][11], short &numEmployees, ifstream &employeeIn); // read file into related arrays
void SortUsers(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13], 
    char dateOfBirth[MAX_EMPLOYEES][11], int numEmployees, ofstream &employeeOut); // sorts arrays by last name and then writes changes back to data file
void MenuChoice(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], 
    char phoneNum[MAX_EMPLOYEES][13], char dateOfBirth[MAX_EMPLOYEES][11], int numEmployees, ofstream &employeeOut, ifstream &employeeIn); // processes user menu choice
void EditUser(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13], char dateOfBirth[MAX_EMPLOYEES][11]); // Allows user to edit a specific user
void PrintUsers(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH],
    char phoneNum[MAX_EMPLOYEES][13], char dateOfBirth[MAX_EMPLOYEES][11], int numEmployees);

int main() {
    char fname[MAX_EMPLOYEES][NAME_LENGTH] = { '\0' }; // array of first names
    char lname[MAX_EMPLOYEES][NAME_LENGTH] = { '\0' }; // array of last names
    char phoneNum[MAX_EMPLOYEES][13] = { '\0' };       // array of phone numbers
    char dateOfBirth[MAX_EMPLOYEES][11] = { '\0' };    // array of birth dates
    short numEmployees = 0;                            // keeps track of number of employees
    char data[25] = { "employee_data.txt" };           // file name

    ifstream employeeIn(data);
    ofstream employeeOut(data, ios::app);

    if (employeeIn.is_open()) {
        ReadFile(fname, lname, phoneNum, dateOfBirth, numEmployees, employeeIn);
    } else {
        cout << "Failed to open file: " << data;
    }
    SortUsers(fname, lname, phoneNum, dateOfBirth, numEmployees, employeeOut);
    DisplayMenu();

    employeeIn.close();
    employeeOut.close();
    cin.ignore(2);
    return 0;
}

void DisplayMenu() {
    cout << "1.) Find user information\n"
         << "2.) Add user\n"
         << "3.) Edit user\n"
         << "4.) Display all records\n"
         << "5.) Exit\n";
}

void ReadFile(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13],
    char dateOfBirth[MAX_EMPLOYEES][11], short &numEmployees, ifstream &employeeIn) {

    employeeIn >> fname[numEmployees] // priming read of `data`
        >> lname[numEmployees]        // saving data from `data` to 2D arrays
        >> phoneNum[numEmployees]
        >> dateOfBirth[numEmployees];

    while (!employeeIn.eof() || numEmployees < MAX_EMPLOYEES) { // if there are more than 1 line in the file, continue reading into array until end of file
        employeeIn >> fname[numEmployees]
            >> lname[numEmployees]
            >> phoneNum[numEmployees]
            >> dateOfBirth[numEmployees];

        numEmployees++;
    }
}

void SortUsers(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13],
    char dateOfBirth[MAX_EMPLOYEES][11], int numEmployees, ofstream &employeeOut) {

    char fnameTemp[1][NAME_LENGTH] = { '\0' }, // first name temp variable
         lnameTemp[1][NAME_LENGTH] = { '\0' }, // last name temp variable
         phoneTemp[1][13] = { '\0' }, // phone number temp variable
         birthTemp[1][11] = { '\0' }; // birthday temp variable
    short pass = 0; // number of passes
    bool sorted = false; // whether or not the sort is complete

    while (pass < numEmployees || sorted == false) {
        sorted = true;

        for (int i = 0; i < numEmployees - pass - 1; i++) {
            if (_stricmp(lname[i], lname[i + 1]) < 0) {
                sorted = false; // resetting to false since we did end up sorting this pass

                strcpy(lnameTemp[i], lname[i]); // save lname to lnameTemp
                strcpy(lname[i], lname[i + 1]); // save lname to lname + 1
                strcpy(lname[i + 1], lnameTemp[i]); // save lnameTemp to lname + 1

                strcpy(fnameTemp[i], fname[i]);
                strcpy(fname[i], fname[i + 1]);
                strcpy(fname[i + 1], fnameTemp[i]);

                strcpy(phoneTemp[i], phoneNum[i]);
                strcpy(phoneNum[i], phoneNum[i + 1]);
                strcpy(phoneNum[i + 1], phoneTemp[i]);

                strcpy(birthTemp[i], dateOfBirth[i]);
                strcpy(dateOfBirth[i], dateOfBirth[i + 1]);
                strcpy(dateOfBirth[i + 1], birthTemp[i]);

                pass++; //incrementing pass counter
            }
        }
    }
}

void MenuChoice(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13], char dateOfBirth[MAX_EMPLOYEES][11],
    int numEmployees, ofstream & employeeOut, ifstream & employeeIn) {
}

void EditUser(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13], char dateOfBirth[MAX_EMPLOYEES][11]) {
}

void PrintUsers(char fname[MAX_EMPLOYEES][NAME_LENGTH], char lname[MAX_EMPLOYEES][NAME_LENGTH], char phoneNum[MAX_EMPLOYEES][13],
    char dateOfBirth[MAX_EMPLOYEES][11], int numEmployees) {
}
