// ����� �������� ����������

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

#include "../libs/additional_functions.h"

class AbstractClass_ConfigEditor {

    public:

        const void ConfigFile_Open (const std::string&) const;
        const void ConfigFile_Close (const std::string&) const;

}; // ����������� �����-�������� ��� ���������������� ������

const void AbstractClass_ConfigEditor::ConfigFile_Open (const std::string& Config_Path) const {

    std::string attrib = "attrib -r -s -h -x " + Config_Path + " >nul";

    system (attrib.c_str());

} // ����� �������� ����� �������

const void AbstractClass_ConfigEditor::ConfigFile_Close (const std::string& Config_Path) const {

    std::string attrib = "attrib +r +s +h +x " + Config_Path + " >nul";

    system (attrib.c_str());

} // ����� �������� ����� �������

class Class_Settings : public AbstractClass_ConfigEditor {

    private:

        std::string ProjectBuild_Type; // ��� ������ ������� (debug / release)
        std::string ProjectBuild_Version; // ������ �������
        std::string ProjectBuild_Name_Release; // realease ���� - ������������� �������� �������� ��������
        std::string ProjectBuild_Name_Debug; // debug ���� - ������������� ��������� ����� ��������

        std::string ProjectBuild_SavePath_DB_Release; // realese ���� ���������� ������� - �������� ����� ��� release �����
        std::string ProjectBUild_SavePath_DB_Debug; // debug ���� ���������� ������� - ��������� ����� ��� debug �����
        std::string PK_Name; // ��� ������� �� �� �����������
        std::string Disk_Path; // ������������ ����������� �������� ����� �� ��, ��� �������� ������
        std::string Config_Path; // ����� �������� ����� � �����������
        std::string Labs_Path; // ����� ���������� ���
        bool Automatic_Order_Start; // �������������� ������ �������� ������
        bool Automatic_Close_Application; // �������������� ���������� ���������� ����� ���������� ������
        bool Automatic_Open_Order; // �������������� �������� ������(��) ��� ��������
        bool Automatic_Update_BanList; // �������������� ���������� ������ ���-�����
        std::string Url_BanList_Clients; // ������ �� ������� ��������
        std::string Url_BanList_Workers; // ������ �� ������� ������������

        std::string SaveTag_Path_to_Labs; // ���-���������� ���� ���������� �������
        std::string SaveTag_Order_Start; // ���-���������� ��������������� ������� �������� ������
        std::string SaveTag_Close_Application; // ���-���������� ��������������� ���������� ������ ����������
        std::string SaveTag_Open_Order; // ���-���������� ��������������� �������� ���������� ������
        std::string SaveTag_Update_BanList; // ���-���������� ��������������� ���������� ���-�����
        std::string SaveTag_Url_BanList_Clients; // ���-���������� ������ �� ���-���� ��������
        std::string SaveTag_Url_BanList_Workers; // ���-���������� ������ �� ���-���� ������������

        std::string SaveTag_Field_Technology; // ���-���������� ������������ ����������
	    std::string SaveTag_Field_IDE; // ���-���������� ������������ ����� ����������
	    std::string SaveTag_Field_OS; // ���-���������� ������������ ������������ �������
	    std::string SaveTag_Field_TypeWork; // ���-���������� ������������ ���� ����������� ������
	    std::string SaveTag_Field_OrderCost; // ���-���������� ��������� ����������� ������
	    std::string SaveTag_Field_Date; // ���-��������� ���� �������� ������
	    std::string SaveTag_Field_Keywords; // ���-���������� �������� ����

	    std::string Technology_Name_C; // ������������ ���������� [��]
        std::string Technology_Name_CPlusPlus; // ������������ ���������� [C++]
        std::string Technology_Name_Another; // ������������ ���������� Another

