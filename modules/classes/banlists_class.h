// Класс бан-листа

#pragma once

#ifndef _banlist_class_h_
#define _banlist_class_h_

static void SetProgramFile_Unicode (const std::string TypeUnicode) {

    if (TypeUnicode == "Program") {

        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

    } // установка кириллицы для программы

    else if (TypeUnicode == "File") {

        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);

    } // установка кириллицы для работы с файлом

} // функция для смены кодировки в зависимости от задачи

class Class_BanLists : public AbstractClass_ConfigEditor {

    private:

		std::string Banlist_Path; // путь к хранению бан-листа

		std::vector <std::string> ClientsBlockList; // список всех заблокированных клиентов
		std::vector <std::string> WorkersBlockList; // список всех заблокированных исполнителей

		std::string SaveTag_ClientsList; // Тэг-сохранения клиентов в бан-листе
		std::string SaveTag_WorkersList; // Тэг-сохранения исполнителей в бан-листе

    public:

        Class_BanLists (const Class_Settings& Settings) {

                if (Settings.getProjectBuild_Type () == "Debug")
                    this->Banlist_Path = "C:\\Users\\" + Settings.getPK_Name () + "\\AppData\\Local\\Temp\\(Debug)_AutoTaskCreator_Banlists.cfg";

                else
                    this->Banlist_Path = "C:\\Users\\" + Settings.getPK_Name () + "\\AppData\\Local\\Temp\\AutoTaskCreator_Banlists.cfg";

                if (Check_BanlistsFile ())
                    Load_LocalBanlists ();

			this->SaveTag_ClientsList = "Clients:";
			this->SaveTag_WorkersList = "Workers:";

        }

        ~Class_BanLists (void) {}

    //////////////////////////////////////////////

        const void setBanlist_Path (const std::string Str) {

            this->Banlist_Path = Str;

        } // сеттер для Banlist_Path

        const std::string getBanlist_Path (void) const {

            return this->Banlist_Path;

        } // геттер для Banlist_Path

    //////////////////////////////////////////////

        const unsigned short int getCount_ClientsBlockList (void) const {

            return this->ClientsBlockList.size ();

        } // геттер для ClientsBlockList.size

        const unsigned short int getCount_WorkersBlockList (void) const {

            return this->WorkersBlockList.size ();

        } // геттер для WorkersBlockList.size

    //////////////////////////////////////////////

        const void Clear_Banlists (void) {

            this->ClientsBlockList.clear ();
            this->WorkersBlockList.clear ();

        } // метод обнуления бан-листов

        const bool Check_BanlistsFile (void);
        const void Load_LocalBanlists (void);
        const void Update_Banlists (const Class_Settings&);
        const bool Check_Client_inBanlists (std::string&) const;

}; // класс бан-листа

const bool Class_BanLists::Check_BanlistsFile (void) {

    bool Existence = true; // существование локального списка бан-листа
    bool Clients_Founded = false;
    bool Workers_Founded = false;
    ConfigFile_Open (this->Banlist_Path);

    std::ifstream Read (this->Banlist_Path.c_str ());

        if (!Read.is_open ())
            Existence = false;

        else {

            std::string Str = "\0";


                while (Read >> Str) {

                    if (Str == this->SaveTag_ClientsList)
                        Clients_Founded = true;

                    if (Str == this->SaveTag_WorkersList)
                        Workers_Founded = true;

                }

        }

    Read.close ();

        if (!Existence || (!Clients_Founded || !Workers_Founded)) {

            remove (this->Banlist_Path.c_str ());

            std::ofstream Write (this->Banlist_Path.c_str ());
            Write << this->SaveTag_ClientsList << "\n"
                  << this->SaveTag_WorkersList << "\n";

            Write.close ();

            Clear_Banlists ();

        } // если файла нет, или чего-то нехватает в нем, то создаем файл конфига с дефолтными настройками

    std::ifstream Check (this->Banlist_Path.c_str ());

        if (!Check.is_open ())
            Exception ("Local ban-lists didnt created");

    Check.close ();

    ConfigFile_Close (this->Banlist_Path);

    return Existence;

} // метод проверки существования файла с конфигом

