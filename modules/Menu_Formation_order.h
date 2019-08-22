// Модуль для формирования заказа. Именно здесь описан весь функционал кнопки "Создать заказ".

#pragma once

#ifndef _Menu_formation_order_h_
#define _Menu_formation_order_h_

static std::string C = "C";
static std::string CPlusPlus = "C++";
static std::string Another = "Another";
static std::string VisualStudio = "VisualStudio";
static std::string Geany = "Geany";
static std::string CodeBlocks = "Code::Blocks";
static std::string Linux = "Linux";
static std::string MacOS = "MacOS";
static std::string Windows = "Windows";

static std::string CodePath = "\0";

static bool Fill_InputData (Class_Clients& Client) {

	unsigned short int ButtonNumber = 0;
	unsigned short int Count = 0;

	std::cout << "\n\nИмя клиента:   ";

	const std::string Temp = Show_Text_Input ();

        if (Check_Input_ForExit (Temp))
            return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

	Client.setName (Temp);

	std::cout << "\n\nВыбор технологии: C / C++ / Another (C / + / A) ?:   ";

		while (true) {

			ButtonNumber = getch ();

				if (ClickCatch ("C", ButtonNumber)) {

					Client.setTechnology_Name (C);
					Show_Text_Output (C);
					break;

				}

				else if (ClickCatch ("+", ButtonNumber)) {

					Client.setTechnology_Name (CPlusPlus);
					Show_Text_Output (CPlusPlus);
					break;

				}

				else if (ClickCatch ("A", ButtonNumber)) {

                    Client.setTechnology_Name (Another);
                    Show_Text_Output (Another);
                    break;

				}


		}

        if (Client.getTechnology_Name () != Another) {

            std::cout << "\n\n\nВыбор IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("V", ButtonNumber)) {

                            Client.setIDE_Name (VisualStudio);
                            Show_Text_Output (VisualStudio);
                            break;

                        }

                        else if (ClickCatch ("G", ButtonNumber)) {

                            Client.setIDE_Name (Geany);
                            Show_Text_Output (Geany);
                            break;

                        }

                        else if (ClickCatch ("C", ButtonNumber)) {

                            Client.setIDE_Name (CodeBlocks);
                            Show_Text_Output (CodeBlocks);
                            break;

                        }

                }

            std::cout << "\n\n\nВыбор ОС: Linux / MacOS / Windows (L / M / W) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("L", ButtonNumber)) {

                            Client.setOS_Name (Linux);
                            Show_Text_Output (Linux);
                            break;

                        }

                        else if (ClickCatch ("M", ButtonNumber)) {

                            Client.setOS_Name (MacOS);
                            Show_Text_Output (MacOS);
                            break;

                        }

                        else if (ClickCatch ("W", ButtonNumber)) {

                            Client.setOS_Name (Windows);
                            Show_Text_Output (Windows);
                            break;

                        }

                }

            std::cout << "\n\n\nДобавить базовый функционал для управления меню (Y / N) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("Y", ButtonNumber)) {

                            Client.setMenuFunctional (true);
                            Show_Text_Output ("Yes");
                            break;

                        }

                        else if (ClickCatch ("N", ButtonNumber)) {

                            Client.setMenuFunctional (false);
                            Show_Text_Output ("No");
                            break;

                        }

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

        if (FirstOrderCreated == false)
                FirstOrderCreated = true;

    return true;

} // функция заполнения данных по клиенту

