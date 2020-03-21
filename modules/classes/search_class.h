// Класс поиска (клиентов, заказов и т.д.)

#pragma once

#ifndef _search_class_h_
#define _search_class_h

const static void Continue (void) {

    CenterText ("Для продолжения нажмите любую клавишу...");
    getch ();

} // функция ожидания нажатия для продолжления

class Class_Search {

    private:



    public:

        Class_Search () {



        }

        ~Class_Search (void) {}

        const void Search_Client (const std::string, const Class_Settings&);

}; // класс поиска

const void Class_Search::Search_Client (std::string InputName, const Class_Settings& Settings) {

    const std::string ClientName = CheckClientExist_ReturnTruthName (InputName, Settings);

        if (ClientName == Settings.getERROR_Message_ClientExist ()) {

            Show_Text_Output ("Такого клиента нет!");
            Continue ();

        }

        else
            system (std::string("explorer \"" + Settings.getLabs_Path () + "\\" + ClientName + "\"").c_str ());



} // метод поиска клиента по имени

#endif // _search_class_h
