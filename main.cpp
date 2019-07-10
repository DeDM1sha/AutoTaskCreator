#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <queue>
#include <time.h>

// подключение всех необходимых стандартных библиотек для проекта

#include "modules/classes/client_class.h" // подключение модуля client_class - класс данных об клиенте
#include "modules/classes/statistics_class.h" // подключение модуля statistics_class - класс базы данных всех заказов и клиентов
#include "modules/classes/settings_class.h" // подключения модуля settings_class - класс настроек приложения

#include "modules/libs/clickcatcher.h" // подключение модуля clickcatcher - самописная библиотека по обработке нажатых клавиш
#include "modules/libs/additional_functions.h" // подключение модуля additional_functions - библиотека дополнительних общий функций

#include "modules/Menu_Formation_order.h" // подключение модуля Formation_order - модуль формирование заказа
#include "modules/Menu_Search_tasks.h" // подключение модуля Search_tasks - модуль поиска заказа по ключевым словам
#include "modules/Menu_Settings.h" // подключение модуля Menu_Settings - модуль настроек приложения
#include "modules/Menu_Statistics.h" // одключение модуля Menu_Statistics - модуль статистики по базе данных

// подключение всех необходимых самописных библиотек и модулей для проекта

const void Configure_Console_Window (void) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo (handle, &structCursorInfo); // отключение каретки
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251); // установка кириллицы
    system ("color A"); // установка цвета текста
    system ("mode con cols=125 lines=30"); // установка разрешения консоли, отключения бокового скрола
    system ("title AutoTaskCreator"); // установка заголовка консоли
    system ("@echo off"); // переключение режима отображения команд на экране

} // Функция настроек консольного окна

const void Draw_Menu (const unsigned short int MenuItem) {

    printf ("\n\n\n\n\n");

        if (MenuItem == 1) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|   Создать заказ   |*                      |    Поиск работ    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");

        }

        else if (MenuItem == 2) {

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

        if (MenuItem == 3) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|     Настройки     |*                      |     Статистика    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");


        }

        else if (MenuItem == 4) {

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

    Class_Clients Client; // инициализация объекта Client
    Class_Settings Settings (Client); // инициализация объекта Settings

        if (Settings.getAutomatic_Order_Start () == true)
            Menu_Formation_Order (Client, Settings);

    unsigned short int MenuItem = 1;

        while (true) {

                while (true) {

                    cls ();
                    CenterText ("Выберите пункт меню, используя клавиши стрелочек на клавиатуре");
                    Draw_Menu (MenuItem);
                    ButtonNumber = getch ();

                        if (ClickCatch ("Esc", ButtonNumber))
                            return 0; // выход из программы

                        if ((ClickCatch ("Arrow_Left", ButtonNumber)) || (ClickCatch ("Arrow_Right", ButtonNumber))) {

                                switch (MenuItem) {

                                    case 1: MenuItem = 2; break;
                                    case 2: MenuItem = 1; break;
                                    case 3: MenuItem = 4; break;
                                    case 4: MenuItem = 3; break;
                                    default: Exception ("Error selected getch in life cycle");

                                }

                            break;

                        } // обработка нажатия клавиши стрелки влево и вправо

                        if ((ClickCatch ("Arrow_Up", ButtonNumber)) || (ClickCatch ("Arrow_Down", ButtonNumber))) {

                                switch (MenuItem) {

                                    case 1: MenuItem = 3; break;
                                    case 2: MenuItem = 4; break;
                                    case 3: MenuItem = 1; break;
                                    case 4: MenuItem = 2; break;
                                    default: Exception ("Error selected getch in life cycle");

                                }

                            break;

                        } // обработка нажатия клавиши стрелки вверх и вниз

                        if (ClickCatch ("Enter", ButtonNumber)) {

                            cls ();

                                switch (MenuItem) {

                                    case 1: CenterText ("Создание нового заказа\n");                Menu_Formation_Order (Client, Settings); break;
                                    case 2: CenterText ("Поиск работы среди имеющихся в базе\n");   Menu_Search_Tasks ();   break;
                                    case 3: CenterText ("Настройки программы\n");                   Menu_Settings (Settings);       break;
                                    case 4: CenterText ("Статистика заказов\n");                    Menu_Statistics ();     break;
                                    default: Exception ("Error selected getch in life cycle"); // эксепшион при работе с getch

                                }

                            break;

                        } // обработка нажатия Enter

                }

        } // жизненный цикл прораммы

}
