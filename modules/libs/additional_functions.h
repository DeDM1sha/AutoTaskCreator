/* ������-��������� ���� �������������� ����� ���������� ������� ��� �������

    ������ �� ���� ������������� �������� ������� �� ������� ����� � ������.
    ������������ �������� � main �����, � ������������ �� ���� �������

*/
#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

const static void Debug (std::string Text, bool Pause = true) {

    printf ("%s\n", Text.c_str()); // ����������� ������ ���������

        if (Pause) // ����� �� �������������, �� ��������� true
            system ("pause");

} // ������� ��� ������� ���� � ������

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

const static std::string Convert_Bool_toString (const bool& Boolean) {

    return Boolean ? "True" : "False";

} // ������� ����������� �� ���� bool � ��� std::string

const static void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // ������� ��������, ��� Time ����������� � ������������� (1000 �� - 1�)

const static void Show_Text_Output (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� ��� ����������� �������� ������ ������ ������

const static void Show_Number_Output (const unsigned short int& Number) {

    Show_Text_Output (Convert_Int_toString (Number));

} // ������� ��� ����������� ��������� ����� ������ ������

/*

//  ������ ���������� ��������� ������, ������� ����� ���������� � ������ ��������� ����
    ��� ���������� ������� ������������ ����� �� ����

//  ������ �������� �������� �� ��, ����� ������� ������ (������� ���������) - ������������ � ����� ������,
    �� ��������� ��������� ����� (������� ��� ����� ��������� ����-�������� ��� ������������ ��� �����)

*/
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

const static std::string String_DeleteSpaces (std::string Stroke) {

        if (Stroke[Stroke.length () - 1] == ' ' ||  Stroke[Stroke.length () - 1] == '\0') {

                std::string Temp = Stroke;
                Stroke = "\0";

                    for (unsigned short int i = 0; i < Temp.length () - 1; i++)
                        Stroke += Temp[i];

        } // �������� �������� � ����� ������

        if (Stroke[0] == ' ' || Stroke[0] == '\0') {

            std::string Temp = Stroke;
            Stroke = "\0";

                    for (unsigned short int i = 1; i < Temp.length (); i++)
                        Stroke += Temp[i];


        } // �������� �������� � ������ ������

    return Stroke;

} // ������� �������� �������� �� ������

const static void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\nError!!!\nReason: %s\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� Exception - ��� ����������� ����������� ������

/*

    ������������ �-�� ��� ��������� ��������� ����-����� ��� ����� ������. ����������:
        *true - � ������ ���� ���� ������� ����-����� (� ����� ������ Exit, ��� !q, ��� Esc)
        *false - ��������� ��� ��� ����

*/

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
            const std::string Normal_Esc_Symbols = "Esc";

                for (unsigned short int i = 0; i < Str.length (); i++) {

                    if (Str[i] == Small_Esc_Symbols[i] || Str[i] == Big_Esc_Symbols[i] || Str[i] == Normal_Esc_Symbols[i])
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
            const std::string Normal_Exit_Symbols = "Exit";

                for (unsigned short int i = 0; i < Str.length (); i++) {

                    if (Str[i] == Small_Exit_Symbols[i] || Str[i] == Big_Exit_Symbols[i] || Normal_Exit_Symbols[i])
                        Flag = true;

                    else {

                        Flag = false;
                        break;

                    }

                }

                if (Flag == false) { // ��� ��������� ����� Quit

                    const std::string Small_Quit_Symbols = "quit";
                    const std::string Big_Quit_Symbols = "QUIT";
                    const std::string Normal_Quit_Symbols = "Quit";

                        for (unsigned short int i = 0; i < Str.length (); i++) {

                            if (Str[i] == Small_Quit_Symbols[i] || Str[i] == Big_Quit_Symbols[i] || Str[i] == Normal_Quit_Symbols[i])
                                Flag = true;

                            else {

                                Flag = false;
                                break;

                            }

                        }

                }
            Exception("Flag = " + Convert_Bool_toString(Flag));
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

    NamesVector.push_back (String_DeleteSpaces(FirstName + " " + SecondName));
    NamesVector.push_back (String_DeleteSpaces(SecondName + " " + FirstName));

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

    ResultName = String_DeleteSpaces (ResultName);

    return ResultName;

} // �������, ������������ ������ ��� ������� � ������ �������� (��������� ����� �����/�������)

const static std::string CheckClientExist_ReturnTruthName (const std::string InputName, const Class_Settings& Settings) {

    bool Founded = false;

    std::ofstream Write (std::string (Settings.getLabs_Path () + "\\" + InputName + "\\CheckClient.txt").c_str ());

        if (Write.is_open ())
            Founded = true;

    Write.close ();

        if (Founded) {

            remove (std::string(Settings.getLabs_Path () + "\\" + InputName + "\\CheckClient.txt").c_str ());
            return InputName;

        }

    return Settings.getERROR_Message_ClientExist (); // ����������� ��������� �� ������ (�� ���������� ������ �������)

} // ������� ��� �������� ����������� ��������� ����� ������� (������ �� 3 ���������: 1-�� (��������), 2-�� (��������), 3-�� (������))

const static std::string GetExist_ClientName (std::string InputName, const Class_Settings& Settings, const bool CreateNewOrder = false) {

    InputName = ToUpper_FirstSymbols_ClientNames (InputName);

        if (CreateNewOrder == true)
            return InputName;

    std::vector <std::string> NamesVector = GetVector_ReverseNames (InputName);

        for (unsigned short int i = 0; i < NamesVector.size (); i++)
            NamesVector[i] = CheckClientExist_ReturnTruthName (NamesVector[i], Settings);

        if (NamesVector[0] == Settings.getERROR_Message_ClientExist () && NamesVector[1] == Settings.getERROR_Message_ClientExist ())
            return Settings.getERROR_Message_ClientExist ();

        else if (NamesVector[1] == Settings.getERROR_Message_ClientExist ())
            return NamesVector[0];

    return NamesVector[1];

} // ������� ��� ��������� ������������� ������� � ���� (���� ���-������� ����� � �������� �������, � ������ ������� ���������� - ������ �������� ���������)

const static std::string Get_DateToday (void) {

    const std::string PathFile_Date = "C:\\Windows\\Temp\\date.txt"; // ���� � ����� � ����������� �����
    std::string GetDate_Command = "date /T > " + PathFile_Date; // ������� ���������� ����

    system (GetDate_Command.c_str());
    std::string DateToday = "\0";

    std::ifstream Read (PathFile_Date.c_str());
    Read >> DateToday;
    Read.close ();

    remove (PathFile_Date.c_str());

    return DateToday;

} // ������� ��� ��������� ���� ������������ ���

#endif // _additional_functions_h_*/