        std::string IDE_Name_VisualStudio; // ������������ ����� ���������� [VisualStudio]
        std::string IDE_Name_Geany; // ������������ ����� ���������� [Geany]
        std::string IDE_Name_CodeBlocks; // ������������ ����� ���������� [CodeBlocks]
        std::string IDE_Name_QtCreator; // ������������ ����� ���������� [QtCreator]
        std::string IDE_Name_NoneIDE; // ������������ ����� ���������� [NoneIDE]

        std::string OS_Name_Linux; // ������������ ������������ ������� [Linux]
        std::string OS_Name_Windows; // ������������ ������������ ������� [Windows]

        std::string TypeWork_Name_LabWork; // ������������ ���� ������ [LabWork]
        std::string TypeWork_Name_CourseWork; // ������������ ���� ������ [CourseWork]
        std::string TypeWork_Name_Diploma; // ������������ ���� ������ [Diploma]

		std::string ERROR_Message_ClientExist; // ��������� �� ������ ��������� ���������� ������� � ����

    public:

        Class_Settings (void) {

            this->ProjectBuild_Name_Release = "Release";
            this->ProjectBuild_Name_Debug = "Debug";
            //this->ProjectBuild_Type = this->ProjectBuild_Name_Release;
            this->ProjectBuild_Type = this->ProjectBuild_Name_Debug;
            this->ProjectBuild_Version = "2.25.01.2021";

            this->ProjectBuild_SavePath_DB_Release = "E:\\Orders\\C++Tasks";
            this->ProjectBUild_SavePath_DB_Debug = "E:\\Orders\\C++Tasks(Debug)";

            this->SaveTag_Path_to_Labs = "Path_to_Labs";
            this->SaveTag_Order_Start = "Order_Start";
            this->SaveTag_Close_Application = "Close_Application";
            this->SaveTag_Open_Order = "Open_Order";
            this->SaveTag_Update_BanList = "Update_BanList";
            this->SaveTag_Url_BanList_Clients = "Url_BanList_Clients";
            this->SaveTag_Url_BanList_Workers = "Url_BanList_Workers";

            this->PK_Name = Load_PK_UserName ();

                if (this->ProjectBuild_Type == this->ProjectBuild_Name_Debug)
                    this->Config_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\(Debug)_AutoTaskCreator_Settings.cfg";

                else
                    this->Config_Path = "C:\\Users\\" + this->PK_Name + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";


            Check_ConfigFile (false);
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

			this->ERROR_Message_ClientExist = "NoneClient";

        }

        ~Class_Settings (void) {}

    //////////////////////////////////////////////

        const std::string getProjectBuild_Type (void) const {

            return this->ProjectBuild_Type;

        } // ������ ��� ProjectBuild_Type

        const std::string getProjectBuild_Version (void) const {

            return this->ProjectBuild_Version;

        } // ������ ��� ProjectBuild_Version

        const std::string getProjectBuild_Name_Release (void) const {

            return this->ProjectBuild_Name_Release;

        } // ������ ��� ProjectBuild_Name_Release

        const std::string getPorjectBuild_Name_Debug (void) const {

            return this->ProjectBuild_Name_Debug;

        } // ������ ��� ProjectBuild_Name_Debug

    //////////////////////////////////////////////

        const void setPK_Name (const std::string Str) {

			this->PK_Name = Str;

		} // ������ ��� PK_Name

		const std::string getPK_Name (void) const {

			return this->PK_Name;

		} // ������ ��� PK_Name

        const void setLabs_Path (const std::string Str) {

            this->Labs_Path = Str;

        } // ������ ��� Labs_Path

        const std::string getLabs_Path (void) const {

            return this->Labs_Path;

        } // ������ ��� Labs_Path

        const void setConfig_Path (const std::string Str) {

            this->Config_Path = Str;

        } // ������ ��� Config_Path

        const std::string getConfig_Path (void) const {

            return this->Config_Path;

        } // ������ ��� Config_Path

