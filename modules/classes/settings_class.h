// Класс настроек приложения

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

#include "../libs/additional_functions.h"

class AbstractClass_ConfigEditor {

    protected:

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

        std::string ProjectBuild_Name_Release; // release билд - использование исходный файловых настроек
        std::string ProjectBuild_Name_Debug; // debug билд - использование дефолтных дебаг настроек

        std::string ProjectBuild_Type; // тип сборки проекта (debug / release)
        std::string ProjectBuild_Version; // версия проекта

        std::string ProjectBuild_SavePath_DB_Release; // release путь сохранения заказов - основная папка для release билда
        std::string ProjectBuild_SavePath_DB_Debug; // debug путь сохранения заказов - отдельная папка для debug билда

        std::string ReleaseExeFile_Path; // путь к хранению release exe приложения
        std::string DebugExeFile_Path; // путь к локальному хранилищу debug exe приложения

        std::string PK_Name; // имя профиля на пк исполнителя
        std::string Disk_Path; // наименование логического жесткого диска на пк, где хранятся заказы
        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб
        bool Automatic_Order_Start; // автоматический запуск создания заказа
        bool Automatic_Close_Application; // автоматическое завершение приложения после заполнения заказа
        bool Automatic_Open_Order; // автоматическое открытие заказа(ов) при создании
        bool Automatic_Update_BanList; // автоматическое обновление списка бан-листа
        bool Display_Money; // отображение заработанных средств (true - да / false - нет)
        std::string Banlist_Path; // путь к хранению бан-листа
        std::string Url_BanList_Clients; // ссылка на банлист клиентов
        std::string Url_BanList_Workers; // ссылка на банлист исполнителей
        std::string Default_IDE_Path; // путь для запуска IDE по умолчанию

        std::string LastTime_ProjectBuild_Type_Release; // время последней сборки проекта в режиме [Release]
        std::string LastTime_ProjectBuild_Type_Debug; // время последней сборки проекта в режиме [Debug]
        std::string NewTime_ProjectBuild_Type_Release; // время новой сборки проекта в режиме [Release]
        std::string NewTime_ProjectBuild_Type_Debug; // время новой сборки проекта врежиме [Debug]

        std::string LoadTag_Path_to_Labs; // Тэг-считывания пути сохранения заказов
        std::string LoadTag_Path_to_Default_IDE; // Тэг-считывания пути для запуска IDE по умолчанию
        std::string LoadTag_Order_Start; // Тэг-считывания автоматического запуска создания заказа
        std::string LoadTag_Close_Application; // Тэг-считывания автоматического завершения работы приложения
        std::string LoadTag_Open_Order; // Тэг-считывания автоматического открытия созданного заказа
        std::string LoadTag_Update_BanList; // Тэг-считывания автоматического обновления бан-листа
        std::string LoadTag_Display_Money; // Тэг-считывания отображения заработанных средств
        std::string LoadTag_Url_BanList_Clients; // Тэг-считывания ссылки на бан-лист клиентов
        std::string LoadTag_Url_BanList_Workers; // Тэг-считывания ссылки на бан-лист исполнителей
        std::string LoadTag_LastTime_ProjectBuild_Type_Debug; // Тэг-считывания времени последней сборки проекта в режиме [Debug]
        std::string LoadTag_LastTime_ProjectBuild_Type_Release; // Тэг-ситывания времени последней сборки проекта в режиме [Release]

        std::string ERROR_Message_ClientExist; // сообщение об ошибки отсуствия введенного клиента в базе
		std::string ERROR_Message_BuildTimeExist; // сообщение об ошибки отсутствия собранных билдов проекта

        std::string SaveTag_Field_Technology; // Тэг-сохранения наименования технологии
	    std::string SaveTag_Field_IDE; // Тэг-сохранения наименования среды разработки
	    std::string SaveTag_Field_OS; // Тэг-сохранения наименования операционной системы
	    std::string SaveTag_Field_TypeWork; // Тэг-сохранения наименования типа выполненной работы
	    std::string SaveTag_Field_OrderCost; // Тэг-сохранения стоимости выполненной работы
	    std::string SaveTag_Field_Date; // Тэг-схранения даты создания заказа
	    std::string SaveTag_Field_Keywords; // Тэг-сохранения ключевых слов

