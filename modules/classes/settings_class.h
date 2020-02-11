// Класс настроек приложения

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

#include "../libs/additional_functions.h"

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

} // метод закрытия файла конфига

class Class_Settings : public AbstractClass_ConfigEditor {

    private:

        std::string PK_Name; // имя профиля на пк исполнителя
        std::string Disk_Path; // наименование логического жесткого диска на пк, где хранятся заказы
        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб
        bool Automatic_Order_Start; // автоматический запуск создания заказа
        bool Automatic_Close_Application; // автоматическое завершение приложения после заполнения заказа
        bool Automatic_Open_Order; // автоматическое открытие заказа(ов) при создании
        bool Automatic_Update_BanList; // автоматическое обновление списка бан-листа
        std::string Url_BanList_Clients; // ссылка на банлист клиентов
        std::string Url_BanList_Workers; // ссылка на банлист исполнителей

        std::string SaveTag_Path_to_Labs; // Тэг-сохранения пути сохранения заказов
        std::string SaveTag_Order_Start; // Тэг-сохранения автоматического запуска создания заказа
        std::string SaveTag_Close_Application; // Тэг-сохранения автоматического завершения работы приложения
        std::string SaveTag_Open_Order; // Тэг-сохранения автоматического открытия созданного заказа
        std::string SaveTag_Update_BanList; // Тэг-сохранения автоматического обновления бан-листа
        std::string SaveTag_Url_BanList_Clients; // Тэг-сохранения ссылки на бан-лист клиентов
        std::string SaveTag_Url_BanList_Workers; // Тэг-сохранения ссылки на бан-лист исполнителей

        std::string Technology_Name_C; // наименование технологии [Си]
        std::string Technology_Name_CPlusPlus; // наименование технологии [C++]
        std::string Technology_Name_Another; // наименование технологии Another
        std::string IDE_Name_VisualStudio; // наименование среды разработки [VisualStudio]
        std::string IDE_Name_Geany; // наименование среды разработки [Geany]
        std::string IDE_Name_CodeBlocks; // наименование среды разработки [CodeBlocks[
        std::string IDE_Name_NoneIDE; // наименование среды разработки [NoneIDE]
        std::string OS_Name_Linux; // наименование операционный системы [Linux]
        std::string OS_Name_Windows; // наименование операционной системы [Windows]

    public:

        Class_Settings (void) {

            this->SaveTag_Path_to_Labs = "Path_to_Labs";
            this->SaveTag_Order_Start = "Order_Start";
            this->SaveTag_Close_Application = "Close_Application";
            this->SaveTag_Open_Order = "Open_Order";
            this->SaveTag_Update_BanList = "Update_BanList";
            this->SaveTag_Url_BanList_Clients = "this->Url_BanList_Clients";
            this->SaveTag_Url_BanList_Workers = "this->Url_BanList_Workers";

            this->PK_Name = Load_PK_UserName ();
            this->Config_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";
            Check_ConfigFile ();
            Load_Parameters ();
            this->Disk_Path = this->Disk_Path + this->Labs_Path[0] + this->Labs_Path[1];

            this->Technology_Name_C = "C";
            this->Technology_Name_CPlusPlus = "C++" ;
            this->Technology_Name_Another = "Another";
            this->IDE_Name_Geany = "Geany";
            this->IDE_Name_CodeBlocks = "Code::Blocks";
            this->IDE_Name_VisualStudio = "VisualStudio";
            this->IDE_Name_NoneIDE = "NoneIDE";
            this->OS_Name_Linux = "Linux";
            this->OS_Name_Windows = "Windows";

        }

        ~Class_Settings (void) {}

    //////////////////////////////////////////////

        const void setPK_Name (const std::string Str) {

			this->PK_Name = Str;

		} // сеттер для PK_Name

		const std::string getPK_Name (void) const {

			return this->PK_Name;

		} // геттер для PK_Name

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

        const void setDisk_Path (const std::string Str) {

            this->Disk_Path = Str;

        } // сеттер для Disk_Path

        const std::string getDisk_Path (void) const {

            return this->Disk_Path;

        } // геттер для Disk_Path

    //////////////////////////////////////////////

        const std::string getTechnology_Name_C (void) const {

            return this->Technology_Name_C;

        } // геттер для Technology_Name_C

        const std::string getTechnology_Name_CPlusPlus (void) const {

            return this->Technology_Name_CPlusPlus;

        } // геттер для Technology_Name_CPlusPlus

        const std::string getTechnology_Name_Another (void) const {

            return this->Technology_Name_Another;

        } // геттер для Technology_Name_Another

        const std::string getIDE_Name_Geany (void) const {

            return this->IDE_Name_Geany;

        } // геттер для IDE_Name_Geany

        const std::string getIDE_Name_CodeBlocks (void) const {

            return this->IDE_Name_CodeBlocks;

        } // геттер для IDE_Name_CodeBlocks

        const std::string getIDE_Name_VisualStudio (void) const {

            return this->IDE_Name_VisualStudio;

        } // геттер для IDE_Name_VisualStudio

        const std::string getIDE_Name_NoneIDE (void) const {

            return this->IDE_Name_NoneIDE;

        } // геттер для IDE_Name_NoneIDE

        const std::string getOS_Name_Windows (void) const {

            return this->OS_Name_Windows;

        } // геттер для OS_Name_Windows

        const std::string getOS_Name_Linux (void) const {

            return this->OS_Name_Linux;

        } // геттер для OS_Name_Linux

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

        const std::string Load_PK_UserName (void) const;
        const void Check_ConfigFile (void);
        const void Load_Parameters (void);
        const void SaveSettings (const bool) const;
        const bool Check_FilePath (const std::string& Path);

}; // класс настроек приложения

