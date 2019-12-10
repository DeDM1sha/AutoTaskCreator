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
static std::string Windows = "Windows";

static bool Fill_InputData (Class_Clients& Client, const Class_BanLists& Banlists) {

	unsigned short int New_TasksCount = 0; // переменная отвечающая за созданное кол-во новых тасков
	unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню

        while (true) {

            cls ();
            Client.Clear_Client_Parameters ();

            CenterText ("Создание нового заказа\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to reload formation order");

            std::string Stroke = Show_Text_Input ("Имя клиента:   ");

                if (Check_Input_ForExit (Stroke))
                    return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

                else if (Check_Input_ForReload (Stroke))
                    continue;

               if (Banlists.Check_Client_inBanlists (Stroke)) {

                    Exception ("This person in ban-list");
                    return false;

               }

            Client.setName (Stroke);

            std::cout << "\n\nВыбор технологии: C / C++ / Another (C / + / A) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("C", &ButtonNumber)) {

                            Client.setTechnology_Name (C);
                            Show_Text_Output (C);
                            break;

                        }

                        else if (ClickCatch ("+", &ButtonNumber)) {

                            Client.setTechnology_Name (CPlusPlus);
                            Show_Text_Output (CPlusPlus);
                            break;

                        }

                        else if (ClickCatch ("A", &ButtonNumber)) {

                            Client.setTechnology_Name (Another);
                            Show_Text_Output (Another);
                            break;

                        }

                        else if (ClickCatch ("Esc", &ButtonNumber))
                            return false;

                        else if (ClickCatch ("F5", &ButtonNumber))
                            break;

                }

                if (ClickCatch ("F5", &ButtonNumber))
                    continue;

                if (Client.getTechnology_Name () != Another) {

                    std::cout << "\n\n\nВыбор IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("V", &ButtonNumber)) {

                                    Client.setIDE_Name (VisualStudio);
                                    Show_Text_Output (VisualStudio);
                                    break;

                                }

                                else if (ClickCatch ("G", &ButtonNumber)) {

                                    Client.setIDE_Name (Geany);
                                    Show_Text_Output (Geany);
                                    break;

                                }

                                else if (ClickCatch ("C", &ButtonNumber)) {

                                    Client.setIDE_Name (CodeBlocks);
                                    Show_Text_Output (CodeBlocks);
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\nВыбор ОС: Linux / Windows (L / W) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("L", &ButtonNumber)) {

                                    Client.setOS_Name (Linux);
                                    Show_Text_Output (Linux);
                                    break;

                                }

                                else if (ClickCatch ("W", &ButtonNumber)) {

                                    Client.setOS_Name (Windows);
                                    Show_Text_Output (Windows);
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\nДобавить базовый функционал для управления меню (Y / N) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Client.setMenuFunctional (true);
                                    Show_Text_Output ("Yes\n");
                                    break;

                                }

                                else if (ClickCatch ("N", &ButtonNumber)) {

                                    Client.setMenuFunctional (false);
                                    Show_Text_Output ("No\n");
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                }

            GetNormal_Number_Value (&New_TasksCount, Stroke, "Количество заданий:   ", -1, 1000);

                if (Check_Input_ForReload (Stroke))
                    continue;

                if (Check_Input_ForExit (Stroke) || New_TasksCount == 0)
                    return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

            Client.setTasksCount (New_TasksCount);

                if (Client.getMenuFunctional () == true && Client.getTasksCount () == 1) {

                    unsigned short int Count_MenuItems = 0;

                    GetNormal_Number_Value (&Count_MenuItems, Stroke, "Количество пунктов в меню:   ", -1, 100);

                        if (Check_Input_ForReload (Stroke))
                            continue;

                        if (Check_Input_ForExit (Stroke) || Count_MenuItems == 0)
                            return false;

                    Client.setMenuItems_Count (Count_MenuItems);

                    Client.Clear_MenuItems_Title ();

                    std::cout << "\n\nНазвания к каждому пункту меню:\n";

                        for (unsigned short int i = 0; i < Count_MenuItems; i++) {

                            Stroke = Show_Text_Input (Convert_Int_toString (i + 1) + ")   ");

                                    if (Check_Input_ForReload (Stroke))
                                        break;

                                    if (Check_Input_ForExit (Stroke))
                                        return false;

                            Client.setMenuItems_Title (Stroke);

                        }

                        if (Check_Input_ForReload (Stroke))
                            continue;

                } // если в программе будет меню, и всего 1 задача по заказу

            break;

        } // конец жизненного цикла создания заказа

    return true;

} // функция заполнения данных по клиенту