        const void setAutomatic_Order_Start (const bool Flag) {

            this->Automatic_Order_Start = Flag;

        } // ������ ��� Automatic_Order_Start

        const bool getAutomatic_Order_Start (void) const {

            return this->Automatic_Order_Start;

        } // ������ ��� Automatic_Order_Start

        const void setAutomatic_Close_Application (const bool Flag) {

            this->Automatic_Close_Application = Flag;

        } // ������ ��� Automatic_Close_Application

        const bool getAutomatic_Close_Application (void) const {

            return this->Automatic_Close_Application;

        } // ������ ��� Automatic_Close_Applcation

        const void setAutomatic_Open_Order (const bool Flag) {

            this->Automatic_Open_Order = Flag;

        } // ������ ��� Automatic_Open_Order

        const bool getAutomatic_Open_Order (void) const {

            return this->Automatic_Open_Order;

        } // ������ ��� Automatic_Open_Order

        const void setAutomatic_Update_BanList (const bool Flag) {

            this->Automatic_Update_BanList = Flag;

        } // ������ ��� Automatic_Update_BanList

        const bool getAutomatic_Update_BanList (void) const {

            return this->Automatic_Update_BanList;

        } // ������ ��� Automatic_Update_BanList

        const void setUrl_BanList_Clients (const std::string Str) {

            this->Url_BanList_Clients = Str;

        } // ������ ��� Url_BanList_Clients

        const std::string getUrl_BanList_Clients (void) const {

            return this->Url_BanList_Clients;

        } // ������ ��� Url_BanList_Clients

        const void setUrl_BanList_Workers (const std::string Str) {

            this->Url_BanList_Workers = Str;

        } // ������ ��� Url_BanList_Workers

        const std::string getUrl_BanList_Workers (void) const {

            return this->Url_BanList_Workers;

        } // ������ ��� Url_BanList_Workers

        const void setDisk_Path (const std::string Str) {

            this->Disk_Path = Str;

        } // ������ ��� Disk_Path

        const std::string getDisk_Path (void) const {

            return this->Disk_Path;

        } // ������ ��� Disk_Path

    //////////////////////////////////////////////

        const std::string getSaveTag_Field_Technology (void) const {

            return this->SaveTag_Field_Technology;

        } // ������ ��� SaveTag_Field_Technology

        const std::string getSaveTag_Field_IDE (void) const {

            return this->SaveTag_Field_IDE;

        } // ������ ��� SaveTag_Field_IDE

        const std::string getSaveTag_Field_OS (void) const {

            return this->SaveTag_Field_OS;

        } // ������ ��� SaveTag_Field_OS

        const std::string getSaveTag_Field_OrderCost (void) const {

            return this->SaveTag_Field_OrderCost;

        } // ������ ��� SaveTag_Field_OrderCost

        const std::string getSaveTag_Field_Date (void) const {

            return this->SaveTag_Field_Date;

        } // ������ ��� SaveTag_Field_Date

        const std::string getSaveTag_Field_Keywords (void) const {

            return this->SaveTag_Field_Keywords;

        } // ������ ��� SaveTag_Field_Keywords

    //////////////////////////////////////////////

        const std::string getSaveTag_Field_TypeWork (void) const {

            return this->SaveTag_Field_TypeWork;

        } // ������ ��� SaveTag_Field_TypeWork

    //////////////////////////////////////////////

        const std::string getTechnology_Name_C (void) const {

            return this->Technology_Name_C;

        } // ������ ��� Technology_Name_C

        const std::string getTechnology_Name_CPlusPlus (void) const {

            return this->Technology_Name_CPlusPlus;

        } // ������ ��� Technology_Name_CPlusPlus

        const std::string getTechnology_Name_Another (void) const {

            return this->Technology_Name_Another;

        } // ������ ��� Technology_Name_Another

    //////////////////////////////////////////////

