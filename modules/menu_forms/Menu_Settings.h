// ������ ��� �������� ����������. ������ ����� ������ ���� ���������� ������ "���������".

#pragma once

#ifndef _Menu_Settings_h_
#define _Menu_Settings_h_

const static void Show_TextHeader (std::string MainText) {

    CenterText (MainText + "\n");
    CenterText ("��� ����� ������� Y (Yes) - ��� �������������\n");
    CenterText ("��� N (No) - ��� ������\n\n");
    CenterText ("��� �����: ");

} // ������� ��� ����������� ����� � ���������� ����

const static bool ChoisenAnswer_SetSettings (unsigned short int* ButtonNumber, bool OldParam) {

        while (true) {

            *ButtonNumber = getch ();

                if (ClickCatch (ButtonNumber, "Y, N, Esc"))
                    break;

        }

        if (ClickCatch ("Esc", ButtonNumber))
            return false; // ���� ��� ����� Esc, �� ����� ���������� ����������� ����� � �������� ���� ��������

        else if (ClickCatch ("Y", ButtonNumber)) {

            if (OldParam == true)
                return false;

            else
                OldParam = true;

        }

        else if (ClickCatch ("N", ButtonNumber)) {

            if (OldParam == false)
                return false;

            else
                OldParam = false;

        }

    return true; // � �������� ������, ����� ������� �������, ������������ ������� [Y] / [N]

} // ������� ��� �������� ������� ������� � ��������� ������ ���� �������� (�������� ��� ������� ��������� ��������)

const static bool ChoisenAnswer_SetParams (unsigned short int* ButtonNumber) {

        if (ClickCatch ("Y", ButtonNumber)) {

            Show_Text_Output ("Yes");
            return true;

        }

    Show_Text_Output ("No");

    return false;

} // ������� ��� �������� ������� ������� ��� ������ ������ [Y] / [N]

const static std::string InputAnswer_SetParams (const std::string& MainText, const std::string& SupportText) {

    std::string Str = "\0";
    CenterText (MainText + "\n");

        while (true) {

            printf ("\n");
            CenterText (SupportText + ": ");

            Str = Show_Text_Input (SupportText + ": ", false);

                if (Check_Input_ForExit (Str))
                    break;

               else if (Str.length () > 1)
                    break;

        } // ���������� �� ���� ����

    return Str;

} // ������� ��� ����� ������������ ���������� � ���� ��������

const static void Draw_MenuHeader (void) {

    cls ();

    CenterText ("��������� ���������\n");
    Show_Text_ForExit ();

    printf ("\n\n\n\n");

} // ������� ���������� ����� ���� ��������

