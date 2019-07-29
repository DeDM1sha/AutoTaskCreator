// Модуль для поиска заказа. Именно здесь описан весь функционал кнопки "Поиск заказа".

#pragma once

#ifndef _Menu_Search_tasks_h_
#define _Menu_Search_tasks_h_

static void Continue (void) {

    CenterText ("Для продолжения нажмите любую клавишу...");
    getch ();

} // функция ожидания нажатия для продолжления

const void Menu_Search_Tasks (const Class_Settings& Settings) {

    while (true) {

        cls ();

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

                bool Founded = false;
                CenterText ("Введите имя: ");
                std::string Name = Show_Text_Input ();

                std::ofstream Write (std::string(Settings.getLabs_Path () + "\\" + Name + "\\CheckClient.txt").c_str ());

                    if (Write.is_open ())
                        Founded = true;

                Write.close ();

                    if (!Founded) {

                        std::ofstream Fopen ("Reverse_Name.txt");
                        Fopen << Name;
                        Fopen.close ();

                        std::string FirstName = "\0";
                        std::string SecondName = "\0";

                        std::ifstream Read ("Reverse_Name.txt");
                        Read >> SecondName;
                        Read >> FirstName;
                        Read.close ();

                        remove ("Reverse_Name.txt");

                        Name = FirstName + " " + SecondName;

                        std::ofstream Write (std::string(Settings.getLabs_Path () + "\\" + Name + "\\CheckClient.txt").c_str ());

                            if (Write.is_open ())
                                Founded = true;

                        Write.close ();

                            if (!Founded) {

                                Show_Text_Choise (std::string ("Клиент " + Name + " не найден в базе\n"));
                                Continue ();

                            }

                    }

                    if (Founded) {

                        remove (std::string(Settings.getLabs_Path () + "\\" + Name + "\\CheckClient.txt").c_str ());
                        system (std::string("explorer \"" + Settings.getLabs_Path () + "\\" + Name + "\"").c_str ());


                    }

            } // поиск клиента по имени

    }

} // функция поиска заказа / задания / клиента

#endif // _Menu_Search_tasks_h_
