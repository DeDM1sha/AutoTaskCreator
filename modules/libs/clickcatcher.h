/*  Данная библиотека позволяет упростить работу с функцией getch.
Автор: Сацук Михаил Михайлович (vk.com/m1shaowned)

При любом из доступных наборов входных параметров функция возвращает:
    *true - пользователь нажал на нужную нам кнопку, можно выполнять дальнейшие действия
    *false - была нажата любая другая кнопка, дальнейших действий не произойдет

//// Вызов функции с одинарным параметром названия входной кнопки (название желаемой кнопки + номер фактически нажатой клавиши)

//  Первый параметр функции отвечает за название нужной нам клавиши на клавиатуре, и имеет тип [std::string].
    Второй параметр отвечает за номер фактически нажатой клавиши, и имеет тип [unsigned short int]
    Предусмотрено написание названия клавиши в разных регистрах, но только на латинице.

        Пример вызова функции:

        ClickCatch ("Esc", &ButtonNumber);
            где "Esc" - название той клавиши нажатие на которой мы ждем,
            а "&ButtonNumber" фактический номер нажатой пользователем клавиши, полученный при помощи функции getch.

    Каждая из кнопок на клавиатуре имеет свое название, и оно представлено здесь в большинстве возможных вариациях

        Пример написания названия нужной клавиши:

        * "Esc" - и еще 3 вариации написания этого слова (esc, Esc, ESC)
        * "Delete" - и остальные 3 вариации (delete, Delete, DELETE)
        * "3" - и остальные 3 вариации (3, #, №)
        * и т.д.

//// Вызов функции с множеством параметров назавний входной кнопки (номер фактически нажатой клавиши + перечень названий нужных кнопок)

//  Первый параметр отвечает за номер фактически нажатой клавиши [unsigned short int]
    Второй параметр отвечает за ASCII номер клавиши, которые нам нужны [std::string]

        Пример вызова функции:

        ClickCatch (&ButtonNumber, "Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, Tab");
            где "&ButtonNumber" - фактический номер нажатой клавиши,
            а "Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, Tab" - будут зафиксированы все 11 наименований кнопок,
            с каждым из которых по отдельности будет сверен первый параметр
            По аналогии с вышеописаным, предусмотрены разные регистры написания одних и тех же названия кнопок,
            по 2-3 альтернативных варианта на каждую кнопку.

    Предусмотрены все возможные варианты нумерации каждой клавиши из всех возможных,
    включая и оба регистра, и оба языка для каждой клавиши - то бишь, взяв например отдельно взятую клавишу G -
    будет успешно обработано все 4 варианта кода этой клавиши, а именно:

        Пример написания названия нужной клавиши:

        * "п" - маленькая буква на кириллице
        * "П" - большая буква на кириллице
        * "g" - маленькая буква на латинице
        * "G" - большая буква на латинице.

    * Допускается любой порядок ввода аргумента

*/

#pragma once

#ifndef _clickcatcher_h_
#define _clickcatcher_h_

