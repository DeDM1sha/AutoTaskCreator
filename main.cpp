#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <queue>
#include <time.h>

// подключение всех необходимых стандартных библиотек для проекта

#include "modules/clickcatcher.h" // подключение модуля clickcatcher - самописная библиотека по обработке нажатых клавиш
#include "modules/client_class.h" // подключение модуля client_class - класс данных об клиенте
#include "modules/formation_order.h" // подключение модуля formation_order - модуль формирование заказа

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

const void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen (Text.c_str ()) / 2); i++)
            printf (" ");

    printf ("%s\n", Text.c_str());

} // функция центирования текста на экране

const void cls (void) {

    system ("cls");

} // функция очистки экрана

const void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\n%s!!!\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция Exception - для отображения случившихся ошибок

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

    unsigned short int MenuItem = 1;
    unsigned short int ButtonNumber = 0;

    Configure_Console_Window ();

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

                                    case 1: CenterText ("Создание нового заказа\n");    Formation_Order();  break;
                                    case 2: CenterText ("Поиск работы среди имеющихся в базе\n");           break;
                                    case 3: CenterText ("Настройки программы\n");                           break;
                                    case 4: CenterText ("Статистика заказов\n");                            break;
                                    default: Exception ("Error selected getch in life cycle"); // эксепшион при работе с getch

                                }

                            break;

                        } // обработка нажатия Enter

                }

        } // жизненный цикл прораммы

}
