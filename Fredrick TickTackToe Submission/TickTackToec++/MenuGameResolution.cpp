#include "MenuGameResolution.h"
#include "GameInstance.h"
#include "conio.h"

void MenuGameResolution::doMenu()
{
	Game::announce("What would you like to do next?");
	char pressedKeyChar = 0;
	bool validInput = false;
	while (true)//getting player choice
	{
		pressedKeyChar = 0;
		validInput = false;
		Game::announce("Press A to play again, or B to quit.");

		switch (pressedKeyChar = _getch())
		{
		case 97://a
			validInput = true;
			break;

		case 98://b
			Game::get()->isQuitting = true;
			validInput = true;
			break;

		default:
			validInput = false;
			break;
		}

		if (!validInput)
		{
			std::cout << std::endl;
			Game::error("Please chose from one of the two choices!");
			std::cout << std::endl;
			continue;
		}
		break;
	}
}