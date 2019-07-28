// Модуль для настроек приложения. Именно здесь описан весь функционал кнопки "Настройки".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const void Menu_Settings (Class_Settings& Settings) {

    std::string String_AutomaticOrderStart = "\0";
    std::string String_AutomaticCloseApplication = "\0";

    while (true) {

        cls ();

        Show_Text_ForExit ();

        printf ("\n\n\n\n\n\n\n");
        CenterText ("Выберите пункт меню для изменения выбранных настроек\n\n\n");
        printf ("%s%s\n", "                                     1. Путь к месту хранения заказов: ", Settings.getLabs_Path ().c_str ());

            if (Settings.getAutomatic_Order_Start () == true)
                String_AutomaticOrderStart = "True";

            else
                String_AutomaticOrderStart = "False";

        printf ("%s%s\n", "                                     2. Автоматический запуск нового заказа: ", String_AutomaticOrderStart.c_str ());

            if (Settings.getAutomatic_Close_Application () == true)
                String_AutomaticCloseApplication = "True";

            else
                String_AutomaticCloseApplication = "False";

        printf ("%s%s\n", "                                     3. Автоматическое закрытие после заполнения заказа: ", String_AutomaticCloseApplication.c_str ());
        printf ("                                     4. Восстановить настройки по умолчанию\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("1", ButtonNumber) || ClickCatch ("2", ButtonNumber) || (ClickCatch ("3", ButtonNumber)) || (ClickCatch ("4", ButtonNumber)))
                        break;

            }

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", ButtonNumber)) {

                    std::string Str = "\0";
                    std::string TestFilePath = "\0";
                    CenterText ("Введите новый путь к хранению заказов");

                        while (true) {

                            printf ("\n");
                            CenterText ("Путь: ");

                            Str = Show_Text_Input ();

                                if (Check_Input_ForExit (Str))
                                    break;

                            TestFilePath = Str + "\\ValidTest.txt";
                            std::ofstream Write (TestFilePath.c_str ());

                                if (!Write.is_open() || Str.length () < 2)
                                    CenterText ("Error! Not valid path\n\n");

                                else
                                    break;

                            Write.close ();

                        } // валидность на ввод пути

                        if (Check_Input_ForExit (Str))
                            continue;

                    remove (TestFilePath.c_str ());
                    Settings.setLabs_Path (Str);

                } // изменение пути места хранения заказов

                else if (ClickCatch ("2", ButtonNumber)) {

                    CenterText ("Задайте булевое значение для автоматического запуска меню заказа\n");
                    CenterText ("Для этого нажмите Y (Yes) - для включения\n");
                    CenterText ("Или N (No) - для отключения\n\n");
                    CenterText ("Ваш выбор: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber)) {

                                if (ClickCatch ("Y", ButtonNumber)) {

                                    Show_Text_Choise ("Yes");
                                    Settings.setAutomatic_Order_Start (true);

                                }

                                else {

                                    Show_Text_Choise ("No");
                                    Settings.setAutomatic_Order_Start (false);

                                }

                        }

                        else
                            continue;

                } // изменение автоматического запуска меню заказа

                else if (ClickCatch ("3", ButtonNumber)) {

                    CenterText ("Задайте булевое значение для автоматического закрытия приложения после меню заказа\n");
                    CenterText ("Для этого нажмите Y (Yes) - для включения\n");
                    CenterText ("Или N (No) - для отключения\n\n");
                    CenterText ("Ваш выбор: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber)) {

                                if (ClickCatch ("Y", ButtonNumber)) {

                                    Show_Text_Choise ("Yes");
                                    Settings.setAutomatic_Close_Application (true);

                                }

                                else {

                                    Show_Text_Choise ("No");
                                    Settings.setAutomatic_Close_Application (false);

                                }

                        }

                        else
                            continue;

                } // изменение автоматического закрытия приложения после меню заказа

                else if (ClickCatch ("4", ButtonNumber)) {

                    CenterText ("Вы действительно хотите восстановить настройки по умолчанию?\n");
                    CenterText ("Для этого нажмите Y (Yes) - для восстановления\n");
                    CenterText ("Или N (No) - для отмены восстановления\n\n");
                    CenterText ("Ваш выбор: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber)) {

                            Show_Text_Choise ("Yes");

                            remove (Settings.getConfig_Path().c_str());

                            Settings.SetDefault_Parameters ();

                        }

                        else if (ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                            continue;

                } // вернуть настройки по умолчанию

            Settings.SaveSettings (true);

    } // конец жизненного цикла меню настроек

} // функция настроек приложения

#endif // _Menu_Settings_h_