        const std::string getIDE_Name_Geany (void) const {

            return this->IDE_Name_Geany;

        } // ������ ��� IDE_Name_Geany

        const std::string getIDE_Name_CodeBlocks (void) const {

            return this->IDE_Name_CodeBlocks;

        } // ������ ��� IDE_Name_CodeBlocks

        const std::string getIDE_Name_VisualStudio (void) const {

            return this->IDE_Name_VisualStudio;

        } // ������ ��� IDE_Name_VisualStudio

        const std::string getIDE_Name_QtCreator (void) const {

            return this->IDE_Name_QtCreator;

        } // ������ ��� IDE_Name_QtCreator

        const std::string getIDE_Name_NoneIDE (void) const {

            return this->IDE_Name_NoneIDE;

        } // ������ ��� IDE_Name_NoneIDE

    //////////////////////////////////////////////

        const std::string getOS_Name_Windows (void) const {

            return this->OS_Name_Windows;

        } // ������ ��� OS_Name_Windows

        const std::string getOS_Name_Linux (void) const {

            return this->OS_Name_Linux;

        } // ������ ��� OS_Name_Linux

    //////////////////////////////////////////////

        const std::string getTypeWork_Name_LabWork (void) const {

            return this->TypeWork_Name_LabWork;

        } // ������ ��� TypeWork_Name_LabWork

         const std::string getTypeWork_Name_CourseWork (void) const {

            return this->TypeWork_Name_CourseWork;

        } // ������ ��� TypeWork_Name_CourseWork

        const std::string getTypeWork_Name_Diploma (void) const {

            return this->TypeWork_Name_Diploma;

        } // ������ ��� TypeWork_Name_Diploma

    //////////////////////////////////////////////

        const std::string getERROR_Message_ClientExist (void) const {

            return this->ERROR_Message_ClientExist;

        } // ������ ��� ERROR_Message_ClientExist

    //////////////////////////////////////////////

         const void SetDefault_Parameters (void) {

                if (this->ProjectBuild_Type == this->ProjectBuild_Name_Debug)
                    this->Labs_Path = this->ProjectBUild_SavePath_DB_Debug;

                else
                    this->Labs_Path = this->ProjectBuild_SavePath_DB_Release;

            this->Automatic_Order_Start = false;
            this->Automatic_Close_Application = false;
            this->Automatic_Open_Order = true;
            this->Automatic_Update_BanList = true;
            this->Url_BanList_Clients = "https://vk.com/topic-156779709_36343200";
            this->Url_BanList_Workers = "https://vk.com/topic-156779709_39456558";

        } // ����� ��������� �������� �� ���������

        const std::string Load_PK_UserName (void) const;
        const void Check_ConfigFile (bool);
        const void Load_Parameters (void);
        const void SaveSettings (const bool) const;
        const bool Check_FilePath (const std::string& Path);

}; // ����� �������� ����������

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

} // ����� ��������� �������� ����� ������������-��

const void Class_Settings::Check_ConfigFile (bool ForceRewriteFile) {

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

        } // ���� ����� ���, �� ������� ���� ������� � ���������� �����������

    Read.close ();

    ConfigFile_Close (this->Config_Path);

} // ����� �������� ������������� ����� � ��������

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

    ConfigFile_Close (this->Config_Path);

        if (LabsPath_Founded != true || OrderStart_Founded != true || CloseApp_Founded != true || Open_Order_Founded != true || UpdateBanList_Founded != true || Url_BanList_Clients_Founded != true || Url_BanList_Workers_Founded != true)
            Check_ConfigFile (true);

} // ����� �������� ���������� ����������

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

            printf ("\n\n\n���������� ��������� ");

                for (unsigned short int i = 0; i < 4; i++) {

                    Delay (1000);
                    printf (".");

                }

        }

} // ����� ���������� ��������

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

} // ����� �������� ������������ ���� � ���� �������

#endif // _settings_class_h_
