// Это модуль для формирования заказа. Именно здесь описан весь функционал кнопки "Создать заказ".

#pragma once

#ifndef _formation_order_h_
#define _formation_order_h_

static std::string C = "c";
static std::string CPlusPlus = "cpp";
static std::string VisualStudio = "VisualStudio";
static std::string Geany = "Geany";
static std::string CodeBlocks = "Code::Blocks";
static std::string Linux = "Linux";
static std::string MacOS = "MacOS";
static std::string Windows = "Windows";

/*static void Delay (unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time) {};

} // функция задержки*/

static void Show_Text_Choise (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция для отображения выбранного решения другим цветом

const void Fill_InputData (Clients& Client) {

	std::string Temp = "\0";
	short int ButtonNumber = 0;
	unsigned short int Count = 0;

	std::cout << "\n\nИмя клиента:   ";
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));
	getline (std::cin, Temp);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));
	Client.setName (Temp);

	std::cout << "\n\nВыбор технологии: C / C++ (C / +) ?:   ";

		while (true) {

			ButtonNumber = getch ();

				if (ClickCatch ("C", ButtonNumber)) {

					Client.setTechnology_Name (C);
					Show_Text_Choise ("C");
					break;

				}

				else if (ClickCatch ("+", ButtonNumber)) {

					Client.setTechnology_Name (CPlusPlus);
					Show_Text_Choise ("C++");
					break;

				}

		}

	std::cout << "\n\n\nВыбор IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

		while (true) {

			ButtonNumber = getch ();

				if (ClickCatch ("V", ButtonNumber)) {

					Client.setIDE_Name (VisualStudio);
					Show_Text_Choise (VisualStudio);
					break;

				}

				else if (ClickCatch ("G", ButtonNumber)) {

					Client.setIDE_Name (Geany);
					Show_Text_Choise (Geany);
					break;

				}

				else if (ClickCatch ("C", ButtonNumber)) {

					Client.setIDE_Name (CodeBlocks);
					Show_Text_Choise (CodeBlocks);
					break;

				}

		}

	std::cout << "\n\n\nВыбор ОС: Linux / MacOS / Windows (L / M / W) ?:   ";

		while (true) {

			ButtonNumber = getch ();

				if (ClickCatch ("L", ButtonNumber)) {

					Client.setOS_Name (Linux);
					Show_Text_Choise (Linux);
					break;

				}

				else if (ClickCatch ("M", ButtonNumber)) {

					Client.setOS_Name (MacOS);
					Show_Text_Choise (MacOS);
					break;

				}

				else if (ClickCatch ("W", ButtonNumber)) {

					Client.setOS_Name (Windows);
					Show_Text_Choise (Windows);
					break;

				}

		}

	std::cout << "\n\n\nДобавить базовый функционал для управления меню (Y / N) ?:   ";

		while (true) {

			ButtonNumber = getch ();

				if (ClickCatch ("Y", ButtonNumber)) {

					Client.setMenuFunctional (true);
					Show_Text_Choise ("Yes");
					break;

				}

				else if (ClickCatch ("N", ButtonNumber)) {

					Client.setMenuFunctional (false);
					Show_Text_Choise ("No");
					break;

				}

		}

	std::cout << "\n";

		while (true) {

			std::cout << "\n\nКоличество заданий:   ";

				while (!(std::cin >> Count) || (std::cin.peek() != '\n')) {

					std::cin.clear();

						while (std::cin.get() != '\n');
							std::cout << "\n\nКоличество заданий:   ";

				}

				if (Count > 0 && Count < 1000)
					break;

		} // проверка на дурака при вводе кол-ва заданий

	Client.setTasksCount (Count);

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

	/*std::cout << "\n---------------------------\n";
	std::cout << "Name: " << Client.getName () << "\nTech: " << Client.getTechnology_Name() << "\nIDE: " << Client.getIDE_Name() << "\nOS: " << Client.getOS_Name() << "\nFunc: " << Client.getMenuFunctional() << "\nCount: " << Client.getTasksCount();*/

}

