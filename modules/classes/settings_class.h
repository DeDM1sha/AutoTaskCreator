// Класс настроек приложения

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

static std::string SaveTag_Path_to_Labs = "Path_to_Labs";
static std::string SaveTag_Order_Start = "Order_Start";
static std::string SaveTag_Close_Application = "Close_Application";
static std::string SaveTag_Open_Order = "Open_Order";
static std::string SaveTag_Update_BanList = "Update_BanList";
static std::string SaveTag_Url_BanList_Clients = "Url_BanList_Clients";
static std::string SaveTag_Url_BanList_Workers = "Url_BanList_Workers";

class AbstractClass_ConfigEditor {

    public:

        const void ConfigFile_Open (const std::string&) const;
        const void ConfigFile_Close (const std::string&) const;

}; // абстрактный класс-родитель для конфигурационных файлов

const void AbstractClass_ConfigEditor::ConfigFile_Open (const std::string& Config_Path) const {

    std::string attrib = "attrib -r -s -h -x " + Config_Path + " >nul";

    system (attrib.c_str());

} // метод открытия файла конфига

const void AbstractClass_ConfigEditor::ConfigFile_Close (const std::string& Config_Path) const {

    std::string attrib = "attrib +r +s +h +x " + Config_Path + " >nul";

    system (attrib.c_str());

} // метод сохранения файла конфига

class Class_Settings : public AbstractClass_ConfigEditor {

    private:

        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб
        bool Automatic_Order_Start; // автоматический запуск создания заказа
        bool Automatic_Close_Application; // автоматическое завершение приложения после заполнения заказа
        bool Automatic_Open_Order; // автоматическое открытие заказа(ов) при создании
        bool Automatic_Update_BanList; // автоматическое обновление списка бан-листа
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

        const void setAutomatic_Open_Order (const bool Flag) {

            this->Automatic_Open_Order = Flag;

        } // сеттер для Automatic_Open_Order

        const bool getAutomatic_Open_Order (void) const {

            return this->Automatic_Open_Order;

        } // геттер для Automatic_Open_Order

    //////////////////////////////////////////////

        const void setAutomatic_Update_BanList (const bool Flag) {

            this->Automatic_Update_BanList = Flag;

        } // сеттер для Automatic_Update_BanList

        const bool getAutomatic_Update_BanList (void) const {

            return this->Automatic_Update_BanList;

        } // геттер для Automatic_Update_BanList

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

            this->Labs_Path = "E:\\Orders\\C++Tasks";
            this->Automatic_Order_Start = false;
            this->Automatic_Close_Application = false;
            this->Automatic_Open_Order = true;
            this->Automatic_Update_BanList = true;
            this->Url_BanList_Clients = "https://vk.com/topic-156779709_36343200";
            this->Url_BanList_Workers = "https://vk.com/topic-156779709_39456558";

        } // метод установки настроек по умолчанию

        const void Check_ConfigFile (void);
        const void Load_Parameters (void);
        const void SaveSettings (const bool) const;
        const bool Check_FilePath (const std::string& Path);

};

const void Class_Settings::Check_ConfigFile (void) {

    ConfigFile_Open (Config_Path);

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

    ConfigFile_Close (Config_Path);

} // метод проверки существования файла с конфигом

const void Class_Settings::Load_Parameters (void) {

    ConfigFile_Open (Config_Path);

    std::string Str = "\0";
    bool LabsPath_Founded = false;
    bool OrderStart_Founded = false;
    bool CloseApp_Founded = false;
    bool Open_Order_Founded = false;
    bool UpdateBanList_Founded = false;
    bool Url_BanList_Clients_Founded = false;
    bool Url_BanList_Workers_Founded = false;

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

                if (Str == SaveTag_Open_Order && Open_Order_Founded == false) {

                    Read >> Str;
                    Read >> Automatic_Open_Order;
                    Open_Order_Founded = true;

                }

                if (Str == SaveTag_Update_BanList && UpdateBanList_Founded == false)  {

                    Read >> Str;
                    Read >> Automatic_Update_BanList;
                    UpdateBanList_Founded = true;

                }

                if (Str == SaveTag_Url_BanList_Clients && Url_BanList_Clients_Founded == false) {

                    Read >> Str;
                    Read >> Url_BanList_Clients;
                    Url_BanList_Clients_Founded = true;

                }

                if (Str == SaveTag_Url_BanList_Workers && Url_BanList_Workers_Founded == false) {

                    Read >> Str;
                    Read >> Url_BanList_Workers;
                    Url_BanList_Workers_Founded = true;

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

        if (Open_Order_Founded == false)
            Exception ("Not found Automatic_Open_Order in settings file");

        if (UpdateBanList_Founded == false)
            Exception ("Not found Automatic_Update_BanList in settings file");

        if (Url_BanList_Clients_Founded == false)
            Exception ("Not found Url_BanList_Clients in settings file");

        if (Url_BanList_Workers_Founded == false)
            Exception ("Not found Url_BanList_Workers in settings file");

        if (!( ( ((LabsPath_Founded == OrderStart_Founded) == (CloseApp_Founded == Open_Order_Founded)) == ( UpdateBanList_Founded == (Url_BanList_Clients_Founded == Url_BanList_Workers_Founded)) ) == true)) {

            remove (Config_Path.c_str ());
            Check_ConfigFile ();

        }

    ConfigFile_Close (Config_Path);

} // метод загрузки параметров приложения

const void Class_Settings::SaveSettings (const bool UsingDelay) const {

    ConfigFile_Open (Config_Path);

    std::ofstream Write (Config_Path.c_str ());

    Write   << SaveTag_Path_to_Labs << " = " << getLabs_Path () << "\n"
            << SaveTag_Order_Start << " = " << getAutomatic_Order_Start () << "\n"
            << SaveTag_Close_Application << " = " << getAutomatic_Close_Application () << "\n"
            << SaveTag_Open_Order << " = " << getAutomatic_Open_Order () << "\n"
            << SaveTag_Update_BanList << " = " << getAutomatic_Update_BanList () << "\n"
            << SaveTag_Url_BanList_Clients << " = " << getUrl_BanList_Clients () << "\n"
            << SaveTag_Url_BanList_Workers << " = " << getUrl_BanList_Workers ();

    Write.close ();

    ConfigFile_Close (Config_Path);

        if (UsingDelay == true) {

            printf ("\n\n\nСохранение изменений ");

                for (unsigned short int i = 0; i < 4; i++) {

                    Delay (1000);
                    printf (".");

                }

        }

} // метод сохранения настроек

const bool Class_Settings::Check_FilePath (const std::string& Path) {

    bool Result = true;
    std::string TestFilePath = Path + "\\ValidTest.txt";
    std::ofstream Write (TestFilePath.c_str ());

        if (!Write.is_open()) {

            CenterText ("Error! Not valid path\n");
            Result = false;

        }

    Write.close ();

        if (Result)
            remove (TestFilePath.c_str ());

    return Result;

} // метод проверки корректности пути к базе заказов

#endif // _settings_class_h_