	    std::string Technology_Name_C; // наименование технологии [Си]
        std::string Technology_Name_CPlusPlus; // наименование технологии [C++]
        std::string Technology_Name_Another; // наименование технологии Another

        std::string IDE_Name_VisualStudio; // наименование среды разработки [VisualStudio]
        std::string IDE_Name_Geany; // наименование среды разработки [Geany]
        std::string IDE_Name_CodeBlocks; // наименование среды разработки [CodeBlocks]
        std::string IDE_Name_QtCreator; // наименование среды разработки [QtCreator]
        std::string IDE_Name_NoneIDE; // наименование среды разработки [NoneIDE]

        std::string OS_Name_Linux; // наименование операционный системы [Linux]
        std::string OS_Name_Windows; // наименование операционной системы [Windows]

        std::string TypeWork_Name_LabWork; // наименование типа работы [LabWork]
        std::string TypeWork_Name_CourseWork; // наименование типа работы [CourseWork]
        std::string TypeWork_Name_Diploma; // наименование типа работы [Diploma]

    public:

        Class_Settings (void) {

            this->ProjectBuild_Version = "2";
            this->ProjectBuild_Name_Release = "Release";
            this->ProjectBuild_Name_Debug = "Debug";

            this->ProjectBuild_SavePath_DB_Release = "D:\\Orders\\C++Tasks";
            this->ProjectBuild_SavePath_DB_Debug = "D:\\Orders\\C++Tasks(Debug)";

            this->ReleaseExeFile_Path = "D:\\Projects\\CPlusPlus_Projects\\Automation\\AutoTaskCreator\\bin\\Release\\AutoTaskCreator.exe";
            this->DebugExeFile_Path = "D:\\Projects\\CPlusPlus_Projects\\Automation\\AutoTaskCreator\\bin\\Debug\\AutoTaskCreator.exe";

            this->LoadTag_Path_to_Labs = "Path_to_Labs";
            this->LoadTag_Path_to_Default_IDE = "Path_to_Default_IDE";
            this->LoadTag_Order_Start = "Order_Start";
            this->LoadTag_Close_Application = "Close_Application";
            this->LoadTag_Open_Order = "Open_Order";
            this->LoadTag_Update_BanList = "Update_BanList";
            this->LoadTag_Display_Money = "Display_Money";
            this->LoadTag_Url_BanList_Clients = "Url_BanList_Clients";
            this->LoadTag_Url_BanList_Workers = "Url_BanList_Workers";
            this->LoadTag_LastTime_ProjectBuild_Type_Release = "LastTime_Release_Build";
            this->LoadTag_LastTime_ProjectBuild_Type_Debug = "LastTime_Debug_Build";

            this->ERROR_Message_ClientExist = "NoneClient";
			this->ERROR_Message_BuildTimeExist = "NoneTime";

            this->PK_Name = Load_PK_UserName ();
            this->ProjectBuild_Type = "\0";
            this->LastTime_ProjectBuild_Type_Release = "\0";
            this->LastTime_ProjectBuild_Type_Debug = "\0";
            this->NewTime_ProjectBuild_Type_Release = "\0";
            this->NewTime_ProjectBuild_Type_Debug = "\0";

            const std::string BuildDate = SetupBuild_TypeVersion ();
            this->ProjectBuild_Version = ProjectBuild_Version + "." + BuildDate[0] + BuildDate[1] + "." + BuildDate[3] + BuildDate[4] +
                                                    "." + BuildDate[6] + BuildDate[7] + BuildDate[8] + BuildDate[9];

                if (this->ProjectBuild_Type == this->ProjectBuild_Name_Release) {

                    this->Config_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";
                    this->Banlist_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\AutoTaskCreator_Banlists.cfg";

                }

                else {

                    this->Config_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\(Debug)_AutoTaskCreator_Settings.cfg";
                    this->Banlist_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\(Debug)_AutoTaskCreator_Banlists.cfg";

                }

            Check_ConfigFile (false);

            this->Automatic_Order_Start = false;
            this->Automatic_Close_Application = false;
            this->Automatic_Open_Order = false;
            this->Automatic_Update_BanList = false;
            this->Display_Money = false;
            this->Url_BanList_Clients = "\0";
            this->Url_BanList_Workers = "\0";
            this->Default_IDE_Path = "\0";

            Load_Parameters ();

            this->Disk_Path = this->Disk_Path + this->Labs_Path[0] + this->Labs_Path[1];

            this->SaveTag_Field_Technology = "Technology";
			this->SaveTag_Field_IDE = "IDE";
			this->SaveTag_Field_OS = "OS";
			this->SaveTag_Field_TypeWork = "TypeWork";
			this->SaveTag_Field_OrderCost = "OrderCost";
			this->SaveTag_Field_Date = "Date";
			this->SaveTag_Field_Keywords = "Keywords";

			this->Technology_Name_C = "C";
            this->Technology_Name_CPlusPlus = "C++" ;
            this->Technology_Name_Another = "Another";

            this->IDE_Name_Geany = "Geany";
            this->IDE_Name_CodeBlocks = "Code::Blocks";
            this->IDE_Name_VisualStudio = "VisualStudio";
            this->IDE_Name_QtCreator = "QtCreator";
            this->IDE_Name_NoneIDE = "NoneIDE";

            this->OS_Name_Linux = "Linux";
            this->OS_Name_Windows = "Windows";

            this->TypeWork_Name_LabWork = "LabWork";
            this->TypeWork_Name_CourseWork = "CourseWork";
            this->TypeWork_Name_Diploma = "Diploma";

            SaveSettings (false); // форсируем сохранение новых дат запуска [Debug] и [Release] билдов

        }

