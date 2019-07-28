// Модуль для статистики. Именно здесь описан весь функционал кнопки "Статистика".

#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const void Menu_Statistics (const Class_Settings& Settings) {

    while (true) {

        Class_Statistics Statistics (Settings);

        Show_Text_ForExit ();
        printf ("                                                                                                Press F5 to update statistics\n");
        printf ("\n\n\n\n\n");
        printf ("                                      ------------------------------------------------\n");
        std::cout << "                                      | Количество клиентов в базе: " << std::setw (16) << Statistics.getTotalNumber_ClientsInDB_Count () << " |\n";
        printf ("                                      |----------------------------------------------|\n");
        std::cout << "                                      | Количество выполненных заданий в базе: " << std::setw (5) << Statistics.getTotalNumber_CompletedTasks_Count () << " |\n";
        printf ("                                      |----------------------------------------------|\n");
        std::cout << "                                      | Количество задач на C: " << std::setw (21) << Statistics.getTotalNumber_Technology_C () << " |\n";
        printf ("                                      |----------------------------------------------|\n");
        std::cout << "                                      | Количество задач на C++: " << std::setw (19) << Statistics.getTotalNumber_Technology_CPlusPlus () << " |\n";
        printf ("                                      |----------------------------------------------|\n");
        std::cout << "                                      | Количество прочих задач: " << std::setw (19) << Statistics.getTotalNumber_Technology_Another () << " |\n";
        printf ("                                      |----------------------------------------------|\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("F5", ButtonNumber));
                        break;

            }

            if (ClickCatch ("Esc", ButtonNumber))
                return;

            else if (ClickCatch ("F5", ButtonNumber)) {

                cls ();
                CenterText ("Статистика заказов\n");
                continue;

            }

    } // конец жизненного цикла меню статистики

} // функция статистики базы заказов и клиентов

#endif // _Menu_Statistics_h_
