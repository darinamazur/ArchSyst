#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int MainMenu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) std::cout << "-> Show file " << std::endl;
		else  std::cout << "Show file" << std::endl;
		if (key == 1) std::cout << "-> Clear file" << std::endl;
		else  std::cout << "Clear file" << std::endl;
		if (key == 2) std::cout << "-> Add new option " << std::endl;
		else  std::cout << "Add new option" << std::endl;
		if (key == 3) std::cout << "-> Run program" << std::endl;
		else  std::cout << "Run program" << std::endl;
		if (key == 4) std::cout << "-> Exit" << std::endl;
		else  std::cout << "Exit" << std::endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}