#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const void Menu_Settings (Class_Settings& Settings) {

    while (true) {

        cls ();

        printf ("\n\n\n\n\n\n\n\n");
        CenterText ("Выберите пункт меню для изменения выбранных настроек\n\n\n");
        printf ("%s%s\n", "                                     1. Путь к месту хранения заказов: ", Settings.getLabs_Path ().c_str ());

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("1", ButtonNumber))
                        break;

            }

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", ButtonNumber)) {

                    std::string Str = "\0";
                    CenterText ("");
                    std::cout << "Новый путь к хранению заказов: ";
                    std::cin >> Str;

                    Settings.setLabs_Path (Str);

                } // изменение пути места хранения заказов


                 /* запилить сохранение настроек */

    }

} // функция настроек приложения

#endif // _Menu_Settings_h_
