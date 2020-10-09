// ����� ���� ������ ���� �������� � �������, ��������� � ����

#pragma once

#ifndef _statistics_class_h_
#define _statistics_class_h_

class Class_Statistics {

    private:

        unsigned short int TotalNumber_ClientsInDB_Count; // ����� ���-�� �������� � ����
        unsigned short int TotalNumber_CompletedTasks_Count; // ����� ���-�� ����������� ������� �� ���� ��������

        unsigned short int TotalNumber_Technology_C; // ����� ���������� ����������� ����� �� [��]
        unsigned short int TotalNumber_Technology_CPlusPlus; // ����� ���������� ����������� ����� �� [C++]
        unsigned short int TotalNumber_Technology_Another; // ����� ���������� ����������� ����� �� ������ ������������ (������ �� ���������, ������ �� ������� � �.�.)

        unsigned short int TotalNumber_IDE_CodeBlocks; // ����� ���������� ����������� ����� ��� [Code::Blocks]
        unsigned short int TotalNumber_IDE_Geany; // ����� ���������� ����������� ����� ��� [Geany]
        unsigned short int TotalNumber_IDE_QtCreator; // ����� ���������� ����������� ����� ��� [QtCreator]
        unsigned short int TotalNumber_IDE_VisualStudio; // ����� ���������� ����������� ����� ��� [VisualStudio]
        unsigned short int TotalNumber_IDE_NoneIDE; // ����� ���������� ����������� ����� ��� [Another] �������

        unsigned short int TotalNumber_OS_Linux; // ����� ���������� ����������� ����� ��� [Linux]
        unsigned short int TotalNumber_OS_Windows; // ����� ���������� ����������� ����� ��� [Windows]

        unsigned short int TotalNumber_Clients_InBanList_Count; // ����� ���-�� �������� � ���-�����
		unsigned short int TotalNumber_Workers_InBanList_Count; // ����� ���-�� ������������ � ���-�����

        std::vector <std::string> ClientsName; // ����� ���� ��������

    public:

        Class_Statistics (const Class_Settings& Settings) {

            this->TotalNumber_ClientsInDB_Count = Load_TotalNumber_ClientsInDB_Count (Settings);
            this->TotalNumber_CompletedTasks_Count = 0;

            this->TotalNumber_Technology_C = 0;
            this->TotalNumber_Technology_CPlusPlus = 0;
            this->TotalNumber_Technology_Another = 0;

            this->TotalNumber_IDE_CodeBlocks = 0;
            this->TotalNumber_IDE_Geany = 0;
            this->TotalNumber_IDE_QtCreator = 0;
            this->TotalNumber_IDE_VisualStudio = 0;
            this->TotalNumber_IDE_NoneIDE = 0;

            this->TotalNumber_OS_Linux = 0;
            this->TotalNumber_OS_Windows = 0;

            this->ClientsName.reserve (TotalNumber_ClientsInDB_Count);

            this->TotalNumber_Clients_InBanList_Count = 0;
            this->TotalNumber_Workers_InBanList_Count = 0;

        }

        ~Class_Statistics (void) {}

    //////////////////////////////////////////////

		const unsigned short int getTotalNumber_CompletedTasks_Count (void) const {

			return this->TotalNumber_CompletedTasks_Count;

		} // ������ ��� TotalNumber_CompletedTasks_Count

		const unsigned short int getTotalNumber_ClientsInDB_Count (void) const {

			return this->TotalNumber_ClientsInDB_Count;

		} // ������ ��� TotalNumber_ClientsInDB_Count

    //////////////////////////////////////////////

        const unsigned short int getTotalNumber_Technology_C (void) const {

            return this->TotalNumber_Technology_C;

        } // ������ ��� TotalNumber_Technology_C

        const unsigned short int getTotalNumber_Technology_CPlusPlus (void) const {

            return this->TotalNumber_Technology_CPlusPlus;

        } // ������ ��� TotalNumber_Technology_CPlusPlus

        const unsigned short int getTotalNumber_Technology_Another (void) const {

            return this->TotalNumber_Technology_Another;

        } // ������ ��� TotalNumber_Technology_Another

    //////////////////////////////////////////////

        const unsigned short int getTotalNumber_IDE_CodeBlocks (void) const {

            return this->TotalNumber_IDE_CodeBlocks;

        } // ������ ��� TotalNumber_IDE_CodeBlocks

        const unsigned short int getTotalNumber_IDE_Geany (void) const {

            return this->TotalNumber_IDE_Geany;

        } // ������ ��� TotalNumber_IDE_Geany

        const unsigned short int getTotalNumber_IDE_QtCreator (void) const {

            return this->TotalNumber_IDE_QtCreator;

        } // ������ ��� TotalNumber_IDE_QtCreator

        const unsigned short int getTotalNumber_IDE_VisualStudio (void) const {

            return this->TotalNumber_IDE_VisualStudio;

        } // ������ ��� TotalNumber_IDE_VisualStudio

        const unsigned short int getTotalNumber_IDE_NoneIDE (void) const {

            return this->TotalNumber_IDE_NoneIDE;

        } // ������ ��� TotalNumber_IDE_NoneIDE

    //////////////////////////////////////////////

        const unsigned short int getTotalNumber_OS_Linux (void) const {

            return this->TotalNumber_OS_Linux;

        } // ������ ��� TotalNumber_OS_Linux

        const unsigned short int getTotalNumber_OS_Windows (void) const {

            return this->TotalNumber_OS_Windows;

        } // ������ ��� TotalNumber_OS_Windows