const bool ClickCatch (const std::string Button_Name, const unsigned short int* Button_Number) {

    /* Esc -> F12 */

		if ((Button_Name == "ESC" || Button_Name == "Esc" || Button_Name == "esc") && *Button_Number == 27)
			return true;

		else if ((Button_Name == "F1" || Button_Name == "f1") && (*Button_Number == 59 || *Button_Number == 84))
			return true;

		else if ((Button_Name == "F2" || Button_Name == "f2") && (*Button_Number == 60 || *Button_Number == 85))
			return true;

		else if ((Button_Name == "F3" || Button_Name == "f3") && (*Button_Number == 61 || *Button_Number == 86))
			return true;

		else if ((Button_Name == "F4" || Button_Name == "f4") && (*Button_Number == 62 || *Button_Number == 87))
			return true;

		else if ((Button_Name == "F5" || Button_Name == "f5") && (*Button_Number == 63 || *Button_Number == 88))
			return true;

		else if ((Button_Name == "F6" || Button_Name == "f6") && (*Button_Number == 64 || *Button_Number == 89))
			return true;

		else if ((Button_Name == "F7" || Button_Name == "f7") && (*Button_Number == 65 || *Button_Number == 90))
			return true;

		else if ((Button_Name == "F8" || Button_Name == "f8") && (*Button_Number == 66 || *Button_Number == 91))
			return true;

		else if ((Button_Name == "F9" || Button_Name == "f9") && (*Button_Number == 67 || *Button_Number == 92))
			return true;

		else if ((Button_Name == "F10" || Button_Name == "f10") && (*Button_Number == 68 || *Button_Number == 93))
			return true;

		else if ((Button_Name == "F11" || Button_Name == "f11") && (*Button_Number == 133 || *Button_Number == 135))
			return true;

		else if ((Button_Name == "F12" || Button_Name == "f12") && (*Button_Number == 134 || *Button_Number == 136))
			return true;

    /* Esc -> F12 */

    /* ~ -> - Page Up */

		else if ((Button_Name == "`" || Button_Name == "~") && (*Button_Number == 96 || *Button_Number == 126 || *Button_Number == 81 || *Button_Number == 1))
			return true;

		else if ((Button_Name == "1" || Button_Name == "!") && (*Button_Number == 49 || *Button_Number == 33))
			return true;

		else if ((Button_Name == "2" || Button_Name == "@" || Button_Name == "\"") && (*Button_Number == 50 || *Button_Number == 64 || *Button_Number == 34))
			return true;

		else if ((Button_Name == "3" || Button_Name == "#" || Button_Name == "№") && (*Button_Number == 51 || *Button_Number == 35 || *Button_Number == 22))
			return true;

		else if ((Button_Name == "4" || Button_Name == "$" || Button_Name == ";") && (*Button_Number == 52 || *Button_Number == 36 || *Button_Number == 59))
			return true;

		else if ((Button_Name == "5" || Button_Name == "%") && (*Button_Number == 53 || *Button_Number == 37))
			return true;

		else if ((Button_Name == "6" || Button_Name == "^" || Button_Name == ":") && (*Button_Number == 54 || *Button_Number == 94 || *Button_Number == 58))
			return true;

		else if ((Button_Name == "7" || Button_Name == "&" || Button_Name == "?") && (*Button_Number == 55 || *Button_Number == 38 || *Button_Number == 63))
			return true;

		else if ((Button_Name == "8" || Button_Name == "*") && (*Button_Number == 56 || *Button_Number == 42))
			return true;

		else if ((Button_Name == "9" || Button_Name == "(") && (*Button_Number == 57 || *Button_Number == 40))
			return true;

		else if ((Button_Name == "0" || Button_Name == ")") && (*Button_Number == 48 || *Button_Number == 41))
			return true;

		else if ((Button_Name == "-" || Button_Name == "_") && (*Button_Number == 45 || *Button_Number == 95))
			return true;

		else if ((Button_Name == "=" || Button_Name == "+") && (*Button_Number == 61 || *Button_Number == 43))
			return true;

		else if ((Button_Name == "BACKSPACE" || Button_Name == "BackSpace" || Button_Name == "backspace") && *Button_Number == 8)
			return true;

		else if ((Button_Name == "INSERT" || Button_Name == "Insert" || Button_Name == "insert" || Button_Name == "INS" || Button_Name == "ins") && *Button_Number == 82)
			return true;

		else if ((Button_Name == "HOME" || Button_Name == "Home" || Button_Name == "home") && *Button_Number == 71)
			return true;

		else if ((Button_Name == "PAGEUP" || Button_Name == "PAGE UP" || Button_Name == "PageUp" || Button_Name == "Page Up" || Button_Name == "pageup" || Button_Name == "page up") && *Button_Number == 73)
			return true;

    /* ~ -> Page Up */

    /* Tab -> Page Down */

		else if ((Button_Name == "TAB" || Button_Name == "Tab" || Button_Name == "tab") && *Button_Number == 9)
			return true;

		else if ((Button_Name == "Q" || Button_Name == "q") && (*Button_Number == 81 || *Button_Number == 113 || *Button_Number == 57 || *Button_Number == 25))
			return true;

		else if ((Button_Name == "W" || Button_Name == "w") && (*Button_Number == 87 || *Button_Number == 119 || *Button_Number == 70 || *Button_Number == 38))
			return true;

		else if ((Button_Name == "E" || Button_Name == "e") && (*Button_Number == 69 || *Button_Number == 101 || *Button_Number == 67 || *Button_Number == 35))
			return true;

		else if ((Button_Name == "R" || Button_Name == "r") && (*Button_Number == 82 || *Button_Number == 114 || *Button_Number == 58 || *Button_Number == 26))
			return true;

		else if ((Button_Name == "T" || Button_Name == "t") && (*Button_Number == 84 || *Button_Number == 116 || *Button_Number == 53 || *Button_Number == 21))
			return true;

		else if ((Button_Name == "Y" || Button_Name == "y") && (*Button_Number == 89 || *Button_Number == 121 || *Button_Number == 61 || *Button_Number == 29))
			return true;

		else if ((Button_Name == "U" || Button_Name == "u") && (*Button_Number == 85 || *Button_Number == 117 || *Button_Number == 51 || *Button_Number == 19))
			return true;

		else if ((Button_Name == "I" || Button_Name == "i") && (*Button_Number == 73 || *Button_Number == 105 || *Button_Number == 72 || *Button_Number == 40))
			return true;

		else if ((Button_Name == "O" || Button_Name == "o") && (*Button_Number == 79 || *Button_Number == 111 || *Button_Number == 73 || *Button_Number == 41))
			return true;

		else if ((Button_Name == "P" || Button_Name == "p") && (*Button_Number == 80 || *Button_Number == 112 || *Button_Number == 55 || *Button_Number == 23))
			return true;

		else if ((Button_Name == "{" || Button_Name == "[") && (*Button_Number == 123 || *Button_Number == 91 || *Button_Number == 69 || *Button_Number == 37))
			return true;

		else if ((Button_Name == "}" || Button_Name == "]") && (*Button_Number == 125 || *Button_Number == 93 || *Button_Number == 74 || *Button_Number == 42))
			return true;

		else if ((Button_Name == "|" || Button_Name == "\"" || Button_Name == "/") && (*Button_Number == 124 || *Button_Number == 92 || *Button_Number == 47))
			return true;

		else if ((Button_Name == "DELETE" || Button_Name == "Delete" || Button_Name == "delete" || Button_Name == "DEL" || Button_Name == "Del" || Button_Name == "del") && *Button_Number == 83)
			return true;

		else if ((Button_Name == "END" || Button_Name == "End" || Button_Name == "end") && *Button_Number == 79)
			return true;

		else if ((Button_Name == "PAGEDOWN" || Button_Name == "PAGE DOWN" || Button_Name == "PageDown" || Button_Name == "Page Down" || Button_Name == "pagedown" || Button_Name == "page down") && *Button_Number == 81)
			return true;

    /* Tab -> + Page Down */

    /* A -> Enter */

		else if ((Button_Name == "A" || Button_Name == "a") && (*Button_Number == 97 || *Button_Number == 65 || *Button_Number == 68 || *Button_Number == 36))
			return true;

		else if ((Button_Name == "S" || Button_Name == "s") && (*Button_Number == 115 || *Button_Number == 83 || *Button_Number == 75 || *Button_Number == 43))
			return true;

		else if ((Button_Name == "D" || Button_Name == "d") && (*Button_Number == 100 || *Button_Number == 68 || *Button_Number == 50 || *Button_Number == 18))
			return true;

		else if ((Button_Name == "F" || Button_Name == "f") && (*Button_Number == 102 || *Button_Number == 70 || *Button_Number == 48 || *Button_Number == 16))
			return true;

		else if ((Button_Name == "G" || Button_Name == "g") && (*Button_Number == 71 || *Button_Number == 103 || *Button_Number == 63 || *Button_Number == 31))
			return true;

		else if ((Button_Name == "H" || Button_Name == "h") && (*Button_Number == 72 || *Button_Number == 104 || *Button_Number == 64 || *Button_Number == 32))
			return true;

		else if ((Button_Name == "J" || Button_Name == "j") && (*Button_Number == 74 || *Button_Number == 106 || *Button_Number == 62 || *Button_Number == 30))
			return true;

		else if ((Button_Name == "K" || Button_Name == "k") && (*Button_Number == 75 || *Button_Number == 107 || *Button_Number == 59 || *Button_Number == 27))
			return true;

		else if ((Button_Name == "L" || Button_Name == "l") && (*Button_Number == 76 || *Button_Number == 108 || *Button_Number == 52 || *Button_Number == 20))
			return true;

		else if ((Button_Name == ":" || Button_Name == ";") && (*Button_Number == 58 || *Button_Number == 59 || *Button_Number == 198 || *Button_Number == 230))
			return true;

		else if ((Button_Name == "\"" || Button_Name == "\'") && (*Button_Number == 34 || *Button_Number == 39 || *Button_Number == 77 || *Button_Number == 45))
			return true;

		else if ((Button_Name == "ENTER" || Button_Name == "Enter" || Button_Name == "enter") && *Button_Number == 13)
			return true;

    /* A -> Enter */

    /* Z -> Arrow_Up */

		else if ((Button_Name == "Z" || Button_Name == "z") && (*Button_Number == 90 || *Button_Number == 122 || *Button_Number == 79 || *Button_Number == 47))
			return true;

		else if ((Button_Name == "X" || Button_Name == "x") && (*Button_Number == 88 || *Button_Number == 120 || *Button_Number == 71 || *Button_Number == 39))
			return true;

		else if ((Button_Name == "C" || Button_Name == "c") && (*Button_Number == 67 || *Button_Number == 99 || *Button_Number == 65 || *Button_Number == 33))
			return true;

		else if ((Button_Name == "V" || Button_Name == "v") && (*Button_Number == 86 || *Button_Number == 118 || *Button_Number == 60 || *Button_Number == 28))
			return true;

		else if ((Button_Name == "B" || Button_Name == "b") && (*Button_Number == 66 || *Button_Number == 98 || *Button_Number == 56 || *Button_Number == 24))
			return true;

		else if ((Button_Name == "N" || Button_Name == "n") && (*Button_Number == 78 || *Button_Number == 110 || *Button_Number == 66 || *Button_Number == 34))
			return true;

		else if ((Button_Name == "M" || Button_Name == "m") && (*Button_Number == 77 || *Button_Number == 109 || *Button_Number == 76 || *Button_Number == 44))
			return true;

		else if ((Button_Name == "<" || Button_Name == ",") && (*Button_Number == 60 || *Button_Number == 44 || *Button_Number == 49 || *Button_Number == 17))
			return true;

		else if ((Button_Name == ">" || Button_Name == ".") && (*Button_Number == 62 || *Button_Number == 46 || *Button_Number == 78 || *Button_Number == 46))
			return true;

		else if ((Button_Name == "?" || Button_Name == "/") && (*Button_Number == 63 || *Button_Number == 47 || *Button_Number == 44 || *Button_Number == 46))
			return true;

		else if ((Button_Name == "ARROW_UP" || Button_Name == "Arrow_Up" || Button_Name == "arror_up") && *Button_Number == 72)
			return true;

    /* Z -> Arrow_Up */

    /* Space -> Arrow_Right */

		else if ((Button_Name == "SPACE" || Button_Name == "Space" || Button_Name == "space") && *Button_Number == 32)
			return true;

		else if ((Button_Name == "ARROW_LEFT" || Button_Name == "Arrow_Left" || Button_Name == "arrow_left") && *Button_Number == 75)
			return true;

		else if ((Button_Name == "ARROW_DOWN" || Button_Name == "Arrow_Down" || Button_Name == "arrow_down") && *Button_Number == 80)
			return true;

		else if ((Button_Name == "ARROW_RIGHT" || Button_Name == "Arrow_Right" || Button_Name == "arrow_right") && *Button_Number == 77)
			return true;

    /* Space -> Arrow_Right */

    return false;

} // функция обработки нажатой и требуемой кнопки (одной)

const bool ClickCatch (const unsigned short int* Button_Number, const std::string Buttons_Massive_Name)  {

    std::vector <std::string> Buttons_Vector; // вектор входных строк-кнопок
    std::string Temp = "\0";

        for (unsigned short int i = 0; i < Buttons_Massive_Name.length (); i++) {

            if (Buttons_Massive_Name[i] == ',') {

                Buttons_Vector.push_back (Temp);
                Temp = "\0";

            }

            else if (Buttons_Massive_Name[i] != '\0' && Buttons_Massive_Name[i] != ' ')
                Temp += Buttons_Massive_Name[i];

        }

    Buttons_Vector.push_back (Temp);

        for (unsigned short int i = 0; i < Buttons_Vector.size (); i++)
            if (ClickCatch (Buttons_Vector[i], Button_Number) == true)
                return true;

    return false;

} // функция для массива входных кнопок

#endif // _clickcatcher_h_


