// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

class Class_Settings {

    private:

        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб

    public:

        Class_Settings (Class_Clients& Client) {

            Config_Path = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";
            Labs_Path = Load_Labs_Path ();

        }

        ~Class_Settings (void) {}

    //////////////////////////////////////////////

        const void setLabs_Path (const std::string Str) {

            this->Labs_Path = Str;

        } // сеттер для Labs_Path

        const std::string getLabs_Path (void) const {

            return this->Labs_Path;

        } // геттер для Labs_Path

    //////////////////////////////////////////////

        const void setConfig_Path (const std::string Str) {

            this->Config_Path = Str;

        } // сеттер для Config_Path

        const std::string getConfig_Path (void) const {

            return this->Config_Path;

        } // геттер для Config_Path

    //////////////////////////////////////////////

        const void ConfigFile_Open (void) const;
        const void ConfigFile_Close (void) const;
        const std::string Load_Labs_Path (void) const;
        const void SaveSettings (void) const;


};

const void Class_Settings::ConfigFile_Open (void) const {

    std::string attrib = "attrib -r -s -h -x" + Config_Path;

    system (attrib.c_str());

} // метод открытия файла конфига

const void Class_Settings::ConfigFile_Close (void) const {

    std::string attrib = "attrib +r +s +h +x " + Config_Path;

    system (attrib.c_str());

}

const std::string Class_Settings::Load_Labs_Path (void) const {

    std::string Str = "\0";
    std::string LabsPath = "\0";

    ConfigFile_Open ();

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            Read >> Str;

                if (Str == "Path_to_Labs") {

                    Read >> Str;
                    Read >> LabsPath;

                }

        }

        else
            Exception ("File Settings didnt open");

        if (LabsPath.length () == 0)
            Exception ("Not found Path_to_Labs in settins file");

    Read.close ();

    ConfigFile_Close ();

    return LabsPath;

} // метод получения пути хранения заказов

const void Class_Settings::SaveSettings (void) const {

    ConfigFile_Open ();

    // дописать

    ConfigFile_Close ();

}

#endif // _settings_class_h_
