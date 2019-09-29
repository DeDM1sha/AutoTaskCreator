// Модуль для настроек приложения. Именно здесь описан весь функционал кнопки "Настройки".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

static std::string Convert_Bool_toString (const bool& Boolean) {

    if (Boolean)
        return "True";

    return "False";

} // функция конвертации из типа bool в тип std::string

static void Show_TextHeader (std::string MainText) {

    CenterText (MainText + "\n");
    CenterText ("Для этого нажмите Y (Yes) - для подтверждения\n");
    CenterText ("Или N (No) - для отмены\n\n");
    CenterText ("Ваш выбор: ");

} // функция для отображения шапки в подпунктах меню

const void Menu_Settings (Class_Settings& Settings, Class_BanLists& Banlists) {

    std::string String_AutomaticCloseApplication = "\0";
    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню

    while (true) {

        cls ();

        CenterText ("Настройки программы\n");
        Show_Text_ForExit ();

        printf ("\n\n\n\n");
        CenterText ("Выберите пункт меню для изменения выбранных настроек\n\n\n");
        printf ("                                   1. Путь к месту хранения заказов: ");
        Show_Text_Output(Settings.getLabs_Path () + "\n");

        printf ("                                   2. Автоматический запуск создания нового заказа: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Order_Start ()) + "\n");

        printf ("                                   3. Автоматическое завершение после заполнения заказа: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Close_Application ()) + "\n");

        printf ("                                   4. Автоматическое открытие заказа после его создания: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Open_Order ()) + "\n");

        printf ("                                   5. Автоматическое ежемесячное обновление списка бан-листа: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Update_BanList()) + "\n");

        printf ("                                   6. Изменить адрес бан-листа клиентов: ");
        Show_Text_Output (Settings.getUrl_BanList_Clients() + "\n");

        printf ("                                   7. Изменить адрес бан-листа исполнителей: ");
        Show_Text_Output (Settings.getUrl_BanList_Workers() + "\n");

        //printf ("                                   8. Обновить список бан-листа");

        printf ("\n                                   Tab. Восстановить настройки по умолчанию\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", &ButtonNumber) || ClickCatch ("1", &ButtonNumber) || ClickCatch ("2", &ButtonNumber) || ClickCatch ("3", &ButtonNumber) || ClickCatch ("4", &ButtonNumber) || ClickCatch ("5", &ButtonNumber) || ClickCatch ("6", &ButtonNumber) || ClickCatch ("7", &ButtonNumber) || ClickCatch ("Tab", &ButtonNumber))
                        break;

            }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", &ButtonNumber)) {

                    std::string Str = "\0";
                    CenterText ("Введите новый путь к хранению заказов");

                        while (true) {

                            printf ("\n");
                            CenterText ("Путь: ");

                            Str = Show_Text_Input ("Путь: ");

                                if (Check_Input_ForExit (Str))
                                    break;

                               else if (Str.length () > 1 && Settings.Check_FilePath (Str))
                                    break;

                        } // валидность на ввод пути

                        if (Check_Input_ForExit (Str))
                            continue;

                    Settings.setLabs_Path (Str);

                } // изменение пути места хранения заказов

                else if (ClickCatch ("2", &ButtonNumber)) {

                    Show_TextHeader ("Задайте булевое значение для автоматического запуска меню заказа");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Order_Start (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Order_Start (false);

                                }

                        }

                        else
                            continue;

                } // изменение автоматического запуска меню заказа

                else if (ClickCatch ("3", &ButtonNumber)) {

                    Show_TextHeader ("Задайте булевое значение для автоматического закрытия приложения после меню заказа");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Close_Application (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Close_Application (false);

                                }

                        }

                        else
                            continue;

                } // изменение автоматического закрытия приложения после меню заказа

                else if (ClickCatch ("4", &ButtonNumber)) {

                    Show_TextHeader ("Задайте булевое значение для автоматического открытия заказа после его создания");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Open_Order (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Open_Order (false);

                                }

                        }

                        else
                            continue;

                } // включение/отключение автоматического запуска заказа после его создания

                else if (ClickCatch ("5", &ButtonNumber)) {

                    Show_TextHeader ("Задайте булевое значение для автоматического обновления списка бан-листа");

                    while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Update_BanList (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Update_BanList (false);

                                }

                        }

                        else
                            continue;

                } // включение/отключение ежемесячного обновления списка бан-листа

                else if (ClickCatch ("6", &ButtonNumber)) {

                    continue;


                } // изменение ссылки на список бан-листа клиентов

                else if (ClickCatch ("7", &ButtonNumber)) {

                    continue;

                } // изменение ссылки на список бан-листа исполнителей

                /*else if (ClickCatch ("8", &ButtonNumber)) {

                        Show_TextHeader ("Вы действительно хотите обновить список бан-листов?");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber)) {

                            Show_Text_Output ("Yes");

                            Banlists.Update_Banlists (Settings);

                        }

                        else if (ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                            continue;

                } // обновить список бан-листа*/

                else if (ClickCatch ("Tab", &ButtonNumber)) {

                    Show_TextHeader ("Вы действительно хотите восстановить настройки по умолчанию?");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber)) {

                            Show_Text_Output ("Yes");

                            Settings.ConfigFile_Open (Settings.getConfig_Path ());

                            remove (Settings.getConfig_Path().c_str());

                            Settings.SetDefault_Parameters ();

                            Settings.ConfigFile_Close (Settings.getConfig_Path ());

                        }

                        else if (ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                            continue;

                } // вернуть настройки по умолчанию

            Settings.SaveSettings (true);

    } // конец жизненного цикла меню настроек

} // функция настроек приложения

#endif // _Menu_Settings_h_