static void Create_Source_Code (const Class_Clients& Client, const Class_Settings& Settings) {

        if (Client.getTechnology_Name () == Another)
            return;

	std::queue <std::string> Code;

		if (Client.getIDE_Name () == VisualStudio)
			Code.push ("//#include \"stdafx.h\"\n");

    Code.push ("#include <windows.h>\n");

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

            Code.push ("	SetConsoleCP(1251);\n");
            Code.push ("	SetConsoleOutputCP(1251); // кириллица в консоли\n");

        if (Client.getOS_Name () == Windows) {

            if (Client.getIDE_Name () == Geany)
                Code.push ("	//system (\"title Лабораторная работа\");\n\n");

            else
                Code.push ("	system (\"title Лабораторная работа\");\n\n");

        }

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // переменная для работа с функцией getch\n\n\n\n");
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
			Code.push ("				} //\n\n");
			Code.push ("				if (ButtonNumber == 50) {\n\n\n\n");
			Code.push ("					Continue ();\n\n");
			Code.push ("				} //\n\n");
			Code.push ("		} // конец жизненного цикла программы\n\n");

		}

		else {

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // завершение программы\n\n");

		}

	Code.push ("}");

    CodePath = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\task.c";

		if (Client.getTechnology_Name () == CPlusPlus)
			CodePath += "pp";

    std::ofstream Write (CodePath.c_str());

		while (!Code.empty ()) {

			Write << Code.front ();
			Code.pop ();

		}

	Write.close ();

	std::ifstream Read (CodePath.c_str());

        if (!Read.is_open ())
            Exception ("Source code didnt created");

	Read.close ();

} // функция создания исходного кода

static void Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool Founded = false;

    std::ofstream Write (Path.c_str ());

        if (!Write.is_open ()) { // если такого клиента в базе еще не существует, то создать папку

            system (std::string("mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"").c_str());
            Founded = true;

        }

    Write.close ();

        if (!Founded) // если уже существует, то удалить проверочный файл
            remove (Path.c_str ());

} // функция создания папки для нового клиента

static void SendFiles_To_ClientFolders (const Class_Clients& Client, const Class_Settings& Settings, const std::string& CodePath) {

    unsigned short int TasksCount = 0;
    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\TasksCount.txt";
    std::string Str = "\0";
    system (std::string("cd " + Settings.getLabs_Path () + "\\" + Client.getName () + " && dir /B > TasksCount.txt").c_str());

    std::ifstream Read (Path.c_str ());

        if (Read.is_open ()) {

            while (getline (Read, Str))
                if (Str != "TasksCount.txt")
                    TasksCount++;

        }

        else
            Exception ("File TasksCount in Formation order didnt open");

    Read.close ();
    remove (Path.c_str ());

        for (unsigned short int i = TasksCount + 1; i < Client.getTasksCount () + TasksCount + 1; i++) {

            std::string TaskFolder_Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i);
            system (std::string("mkdir " + TaskFolder_Path).c_str ());

             std::ofstream Write ((TaskFolder_Path + "\\tz.txt").c_str ());

                if (Write.is_open ())
                    Write << "Technology = " << Client.getTechnology_Name () << "\n";

                else
                    Exception ("tz.txt didnt created in new task folder");

            Write.close ();

                if (Client.getTechnology_Name () != Another)
                    system (std::string("copy " + CodePath + " \"" + TaskFolder_Path + "\"" + " /-Y >nul").c_str ());

                else
                    system (std::string("start " + TaskFolder_Path).c_str ());

        }

        if (Client.getTechnology_Name () != Another) {

            std::string CPP = "\0";

                if (Client.getTechnology_Name () == CPlusPlus)
                        CPP = "pp";

                for (unsigned short int i = TasksCount + 1; i < Client.getTasksCount () + TasksCount + 1; i++)
                    system (std::string("start " + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\\task.c" + CPP).c_str());

        }

    remove (CodePath.c_str ());

} // функция отправки исходников по папкам проекта

const void Menu_Formation_Order (Class_Clients& Client, const Class_Settings& Settings) {

    Show_Text_ForExit ();

        if (!Fill_InputData (Client)) // заполнение данных по заказу
            return;

    Create_Client_Folder (Client, Settings); // создание папки клиента
    Create_Source_Code (Client, Settings); // создание исходников
    SendFiles_To_ClientFolders (Client, Settings, CodePath); // отправка исходников по новым папкам с заданиями

} // функция формирования заказа

#endif // _Menu_formation_order_h_
