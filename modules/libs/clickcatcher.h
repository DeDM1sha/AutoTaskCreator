/*  Данная библиотека позволяет упростить работу с функцией getch, путем отправки в данную функцию названия желаемой
    нажатой пользователем кнопки, и номером этой конпки.

//  Первый параметр функции отвечает за название нужной нам клавиши на клавиатуре, и имеет тип string.
    Предусмотрено написание названия клавиши в разных регистрах, но только на латинице.

//  Второй параметр функции отвечает за ASCII номер клавиши, и имеет тип unsigned short int.
    Предусмотрены все возможные варианты нумерации каждой клавиши из всех возможных,
    включая и оба регистра, и оба языка для каждой клавиши - то бишь, взяв например отдельно взятую клавишу G -
    будет успешно обработано все 4 варианта кода этой клавиши, а именно:

    * "п" - маленькая буква на кириллице
    * "П" - большая буква на кириллице
    * "g" - маленькая буква на латинице
    * "G" - большая буква на латинице.

    Сюда следует отправлять значение, полученное функцией getch в основной программе.

*/

#pragma once

#ifndef _clickcatcher_h_
#define _clickcatcher_h_

class ClassClick {

	private:

	std::string Name; // название клавиш
	unsigned short int Number; // номер клавиши по ASCII таблице

	public:

		ClassClick (const std::string& Str, const unsigned short int& Value) {

			this->Name = Str;
			this->Number = Value;

		}

		~ClassClick (void) {}

		const void setName (const std::string& Str) {

			this->Name = Str;

		} // сеттер на Name

		const std::string getName (void) const {

			return this->Name;

		} // геттер на Name

		const void setNumber (const unsigned short int& Value) {

			this->Number = Value;

		} // сеттер на Number

		const unsigned short int getNumber (void) const {

			return this->Number;

		} // геттер на Number

}; // класс нажатой клавиши