        ~Class_Settings (void) {}

    //////////////////////////////////////////////

        const std::string getProjectBuild_Type (void) const {

            return this->ProjectBuild_Type;

        } // геттер для ProjectBuild_Type

        const std::string getProjectBuild_Version (void) const {

            return this->ProjectBuild_Version;

        } // геттер для ProjectBuild_Version

        const std::string getProjectBuild_Name_Release (void) const {

            return this->ProjectBuild_Name_Release;

        } // геттер для ProjectBuild_Name_Release

        const std::string getProjectBuild_Name_Debug(void) const {

            return this->ProjectBuild_Name_Debug;

        } // геттер для ProjectBuild_Name_Debug

    //////////////////////////////////////////////

        const void setPK_Name (const std::string Str) {

			this->PK_Name = Str;

		} // сеттер для PK_Name

		const std::string getPK_Name (void) const {

			return this->PK_Name;

		} // геттер для PK_Name

        const void setLabs_Path (const std::string Str) {

            this->Labs_Path = Str;

        } // сеттер для Labs_Path

        const std::string getLabs_Path (void) const {

            return this->Labs_Path;

        } // геттер для Labs_Path

        const void setConfig_Path (const std::string Str) {

            this->Config_Path = Str;

        } // сеттер для Config_Path

        const std::string getConfig_Path (void) const {

            return this->Config_Path;

        } // геттер для Config_Path

        const void setDefault_IDE_Path (const std::string Str) {

            this->Default_IDE_Path = Str;

        } // сеттер для Default_IDE_Path

        const std::string getDefault_IDE_Path (void) const {

            return this->Default_IDE_Path;

        } // геттер для Default_IDE_Path

        const void setAutomatic_Order_Start (const bool Flag) {

            this->Automatic_Order_Start = Flag;

        } // сеттер для Automatic_Order_Start

        const bool getAutomatic_Order_Start (void) const {

            return this->Automatic_Order_Start;

        } // геттер для Automatic_Order_Start

        const void setAutomatic_Close_Application (const bool Flag) {

            this->Automatic_Close_Application = Flag;

        } // сеттер для Automatic_Close_Application

        const bool getAutomatic_Close_Application (void) const {

            return this->Automatic_Close_Application;

        } // геттер для Automatic_Close_Applcation

        const void setAutomatic_Open_Order (const bool Flag) {

            this->Automatic_Open_Order = Flag;

        } // сеттер для Automatic_Open_Order

        const bool getAutomatic_Open_Order (void) const {

            return this->Automatic_Open_Order;

        } // геттер для Automatic_Open_Order

