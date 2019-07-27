// Модуль - хранилище всех дополнительных общих глобальных переменных и функций для проекта

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

//////////////////////////////////////////////////////////////////////////////

/* Глобальные общие переменные */

volatile unsigned int ButtonNumber = 0; // переменная для обработки нажатий в меню
bool FirstOrderCreated = false; // переменная для отметки о том что первый заказ был создан

//////////////////////////////////////////////////////////////////////////////

/* Глобальные общие функции */

const void Delay (const unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time);

} // функция задержки

const void Show_Text_Choise (const std::string Text) {

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

	std::cout << Text;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

} // функция для отображения выбранного решения другим цветом

const std::string Show_Text_Input (void) {

    const unsigned short int StrokeSize = 128;
    char Stroke [StrokeSize];

		for (unsigned short int i = 0; i < StrokeSize; i++)
            Stroke[i] = '\0'; // очистка строки от мусора

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 11));

    fflush (stdin); // очистка потока ввода
    fgets (Stroke, StrokeSize, stdin); // считываем всю строку с пробелами

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) ((0 << 4) | 10));

    std::string Str = std::string (Stroke); // инициализируем строку типа string, в нее закидываем всю строку Stroke

    Str.erase (Str.length () - 1, Str.length ()); // стираем всю оставшуюся ненужную часть строки (все табы, лишние пробелы)

    return Str;

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

const void Show_Text_ForExit (void) {

    printf ("                                                                                               Input Exit / Esc / !q for quit\n");

} // функция для отображения подсказки для выхода из меню

const std::string Convert_Int_toString (unsigned short int Number) {

    std::ostringstream ConverInt_ToString;
    ConverInt_ToString << Number;

    return std::string(ConverInt_ToString.str());

} // функция конвертирования из int в string

#endif // _additional_functions_h_