const std::string Class_Settings::Load_PK_UserName (void) const {

    const std::string PathPK_UserName = "C:\\Windows\\Temp\\PK_UserName.txt";
    std::string Command = "@echo %UserName% > " + PathPK_UserName;
    std::string PK_User_Name = "\0";

    system (Command.c_str());

    std::ifstream Read (PathPK_UserName.c_str ());

        if (Read.is_open ())
            Read >> PK_User_Name;

        else
            Exception ("File PK_UserName.txt didnt open");

    Read.close ();

    remove (PathPK_UserName.c_str ());

    return PK_User_Name;

} // метод получения названия имени пользователя-пк

const void Class_Settings::Check_ConfigFile (void) {

    ConfigFile_Open (this->Config_Path);

    std::ifstream Read (this->Config_Path.c_str ());

        if (!Read.is_open ()) {

            SetDefault_Parameters ();
            SaveSettings (false);

            std::ifstream Check (this->Config_Path.c_str ());

                if (!Check.is_open ())
                    Exception ("Default settings didnt created");

            Check.close ();

        } // если файла нет, то создаем файл конфига с дефолтными настройками

    Read.close ();

    ConfigFile_Close (this->Config_Path);

} // метод проверки существования файла с конфигом

const void Class_Settings::Load_Parameters (void) {

    ConfigFile_Open (this->Config_Path);

    std::string Str = "\0";
    bool LabsPath_Founded = false;
    bool OrderStart_Founded = false;
    bool CloseApp_Founded = false;
    bool Open_Order_Founded = false;
    bool UpdateBanList_Founded = false;
    bool Url_BanList_Clients_Founded = false;
    bool Url_BanList_Workers_Founded = false;

    std::ifstream Read (this->Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == this->SaveTag_Path_to_Labs && LabsPath_Founded == false) {

                    Read >> Str;
                    Read >> this->Labs_Path;
                    LabsPath_Founded = true;

                }

                if (Str == this->SaveTag_Order_Start && OrderStart_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Order_Start;
                    OrderStart_Founded = true;

                }

                if (Str == this->SaveTag_Close_Application && CloseApp_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Close_Application;
                    CloseApp_Founded = true;

                }

                if (Str == this->SaveTag_Open_Order && Open_Order_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Open_Order;
                    Open_Order_Founded = true;

                }

                if (Str == this->SaveTag_Update_BanList && UpdateBanList_Founded == false)  {

                    Read >> Str;
                    Read >> this->Automatic_Update_BanList;
                    UpdateBanList_Founded = true;

                }

                if (Str == this->SaveTag_Url_BanList_Clients && Url_BanList_Clients_Founded == false) {

                    Read >> Str;
                    Read >> this->Url_BanList_Clients;
                    Url_BanList_Clients_Founded = true;

                }

                if (Str == this->SaveTag_Url_BanList_Workers && Url_BanList_Workers_Founded == false) {

                    Read >> Str;
                    Read >> this->Url_BanList_Workers;
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
            Exception ("Not found this->Automatic_Order_Start in settings file");

        if (CloseApp_Founded == false)
            Exception ("Not found this->Automatic_Close_Application in settings file");

        if (Open_Order_Founded == false)
            Exception ("Not found this->Automatic_Open_Order in settings file");

        if (UpdateBanList_Founded == false)
            Exception ("Not found this->Automatic_Update_BanList in settings file");

        if (Url_BanList_Clients_Founded == false)
            Exception ("Not found this->Url_BanList_Clients in settings file");

        if (Url_BanList_Workers_Founded == false)
            Exception ("Not found this->Url_BanList_Workers in settings file");

        if (!( ( ((LabsPath_Founded == OrderStart_Founded) == (CloseApp_Founded == Open_Order_Founded)) == ( UpdateBanList_Founded == (Url_BanList_Clients_Founded == Url_BanList_Workers_Founded)) ) == true)) {

            remove (this->Config_Path.c_str ());
            Check_ConfigFile ();

        }

    ConfigFile_Close (this->Config_Path);

} // метод загрузки параметров приложения

const void Class_Settings::SaveSettings (const bool UsingDelay) const {

    ConfigFile_Open (this->Config_Path);

    std::ofstream Write (this->Config_Path.c_str ());

    Write   << SaveTag_Path_to_Labs << " = " << getLabs_Path () << "\n"
            << SaveTag_Order_Start << " = " << getAutomatic_Order_Start () << "\n"
            << SaveTag_Close_Application << " = " << getAutomatic_Close_Application () << "\n"
            << SaveTag_Open_Order << " = " << getAutomatic_Open_Order () << "\n"
            << SaveTag_Update_BanList << " = " << getAutomatic_Update_BanList () << "\n"
            << SaveTag_Url_BanList_Clients << " = " << getUrl_BanList_Clients () << "\n"
            << SaveTag_Url_BanList_Workers << " = " << getUrl_BanList_Workers ();

    Write.close ();

    ConfigFile_Close (this->Config_Path);

        if (UsingDelay == true) {

            printf ("\n\n\nСохранение изменений ");

                for (unsigned short int i = 0; i < 4; i++) {

                    Delay (1000);
                    printf (".");

                }

        }

} // метод сохранения настроек

const bool Class_Settings::Check_FilePath (const std::string& Path) {

    std::string TestFilePath = Path + "\\ValidTest.txt";
    std::ofstream Write (TestFilePath.c_str ());

        if (!Write.is_open()) {

            Exception ("New path is invalid, check this folder and repeat");
            return false;

        }

    Write.close ();

    remove (TestFilePath.c_str ());

    return true;

} // метод проверки корректности пути к базе заказов

#endif // _settings_class_h_
