#pragma once
enum class ConsoleColor;
/*Object for containing the name and text color of each player*/
class Player
{
	//feilds
private:
	const char* playerName;
	ConsoleColor textColor;
public:

	//methods
private:
public:
	Player(const char* playerName, ConsoleColor textColor) : playerName(playerName), textColor(textColor) {};
	~Player();
	
	const char* getName()
	{
		return playerName;
	}

	const int getTextColor()
	{
		return (int)textColor;
	}

	/*Prints the input into the console with the name and color of this player.*/
	void say(const char* string);
};