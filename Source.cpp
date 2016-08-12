#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::string;

// global variables
const int size = 3;
char board[size][size];

// prototypes
int menu();
int numGenerator();
void PvP();
void PvE();
void dispBoard();
void RetMenu();
void newBoard();
void ExitProgram();
bool checkWinner();

// global variables
string InvalInput = "ERROR: INPUT CANNOT BE UNDERSTOOD";

int main()
{
	srand(time(NULL));
	while (true) {
		switch (menu())
		{
		case 1:
			newBoard();
			PvE();
			break;
		case 2:
			newBoard();
			PvP();
			break;
		case 3:
			ExitProgram();
		}
	}
}

// the menu
int menu()
{
	int choice;
	try {
		cout << "\t\t\t+ =============== +" << endl;
		cout << "\t\t\t+ Tic - Tac - Toe +" << endl;
		cout << "\t\t\t+ =============== +" << endl;

		// sleep function goes here?
		cout << endl;

		cout << "\t\t*\t- - - - - - - - - -\t*" << endl;
		cout << "\t\t*\t1. Play the computer\t*" << endl;
		cout << "\t\t*\t2. Play a friend\t*" << endl;
		cout << "\t\t*\t3. Exit game\t\t*" << endl;
		cout << "\t\t*\t- - - - - - - - - -\t*" << endl;
		cout << "\t\t\tCHOICE:: ";
		cin >> choice;

		// finding out if input is valid
		if (!cin)
			throw InvalInput;
		else if (choice < 1 || choice > 3)
			throw InvalInput;
		else
			return choice;
	}

	// dealing with exceptions
	catch (...) 
	{
		system("CLS");
		cin.clear();
		cin.ignore(1, ' ');
		cout << InvalInput << endl << endl << endl;
		menu();
	}
}

// playing against a friend
void PvP()
{
	int turn = 1;
	int choice, player, letter;
	bool valid;
	bool won = false;
	while (!won)
	{
		valid = false;
		// it's Player _'s turn!!
		system("CLS");
		cout << "\n\nPlayer ";
		if (turn % 2 == 0) {
			cout << "2";
			player = 2;
			letter = 'O';
		}
		else {
			cout << "1";
			player = 1;
			letter = 'X';
		}
		cout << "'s turn. ";
		turn++;
		system("PAUSE");
		system("CLS");
		cout << "PLAYER " << player << ":" << endl << endl;
		dispBoard();


		// displaying options
		while (!valid) {
			try 
			{
				cout << endl << endl << "\tCHOICE:: ";
				cin >> choice;
				if (!cin)
					throw InvalInput;
				else if (choice < 1 || choice > 9)
					throw InvalInput;
				valid = true;
			}
			catch (...)
			{
				cin.clear();
				cin.ignore(1, ' ');
				cout << InvalInput << endl << endl;
			}// end catch
		}// end inner while loop
		switch (choice) 
		{
		case 1:
			board[0][0] = letter;
			break;
		case 2:
			board[0][1] = letter;
			break;
		case 3:
			board[0][2] = letter;
			break;
		case 4:
			board[1][0] = letter;
			break;
		case 5:
			board[1][1] = letter;
			break;
		case 6:
			board[1][2] = letter;
			break;
		case 7:
			board[2][0] = letter;
			break;
		case 8:
			board[2][1] = letter;
			break;
		case 9:
			board[2][2] = letter;
			break;
		}// end switch
		won = checkWinner();
		if (won)
		{
			system("CLS");
			cout << "\n\n\n\t    PLAYER " << player << " WINS!" << endl << endl;
			dispBoard();
			cout << endl << endl;
			RetMenu();
		}// end if
	}// end while loop
}

