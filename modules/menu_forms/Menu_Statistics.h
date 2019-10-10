// Модуль для статистики. Именно здесь описан весь функционал кнопки "Статистика".

#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const void Menu_Statistics (const Class_Settings& Settings, const Class_BanLists& Banlists) {

    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню

        while (true) {

            cls ();
            CenterText ("Статистика заказов\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to update statistics");

            Class_Statistics Statistics (Settings);

            printf ("\n\n\n\n");
            printf ("                                      ------------------------------------------------\n");

            std::cout << "                                      | Количество клиентов в базе: " << std::setw (16);
            Show_Number_Output (Statistics.getTotalNumber_ClientsInDB_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | Количество выполненных заданий в базе: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_CompletedTasks_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | Количество задач на C: " << std::setw (21);
            Show_Number_Output (Statistics.getTotalNumber_Technology_C ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | Количество задач на C++: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_CPlusPlus ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | Количество прочих задач: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_Another ());
            std::cout << " |\n";

            printf ("                                      |______________________________________________|\n");
            /*std::cout << "                                      | Количество заблокированных клиентов: " << std::setw (7);
            Show_Number_Output (Banlists.getTotalNumber_Clients_InBanList_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | Количество заблокированных исполнителей: " << std::setw (3);
            Show_Number_Output (Banlists.getTotalNumber_Workers_InBanList_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
*/
                if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_Technology_C () + Statistics.getTotalNumber_Technology_CPlusPlus () + Statistics.getTotalNumber_Technology_Another ()))
                    Show_Text_Output ("\n                         Общее кол-во выполненных задач не совпадает в сумме по отдельности!");

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("Esc", &ButtonNumber) || ClickCatch ("F5", &ButtonNumber))
                            break;

                }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

                else if (ClickCatch ("F5", &ButtonNumber)) {

                    cls ();
                    CenterText ("Статистика заказов\n");
                    continue;

                }

        } // конец жизненного цикла меню статистики

} // функция статистики базы заказов и клиентов

#endif // _Menu_Statistics_h_
