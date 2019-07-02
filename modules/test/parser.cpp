// #pragma once

// #ifndef _parser_H_
// #define _parser_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

#include "client_class.h"
#define BanList_Url "https://vk.com/topic-156779709_36343200"

bool Readiness_Check (std::string FilePath) {
	
	bool Result = false;
	std::ifstream Read (FilePath.c_str());
	
		if (Read.is_open())
			Result = true;
			
	Read.close ();
	
	return Result;
	
} // функция проверки существования файла по заданному пути

void BanList_Parser (void) {
	
	std::ofstream Parser ("parser.bat");
	Parser << "GnuWin32\\bin\\wget.exe " << BanList_Url << " --no-check-certificate --html-extension --output-document=\"index.html\" \nexit";
	Parser.close ();
	// сделать закрытие bat-ника при неуспешном парсинге
	
	while (!Readiness_Check ("parser.bat")) {};
	system ("start parser.bat");
	
	std::ofstream Write ("check.bat");
	Write << "echo 1 > check.txt && exit";
	Write.close ();
	
	
	while (!Readiness_Check ("check.bat")) {};
	system ("start check.bat");
	
	while (!Readiness_Check("check.txt")) {};
	
	remove ("check.txt"); // задержка перед открытием файла index.html (ожидаем загрузку исходного кода)
	remove ("parser.bat");
	remove ("check.bat");
	
	std::ifstream Read ("index.html");
		
		if (Read.is_open())
			std::cout << "true\n";
			
		else
			std::cout << "false\n";
			
	Read.close ();
	
	Delay (1000); // в релизе убрать
	remove ("index.html");
	
}

int main (void) {
	
	BanList_Parser();
	return 0;
}

//#endif // _parser_H_