static bool Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool FolderExists = true; // наличие уже такой папки

    std::ofstream Write (Path.c_str ());

        if (!Write.is_open ()) { // если такого клиента в базе еще не существует, то создать папку

            std::string Folder = "mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"";
            system (Folder.c_str());
            FolderExists = false;

        }

    Write.close ();

        if (FolderExists) // если уже существует, то удалить проверочный файл
            remove (Path.c_str ());

    return FolderExists;

} // функция создания папки для нового клиента

static std::string Create_Source_Code (const Class_Clients& Client, const Class_Settings& Settings) {

        if (Client.getTechnology_Name () == Another)
            return "\0";

    std::string CodePath = "\0";
    std::string Stroke = "\0";

	std::queue <std::string> Code;

		if (Client.getIDE_Name () == VisualStudio) {

			Code.push ("//#pragma warning (disable:4786)\n");
            Code.push ("#include <string>\n");

		}

		if (Client.getOS_Name () == Windows)
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

        if (Client.getOS_Name () == Windows) {

            Code.push ("	SetConsoleCP(1251);\n");
            Code.push ("	SetConsoleOutputCP(1251); // кириллица в консоли\n");

                if (Client.getIDE_Name () == Geany)
                    Code.push ("	//system (\"title Лабораторная работа\");");

                else
                    Code.push ("	system (\"title Лабораторная работа\");");

        }

    Code.push ("\n\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // переменная для работа с функцией getch\n\n\n\n");
			Code.push ("		while (true) { // начало жизненного цикла программы\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");


                if (Client.getTechnology_Name () == C)
                    Code.push ("			printf (\"		Меню программы\\n\\n\");\n");

                else
                    Code.push ("			cout << \"		Меню программы\\n\\n\";\n");

                for (unsigned short int i = 0; i < Client.getMenuItems_Count (); i++) {

                    if (Client.getTasksCount () == 1) // если в программе будет функционал с меню, и создается только 1 задача
                        Stroke = Client.getMenuItems_Title (i);

                    else
                        Stroke = "\0";

                    if (Client.getTechnology_Name () == C)
                        Code.push ("			printf (\"" + Convert_Int_toString (i + 1) + ". " + Stroke +"\\n\");\n");

                    else
                        Code.push ("			cout << \"" + Convert_Int_toString (i + 1) + ". " + Stroke + "\\n\";\n");

                }

                if (Client.getTechnology_Name () == C)
                    Code.push ("			printf (\"Esc. Выйти из программы\\n\");\n\n");

                else
                    Code.push ("			cout << \"Esc. Выйти из программы\\n\";\n\n");

			Code.push ("				while (true) { // защита от дурака по нажатию\n\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("					ButtonNumber = _getch ();\n\n");

				else
					Code.push ("					ButtonNumber = getch ();\n\n");

			Code.push ("						if (ButtonNumber == 27)\n");
			Code.push ("							return 0; // завершение программы\n\n");
			Code.push ("						else if (ButtonNumber > 48 && ButtonNumber < " + Convert_Int_toString (49 + Client.getMenuItems_Count ()) + ") {\n\n");
			Code.push ("							cls ();\n");
			Code.push ("							break;\n\n");
			Code.push ("						}\n\n");
			Code.push ("				}\n\n");

			bool Flag = false;

                for (unsigned short int i = 0; i < Client.getMenuItems_Count (); i++) {

                        if (Flag == false) {

                            Code.push ("				if (ButtonNumber == 49) {\n\n");
                            Flag = true;

                        }

                        else
                            Code.push ("				else if (ButtonNumber == " + Convert_Int_toString (49 + i) + ") {\n\n");

                        if (Client.getTechnology_Name () == C)
                            Code.push ("                    printf (\"      " + Client.getMenuItems_Title (i) + "\\n\\n\");\n\n\n\n");

                        else
                            Code.push ("                    cout << \"      " + Client.getMenuItems_Title (i) + "\\n\\n\";\n\n\n\n");

                    Code.push ("					Continue ();\n\n");
                    Code.push ("				} // " + Client.getMenuItems_Title (i) +"\n\n");

                }

			Code.push ("		} // конец жизненного цикла программы\n\n");

		}

		else {

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // завершение программы\n\n");

		}

	Code.push ("}");

    CodePath = "C:\\Users\\" + Settings.getPK_Name () + "\\AppData\\Local\\Temp\\task.c";

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

	return CodePath;

} // функция создания исходного кода

