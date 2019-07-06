// Модуль - хранилище всех дополнительных общих библиотек для проекта

#pragma once

#ifndef _additional_functions_h_
#define _additional_functions_h_

/*const void Delay (unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time) {};

} // функция задержки*/

const void CenterText (const std::string Text) {

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo ((GetStdHandle (STD_OUTPUT_HANDLE)), &consoleInfo);

        for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen (Text.c_str ()) / 2); i++)
            printf (" ");

    printf ("%s\n", Text.c_str());

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

#endif // _additional_functions_h_
