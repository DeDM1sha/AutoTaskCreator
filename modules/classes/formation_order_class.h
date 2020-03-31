// Класс формирования заказа

#pragma once

#ifndef _formation_order_class_h
#define _formation_order_class_h

class Class_Formation_Order {

	private:

        bool FolderExists; // существует ли директория (папка) клиента
        std::string CodePath; // путь к создаваемому исходнику

	public:

		Class_Formation_Order () {

            this->FolderExists = false;
            CodePath = "\0";

		}

		~Class_Formation_Order (void) {}

        const bool CheckFolder_Exists (const std::string);
        void Create_NewOrder (const Class_Clients&, const Class_Settings&);
        const bool Create_Client_Folder (const Class_Clients&, const Class_Settings&);
        const std::string Create_Source_Code (const Class_Clients&, const Class_Settings&);
        const void SendFiles_To_ClientFolders (const Class_Clients&, const Class_Settings&, const std::string&, const bool);


}; // класс формирования заказа

const bool Class_Formation_Order::CheckFolder_Exists (const std::string FolderPath) {

    bool Result = false;
    std::string InputPath = FolderPath + "\\CheckFolder.txt";

    std::ofstream Write (InputPath.c_str ());

         if (Write.is_open ())
            Result = true;

    Write.close ();

        if (Result == true)
            remove (InputPath.c_str ());

    return Result;

} // метод проверки существовании директории (папки)

void Class_Formation_Order::Create_NewOrder (const Class_Clients& Client, const Class_Settings& Settings) {

    this->FolderExists = Create_Client_Folder (Client, Settings); // создание папки клиента, если папка существует, то false

        if (CheckFolder_Exists (Settings.getLabs_Path () + "\\" + Client.getName ()) == false)
            Exception ("Client folder didn`t created");

    CodePath = Create_Source_Code (Client, Settings); // создание исходников

    SendFiles_To_ClientFolders (Client, Settings, CodePath, &this->FolderExists); // отправка исходников по новым папкам с заданиями

} // метод создания нового заказа

const bool Class_Formation_Order::Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool FolderExists_Check = true; // наличие уже такой папки

        if (CheckFolder_Exists (Settings.getLabs_Path () + "\\" + Client.getName ()) == false) {

            std::string CreateFolder = "mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"";
            system (CreateFolder.c_str());
            FolderExists_Check = false;

        }

        if (FolderExists_Check) // если уже существует, то удалить проверочный файл
            remove (Path.c_str ());

    return FolderExists_Check;

} // метод создания папки для нового клиента

