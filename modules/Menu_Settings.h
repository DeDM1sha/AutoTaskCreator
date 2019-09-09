// ������ ��� �������� ����������. ������ ����� ������ ���� ���������� ������ "���������".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const void Menu_Settings (Class_Settings& Settings) {

    std::string String_AutomaticOrderStart = "\0";
    std::string String_AutomaticCloseApplication = "\0";

    while (true) {

        cls ();

        Show_Text_ForExit ();

        printf ("\n\n\n\n\n\n\n");
        CenterText ("�������� ����� ���� ��� ��������� ��������� ��������\n\n\n");
        printf ("%s%s\n", "                                     1. ���� � ����� �������� �������: ", Settings.getLabs_Path ().c_str ());

            if (Settings.getAutomatic_Order_Start () == true)
                String_AutomaticOrderStart = "True";

            else
                String_AutomaticOrderStart = "False";

        printf ("%s%s\n", "                                     2. �������������� ������ ������ ������: ", String_AutomaticOrderStart.c_str ());

            if (Settings.getAutomatic_Close_Application () == true)
                String_AutomaticCloseApplication = "True";

            else
                String_AutomaticCloseApplication = "False";

        printf ("%s%s\n", "                                     3. �������������� �������� ����� ���������� ������: ", String_AutomaticCloseApplication.c_str ());
        printf ("                                     4. ������������ ��������� �� ���������\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", ButtonNumber) || ClickCatch ("1", ButtonNumber) || ClickCatch ("2", ButtonNumber) || (ClickCatch ("3", ButtonNumber)) || (ClickCatch ("4", ButtonNumber)))
                        break;

            }

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", ButtonNumber)) {

                    std::string Str = "\0";
                    std::string TestFilePath = "\0";
                    CenterText ("������� ����� ���� � �������� �������");

                        while (true) {

                            printf ("\n");
                            CenterText ("����: ");

                            Str = Show_Text_Input ();

                                if (Check_Input_ForExit (Str))
                                    break;

                            TestFilePath = Str + "\\ValidTest.txt";
                            std::ofstream Write (TestFilePath.c_str ());

                                if (!Write.is_open() || Str.length () < 2)
                                    CenterText ("Error! Not valid path\n\n");

                                else
                                    break;

                            Write.close ();

                        } // ���������� �� ���� ����

                        if (Check_Input_ForExit (Str))
                            continue;

                    remove (TestFilePath.c_str ());
                    Settings.setLabs_Path (Str);

                } // ��������� ���� ����� �������� �������

                else if (ClickCatch ("2", ButtonNumber)) {

                    CenterText ("������� ������� �������� ��� ��������������� ������� ���� ������\n");
                    CenterText ("��� ����� ������� Y (Yes) - ��� ���������\n");
                    CenterText ("��� N (No) - ��� ����������\n\n");
                    CenterText ("��� �����: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber)) {

                                if (ClickCatch ("Y", ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Order_Start (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Order_Start (false);

                                }

                        }

                        else
                            continue;

                } // ��������� ��������������� ������� ���� ������

                else if (ClickCatch ("3", ButtonNumber)) {

                    CenterText ("������� ������� �������� ��� ��������������� �������� ���������� ����� ���� ������\n");
                    CenterText ("��� ����� ������� Y (Yes) - ��� ���������\n");
                    CenterText ("��� N (No) - ��� ����������\n\n");
                    CenterText ("��� �����: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber)) {

                                if (ClickCatch ("Y", ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Close_Application (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Close_Application (false);

                                }

                        }

                        else
                            continue;

                } // ��������� ��������������� �������� ���������� ����� ���� ������

                else if (ClickCatch ("4", ButtonNumber)) {

                    CenterText ("�� ������������� ������ ������������ ��������� �� ���������?\n");
                    CenterText ("��� ����� ������� Y (Yes) - ��� ��������������\n");
                    CenterText ("��� N (No) - ��� ������ ��������������\n\n");
                    CenterText ("��� �����: ");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", ButtonNumber) || ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", ButtonNumber)) {

                            Show_Text_Output ("Yes");

                            remove (Settings.getConfig_Path().c_str());

                            Settings.SetDefault_Parameters ();

                        }

                        else if (ClickCatch ("N", ButtonNumber) || ClickCatch ("Esc", ButtonNumber))
                            continue;

                } // ������� ��������� �� ���������

            Settings.SaveSettings (true);

    } // ����� ���������� ����� ���� ��������

} // ������� �������� ����������

#endif // _Menu_Settings_h_
