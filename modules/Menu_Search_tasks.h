// Модуль для поиска заказа. Именно здесь описан весь функционал кнопки "Поиск заказа".

#pragma once

#ifndef _Menu_Search_tasks_h_
#define _Menu_Search_tasks_h_

const void Menu_Search_Tasks (void) {

    while (true) {

        Show_Text_ForExit ();

        printf ("1. Найти клиента по имени\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("1", ButtonNumber))
                        break;

            }

            if (ClickCatch ("Esc", ButtonNumber))
                return;

            else if (ClickCatch ("1", ButtonNumber)) {

                CenterText ("Введите имя: ");
                std::string Name = Show_Text_Input ();

            } // поиск клиента по имени

    }

} // функция поиска заказа / задания / клиента

#endif // _Menu_Search_tasks_h_
