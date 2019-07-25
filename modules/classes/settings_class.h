// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

static std::string SaveTag_Path_to_Labs = "Path_to_Labs";
static std::string SaveTag_Order_Start = "Order_Start";
static std::string SaveTag_Close_Application = "Close_Application";

class Class_Settings {

    private:

        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб
        bool Automatic_Order_Start; // автоматический запуск создания заказа
        bool Automatic_Close_Application; // автоматическое завершение приложения после заполнения заказа
        std::string Url_BanList_Clients; // ссылка на банлист клиентов
        std::string Url_BanList_Workers; // ссылка на банлист исполнителей

    public:

        Class_Settings (const Class_Clients& Client) {

            Config_Path = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";
            Check_ConfigFile ();
            Load_Parameters ();

        }

        ~Class_Settings (void) {}

    //////////////////////////////////////////////

        const void setLabs_Path (const std::string Str) {

            this->Labs_Path = Str;

        } // сеттер для Labs_Path

        const std::string getLabs_Path (void) const {

            return this->Labs_Path;

        } // геттер для Labs_Path

    //////////////////////////////////////////////

        const void setConfig_Path (const std::string Str) {

            this->Config_Path = Str;

        } // сеттер для Config_Path

        const std::string getConfig_Path (void) const {

            return this->Config_Path;

        } // геттер для Config_Path

    //////////////////////////////////////////////

        const void setAutomatic_Order_Start (const bool Flag) {

            this->Automatic_Order_Start = Flag;

        } // сеттер для Automatic_Order_Start

        const bool getAutomatic_Order_Start (void) const {

            return this->Automatic_Order_Start;

        } // геттер для Automatic_Order_Start

    //////////////////////////////////////////////

        const void setAutomatic_Close_Application (const bool Flag) {

            this->Automatic_Close_Application = Flag;

        } // сеттер для Automatic_Close_Application

        const bool getAutomatic_Close_Application (void) const {

            return this->Automatic_Close_Application;

        } // геттер для Automatic_Close_Applcation

    //////////////////////////////////////////////

        const void setUrl_BanList_Clients (const std::string Str) {

            this->Url_BanList_Clients = Str;

        } // сеттер для Url_BanList_Clients

        const std::string getUrl_BanList_Clients (void) const {

            return this->Url_BanList_Clients;

        } // геттер для Url_BanList_Clients

    //////////////////////////////////////////////

        const void setUrl_BanList_Workers (const std::string Str) {

            this->Url_BanList_Workers = Str;

        } // сеттер для Url_BanList_Workers

        const std::string getUrl_BanList_Workers (void) const {

            return this->Url_BanList_Workers;

        } // геттер для Url_BanList_Workers

    //////////////////////////////////////////////

         const void SetDefault_Parameters (void) {

            this->Labs_Path = "E:\\C++Tasks";
            this->Automatic_Order_Start = false;
            this->Automatic_Close_Application = false;

        } // метод установки настроек по умолчанию

        const void Check_ConfigFile (void);
        const void ConfigFile_Open (void) const;
        const void ConfigFile_Close (void) const;
        const void Load_Parameters (void);
        const void SaveSettings (const bool) const;
};

const void Class_Settings::Check_ConfigFile (void) {

    ConfigFile_Open ();

    std::ifstream Read (Config_Path.c_str ());

        if (!Read.is_open ()) {

            SetDefault_Parameters ();
            SaveSettings (false);

            std::ifstream Check (Config_Path.c_str ());

                if (!Check.is_open ())
                    Exception ("Default settings didnt created");

            Check.close ();

        } // если файла нет, то создаем файл конфига с дефолтными настройками

    Read.close ();

    ConfigFile_Close ();

} // метод проверки существования файла с конфигом

const void Class_Settings::ConfigFile_Open (void) const {

    std::string attrib = "attrib -r -s -h -x " + Config_Path;

    system (attrib.c_str());

} // метод открытия файла конфига

const void Class_Settings::ConfigFile_Close (void) const {

    std::string attrib = "attrib +r +s +h +x " + Config_Path;

    system (attrib.c_str());

} // метод сохранения файла конфига

const void Class_Settings::Load_Parameters (void) {

    ConfigFile_Open ();

    std::string Str = "\0";
    bool LabsPath_Founded = false;
    bool OrderStart_Founded = false;
    bool CloseApp_Founded = false;

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == SaveTag_Path_to_Labs && LabsPath_Founded == false) {

                    Read >> Str;
                    Read >> Labs_Path;
                    LabsPath_Founded = true;

                }

                if (Str == SaveTag_Order_Start && OrderStart_Founded == false) {

                    Read >> Str;
                    Read >> Automatic_Order_Start;
                    OrderStart_Founded = true;

                }

                if (Str == SaveTag_Close_Application && CloseApp_Founded == false) {

                    Read >> Str;
                    Read >> Automatic_Close_Application;
                    CloseApp_Founded = true;

                }

            }

        }

        else
            Exception ("File Settings didnt open");

    Read.close ();

        if (LabsPath_Founded == false)
            Exception ("Not found Path_to_Labs in settings file");

        if (OrderStart_Founded == false)
            Exception ("Not found Automatic_Order_Start in settings file");

        if (CloseApp_Founded == false)
            Exception ("Not found Automatic_Close_Application in settings file");

        if (!(((LabsPath_Founded == OrderStart_Founded) == CloseApp_Founded) == true)) {

            remove (Config_Path.c_str ());
            Check_ConfigFile ();

        }

    ConfigFile_Close ();

}

/*const bool Load_Order_Start (void) const {

    std::string Str = "\0";
    bool Found = false;
    bool Flag = false;

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == SaveTag_Order_Start) {

                    Read >> Str;
                    Read >> Flag;
                    Found = true;

                }

            }

        }

        else
            Exception ("File Settings didnt open");

        if (Found == false)
            Exception ("Not found Automatic_Order_Start in settings file");

    Read.close ();

    return Flag;

} // метод получения значения для автоматического запуска создания лаб

const bool Load_Close_Application (void) const {

    std::string Str = "\0";
    bool Found = false;
    bool Flag = false;

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == SaveTag_Close_Application) {

                    Read >> Str;
                    Read >> Flag;
                    Found = true;

                }

            }

        }

        else
            Exception ("File Settings didnt open");

        if (Found == false)
            Exception ("Not found Automatic_Close_Application in settings file");

    return Flag;

} // метод получения значения для автоматического закрытия приложения*/

const void Class_Settings::SaveSettings (const bool UsingDelay) const {

    ConfigFile_Open ();

    std::ofstream Write (Config_Path.c_str ());

    Write   << SaveTag_Path_to_Labs << " = " << getLabs_Path () << "\n"
            << SaveTag_Order_Start << " = " << getAutomatic_Order_Start () << "\n"
            << SaveTag_Close_Application << " = " << getAutomatic_Close_Application () << "\n";

    Write.close ();

    ConfigFile_Close ();

        if (UsingDelay == true) {

            printf ("\n\n\nСохранение изменений");

                for (unsigned short int i = 0; i < 3; i++) {

                    printf (".");
                    Delay (1000);

                }

        }

} // метод сохранения настроек

#endif // _settings_class_h_
