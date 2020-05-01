// ������ ��� ������������ ������. ������ ����� ������ ���� ���������� ������ "������� �����".

#pragma once

#ifndef _Menu_formation_order_h_
#define _Menu_formation_order_h_

const static bool Fill_InputData (Class_Clients& Client, const Class_BanLists& Banlists, const Class_Settings& Settings) {

	unsigned short int New_TasksCount = 0; // ���������� ���������� �� ��������� ���-�� ����� ������
	unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����

        while (true) {

            cls ();
            Client.Clear_Client_Parameters ();

            CenterText ("�������� ������ ������\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to reload formation order");

            std::string Stroke = Show_Text_Input ("��� �������:   ", true);

                if (Check_Input_ForExit (Stroke))
                    return false; // ���� ���� ������� ���� �� �������� ���� ��� ������ - ������� � ������� ���� ���������

                else if (Check_Input_ForReload (Stroke))
                    continue;

            Stroke = GetExist_ClientName (Stroke, Settings);

                if (Banlists.Check_Client_inBanlists (Stroke)) {

                    Exception ("This person in ban-list");
                    return false;

                }

            Client.setName (Stroke);

            std::cout << "\n\n����� ����������: C / C++ / Another (C / + / A) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("C", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_C ());
                            Show_Text_Output (Settings.getTechnology_Name_C ());
                            break;

                        }

                        else if (ClickCatch ("+", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_CPlusPlus ());
                            Show_Text_Output (Settings.getTechnology_Name_CPlusPlus ());
                            break;

                        }

                        else if (ClickCatch ("A", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_Another());
                            Show_Text_Output (Settings.getTechnology_Name_Another());
                            break;

                        }

                        else if (ClickCatch ("Esc", &ButtonNumber))
                            return false;

                        else if (ClickCatch ("F5", &ButtonNumber))
                            break;

                }

                if (ClickCatch ("F5", &ButtonNumber))
                    continue;

                if (Client.getTechnology_Name () != Settings.getTechnology_Name_Another()) {

                    std::cout << "\n\n\n����� IDE: Visual Studio / Geany / Code::Blocks (V / G / C) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("V", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_VisualStudio ());
                                    Show_Text_Output (Settings.getIDE_Name_VisualStudio ());
                                    break;

                                }

                                else if (ClickCatch ("G", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_Geany ());
                                    Show_Text_Output (Settings.getIDE_Name_Geany ());
                                    break;

                                }

                                else if (ClickCatch ("C", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_CodeBlocks ());
                                    Show_Text_Output (Settings.getIDE_Name_CodeBlocks ());
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\n����� ��: Linux / Windows (L / W) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("L", &ButtonNumber)) {

                                    Client.setOS_Name (Settings.getOS_Name_Linux ());
                                    Show_Text_Output (Settings.getOS_Name_Linux ());
                                    break;

                                }

                                else if (ClickCatch ("W", &ButtonNumber)) {

                                    Client.setOS_Name (Settings.getOS_Name_Windows ());
                                    Show_Text_Output (Settings.getOS_Name_Windows ());
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\n�������� ������� ���������� ��� ���������� ���� (Y / N) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Client.setMenuFunctional (true);
                                    Show_Text_Output ("Yes\n");
                                    break;

                                }

                                else if (ClickCatch ("N", &ButtonNumber)) {

                                    Client.setMenuFunctional (false);
                                    Show_Text_Output ("No\n");
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                }

                else {

                    printf ("\n");
                    Client.setOS_Name (Settings.getOS_Name_Windows ());
                    Client.setIDE_Name (Settings.getIDE_Name_NoneIDE ());

                }

            GetNormal_Number_Value (&New_TasksCount, Stroke, "���������� �������:   ", -1, 1000);

                if (Check_Input_ForReload (Stroke))
                    continue;

                if (Check_Input_ForExit (Stroke) || New_TasksCount == 0)
                    return false; // ���� ���� ������� ���� �� �������� ���� ��� ������ - ������� � ������� ���� ���������

            Client.setTasksCount (New_TasksCount);

                if (Client.getMenuFunctional () == true && Client.getTasksCount () == 1) {

                    unsigned short int Count_MenuItems = 0;

                    GetNormal_Number_Value (&Count_MenuItems, Stroke, "���������� ������� � ����:   ", -1, 100);

                        if (Check_Input_ForReload (Stroke))
                            continue;

                        if (Check_Input_ForExit (Stroke) || Count_MenuItems == 0)
                            return false;

                    Client.setMenuItems_Count (Count_MenuItems);

                    Client.Clear_MenuItems_Title ();

                    std::cout << "\n\n�������� � ������� ������ ����:\n";

                        for (unsigned short int i = 0; i < Count_MenuItems; i++) {

                            Stroke = Show_Text_Input (Convert_Int_toString (i + 1) + ")   ", true);

                                    if (Check_Input_ForReload (Stroke))
                                        break;

                                    if (Check_Input_ForExit (Stroke))
                                        return false;

                            Client.setMenuItems_Title (Stroke);

                        }

                        if (Check_Input_ForReload (Stroke))
                            continue;

                } // ���� � ��������� ����� ����, � ����� 1 ������ �� ������

            break;

        } // ����� ���������� ����� �������� ������

    return true;

} // ������� ���������� ������ �� �������

const static void Menu_Formation_Order (const Class_Settings& Settings, const Class_BanLists& Banlists, bool* FirstOrderCreated) {

    Show_Text_ForExit ();
    Class_Clients Client; // ������������� ������� Client
    Class_Formation_Order Order; // ������������� ������� Order

        if (!Fill_InputData (Client, Banlists, Settings)) // ���������� ������ �� ������
            return;

    Order.Create_NewOrder (Client, Settings);

        if (*FirstOrderCreated == false)
            *FirstOrderCreated = true;

} // ������� ������������ ������

#endif // _Menu_formation_order_h_