const bool ClickCatch (const std::string& Str, const unsigned short int& Value) {

	ClassClick Button (Str, Value);

    /* Esc -> F12 */

		if ((Button.getName () == "ESC" || Button.getName () == "Esc" || Button.getName () == "esc") && Button.getNumber () == 27)
			return true;

		else if ((Button.getName () == "F1" || Button.getName () == "f1") && (Button.getNumber () == 59 || Button.getNumber () == 84))
			return true;

		else if ((Button.getName () == "F2" || Button.getName () == "f2") && (Button.getNumber () == 60 || Button.getNumber () == 85))
			return true;

		else if ((Button.getName () == "F3" || Button.getName () == "f3") && (Button.getNumber () == 61 || Button.getNumber () == 86))
			return true;

		else if ((Button.getName () == "F4" || Button.getName () == "f4") && (Button.getNumber () == 62 || Button.getNumber () == 87))
			return true;

		else if ((Button.getName () == "F5" || Button.getName () == "f5") && (Button.getNumber () == 63 || Button.getNumber () == 88))
			return true;

		else if ((Button.getName () == "F6" || Button.getName () == "f6") && (Button.getNumber () == 64 || Button.getNumber () == 89))
			return true;

		else if ((Button.getName () == "F7" || Button.getName () == "f7") && (Button.getNumber () == 65 || Button.getNumber () == 90))
			return true;

		else if ((Button.getName () == "F8" || Button.getName () == "f8") && (Button.getNumber () == 66 || Button.getNumber () == 91))
			return true;

		else if ((Button.getName () == "F9" || Button.getName () == "f9") && (Button.getNumber () == 67 || Button.getNumber () == 92))
			return true;

		else if ((Button.getName () == "F10" || Button.getName () == "f10") && (Button.getNumber () == 68 || Button.getNumber () == 93))
			return true;

		else if ((Button.getName () == "F11" || Button.getName () == "f11") && (Button.getNumber () == 133 || Button.getNumber () == 135))
			return true;

		else if ((Button.getName () == "F12" || Button.getName () == "f12") && (Button.getNumber () == 134 || Button.getNumber () == 136))
			return true;

		/* Esc -> F12 */

		/* ~ -> - Page Up */

		else if ((Button.getName () == "`" || Button.getName () == "~") && (Button.getNumber () == 96 || Button.getNumber () == 126 || Button.getNumber () == 184 || Button.getNumber () == 168))
			return true;

		else if ((Button.getName () == "1" || Button.getName () == "!") && (Button.getNumber () == 49 || Button.getNumber () == 33))
			return true;

		else if ((Button.getName () == "2" || Button.getName () == "@" || Button.getName () == "\"") && (Button.getNumber () == 50 || Button.getNumber () == 64 || Button.getNumber () == 34))
			return true;

		else if ((Button.getName () == "3" || Button.getName () == "#" || Button.getName () == "№") && (Button.getNumber () == 51 || Button.getNumber () == 35 || Button.getNumber () == 185))
			return true;

		else if ((Button.getName () == "4" || Button.getName () == "$" || Button.getName () == ";") && (Button.getNumber () == 52 || Button.getNumber () == 36 || Button.getNumber () == 59))
			return true;

		else if ((Button.getName () == "5" || Button.getName () == "%") && (Button.getNumber () == 53 || Button.getNumber () == 37))
			return true;

		else if ((Button.getName () == "6" || Button.getName () == "^" || Button.getName () == ":") && (Button.getNumber () == 54 || Button.getNumber () == 94 || Button.getNumber () == 58))
			return true;

		else if ((Button.getName () == "7" || Button.getName () == "&" || Button.getName () == "?") && (Button.getNumber () == 55 || Button.getNumber () == 38 || Button.getNumber () == 63))
			return true;

		else if ((Button.getName () == "8" || Button.getName () == "*") && (Button.getNumber () == 56 || Button.getNumber () == 42))
			return true;

		else if ((Button.getName () == "9" || Button.getName () == "(") && (Button.getNumber () == 57 || Button.getNumber () == 42))
			return true;

		else if ((Button.getName () == "0" || Button.getName () == ")") && (Button.getNumber () == 48 || Button.getNumber () == 41))
			return true;

		else if ((Button.getName () == "-" || Button.getName () == "_") && (Button.getNumber () == 45 || Button.getNumber () == 95))
			return true;

		else if ((Button.getName () == "=" || Button.getName () == "+") && (Button.getNumber () == 61 || Button.getNumber () == 43))
			return true;

		else if ((Button.getName () == "BACKSPACE" || Button.getName () == "BackSpace" || Button.getName () == "backspace") && Button.getNumber () == 8)
			return true;

		else if ((Button.getName () == "INSERT" || Button.getName () == "Insert" || Button.getName () == "insert" || Button.getName () == "INS" || Button.getName () == "ins") && Button.getNumber () == 82)
			return true;

		else if ((Button.getName () == "HOME" || Button.getName () == "Home" || Button.getName () == "home") && Button.getNumber () == 71)
			return true;

		else if ((Button.getName () == "PAGEUP" || Button.getName () == "PAGE UP" || Button.getName () == "PageUp" || Button.getName () == "Page Up" || Button.getName () == "pageup" || Button.getName () == "page up") && Button.getNumber () == 73)
			return true;

		/* ~ -> Page Up */

		/* Tab -> Page Down */

		else if ((Button.getName () == "TAB" || Button.getName () == "Tab" || Button.getName () == "tab") && Button.getNumber () == 9)
			return true;

		else if ((Button.getName () == "Q" || Button.getName () == "q") && (Button.getNumber () == 81 || Button.getNumber () == 113 || Button.getNumber () == 201 || Button.getNumber () == 233))
			return true;

		else if ((Button.getName () == "W" || Button.getName () == "w") && (Button.getNumber () == 87 || Button.getNumber () == 119 || Button.getNumber () == 214 || Button.getNumber () == 246))
			return true;

		else if ((Button.getName () == "E" || Button.getName () == "e") && (Button.getNumber () == 69 || Button.getNumber () == 101 || Button.getNumber () == 211 || Button.getNumber () == 243))
			return true;

		else if ((Button.getName () == "R" || Button.getName () == "r") && (Button.getNumber () == 82 || Button.getNumber () == 114 || Button.getNumber () == 202 || Button.getNumber () == 234))
			return true;

		else if ((Button.getName () == "T" || Button.getName () == "t") && (Button.getNumber () == 84 || Button.getNumber () == 116 || Button.getNumber () == 197 || Button.getNumber () == 229))
			return true;

		else if ((Button.getName () == "Y" || Button.getName () == "y") && (Button.getNumber () == 89 || Button.getNumber () == 121 || Button.getNumber () == 205 || Button.getNumber () == 237))
			return true;

		else if ((Button.getName () == "U" || Button.getName () == "u") && (Button.getNumber () == 85 || Button.getNumber () == 117 || Button.getNumber () == 195 || Button.getNumber () == 227))
			return true;

		else if ((Button.getName () == "I" || Button.getName () == "i") && (Button.getNumber () == 73 || Button.getNumber () == 105 || Button.getNumber () == 216 || Button.getNumber () == 248))
			return true;

		else if ((Button.getName () == "O" || Button.getName () == "o") && (Button.getNumber () == 79 || Button.getNumber () == 111 || Button.getNumber () == 217 || Button.getNumber () == 249))
			return true;

		else if ((Button.getName () == "P" || Button.getName () == "p") && (Button.getNumber () == 80 || Button.getNumber () == 112 || Button.getNumber () == 199 || Button.getNumber () == 231))
			return true;

		else if ((Button.getName () == "{" || Button.getName () == "[") && (Button.getNumber () == 123 || Button.getNumber () == 91 || Button.getNumber () == 213 || Button.getNumber () == 245))
			return true;

		else if ((Button.getName () == "}" || Button.getName () == "]") && (Button.getNumber () == 125 || Button.getNumber () == 93 || Button.getNumber () == 218 || Button.getNumber () == 250))
			return true;

		else if ((Button.getName () == "|" || Button.getName () == "\"" || Button.getName () == "/") && (Button.getNumber () == 124 || Button.getNumber () == 92 || Button.getNumber () == 47))
			return true;

		else if ((Button.getName () == "DELETE" || Button.getName () == "Delete" || Button.getName () == "delete" || Button.getName () == "DEL" || Button.getName () == "Del" || Button.getName () == "del") && Button.getNumber () == 83)
			return true;

		else if ((Button.getName () == "END" || Button.getName () == "End" || Button.getName () == "end") && Button.getNumber () == 79)
			return true;

		else if ((Button.getName () == "PAGEDOWN" || Button.getName () == "PAGE DOWN" || Button.getName () == "PageDown" || Button.getName () == "Page Down" || Button.getName () == "pagedown" || Button.getName () == "page down") && Button.getNumber () == 81)
			return true;

		/* Tab -> + Page Down */

		/* A -> Enter */

		else if ((Button.getName () == "A" || Button.getName () == "a") && (Button.getNumber () == 97 || Button.getNumber () == 65 || Button.getNumber () == 244 || Button.getNumber () == 212))
			return true;

		else if ((Button.getName () == "S" || Button.getName () == "s") && (Button.getNumber () == 115 || Button.getNumber () == 83 || Button.getNumber () == 251 || Button.getNumber () == 219))
			return true;

		else if ((Button.getName () == "D" || Button.getName () == "d") && (Button.getNumber () == 100 || Button.getNumber () == 68 || Button.getNumber () == 226 || Button.getNumber () == 194))
			return true;

		else if ((Button.getName () == "F" || Button.getName () == "f") && (Button.getNumber () == 102 || Button.getNumber () == 70 || Button.getNumber () == 224 || Button.getNumber () == 192))
			return true;

		else if ((Button.getName () == "G" || Button.getName () == "g") && (Button.getNumber () == 71 || Button.getNumber () == 103 || Button.getNumber () == 207 || Button.getNumber () == 239))
			return true;

		else if ((Button.getName () == "H" || Button.getName () == "h") && (Button.getNumber () == 72 || Button.getNumber () == 104 || Button.getNumber () == 208 || Button.getNumber () == 240))
			return true;

		else if ((Button.getName () == "J" || Button.getName () == "j") && (Button.getNumber () == 74 || Button.getNumber () == 106 || Button.getNumber () == 206 || Button.getNumber () == 238))
			return true;

		else if ((Button.getName () == "K" || Button.getName () == "k") && (Button.getNumber () == 75 || Button.getNumber () == 107 || Button.getNumber () == 203 || Button.getNumber () == 235))
			return true;

		else if ((Button.getName () == "L" || Button.getName () == "l") && (Button.getNumber () == 76 || Button.getNumber () == 108 || Button.getNumber () == 196 || Button.getNumber () == 228))
			return true;

		else if ((Button.getName () == ":" || Button.getName () == ";") && (Button.getNumber () == 58 || Button.getNumber () == 59 || Button.getNumber () == 198 || Button.getNumber () == 230))
			return true;

		else if ((Button.getName () == "\"" || Button.getName () == "\'") && (Button.getNumber () == 34 || Button.getNumber () == 39 || Button.getNumber () == 221 || Button.getNumber () == 253))
			return true;

		else if ((Button.getName () == "ENTER" || Button.getName () == "Enter" || Button.getName () == "enter") && Button.getNumber () == 13)
			return true;

		/* A -> Enter */

		/* Z -> Arrow_Up */

		else if ((Button.getName () == "Z" || Button.getName () == "z") && (Button.getNumber () == 90 || Button.getNumber () == 122 || Button.getNumber () == 223 || Button.getNumber () == 255))
			return true;

		else if ((Button.getName () == "X" || Button.getName () == "x") && (Button.getNumber () == 88 || Button.getNumber () == 120 || Button.getNumber () == 215 || Button.getNumber () == 247))
			return true;

		else if ((Button.getName () == "C" || Button.getName () == "c") && (Button.getNumber () == 67 || Button.getNumber () == 99 || Button.getNumber () == 209 || Button.getNumber () == 241))
			return true;

		else if ((Button.getName () == "V" || Button.getName () == "v") && (Button.getNumber () == 86 || Button.getNumber () == 118 || Button.getNumber () == 204 || Button.getNumber () == 236))
			return true;

		else if ((Button.getName () == "B" || Button.getName () == "b") && (Button.getNumber () == 66 || Button.getNumber () == 98 || Button.getNumber () == 200 || Button.getNumber () == 232))
			return true;

		else if ((Button.getName () == "N" || Button.getName () == "n") && (Button.getNumber () == 78 || Button.getNumber () == 110 || Button.getNumber () == 210 || Button.getNumber () == 242))
			return true;

		else if ((Button.getName () == "M" || Button.getName () == "m") && (Button.getNumber () == 77 || Button.getNumber () == 109 || Button.getNumber () == 220 || Button.getNumber () == 252))
			return true;

		else if ((Button.getName () == "<" || Button.getName () == ",") && (Button.getNumber () == 60 || Button.getNumber () == 44 || Button.getNumber () == 193 || Button.getNumber () == 225))
			return true;

		else if ((Button.getName () == ">" || Button.getName () == ".") && (Button.getNumber () == 62 || Button.getNumber () == 46 || Button.getNumber () == 222 || Button.getNumber () == 254))
			return true;

		else if ((Button.getName () == "?" || Button.getName () == "/") && (Button.getNumber () == 63 || Button.getNumber () == 47 || Button.getNumber () == 44 || Button.getNumber () == 46))
			return true;

		else if ((Button.getName () == "ARROW_UP" || Button.getName () == "Arrow_Up" || Button.getName () == "arror_up") && Button.getNumber () == 72)
			return true;

		/* Z -> Arrow_Up */

		/* Space -> Arrow_Right */

		else if ((Button.getName () == "SPACE" || Button.getName () == "Space" || Button.getName () == "space") && Button.getNumber () == 32)
			return true;

		else if ((Button.getName () == "ARROW_LEFT" || Button.getName () == "Arrow_Left" || Button.getName () == "arrow_left") && Button.getNumber () == 75)
			return true;

		else if ((Button.getName () == "ARROW_DOWN" || Button.getName () == "Arrow_Down" || Button.getName () == "arrow_down") && Button.getNumber () == 80)
			return true;

		else if ((Button.getName () == "ARROW_RIGHT" || Button.getName () == "Arrow_Right" || Button.getName () == "arrow_right") && Button.getNumber () == 77)
			return true;

		/* Space -> Arrow_Right */

    return false;

} // функция обработки нажатой и требуемой кнопки

#endif // _click_catcher_h_
