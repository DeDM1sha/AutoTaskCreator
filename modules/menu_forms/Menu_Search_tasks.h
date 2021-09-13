// ������ ��� ������ ������. ������ ����� ������ ���� ���������� ������ "����� ������".

#pragma once

#ifndef _Menu_Search_tasks_h_
#define _Menu_Search_tasks_h_

const static void Menu_Search_Tasks (const Class_Settings& Settings) {

    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����
    Class_Search Searching;

        while (true) {

            cls ();
            CenterText ("����� ����� ����� ��������� � ����\n");
            Show_Text_ForExit ();

            printf ("\n\n\n");
            printf ("                                             ---------------------------------\n");
            CenterText ("|   1. ����� ������� �� �����   |\n");
            printf ("                                             |_______________________________|\n\n\n");

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, 1"))
                            break;

                }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

                else if (ClickCatch ("1", &ButtonNumber)) {

                        CenterText ("������� ���: ");
                        std::string ClientName = Show_Text_Input ("������� ���: ", true);
                        Searching.Search_Client(ClientName, Settings);

                } // ����� ������� �� �����

        }

} // ������� ������ ������ / ������� / �������

#endif // _Menu_Search_tasks_h_