        const void setAutomatic_Update_BanList (const bool Flag) {

            this->Automatic_Update_BanList = Flag;

        } // сеттер для Automatic_Update_BanList

        const bool getAutomatic_Update_BanList (void) const {

            return this->Automatic_Update_BanList;

        } // геттер для Automatic_Update_BanList

        const void setDisplay_Money (const bool Flag) {

            this->Display_Money = Flag;

        } // сеттер для Display_Money

        const bool getDisplay_Money (void) const {

            return this->Display_Money;

        } // геттер для Display_Money

        const void setUrl_BanList_Clients (const std::string Str) {

            this->Url_BanList_Clients = Str;

        } // сеттер для Url_BanList_Clients

        const std::string getUrl_BanList_Clients (void) const {

            return this->Url_BanList_Clients;

        } // геттер для Url_BanList_Clients

        const void setUrl_BanList_Workers (const std::string Str) {

            this->Url_BanList_Workers = Str;

        } // сеттер для Url_BanList_Workers

        const std::string getUrl_BanList_Workers (void) const {

            return this->Url_BanList_Workers;

        } // геттер для Url_BanList_Workers

        const std::string getLastTime_ProjectBuild_Type_Release (void) const {

            return this->LastTime_ProjectBuild_Type_Release;

        } // геттер для LastTime_ProjectBuild_Type_Release

        const std::string getLastTime_ProjectBuild_Type_Debug (void) const {

            return this->LastTime_ProjectBuild_Type_Debug;

        } // геттер для LastTime_ProjectBuild_Type_Debug

        const std::string getNewTime_ProjectBuild_Type_Release (void) const {

            return this->NewTime_ProjectBuild_Type_Release;

        } // геттер для NewTime_ProjectBuild_Type_Release

        const std::string getNewTime_ProjectBuild_Type_Debug (void) const {

            return this->NewTime_ProjectBuild_Type_Debug;

        } // геттер для NewTime_ProjectBuild_Type_Debug

    //////////////////////////////////////////////

        const void setDisk_Path (const std::string Str) {

            this->Disk_Path = Str;

        } // сеттер для Disk_Path

        const std::string getDisk_Path (void) const {

            return this->Disk_Path;

        } // геттер для Disk_Path

        const void setBanlist_Path (const std::string Str) {

            this->Banlist_Path = Str;

        } // сеттер для Banlist_Path

        const std::string getBanlist_Path (void) const {

            return this->Banlist_Path;

        } // геттер для Banlist_Path

    //////////////////////////////////////////////

        const std::string getSaveTag_Field_Technology (void) const {

            return this->SaveTag_Field_Technology;

        } // геттер для SaveTag_Field_Technology

        const std::string getSaveTag_Field_IDE (void) const {

            return this->SaveTag_Field_IDE;

        } // геттер для SaveTag_Field_IDE

        const std::string getSaveTag_Field_OS (void) const {

            return this->SaveTag_Field_OS;

        } // геттер для SaveTag_Field_OS

        const std::string getSaveTag_Field_OrderCost (void) const {

            return this->SaveTag_Field_OrderCost;

        } // геттер для SaveTag_Field_OrderCost

        const std::string getSaveTag_Field_Date (void) const {

            return this->SaveTag_Field_Date;

        } // геттер для SaveTag_Field_Date

        const std::string getSaveTag_Field_Keywords (void) const {

            return this->SaveTag_Field_Keywords;

        } // геттер для SaveTag_Field_Keywords

    //////////////////////////////////////////////

        const std::string getSaveTag_Field_TypeWork (void) const {

            return this->SaveTag_Field_TypeWork;

        } // геттер для SaveTag_Field_TypeWork

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

    //////////////////////////////////////////////

        const std::string getIDE_Name_Geany (void) const {

            return this->IDE_Name_Geany;

        } // геттер для IDE_Name_Geany

        const std::string getIDE_Name_CodeBlocks (void) const {

            return this->IDE_Name_CodeBlocks;

        } // геттер для IDE_Name_CodeBlocks

        const std::string getIDE_Name_VisualStudio (void) const {

            return this->IDE_Name_VisualStudio;

        } // геттер для IDE_Name_VisualStudio

