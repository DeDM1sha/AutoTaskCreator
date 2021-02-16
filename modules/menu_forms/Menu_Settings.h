// Модуль для настроек приложения. Именно здесь описан весь функционал кнопки "Настройки".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const static void Show_TextHeader (std::string MainText) {

    CenterText (MainText + "\n");
    CenterText ("Для этого нажмите Y (Yes) - для подтверждения\n");
    CenterText ("Или N (No) - для отмены\n\n");
    CenterText ("Ваш выбор: ");

} // функция для отображения шапки в подпунктах меню

const static bool ChoisenAnswer_SetSettings (unsigned short int* ButtonNumber, bool* OldParam) {

std::cout << "\nOldparam start: " << *OldParam;
        while (true) {

            *ButtonNumber = getch ();

                if (ClickCatch (ButtonNumber, "Y, N, Esc"))
                    break;

        }

        if (ClickCatch ("Esc", ButtonNumber))
            return false; // если был нажат Esc, то будет произведен дальшнейший выход в основное меню настроек

        else if (ClickCatch ("Y", ButtonNumber)) {

            if (*OldParam == true)
                return false;

            else
                *OldParam = true;

        }

        else if (ClickCatch ("N", ButtonNumber)) {

            if (*OldParam == false)
                return false;

            else
                *OldParam = false;

        }
std::cout << "\nOldparam finish: " << *OldParam << "\n";
    return true; // в обратном случае, будет вызвана функция, определяющая нажатие [Y] / [N]

} // функция для проверки нажатой клавиши в отдельном пункте меню настроек (отдельно для каждого параметра настроек)

const static bool ChoisenAnswer_SetParams (unsigned short int* ButtonNumber) {

        if (ClickCatch ("Y", ButtonNumber)) {

            Show_Text_Output ("Yes");
            return true;

        }

    Show_Text_Output ("No");

    return false;

} // функция для проверки нажатой клавиши при выборе ответа [Y] / [N]

const static std::string InputAnswer_SetParams (const std::string& MainText, const std::string& SupportText) {

    std::string Str = "\0";
    CenterText (MainText + "\n");

        while (true) {

            printf ("\n");
            CenterText (SupportText + ": ");

            Str = Show_Text_Input (SupportText + ": ", false);

                if (Check_Input_ForExit (Str))
                    break;

               else if (Str.length () > 1)
                    break;

        } // валидность на ввод пути

    return Str;

} // функция для ввода произвольных параметров в меню настроек

const static void Draw_MenuHeader (void) {

    cls ();

    CenterText ("Настройки программы\n");
    Show_Text_ForExit ();

    printf ("\n\n\n\n");

} // функция отрисровки шапки меню настроек