const static void Menu_Settings (Class_Settings& Settings, Class_BanLists& Banlists) {

    std::string String_AutomaticCloseApplication = "\0";
    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����

        while (true) {

            Draw_MenuHeader ();

            CenterText ("�������� ������ �������� ���������� ����������� �������\n\n");

            CenterText ("|------------------------------------------|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 1.      ������ ������������ �������      |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 2.   ������ ������ ������� / ��������    |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 3.      ������ ���������� ��������       |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| 4.      ������ ���������� � ������       |\n");
            CenterText ("|__________________________________________|\n");
            CenterText ("|                                          |\n");
            CenterText ("| Tab. ������������ ��������� �� ��������� |\n");
            CenterText ("|__________________________________________|\n");

            CenterText ("\n�������� ����� ���� ��� ��������� ��������� ��������\n\n\n");

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, Tab"))
                            break;

                }

                    if (ClickCatch ("Esc", &ButtonNumber))
                        return;

                if (ClickCatch ("1", &ButtonNumber)) {

                    while (true) {

                        Draw_MenuHeader ();

                        CenterText ("������ �������� ������ ������������ �������\n\n");
                        printf ("                                   1. ���� � ����� �������� �������: ");
                        Show_Text_Output(Settings.getLabs_Path () + "\n");

                        printf ("                                   2. �������������� ������ �������� ������ ������: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Order_Start ()) + "\n");

                        printf ("                                   3. �������������� ���������� ����� ���������� ������: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Close_Application ()) + "\n");

                        printf ("                                   4. �������������� �������� ������ ����� ��� ��������: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Open_Order ()) + "\n");

                        printf ("\n                                 Tab. ������������ ��������� ������������ ������� �� ���������\n");

                            while (true) {

                                ButtonNumber = getch ();

                                    if (ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, Tab"))
                                        break;

                            }

                            if (ClickCatch ("Esc", &ButtonNumber))
                                break;

                        printf ("\n\n\n");

                            if (ClickCatch ("1", &ButtonNumber)) {

                                std::string Str = InputAnswer_SetParams ("������� ����� ���� � �������� �������", "����");

                                    if (Check_Input_ForExit (Str))
                                        continue;

                                    if (Settings.Check_FilePath (Str))
                                        Settings.setLabs_Path (Str);

                                    else
                                        continue;

                            } // ��������� ���� ����� �������� �������

                            else if (ClickCatch ("2", &ButtonNumber)) {

                                Show_TextHeader ("������� ������� �������� ��� ��������������� ������� ���� ������");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber, Settings.getAutomatic_Order_Start ()) == true) {

                                        Settings.setAutomatic_Order_Start (ChoisenAnswer_SetParams (&ButtonNumber));
                                        Settings.SaveSettings (true);

                                    }

                                    else
                                        continue;

                            } // ��������� ��������������� ������� ���� ������

                            else if (ClickCatch ("3", &ButtonNumber)) {

                                Show_TextHeader ("������� ������� �������� ��� ��������������� �������� ���������� ����� ���� ������");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber, Settings.getAutomatic_Close_Application ()) == true) {

                                        Settings.setAutomatic_Close_Application (ChoisenAnswer_SetParams (&ButtonNumber));
                                        Settings.SaveSettings (true);

                                    }

                                    else
                                        continue;

                            } // ��������� ��������������� �������� ���������� ����� ���� ������

                            else if (ClickCatch ("4", &ButtonNumber)) {

                                Show_TextHeader ("������� ������� �������� ��� ��������������� �������� ������ ����� ��� ��������");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber, Settings.getAutomatic_Open_Order ()) == true) {

                                        Settings.setAutomatic_Open_Order (ChoisenAnswer_SetParams (&ButtonNumber));
                                        Settings.SaveSettings (true);

                                    }

                                    else
                                        continue;

                            } // ���������/���������� ��������������� ������� ������ ����� ��� ��������

                            else if (ClickCatch ("Tab", &ButtonNumber)) {

                                Show_TextHeader ("�� ������������� ������ ������������ ��������� ������������ ������� �� ���������?");

                                    while (true) {

                                        ButtonNumber = getch ();

                                            if (ClickCatch ("Y", &ButtonNumber) || ClickCatch ("N", &ButtonNumber) || ClickCatch ("Esc", &ButtonNumber))
                                                    break;

                                    }

                                    if (ClickCatch ("Y", &ButtonNumber)) {

                                        Show_Text_Output ("Yes");
                                        Settings.SetDefaultParameters_FormationOrder ();
                                        Settings.SaveSettings (true);

                                    }

                                    else if (ClickCatch (&ButtonNumber, "N, Esc"))
                                        continue;

                            } // �������������� �� ��������� �������� ������������ �������

                    } // ����� ���������� ����� ���� �������� ������ ������������ ������

                } // ������ �������� ������ ������������ ������

                else if (ClickCatch ("2", &ButtonNumber)) {

                    while (true) {

                        Draw_MenuHeader ();
                        CenterText ("������ �������� ������ ������ ������� � ��������\n\n");

                    } // ����� ���������� ����� ���� �������� ������ ������ �������

                } // ������� �������� ������ ������ �������

                else if (ClickCatch ("3", &ButtonNumber)) {

                    while (true) {

                        CenterText ("������ �������� ������ ���������� ��������\n\n");
                        printf ("                                   1. �������������� ����������� ���������� ������ ���-�����: ");
                        Show_Text_Output (Convert_Bool_toString (Settings.getAutomatic_Update_BanList()) + "\n");

                        printf ("                                   2. �������� ����� ���-����� ��������: ");
                        Show_Text_Output (Settings.getUrl_BanList_Clients() + "\n");

                        printf ("                                   3. �������� ����� ���-����� ������������: ");
                        Show_Text_Output (Settings.getUrl_BanList_Workers() + "\n");

                        printf ("                                   4. �������� ������ ���-�����");
                        printf ("\n                                 Tab. ������������ ��������� ���������� �������� �� ���������\n");

                            while (true) {

                                ButtonNumber = getch ();

                                    if (ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, Tab"))
                                        break;

                            }

                            if (ClickCatch ("Esc", &ButtonNumber))
                                break;

                        printf ("\n\n\n");

                            if (ClickCatch ("1", &ButtonNumber)) {

                                Show_TextHeader ("������� ������� �������� ��� ��������������� ���������� ������ ���-�����");

                                    if (ChoisenAnswer_SetSettings (&ButtonNumber, Settings.getAutomatic_Update_BanList ()) == true) {

                                        Settings.setAutomatic_Update_BanList (ChoisenAnswer_SetParams (&ButtonNumber));
                                        Settings.SaveSettings (true);

                                    }

                                    else
                                        continue;

                            } // ��������� ��������������� ������������ ���������� ������ ���-�����

                            if (ClickCatch ("2", &ButtonNumber)) {

                                std::string Str = InputAnswer_SetParams ("������� ������ �� ���-������ ��������", "������");

                                    if (Check_Input_ForExit (Str))
                                        continue;

                                    else {

                                        Settings.setUrl_BanList_Clients (Str);
                                        Settings.SaveSettings (true);

                                    }

                            } // ��������� ���-������ ���-����� ��������

                            if (ClickCatch ("3", &ButtonNumber)) {

                                std::string Str = InputAnswer_SetParams ("������� ������ �� ���-������ ������������", "������");

                                    if (Check_Input_ForExit (Str))
                                        continue;

                                    else {

                                        Settings.setUrl_BanList_Workers (Str);
                                        Settings.SaveSettings (true);

                                    }

                            } // ��������� ���-������ ���-����� ������������

                            if (ClickCatch ("4", &ButtonNumber)) {

                                Show_TextHeader ("�� ������������� ������ �������� ������ ���-������?");

                                   // if ((ChoisenAnswer_SetSettings (&ButtonNumber) == true, false) && (ChoisenAnswer_SetParams (&ButtonNumber) == true)) {

                                     //       Banlists.Update_Banlists (Settings);
                                       //     Settings.SaveSettings (true);

                                    //}

                                    //else
                                        continue;

                            } // ���������� ������ ���-�����

                            else if (ClickCatch ("Tab", &ButtonNumber)) {

                                Settings.SetDefaultParameters_Banlists ();
                                Settings.SaveSettings (true);

                            } // �������������� �� ��������� �������� ������������ �������

                    } // ����� ���������� ����� ������ �������� ���������� �������

                 } // ������ �������� ������ ���������� ��������

                 else if (ClickCatch ("4", &ButtonNumber)) {

                    CenterText ("������ �������� ������ ���������� � ������ \n\n");

                    printf ("                                   6. ����������� ������������ �������: ");
                    Show_Text_Output (Convert_Bool_toString (Settings.getDisplay_Money ()) + "\n");

                } // ������ �������� ������ ����������
        /*
                    else if (ClickCatch ("5", &ButtonNumber)) {



                    } // ���������/���������� ������������ ���������� ������ ���-�����

                    else if (ClickCatch ("6", &ButtonNumber)) {

                        Show_TextHeader ("������� ������� �������� ��� ����������� ������������ �������");

                            if (ChoisenAnswer_SetSettings (&ButtonNumber) == true)
                                Settings.setDisplay_Money (ChoisenAnswer_SetParams (&ButtonNumber));

                            else
                                continue;

                    } // ���������/���������� ����������� ������������ �������

                    else if (ClickCatch ("7", &ButtonNumber)) {



                    } // ��������� ������ �� ������ ���-����� ��������

                    else if (ClickCatch ("8", &ButtonNumber)) {



                    } // ��������� ������ �� ������ ���-����� ������������

                    else if (ClickCatch ("9", &ButtonNumber)) {



                    } // �������� ������ ���-�����

                    else if (ClickCatch ("Tab", &ButtonNumber)) {

                        Show_TextHeader ("�� ������������� ������ ������������ ��� ��������� �� ���������?");

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
*/
                    } // ������� ��������� �� ���������

        //} // ����� ���������� ����� ���� ��������

} // ������� �������� ����������

#endif // _Menu_Settings_h_