        const std::string getIDE_Name_QtCreator (void) const {

            return this->IDE_Name_QtCreator;

        } // геттер для IDE_Name_QtCreator

        const std::string getIDE_Name_NoneIDE (void) const {

            return this->IDE_Name_NoneIDE;

        } // геттер для IDE_Name_NoneIDE

    //////////////////////////////////////////////

        const std::string getOS_Name_Windows (void) const {

            return this->OS_Name_Windows;

        } // геттер для OS_Name_Windows

        const std::string getOS_Name_Linux (void) const {

            return this->OS_Name_Linux;

        } // геттер для OS_Name_Linux

    //////////////////////////////////////////////

        const std::string getTypeWork_Name_LabWork (void) const {

            return this->TypeWork_Name_LabWork;

        } // геттер для TypeWork_Name_LabWork

         const std::string getTypeWork_Name_CourseWork (void) const {

            return this->TypeWork_Name_CourseWork;

        } // геттер для TypeWork_Name_CourseWork

        const std::string getTypeWork_Name_Diploma (void) const {

            return this->TypeWork_Name_Diploma;

        } // геттер для TypeWork_Name_Diploma

    //////////////////////////////////////////////

        const std::string getERROR_Message_ClientExist (void) const {

            return this->ERROR_Message_ClientExist;

        } // геттер для ERROR_Message_ClientExist

        const std::string getERROR_Message_BuildTimeExist (void) const {

            return this->ERROR_Message_BuildTimeExist;

        } // геттер для ERROR_Message_BuildTimeExist

    //////////////////////////////////////////////

        const void SetDefaultParameters_FormationOrder (void) {

                if (this->ProjectBuild_Type == this->ProjectBuild_Name_Debug)
                    this->Labs_Path = this->ProjectBuild_SavePath_DB_Debug;

                else
                    this->Labs_Path = this->ProjectBuild_SavePath_DB_Release;

            this->Automatic_Order_Start = false;
            this->Automatic_Close_Application = false;
            this->Automatic_Open_Order = true;
            this->Default_IDE_Path = "NoneIDE";

        } // метод установки настроек по умолчанию для модуля формирования заказов

        const void SetDefaultParameters_Banlists (void) {

            this->Automatic_Update_BanList = true;
            this->Url_BanList_Clients = "https://vk.com/topic-156779709_36343200";
            this->Url_BanList_Workers = "https://vk.com/topic-156779709_39456558";

        } // метод установки настроек по умолчанию для модуля блокировки клиентов

        const void SetDefaultParameters_BuildTypeTime (void) {

            this->LastTime_ProjectBuild_Type_Release = CheckBuild_getTime (ReleaseExeFile_Path);
            this->LastTime_ProjectBuild_Type_Debug = CheckBuild_getTime (DebugExeFile_Path);

        } // метод установки настроек по умолчанию для данных по времени последних билдов

        const void SetDefaultParameters_Statistics (void) {

            this->Display_Money = false;

        } // метод установки настроек по умолчанию для модуля статистики

         const void SetDefault_Parameters (void) {

            SetDefaultParameters_FormationOrder ();
            SetDefaultParameters_Banlists ();
            SetDefaultParameters_BuildTypeTime ();
            SetDefaultParameters_Statistics ();

        } // метод установки настроек по умолчанию

        const std::string Load_PK_UserName (void) const;
        const void Check_ConfigFile (bool);
        const void Load_Parameters (void);
        const void SaveSettings (const bool) const;
        const bool Check_FilePath (const std::string&);
        const bool Check_ExePath (const std::string&);
        const std::string CheckBuild_getTime (const std::string&);
        const std::string SetupBuild_TypeVersion (void);

}; // класс настроек приложения

