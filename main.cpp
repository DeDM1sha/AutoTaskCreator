#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "modules/clickcatcher.h"

void Configure_Console_Window (void) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = false;
    SetConsoleCursorInfo (handle, &structCursorInfo); // Отключение каретки
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251); // Установка кириллицы
    system ("color A && mode con cols=125 lines=30 && title AutoTaskCreator"); // Установка цвета текста, отключение бокового меню, заголовок программы

} // Функция настроек консольного окна

void CenterText (std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen (Text.c_str ()) / 2); i++)
            printf (" ");

    printf ("%s\n", Text.c_str());

} // функция центирования текста на экране

void cls (void) {

    system ("cls");

} // функция очистки экрана

void Draw_Menu (unsigned short int MenuItem) {

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
                            exit(0); // выход из программы

                        if ((ClickCatch ("Arrow_Left", ButtonNumber)) || (ClickCatch ("Arrow_Right", ButtonNumber))) {

                            switch (MenuItem) {

                                case 1: MenuItem = 2; break;
                                case 2: MenuItem = 1; break;
                                case 3: MenuItem = 4; break;
                                case 4: MenuItem = 3; break;

                            }

                            break;

                        } // обработка нажатия клавиши стрелки влево и вправо

                        if ((ClickCatch ("Arrow_Up", ButtonNumber)) || (ClickCatch ("Arrow_Down", ButtonNumber))) {

                            switch (MenuItem) {

                                case 1: MenuItem = 3; break;
                                case 2: MenuItem = 4; break;
                                case 3: MenuItem = 1; break;
                                case 4: MenuItem = 2; break;

                            }

                            break;

                        } // обработка нажатия клавиши стрелки вверх и вниз

                        if (ClickCatch ("Enter", ButtonNumber)) {

                            cls ();

                            switch (MenuItem) {

                                case 1: CenterText ("Создание нового заказа\n"); break;
                                case 2: CenterText ("Поиск работы среди имеющихся в базе\n"); break;
                                case 3: CenterText ("Настройки программы\n"); break;
                                case 4: CenterText ("Статистика заказов\n"); break;

                            }

                            break;

                        } // обработка нажатия Enter

                }

        } // жизненный цикл прораммы

}
