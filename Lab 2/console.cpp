#pragma once
#include "console.h"
#include "shapeFactory.h"

Console::Console() :figure(0), points(0), length(0) {};

void Console::onConsoleCall() {
	setColor(3);
	std::cout << "Hello, I'm your assistant. Let's start? Type Y/N" << std::endl;
	setColor(15);
	char answer;
	std::cin >> answer;
	answer = tolower(answer);

	if (answer == 'y') {

		/*create loop*/
		while (onConversationStart());
	}
	setColor(3);
	std::cout << "See you!" << std::endl;
	setColor(15);
}

bool Console::onConversationStart() {
	std::cout << std::endl << "-----------------------------" << std::endl;

	std::cout << "What do you want?" << std::endl;
	setColor(14);
	std::cout << "Only one figure can be create at moment" << std::endl;
	setColor(15);
	for (int i = 0; i < _COMMANDS_LENGS; i++) {
		if (i == _COMMANDS_LENGS - 1) {
			std::cout << "0. " << strings[i] << std::endl;
		}
		else {
			std::cout << i + 1 << ". " << strings[i] << std::endl;
		}
	}
	std::cout << std::endl << "-----------------------------" << std::endl;
	int answer;
	std::cin >> answer;
	switch (answer) {
		case 0:
			return false;

		case 1:
			createFigureFactory();
			return true;

		case 2:
			if (tryCrash()) {
				std::cout << figure->getArea() << std::endl;
			}
			return true;

		case 3:
			if (tryCrash()) {
				double* point = figure->getWeight();
				std::cout << "(" << point[0] << ", " << point[1] << ")" << std::endl;
				point = NULL;
				delete[] point;
			}
			return true;
		case 4:
			if (tryCrash()) {
				std::cout << figure->getPerimeter() << std::endl;
			}
			return true;
			

		case 5:
			if (tryCrash()) {
				std::cout << "Enter how much to increase. Two points x and y" << std::endl;
				double x, y;
				std::cin >> x >> y;
				figure->onMove(x, y);
			}
			return true;

		case 6:
			if (tryCrash()) {
				std::cout << "Enter angle in degrees" << std::endl;
				double angle;
				std::cin >> angle;
				figure->onRotate(angle);
			}
			return true;			

		case 7: 
			if (tryCrash()) {
				for (int i = 0; i < length; i++) {
					std::cout << i + 1 << ". " << figure->points->x[i] << " " << figure->points->y[i] << std::endl;
				}
			}
			return true;

		case 8:
			if (tryCrash()) {
				figure = NULL;
				points = NULL;
				setColor(10);
				std::cout << "Ok figure is deleted" << std::endl;
				setColor(15);
			}
			return true;		

		default:
			setColor(10);
			std::cout << "Try again, my boy..." << std::endl;
			setColor(15);
			return true;
	}

		
	
}

void Console::setColor(int text){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | text));
}

bool Console::tryCrash() {
	if (!figure) {
		setColor(12);
		std::cout << "Don't try to crash me. Initialaise figure" << std::endl;
		setColor(15);
		return false;
	}
	return true;

}

void Console::createFigureFactory() {
	setColor(14);
	std::cout << "Enter count of points" << std::endl;
	setColor(15);
	int count;
	std::cin >> count;
	length = count;
	figure = NULL;
	points = NULL;
	
	figure = ShapeFactory::createFigure(count, points);

	if ( figure == NULL || !figure->Figure::asSidesExist(count)) {
		setColor(12);
		std::cout << "Enter exist figure!" << std::endl;
		setColor(15);
		figure = NULL;
		return;
	}

}

Console::~Console() {
	delete figure;
}