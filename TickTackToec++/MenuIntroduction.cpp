#pragma once
#include "MenuIntroduction.h"
#include <iostream>
#include "GameInstance.h"
#include "Player.h"

void MenuIntroduction::doMenu() 
{
	while (true)//getting name of player one
	{
		Game::announce("Enter name for player ONE (0 - 16 characters):");
		char* input = new char[17];
		std::cin.get(input, 17);
		std::cout << std::endl;

		if (isNullOrWhiteSpace(input) || std::cin.fail())
		{
			Game::announce("Please enter atleast 1 character for player one's name!");
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());//resets the console input so we can provide more
			delete[] input;
			continue;
		}
		
		*playerOne = new Player(input, ConsoleColor::RED);
		(*playerOne)->say("Hello, i am player one!");
		std::cout << std::endl;
		break;
	}

	std::cin.ignore(std::cin.rdbuf()->in_avail());//resets the console input so we can provide more

	while (true)//getting name of player two
	{
		Game::announce("Enter name for player TWO (0 - 16 characters):");
		char* input = new char[17];
		std::cin.get(input, 17);
		std::cout << std::endl;

		if (isNullOrWhiteSpace(input) || std::cin.fail())
		{
			Game::announce("Please enter atleast 1 character for player two's name!");
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());//resets the console input so we can provide more
			delete[] input;
			continue;
		}
		*playerTwo = new Player(input, ConsoleColor::LIGHTBLUE);
		(*playerTwo)->say("Hello, i am player two!");
		std::cout << std::endl;
		break;
	}
}