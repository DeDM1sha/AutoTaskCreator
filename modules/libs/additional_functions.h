// Модуль-хранилище всех дополнительных общих глобальных функций для проекта

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

/* Глобальные общие функции */

const static std::string Convert_Int_toString (unsigned short int Number) {

    std::ostringstream ConverInt_ToString;
    ConverInt_ToString << Number;

    return std::string(ConverInt_ToString.str());

} // функция конвертирования из int в string

const static unsigned short int Convert_String_toInt (std::string Str) {

    unsigned short int Number = 0;

    std::stringstream ConvertString_toInt (Str);
    ConvertString_toInt >> Number;

    return Number;

} // функция конвертациии из string в int

const static void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // функция задержки

const static void Show_Text_Output (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция для отображения заданной строки другим цветом

const static void Show_Number_Output (const unsigned short int& Number) {

    Show_Text_Output (Convert_Int_toString (Number));

} // функция для отображения заданного числа другим цветом

const static std::string Show_Text_Input (std::string ErrorText, const bool Show_ErrorText_AtStart) {

    const unsigned short int StrokeSize = 128;
    char Stroke [StrokeSize];
    std::string Str = "\0";

        if (Show_ErrorText_AtStart == true)
            printf ("\n\n%s", ErrorText.c_str());

        while (true) {

                for (unsigned short int i = 0; i < StrokeSize; i++)
                    Stroke[i] = '\0'; // очистка строки от мусора

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

            fflush (stdin); // очистка потока ввода
            fgets (Stroke, StrokeSize, stdin); // считываем всю строку с пробелами

            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

            std::string Temp = std::string (Stroke); // инициализируем строку типа string, в нее закидываем всю строку Stroke

            Temp.erase (Temp.length () - 1, Temp.length ()); // стираем всю оставшуюся ненужную часть строки (все табы, лишние пробелы)

                if (Temp.length () > 0) {

                    Str = Temp;
                    break;

                }

                else
                    printf ("\n\n%s", ErrorText.c_str());

        }

    return Str;

} // функция для отображения вводимых данных другим цветом
  // * первым аргументом выступает строка, которая будет выводиться в случае неверного ввода,
  // для повторного запуска бесконечного цикла на ввод
  // * второй аргумент отвечает за то, чтобы входная строка (первого аргумента) - отобразилась в самом начале,
  // не дожидаясь неверного ввода (задавая тем самым текстовое поле-описание для пользователя при вводе)

const static void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < (((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) >> 1) - (strlen (Text.c_str ()) >> 1)); ++i)
            printf (" ");

    printf ("%s", Text.c_str());

} // функция центирования текста на экране

const static void cls (void) {

    system ("cls");

} // функция очистки экрана

const static void Exception (const std::string TextError) {

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 12));

    printf ("\n\nError!!!\nReason: %s\n\n", TextError.c_str());
    system ("pause");

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция Exception - для отображения случившихся ошибок

const static bool Check_Input_ForExit (const std::string& Str) {

    bool Flag = false;

        if (Str.length () == 2) { // для служебного слова !q

            if (Str[0] == '!')
                if (Str[1] == 'q' || Str[1] == 'Q')
                    return true;

        }

        else if (Str.length () == 3) { // для служебного слова Esc

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

        else if (Str.length () == 4) { // для служебного слова Exit

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

                if (Flag == false) { // для запасного слова Quit

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

} // функция для проверки ввода на строку выхода

const static bool Check_Input_ForReload (const std::string& Str) {

        if (Str[0] == 'f' || Str[0] == 'F')
            if (Str[1] == '5')
                return true;

    return false;

} // функция для проверки ввода на строку перезагрузки

const static void Show_Text_In_Right_Corner (const std::string Str) {

    HANDLE hWndConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	unsigned short int ConsoleWidht = 0;

        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
			ConsoleWidht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;

        for (unsigned short int i = 0; i < ConsoleWidht - Str.length (); i++)
            printf (" ");

    std::cout << Str << "\n";

} // функция для отображения текста в правом углу

const static void Show_Text_ForExit (void) {

    Show_Text_In_Right_Corner ("Input \"Exit\" / \"Esc\" / \"!q\" for quit");

} // функция для отображения подсказки для выхода из меню

const static bool IsNumber (const std::string& Str) {

        for (unsigned short int i = 0; i < Str.length(); i++) {

            if (Str[i] != 45) // Проверка на знак минус
                if ((Str[i] < 48) || (Str[i] > 57))
                    return false;

        } // Если в строке только цифровые символы значит это число

    return true;

} // функция проверки является ли строка - числом

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

    } // проверка на дурака при вводе числа

} // функция для получения от пользователя корректного ввода числа

#endif // _additional_functions_h_