const std::string Class_Settings::Load_PK_UserName (void) const {

    const std::string PathPK_UserName = "C:\\Windows\\Temp\\PK_UserName.txt";
    const std::string Command = "@echo %UserName% > " + PathPK_UserName;
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

const void Class_Settings::Check_ConfigFile (const bool ForceRewriteFile) {

    ConfigFile_Open (this->Config_Path);

        if (ForceRewriteFile == true)
            remove (Config_Path.c_str ());

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
    bool DefaultIDEPath_Founded = false;
    bool OrderStart_Founded = false;
    bool CloseApp_Founded = false;
    bool Open_Order_Founded = false;
    bool UpdateBanList_Founded = false;
    bool DisplayMoney_Founded = false;
    bool Url_BanList_Clients_Founded = false;
    bool Url_BanList_Workers_Founded = false;
    bool LastTime_ProjectBuild_Type_Release_Founded = false;
    bool LastTime_ProjectBuild_Type_Debug_Founded = false;

    std::ifstream Read (this->Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == this->LoadTag_Path_to_Labs && LabsPath_Founded == false) {

                    Read >> Str;
                    Read >> this->Labs_Path;
                    LabsPath_Founded = true;

                }

                if (Str == this->LoadTag_Path_to_Default_IDE && DefaultIDEPath_Founded == false) {

                    Read >> Str;
                    Read >> this->Default_IDE_Path;
                    DefaultIDEPath_Founded = true;

                }
                if (Str == this->LoadTag_Order_Start && OrderStart_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Order_Start;
                    OrderStart_Founded = true;

                }

                if (Str == this->LoadTag_Close_Application && CloseApp_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Close_Application;
                    CloseApp_Founded = true;

                }

                if (Str == this->LoadTag_Open_Order && Open_Order_Founded == false) {

                    Read >> Str;
                    Read >> this->Automatic_Open_Order;
                    Open_Order_Founded = true;

                }

                if (Str == this->LoadTag_Update_BanList && UpdateBanList_Founded == false)  {

                    Read >> Str;
                    Read >> this->Automatic_Update_BanList;
                    UpdateBanList_Founded = true;

                }

                if (Str == this->LoadTag_Display_Money && DisplayMoney_Founded == false) {

                    Read >> Str;
                    Read >> this->Display_Money;
                    DisplayMoney_Founded = true;

                }

                if (Str == this->LoadTag_Url_BanList_Clients && Url_BanList_Clients_Founded == false) {

                    Read >> Str;
                    Read >> this->Url_BanList_Clients;
                    Url_BanList_Clients_Founded = true;

                }

                if (Str == this->LoadTag_Url_BanList_Workers && Url_BanList_Workers_Founded == false) {

                    Read >> Str;
                    Read >> this->Url_BanList_Workers;
                    Url_BanList_Workers_Founded = true;

                }

                if (Str == this->LoadTag_LastTime_ProjectBuild_Type_Release && LastTime_ProjectBuild_Type_Release_Founded == false) {

                    Read >> Str;
                    Read >> this->LastTime_ProjectBuild_Type_Release;
                    LastTime_ProjectBuild_Type_Release_Founded = true;

                }

                if (Str == this->LoadTag_LastTime_ProjectBuild_Type_Debug && LastTime_ProjectBuild_Type_Debug_Founded == false) {

                    Read >> Str;
                    Read >> this->LastTime_ProjectBuild_Type_Debug;
                    LastTime_ProjectBuild_Type_Debug_Founded = true;

                }

            }

        }

        else if (ProjectBuild_Type == ProjectBuild_Name_Debug)
            Exception ("File Settings didnt open");

    Read.close ();

        if (ProjectBuild_Type == ProjectBuild_Name_Debug) {

            if (LabsPath_Founded == false)
                Exception ("Not found Path_to_Labs in settings file");

            if (DefaultIDEPath_Founded == false)
                Exception ("Not found Default_IDE_Path in settings file");

            if (OrderStart_Founded == false)
                Exception ("Not found Automatic_Order_Start in settings file");

            if (CloseApp_Founded == false)
                Exception ("Not found Automatic_Close_Application in settings file");

            if (Open_Order_Founded == false)
                Exception ("Not found Automatic_Open_Order in settings file");

            if (UpdateBanList_Founded == false)
                Exception ("Not found Automatic_Update_BanList in settings file");

            if (DisplayMoney_Founded == false)
                Exception ("Not found Display_Money in settings file");

            if (Url_BanList_Clients_Founded == false)
                Exception ("Not found Url_BanList_Clients in settings file");

            if (Url_BanList_Workers_Founded == false)
                Exception ("Not found Url_BanList_Workers in settings file");

            if (LastTime_ProjectBuild_Type_Release_Founded == false)
                Exception ("Not found LastTime_ProjectBuild_Type_Release in settings file");

            if (LastTime_ProjectBuild_Type_Debug_Founded == false)
                Exception ("Not found LastTime_ProjectBuild_Type_Debug in settings file");

        }

    ConfigFile_Close (this->Config_Path);

        if (LabsPath_Founded != true || DefaultIDEPath_Founded != true || OrderStart_Founded != true ||
            CloseApp_Founded != true || Open_Order_Founded != true || UpdateBanList_Founded != true ||
            DisplayMoney_Founded != true || Url_BanList_Clients_Founded != true || Url_BanList_Workers_Founded != true ||
            LastTime_ProjectBuild_Type_Release_Founded != true || LastTime_ProjectBuild_Type_Debug_Founded != true) {

                Check_ConfigFile (true);

            }

} // метод загрузки параметров приложения

