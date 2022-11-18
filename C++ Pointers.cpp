/*
Sanyerlis Camacaro- CSC215 - Sancamac@uat.edu
Assignment: C++ Pointers

Class is almost over and I've been giving the opportunity to write any program I would like,
as long as I follow the assigment's guidelines. 

To create a new console project C++ program.Create at least two pointers in main that point at variables 
with at least two different data types.Use more than one function. In one or more function(s), pass a pointer into the function.
Use a pointer you passed into a function back in main to show the value
pointed to has been changed in the function and the change happens to the actual value outside that function.
*/

#include "pch.h" // includes precompiled header, faster to process for the compiler.
#include <iostream> // includes input and out as the standard library.
#include <string> // this includes and allows me to work with strings.

using namespace std; // means using standard namespace and that I dont have to type std:: in front of each line.

// Function prototypes.
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast); //  declaration, calls jumblename function, constant pointers. 
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast); // declaration, calls unjumblename function, constant pointers.
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast); // declaration, calls countletters function, constant pointers.

// first line of your program, your first instruction.
int main()
{
	string firstName; // Gets user input on their first name.
	string middleName; // Gets user input on their middle name.
	string lastName; // Gets user input on their last name.

	cout << "\tWelcome to the C++ Pointers Assigment!!!\n" << endl; // Title of Program.
	cout << "\t        It's time to scramble!!!\n" << endl; // Getting user ready for UX experience. 
	cout << "\nBefore we start, we would like to ask you some information to create the best experience.\n" << endl; // line for user agreement.
	cout << "\nWould you like to continue? Y/N?\n" << endl; // y/n gets printed out,questionf is user would like to proceed to answer quest.

	char answer; // declares answer as varible.
	cin >> answer; // character inputs answer.
	if (answer == 'y' || answer == 'Y') // if user inputs y they will proceed to answer questions.
	{
	cout << "Please enter your First name: "; // line that ask user for their first name.
	cin >> firstName; // user enter first name in this line.
	cout << "Please enter your Middle name: "; // line that ask user for their middle name.
	cin >> middleName; // user enter middle name in this line.
	cout << "Please enter your Last name: "; // line that ask user for their last name.
	cin >> lastName; // user enter last name in this line.

	jumbleName(&firstName, &middleName, &lastName);// Calls the jumbleName function.
	cout << "\n\nHello, " << firstName << " " << middleName << " " << lastName << "!\n"; // greats user by full name. 

	cout << "oOpss... I think I got your name wrong...\n"; // tells users that got their name wrong.
	cout << "I definitely meant to say "; // apologizes to users and displays the right name. 

	unjumbleName(&firstName, &middleName, &lastName);// Calls the unjumbleName function.
	cout << firstName << " " << middleName << " " << lastName << ".\n\n"; // displays user full name in order. 

	cout << "I apologize about the name confusion...\n"; // apologizes to user about the name confusion. 
	cout << "Just to make it up to you, I'll count the total letters in your full name.\n"; // tells users that it will count letters of full name.
	
	cout << "You have " << countLetters(&firstName, &middleName, &lastName) << " letters in your full name!\n\n";// Calls the countLetters function.

	}
	else // if user click something else or n they will.
	{
		cout << " We understand that you're not ready, to try again, exit and enter 'Y' to continue." << endl; // message when user inputs no.
	}

	//  if successful returns value. 
	return 0;
}

// Functions
// jumbleName will disorganize the full name entered by the user originally.
void jumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
	string temp = *pFirst; // Store value pointed to by pFirst in temp.
	*pFirst = *pMiddle; // Store value pointed to by pMiddle in address pointed to by pFirst.
	*pMiddle = *pLast; // Store value originally pointed to by pLast in address pointed to by pMiddle.
	*pLast = temp;// Stores value originally pointed to by pLast in address pointed to temp.
}

// unjumbleName will reorganize the full name as the user originally input.
void unjumbleName(string* const pFirst, string* const pMiddle, string* const pLast)
{
	string temp = *pMiddle; // Store value pointed to by pMiddle in temp.
	*pMiddle = *pFirst; // Store value pointed to by pFirst in address pointed to by pMiddle.
	*pFirst = *pLast; // Store value originally pointed to by pLast in address pointed to by pFirst.
	*pLast = temp; // Store value orignally pointed to by pLast in address pointed to temp.
}

// countLetters will count the total amount of letters in the users name.
int countLetters(string* const pFirst, string* const pMiddle, string* const pLast)
{
	// Add together the size of all the pointers and returns the int letterCount.
	int letterCount = pFirst->size() + pMiddle->size() + pLast->size();

	return letterCount; //  if successful returns value to letterCount. 
}
