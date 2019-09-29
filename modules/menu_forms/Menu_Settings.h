// ������ ��� �������� ����������. ������ ����� ������ ���� ���������� ������ "���������".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

static std::string Convert_Bool_toString (const bool& Boolean) {

    if (Boolean)
        return "True";

    return "False";

} // ������� ����������� �� ���� bool � ��� std::string

static void Show_TextHeader (std::string MainText) {

    CenterText (MainText + "\n");
    CenterText ("��� ����� ������� Y (Yes) - ��� �������������\n");
    CenterText ("��� N (No) - ��� ������\n\n");
    CenterText ("��� �����: ");

} // ������� ��� ����������� ����� � ���������� ����

const void Menu_Settings (Class_Settings& Settings, Class_BanLists& Banlists) {

    std::string String_AutomaticCloseApplication = "\0";
    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����

    while (true) {

        cls ();

        CenterText ("��������� ���������\n");
        Show_Text_ForExit ();

        printf ("\n\n\n\n");
        CenterText ("�������� ����� ���� ��� ��������� ��������� ��������\n\n\n");
        printf ("                                   1. ���� � ����� �������� �������: ");
        Show_Text_Output(Settings.getLabs_Path () + "\n");

        printf ("                                   2. �������������� ������ �������� ������ ������: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Order_Start ()) + "\n");

        printf ("                                   3. �������������� ���������� ����� ���������� ������: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Close_Application ()) + "\n");

        printf ("                                   4. �������������� �������� ������ ����� ��� ��������: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Open_Order ()) + "\n");

        printf ("                                   5. �������������� ����������� ���������� ������ ���-�����: ");
        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Update_BanList()) + "\n");

        printf ("                                   6. �������� ����� ���-����� ��������: ");
        Show_Text_Output (Settings.getUrl_BanList_Clients() + "\n");

        printf ("                                   7. �������� ����� ���-����� ������������: ");
        Show_Text_Output (Settings.getUrl_BanList_Workers() + "\n");

        //printf ("                                   8. �������� ������ ���-�����");

        printf ("\n                                   Tab. ������������ ��������� �� ���������\n");

            while (true) {

                ButtonNumber = getch ();

                    if (ClickCatch ("Esc", &ButtonNumber) || ClickCatch ("1", &ButtonNumber) || ClickCatch ("2", &ButtonNumber) || ClickCatch ("3", &ButtonNumber) || ClickCatch ("4", &ButtonNumber) || ClickCatch ("5", &ButtonNumber) || ClickCatch ("6", &ButtonNumber) || ClickCatch ("7", &ButtonNumber) || ClickCatch ("Tab", &ButtonNumber))
                        break;

            }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

            printf ("\n\n\n");

                if (ClickCatch ("1", &ButtonNumber)) {

                    std::string Str = "\0";
                    CenterText ("������� ����� ���� � �������� �������");

                        while (true) {

                            printf ("\n");
                            CenterText ("����: ");

                            Str = Show_Text_Input ("����: ");

                                if (Check_Input_ForExit (Str))
                                    break;

                               else if (Str.length () > 1 && Settings.Check_FilePath (Str))
                                    break;

                        } // ���������� �� ���� ����

                        if (Check_Input_ForExit (Str))
                            continue;

                    Settings.setLabs_Path (Str);

                } // ��������� ���� ����� �������� �������

                else if (ClickCatch ("2", &ButtonNumber)) {

                    Show_TextHeader ("������� ������� �������� ��� ��������������� ������� ���� ������");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

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

                else if (ClickCatch ("3", &ButtonNumber)) {

                    Show_TextHeader ("������� ������� �������� ��� ��������������� �������� ���������� ����� ���� ������");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

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

                else if (ClickCatch ("4", &ButtonNumber)) {

                    Show_TextHeader ("������� ������� �������� ��� ��������������� �������� ������ ����� ��� ��������");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Open_Order (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Open_Order (false);

                                }

                        }

                        else
                            continue;

                } // ���������/���������� ��������������� ������� ������ ����� ��� ��������

                else if (ClickCatch ("5", &ButtonNumber)) {

                    Show_TextHeader ("������� ������� �������� ��� ��������������� ���������� ������ ���-�����");

                    while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber)) {

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Show_Text_Output ("Yes");
                                    Settings.setAutomatic_Update_BanList (true);

                                }

                                else {

                                    Show_Text_Output ("No");
                                    Settings.setAutomatic_Update_BanList (false);

                                }

                        }

                        else
                            continue;

                } // ���������/���������� ������������ ���������� ������ ���-�����

                else if (ClickCatch ("6", &ButtonNumber)) {

                    continue;


                } // ��������� ������ �� ������ ���-����� ��������

                else if (ClickCatch ("7", &ButtonNumber)) {

                    continue;

                } // ��������� ������ �� ������ ���-����� ������������

                /*else if (ClickCatch ("8", &ButtonNumber)) {

                        Show_TextHeader ("�� ������������� ������ �������� ������ ���-������?");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber)) {

                            Show_Text_Output ("Yes");

                            Banlists.Update_Banlists (Settings);

                        }

                        else if (ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                            continue;

                } // �������� ������ ���-�����*/

                else if (ClickCatch ("Tab", &ButtonNumber)) {

                    Show_TextHeader ("�� ������������� ������ ������������ ��������� �� ���������?");

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                        break;

                        }

                        if (ClickCatch ("Y", &ButtonNumber)) {

                            Show_Text_Output ("Yes");

                            Settings.ConfigFile_Open (Settings.getConfig_Path ());

                            remove (Settings.getConfig_Path().c_str());

                            Settings.SetDefault_Parameters ();

                            Settings.ConfigFile_Close (Settings.getConfig_Path ());

                        }

                        else if (ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                            continue;

                } // ������� ��������� �� ���������

            Settings.SaveSettings (true);

    } // ����� ���������� ����� ���� ��������

} // ������� �������� ����������

#endif // _Menu_Settings_h_
