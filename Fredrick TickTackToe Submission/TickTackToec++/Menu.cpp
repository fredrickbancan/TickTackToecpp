#pragma once
#include "Menu.h"
#include "ctype.h"
void Menu::doMenu()
{
}

bool Menu::isNullOrWhiteSpace(const char* string)
{
	if (string == nullptr || *string == NULL)//if the string is uninitialized
	{
		return true;
	}

	int i = 0;
	char currentChar;

	while (string[i])
	{
		currentChar = string[i];
		
		if (i == 0 && currentChar == '\0')//if the only char in the string is the null terminator
		{
			return true;
		}

		if (!isblank(currentChar) && !isspace(currentChar))
		{
			return false;
		}

		i++;
	}

	return true;
}