    //////////////////////////////////////////////

        const std::string getClientsName (const unsigned short int Counter) const {

            return this->ClientsName[Counter];

        } // ������ ��� ClientsName

    //////////////////////////////////////////////

        const unsigned short int getTotalNumber_Clients_InBanList_Count (void) const {

            return this->TotalNumber_Clients_InBanList_Count;

        } // ������ ��� TotalNumber_Clients_InBanList_Count

        const unsigned short int getTotalNumber_Workers_InBanList_Count (void) const {

            return this->TotalNumber_Workers_InBanList_Count;

        } // ������ ��� TotalNumber_Workers_InBanList_Count

    //////////////////////////////////////////////

        const unsigned short int Load_TotalNumber_ClientsInDB_Count (const Class_Settings&);
        const void Load_ClientsName (const Class_Settings&);
        const void Load_TotalNumber_Information (const Class_Settings&, const Class_BanLists&);

}; // ����� ���� ������ ���� �������

const unsigned short int Class_Statistics::Load_TotalNumber_ClientsInDB_Count (const Class_Settings& Settings) {

    unsigned short int TotalCount = 0;

    std::string Command = Settings.getDisk_Path () + " && cd " + Settings.getLabs_Path () + " && dir /B > CountClients.txt";
    system (Command.c_str ());

    std::string Str = "\0";
    std::string LogPath = Settings.getLabs_Path () + "//CountClients.txt";
    std::ifstream Read (LogPath.c_str ());

        if (Read.is_open ()) {

            while (getline (Read, Str)) {

                if (Str != "CountClients.txt") {

                    ClientsName.push_back (Str);
                    TotalCount++;

                }

            }

        }

        else
            Exception ("File CountClients.txt didnt open (For upload count clients)");

    Read.close ();

    remove (LogPath.c_str ());

    return TotalCount;

} // ����� �������� ���-�� �������� � �� ���� � ����

const void Class_Statistics::Load_TotalNumber_Information (const Class_Settings& Settings, const Class_BanLists& Banlists) {

    std::string Str = "\0";
    std::string LogPath = Settings.getLabs_Path () + "//CountClients.txt";

        for (unsigned short int i = 0; i < this->TotalNumber_ClientsInDB_Count; i++) {

            unsigned short int LocalCountTasks = 0;
            std::string Path = Settings.getLabs_Path () + "\\" + ClientsName[i];
            std::string Command = Settings.getDisk_Path () + " && cd " + Path  + " && dir /B > CountTasks.txt";
            Path = Path + "\\" + "CountTasks.txt";

            system (Command.c_str ());

            std::ifstream Read (Path.c_str ());

                while (getline (Read, Str)) {

                    if (Str != "CountTasks.txt")
                        LocalCountTasks++;

                }

            Read.close ();
            remove (Path.c_str ());

            this->TotalNumber_CompletedTasks_Count += LocalCountTasks;

                for (unsigned short int c = 1; c < LocalCountTasks + 1; c++) {

                    std::string LogPath = Settings.getLabs_Path () + "\\" + ClientsName[i] + "\\Task_" + Convert_Int_toString (c) + "\\" + "tz.txt";

                     std::ifstream Read (LogPath.c_str ());

                        while (Read >> Str) {

                            if (Str == Settings.getSaveTag_Field_Technology()) {

                                Read >> Str; // ���������� ������� [=]
                                Read >> Str; // ���������� �������� ��� ���� [Technology]

                                    if (Str == Settings.getTechnology_Name_C ())
                                        this->TotalNumber_Technology_C++;

                                    else if (Str == Settings.getTechnology_Name_CPlusPlus ())
                                        this->TotalNumber_Technology_CPlusPlus++;

                                    else if (Str == Settings.getTechnology_Name_Another ())
                                        this->TotalNumber_Technology_Another++;

                            } // �������� ���� Technology

                            else if (Str == Settings.getSaveTag_Field_IDE ()) {

                                Read >> Str; // ���������� ������� [=]
                                Read >> Str; // ���������� �������� ��� ���� [IDE]

                                    if (Str == Settings.getIDE_Name_CodeBlocks ())
                                        this->TotalNumber_IDE_CodeBlocks++;

                                    else if (Str == Settings.getIDE_Name_Geany ())
                                        this->TotalNumber_IDE_Geany++;

                                    else if (Str == Settings.getIDE_Name_QtCreator ())
                                        this->TotalNumber_IDE_QtCreator++;

                                    else if (Str == Settings.getIDE_Name_VisualStudio ())
                                        this->TotalNumber_IDE_VisualStudio++;

                                    else if (Str == Settings.getIDE_Name_NoneIDE ())
                                        this->TotalNumber_IDE_NoneIDE++;

                            } // �������� ���� IDE

                            else if (Str == Settings.getSaveTag_Field_OS ()) {

                                Read >> Str; // ���������� ������� [=]
                                Read >> Str; // ���������� �������� ��� ���� [OS]

                                    if (Str == Settings.getOS_Name_Linux ())
                                        this->TotalNumber_OS_Linux++;

                                    else if (Str == Settings.getOS_Name_Windows ())
                                        this->TotalNumber_OS_Windows++;

                            } // �������� ���� OS

                        }

                    Read.close ();

                }

        }

    this->TotalNumber_Clients_InBanList_Count = Banlists.getCount_ClientsBlockList ();
    this->TotalNumber_Workers_InBanList_Count = Banlists.getCount_WorkersBlockList ();

} // ����� �������� ���� ����������

#endif // _statistics_class_h_
