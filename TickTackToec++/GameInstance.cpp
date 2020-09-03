#include "GameInstance.h"
#include <ctime>
#include "MenuIntroduction.h"
#include "MenuPlayerTurn.h"
#include "MenuGameResolution.h"
#include "Player.h"
#include "TickTackToeGameBoard.h"

Game* Game::instance = nullptr;

Game* Game::get()
{
	if (instance == nullptr)
	{
		instance = new Game();
	}
	return instance;
}

void Game::start()
{
	introductionMenu = new MenuIntroduction(&playerOne, &playerTwo);//asks for player names and initializes player objects
	playerTurnMenu = new MenuPlayerTurn();
	gameResolutionMenu = new MenuGameResolution();
	gameBoard = new TickTackToeGameBoard();

	announce("Hello! Welcome to TickTackToe!\nTo begin, enter the names for both players!");
	introductionMenu->doMenu();
	doGameLoop();

	Game::announce("Thank you for playing!");
}

void Game::doGameLoop()
{
	while (!isQuitting)
	{
		onUpdate();
	} 
}

void Game::onUpdate()
{
	chosePlayerTurn();
	if (startingNewGame)
	{
		if (gamesPlayed > 0)
		{
			gameBoard->resetGameBoard();//reset the game board apon starting new round
		}

		gameBoard->printGameBoard();
	}

	playerTurnMenu->doMenu();

	gameBoard->printGameBoard();


	if (gameBoard->checkForWinCondition())
	{
		announceWinner();
		gameBoard->printGameBoardWithColor(currentPlayerTurn == PlayerTurn::PLAYERONE ? playerOne->getTextColor() : playerTwo->getTextColor());
		gameResolutionMenu->doMenu();
		startingNewGame = true;
		gamesPlayed++;
	}
	else if (gameBoard->isBoardFull())
	{
		announce("There has been a tie! all squares are full!");
		gameBoard->printGameBoardWithColor((int)ConsoleColor::WHITE);
		gameResolutionMenu->doMenu();
		startingNewGame = true;
		gamesPlayed++;
	}
	else
	{
		startingNewGame = false;
	}
}

void Game::chosePlayerTurn()
{
	if (startingNewGame)
	{
		if (gamesPlayed == 0)
		{
			//If this is the first game being played, then a random player is chosen to get the first turn.
			choseRandomFirstPlayerTurn();
		}
		else
		{
			//If atleast one game has been played, the other player gets to have the first turn.
			currentPlayerTurn = currentPlayerTurn == PlayerTurn::PLAYERONE ? PlayerTurn::PLAYERTWO : PlayerTurn::PLAYERONE;
		}
	}
	else 
	{
		//If it is not a new game, just chose the other player as the next turn.
		currentPlayerTurn = currentPlayerTurn == PlayerTurn::PLAYERONE ? PlayerTurn::PLAYERTWO : PlayerTurn::PLAYERONE;
	}
}

void Game::choseRandomFirstPlayerTurn()
{
	currentPlayerTurn = time(0) % 2 == 0 ? PlayerTurn::PLAYERONE : PlayerTurn::PLAYERTWO;//chosing a 0 or 1 value based on current time and using it as a bool. Should have 50% chance result.
}

void Game::announceWinner()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentPlayerTurn == PlayerTurn::PLAYERONE ? playerOne->getTextColor() : playerTwo->getTextColor());
	std::cout << (currentPlayerTurn == PlayerTurn::PLAYERONE ? playerOne->getName() : playerTwo->getName()) << " wins!";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
	std::cout << std::endl;
}

Game::~Game()
{
	delete playerOne;
	delete playerTwo;
	delete introductionMenu;
	delete gameResolutionMenu;
	delete playerTurnMenu;
	delete gameBoard;
}
