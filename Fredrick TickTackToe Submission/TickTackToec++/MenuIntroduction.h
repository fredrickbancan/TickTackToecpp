#pragma once
#include "Menu.h"
class Player;
/*console output menu for getting player names, also initializes player objects*/
class MenuIntroduction : public Menu
{
	//feilds
private:
	Player** playerOne;
	Player** playerTwo;
public:
	//functions
private:
public:
	MenuIntroduction(Player** playerOne, Player** playerTwoNameResult) : playerOne(playerOne), playerTwo(playerTwoNameResult) {};
    void doMenu() override;
};