const void Class_Settings::SaveSettings (const bool UsingDelay) const {

    ConfigFile_Open (this->Config_Path);

    std::ofstream Write (this->Config_Path.c_str ());

    Write   << this->LoadTag_Path_to_Labs << " = " << getLabs_Path () << "\n"
            << this->LoadTag_Path_to_Default_IDE << " = " << getDefault_IDE_Path () << "\n"
            << this->LoadTag_Order_Start << " = " << getAutomatic_Order_Start () << "\n"
            << this->LoadTag_Close_Application << " = " << getAutomatic_Close_Application () << "\n"
            << this->LoadTag_Open_Order << " = " << getAutomatic_Open_Order () << "\n"
            << this->LoadTag_Update_BanList << " = " << getAutomatic_Update_BanList () << "\n"
            << this->LoadTag_Display_Money << " = " << getDisplay_Money () << "\n"
            << this->LoadTag_Url_BanList_Clients << " = " << getUrl_BanList_Clients () << "\n"
            << this->LoadTag_Url_BanList_Workers << " = " << getUrl_BanList_Workers () << "\n"
            << this->LoadTag_LastTime_ProjectBuild_Type_Release << " = " << getNewTime_ProjectBuild_Type_Release () << "\n"
            << this->LoadTag_LastTime_ProjectBuild_Type_Debug << " = " << getNewTime_ProjectBuild_Type_Debug ();

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

    const std::string TestFilePath = Path + "\\ValidTest.txt";
    bool Result = true;
    std::ofstream Write (TestFilePath.c_str ());

        if (!Write.is_open())
            Result = false;

    Write.close ();

    remove (TestFilePath.c_str ());

        if (Result == false) {

            Exception ("New path is invalid, check this folder and repeat");
            return false;

        }

    return true;

} // метод проверки корректности пути к базе заказов

const bool Class_Settings::Check_ExePath (const std::string& Path) {

    const std::string Command = "IF EXIST " + Path + " (echo GOOD >> log.txt) ELSE (echo BAD >> log.txt)";
    system (Command.c_str());
    std::string Result = "BAD";

    std::ifstream Read ("log.txt");
    Read >> Result;
    Read.close ();
    remove ("log.txt");

        if (Result == "BAD") {

            Exception ("New .exe path is invalid, check this full path and repeat");
            return false;

        }

    return true;

} // метод проверки корректности к запуску IDE по умолчанию