// playing against the computer
void PvE()
{
	char letter;
	bool won = false, valid = false, player = false;
	int turn = 1, choice;
	while (!won)
	{
		valid = false;
		system("CLS");
		if (turn % 2 != 0) {
			if (turn > 1)
				cout << "Computer chose: " << choice << endl;
			cout << "Player 1's turn. ";
			player = true;
			letter = 'X';
		}
		else 
		{
			cout << "Computer is taking turn... ";
			player = false;
			letter = 'O';
		}
		turn++;
		system("PAUSE");
		system("CLS"); 
		if (player)
		{
			while (!valid)
			{
				try 
				{
					dispBoard();
					cout << "\tCHOICE:: ";
					cin >> choice;
					if (!cin)
						throw InvalInput;
					else if (choice < 1 || choice > 9)
						throw InvalInput;
					valid = true;
				}// end try
				catch (...)
				{
					cin.clear();
					cin.ignore(1, ' ');
					cout << InvalInput << endl << endl;
				}// end catch
			}// end inner while
		}// end if
		else
		{
			choice = numGenerator();
		}// end else
		
		switch (choice)
		{
		case 1:
			board[0][0] = letter;
			break;
		case 2:
			board[0][1] = letter;
			break;
		case 3:
			board[0][2] = letter;
			break;
		case 4:
			board[1][0] = letter;
			break;
		case 5:
			board[1][1] = letter;
			break;
		case 6:
			board[1][2] = letter;
			break;
		case 7:
			board[2][0] = letter;
			break;
		case 8:
			board[2][1] = letter;
			break;
		case 9:
			board[2][2] = letter;
			break;
		}// end switch

		won = checkWinner();
		if (won)
		{
			system("CLS");
			cout << "\n\n\n\t    ";
			if (player)
				cout << "PLAYER ONE ";
			else
				cout << "COMPUTER ";
			cout << " WINS!" << endl << endl;
			dispBoard();
			cout << endl << endl;
			RetMenu();
		}// end if
	}// end while loop
}

// function to display the board
void dispBoard()
{
	//	BOARD PART 1/9	TOP TOP
	cout << "\t       |       |" << endl;


	// BOARD PART 2/9	TOP MIDDLE
	cout << "\t   ";
	if (board[0][0] == 'X' || board[0][0] == 'O')
		cout << board[0][0];
	else
		cout << "1";
	cout << "   |   ";
	if (board[0][1] == 'X' || board[0][1] == 'O')
		cout << board[0][1];
	else
		cout << "2";
	cout << "   |   ";
	if (board[0][2] == 'X' || board[0][2] == 'O')
		cout << board[0][2] << endl;
	else
		cout << "3" << endl;
	

	// BOARD PART 3/9	TOP BOTTOM
	cout << "\t_______|_______|_______" << endl;


	// BOARD PART 4/9	MIDDLE TOP
	cout << "\t       |       |" << endl;

	
	//BOARD PART 5/9	MIDDLE MIDDLE
	cout << "\t   ";
	if (board[1][0] == 'X' || board[1][0] == 'O')
		cout << board[1][0];
	else
		cout << "4";
	cout << "   |   ";
	if (board[1][1] == 'X' || board[1][1] == 'O')
		cout << board[1][1];
	else
		cout << "5";
	cout << "   |   ";
	if (board[1][2] == 'X' || board[1][2] == 'O')
		cout << board[1][2] << endl;
	else
		cout << "6" << endl;

	
	// BOARD PART 6/9	MIDDLE BOTTOM
	cout << "\t_______|_______|_______" << endl;


	// BOARD PART 7/9	BOTTOM TOP
	cout << "\t       |       |" << endl;


	// BOARD PART 8/9	BOTTOM MIDDLE
	cout << "\t   ";
	if (board[2][0] == 'X' || board[2][0] == 'O')
		cout << board[2][0];
	else
		cout << "7";
	cout << "   |   ";
	if (board[2][1] == 'X' || board[2][1] == 'O')
		cout << board[2][1];
	else
		cout << "8";
	cout << "   |   ";
	if (board[2][2] == 'X' || board[2][2] == 'O')
		cout << board[2][2] << endl;
	else
		cout << "9" << endl;


	//	BOTTOME PART 9/9	BOTTOM BOTTOM
	cout << "\t       |       |" << endl;
}

// function to check if there is a winner
bool checkWinner()
{
	// ups and downs
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
		return 1;
	if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
		return 1;
	if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
		return 1;

	// diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return 1;
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return 1;

	// side to side
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
		return 1;
	if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
		return 1;
	if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
		return 1;

	// no winner
	else
		return 0;
}

// function to check if users wish to play again
void RetMenu()
{
	char yesno;
	try
	{
		cout << "Return to menu (y/n): ";
		cin >> yesno;
		if (yesno == 'y')
		{
			system("CLS");
		}
		else if (yesno == 'n')
			ExitProgram();
		else
			throw InvalInput;
	}
	catch (...) 
	{
		cin.clear();
		cin.ignore(1, ' ');
		cout << endl << InvalInput << endl << endl;
		RetMenu();
	}
}

// function to fill the board with arbitrary letters
void newBoard()
{
	int index = 0;
	char letters[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = letters[index];
			index++;
		}
	}
}

// function to generate the computer's move
int numGenerator()
{
	int num;
	num = rand() % 9 + 1;
	return num;
}

// function to... START the program... jk
void ExitProgram()
{
	int secret;
	system("CLS");
	cout << "\n\n\t\t\tThanks for playing!" << endl << endl << endl << endl << endl;
	cin >> secret;
	if (secret == 64)
	{

	}
	exit(-1);
}