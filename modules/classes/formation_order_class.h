// ����� ������������ ������

#pragma once

#ifndef _formation_order_class_h
#define _formation_order_class_h

class Class_Formation_Order {

	private:

        bool FolderExists; // ���������� �� ���������� (�����) �������
        std::string CodePath; // ���� � ������������ ���������

	public:

		Class_Formation_Order () {

            this->FolderExists = false;
            this->CodePath = "\0";

		}

		~Class_Formation_Order (void) {}

        const bool CheckFolder_Exists (const std::string);
        void Create_NewOrder (const Class_Clients&, const Class_Settings&);
        const bool Create_Client_Folder (const Class_Clients&, const Class_Settings&);
        const std::string Create_Source_Code (const Class_Clients&, const Class_Settings&);
        const void SendFiles_To_ClientFolders (const Class_Clients&, const Class_Settings&, const std::string&, const bool);

}; // ����� ������������ ������

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

} // ����� �������� ������������� ���������� (�����)

void Class_Formation_Order::Create_NewOrder (const Class_Clients& Client, const Class_Settings& Settings) {

    this->FolderExists = Create_Client_Folder (Client, Settings); // �������� ����� �������, ���� ����� ����������, �� false

        if (CheckFolder_Exists (Settings.getLabs_Path () + "\\" + Client.getName ()) == false)
            Exception ("Client folder didn`t created");

    CodePath = Create_Source_Code (Client, Settings); // �������� ����������

    SendFiles_To_ClientFolders (Client, Settings, CodePath, &this->FolderExists); // �������� ���������� �� ����� ������ � ���������

} // ����� �������� ������ ������

const bool Class_Formation_Order::Create_Client_Folder (const Class_Clients& Client, const Class_Settings& Settings) {

    std::string Path = Settings.getLabs_Path () + "\\" + Client.getName () + "\\CheckFolder.txt";
    bool FolderExists_Check = true; // ������� ��� ����� �����

        if (CheckFolder_Exists (Settings.getLabs_Path () + "\\" + Client.getName ()) == false) {

            std::string CreateFolder = "mkdir " + Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"";
            system (CreateFolder.c_str());
            FolderExists_Check = false;

        }

        if (FolderExists_Check) // ���� ��� ����������, �� ������� ����������� ����
            remove (Path.c_str ());

    return FolderExists_Check;

} // ����� �������� ����� ��� ������ �������

const std::string Class_Formation_Order::Create_Source_Code (const Class_Clients& Client, const Class_Settings& Settings) {

        if (Client.getTechnology_Name () == Settings.getTechnology_Name_Another ())
            return "\0";

    std::string CodePath = "\0";
    std::string Stroke = "\0";

	std::queue <std::string> Code;

		if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
			Code.push ("//#pragma warning (disable:4786)\n");

        if (Client.getTechnology_Name () == Settings.getTechnology_Name_CPlusPlus ())
            Code.push ("#include <string>\n");

		if (Client.getOS_Name () == Settings.getOS_Name_Windows ())
            Code.push ("#include <windows.h>\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("#include <conio.h>\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("#include <stdbool.h>\n");

		}

		if (Client.getIDE_Name () == Settings.getIDE_Name_QtCreator ()) {

            Code.push ("#include <QTextCodec>\n");
             Code.push ("#include <QCoreApplication>\n");

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

			Code.push ("} // ������� ������� ������\n\n");
			Code.push ("void DrawLine (void) {\n\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("	printf (\"\\n--------------------------------------\\n\");\n\n");

				else
					Code.push ("	cout << \"\\n--------------------------------------\\n\";\n\n");

			Code.push ("} // ������� ��������� ���������� �����\n\n");
			Code.push ("void Continue (void) {\n\n");

				if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
					Code.push ("	printf (\"\\n��� ����������� ������� ����� �������... \\n\");\n");

				else
					Code.push ("	cout << \"\\n��� ����������� ������� ����� �������... \\n\";\n");

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
					Code.push ("	_getch ();\n\n");

				else
					Code.push ("	getch ();\n\n");

			Code.push ("} // ������� �������� �������\n\n");

		}

		if (Client.getIDE_Name () == Settings.getIDE_Name_QtCreator ()) {

                if (Client.getTechnology_Name () == Settings.getTechnology_Name_CPlusPlus ()) {

                    Code.push ("void print (string Text) {\n\n");
                    Code.push ("    cout << QString::fromUtf8(Text.c_str()).toLocal8Bit().data();\n\n");

                }

                else if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ()) {

                    Code.push ("void print (const char* Text) {\n\n");
                    Code.push ("    printf (\"%s\" , QString::fromUtf8(Text).toLocal8Bit().data());\n\n");

                }

            Code.push ("}; // ������� ������ ������ ��������� �� �����\n\n");

		}

	Code.push ("int main (void) {\n\n");

        if (Client.getOS_Name () == Settings.getOS_Name_Windows ()) {

                if (Client.getIDE_Name () != Settings.getIDE_Name_QtCreator ()) {

                    Code.push ("	SetConsoleCP(1251);\n");
                    Code.push ("	SetConsoleOutputCP(1251); // ��������� � �������\n");
                    Code.push ("	system (\"title ������������ ������\");");

                }

                else {

                    Code.push ("    #ifdef Q_OS_WIN32\n");
                    Code.push ("        QTextCodec::setCodecForLocale(QTextCodec::codecForName(\"IBM 866\"));\n");
                    Code.push ("    #endif\n\n");
                    Code.push ("    system (\"title Lab Work\");\n");

                }

        }

    Code.push ("\n\n");

		if (Client.getMenuFunctional () == true) {

			Code.push ("	int ButtonNumber = 0; // ���������� ��� ������ � �������� getch\n\n\n\n");
			Code.push ("		while (true) { // ������ ���������� ����� ���������\n\n");
			Code.push ("			ButtonNumber = 0;\n");
			Code.push ("			cls ();\n\n");


                if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                    Code.push ("			printf (\"		���� ���������\\n\\n\");\n");

                else
                    Code.push ("			cout << \"		���� ���������\\n\\n\";\n");

                for (unsigned short int i = 0; i < Client.getMenuItems_Count (); i++) {

                    if (Client.getTasksCount () == 1) // ���� � ��������� ����� ���������� � ����, � ��������� ������ 1 ������
                        Stroke = Client.getMenuItems_Title (i);

                    else
                        Stroke = "\0";

                    if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                        Code.push ("			printf (\"" + Convert_Int_toString (i + 1) + ". " + Stroke +"\\n\");\n");

                    else
                        Code.push ("			cout << \"" + Convert_Int_toString (i + 1) + ". " + Stroke + "\\n\";\n");

                }

                if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                    Code.push ("			printf (\"Esc. ����� �� ���������\\n\");\n\n");

                else
                    Code.push ("			cout << \"Esc. ����� �� ���������\\n\";\n\n");

			Code.push ("				while (true) { // ������ �� ������ �� �������\n\n");

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
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

                        if (Client.getTechnology_Name () == Settings.getTechnology_Name_C ())
                            Code.push ("                    printf (\"      " + Client.getMenuItems_Title (i) + "\\n\\n\");\n\n\n\n");

                        else
                            Code.push ("                    cout << \"      " + Client.getMenuItems_Title (i) + "\\n\\n\";\n\n\n\n");

                    Code.push ("					Continue ();\n\n");
                    Code.push ("				} // " + Client.getMenuItems_Title (i) +"\n\n");

                }

			Code.push ("		} // ����� ���������� ����� ���������\n\n");

		}

		else {

				if (Client.getIDE_Name () == Settings.getIDE_Name_VisualStudio ())
					Code.push ("	//system (\"pause\");\n\n");

			Code.push ("	return 0; // ���������� ���������\n\n");

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

} // ����� �������� ��������� ����

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

                if (Client.getTechnology_Name () != Settings.getTechnology_Name_Another ())
                    system (("copy \"" + CodePath + "\" \"" + Settings.getLabs_Path () + "\\" + Client.getName () + "\\Task_" + Convert_Int_toString (i) + "\" /-Y >nul").c_str ());
        }

        if (Settings.getAutomatic_Open_Order()) {

            std::string Path = Settings.getLabs_Path () + "\\\"" + Client.getName () + "\"\\Task_";
            std::string CPP = "\0";

                if (Client.getTechnology_Name () == Settings.getTechnology_Name_CPlusPlus ())
                            CPP = "pp";

                //for (unsigned short int i = Old_TasksCount + 1; i < Client.getTasksCount () + Old_TasksCount + 1; i++) { // ����������� ��������
                for (unsigned short int i = Client.getTasksCount () + Old_TasksCount; i > Old_TasksCount; i--) { // ����������� ��������

                     Sleep (1000);

                        if (Client.getTechnology_Name () != Settings.getTechnology_Name_Another ())
                            system (("start " + Path + Convert_Int_toString (i) + "\\task.c" + CPP).c_str());

                        else
                            system (("explorer " + Path + Convert_Int_toString (i)).c_str());


                }

        }

    remove (CodePath.c_str ());

} // ����� �������� ���������� �� ������ �������

#endif // _formation_order_class_h
