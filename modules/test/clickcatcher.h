// Данная библиотека позволяет упростить работу с функцией getch, путем отправки в данную функцию названия желаемой нажатой пользователм кнопки, и номером этой конпки.
// Первый параметр функции отвечает за название нужной нам клавиши на клавиатуре, и имеет тип string. Предусмотрено написание названия клавиши в разных регистрах, но только на английском языке.
// Второй параметр функции отвечает за ASCII номер клавиши, и имеет тип int. Предусмотрены все возможные варианты нумерации каждой клавиши из всех возможных (включая и оба регистра, и оба языка для каждой клавиши). Сюда следует отправлять значение, полученное функцией getch в основной программе.

#pragma once

#ifndef _clickcatcher_H_
#define _clickcatcher_H_


bool ClickCatch (std::string ButtonName, unsigned short int ButtonNumber) {

    /* Esc -> F12 */

    if ((ButtonName == "ESC" || ButtonName == "Esc" || ButtonName == "esc") && ButtonNumber == 27)
        return true;

    if ((ButtonName == "F1" || ButtonName == "f1") && (ButtonNumber == 59 || ButtonNumber == 84))
        return true;

    if ((ButtonName == "F2" || ButtonName == "f2") && (ButtonNumber == 60 || ButtonNumber == 85))
        return true;

    if ((ButtonName == "F3" || ButtonName == "f3") && (ButtonNumber == 61 || ButtonNumber == 86))
        return true;

    if ((ButtonName == "F4" || ButtonName == "f4") && (ButtonNumber == 62 || ButtonNumber == 87))
        return true;

    if ((ButtonName == "F5" || ButtonName == "f5") && (ButtonNumber == 63 || ButtonNumber == 88))
        return true;

    if ((ButtonName == "F6" || ButtonName == "f6") && (ButtonNumber == 64 || ButtonNumber == 89))
        return true;

    if ((ButtonName == "F7" || ButtonName == "f7") && (ButtonNumber == 65 || ButtonNumber == 90))
        return true;

    if ((ButtonName == "F8" || ButtonName == "f8") && (ButtonNumber == 66 || ButtonNumber == 91))
        return true;

    if ((ButtonName == "F9" || ButtonName == "f9") && (ButtonNumber == 67 || ButtonNumber == 92))
        return true;

    if ((ButtonName == "F10" || ButtonName == "f10") && (ButtonNumber == 68 || ButtonNumber == 93))
        return true;

    if ((ButtonName == "F11" || ButtonName == "f11") && (ButtonNumber == 133 || ButtonNumber == 135))
        return true;

    if ((ButtonName == "F12" || ButtonName == "f12") && (ButtonNumber == 134 || ButtonNumber == 136))
        return true;

    /* Esc -> F12 */

    /* ~ -> - Page Up */

    if ((ButtonName == "`" || ButtonName == "~") && (ButtonNumber == 96 || ButtonNumber == 126 || ButtonNumber == 184 || ButtonNumber == 168))
        return true;

    if ((ButtonName == "1" || ButtonName == "!") && (ButtonNumber == 49 || ButtonNumber == 33))
        return true;

    if ((ButtonName == "2" || ButtonName == "@" || ButtonName == "\"") && (ButtonNumber == 50 || ButtonNumber == 64 || ButtonNumber == 34))
        return true;

    if ((ButtonName == "3" || ButtonName == "#" || ButtonName == "№") && (ButtonNumber == 51 || ButtonNumber == 35 || ButtonNumber == 185))
        return true;

    if ((ButtonName == "4" || ButtonName == "$" || ButtonName == ";") && (ButtonNumber == 52 || ButtonNumber == 36 || ButtonNumber == 59))
        return true;

    if ((ButtonName == "5" || ButtonName == "%") && (ButtonNumber == 53 || ButtonNumber == 37))
        return true;

    if ((ButtonName == "6" || ButtonName == "^" || ButtonName == ":") && (ButtonNumber == 54 || ButtonNumber == 94 || ButtonNumber == 58))
        return true;

    if ((ButtonName == "7" || ButtonName == "&" || ButtonName == "?") && (ButtonNumber == 55 || ButtonNumber == 38 || ButtonNumber == 63))
        return true;

    if ((ButtonName == "8" || ButtonName == "*") && (ButtonNumber == 56 || ButtonNumber == 42))
        return true;

    if ((ButtonName == "9" || ButtonName == "(") && (ButtonNumber == 57 || ButtonNumber == 42))
        return true;

    if ((ButtonName == "0" || ButtonName == ")") && (ButtonNumber == 48 || ButtonNumber == 41))
        return true;

    if ((ButtonName == "-" || ButtonName == "_") && (ButtonNumber == 45 || ButtonNumber == 95))
        return true;

    if ((ButtonName == "=" || ButtonName == "+") && (ButtonNumber == 61 || ButtonNumber == 43))
        return true;

    if ((ButtonName == "BACKSPACE" || ButtonName == "BackSpace" || ButtonName == "backspace") && ButtonNumber == 8)
        return true;

    if ((ButtonName == "INSERT" || ButtonName == "Insert" || ButtonName == "insert" || ButtonName == "INS" || ButtonName == "ins") && ButtonNumber == 82)
        return true;

    if ((ButtonName == "HOME" || ButtonName == "Home" || ButtonName == "home") && ButtonNumber == 71)
        return true;

    if ((ButtonName == "PAGEUP" || ButtonName == "PAGE UP" || ButtonName == "PageUp" || ButtonName == "Page Up" || ButtonName == "pageup" || ButtonName == "page up") && ButtonNumber == 73)
        return true;

    /* ~ -> Page Up */

    /* Tab -> Page Down */

    if ((ButtonName == "TAB" || ButtonName == "Tab" || ButtonName == "tab") && ButtonNumber == 9)
        return true;

    if ((ButtonName == "Q" || ButtonName == "q") && (ButtonNumber == 81 || ButtonNumber == 113 || ButtonNumber == 201 || ButtonNumber == 233))
        return true;

    if ((ButtonName == "W" || ButtonName == "w") && (ButtonNumber == 87 || ButtonNumber == 119 || ButtonNumber == 214 || ButtonNumber == 246))
        return true;

    if ((ButtonName == "E" || ButtonName == "e") && (ButtonNumber == 69 || ButtonNumber == 101 || ButtonNumber == 211 || ButtonNumber == 243))
        return true;

    if ((ButtonName == "R" || ButtonName == "r") && (ButtonNumber == 82 || ButtonNumber == 114 || ButtonNumber == 202 || ButtonNumber == 234))
        return true;

    if ((ButtonName == "T" || ButtonName == "t") && (ButtonNumber == 84 || ButtonNumber == 116 || ButtonNumber == 197 || ButtonNumber == 229))
        return true;

    if ((ButtonName == "Y" || ButtonName == "y") && (ButtonNumber == 89 || ButtonNumber == 121 || ButtonNumber == 205 || ButtonNumber == 237))
        return true;

    if ((ButtonName == "U" || ButtonName == "u") && (ButtonNumber == 85 || ButtonNumber == 117 || ButtonNumber == 195 || ButtonNumber == 227))
        return true;

    if ((ButtonName == "I" || ButtonName == "i") && (ButtonNumber == 73 || ButtonNumber == 105 || ButtonNumber == 216 || ButtonNumber == 248))
        return true;

    if ((ButtonName == "O" || ButtonName == "o") && (ButtonNumber == 79 || ButtonNumber == 111 || ButtonNumber == 217 || ButtonNumber == 249))
        return true;

    if ((ButtonName == "P" || ButtonName == "p") && (ButtonNumber == 80 || ButtonNumber == 112 || ButtonNumber == 199 || ButtonNumber == 231))
        return true;

    if ((ButtonName == "{" || ButtonName == "[") && (ButtonNumber == 123 || ButtonNumber == 91 || ButtonNumber == 213 || ButtonNumber == 245))
        return true;

    if ((ButtonName == "}" || ButtonName == "]") && (ButtonNumber == 125 || ButtonNumber == 93 || ButtonNumber == 218 || ButtonNumber == 250))
        return true;

    if ((ButtonName == "|" || ButtonName == "\"" || ButtonName == "/") && (ButtonNumber == 124 || ButtonNumber == 92 || ButtonNumber == 47))
        return true;

    if ((ButtonName == "DELETE" || ButtonName == "Delete" || ButtonName == "delete" || ButtonName == "DEL" || ButtonName == "Del" || ButtonName == "del") && ButtonNumber == 83)
        return true;

    if ((ButtonName == "END" || ButtonName == "End" || ButtonName == "end") && ButtonNumber == 79)
        return true;

    if ((ButtonName == "PAGEDOWN" || ButtonName == "PAGE DOWN" || ButtonName == "PageDown" || ButtonName == "Page Down" || ButtonName == "pagedown" || ButtonName == "page down") && ButtonNumber == 81)
        return true;

    /* Tab -> + Page Down */

    /* A -> Enter */

    if ((ButtonName == "A" || ButtonName == "a") && (ButtonNumber == 97 || ButtonNumber == 65 || ButtonNumber == 244 || ButtonNumber == 212))
        return true;

    if ((ButtonName == "S" || ButtonName == "s") && (ButtonNumber == 115 || ButtonNumber == 83 || ButtonNumber == 251 || ButtonNumber == 219))
        return true;

    if ((ButtonName == "D" || ButtonName == "d") && (ButtonNumber == 100 || ButtonNumber == 68 || ButtonNumber == 226 || ButtonNumber == 194))
        return true;

    if ((ButtonName == "F" || ButtonName == "f") && (ButtonNumber == 102 || ButtonNumber == 70 || ButtonNumber == 224 || ButtonNumber == 192))
        return true;

    if ((ButtonName == "G" || ButtonName == "g") && (ButtonNumber == 71 || ButtonNumber == 103 || ButtonNumber == 207 || ButtonNumber == 239))
        return true;

    if ((ButtonName == "H" || ButtonName == "h") && (ButtonNumber == 72 || ButtonNumber == 104 || ButtonNumber == 208 || ButtonNumber == 240))
        return true;

    if ((ButtonName == "J" || ButtonName == "j") && (ButtonNumber == 74 || ButtonNumber == 106 || ButtonNumber == 206 || ButtonNumber == 238))
        return true;

    if ((ButtonName == "K" || ButtonName == "k") && (ButtonNumber == 75 || ButtonNumber == 107 || ButtonNumber == 203 || ButtonNumber == 235))
        return true;

    if ((ButtonName == "L" || ButtonName == "l") && (ButtonNumber == 76 || ButtonNumber == 108 || ButtonNumber == 196 || ButtonNumber == 228))
        return true;

    if ((ButtonName == ":" || ButtonName == ";") && (ButtonNumber == 58 || ButtonNumber == 59 || ButtonNumber == 198 || ButtonNumber == 230))
        return true;

    if ((ButtonName == "\"" || ButtonName == "\'") && (ButtonNumber == 34 || ButtonNumber == 39 || ButtonNumber == 221 || ButtonNumber == 253))
        return true;

    if ((ButtonName == "ENTER" || ButtonName == "Enter" || ButtonName == "enter") && ButtonNumber == 13)
        return true;

    /* A -> Enter */

    /* Z -> Arrow_Up */

    if ((ButtonName == "Z" || ButtonName == "z") && (ButtonNumber == 90 || ButtonNumber == 122 || ButtonNumber == 223 || ButtonNumber == 255))
        return true;

    if ((ButtonName == "X" || ButtonName == "x") && (ButtonNumber == 88 || ButtonNumber == 120 || ButtonNumber == 215 || ButtonNumber == 247))
        return true;

    if ((ButtonName == "C" || ButtonName == "c") && (ButtonNumber == 67 || ButtonNumber == 99 || ButtonNumber == 209 || ButtonNumber == 241))
        return true;

    if ((ButtonName == "V" || ButtonName == "v") && (ButtonNumber == 86 || ButtonNumber == 118 || ButtonNumber == 204 || ButtonNumber == 236))
        return true;

    if ((ButtonName == "B" || ButtonName == "b") && (ButtonNumber == 66 || ButtonNumber == 98 || ButtonNumber == 200 || ButtonNumber == 232))
        return true;

    if ((ButtonName == "N" || ButtonName == "n") && (ButtonNumber == 78 || ButtonNumber == 110 || ButtonNumber == 210 || ButtonNumber == 242))
        return true;

    if ((ButtonName == "M" || ButtonName == "m") && (ButtonNumber == 77 || ButtonNumber == 109 || ButtonNumber == 220 || ButtonNumber == 252))
        return true;

    if ((ButtonName == "<" || ButtonName == ",") && (ButtonNumber == 60 || ButtonNumber == 44 || ButtonNumber == 193 || ButtonNumber == 225))
        return true;

    if ((ButtonName == ">" || ButtonName == ".") && (ButtonNumber == 62 || ButtonNumber == 46 || ButtonNumber == 222 || ButtonNumber == 254))
        return true;

    if ((ButtonName == "?" || ButtonName == "/") && (ButtonNumber == 63 || ButtonNumber == 47 || ButtonNumber == 44 || ButtonNumber == 46))
        return true;

    if ((ButtonName == "ARROW_UP" || ButtonName == "Arrow_Up" || ButtonName == "arror_up") && ButtonNumber == 72)
        return true;

    /* Z -> Arrow_Up */

    /* Space -> Arrow_Right */

    if ((ButtonName == "SPACE" || ButtonName == "Space" || ButtonName == "space") && ButtonNumber == 32)
        return true;

    if ((ButtonName == "ARROW_LEFT" || ButtonName == "Arrow_Left" || ButtonName == "arrow_left") && ButtonNumber == 75)
        return true;

    if ((ButtonName == "ARROW_DOWN" || ButtonName == "Arrow_Down" || ButtonName == "arrow_down") && ButtonNumber == 80)
        return true;

    if ((ButtonName == "ARROW_RIGHT" || ButtonName == "Arrow_Right" || ButtonName == "arrow_right") && ButtonNumber == 77)
        return true;

    /* Space -> Arrow_Right */

    return false;

}

#endif // _click_catcher_H_
