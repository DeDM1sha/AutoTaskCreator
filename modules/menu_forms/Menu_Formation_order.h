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
static std::string None = "None";
static std::string Linux = "Linux";
static std::string Windows = "Windows";

static bool Fill_InputData (Class_Clients& Client, const Class_BanLists& Banlists) {

	unsigned short int New_TasksCount = 0; // ���������� ���������� �� ��������� ���-�� ����� ������
	unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����

        while (true) {

            cls ();
            Client.Clear_Client_Parameters ();

            CenterText ("�������� ������ ������\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to reload formation order");

            std::string Stroke = Show_Text_Input ("��� �������:   ", true);

                if (Check_Input_ForExit (Stroke))
                    return false; // ���� ���� ������� ���� �� �������� ���� ��� ������ - ������� � ������� ���� ���������

                else if (Check_Input_ForReload (Stroke))
                    continue;

               if (Banlists.Check_Client_inBanlists (Stroke)) {

                    Exception ("This person in ban-list");
                    return false;

               }

            Client.setName (Stroke);

            std::cout << "\n\n����� ����������: C / C++ / Another (C / + / A) ?:   ";

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

                    std::cout << "\n\n\n����� IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

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

                    std::cout << "\n\n\n����� ��: Linux / Windows (L / W) ?:   ";

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

                    std::cout << "\n\n\n�������� ������� ���������� ��� ���������� ���� (Y / N) ?:   ";

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

                else {

                    printf ("\n");
                    Client.setOS_Name (Windows);
                    Client.setIDE_Name (None);

                }

            GetNormal_Number_Value (&New_TasksCount, Stroke, "���������� �������:   ", -1, 1000);

                if (Check_Input_ForReload (Stroke))
                    continue;

                if (Check_Input_ForExit (Stroke) || New_TasksCount == 0)
                    return false; // ���� ���� ������� ���� �� �������� ���� ��� ������ - ������� � ������� ���� ���������

            Client.setTasksCount (New_TasksCount);

                if (Client.getMenuFunctional () == true && Client.getTasksCount () == 1) {

                    unsigned short int Count_MenuItems = 0;

                    GetNormal_Number_Value (&Count_MenuItems, Stroke, "���������� ������� � ����:   ", -1, 100);

                        if (Check_Input_ForReload (Stroke))
                            continue;

                        if (Check_Input_ForExit (Stroke) || Count_MenuItems == 0)
                            return false;

                    Client.setMenuItems_Count (Count_MenuItems);

                    Client.Clear_MenuItems_Title ();

                    std::cout << "\n\n�������� � ������� ������ ����:\n";

                        for (unsigned short int i = 0; i < Count_MenuItems; i++) {

                            Stroke = Show_Text_Input (Convert_Int_toString (i + 1) + ")   ", true);

                                    if (Check_Input_ForReload (Stroke))
                                        break;

                                    if (Check_Input_ForExit (Stroke))
                                        return false;

                            Client.setMenuItems_Title (Stroke);

                        }

                        if (Check_Input_ForReload (Stroke))
                            continue;

                } // ���� � ��������� ����� ����, � ����� 1 ������ �� ������

            break;

        } // ����� ���������� ����� �������� ������

    return true;

} // ������� ���������� ������ �� �������

static bool Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool FolderExists = true; // ������� ��� ����� �����

    std::ofstream Write (Path.c_str ());

        if (!Write.is_open ()) { // ���� ������ ������� � ���� ��� �� ����������, �� ������� �����

            std::string Folder = "mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"";
            system (Folder.c_str());
            FolderExists = false;

        }

    Write.close ();

        if (FolderExists) // ���� ��� ����������, �� ������� ����������� ����
            remove (Path.c_str ());

    return FolderExists;

} // ������� �������� ����� ��� ������ �������

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

        if (Client.getOS_Name () == Windows) {

            Code.push ("	SetConsoleCP(1251);\n");
            Code.push ("	SetConsoleOutputCP(1251); // ��������� � �������\n");
            Code.push ("	system (\"title ������������ ������\");");

        }

    Code.push ("\n\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // ���������� ��� ������ � �������� getch\n\n\n\n");
			Code.push ("		while (true) { // ������ ���������� ����� ���������\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");


                if (Client.getTechnology_Name () == C)
                    Code.push ("			printf (\"		���� ���������\\n\\n\");\n");

                else
                    Code.push ("			cout << \"		���� ���������\\n\\n\";\n");

                for (unsigned short int i = 0; i < Client.getMenuItems_Count (); i++) {

                    if (Client.getTasksCount () == 1) // ���� � ��������� ����� ���������� � ����, � ��������� ������ 1 ������
                        Stroke = Client.getMenuItems_Title (i);

                    else
                        Stroke = "\0";

                    if (Client.getTechnology_Name () == C)
                        Code.push ("			printf (\"" + Convert_Int_toString (i + 1) + ". " + Stroke +"\\n\");\n");

                    else
                        Code.push ("			cout << \"" + Convert_Int_toString (i + 1) + ". " + Stroke + "\\n\";\n");

                }

                if (Client.getTechnology_Name () == C)
                    Code.push ("			printf (\"Esc. ����� �� ���������\\n\");\n\n");

                else
                    Code.push ("			cout << \"Esc. ����� �� ���������\\n\";\n\n");

			Code.push ("				while (true) { // ������ �� ������ �� �������\n\n");

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("					ButtonNumber = _getch ();\n\n");

				else
					Code.push ("					ButtonNumber = getch ();\n\n");

			Code.push ("						if (ButtonNumber == 27)\n");
			Code.push ("							return 0; // ���������� ���������\n\n");
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

			Code.push ("		} // ����� ���������� ����� ���������\n\n");

		}

		else {

				if (Client.getIDE_Name () == VisualStudio)
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // ���������� ���������\n\n");

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

} // ������� �������� ��������� ����

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

                    //for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) { // ����������� ��������
                    for (unsigned short int i = Client.getTasksCount () + Old_TasksCount; i > Old_TasksCount; i--) { // ����������� ��������

                        system (("start " + Path + Convert_Int_toString (i) + "\\task.c" + CPP).c_str());
                        Delay (300);

                    }

                }

        }

    remove (CodePath.c_str ());

} // ������� �������� ���������� �� ������ �������

const void Menu_Formation_Order (const Class_Settings& Settings, const Class_BanLists& Banlists, bool* FirstOrderCreated) {

    Show_Text_ForExit ();
    Class_Clients Client; // ������������� ������� Client

        if (!Fill_InputData (Client, Banlists)) // ���������� ������ �� ������
            return;

    bool FolderExists = Create_Client_Folder (Client, Settings); // �������� ����� �������, ���� ����� ����������, �� false
    const std::string CodePath = Create_Source_Code (Client, Settings); // �������� ����������
    SendFiles_To_ClientFolders (Client, Settings, CodePath, &FolderExists); // �������� ���������� �� ����� ������ � ���������

        if (*FirstOrderCreated == false)
            *FirstOrderCreated = true;

} // ������� ������������ ������

#endif // _Menu_formation_order_h_
