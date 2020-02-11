// Главное окно приложения, настройки окна и единое описанное хранилище всех необходимых библиотек/модулей для проекта

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <queue>
#include <time.h>
#include <vector>
#include <iomanip>
#include <sstream>

// подключение всех необходимых стандартных библиотек для проекта

#include "modules/classes/clients_class.h" // подключение  clients_class - класс данных об клиенте
#include "modules/classes/settings_class.h" // подключение settings_class - класс настроек приложения
#include "modules/classes/banlists_class.h" // подключение banlist_class - класс забаненных клиентов
#include "modules/classes/statistics_class.h" // подключение statistics_class - класс базы данных всех заказов и клиентов

#include "modules/libs/clickcatcher.h" // подключение модуля clickcatcher - самописная библиотека по обработке нажатых клавиш
#include "modules/libs/additional_functions.h" // подключение модуля additional_functions - библиотека дополнительних общий функций

#include "modules/menu_forms/Menu_Formation_order.h" // подключение модуля Formation_order - модуль формирование заказа
#include "modules/menu_forms/Menu_Search_tasks.h" // подключение модуля Search_tasks - модуль поиска заказа по ключевым словам
#include "modules/menu_forms/Menu_Settings.h" // подключение модуля Menu_Settings - модуль настроек приложения
#include "modules/menu_forms/Menu_Statistics.h" // одключение модуля Menu_Statistics - модуль статистики по базе данных

// подключение всех необходимых самописных библиотек и модулей для проекта

const static void Configure_Console_Window (void) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo (handle, &structCursorInfo); // отключение каретки

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // установка кириллицы

    system ("color A");
    system ("mode con cols=125 lines=30"); // установка разрешения консоли, отключения бокового скрола
    system ("title AutoTaskCreator"); // установка заголовка консоли
    system ("@echo off"); // переключение режима отображения команд на экране

} // Функция настроек консольного окна

const static void Draw_Menu (const unsigned short int* MenuItem) {

    printf ("\n\n\n\n");

        if (*MenuItem == 1) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|   Создать заказ   |*                      |    Поиск работ    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");

        }

        else if (*MenuItem == 2) {

            printf("                                                                         ***********************\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |   Создать заказ   |                      *|    Поиск работ    |*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                                                                         ***********************\n");

        }

        else {

            printf("                                                                                                \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |   Создать заказ   |                       |    Поиск работ    | \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                                                                                                \n");

        }

    printf("\n\n\n");

        if (*MenuItem == 3) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|     Настройки     |*                      |     Статистика    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");


        }

        else if (*MenuItem == 4) {

            printf("                                                                         ***********************\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |     Настройки     |                      *|     Статистика    |*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                                                                         ***********************\n");

        }

        else {

            printf("                                                                                                \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |     Настройки     |                       |     Статистика    | \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                                                                                                \n");

        }

} // функция отрисовки меню

int main (void) {

    Configure_Console_Window ();

    Class_Settings Settings; // инициализация объекта Settings
    Class_BanLists Banlists (Settings); // инициализация объекта Banlist;

    bool FirstOrderCreated = false; // переменная для отметки о том что первый заказ был создан

        if (Settings.getAutomatic_Order_Start () == true)
            Menu_Formation_Order (Settings, Banlists, &FirstOrderCreated);

    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню
    unsigned short int MenuItem = 1; // выбранный пункт в меню
    const static std::string ProgramVersion = "2.12.02"; // номер версии продукта
    const static std::string BuildType = "Debug"; // режим сборки

        while (true) {

                if (Settings.getAutomatic_Close_Application () == true && FirstOrderCreated == true)
                    return 0;

            cls ();
            CenterText ("Выберите пункт меню, используя клавиши стрелочек на клавиатуре (Esc - выход)");
            printf ("\n");
            Show_Text_In_Right_Corner (BuildType + " build (v" + ProgramVersion + ")");
            Draw_Menu (&MenuItem);

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("Esc", &ButtonNumber))
                            return 0; // выход из программы

                        if (ClickCatch (&ButtonNumber, "Arrow_Left, Arrow_Right")) {

                                switch (MenuItem) {

                                    case 1: ++MenuItem; break;
                                    case 2: --MenuItem; break;
                                    case 3: ++MenuItem; break;
                                    case 4: --MenuItem; break;

                                }

                            break;

                        } // обработка нажатия клавиши стрелки влево и вправо

                        if (ClickCatch (&ButtonNumber, "Arrow_Up, Arrow_Down")) {

                                switch (MenuItem) {

                                    case 1: ++(++MenuItem);             break;
                                    case 2: MenuItem = MenuItem << 1;   break;
                                    case 3: --(--MenuItem);             break;
                                    case 4: MenuItem = MenuItem >> 1;   break;

                                }

                            break;

                        } // обработка нажатия клавиши стрелки вверх и вниз

                        if (ClickCatch ("Enter", &ButtonNumber)) {

                            cls ();

                            if (MenuItem == 1 || MenuItem == 2 || MenuItem == 4)
                                if (!Settings.Check_FilePath (Settings.getLabs_Path())) {

                                    Exception ("Invalid FilePath to save order");
                                    break;

                                }

                                switch (MenuItem) {

                                    case 1: Menu_Formation_Order (Settings, Banlists, &FirstOrderCreated);  break;
                                    case 2: Menu_Search_Tasks (Settings);                                   break;
                                    case 3: Menu_Settings (Settings, Banlists);                             break;
                                    case 4: Menu_Statistics (Settings, Banlists);                           break;

                                }

                            break;

                        } // обработка нажатия Enter

                }

        } // жизненный цикл прораммы

}
