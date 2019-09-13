// Модуль-хранилище всех дополнительных общих глобальных функций для проекта

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

/* Глобальные общие функции */

const std::string Convert_Int_toString (unsigned short int Number) {

    std::ostringstream ConverInt_ToString;
    ConverInt_ToString << Number;

    return std::string(ConverInt_ToString.str());

} // функция конвертирования из int в string

const unsigned short int Convert_String_toInt (std::string Str) {

    unsigned short int Number = 0;

    std::stringstream ConvertString_toInt (Str);
    ConvertString_toInt >> Number;

    return Number;

} // функция конвертациии из string в int

const void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // функция задержки

const void Show_Text_Output (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция для отображения заданной строки другим цветом

const void Show_Number_Output (const unsigned short int& Number) {

    Show_Text_Output (Convert_Int_toString (Number));

} // функция для отображения заданного числа другим цветом

const std::string Show_Text_Input (std::string ErrorText) {

    const unsigned short int StrokeSize = 128;
    char Stroke [StrokeSize];

        while (true) {

                for (unsigned short int i = 0; i < StrokeSize; i++)
                    Stroke[i] = '\0'; // очистка строки от мусора

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

            fflush (stdin); // очистка потока ввода
            fgets (Stroke, StrokeSize, stdin); // считываем всю строку с пробелами

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

            std::string Str = std::string (Stroke); // инициализируем строку типа string, в нее закидываем всю строку Stroke

            Str.erase (Str.length () - 1, Str.length ()); // стираем всю оставшуюся ненужную часть строки (все табы, лишние пробелы)

                if (Str.length () > 0)
                    return Str;

                else
                    printf ("\n\n%s", ErrorText.c_str());

        }

} // функция для отображения вводимых данных другим цветом

const void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen (Text.c_str ()) / 2); i++)
            printf (" ");

    printf ("%s", Text.c_str());

} // функция центирования текста на экране

const void cls (void) {

    system ("cls");

} // функция очистки экрана

const void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\nError!!!\nReason: %s\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция Exception - для отображения случившихся ошибок

//////////////////////////////////////////////////////////////////////////////

const bool Check_Input_ForExit (const std::string& Str) {

        if (Str == "EXIT" || Str == "Exit" || Str == "exit" || Str == "ESC" || Str == "Esc" || Str == "esc" || Str == "!q")
            return true;

    return false;

} // функция для проверки ввода на строку выхода

const void Show_Text_In_Right_Corner (const std::string Str) {

    HANDLE hWndConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	unsigned short int ConsoleWidht = 0;

        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
			ConsoleWidht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;

        for (unsigned short int i = 0; i < ConsoleWidht - Str.length (); i++)
            printf (" ");

    std::cout << Str << "\n";

} // функция для отображения текста в правом углу

const void Show_Text_ForExit (void) {

    Show_Text_In_Right_Corner ("Input Exit / Esc / !q for quit");

} // функция для отображения подсказки для выхода из меню

#endif // _additional_functions_h_
