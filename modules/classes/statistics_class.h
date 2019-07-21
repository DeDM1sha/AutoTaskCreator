// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _statistics_class_h_
#define _statistics_class_h_

class Class_Statistics {

    private:

        unsigned short int TotalNumber_ClientsInDB_Count; // общее кол-во клиентов в базе
        unsigned short int TotalNumber_CompletedTasks_Count; // общее кол-во выполненных заданий со всех клиентов
        std::string* ClientsName;

    public:

        Class_Statistics (const Class_Settings& Settings) {

            TotalNumber_ClientsInDB_Count = Load_TotalNumber_ClientsInDB_Count (Settings);

            ClientsName = new std::string [TotalNumber_ClientsInDB_Count];
            Load_ClientsName (Settings);

			TotalNumber_CompletedTasks_Count = Load_TotalNumber_CompletedTasks_Count (Settings);

        }

        ~Class_Statistics (void) {

            delete [] ClientsName;

        }

        const void setTotalNumber_CompletedTasks_Count (const unsigned short int Number) {

			this->TotalNumber_CompletedTasks_Count = Number;

		} // сеттер для TotalNumber_CompletedTasks_Count

		const unsigned short int getTotalNumber_CompletedTasks_Count (void) const {

			return this->TotalNumber_CompletedTasks_Count;

		} // геттер для TotalNumber_CompletedTasks_Count

	//////////////////////////////////////////////

        const void setTotalNumber_ClientsInDB_Count (const unsigned short int Number) {

			this->TotalNumber_ClientsInDB_Count = Number;

		} // сеттер для TotalNumber_ClientsInDB_Count

		const unsigned short int getTotalNumber_ClientsInDB_Count (void) const {

			return this->TotalNumber_ClientsInDB_Count;

		} // геттер для TotalNumber_ClientsInDB_Count

	//////////////////////////////////////////////

        const void setClientsName (const std::string Str, const unsigned short int Counter) {

            this->ClientsName[Counter] = Str;

        } // сеттер для ClientsName

        const std::string getClientsName (const unsigned short int Counter) const {

            return this->ClientsName[Counter];

        } // геттер для ClientsName

        const unsigned short int Load_TotalNumber_ClientsInDB_Count (const Class_Settings&) const;
        const void Load_ClientsName (const Class_Settings&) const;
        const unsigned short int Load_TotalNumber_CompletedTasks_Count (const Class_Settings&) const;

}; // класс базы данных всех заказов

const unsigned short int Class_Statistics::Load_TotalNumber_ClientsInDB_Count (const Class_Settings& Settings) const {

    unsigned short int TotalCount = 0;

    std::string Command = "cd " + Settings.getLabs_Path () + " && dir /B > CountClients.txt";
    system (Command.c_str ());

    std::string Str = "\0";
    std::string LogPath = Settings.getLabs_Path () + "//CountClients.txt";
    std::ifstream Read (LogPath.c_str ());

        if (Read.is_open ()) {

            while (getline (Read, Str))

                if (Str != "CountClients.txt")
                    TotalCount++;

        }

        else
            Exception ("File CountClients.txt didnt open (For upload count clients)");

    Read.close ();

    return TotalCount;

} // метод подсчета кол-ва клиентов в базе

const void Class_Statistics::Load_ClientsName (const Class_Settings& Settings) const {

    std::string Str = "\0";
    unsigned short int Counter = 0;
    std::string LogPath = Settings.getLabs_Path () + "//CountClients.txt";
    std::ifstream Read (LogPath.c_str ());

        if (Read.is_open ()) {

            while (getline (Read, Str)) {

                if (Str != "CountClients.txt") {

                    ClientsName[Counter] = Str;
                    Counter++;

                }

            }

        }

        else
            Exception ("File CountClients.txt didnt open (For upload clients names)");

    Read.close ();

    remove (LogPath.c_str ());

} // метод по подгрузке всех имен клиентов в базе

const unsigned short int Class_Statistics::Load_TotalNumber_CompletedTasks_Count (const Class_Settings& Settings) const {

    unsigned short int TotalCount = 0;
    std::string Str = "\0";
    std::string LogPath = Settings.getLabs_Path () + "//CountClients.txt";

        for (unsigned short int i = 0; i < TotalNumber_ClientsInDB_Count; i++) {

            std::string Path = Settings.getLabs_Path () + "\\" + ClientsName[i];
            std::string Command = "cd " + Path  + " && dir /B > CountTasks.txt";
            Path = Path + "\\" + "CountTasks.txt";

            system (Command.c_str ());

            std::ifstream Read (Path.c_str ());

                while (Read >> Str)
                    if (Str != "CountTasks.txt")
                        TotalCount++;

            Read.close ();

            remove (Path.c_str ());

        } // подсчет общего числа выполненных заданий

    return TotalCount;

} // метод подсчета кол-ва выполненных заданий в базе

#endif // _statistics_class_h_
