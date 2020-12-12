#pragma once
#define _COMMANDS_LENGS 10
#include <iostream>
#include <Windows.h>
#include "shapes.h"
#include <string>

class Console {
public:
	Console():figure(0), points(0), length(0) {}
	void onConsoleCall();
	~Console() {
		delete[] figure;
		delete points;
	}
private:
	Figure* figure;
	Points* points;
	int length;
	std::string strings[_COMMANDS_LENGS] = {"Create Recatangle", "Create Pentagon", "What area?", "What weight?", "What perimeter?",
											"Move Figure" , "Rotate Figure" , "Show coordinates", "Delete shape", "Exit"};
	
	bool onConversationStart();

	void setColor(int text);

	bool tryCrash();

	void createFigureFactory(int type, int count);


};