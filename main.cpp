/* Project - AutoTaskCreator (ATC), by DeD_M1sha
==================================================================
������ ������ � ������������ ��� ������������� ������ � ������������ ��������, ������������� � �������� �� C / C++.
���������� ������� � �������� 2017 ����, � �� ��� ����.
������������ �������: Windows 10.
����� ����������: Code::Blocks.
���� ����������������: �������� - ������ C++, � �������������� ��, � ����� bat �������.
����������: MinGW (17.01)
�����������: http://github.com/dedm1sha/autotaskcreator.
�����: ����� ������ ���������� (vk.com/m1shaowned)

==================================================================
������ ������ �� ��������� ������:

    * ������
    * �������������� ���������� (���������, ��� ����������)
    * ���� (� ���������� �����������)
    * �������������� ������ � ���������������� �����

����� ��������������� ���������� ���� �� �����, �� ����������� �������� ����������, ������� ����� ������ ���� ��������
��� �������� �� ����� ����� � ������, �� ��� ���� ��� ������ ������ ���� �������������� ���� �����.

��������� �������� ������� �� ���� �����:
1) � ������� ������� ��������������� ���������� �������, �������� ���������� ������. ��� �������� � ������ ��������
�� �������� �����������, � ����� � �� ��������� ���������� ������ ��� ������ ������ ����������.

2) � �������������� ���������� ����������� ���������� ����� ���������� �������, ������������ � ������ �� ���� ����������.
��������� ������� �������� �������� �����������������, �.�. �� ����� ������������ � � ������ ���������� ��� �������� ����������.

3) � ������ ��������� ���������� 5 ����������� ����:

    % ������� ����
    % ���� �������� ������
    * ���� ������ ������
    * ���� ��������
    * ���� ����������

�� ����������� �������� ���� (�������������� ��������������� � main.cpp), ��� ����������� ������� � ��������� ������.
��������� �������� ������� ���� �������� � ��� ������ ��������������

4) �������������� ������ � ������� - ��������������� �����, ������� ������� ��������, cfg, ��������� ��������.

����������� ��������� ��������� ��������� ����� ���������� ����� ������, �� ����� ��� ����� ����� ���������.
������ ������ ����� ������������ �� �������������, ��������� ������������ ��� � ����������� ����� ������, ��� �
� ����� ������ ������ - �������� �����.

*/

// ������� ���� ����������, ��������� ���� � ������ ��������� ��������� ���� ����������� ���������/������� ��� �������

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

// ����������� ���� ����������� ����������� ��������� ��� �������

#include "modules/libs/clickcatcher.h" // ����������� ������ clickcatcher - ���������� ���������� �� ��������� ������� ������
#include "modules/libs/additional_functions.h" // ����������� ������ additional_functions - ���������� �������������� ����� �������

#include "modules/classes/settings_class.h" // ����������� settings_class - ����� �������� ����������
#include "modules/classes/clients_class.h" // �����������  clients_class - ����� ������ �� �������
#include "modules/classes/banlists_class.h" // ����������� banlist_class - ����� ���������� ��������
#include "modules/classes/statistics_class.h" // ����������� statistics_class - ����� ���� ������ ���� ������� � ��������
#include "modules/classes/search_class.h" // ����������� search_class - ����� ������ ��������, ������� � �.�.
#include "modules/classes/formation_order_class.h" // ����������� formation_order_class - ����� �������� ������ ������


#include "modules/menu_forms/Menu_Formation_order.h" // ����������� ������ Formation_order - ������ ������������ ������
#include "modules/menu_forms/Menu_Search_tasks.h" // ����������� ������ Search_tasks - ������ ������ ������ �� �������� ������
#include "modules/menu_forms/Menu_Settings.h" // ����������� ������ Menu_Settings - ������ �������� ����������
#include "modules/menu_forms/Menu_Statistics.h" // ���������� ������ Menu_Statistics - ������ ���������� �� ���� ������

// ����������� ���� ����������� ���������� ��������� � ������� ��� �������

const static void Configure_Console_Window (const Class_Settings& Settings) {

    void *handle = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo (handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo (handle, &structCursorInfo); // ���������� �������

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // ��������� ���������

    const std::string Title = "title AutoTaskCreator - " + Settings.getProjectBuild_Type () + " build (v" + Settings.getProjectBuild_Version () + ")";

    system ("color A");
    system ("mode con cols=125 lines=30"); // ��������� ���������� �������, ���������� �������� ������
    system (Title.c_str ()); // ��������� ��������� �������
    system ("@echo off"); // ������������ ������ ����������� ������ �� ������

} // ������� �������� ����������� ����

const static void Draw_Menu (const unsigned short int* MenuItem) {

    printf ("\n\n\n\n\n\n");

        if (*MenuItem == 1) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|   ������� �����   |*                      |    ����� �����    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");

        }

        else if (*MenuItem == 2) {

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

        if (*MenuItem == 3) {

            printf("                             ***********************                                            \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|     ���������     |*                      |     ����������    | \n");
            printf("                             *|                   |*                      |                   | \n");
            printf("                             *|-------------------|*                      |-------------------| \n");
            printf("                             ***********************                                            \n");


        }

        else if (*MenuItem == 4) {

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

    Class_Settings Settings; // ������������� ������� Settings
    Class_BanLists Banlists (Settings); // ������������� ������� Banlist;

    Configure_Console_Window (Settings);

    bool FirstOrderCreated = false; // ���������� ��� ������� � ��� ��� ������ ����� ��� ������

        if (Settings.getAutomatic_Order_Start () == true)
            Menu_Formation_Order (Settings, Banlists, &FirstOrderCreated);

    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����
    unsigned short int MenuItem = 1; // ��������� ����� � ����

        while (true) {

                if (Settings.getAutomatic_Close_Application () == true && FirstOrderCreated == true)
                    return 0;

            cls ();
            CenterText ("�������� ����� ����, ��������� ������� ��������� �� ���������� (Esc - �����)");
            Draw_Menu (&MenuItem);

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("Esc", &ButtonNumber))
                            return 0; // ����� �� ���������

                        if (ClickCatch (&ButtonNumber, "Arrow_Left, Arrow_Right")) {

                                switch (MenuItem) {

                                    case 1: ++MenuItem; break;
                                    case 2: --MenuItem; break;
                                    case 3: ++MenuItem; break;
                                    case 4: --MenuItem; break;

                                }

                            break;

                        } // ��������� ������� ������� ������� ����� � ������

                        if (ClickCatch (&ButtonNumber, "Arrow_Up, Arrow_Down")) {

                                switch (MenuItem) {

                                    case 1: ++(++MenuItem);             break;
                                    case 2: MenuItem = MenuItem << 1;   break;
                                    case 3: --(--MenuItem);             break;
                                    case 4: MenuItem = MenuItem >> 1;   break;

                                }

                            break;

                        } // ��������� ������� ������� ������� ����� � ����

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

                        } // ��������� ������� Enter

                }

        } // ��������� ���� ��������

}