const std::string Class_Settings::CheckBuild_getTime (const std::string& ExeFile_Path) {

    std::string Time = "\0";
    WIN32_FILE_ATTRIBUTE_DATA ad;

     //01/02/2022|23:43:13

        if (GetFileAttributesEx(ExeFile_Path.c_str(), GetFileExInfoStandard, &ad) == TRUE) {

            const int SizeDate = 19;
            char strDate[SizeDate];

            FILETIME ftWrite;
            SYSTEMTIME stUTC, stLocal;

            ftWrite = ad.ftLastWriteTime;
            FileTimeToSystemTime(&ftWrite, &stUTC);
            SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

        // преобразовать полученное время в строку

            sprintf(strDate, "%02hu/%02hu/%02hu|%02hu:%02hu:%02hu",
            stLocal.wDay, stLocal.wMonth, stLocal.wYear,
            stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

                for (unsigned short int i = 0; i < SizeDate; i++)
                    Time += strDate[i];

        }

        else
            Time = getERROR_Message_BuildTimeExist ();

    return Time;

} // метод считывания времени последнего изменения файла

class Class_DateTime {

    private:

        int Seconds; // кол-во секунд
        int Minutes; // кол-во минут
        int Hours; // кол-во часов

        int Days; // кол-во дней
        int Months; // кол-во недель
        int Years; // кол-во лет

    public:

        Class_DateTime (void) {

            Seconds = 0;
            Minutes = 0;
            Hours = 0;

            Days = 0;
            Months = 0;
            Years = 0;

        }

        Class_DateTime (const std::string StrData) {

            //01/02/2022|23:43:13
            Days = Convert_String_toInt ((std::string) &StrData[0] + &StrData[1]);
            Months = Convert_String_toInt ((std::string) &StrData[3] + &StrData[4]);
            Years = Convert_String_toInt ((std::string) &StrData[6] + &StrData[7] + &StrData[8] + StrData[9]);

            Hours = Convert_String_toInt ((std::string) &StrData[11] + &StrData[12]);
            Minutes = Convert_String_toInt ((std::string) &StrData[14] + &StrData[15]);
            Seconds = Convert_String_toInt ((std::string) &StrData[17]);

        }

        ~Class_DateTime (void) {}

        const int Converting_Time_toSeconds (void) const {

            return (Hours*60*60) + Minutes*60 + Seconds;

        } // метод перевода времени в секунды

        const int Converting_Date_toDays (void) const {

            return (Years * 10000) + Months * 100 + Days;

        } // метод перевода даты в дни

        bool Compare_DateTimes (Class_DateTime& Object) {

                /*Debug ("Old: " + Convert_Int_toString(Converting_Date_toDays ()) + "|" + Convert_Int_toString(Converting_Time_toSeconds ()), false);
                Debug ("vs", false);
                Debug ("New: " + Convert_Int_toString(Object.Converting_Date_toDays ()) + "|" + Convert_Int_toString(Object.Converting_Time_toSeconds ()), false);*/

                if (Converting_Date_toDays () > Object.Converting_Date_toDays ())
                    return false;

                else if (Converting_Date_toDays () == Object.Converting_Date_toDays ()) {

                    if (Converting_Time_toSeconds () > Object.Converting_Time_toSeconds ())
                        return false;

                }

            return true;

        } // метод сравнения даты + время

}; // класс обработки времени и даты

const std::string Class_Settings::SetupBuild_TypeVersion (void){

    this->NewTime_ProjectBuild_Type_Release = CheckBuild_getTime (this->ReleaseExeFile_Path); // в этом свойстве хранится полученное время файла Release exe (преобразованное из char [])
    this->NewTime_ProjectBuild_Type_Debug = CheckBuild_getTime (this->DebugExeFile_Path); // в этой свойстве хранится полученное время файла Debug exe (преобразованное из char [])

    /*printf("\nNew release: %s", NewTime_ProjectBuild_Type_Release.c_str());
    printf("\nNew debug: %s", NewTime_ProjectBuild_Type_Debug.c_str());

    printf("\nOld release: %s", this->LastTime_ProjectBuild_Type_Release.c_str());
    printf("\nOld debug: %s", this->LastTime_ProjectBuild_Type_Debug.c_str()); */


        if (this->NewTime_ProjectBuild_Type_Release != getERROR_Message_BuildTimeExist ()) {

            Class_DateTime NewTime_Build (this->LastTime_ProjectBuild_Type_Release);
            Class_DateTime LastTime_Build (this->LastTime_ProjectBuild_Type_Debug);

                if (NewTime_Build.Compare_DateTimes(LastTime_Build) == true) {

                    this->ProjectBuild_Type = getProjectBuild_Name_Release ();
                    return this->NewTime_ProjectBuild_Type_Release;

                }

        }

    this->ProjectBuild_Type = getProjectBuild_Name_Debug ();
    return this->NewTime_ProjectBuild_Type_Debug;

} // метод, задающий тип сборки (билда) программы [Debug] / [Release]

#endif // _settings_class_h_


