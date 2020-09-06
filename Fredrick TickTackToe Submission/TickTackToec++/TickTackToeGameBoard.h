#pragma once

enum class PlayerTurn;
/*Abstraction of the tick tack toe game board. Holds the 2D array and processes game board related logic such as
  detecting a win condition.*/
class TickTackToeGameBoard
{
	//feilds
private:
	char** symbols;//2d 3 x 4 array of symbols, each pointer points to a row of chars. each row is 4 chars long.
	char** boardLayout;//2d 9 x 17 array of text to print board, each pointer points to a row of chars 17 chars long.
public:
	const char playerOneSymbol = 'O'; 
	const char playerTwoSymbol = 'X';
	//functions
private:
	/*Takes the 2D symbols array and places them into the game board arrays.
	  This should place each symbol in the corrisponding ticktacktoe square.*/
	void applySymbolsToGameBoard();
public:
	/*Constructor, Builds boardlayout for being printed.*/
	TickTackToeGameBoard();
	~TickTackToeGameBoard();

	/*When called, prints the whole gameboard including all placed symbols to console.*/
	void printGameBoard();

	/*When called, prints the whole gameboard including all placed symbols to console with the specified color.*/
	void printGameBoardWithColor(int color);

	/*When called with a slot id of 1 - 9, places the corrisponding player symbol in the board at the chosen slot depending on the provided playerTurn enum.
	  For example, slot 2 with playerTurn::PLAYERTWO will place an 'X' in row 1 column 2 of the board.*/
	void doPlayerChoiceAtSlot(unsigned int slotID, PlayerTurn playerTurn);

	/*resets the game board to its new state*/
	void resetGameBoard();

	/*When called, checks the game board for a win condition (3 of same symbols in a row) and returns true if the current player has won.*/
	bool checkForWinCondition();

	/*returns true or false depending on whether the provided slot ID is empty.*/
	bool isSlotEmpty(unsigned int slotID);

	/*returns true or false depending on whether the whole board is used up indicating a tie.*/
	bool isBoardFull();
};