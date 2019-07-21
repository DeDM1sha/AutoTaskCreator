#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const void Menu_Statistics (const Class_Settings& Settings) {

    Class_Statistics Statistics (Settings);

        while (true) {

            Show_Text_ForExit ();
            printf ("\n\n\n\n\n\n\n");

            printf ("%s%u\n", "                     Количество клиентов в базе: ", Statistics.getTotalNumber_ClientsInDB_Count ());
            printf ("%s%u\n", "                  Количество выполненных заданий в базе: ", Statistics.getTotalNumber_CompletedTasks_Count ());

                while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber))
                        return;

                }

        } // конец жизненного цикла меню статистики


    std::cout << "Clients in BD: " << Statistics.getTotalNumber_ClientsInDB_Count ();



} // функция статистики базы заказов и клиентов

#endif // _Menu_Statistics_h_
