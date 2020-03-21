// ����� ������ (��������, ������� � �.�.)

#pragma once

#ifndef _search_class_h_
#define _search_class_h

const static void Continue (void) {

    CenterText ("��� ����������� ������� ����� �������...");
    getch ();

} // ������� �������� ������� ��� ������������

class Class_Search {

    private:



    public:

        Class_Search () {



        }

        ~Class_Search (void) {}

        const void Search_Client (const std::string, const Class_Settings&);

}; // ����� ������

const void Class_Search::Search_Client (std::string InputName, const Class_Settings& Settings) {

    const std::string ClientName = CheckClientExist_ReturnTruthName (InputName, Settings);

        if (ClientName == Settings.getERROR_Message_ClientExist ()) {

            Show_Text_Output ("������ ������� ���!");
            Continue ();

        }

        else
            system (std::string("explorer \"" + Settings.getLabs_Path () + "\\" + ClientName + "\"").c_str ());



} // ����� ������ ������� �� �����

#endif // _search_class_h
