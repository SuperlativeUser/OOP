#pragma once
#include <iostream>
#include <Windows.h>
#include "Ractangle.h"
#include "pentagon.h"
#include <string>

class Console {
public:
	Console();
	void onConsoleCall();
	~Console();
private:
	static const int _COMMANDS_LENGS = 9;
	Figure* figure;
	int length;
	std::string strings[_COMMANDS_LENGS] = {"Create shape", "What area?", "What weight?", "What perimeter?",
											"Move Figure" , "Rotate Figure" , "Show coordinates", "Delete shape", "Exit"};
	
	bool onConversationStart();

	static void setColor(int text);

	bool tryCrash();

	void createFigureFactory();
};