const std::string Class_Formation_Order::Create_Source_Code (const Class_Clients& Client, const Class_Settings& Settings) {

        if (Client.getTechnology_Name () == Settings.getIDE_Name_NoneIDE ())
            return "\0";

    std::string CodePath = "\0";
    std::string Stroke = "\0";

	std::queue <std::string> Code;

		if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ()) {

			Code.push ("//#pragma warning (disable:4786)\n");
            Code.push ("#include <string.h>\n");

		}

		if (Client.getOS_Name () == Settings.getOS_Name_Windows ())
            Code.push ("#include <windows.h>\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("#include <conio.h>\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("#include <stdbool.h>\n");

		}

		if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
			Code.push ("#include <stdio.h>\n\n");

		else {

			Code.push ("#include <iostream>\n\n");
			Code.push ("using namespace std;\n\n");

		}

		if (Client.getMenuFunctional () == true) {

			Code.push ("void cls (void) {\n\n");
			Code.push ("	system (\"cls\");\n\n");

				if (Client.getOS_Name () != Settings.getOS_Name_Windows())
					Code.push ("	//system (\"clear\");\n\n");

			Code.push ("} // функция очистки экрана\n\n");
			Code.push ("void DrawLine (void) {\n\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("	printf (\"\\n--------------------------------------\\n\");\n\n");

				else
					Code.push ("	cout << \"\\n--------------------------------------\\n\";\n\n");

			Code.push ("} // функция отрисовки пунктирной линии\n\n");
			Code.push ("void Continue (void) {\n\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("	printf (\"\\nДля продолжения нажмите любую клавишу... \\n\");\n");

				else
					Code.push ("	cout << \"\\nДля продолжения нажмите любую клавишу... \\n\";\n");

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
					Code.push ("	_getch ();\n\n");

				else
					Code.push ("	getch ();\n\n");

			Code.push ("} // функция ожидания нажатия\n\n");

		}

	Code.push ("int main (void) {\n\n");

        if (Client.getOS_Name () == Settings.getOS_Name_Windows ()) {

            Code.push ("	SetConsoleCP(1251);\n");
            Code.push ("	SetConsoleOutputCP(1251); // кириллица в консоли\n");
            Code.push ("	system (\"title Лабораторная работа\");");

        }

    Code.push ("\n\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // переменная для работа с функцией getch\n\n\n\n");
			Code.push ("		while (true) { // начало жизненного цикла программы\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");


                if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                    Code.push ("			printf (\"		Меню программы\\n\\n\");\n");

                else
                    Code.push ("			cout << \"		Меню программы\\n\\n\";\n");

                for (unsigned short int i = 0; i < Client.getMenuItems_Count (); i++) {

                    if (Client.getTasksCount () == 1) // если в программе будет функционал с меню, и создается только 1 задача
                        Stroke = Client.getMenuItems_Title (i);

                    else
                        Stroke = "\0";

                    if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                        Code.push ("			printf (\"" + Convert_Int_toString (i + 1) + ". " + Stroke +"\\n\");\n");

                    else
                        Code.push ("			cout << \"" + Convert_Int_toString (i + 1) + ". " + Stroke + "\\n\";\n");

                }

                if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                    Code.push ("			printf (\"Esc. Выйти из программы\\n\");\n\n");

                else
                    Code.push ("			cout << \"Esc. Выйти из программы\\n\";\n\n");

			Code.push ("				while (true) { // защита от дурака по нажатию\n\n");

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
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

                        if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                            Code.push ("                    printf (\"      " + Client.getMenuItems_Title (i) + "\\n\\n\");\n\n\n\n");

                        else
                            Code.push ("                    cout << \"      " + Client.getMenuItems_Title (i) + "\\n\\n\";\n\n\n\n");

                    Code.push ("					Continue ();\n\n");
                    Code.push ("				} // " + Client.getMenuItems_Title (i) +"\n\n");

                }

			Code.push ("		} // конец жизненного цикла программы\n\n");

		}

		else {

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // завершение программы\n\n");

		}

	Code.push ("}");

    CodePath = "C:\\Users\\" + Settings.getPK_Name () + "\\AppData\\Local\\Temp\\task.c";

		if (Client.getTechnology_Name () == Settings.getTechnology_Name_CPlusPlus ())
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

} // метод создания исходного кода

const void Class_Formation_Order::SendFiles_To_ClientFolders (const Class_Clients& Client, const Class_Settings& Settings, const std::string& CodePath, const bool FolderExists) {

    unsigned short int Old_TasksCount = 0;

        if (this->FolderExists) {

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

                    Write << Settings.getSaveTag_Field_Technology () << " = " << Client.getTechnology_Name () << "\n";
                    Write << Settings.getSaveTag_Field_IDE () << " = " << Client.getIDE_Name () << "\n";
                    Write << Settings.getSaveTag_Field_OS () << " = " << Client.getOS_Name ();

                }

                else
                    Exception ("tz.txt didnt created in new task folder");

            Write.close ();

                if (Client.getTechnology_Name () != Settings.getIDE_Name_NoneIDE ())
                    system (("copy \"" + CodePath + "\" \"" + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\" /-Y >nul").c_str ());

                else
                    system (std::string("start " + TaskFolder_Path).c_str ());

        }

        if (Client.getTechnology_Name () != Settings.getIDE_Name_NoneIDE ()) {

            std::string CPP = "\0";

                if (Client.getTechnology_Name () == Settings.getTechnology_Name_CPlusPlus ())
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

} // метод отправки исходников по папкам проекта*/

#endif // _formation_order_class_h