const static void Menu_Settings (Class_Settings& Settings, Class_BanLists& Banlists) {

    std::string String_AutomaticCloseApplication = "\0";
    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню
    bool Result = false;

        while (true) {

            Draw_MenuHeader ();

            CenterText ("Выберите раздел настроек параметров программных модулей\n\n");

            CenterText ("|------------------------------------------|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 1.      Раздел формирования заказов      |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 2.       Раздел поиска заказов           |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 3.      Раздел блокировки клиентов       |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 4.      Раздел статистики и данных       |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| Tab. Восстановить настройки по умолчанию |\n");
            CenterText ("|__________________________________________|\n");


            /*CenterText ("Выберите пункт меню для изменения выбранных настроек\n\n\n");


            printf ("                                   5. Автоматическое ежемесячное обновление списка бан-листа: ");
            Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Update_BanList()) + "\n");

            printf ("                                   6. Отображение заработанных средств: ");
            Show_Text_Output (Convert_Bool_toString (Settings.getDisplay_Money ()) + "\n");

            printf ("                                   7. Изменить адрес бан-листа клиентов: ");
            Show_Text_Output (Settings.getUrl_BanList_Clients() + "\n");

            printf ("                                   8. Изменить адрес бан-листа исполнителей: ");
            Show_Text_Output (Settings.getUrl_BanList_Workers() + "\n");

            printf ("                                   9. Обновить список бан-листа");

            printf ("\n                                   Tab. Восстановить настройки по умолчанию\n");*/

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, Tab"));
                            break;

                }

                    if (ClickCatch ("Esc", &ButtonNumber))
                        return;

                if (ClickCatch ("1", &ButtonNumber)) {

                    while (true) {

                        Draw_MenuHeader ();

                        CenterText ("Раздел настроек модуля формирования заказов\n\n");
                        printf ("                                   1. Путь к месту хранения заказов: ");
                        Show_Text_Output(Settings.getLabs_Path () + "\n");

                        printf ("                                   2. Автоматический запуск создания нового заказа: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Order_Start ()) + "\n");

                        printf ("                                   3. Автоматическое завершение после заполнения заказа: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Close_Application ()) + "\n");

                        printf ("                                   4. Автоматическое открытие заказа после его создания: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Open_Order ()) + "\n");

                        printf ("\n                                 Tab. Восстановить параметры формирования заказов по умолчанию\n");

                            while (true) {

                                ButtonNumber = getch ();

                                    if (ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, Tab"));
                                        break;

                            }

                            if (ClickCatch ("Esc", &ButtonNumber))
                                break;

                        printf ("\n\n\n");

                            if (ClickCatch ("1", &ButtonNumber)) {

                                std::string Str = InputAnswer_SetParams ("Введите новый путь к хранению заказов", "Путь");

                                    if (Check_Input_ForExit (Str))
                                        continue;

                                    if (Settings.Check_FilePath (Str))
                                        Settings.setLabs_Path (Str);

                                    else
                                        continue;

                            } // изменение пути места хранения заказов

                            else if (ClickCatch ("2", &ButtonNumber)) {

                                Show_TextHeader ("Задайте булевое значение для автоматического запуска меню заказа");
                                Result = Settings.getAutomatic_Order_Start ();

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber, &Result) == true) {

                                        std::cout << "REsult: " << Result << "\n";
                                        //ChoisenAnswer_SetParams (&ButtonNumber);
                                        Settings.setAutomatic_Order_Start (Result);
                                        Settings.SaveSettings (true);

                                    }

                                    else
                                        continue;

                            } // изменение автоматического запуска меню заказа

                            /*else if (ClickCatch ("3", &ButtonNumber)) {

                                Show_TextHeader ("Задайте булевое значение для автоматического закрытия приложения после меню заказа");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber) == true)
                                        Settings.setAutomatic_Close_Application (ChoisenAnswer_SetParams (&ButtonNumber));

                                    else
                                        continue;

                            } // изменение автоматического закрытия приложения после меню заказа

                            else if (ClickCatch ("4", &ButtonNumber)) {

                                Show_TextHeader ("Задайте булевое значение для автоматического открытия заказа после его создания");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber) == true)
                                        Settings.setAutomatic_Open_Order (ChoisenAnswer_SetParams (&ButtonNumber));

                                    else
                                        continue;

                            } // включение/отключение автоматического запуска заказа после его создания*/

                            else if (ClickCatch ("Tab", &ButtonNumber)) {

                                Show_TextHeader ("Вы действительно хотите восстановить параметры формирования заказов по умолчанию?");

                                    while (true) {

                                        ButtonNumber = getch ();

                                            if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                                    break;

                                    }

                                    if (ClickCatch ("Y", &ButtonNumber)) {

                                        Show_Text_Output ("Yes");
                                        Settings.SetDefaultParameters_FormationOrder ();
                                        Settings.SaveSettings (true);

                                    }

                                    else if (ClickCatch (&ButtonNumber, "N, Esc"))
                                        continue;

                            } // восстановление по умолчанию настроек формирования заказов

                    } // конец жизненного цикла меню настроек модуля формирования заказа

                } // раздел настроек модуля формирования заказа

                 /*else if (ClickCatch ("2", &ButtonNumber)) {



                 } // раздела настроек модуля поиска заказов

                 else if (ClickCatch ("3", &ButtonNumber)) {

                        if (ClickCatch ("1", &ButtonNumber)) {

                        }

                        else if (ClickCatch ("Tab", &ButtonNumber)) {

                            Settings.SetDefaultParameters_Banlists ();
                            Settings.SaveSettings (true);

                        } // восстановление по умолчанию настроек формирования заказов

                 } // раздел настроек модуля блокировки клиентов

                 else if (ClickCatch ("4", &ButtonNumber)) {



              */   } // раздел настроек модуля статистики

                /*

                    else if (ClickCatch ("5", &ButtonNumber)) {

                        Show_TextHeader ("Задайте булевое значение для автоматического обновления списка бан-листа");

                            if (ChoisenAnswer_SetSettings (&ButtonNumber) == true)
                                Settings.setAutomatic_Update_BanList (ChoisenAnswer_SetParams (&ButtonNumber));

                            else
                                continue;

                    } // включение/отключение ежемесячного обновления списка бан-листа

                    else if (ClickCatch ("6", &ButtonNumber)) {

                        Show_TextHeader ("Задайте булевое значение для отображения заработанных средств");

                            if (ChoisenAnswer_SetSettings (&ButtonNumber) == true)
                                Settings.setDisplay_Money (ChoisenAnswer_SetParams (&ButtonNumber));

                            else
                                continue;

                    } // включение/отключение отображения заработанных средств

                    else if (ClickCatch ("7", &ButtonNumber)) {

                        std::string Str = InputAnswer_SetParams ("Введите ссылку на бан-листов клиентов", "Ссылка");

                            if (Check_Input_ForExit (Str))
                                continue;

                            else
                                Settings.setUrl_BanList_Clients (Str);

                    } // изменение ссылки на список бан-листа клиентов

                    else if (ClickCatch ("8", &ButtonNumber)) {

                            std::string Str = InputAnswer_SetParams ("Введите ссылку на бан-листов исполнителей", "Ссылка");

                            if (Check_Input_ForExit (Str))
                                continue;

                            else
                                Settings.setUrl_BanList_Workers (Str);

                    } // изменение ссылки на список бан-листа исполнителей

                    else if (ClickCatch ("9", &ButtonNumber)) {

                            Show_TextHeader ("Вы действительно хотите обновить список бан-листов?");

                            if ((ChoisenAnswer_SetSettings (&ButtonNumber) == true) && (ChoisenAnswer_SetParams (&ButtonNumber) == true))
                                    Banlists.Update_Banlists (Settings);

                            else
                                continue;

                    } // обновить список бан-листа

                    else if (ClickCatch ("Tab", &ButtonNumber)) {

                        Show_TextHeader ("Вы действительно хотите восстановить все настройки по умолчанию?");

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
            */


        //} // конец жизненного цикла меню настроек

} // функция настроек приложения

#endif // _Menu_Settings_h_