static void Create_Source_Code (const Clients& Client) {

	std::queue <std::string> Code;

		if (Client.getIDE_Name () == VisualStudio)
			Code.push ("//#include \"stdafx.h\"\n");

		if (Client.getOS_Name () == Windows)
			Code.push ("#include <windows.h>\n");

		else {

			Code.push ("//#include <stdlib.h>\n");
			Code.push ("//#include <locale.h>\n");

		}

		if (Client.getMenuFunctional () == true) {

			Code.push ("#include <conio.h>\n");

				if (Client.getTechnology_Name () == C)
					Code.push ("#include <stdbool.h>\n");

		}

		if (Client.getTechnology_Name () == C)
			Code.push ("#include <stdio.h>\n\n");

		else {

			Code.push ("#include <iostream>\n\n");
			Code.push ("using namespace std;\n\n");

		}

		if (Client.getMenuFunctional () == true) {

			Code.push ("void cls (void) {\n\n");
			Code.push ("	system (\"cls\");\n\n");

				if (Client.getOS_Name () != Windows)
					Code.push ("	//system (\"clear\");\n\n");

			Code.push ("} // функция очистки экрана\n\n");
			Code.push ("void DrawLine (void) {\n\n");

				if (Client.getTechnology_Name () == C)
					Code.push ("	printf (\"\\n--------------------------------------\\n\");\n\n");

				else
					Code.push ("	cout << \"\\n--------------------------------------\\n\";\n\n");

			Code.push ("} // функция отрисовки пунктирной линии\n\n");
			Code.push ("void Continue (void) {\n\n");

				if (Client.getTechnology_Name () == C)
					Code.push ("	printf (\"\\nДля продолжения нажмите любую клавишу... \\n\");\n");

				else
					Code.push ("	cout << \"\\nДля продолжения нажмите любую клавишу... \\n\";\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	_getch ();\n\n");

				else
					Code.push ("	getch ();\n\n");

			Code.push ("} // функция ожидания нажатия\n\n");

		}

	Code.push ("int main (void) {\n\n");

		if (Client.getOS_Name () == Windows) {

			if (Client.getIDE_Name () == Geany) {

			Code.push ("	//SetConsoleCP(1251);\n");
			Code.push ("	//SetConsoleOutputCP(1251); // кириллица в консоли\n");
			Code.push ("	//system (\"title Лабораторная работа\");\n\n");

			}

			else {

				Code.push ("	SetConsoleCP(1251);\n");
				Code.push ("	SetConsoleOutputCP(1251); // кириллица в консоли\n");
				Code.push ("	system (\"title Лабораторная работа\");\n\n");

			}

		}

		else
			Code.push ("	//setlocale (LC_ALL, \"Russian\");\n\n");



		if (Client.getMenuFunctional () == true) {

			Code.push ("	short ButtonNumber = 0; // переменная для работа с функцией getch\n\n\n\n");
			Code.push ("		while (true) { // начало жизненного цикла программы\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");

				if (Client.getTechnology_Name () == C) {

					Code.push ("			printf (\"		Меню программы\\n\\n\");\n");
					Code.push ("			printf (\"1. \\n\");\n");
					Code.push ("			printf (\"2. \\n\");\n");
					Code.push ("			printf (\"Esc. Выйти из программы\\n\");\n\n");

				}

				else {

					Code.push ("			cout << \"		Меню программы\\n\\n\";\n");
					Code.push ("			cout << \"1. \\n\";\n");
					Code.push ("			cout << \"2. \\n\";\n");
					Code.push ("			cout << \"Esc. Выйти из программы\\n\";\n\n");

				}

			Code.push ("				while (true) { // защита от дурака по нажатию\n\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("					ButtonNumber = _getch ();\n\n");

				else
					Code.push ("					ButtonNumber = getch ();\n\n");

			Code.push ("						if (ButtonNumber == 27)\n");
			Code.push ("							return 0; // завершение программы\n\n");
			Code.push ("						if (ButtonNumber > 48 && ButtonNumber < 51) {\n\n");
			Code.push ("							cls ();\n");
			Code.push ("							break;\n\n");
			Code.push ("						}\n\n");
			Code.push ("				}\n\n");
			Code.push ("				if (ButtonNumber == 49) {\n\n\n\n");
			Code.push ("					Continue ();\n\n");
			Code.push ("				}\n\n");
			Code.push ("				if (ButtonNumber == 50) {\n\n\n\n");
			Code.push ("					Continue ();\n\n");
			Code.push ("				}\n\n");
			Code.push ("		} // конец жизненного цикла программы\n\n");

		}

		else {

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // завершение программы\n\n");

		}

	Code.push ("}");

	std::string FilePath = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\task.c";

		if (Client.getTechnology_Name () == CPlusPlus)
			FilePath += "pp";

	std::ofstream Write (FilePath.c_str());

		while (!Code.empty ()) {

			Write << Code.front ();
			Code.pop ();

		}

	Write.close ();

} // функция создания исходного кода

const void Formation_Order (void) {

    Clients Client;

	Fill_InputData (Client); // заполнение данных по заказу
	Create_Source_Code (Client); // создание исходников


} // функция формирования заказа

#endif // _formation_order_h_
