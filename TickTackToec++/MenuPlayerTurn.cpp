#include "MenuPlayerTurn.h"
#include "TickTackToeGameBoard.h"
#include "GameInstance.h"
#include "Player.h"
#include "conio.h"

void MenuPlayerTurn::doMenu()
{
	Player* currentPlayer = Game::get()->currentPlayerTurn == PlayerTurn::PLAYERONE ? Game::get()->playerOne : Game::get()->playerTwo;
	currentPlayer->say("It's my turn!");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Game::get()->defaultConsoleColor);
	std::cout << Game::get()->playerOne->getName() << "'s symbol is 'O' and " << Game::get()->playerTwo->getName() << "'s symbol is 'X'\nPress the number of the square you want to put your symbol!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
	std::cout << std::endl;

	unsigned int result = 0;
	bool validInput = false;
	char pressedChar = 0;

	while (true)//get player input, (single number from 1 to 9 inclusive)
	{
		result = 0;
		validInput = false;
		pressedChar = 0;
		switch (pressedChar = _getch())
		{
		case 49:
			result = 1;
			validInput = true;
			break;

		case 50:
			result = 2;
			validInput = true;
			break;

		case 51:
			result = 3;
			validInput = true;
			break;

		case 52:
			result = 4;
			validInput = true;
			break;

		case 53:
			result = 5;
			validInput = true;
			break;

		case 54:
			result = 6;
			validInput = true;
			break;

		case 55:
			result = 7;
			validInput = true;
			break;

		case 56:
			result = 8;
			validInput = true;
			break;

		case 57:
			result = 9;
			validInput = true;
			break;

		default:
			validInput = false;
			break;
		}
		if (!validInput)
		{
			std::cout << std::endl;
			Game::error("Please press a number key from 1 to 9!");
			std::cout << std::endl;
			continue;
		}

		if (!Game::get()->gameBoard->isSlotEmpty(result))
		{
			std::cout << std::endl;
			Game::error("That square isn't empty, please chose a different square!");
			std::cout << std::endl;
			continue;
		}
		break;
	}

	Game::get()->gameBoard->doPlayerChoiceAtSlot(result, Game::get()->currentPlayerTurn);
}
