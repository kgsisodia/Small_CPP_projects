// Cpp Program to predict the correct card out of three cards (Card1, Card2 and Card3).
// Winner card is ACE of SPADES.
// by - Kishan Gopal

#include <iostream>
#include <conio.h>
#include <cstdlib> //for srand(), rand()
#include <ctime>  //for time for srand()

using namespace std;

///////////////////////////////////////////
struct Card  // Declaring room structure
{
	int card_number; // card number : 2 - 10, Jack, Queen, King, Ace 
	int suit; // suit - clubs, diamonds, hearts, spades
};

int main()
{
	const int JACK = 11;
	const int QUEEN = 12;
	const int KING = 13;
	const int ACE = 14;
	int i = 0, choice_card=0;

	const int clubs = 0;
	const int diamonds = 1;
	const int hearts = 2;
	const int spades = 3;
	char next_try = 'y';

	Card card1, card2, card3, tmp1, tmp2, winner, choosen;

	card1 = {7, clubs}; 
	card2 = { ACE, spades };
	card3 = { JACK, diamonds};

	winner = { ACE, spades };

	while (next_try == 'y')
	{
		cout << "card1 is 7 of clubs" << endl;
		cout << "card2 is ACE of spades" << endl;
		cout << "card3 is 7 of clubs" << endl;

		srand(time(NULL)); //seed random numbers with time
		int k = rand() % 12; //pick another card at random
		cout << "Swiping the cards Random number: " << k << "times" << endl;

		while (i > k)
		{
			tmp1 = card1;
			tmp2 = card2;
			card1 = card3;
			card3 = tmp2;
			card2 = tmp1;
			cout << "Swipe cards randomly" << endl;
			i++;
		}
		cout << "Choose the card number (1/2/3): " << endl;
		cin >> choice_card;

		switch (choice_card)
		{
		case 1: choosen = card1; break;
		case 2: choosen = card2; break;
		case 3: choosen = card3; break;
		default: cout << "\nInvalid card choice!" << endl;
			exit(0);
		} // end of switch

		if ((choosen.card_number == winner.card_number) && (choosen.suit == winner.suit))
		{
			cout << "\nYou are the winner" << endl;
			cout << "Winner card is ACE of SPADES" << endl;
		}
		else
			cout << "\nSorry! better luck next time" << endl;

		cout << "\nDo you want to try again (y/n)?" << endl;
		cin >> next_try;
	}
	

	return 0;
}