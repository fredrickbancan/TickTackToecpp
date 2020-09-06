#include "GameInstance.h"
int main()
{
    Game::get()->start();
    delete Game::get();
    Game::pausePrompt();
}