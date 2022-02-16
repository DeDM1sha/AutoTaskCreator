// Модуль для статистики. Именно здесь описан весь функционал кнопки "Статистика".

#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const static void Menu_Statistics (const Class_Settings& Settings, const Class_BanLists& Banlists) {

    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню

        while (true) {

            cls ();
            CenterText ("Статистика заказов\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to update statistics");

            Class_Statistics Statistics (Settings);
            Statistics.Load_TotalNumber_Information (Settings, Banlists);

            printf ("                                       -----------------------------------------------\n");

            std::cout << "                                       | Количество клиентов в базе: " << std::setw (15);
            Show_Number_Output (Statistics.getTotalNumber_ClientsInDB_Count ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество выполненных заданий в базе: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_CompletedTasks_Count ());
            std::cout << " | Количество задач под IDE Code::Blocks: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_IDE_CodeBlocks ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество задач на C: " << std::setw (21);
            Show_Number_Output (Statistics.getTotalNumber_Technology_C ());
            std::cout << " | Количество задач под IDE Geany: " << std::setw (12);
            Show_Number_Output (Statistics.getTotalNumber_IDE_Geany ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество задач на C++: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_CPlusPlus ());
            std::cout << " | Количество задач под IDE VisualStudio: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_IDE_VisualStudio ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество прочих задач: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_Another ());
            std::cout << " | Количество задач под None IDE: " << std::setw (13);
            Show_Number_Output (Statistics.getTotalNumber_IDE_NoneIDE ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Кол-во выполненных лаборат. работ: " << std::setw (9);
            Show_Number_Output (Statistics.getTotalNumber_Completed_LabWorks ());
            std::cout << " | Количество задач под IDE QtCreator: " << std::setw (8);
            Show_Number_Output (Statistics.getTotalNumber_IDE_QtCreator ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Кол-во выполненных курсовых работ: " << std::setw (9);
            Show_Number_Output (Statistics.getTotalNumber_Completed_CourseWorks ());
            std::cout << " | Кол-во выполненных дипломных работ: " << std::setw (8);
            Show_Number_Output (Statistics.getTotalNumber_Completed_DiplomaWorks ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество заблокированных клиентов: " << std::setw (7);
            Show_Number_Output (Statistics.getTotalNumber_Clients_InBanList_Count ());
            std::cout << " | Количество задач под Windows: " << std::setw (14);
            Show_Number_Output (Statistics.getTotalNumber_OS_Windows ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | Количество заблокированных исполнителей: " << std::setw (3);
            Show_Number_Output (Statistics.getTotalNumber_Workers_InBanList_Count ());
            std::cout << " | Количество задач под Linux / Mac: " << std::setw (10);
            Show_Number_Output (Statistics.getTotalNumber_OS_Linux ());
            std::cout << " |\n";

            printf ("               |______________________________________________|______________________________________________|\n");

                if (Settings.getDisplay_Money () == true) {

                    std::cout << "                                       | Заработано денег: " << std::setw (18);
                    Show_Number_Output (999);
                    printf ("         |\n                                       ------------------------------------------------");

                }

               if (Settings.getProjectBuild_Type () == Settings.getProjectBuild_Name_Debug ()) {

                    if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_Technology_C () + Statistics.getTotalNumber_Technology_CPlusPlus () + Statistics.getTotalNumber_Technology_Another ()))
                        Show_Text_Output ("\n                           Общее кол-во выполненных задач не совпадает с суммой задач по отдельности!");

                    if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_IDE_CodeBlocks () + Statistics.getTotalNumber_IDE_Geany () + Statistics.getTotalNumber_IDE_VisualStudio () + Statistics.getTotalNumber_IDE_NoneIDE () + Statistics.getTotalNumber_IDE_QtCreator ()))
                        Show_Text_Output ("\n                           Общее кол-во выполненных задач не совпадает с суммой задач по IDE!");

                    if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_OS_Linux () + Statistics.getTotalNumber_OS_Windows ()))
                        Show_Text_Output ("\n                           Общее кол-во выполненных задач не совпадает с суммой задач по OS !");

                    if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_Completed_LabWorks () + Statistics.getTotalNumber_Completed_CourseWorks () + Statistics.getTotalNumber_Completed_DiplomaWorks ()) )
                        Show_Text_Output ("\n                           Общее кол-во выполненных задач не совпадает с суммой типов выполненных работ !");


                }

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, F5"))
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


