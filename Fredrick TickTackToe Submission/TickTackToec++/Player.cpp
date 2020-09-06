#include "Windows.h"
#include "Player.h"
#include <iostream>
#include "GameInstance.h"

void Player::say(const char* input)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), getTextColor());
	std::cout << getName() << " says: "<< input;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)ConsoleColor::WHITE);
	std::cout << std::endl;
}

Player::~Player() 
{
	delete[] playerName;
}