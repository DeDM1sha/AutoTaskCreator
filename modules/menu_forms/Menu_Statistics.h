// ������ ��� ����������. ������ ����� ������ ���� ���������� ������ "����������".

#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const static void Menu_Statistics (const Class_Settings& Settings, const Class_BanLists& Banlists) {

    unsigned short int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����

        while (true) {

            cls ();
            CenterText ("���������� �������\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to update statistics");

            Class_Statistics Statistics (Settings);
            Statistics.Load_TotalNumber_Information (Settings);

            printf ("\n\n\n\n");
            printf ("                                       -----------------------------------------------\n");

            std::cout << "                                       | ���������� �������� � ����: " << std::setw (15);
            Show_Number_Output (Statistics.getTotalNumber_ClientsInDB_Count ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ����������� ������� � ����: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_CompletedTasks_Count ());
            std::cout << " | ���������� ����� ��� IDE Code::Blocks: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_IDE_CodeBlocks ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ����� �� C: " << std::setw (21);
            Show_Number_Output (Statistics.getTotalNumber_Technology_C ());
            std::cout << " | ���������� ����� ��� IDE Geany: " << std::setw (12);
            Show_Number_Output (Statistics.getTotalNumber_IDE_Geany ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ����� �� C++: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_CPlusPlus ());
            std::cout << " | ���������� ����� ��� IDE VisualStudio: " << std::setw (5);
            Show_Number_Output (Statistics.getTotalNumber_IDE_VisualStudio ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ������ �����: " << std::setw (19);
            Show_Number_Output (Statistics.getTotalNumber_Technology_Another ());
            std::cout << " | ���������� ����� ��� None IDE: " << std::setw (13);
            Show_Number_Output (Statistics.getTotalNumber_IDE_NoneIDE ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ��������������� ��������: " << std::setw (7);
            Show_Number_Output (Banlists.getTotalNumber_Clients_InBanList_Count ());
            std::cout << " | ���������� ����� ��� Windows: " << std::setw (14);
            Show_Number_Output (Statistics.getTotalNumber_OS_Windows ());
            std::cout << " |\n";

            printf ("               |----------------------------------------------|----------------------------------------------|\n");
            std::cout << "               | ���������� ��������������� ������������: " << std::setw (3);
            Show_Number_Output (Banlists.getTotalNumber_Workers_InBanList_Count ());
            std::cout << " | ���������� ����� ��� Linux / Mac: " << std::setw (10);
            Show_Number_Output (Statistics.getTotalNumber_OS_Linux ());
            std::cout << " |\n";

            printf ("               |______________________________________________|______________________________________________|\n");
            /*std::cout << "                                      | ���������� ��������������� ��������: " << std::setw (7);
            Show_Number_Output (Banlists.getTotalNumber_Clients_InBanList_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
            std::cout << "                                      | ���������� ��������������� ������������: " << std::setw (3);
            Show_Number_Output (Banlists.getTotalNumber_Workers_InBanList_Count ());
            std::cout << " |\n";

            printf ("                                      |----------------------------------------------|\n");
*/
                if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_Technology_C () + Statistics.getTotalNumber_Technology_CPlusPlus () + Statistics.getTotalNumber_Technology_Another ()))
                    Show_Text_Output ("\n                           ����� ���-�� ����������� ����� �� ��������� � ������ ����� �� �����������!");

                if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_IDE_CodeBlocks () + Statistics.getTotalNumber_IDE_Geany () + Statistics.getTotalNumber_IDE_VisualStudio () + Statistics.getTotalNumber_IDE_NoneIDE ()))
                    Show_Text_Output ("\n                           ����� ���-�� ����������� ����� �� ��������� � ������ ����� �� IDE!");

                if (Statistics.getTotalNumber_CompletedTasks_Count () != (Statistics.getTotalNumber_OS_Linux () + Statistics.getTotalNumber_OS_Windows ()))
                    Show_Text_Output ("\n                           ����� ���-�� ����������� ����� �� ��������� � ������ ����� �� OS !");


                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch (&ButtonNumber, "Esc, F5"))
                            break;

                }

                if (ClickCatch ("Esc", &ButtonNumber))
                    return;

                else if (ClickCatch ("F5", &ButtonNumber)) {

                    cls ();
                    CenterText ("���������� �������\n");
                    continue;

                }

        } // ����� ���������� ����� ���� ����������

} // ������� ���������� ���� ������� � ��������

#endif // _Menu_Statistics_h_
