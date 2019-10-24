#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void rightans();
void incorans();
void again();

int main()
{
	srand(time(NULL));
	int user;
	bool playagain = true;
	int ranNum;
	char play;
	int gwon;
	int glost;

	do
	{
		ranNum = rand() % 100 + 1;
		cout << "Welcome to the number guessing game. I am thinking of a number between 1 and 100. You have 20 guesses to figure it out. Start guessing.\n";

		for (int guesses = 19; guesses >= 0; guesses--)
		{
			cin >> user;
			if (user == ranNum)
			{
				rightans(Num);
				guesses = -1;
				gwon++;
			}
			else if (user != ranNum)
			{
				incorans(Num);
				cout << "Guesses left:" << guesses << endl;
			}
			else if (!user)
			{
				cout << "An invalid input has been entered.\n";
				return 1;
			}
			glost++;
			cout << "Sorry you lost. The number was " << ranNum << endl;
		}
		bool tester = true;
		again(Num);
		while (tester)
		{
			cin >> play;
			if (play == 'Y' || play == 'y' || play == 'Yes' || play == 'yes')
			{
				playagain = true;
				tester = false;
			}
			else if (play == 'N' || play == 'n' || play == 'No' || play == 'no')
			{
				playagain = false;
				tester = false;
			}
			else
			{
				cout << "This is not a guessing game. Y or N to play again\n";
				tester = true;
			}
		}
	} while (playagain);
	cout << "Thanks for playing. You won " << gwon << "games and lost " << glost << "games. Thanks for playing\n";

	return 0;
}

void rightans()
{
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