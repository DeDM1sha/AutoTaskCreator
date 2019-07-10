#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const void Menu_Settings (Class_Settings& Settings) {

    std::string String_AutomaticOrderStart = "\0";

    while (true) {

        cls ();

        printf ("\n\n\n\n\n\n\n\n");
        CenterText ("Выберите пункт меню для изменения выбранных настроек\n\n\n");
        printf ("%s%s\n", "                                     1. Путь к месту хранения заказов: ", Settings.getLabs_Path ().c_str ());

            if (Settings.getAutomatic_Order_Start () == true)
                String_AutomaticOrderStart = "True";

            else
                String_AutomaticOrderStart = "False";

        printf ("%s%s\n", "                                     2. Автоматический запуск нового заказа: ", String_AutomaticOrderStart.c_str ());

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("1", ButtonNumber) || ClickCatch ("2", ButtonNumber))
                        break;

            }

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", ButtonNumber)) {

                    CenterText ("Введите новый путь к хранению заказов\n");
                    CenterText ("Путь: ");

                    const std::string Str = Show_Text_Input ();

                    Settings.setLabs_Path (Str);

                } // изменение пути места хранения заказов

                else if (ClickCatch ("2", ButtonNumber)) {

                    CenterText ("Задайте булевое значение для автоматического запуска меню заказа\n");
                    CenterText ("Для этого нажмите Y (Yes) - для включения\n");
                    CenterText ("Или N (No) - для отключения\n\n");
                    CenterText ("Ваш выбор: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber))
                                        break;

                        }

                         if (ClickCatch ("Y", ButtonNumber)) {

                            Show_Text_Choise ("Yes");
                            Settings.setAutomatic_Order_Start (true);

                        }

                        else if (ClickCatch ("N", ButtonNumber)) {

                            Show_Text_Choise ("No");
                            Settings.setAutomatic_Order_Start (false);

                        }

                        else
                            Exception ("Error selected getch in settings, order start choice");

                }

        Settings.SaveSettings ();

    }

} // функция настроек приложения

#endif // _Menu_Settings_h_
