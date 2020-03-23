// ������-��������� ���� �������������� ����� ���������� ������� ��� �������

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

#include <string.h>
#include <cstring>

/* ���������� ����� ������� */

const static std::string Convert_Int_toString (unsigned short int Number) {

    std::ostringstream ConverInt_ToString;
    ConverInt_ToString << Number;

    return std::string(ConverInt_ToString.str());

} // ������� ��������������� �� int � string

const static unsigned short int Convert_String_toInt (std::string Str) {

    unsigned short int Number = 0;

    std::stringstream ConvertString_toInt (Str);
    ConvertString_toInt >> Number;

    return Number;

} // ������� ������������ �� string � int

const static void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // ������� ��������

const static void Show_Text_Output (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� ��� ����������� �������� ������ ������ ������

const static void Show_Number_Output (const unsigned short int& Number) {

    Show_Text_Output (Convert_Int_toString (Number));

} // ������� ��� ����������� ��������� ����� ������ ������

const static std::string Show_Text_Input (std::string ErrorText, const bool Show_ErrorText_AtStart) {

    const unsigned short int StrokeSize = 128;
    char Stroke [StrokeSize];
    std::string Str = "\0";

        if (Show_ErrorText_AtStart == true)
            printf ("\n\n%s", ErrorText.c_str());

        while (true) {

                for (unsigned short int i = 0; i < StrokeSize; i++)
                    Stroke[i] = '\0'; // ������� ������ �� ������

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

            fflush (stdin); // ������� ������ �����
            fgets (Stroke, StrokeSize, stdin); // ��������� ��� ������ � ���������

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

            std::string Temp = std::string (Stroke); // �������������� ������ ���� string, � ��� ���������� ��� ������ Stroke

            Temp.erase (Temp.length () - 1, Temp.length ()); // ������� ��� ���������� �������� ����� ������ (��� ����, ������ �������)

                if (Temp.length () > 0) {

                    Str = Temp;
                    break;

                }

                else
                    printf ("\n\n%s", ErrorText.c_str());

        }

    return Str;

} // ������� ��� ����������� �������� ������ ������ ������
  // * ������ ���������� ��������� ������, ������� ����� ���������� � ������ ��������� �����,
  // ��� ���������� ������� ������������ ����� �� ����
  // * ������ �������� �������� �� ��, ����� ������� ������ (������� ���������) - ������������ � ����� ������,
  // �� ��������� ��������� ����� (������� ��� ����� ��������� ����-�������� ��� ������������ ��� �����)

const static void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < (((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) >> 1) - (strlen (Text.c_str ()) >> 1)); ++i)
            printf (" ");

    printf ("%s", Text.c_str());

} // ������� ������������ ������ �� ������

const static void cls (void) {

    system ("cls");

} // ������� ������� ������

const static void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\nError!!!\nReason: %s\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� Exception - ��� ����������� ����������� ������

const static bool Check_Input_ForExit (const std::string& Str) {

    bool Flag = false;

        if (Str.length () == 2) { // ��� ���������� ����� !q

            if (Str[0] == '!')
                if (Str[1] == 'q' || Str[1] == 'Q')
                    return true;

        }

        else if (Str.length () == 3) { // ��� ���������� ����� Esc

            const std::string Small_Esc_Symbols = "esc";
            const std::string Big_Esc_Symbols = "ESC";

                for (unsigned short int i = 0; i < Str.length (); i++) {

                    if (Str[i] == Small_Esc_Symbols[i] || Str[i] == Big_Esc_Symbols[i])
                        Flag = true;

                    else {

                        Flag = false;
                        break;

                    }

                }

            return Flag;

        }

        else if (Str.length () == 4) { // ��� ���������� ����� Exit

            const std::string Small_Exit_Symbols = "exit";
            const std::string Big_Exit_Symbols = "EXIT";

                for (unsigned short int i = 0; i < Str.length (); i++) {

                    if (Str[i] == Small_Exit_Symbols[i] || Str[i] == Big_Exit_Symbols[i])
                        Flag = true;

                    else {

                        Flag = false;
                        break;

                    }

                }

                if (Flag == false) { // ��� ��������� ����� Quit

                    const std::string Small_Quit_Symbols = "quit";
                    const std::string Big_Quit_Symbols = "QUIT";

                        for (unsigned short int i = 0; i < Str.length (); i++) {

                            if (Str[i] == Small_Quit_Symbols[i] || Str[i] == Big_Quit_Symbols[i])
                                Flag = true;

                            else {

                                Flag = false;
                                break;

                            }

                        }

                }

            return Flag;

        }


    return false;

} // ������� ��� �������� ����� �� ������ ������

