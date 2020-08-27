#pragma once
#include <iostream>
#include "Windows.h"
/*an enum class for chosing console colours*/
enum class ConsoleColor
{
	BLACK = 128,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	DARKMAGENTA = 5,
	GOLD = 6,
	LIGHTGREY = 7,
	GREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	PINK = 12,
	MAGENTA = 13,
	LIGHTYELLOW = 14,
	WHITE = 15,
};

/*An enum class for chosing which players turn it is.*/
enum class PlayerTurn
{
	NONE,
	PLAYERONE,
	PLAYERTWO
};

class Menu;
class Player;
class TickTackToeGameBoard;
/*A singleton class for abstracting the main game logic*/
class Game
{
//feilds
private:
	static Game* instance;
	bool startingNewGame = true;
	unsigned int gamesPlayed = 0;
    Menu* introductionMenu;
	Menu* playerTurnMenu;
	Menu* gameResolutionMenu;
public:
	bool isQuitting = false;
	TickTackToeGameBoard* gameBoard;
	Player* playerOne;
	Player* playerTwo;
	PlayerTurn currentPlayerTurn = PlayerTurn::NONE;
	static const ConsoleColor defaultConsoleColor = ConsoleColor::BLACK;

//functions
private:
public:
	/*returns a pointer to the singleton game instance, If its not created yet, will create it.*/
	static Game* get();
	~Game();

	/*Initializes and begins the game*/
	void start();

	/*Begins recurring loop of game logic*/
	void doGameLoop();

	/*called every itteration of game logic*/
	void onUpdate();

	/*Choses which player should have their turn next*/
	void chosePlayerTurn();

	/*choses randomly which players turn it is.*/
	void choseRandomFirstPlayerTurn();

	/*Returns the pointer to the current player whos turn it is.*/
	class Player* getCurrentPlayerByTurn() { return currentPlayerTurn == PlayerTurn::PLAYERONE ? playerOne : playerTwo; }

	/*announces a winner with their name*/
	void announceWinner();

	/*Can be called to announce a string into console using the games default text color*/
	static void announce(const char* input)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)defaultConsoleColor);
		std::cout << input;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
		std::cout << std::endl;
	}

	/*Can be called to print an error to console, should not be part of gameplay.*/
	static void error(const char* input)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::RED);
		std::cout << "ERROR: " << input;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
		std::cout << std::endl;
	}

	/*can be called to pause the console prompt, asks the current user to press enter to continue.*/
	static void pausePrompt()
	{
		std::cout << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)defaultConsoleColor);
		system("PAUSE");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
		std::cout << std::endl;
	}
};