#pragma once
/*Base class for all text based menus, not much base functionality.*/
class Menu
{
	//feilds
protected:
public:
	//functions
protected:
	/*Loops through a provided string and checks if it is null or doesnt contain any non white space characters. Returns true if either is true.*/
	static bool isNullOrWhiteSpace(const char* string);
public:
	virtual void doMenu();
};