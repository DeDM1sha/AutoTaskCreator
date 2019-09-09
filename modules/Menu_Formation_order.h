// ������ ��� ������������ ������. ������ ����� ������ ���� ���������� ������ "������� �����".

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

static bool Fill_InputData (Class_Clients& Client) {

	unsigned short int ButtonNumber = 0;
	unsigned short int Count = 0;

	std::cout << "\n\n��� �������:   ";

	const std::string Temp = Show_Text_Input ();

        if (Check_Input_ForExit (Temp))
            return false; // ���� ���� ������� ���� �� �������� ���� ��� ������ - ������� � ������� ���� ���������

	Client.setName (Temp);

	std::cout << "\n" << Client.getName() << "\n";
	system ("pause");

	std::cout << "\n\n����� ����������: C / C++ / Another (C / + / A) ?:   ";

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

				else if (ClickCatch ("Esc", ButtonNumber))
                    return false;

		}

        if (Client.getTechnology_Name () != Another) {

            std::cout << "\n\n\n����� IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

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

                        else if (ClickCatch ("Esc", ButtonNumber))
                            return false;

                }

            std::cout << "\n\n\n����� ��: Linux / MacOS / Windows (L / M / W) ?:   ";

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

                        else if (ClickCatch ("Esc", ButtonNumber))
                            return false;

                }

            std::cout << "\n\n\n�������� ������� ���������� ��� ���������� ���� (Y / N) ?:   ";

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

                        else if (ClickCatch ("Esc", ButtonNumber))
                            return false;

                }

        }

	std::cout << "\n";

		while (true) {

			std::cout << "\n\n���������� �������:   ";

				while (!(std::cin >> Count) || (std::cin.peek() != '\n')) {

					std::cin.clear();

						while (std::cin.get() != '\n');
							std::cout << "\n\n���������� �������:   ";

				}

				if (Count > -1 && Count < 1000)
					break;

		} // �������� �� ������ ��� ����� ���-�� �������

		if (Count == 0)
            return false;

	Client.setTasksCount (Count);

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

        if (FirstOrderCreated == false)
                FirstOrderCreated = true;

    return true;

} // ������� ���������� ������ �� �������

static bool Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool FolderExists = true; // ������� ��� ����� �����

    std::cout << "\nPath: " << Path << "\n";
    system ("pause");

    std::ofstream Write (Path.c_str ());

        if (!Write.is_open ()) { // ���� ������ ������� � ���� ��� �� ����������, �� ������� �����

            std::string Folder = "mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"";
            system (Folder.c_str());
            FolderExists = false;

            std::cout << "\nFolder: " << Folder << "\n";
            system ("pause");

        }

    Write.close ();

        if (FolderExists) // ���� ��� ����������, �� ������� ����������� ����
            remove (Path.c_str ());

    std::cout << "\nnalichie folder: " << FolderExists << "\n";

    return FolderExists;

} // ������� �������� ����� ��� ������ �������

static std::string Create_Source_Code (const Class_Clients& Client, const Class_Settings& Settings) {

        if (Client.getTechnology_Name () == Another)
            return "\0";

    std::string CodePath = "\0";

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

			Code.push ("} // ������� ������� ������\n\n");
			Code.push ("void DrawLine (void) {\n\n");

				if (Client.getTechnology_Name () == C)
					Code.push ("	printf (\"\\n--------------------------------------\\n\");\n\n");

				else
					Code.push ("	cout << \"\\n--------------------------------------\\n\";\n\n");

			Code.push ("} // ������� ��������� ���������� �����\n\n");
			Code.push ("void Continue (void) {\n\n");

				if (Client.getTechnology_Name () == C)
					Code.push ("	printf (\"\\n��� ����������� ������� ����� �������... \\n\");\n");

				else
					Code.push ("	cout << \"\\n��� ����������� ������� ����� �������... \\n\";\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	_getch ();\n\n");

				else
					Code.push ("	getch ();\n\n");

			Code.push ("} // ������� �������� �������\n\n");

		}

	Code.push ("int main (void) {\n\n");

            Code.push ("	SetConsoleCP(1251);\n");
            Code.push ("	SetConsoleOutputCP(1251); // ��������� � �������\n");

        if (Client.getOS_Name () == Windows) {

            if (Client.getIDE_Name () == Geany)
                Code.push ("	//system (\"title ������������ ������\");\n\n");

            else
                Code.push ("	system (\"title ������������ ������\");\n\n");

        }

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // ���������� ��� ������ � �������� getch\n\n\n\n");
			Code.push ("		while (true) { // ������ ���������� ����� ���������\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");

				if (Client.getTechnology_Name () == C) {

					Code.push ("			printf (\"		���� ���������\\n\\n\");\n");
					Code.push ("			printf (\"1. \\n\");\n");
					Code.push ("			printf (\"2. \\n\");\n");
					Code.push ("			printf (\"Esc. ����� �� ���������\\n\");\n\n");

				}

				else {

					Code.push ("			cout << \"		���� ���������\\n\\n\";\n");
					Code.push ("			cout << \"1. \\n\";\n");
					Code.push ("			cout << \"2. \\n\";\n");
					Code.push ("			cout << \"Esc. ����� �� ���������\\n\";\n\n");

				}

			Code.push ("				while (true) { // ������ �� ������ �� �������\n\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("					ButtonNumber = _getch ();\n\n");

				else
					Code.push ("					ButtonNumber = getch ();\n\n");

			Code.push ("						if (ButtonNumber == 27)\n");
			Code.push ("							return 0; // ���������� ���������\n\n");
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
			Code.push ("		} // ����� ���������� ����� ���������\n\n");

		}

		else {

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // ���������� ���������\n\n");

		}

	Code.push ("}");

    CodePath = "C:\\Users\\\"" + Client.getPK_Name () + "\"\\AppData\\Local\\Temp\\task.c";

		if (Client.getTechnology_Name () == CPlusPlus)
			CodePath += "pp";

    std::ofstream Write (("C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\task.c").c_str());

		while (!Code.empty ()) {

			Write << Code.front ();
			Code.pop ();

		}

	Write.close ();

	std::ifstream Read (("C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\task.c").c_str());

        if (!Read.is_open ())
            Exception ("Source code didnt created");

	Read.close ();

	return CodePath;

} // ������� �������� ��������� ����

static void SendFiles_To_ClientFolders (const Class_Clients& Client, const Class_Settings& Settings, const std::string& CodePath, const bool& FolderExists) {

    unsigned short int Old_TasksCount = 0;

        if (FolderExists) {

            std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\Old_TasksCount.txt";
            std::string Str = "\0";
            system (std::string("cd " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\" && dir /B > Old_TasksCount.txt").c_str());

            std::ifstream Read (Path.c_str ());

                if (Read.is_open ()) {

                    while (getline (Read, Str))
                        if (Str != "Old_TasksCount.txt")
                            Old_TasksCount++;

                }

                else
                    Exception ("File Old_TasksCount in Formation order didnt open");

            std::cout << "\nOldTsk: " << Old_TasksCount << "\n";
            system ("pause");

            Read.close ();
            remove (Path.c_str ());

        }

        for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) {

            std::string TaskFolder_Path = Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"\\Task_" + Convert_Int_toString (i);
            system (std::string("mkdir " + TaskFolder_Path).c_str ());

            std::cout << "\nClientFolder: " << TaskFolder_Path << "\n";
            system ("pause");

            std::string TZ = Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\\tz.txt";
            std::cout << "\nTZ: " << TZ << "\n";
            system ("pause");

             std::ofstream Write ((TZ).c_str ());

                if (Write.is_open ())
                    Write << "Technology = " << Client.getTechnology_Name () << "\n";

                else
                    Exception ("tz.txt didnt created in new task folder");

            Write.close ();

            std::string COPY = "copy \"" + CodePath + "\" \"" + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\" /-Y >nul";
            std::cout << "\ncopy = " << COPY << "\n";
            system ("pause");

                if (Client.getTechnology_Name () != Another)
                    system (COPY.c_str ());

                else
                    system (std::string("start " + TaskFolder_Path).c_str ());

        }

        if (Client.getTechnology_Name () != Another) {

            std::string CPP = "\0";

                if (Client.getTechnology_Name () == CPlusPlus)
                        CPP = "pp";

                for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) {
                        std::string OPEN = "start " + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\\task.c" + CPP;
                        std::cout << "\nOpen = " << OPEN << "\n";
                        system ("pause");
                    system (OPEN.c_str());

                }

        }

    remove (CodePath.c_str ());

} // ������� �������� ���������� �� ������ �������

const void Menu_Formation_Order (Class_Clients& Client, const Class_Settings& Settings) {

    Show_Text_ForExit ();

        if (!Fill_InputData (Client)) // ���������� ������ �� ������
            return;

    bool FolderExists = Create_Client_Folder (Client, Settings); // �������� ����� �������, ���� ����� ����������, �� false
    const std::string CodePath = Create_Source_Code (Client, Settings); // �������� ����������
    SendFiles_To_ClientFolders (Client, Settings, CodePath, FolderExists); // �������� ���������� �� ����� ������ � ���������

} // ������� ������������ ������

#endif // _Menu_formation_order_h_
