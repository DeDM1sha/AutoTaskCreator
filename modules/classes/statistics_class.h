// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _statistics_class_h_
#define _statistics_class_h_

class Class_Statistics {

    private:

        unsigned short int TotalNumber_ClientsInDB_Count; // общее кол-во клиентов в базе
        unsigned short int TotalNumber_CompletedTasks_Count; // общее кол-во выполненных заданий со всех клиентов

        unsigned short int TotalNumber_Technology_C; // общее количество выполненных задач на [Си]
        unsigned short int TotalNumber_Technology_CPlusPlus; // общее количество выполненных задач на [C++]
        unsigned short int TotalNumber_Technology_Another; // общее количество выполненных задач по другим направлениям (помощь на экзаменах, ответы на вопросы и т.д.)

        unsigned short int TotalNumber_IDE_Geany; // общее количество выполненных задач под [Geany]
        unsigned short int TotalNumber_IDE_CodeBlocks; // общее количество выполненных задач под [Code::Blocks]
        unsigned short int TotalNumber_IDE_VisualStudio; // общее количество выполненных задач под [VisualStudio]
        unsigned short int TotalNumber_IDE_NoneIDE; // общее количество выполненных задач для [Another] заказов

        unsigned short int TotalNumber_OS_Linux; // общее количество выполненных задач под [Linux]
        unsigned short int TotalNumber_OS_Windows; // общее количество выполненных задач под [Windows]

        std::vector <std::string> ClientsName; // имена всех клиентов

    public:

        Class_Statistics (const Class_Settings& Settings) {

            this->TotalNumber_ClientsInDB_Count = Load_TotalNumber_ClientsInDB_Count (Settings);
            this->TotalNumber_CompletedTasks_Count = 0;

            this->TotalNumber_Technology_C = 0;
            this->TotalNumber_Technology_CPlusPlus = 0;
            this->TotalNumber_Technology_Another = 0;

            this->TotalNumber_IDE_Geany = 0;
            this->TotalNumber_IDE_CodeBlocks = 0;
            this->TotalNumber_IDE_VisualStudio = 0;
            this->TotalNumber_IDE_NoneIDE = 0;

            this->TotalNumber_OS_Linux = 0;
            this->TotalNumber_OS_Windows = 0;

            this->ClientsName.reserve (TotalNumber_ClientsInDB_Count);

        }

        ~Class_Statistics (void) {}


    //////////////////////////////////////////////

		const unsigned short int getTotalNumber_CompletedTasks_Count (void) const {

			return this->TotalNumber_CompletedTasks_Count;

		} // геттер для TotalNumber_CompletedTasks_Count

		const unsigned short int getTotalNumber_ClientsInDB_Count (void) const {

			return this->TotalNumber_ClientsInDB_Count;

		} // геттер для TotalNumber_ClientsInDB_Count

        const unsigned short int getTotalNumber_Technology_C (void) const {

            return this->TotalNumber_Technology_C;

        } // геттер для TotalNumber_Technology_C

        const unsigned short int getTotalNumber_Technology_CPlusPlus (void) const {

            return this->TotalNumber_Technology_CPlusPlus;

        } // геттер для TotalNumber_Technology_CPlusPlus

        const unsigned short int getTotalNumber_Technology_Another (void) const {

            return this->TotalNumber_Technology_Another;

        } // геттер для TotalNumber_Technology_Another

    //////////////////////////////////////////////

        const unsigned short int getTotalNumber_IDE_Geany (void) const {

            return this->TotalNumber_IDE_Geany;

        } // геттер для TotalNumber_IDE_Geany

        const unsigned short int getTotalNumber_IDE_CodeBlocks (void) const {

            return this->TotalNumber_IDE_CodeBlocks;

        } // геттер для TotalNumber_IDE_CodeBlocks

        const unsigned short int getTotalNumber_IDE_VisualStudio (void) const {

            return this->TotalNumber_IDE_VisualStudio;

        } // геттер для TotalNumber_IDE_VisualStudio

        const unsigned short int getTotalNumber_IDE_NoneIDE (void) const {

            return this->TotalNumber_IDE_NoneIDE;

        } // геттер для TotalNumber_IDE_NoneIDE

        const unsigned short int getTotalNumber_OS_Linux (void) const {

            return this->TotalNumber_OS_Linux;

        } // геттер для TotalNumber_OS_Linux

        const unsigned short int getTotalNumber_OS_Windows (void) const {

            return this->TotalNumber_OS_Windows;

        } // геттер для TotalNumber_OS_Windows

    //////////////////////////////////////////////

        const std::string getClientsName (const unsigned short int Counter) const {

            return this->ClientsName[Counter];

        } // геттер для ClientsName

        const unsigned short int Load_TotalNumber_ClientsInDB_Count (const Class_Settings&);
        const void Load_ClientsName (const Class_Settings&);
        const void Load_TotalNumber_Information (const Class_Settings&);

}; // класс базы данных всех заказов

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

} // метод подсчета кол-ва клиентов и их имен в базе

const void Class_Statistics::Load_TotalNumber_Information (const Class_Settings& Settings) {

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

                                Read >> Str; // считывание символа [=]
                                Read >> Str; // считывание значения для поля [Technology]

                                    if (Str == Settings.getTechnology_Name_C ())
                                        this->TotalNumber_Technology_C++;

                                    else if (Str == Settings.getTechnology_Name_CPlusPlus ())
                                        this->TotalNumber_Technology_CPlusPlus++;

                                    else if (Str == Settings.getTechnology_Name_Another ())
                                        this->TotalNumber_Technology_Another++;

                            } // проверка поля Technology

                            else if (Str == Settings.getSaveTag_Field_IDE ()) {

                                Read >> Str; // считывание символа [=]
                                Read >> Str; // считывание значения для поля [IDE]

                                    if (Str == Settings.getIDE_Name_CodeBlocks ())
                                        this->TotalNumber_IDE_CodeBlocks++;

                                    else if (Str == Settings.getIDE_Name_Geany ())
                                        this->TotalNumber_IDE_Geany++;

                                    else if (Str == Settings.getIDE_Name_VisualStudio ())
                                        this->TotalNumber_IDE_VisualStudio++;

                                    else if (Str == Settings.getIDE_Name_NoneIDE ())
                                        this->TotalNumber_IDE_NoneIDE++;

                            } // проверка поля IDE

                            else if (Str == Settings.getSaveTag_Field_OS ()) {

                                Read >> Str; // считывание символа [=]
                                Read >> Str; // считывание значения для поля [OS]

                                    if (Str == Settings.getOS_Name_Linux ())
                                        this->TotalNumber_OS_Linux++;

                                    else if (Str == Settings.getOS_Name_Windows ())
                                        this->TotalNumber_OS_Windows++;

                            } // проверка поля OS

                        }

                    Read.close ();

                }

        }

} // метод подсчета всей статистики

#endif // _statistics_class_h_