const void Class_BanLists::Load_LocalBanlists (void) {

    ConfigFile_Open (this->Banlist_Path);

    SetProgramFile_Unicode("File");

    std::string Str = "\0";
    bool Clients_Founded = false;
    bool Workers_Founed = false;

    std::ifstream Read (this->Banlist_Path.c_str ());

        if (Read.is_open ()) {

            while (getline (Read, Str)) {

                if (Str == this->SaveTag_ClientsList) {

                        while (getline (Read, Str)) {

                                if (Str == this->SaveTag_WorkersList)
                                    break;

                            //printf ("%s%s\n", "Client: ", Str.c_str());
                            this->ClientsBlockList.push_back (Str);
                            //++this->TotalNumber_Clients_InBanList_Count;


                        }

                    Clients_Founded = true;

                }

                if (Str == this->SaveTag_WorkersList) {

                    std::cout << "\n\n\n\n\n";

                        while (getline (Read, Str)) {

                            this->WorkersBlockList.push_back (Str);
                            //std::cout << "Worker: " << Str << "\n";
                            //++this->TotalNumber_Workers_InBanList_Count;
                            //system ("pause");

                        }

                    Workers_Founed = true;
                    break;

                }

            }

        }

        else
            Exception ("Local ban-lists didnt open");

    Read.close ();

        if (Clients_Founded == false)
            Exception ("Not found clients in local ban-lists");

        if (Workers_Founed == false)
            Exception ("Not found workers in local ban-lists");

        if ( !( (Clients_Founded == Workers_Founed) == true) ) {

            remove (this->Banlist_Path.c_str ());
            Check_BanlistsFile ();

        }

    //std::cout << "\nClients: " << this->TotalNumber_Clients_InBanList_Count << "\n";
    //std::cout << "Workers: " << this->TotalNumber_Workers_InBanList_Count << "\n";

    ConfigFile_Close (this->Banlist_Path);

    SetProgramFile_Unicode("Program");

    //system ("pause");

} // метод загрузки локальной базы бан-листов

const void Class_BanLists::Update_Banlists (const Class_Settings& Settings) {

    std::string Parser_Clients_Command = "start modules\\parser_GnuWin32\\bin\\wget.exe " + Settings.getUrl_BanList_Clients () + " --no-check-certificate --tries=1 --force-html --html-extension  --output-document=\"index.html\"";
	//std::string Parser_Clients_Command = "start modules\\parser_GnuWin32\\bin\\wget.exe " + Settings.getUrl_BanList_Clients () + " --no-check-certificate —output-document=\"index.html\"";
	std::string Str = "\0";
	system ((Parser_Clients_Command + " >nul").c_str ());

    const std::string MessageCount_String = "class=\"slim_header\">";
    std::string ClientNum_Tag = "class=\"pi_text\">1)";
    unsigned short int ClientNum_Count = 1;
	bool MessageCount_Founded = false;
	unsigned short int NewTotal_Count = 0;

	Clear_Banlists ();

        while (true) {

            std::ifstream ReadCheck ("index.html");

                while (ReadCheck >> Str);

            ReadCheck.close ();

                if (Str == "</html>")
                    break;

            Delay (1000);

        } // ожидание полного скачивания всего файла

    Delay (3000); // переписать задержку на адекватную проверку готовности

    system ("pause");

	std::ifstream Read("index.html");

        while (Read >> Str) {

            if (!MessageCount_Founded && Str.length () > 20) {

                std::string Tag = MessageCount_String;

                    for (unsigned short int i = 0; i < 20; i++)
                        Tag[i] = Str[i];

                    if (MessageCount_String == Tag) {

                        std::string StringNum = "\0";

                            for (unsigned short int i = 20; i < Str.length (); i++)
                                StringNum += Str[i];

                        NewTotal_Count = Convert_String_toInt (StringNum) - 1;
                        MessageCount_Founded = true;

                    }

            }

            if (MessageCount_Founded && Str == ClientNum_Tag) {

                Read >> Str;

                std::string FirstName = "\0";
                std::string SecondName = "\0";
                std::string Temp = "\0";

                Read >> FirstName;
                Read >> SecondName;

                    for (unsigned short int i = 0; i < SecondName.length (); i++) {

                            if (SecondName[i] == '<')
                                break;

                        Temp += SecondName[i];

                    }

                SecondName = Temp;

                ClientNum_Count++;
                ClientNum_Tag = "class=\"pi_text\">" + Convert_Int_toString (ClientNum_Count) + ")";

                std::string Name = FirstName + " " + SecondName;
                std::cout << "New Client: " << Name << "\n";
                this->ClientsBlockList.push_back (FirstName + " " + SecondName);

            }

        }

        if (!MessageCount_Founded)
            Exception ("Not found MessageCount in clients ban-lists from URL");

        if (NewTotal_Count != this->getCount_ClientsBlockList ())
            Exception ("New total count clients don`t add up");

    Read.close ();

    ConfigFile_Open (this->Banlist_Path);

    remove (this->Banlist_Path.c_str ());

    std::ofstream Write (this->Banlist_Path.c_str ());
    Write.imbue(std::locale(""));
    Write << this->SaveTag_ClientsList << "\n";

        for (unsigned short int i = 0; i < this->ClientsBlockList.size (); i++) {

            Write << this->ClientsBlockList[i] << "\n";
            std::cout << this->ClientsBlockList[i] << "\n";

        }

        system ("pause");

    Write << this->SaveTag_WorkersList << "\n";
    Write.close ();

    ConfigFile_Close (this->Banlist_Path);

    Check_BanlistsFile ();

    remove ("index.html");

} // метод загрузки актуального бан-листа

const bool Class_BanLists::Check_Client_inBanlists (std::string& Str) const {

    ConfigFile_Open (this->Banlist_Path);

    // запись в файл на Си


    return false;

} // метод проверки клиента в бан-листах

#endif // _banlist_class_h_
