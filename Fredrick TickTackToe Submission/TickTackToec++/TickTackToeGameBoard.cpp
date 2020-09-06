#include "TickTackToeGameBoard.h"
#include "GameInstance.h"

TickTackToeGameBoard::TickTackToeGameBoard()
{
	symbols = new char* [3];//each char array in the pointer array is a row
	for (int i = 0; i < 3; i++)//rows
	{
		symbols[i] = new char[4];//plus 1 for null terminator
		for (int j = 0; j < 3; j++)
		{
			symbols[i][j] = ' ';//initializing all symbols to spaces
		}
		symbols[i][3] = '\0';
	}

	//setting up board layout
	boardLayout = new char*[9];//9x9 for printing board grid 
	for (int i = 0; i < 9; i++)//rows
	{
		boardLayout[i] = new char[18];//plus 1 for null terminator
		for (int j = 0; j < 17; j++)
		{
			boardLayout[i][j] = j % 2 == 1 ? ' ' : '#';//initializing all symbols to hash, every second symbol is a space for more even printing.
		}
		boardLayout[i][17] = '\0';
	}

	/*inserting slot numbers under each slot in the board.*/
	for (int i = 0; i < 9; i++)
	{
		boardLayout[2 + ((i / 3) * 3)][2 + ((i % 3) * 6)] = (char)49 + i;
	}
	applySymbolsToGameBoard();//put the empty symbols into the board to make the empty slots.
}

void TickTackToeGameBoard::printGameBoard()
{
	std::cout << std::endl;
	for (int i = 0; i < 9; i++)
	{
		Game::announce(boardLayout[i]);
	}
	std::cout << std::endl;
}

void TickTackToeGameBoard::printGameBoardWithColor(int color)
{
	std::cout << std::endl;
	for (int i = 0; i < 9; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		std::cout << boardLayout[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void TickTackToeGameBoard::doPlayerChoiceAtSlot(unsigned int slotID, PlayerTurn playerTurn)
{
	if (slotID > 9 || slotID <= 0)
	{
		Game::error("TickTackToeGameBoard::doPlayerChoiceAtSlot() received a slot id outside of range 1 - 9 inclusive!");
	}
	else
	{
		symbols[(slotID - 1) / 3][(slotID - 1) % 3] = playerTurn == PlayerTurn::PLAYERONE ? playerOneSymbol : playerTwoSymbol;
		applySymbolsToGameBoard();
	}
}

void TickTackToeGameBoard::applySymbolsToGameBoard()
{
	for (int i = 0; i < 9; i++)
	{
		boardLayout[1 + ((i / 3) * 3)][2 + ((i % 3) * 6)] = symbols[i / 3][i % 3];
	}
}

void TickTackToeGameBoard::resetGameBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			symbols[i][j] = ' ';//make all symbols empty
		}
	}
	applySymbolsToGameBoard();//put the empty symbols into the board to make the empty slots.
}

bool TickTackToeGameBoard::checkForWinCondition()
{
	for (int i = 0; i < 3; i++)
	{
		//check rows
		char symbolToCheckFor = symbols[i][0];
		if (symbolToCheckFor != ' ' && symbols[i][1] == symbolToCheckFor && symbols[i][2] == symbolToCheckFor)
		{
			return true;
		}

		//check columns
		symbolToCheckFor = symbols[0][i];
		if (symbolToCheckFor != ' ' && symbols[1][i] == symbolToCheckFor && symbols[2][i] == symbolToCheckFor)
		{
			return true;
		}
	}

	//check diagonals
	char symbolToCheckFor = symbols[0][0];
	if (symbolToCheckFor != ' ' && symbols[1][1] == symbolToCheckFor && symbols[2][2] == symbolToCheckFor)
	{
		return true;
	}
	symbolToCheckFor = symbols[2][0];
	return symbolToCheckFor != ' ' && symbols[1][1] == symbolToCheckFor && symbols[0][2] == symbolToCheckFor;
}

bool TickTackToeGameBoard::isSlotEmpty(unsigned int slotID)
{
	return symbols[(slotID - 1) / 3][(slotID - 1) % 3] == ' ';
}

bool TickTackToeGameBoard::isBoardFull()
{
	for (unsigned int i = 1; i < 10; i++)
	{
		if (isSlotEmpty(i))
		{
			return false;
		}
	}
	return true;
}

TickTackToeGameBoard::~TickTackToeGameBoard() 
{
	for (int i = 0; i < 3; i++)
	{
		delete[] symbols[i];
	}
	delete[] symbols;

	for (int i = 0; i < 9; i++)
	{
		delete[] boardLayout[i];
	}
	delete[] boardLayout;
}