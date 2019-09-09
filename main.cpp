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

// ����������� ���� ����������� ����������� ��������� ��� �������

#include "modules/classes/client_class.h" // ����������� ������ client_class - ����� ������ �� �������
#include "modules/classes/settings_class.h" // ����������� ������ settings_class - ����� �������� ����������
#include "modules/classes/statistics_class.h" // ����������� ������ statistics_class - ����� ���� ������ ���� ������� � ��������

#include "modules/libs/clickcatcher.h" // ����������� ������ clickcatcher - ���������� ���������� �� ��������� ������� ������
#include "modules/libs/additional_functions.h" // ����������� ������ additional_functions - ���������� �������������� ����� �������

#include "modules/Menu_Formation_order.h" // ����������� ������ Formation_order - ������ ������������ ������
#include "modules/Menu_Search_tasks.h" // ����������� ������ Search_tasks - ������ ������ ������ �� �������� ������
#include "modules/Menu_Settings.h" // ����������� ������ Menu_Settings - ������ �������� ����������
#include "modules/Menu_Statistics.h" // ���������� ������ Menu_Statistics - ������ ���������� �� ���� ������

// ����������� ���� ����������� ���������� ��������� � ������� ��� �������

const void Configure_Console_Window (void) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo (handle, &structCursorInfo); // ���������� �������

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // ��������� ���������

    system ("color A");
    system ("mode con cols=125 lines=30"); // ��������� ���������� �������, ���������� �������� ������
    system ("title AutoTaskCreator"); // ��������� ��������� �������
    system ("@echo off"); // ������������ ������ ����������� ������ �� ������
    
    test unciode

} // ������� �������� ����������� ����

const void Draw_Menu (const unsigned short int& MenuItem) {

    printf ("\n\n\n\n\n");

        if (MenuItem == 1) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|   ������� �����   |*                      |    ����� �����    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");

        }

        else if (MenuItem == 2) {

            printf("                                                                         ***********************\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |   ������� �����   |                      *|    ����� �����    |*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                                                                         ***********************\n");

        }

        else {

            printf("                                                                                                \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |   ������� �����   |                       |    ����� �����    | \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                                                                                                \n");

        }

    printf("\n\n\n");

        if (MenuItem == 3) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|     ���������     |*                      |     ����������    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");


        }

        else if (MenuItem == 4) {

            printf("                                                                         ***********************\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |     ���������     |                      *|     ����������    |*\n");
            printf("                              |                   |                      *|                   |*\n");
            printf("                              |-------------------|                      *|-------------------|*\n");
            printf("                                                                         ***********************\n");

        }

        else {

            printf("                                                                                                \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |     ���������     |                       |     ����������    | \n");
            printf("                              |                   |                       |                   | \n");
            printf("                              |-------------------|                       |-------------------| \n");
            printf("                                                                                                \n");

        }

} // ������� ��������� ����

int main (void) {

    Configure_Console_Window ();

    Class_Clients Client; // ������������� ������� Client
    Class_Settings Settings (Client); // ������������� ������� Settings

    bool FirstOrderCreated = false; // ���������� ��� ������� � ��� ��� ������ ����� ��� ������

        if (Settings.getAutomatic_Order_Start () == true)
            Menu_Formation_Order (Client, Settings, FirstOrderCreated);


    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����
    unsigned short int MenuItem = 1;

        while (true) {

                if (Settings.getAutomatic_Close_Application () == true && FirstOrderCreated == true)
                    return 0;

            cls ();
            CenterText ("�������� ����� ����, ��������� ������� ��������� �� ����������");
            Draw_Menu (MenuItem);

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("Esc", ButtonNumber))
                            return 0; // ����� �� ���������

                        if ((ClickCatch ("Arrow_Left", ButtonNumber)) || (ClickCatch ("Arrow_Right", ButtonNumber))) {

                                switch (MenuItem) {

                                    case 1: MenuItem = 2; break;
                                    case 2: MenuItem = 1; break;
                                    case 3: MenuItem = 4; break;
                                    case 4: MenuItem = 3; break;

                                }

                            break;

                        } // ��������� ������� ������� ������� ����� � ������

                        if ((ClickCatch ("Arrow_Up", ButtonNumber)) || (ClickCatch ("Arrow_Down", ButtonNumber))) {

                                switch (MenuItem) {

                                    case 1: MenuItem = 3; break;
                                    case 2: MenuItem = 4; break;
                                    case 3: MenuItem = 1; break;
                                    case 4: MenuItem = 2; break;

                                }

                            break;

                        } // ��������� ������� ������� ������� ����� � ����

                        if (ClickCatch ("Enter", ButtonNumber)) {

                            cls ();

                                switch (MenuItem) {

                                    case 1: CenterText ("�������� ������ ������\n");                Menu_Formation_Order (Client, Settings, FirstOrderCreated);     break;
                                    case 2: CenterText ("����� ������ ����� ��������� � ����\n");   Menu_Search_Tasks (Settings);                                   break;
                                    case 3: CenterText ("��������� ���������\n");                   Menu_Settings (Settings);                                       break;
                                    case 4: CenterText ("���������� �������\n");                    Menu_Statistics (Settings);                                     break;

                                }

                            break;

                        } // ��������� ������� Enter

                }

        } // ��������� ���� ��������

}
