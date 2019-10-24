/*
Mason Henry
C++
Due: October 24, 2019
Create a number guessing game where the user has 20 guesses to guess a randomly generated number betweebn 0 and 100. It must output
different messages for winning, losing, an asking to play again. It mjust also keep track of wins and losses and output them at
the end of the program.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//preconditions: Stream must be valid, user guess must equal the randomly generated number.
//postconditions: Outputs one of the cases letting the user know they won.
void rightans();
//preconditions: Stream must be valid, guesses must be greater than zero, user guess must not equal the randomly generated number.
//postconditions: Outputs one of the cases letting the user know they guesses incorrectly.
void incorans();
//preconditions: Stream must be valid, user must have either won or loss the game.
//postconditions: Outputs one of the cases asking the user if they would like to play the game again.
void again();
//preconditions: Stream must be valid, random number must be generated.
//postconditions: Returns either true or false, adds one to either gwon or glost depending if the user correctly guessed the
//				  randomly generated number or not.
bool inputeval(int& gwon, int& glost, float user, int ranNum);\
//preconditions: Stream must be valid, user must have either won or lost the game, againloop must be true.
//postconditions: Outputs play to be either true or false determining whether the game will be played again, also lets the user
//				  know when they inputed an incorrect response.
void playagainloop(char playagain, bool& play, bool againloop);

int main()
{
	srand(time(NULL));
	//The user input, it is a float incase they input a decimal the game will continue.
	float user = 0;
	//Value that determines whether the game is played or not
	bool play = true;
	//random number that will be generated
	int ranNum;
	//character that is user inputed that will determine whether the game will be played again
	char playagain = ' ';
	//keeps track of total games won
	int gwon = 0;
	//keeps track of total games lost
	int glost = 0;
	//Allows the looping of the response of the user being asked to play again. 
	bool againloop = true;

	do
	{
		//generates the random number to be used in the guessing game.
		ranNum = rand() % 100 + 0;
		cout << "Welcome to the number guessing game. I am thinking of a whole number between 0 and 100.\nYou have 20 guesses to figure it out. Start guessing.\n";
		
		//If the input evaluation returns true it means the stream entered a failed state and returns one. Otherwise it returns
		//false and the program continues.
		if (inputeval(gwon, glost, user, ranNum))
			return 1;

		again();

		playagainloop(playagain, play, againloop);

	} while (play);
	cout << "Thanks for playing. You won " << gwon << " games and lost " << glost << " games.\n";

	return 0;
}

void rightans()
{
	//Generates a random number which determines which case is going to be outputted.
	int Num = rand() % 10 + 1;
	switch (Num)
	{
	case 1: cout << "Congrats you won!\n";
		break;
	case 2: cout << "You guessed correctly!\n";
		break;
	case 3: cout << "Would you look at that, you got it correct!\n";
		break;
	case 4: cout << "Wow I didn't think you would be able to guess my number!\n";
		break;
	case 5: cout << "Man, you must be physic, good job!\n";
		break;
	case 6: cout << "How did you know? Good job anyway!\n";
		break;
	case 7: cout << "Wha... how did you? Fine, you win this round!\n";
		break;
	case 8: cout << "You win this round...\n";
		break;
	case 9: cout << "Impressive, but can you do it two games in a row?\n";
		break;
	case 10: cout << "Are you reading my mind? Good job anyway.\n";
		break;
	}
}

void incorans()
{
	//Generates a random number which determines which case is to be outputted.
	int Num = rand() % 10 + 1;
	switch (Num)
	{
	case 1: cout << "That guess is incorrect\n";
		break;
	case 2: cout << "Guess again\n";
		break;
	case 3: cout << "WRONG!\n";
		break;
	case 4: cout << "Nice try, but your wrong. Guess again.\n";
		break;
	case 5: cout << "What were you thinking with that answer?\n";
		break;
	case 6: cout << "Not even close! or were you?\n";
		break;
	case 7: cout << "Try guessing again\n";
		break;
	case 8: cout << "wrong wrong wrong wrong wrong!\n";
		break;
	case 9: cout << "Are you even trying? Guess again!\n";
		break;
	case 10: cout << "Hmmmm let me check if that's correct... It's not try again.\n";
		break;
	}
}

void again()
{
	//Generates a random number which determines which case is to be outputted. 
	//The stat is for case number nine which outputs a random percent each time it is outputted.
	int Num = rand() % 10 + 1;
	int stat = rand() % 100 + 1;
	switch (Num)
	{
	case 1: cout << "Would you like to play again? (Y/N)\n";
		break;
	case 2: cout << "This was fun. We should play again! (Y/N)\n";
		break;
	case 3: cout << "Thanks for playing my game. Would you like to again? (Y/N)\n";
		break;
	case 4: cout << "Did you have fun? You should play again (Y/N)\n";
		break;
	case 5: cout << "I command you to play again! (Y/N)\n";
		break;
	case 6: cout << "You got nothing better to do. You should play again (Y/N)\n";
		break;
	case 7: cout << "I can't think of a good way to ask you to play again. But do it anyway (Y/N)\n";
		break;
	case 8: cout << "PLAY PLAY PLAY PLAY PLAY PLAY again or don't it's really up to you. (Y/N)\n";
		break;
	case 9: cout << "Did you know that " << stat << "% of statstics are made up on the spot. Play again and maybe you'll learn something else. (Y/N)\n";
		break;
	case 10: cout << "You should play again. Or don't it doesn't matter to me I'm just a program. (Y/N)\n";
		break;
	}
}

bool inputeval(int& gwon, int& glost, float user, int ranNum)
{
	for (int guesses = 19; guesses >= 0; guesses--)
	{
		cin >> user;
		//If the user guesses correctly outputs one of the cases from right answer, adds one to games won, and sets guesses to -1.
		if (user == ranNum)
		{
			rightans();
			gwon++;
			guesses = -1;
		}
		//If the user inputs an invalid character and causes the stream to go into a failed state it returns true which will
		//return one in the main function.
		else if (!user)
		{
			cout << "An invalid input has been entered. Please restart the game.\n";
			cout << "You won " << gwon << " games and lost " << glost << " games.\n";
			return true;
		}
		//checks to see if the user guessed within the range and informs the user.
		else if (user < 0 || user > 100)
		{
			cout << "That number is not in the guessing range. Guess a number between 0 and 100.\n";
			cout << "Guesses left:" << guesses << endl;
		}
		//If the use guessed incorrectly outputs a case from the incorrect answer and lets the user know how many guesses they 
		//have left.
		else if (user != ranNum && guesses > 0)
		{
			incorans();
			cout << "Guesses left:" << guesses << endl;
		}
		//When the guesses equal zero lets the user know that they lost, informs them of what the random number was, and adds
		//one to the games lost.
		if (guesses == 0)
		{
			cout << "Sorry you lost. The number was " << ranNum << endl;
			glost++;
		}
	}
	//If the for loop runs through all the way returns false so the program can continue running.
	return false;
}

void playagainloop(char playagain, bool& play, bool againloop)
{
	//Continues to loop until the user inputs one of the valid inputs that causes the againloop variable to be false
	while (againloop)
	{
		cin >> playagain;
		//If the user inputs one of these causes againloop to be false but keeps play true so it plays the game again.
		if (playagain == 'Y' || playagain == 'y' || playagain == 'Yes' || playagain == 'yes')
		{
			play = true;
			againloop = false;
		}
		//If the user inputs one of these causes againloop to be false but makes play false so that the game ends.
		else if (playagain == 'N' || playagain == 'n' || playagain == 'No' || playagain == 'no')
		{
			play = false;
			againloop = false;
		}
		//If the user inputs anything besides one of the valid inputs it informs the user that they inputted an incorrect value and 
		//loops back so they can input another value.
		else
		{
			cout << "This is not part of the guessing game. Y to play again or N to quit.\n";
			againloop = true;
		}
	}
}
