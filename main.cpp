/* Project - AutoTaskCreator (ATC), by DeD_M1sha
==================================================================
Проект создан и предназначен для автоматизации работы с поступающими заказами, первостепенно с заказами по C / C++.
Разработка ведется с сентября 2017 года, и по сей день.
Операционная система: Windows 10.
Среда разработки: Code::Blocks.
Язык программирования: основной - чистый C++, с использованием Си, а также bat комманд.
Компилятор: MinGW (17.01)
Репозиторий: http://github.com/dedm1sha/autotaskcreator.
Автор: Сацук Михаил Михайлович (vk.com/m1shaowned)

==================================================================
Проект разбит на множество файлов:

    * классы
    * дополнительные библиотеки (сторонние, или самописные)
    * меню (с консольным оформлением)
    * дополнительные модули и конфигурационные файлы

Файлы взаимодействуют независимо друг от друга, за исключением передачи аргументов, которые могут менять свои свойства
при передаче из одной формы в другую, но при этом вся работа одного окна ограничивается этим окном.

Отдельное описание каждого из типа файла:
1) В классах описана алгоритмическая реализация методов, решающих конкретные задачи. Все свойства и методы защищены
от внешнего воздействия, а также и от возможных логических ошибок при работе самого приложения.

2) В дополнительных самописных библиотеках содержатся общие глобальные функции, используемые в каждом из окон приложения.
Описанные функции частично являются общеиспользуемыми, т.е. их можно использовать и в других программах для удобства разработки.

3) В данной программе фактически 5 действующих окон:

    % Главное меню
    % Меню создание заказа
    * Меню поиска заказа
    * Меню настроек
    * Меню статистики

За исключением главного меню (реализованного непосредственно в main.cpp), все последующие описаны в отдельных файлах.
Подробное описание каждого меню доступно в тех файлах соответственно

4) Дополнительные модули и конфиги - вспомогательные файлы, имеющие форматы картинок, cfg, сторонних программ.

Архитектура программы позволяет добавлять новый функционал сколь угодно, не роняя тем самым ранее описанный.
Данный проект можно дорабатывать до бесконечности, поскольку возможностей как с технической точки зрения, так и
с точки зрения задачи - огромная масса.

*/

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
#include <cctype>

// подключение всех необходимых стандартных библиотек для проекта

#include "modules/libs/clickcatcher.h" // подключение модуля clickcatcher - самописная библиотека по обработке нажатых клавиш
#include "modules/libs/additional_functions.h" // подключение модуля additional_functions - библиотека дополнительних общий функций

#include "modules/classes/settings_class.h" // подключение settings_class - класс настроек приложения
#include "modules/classes/clients_class.h" // подключение  clients_class - класс данных об клиенте
#include "modules/classes/banlists_class.h" // подключение banlist_class - класс забаненных клиентов
#include "modules/classes/statistics_class.h" // подключение statistics_class - класс базы данных всех заказов и клиентов
#include "modules/classes/search_class.h" // подключение search_class - класс поиска клиентов, заказов и т.д.
#include "modules/classes/formation_order_class.h" // подключение formation_order_class - класс создания нового заказа


#include "modules/menu_forms/Menu_Formation_order.h" // подключение модуля Formation_order - модуль формирование заказа
#include "modules/menu_forms/Menu_Search_tasks.h" // подключение модуля Search_tasks - модуль поиска заказа по ключевым словам
#include "modules/menu_forms/Menu_Settings.h" // подключение модуля Menu_Settings - модуль настроек приложения
#include "modules/menu_forms/Menu_Statistics.h" // одключение модуля Menu_Statistics - модуль статистики по базе данных

// подключение всех необходимых самописных библиотек и модулей для проекта

const static void Configure_Console_Window (const Class_Settings& Settings) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo (handle, &structCursorInfo); // отключение каретки

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // установка кириллицы

    const std::string Title = "title AutoTaskCreator - " + Settings.getProjectBuild_Type () + " build (v" + Settings.getProjectBuild_Version () + ")";

    system ("color A");
    system ("mode con cols=125 lines=30"); // установка разрешения консоли, отключения бокового скрола
    system (Title.c_str ()); // установка заголовка консоли
    system ("@echo off"); // переключение режима отображения команд на экране

} // Функция настроек консольного окна

const static void Draw_Menu (const unsigned short int* MenuItem) {

    printf ("\n\n\n\n\n\n");

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

    Class_Settings Settings; // инициализация объекта Settings
    Class_BanLists Banlists (Settings); // инициализация объекта Banlist;

    Configure_Console_Window (Settings);

    bool FirstOrderCreated = false; // переменная для отметки о том что первый заказ был создан

        if (Settings.getAutomatic_Order_Start () == true)
            Menu_Formation_Order (Settings, Banlists, &FirstOrderCreated);

    unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню
    unsigned short int MenuItem = 1; // выбранный пункт в меню

        while (true) {

                if (Settings.getAutomatic_Close_Application () == true && FirstOrderCreated == true)
                    return 0;

            cls ();
            CenterText ("Выберите пункт меню, используя клавиши стрелочек на клавиатуре (Esc - выход)");
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

                            if (MenuItem != 3)
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
