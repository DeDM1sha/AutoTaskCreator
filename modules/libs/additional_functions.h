// ������ - ��������� ���� �������������� ����� ���������� ���������� � ������� ��� �������

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

//////////////////////////////////////////////////////////////////////////////

/* ���������� ����� ���������� */

volatile unsigned int ButtonNumber = 0; // ���������� ��� ��������� ������� � ����
bool FirstOrderCreated = false; // ���������� ��� ������� � ��� ��� ������ ����� ��� ������

//////////////////////////////////////////////////////////////////////////////

/* ���������� ����� ������� */

const void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // ������� ��������

const void Show_Text_Output (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� ��� ����������� ���������� ������� ������ ������

const std::string Show_Text_Input (void) {

    const unsigned short int StrokeSize = 128;
    char Stroke [StrokeSize];

        while (true) {

                for (unsigned short int i = 0; i < StrokeSize; i++)
                    Stroke[i] = '\0'; // ������� ������ �� ������

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

            fflush (stdin); // ������� ������ �����
            fgets (Stroke, StrokeSize, stdin); // ��������� ��� ������ � ���������

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

            std::string Str = std::string (Stroke); // �������������� ������ ���� string, � ��� ���������� ��� ������ Stroke

            Str.erase (Str.length () - 1, Str.length ()); // ������� ��� ���������� �������� ����� ������ (��� ����, ������ �������)

                if (Str.length () > 0)
                    return Str;

                else
                    std::cout << "\n\n��� �������:   ";

        }

} // ������� ��� ����������� �������� ������ ������ ������

const void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen (Text.c_str ()) / 2); i++)
            printf (" ");

    printf ("%s", Text.c_str());

} // ������� ������������ ������ �� ������

const void cls (void) {

    system ("cls");

} // ������� ������� ������

const void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\nError!!!\nReason: %s\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // ������� Exception - ��� ����������� ����������� ������

//////////////////////////////////////////////////////////////////////////////

const bool Check_Input_ForExit (const std::string& Str) {

        if (Str == "EXIT" || Str == "Exit" || Str == "exit" || Str == "ESC" || Str == "Esc" || Str == "esc" || Str == "!q")
            return true;

    return false;

} // ������� ��� �������� ����� �� ������ ������

const void Show_Text_ForExit (void) {

    printf ("                                                                                               Input Exit / Esc / !q for quit\n");

} // ������� ��� ����������� ��������� ��� ������ �� ����

const std::string Convert_Int_toString (unsigned short int Number) {

    std::ostringstream ConverInt_ToString;
    ConverInt_ToString << Number;

    return std::string(ConverInt_ToString.str());

} // ������� ��������������� �� int � string

#endif // _additional_functions_h_