const static bool Check_Input_ForReload (const std::string& Str) {

        if (Str[0] == 'f' || Str[0] == 'F')
            if (Str[1] == '5')
                return true;

    return false;

} // ������� ��� �������� ����� �� ������ ������������

const static void Show_Text_In_Right_Corner (const std::string Str) {

    HANDLE hWndConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	unsigned short int ConsoleWidht = 0;

        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
			ConsoleWidht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;

        for (unsigned short int i = 0; i < ConsoleWidht - Str.length (); i++)
            printf (" ");

    std::cout << Str << "\n";

} // ������� ��� ����������� ������ � ������ ����

const static void Show_Text_ForExit (void) {

    Show_Text_In_Right_Corner ("Input \"Exit\" / \"Esc\" / \"!q\" for quit");

} // ������� ��� ����������� ��������� ��� ������ �� ����

const static bool IsNumber (const std::string& Str) {

        for (unsigned short int i = 0; i < Str.length(); i++) {

            if (Str[i] != 45) // �������� �� ���� �����
                if ((Str[i] < 48) || (Str[i] > 57))
                    return false;

        } // ���� � ������ ������ �������� ������� ������ ��� �����

    return true;

} // ������� �������� �������� �� ������ - ������

const static void GetNormal_Number_Value (unsigned short int *Count, std::string& Stroke, const std::string InputText, const short int LowerLimit, const short int UpperLimit) {

    while (true) {

        Stroke = Show_Text_Input (InputText, true);

            if (Check_Input_ForExit (Stroke) || Stroke == "f5" || Stroke == "F5")
                return;

            if (IsNumber (Stroke))
                *Count = Convert_String_toInt (Stroke);

            else
                continue;

            if (*Count > LowerLimit && *Count < UpperLimit)
                break;

    } // �������� �� ������ ��� ����� �����

} // ������� ��� ��������� �� ������������ ����������� ����� �����

const static std::vector <std::string> GetVector_ReverseNames (const std::string InputName) {

    std::vector <std::string> NamesVector;
    NamesVector.reserve (2);

    std::string FirstName = "\0";
    std::string SecondName = "\0";
    bool SpaceFounded = false;

        for (unsigned short int i = 0; i < InputName.length (); i++) {

            if (SpaceFounded == true)
                SecondName += InputName[i];

            else if (InputName[i] != ' ' && InputName[i] != '\0' && SpaceFounded == false)
                FirstName += InputName[i];

            else if (SpaceFounded == false)
                SpaceFounded = true;

        }

    NamesVector.push_back (FirstName + " " + SecondName);
    NamesVector.push_back (SecondName + " " + FirstName);

    return NamesVector;

} // ������� ��� ��������� ���� ��������� �������� ����� (�������) - ��������� � ������������

#include "../classes/settings_class.h"

