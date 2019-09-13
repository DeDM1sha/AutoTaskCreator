// Класс бан-листа

#pragma once

#ifndef _banlist_class_h_
#define _banlist_class_h_

static std::string SaveTag_ClientsList = "Clients:";
static std::string SaveTag_WorkersList = "Workers:";

class Class_BanLists : public AbstractClass_ConfigEditor {

    private:

    std::string Banlist_Path; // путь к хранению бан-листа
    unsigned short int TotalNumber_Clients_InBanList_Count; // общее кол-во клиентов в бан-листе
    unsigned short int TotalNumber_Workers_InBanList_Count; // общее кол-во исполнителей в бан-листе
    std::vector <std::string> ClientsBlockList; // список всех заблокированных клиентов
    std::vector <std::string> WorkersBlockList; // список всех заблокированных исполнителей

    public:

        Class_BanLists (const Class_Clients& Client, const Class_Settings& Settings) {

            Banlist_Path = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\Banlists.cfg";
            TotalNumber_Clients_InBanList_Count = 0;
            TotalNumber_Workers_InBanList_Count = 0;

                if (Check_BanlistsFile ())
                    Load_LocalBanlists ();


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

        const void setTotalNumber_Clients_InBanList_Count (const unsigned short int Number) {

            this->TotalNumber_Clients_InBanList_Count = Number;

        } // сеттер для TotalNumber_Clients_InBanList_Count

        const unsigned short int getTotalNumber_Clients_InBanList_Count (void) const {

            return this->TotalNumber_Clients_InBanList_Count;

        } // геттер для TotalNumber_Clients_InBanList_Count

    //////////////////////////////////////////////

        const void setTotalNumber_Workers_InBanList_Count (const unsigned short int Number) {

            this->TotalNumber_Workers_InBanList_Count = Number;

        } // сеттер для TotalNumber_Workers_InBanList_Count

        const unsigned short int getTotalNumber_Workers_InBanList_Count (void) const {

            return this->TotalNumber_Workers_InBanList_Count;

        } // геттер для TotalNumber_Workers_InBanList_Count

    //////////////////////////////////////////////

        const bool Check_BanlistsFile (void);
        const void Load_LocalBanlists (void);
        const void Update_Banlists (const Class_Settings&);


}; // класс бан-листа

const bool Class_BanLists::Check_BanlistsFile (void) {

    bool Existence = true; // существование локального списка бан-листа
    ConfigFile_Open (Banlist_Path);

    std::ifstream Read (Banlist_Path.c_str ());

        if (!Read.is_open ()) {

            std::ofstream Write (Banlist_Path.c_str (), std::ios::out);
            Write << SaveTag_ClientsList << "\n"
                  << SaveTag_WorkersList << "\n";

            Write.close ();

            Existence = false;
            TotalNumber_Clients_InBanList_Count = 0;
            TotalNumber_Workers_InBanList_Count = 0;

            std::ifstream Check (Banlist_Path.c_str ());

                if (!Check.is_open ())
                    Exception ("Local ban-lists didnt created");

            Check.close ();

        } // если файла нет, то создаем файл конфига с дефолтными настройками

    Read.close ();

    ConfigFile_Close (Banlist_Path);

    return Existence;

} // метод проверки существования файла с конфигом

const void Class_BanLists::Load_LocalBanlists (void) {

    ConfigFile_Open (Banlist_Path);

    std::string Str = "\0";
    bool Clients_Founded = false;
    bool Workers_Founed = false;

    std::ifstream Read (Banlist_Path.c_str (), std::ios::in);

        if (Read.is_open ()) {

            while (getline (Read, Str)) {

                if (Str == SaveTag_ClientsList) {

                        while (getline (Read, Str)) {

                                if (Str == SaveTag_WorkersList)
                                    break;

                            ClientsBlockList.push_back (Str);
                            //std::cout << "Client: " << Str << "\n";
                            ++TotalNumber_Clients_InBanList_Count;

                        }

                    Clients_Founded = true;

                }

                if (Str == SaveTag_WorkersList) {

                    std::cout << "\n\n\n\n\n";

                        while (getline (Read, Str)) {

                            WorkersBlockList.push_back (Str);
                            /*std::cout << "Worker: " << Str << "\n";*/
                            ++TotalNumber_Workers_InBanList_Count;

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

            remove (Banlist_Path.c_str ());
            Check_BanlistsFile ();

        }

    //std::cout << "\nClients: " << TotalNumber_Clients_InBanList_Count << "\n";
    //std::cout << "Workers: " << TotalNumber_Workers_InBanList_Count << "\n";

    ConfigFile_Close (Banlist_Path);

} // метод загрузки локальной базы бан-листов

const void Class_BanLists::Update_Banlists (const Class_Settings& Settings) {


}

#endif // _banlist_class_h_
