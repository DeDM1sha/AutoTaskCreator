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
        std::vector <std::string> ClientsName; // ����� ���� ��������

    public:

        Class_Statistics (const Class_Settings& Settings) {

            this->TotalNumber_ClientsInDB_Count = Load_TotalNumber_ClientsInDB_Count (Settings);
            this->ClientsName.reserve (TotalNumber_ClientsInDB_Count);
            this->TotalNumber_Technology_C = 0;
            this->TotalNumber_Technology_CPlusPlus = 0;
            this->TotalNumber_Technology_Another = 0;
			this->TotalNumber_CompletedTasks_Count = Load_TotalNumber_CompletedTasks_Count (Settings);

        }

        ~Class_Statistics (void) {}

        const void setTotalNumber_CompletedTasks_Count (const unsigned short int Number) {

			this->TotalNumber_CompletedTasks_Count = Number;

		} // ������ ��� TotalNumber_CompletedTasks_Count

		const unsigned short int getTotalNumber_CompletedTasks_Count (void) const {

			return this->TotalNumber_CompletedTasks_Count;

		} // ������ ��� TotalNumber_CompletedTasks_Count

	//////////////////////////////////////////////

        const void setTotalNumber_ClientsInDB_Count (const unsigned short int Number) {

			this->TotalNumber_ClientsInDB_Count = Number;

		} // ������ ��� TotalNumber_ClientsInDB_Count

		const unsigned short int getTotalNumber_ClientsInDB_Count (void) const {

			return this->TotalNumber_ClientsInDB_Count;

		} // ������ ��� TotalNumber_ClientsInDB_Count

	//////////////////////////////////////////////

        const void setTotalNumber_Technology_C (const unsigned short int Number) {

            this->TotalNumber_Technology_C = Number;

        } // ������ ��� TotalNumber_Technology_C

        const unsigned short int getTotalNumber_Technology_C (void) const {

            return this->TotalNumber_Technology_C;

        } // ������ ��� TotalNumber_Technology_C

    //////////////////////////////////////////////

        const void setTotalNumber_Technology_CPlusPlus (const unsigned short int Number) {

            this->TotalNumber_Technology_CPlusPlus = Number;

        } // ������ ��� TotalNumber_Technology_CPlusPlus

        const unsigned short int getTotalNumber_Technology_CPlusPlus (void) const {

            return this->TotalNumber_Technology_CPlusPlus;

        } // ������ ��� TotalNumber_Technology_CPlusPlus

    //////////////////////////////////////////////

        const void setTotalNumber_Technology_Another (const unsigned short int Number) {

            this->TotalNumber_Technology_Another = Number;

        } // ������ ��� TotalNumber_Technology_Another

        const unsigned short int getTotalNumber_Technology_Another (void) const {

            return this->TotalNumber_Technology_Another;

        } // ������ ��� TotalNumber_Technology_Another

    //////////////////////////////////////////////

        const void setClientsName (const std::string Str, const unsigned short int Counter) {

            this->ClientsName[Counter] = Str;

        } // ������ ��� ClientsName

        const std::string getClientsName (const unsigned short int Counter) const {

            return this->ClientsName[Counter];

        } // ������ ��� ClientsName

        const unsigned short int Load_TotalNumber_ClientsInDB_Count (const Class_Settings&);
        const void Load_ClientsName (const Class_Settings&);
        const unsigned short int Load_TotalNumber_CompletedTasks_Count (const Class_Settings&);

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

const unsigned short int Class_Statistics::Load_TotalNumber_CompletedTasks_Count (const Class_Settings& Settings) {

    unsigned short int TotalCount = 0;
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

            TotalCount += LocalCountTasks;

                for (unsigned short int c = 1; c < LocalCountTasks + 1; c++) {

                    std::string TypeTechnology = "\0";
                    std::string LogPath = Settings.getLabs_Path () + "\\" + ClientsName[i] + "\\Task_" + Convert_Int_toString (c) + "\\" + "tz.txt";

                     std::ifstream Read (LogPath.c_str ());

                        while (Read >> Str) {

                            if (Str == Settings.getTechnology_Name_C ()) {

                                this->TotalNumber_Technology_C++;
                                TypeTechnology = Settings.getTechnology_Name_C ();
                                break;

                            }

                            if (Str == Settings.getTechnology_Name_CPlusPlus ()) {

                                this->TotalNumber_Technology_CPlusPlus++;
                                TypeTechnology = Settings.getTechnology_Name_CPlusPlus ();
                                break;

                            }

                            if (Str == Settings.getTechnology_Name_Another ()) {

                                this->TotalNumber_Technology_Another++;
                                TypeTechnology = Settings.getTechnology_Name_Another ();
                                break;

                            }

                        }

                    Read.close ();

                }

        }

    return TotalCount;

} // ����� �������� ���-�� ����������� ������� � ����

#endif // _statistics_class_h_