static void SendFiles_To_ClientFolders (const Class_Clients& Client, const Class_Settings& Settings, const std::string& CodePath, const bool* FolderExists) {

    unsigned short int Old_TasksCount = 0;

        if (FolderExists) {

            std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\Old_TasksCount.txt";
            std::string Str = "\0";
            system (std::string(Settings.getDisk_Path () + " && cd " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\" && dir /B > Old_TasksCount.txt").c_str());

            std::ifstream Read (Path.c_str ());

                if (Read.is_open ()) {

                    while (getline (Read, Str))
                        if (Str != "Old_TasksCount.txt")
                            Old_TasksCount++;

                }

                else
                    Exception ("File Old_TasksCount in Formation order didnt open");

            Read.close ();
            remove (Path.c_str ());

        }

        for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) {

            std::string TaskFolder_Path = Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"\\Task_" + Convert_Int_toString (i);
            system (std::string("mkdir " + TaskFolder_Path).c_str ());

             std::ofstream Write ((Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\\tz.txt").c_str ());

                if (Write.is_open ()) {

                    Write << "Technology = " << Client.getTechnology_Name () << "\n";
                    Write << "IDE = " << Client.getIDE_Name () << "\n";
                    Write << "OS = " << Client.getOS_Name ();

                }

                else
                    Exception ("tz.txt didnt created in new task folder");

            Write.close ();

                if (Client.getTechnology_Name () != Another)
                    system (("copy \"" + CodePath + "\" \"" + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\" /-Y >nul").c_str ());

                else
                    system (std::string("start " + TaskFolder_Path).c_str ());

        }

        if (Client.getTechnology_Name () != Another) {

            std::string CPP = "\0";

                if (Client.getTechnology_Name () == CPlusPlus)
                    CPP = "pp";

                if (Settings.getAutomatic_Open_Order()) {

                    std::string Path = Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"\\Task_";

                    //for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) { // поочередное открытие
                    for (unsigned short int i = Client.getTasksCount () + Old_TasksCount; i > Old_TasksCount; i--) { // реверсивное открытие

                        system (("start " + Path + Convert_Int_toString (i) + "\\task.c" + CPP).c_str());
                        Delay (300);

                    }

                }

        }

    remove (CodePath.c_str ());

} // функция отправки исходников по папкам проекта

const void Menu_Formation_Order (const Class_Settings& Settings, const Class_BanLists& Banlists, bool* FirstOrderCreated) {

    Show_Text_ForExit ();
    Class_Clients Client; // инициализация объекта Client

        if (!Fill_InputData (Client, Banlists)) // заполнение данных по заказу
            return;

    bool FolderExists = Create_Client_Folder (Client, Settings); // создание папки клиента, если папка существует, то false
    const std::string CodePath = Create_Source_Code (Client, Settings); // создание исходников
    SendFiles_To_ClientFolders (Client, Settings, CodePath, &FolderExists); // отправка исходников по новым папкам с заданиями

        if (*FirstOrderCreated == false)
            *FirstOrderCreated = true;

} // функция формирования заказа

#endif // _Menu_formation_order_h_
