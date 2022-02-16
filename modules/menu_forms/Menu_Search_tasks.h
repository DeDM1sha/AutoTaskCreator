// Модуль для поиска заказа. Именно здесь описан весь функционал кнопки "Поиск заказа".

#pragma once

#ifndef _Menu_Search_tasks_h_
#define _Menu_Search_tasks_h_

const static void Menu_Search_Tasks (const Class_Settings& Settings) {

    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню
    Class_Search Searching;

        while (true) {

            cls ();
            CenterText ("Поиск работ среди имеющихся в базе\n");
            Show_Text_ForExit ();

            printf ("\n\n\n");
            printf ("                                             ---------------------------------\n");
            CenterText ("|   1. Найти клиента по имени   |\n");
            printf ("                                             |_______________________________|\n\n\n");

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, 1"))
                            break;

                }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

                else if (ClickCatch ("1", &ButtonNumber)) {

                        CenterText ("Введите имя: ");
                        std::string ClientName = Show_Text_Input ("Введите имя: ", true);
                        Searching.Search_Client(ClientName, Settings);

                } // поиск клиента по имени

        }

} // функция поиска заказа / задания / клиента

#endif // _Menu_Search_tasks_h_