const static std::string ToUpper_FirstSymbols_ClientNames (const std::string InputName) {

    const int CountRus_Letters = 33;
    const int CountEng_Letters = 26;

    char Rus_Small_Letters [CountRus_Letters] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'}; // �������� ����� ���������
    char Rus_Big_Letters [CountRus_Letters] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'}; // ��������� ����� ���������

    char Eng_Small_Letters [CountEng_Letters] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // �������� ����� ��������
    char Eng_Big_Letters [CountEng_Letters] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // ��������� ����� ��������

    std::string FirstName = "\0";
    std::string SecondName = "\0";
    bool Start = false;
    bool Flag = false;

        for (unsigned short int i = 0; i < InputName.length(); i++) {

            if (InputName[i] != ' ' && InputName[i] != '\0')
                Start = true;

            if (Start == true && (InputName[i] == ' ' || InputName[i] == '\0'))
                Flag = true;

            if (Start == true && !Flag && InputName[i] != ' ' && InputName[i] != '\0')
                FirstName += InputName[i];

            else if (Start == true && Flag && InputName[i] != ' ' && InputName[i] != '\0')
                SecondName += InputName[i];

        }

    bool Found_First = false;
    bool Found_Second = false;

        for (unsigned short int i = 0; i < CountRus_Letters; i++) {

            if (Found_First == true && Found_Second == true)
                break;

            if (Found_First == false)
                if (FirstName[0] == Rus_Small_Letters[i]) {

                    FirstName[0] = Rus_Big_Letters[i];
                    Found_First = true;

                }

            if (Found_Second == false)
                if (SecondName[0] == Rus_Small_Letters[i]) {

                    SecondName[0] = Rus_Big_Letters[i];
                    Found_Second = true;

                }

        }

        for (unsigned short int i = 0; i < CountEng_Letters; i++) {

            if (Found_First == true && Found_Second == true)
                break;

            if (Found_First == false)
                if (FirstName[0] == Eng_Small_Letters[i]) {

                    FirstName[0] = Eng_Big_Letters[i];
                    Found_First = true;

                }

            if (Found_Second == false)
                if (SecondName[0] == Eng_Small_Letters[i]) {

                    SecondName[0] = Eng_Big_Letters[i];
                    Found_Second = true;

                }

        }

    std::string ResultName = FirstName + " " + SecondName;

        if (ResultName[ResultName.length () - 1] == ' ' ||  ResultName[ResultName.length () - 1] == '\0') {

            std::string Temp = ResultName;
            ResultName = "\0";

                for (unsigned short int i = 0; i < Temp.length () - 1; i++)
                    ResultName += Temp[i];

        }

    return ResultName;

} // �������, ������������ ������ ��� ������� � ������ �������� (��������� ����� �����/�������)

const static std::string CheckClientExist_ReturnTruthName (const std::string InputName, const Class_Settings& Settings) {

    std::vector <std::string> NamesVector = GetVector_ReverseNames (InputName);

    bool Founded = false;
    bool Variant = false;

        for (unsigned short int i = 0; i < NamesVector.size (); i++) {

            std::ofstream Write (std::string (Settings.getLabs_Path () + "\\" + NamesVector[i] + "\\CheckClient.txt").c_str ());

                if (Write.is_open ()) {

                    Founded = true;

                        if (i == 1)
                            Variant = true;

                }

            Write.close ();

        }

        if (Founded) {

            remove (std::string(Settings.getLabs_Path () + "\\" + NamesVector[Variant] + "\\CheckClient.txt").c_str ());
            return NamesVector[Variant];

        }


    return Settings.getERROR_Message_ClientExist (); // ����������� ��������� �� ������ (�� ���������� ������ �������)

} // ������� ��� �������� ����������� ��������� ����� ������� (������ �� 3 ���������: 1-�� (��������), 2-�� (��������), 3-�� (������))

const static std::string GetExist_ClientName (std::string InputName, const Class_Settings& Settings) {

    InputName = ToUpper_FirstSymbols_ClientNames (InputName);
    const std::string TruthName = CheckClientExist_ReturnTruthName (InputName, Settings);

        if (TruthName == Settings.getERROR_Message_ClientExist ())
            return InputName;

    return TruthName;

} // ������� ��� ��������� ������������� ������� � ���� (���� ���-������� ����� � �������� �������, � ������ ������� ���������� - ������ �������� ���������)

#endif // _additional_functions_h_*/
