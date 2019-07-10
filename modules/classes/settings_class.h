// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _settings_class_h_
#define _settings_class_h_

static std::string SaveTag_Path_to_Labs = "Path_to_Labs";
static std::string SaveTag_Order_Start = "Order_Start";

class Class_Settings {

    private:

        std::string Config_Path; // место хранения файла с настройками
        std::string Labs_Path; // место сохранения лаб
        bool Automatic_Order_Start; // автоматический запуск создания заказа

    public:

        Class_Settings (Class_Clients& Client) {

            Config_Path = "C:\\Users\\" + Client.getPK_Name () + "\\AppData\\Local\\Temp\\AutoTaskCreator_Settings.cfg";
            Check_ConfigFile ();
            Labs_Path = Load_Labs_Path ();
            Automatic_Order_Start = Load_Order_Start ();

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

        const void setAutomatic_Order_Start (const bool Flag) {

            this->Automatic_Order_Start = Flag;

        } // сеттер для Automatic_Order_Start

        const bool getAutomatic_Order_Start (void) const {

            return this->Automatic_Order_Start;

        } // геттер для Automatic_Order_Start

    //////////////////////////////////////////////

        const void Check_ConfigFile (void) const;
        const void ConfigFile_Open (void) const;
        const void ConfigFile_Close (void) const;
        const std::string Load_Labs_Path (void) const;
        const bool Load_Order_Start (void) const;
        const void SaveSettings (void) const;


};

const void Class_Settings::Check_ConfigFile (void) const {

    ConfigFile_Open ();

    std::ifstream Read (Config_Path.c_str ());

        if (!Read.is_open ()) {

            std::ofstream Write (Config_Path.c_str ());

            Write   << SaveTag_Path_to_Labs << " = " << "E:\\C++Tasks" << "\n" // дефолтный путь к лабам
                    << SaveTag_Order_Start << " = " << 0 << "\n"; // дефолтное значение автозапуска нового заказа - отключено

            Write.close ();

            std::ifstream Check (Config_Path.c_str ());

                if (!Check.is_open ())
                    Exception ("Default settings didnt created");

            Check.close ();

        } // если файла нет, то создаем файл конфига с дефолтными настройками

    Read.close ();

    ConfigFile_Close ();


} // метод проверки существования файла с конфигом

const void Class_Settings::ConfigFile_Open (void) const {

    std::string attrib = "attrib -r -s -h -x " + Config_Path;

    system (attrib.c_str());

} // метод открытия файла конфига

const void Class_Settings::ConfigFile_Close (void) const {

    std::string attrib = "attrib +r +s +h +x " + Config_Path;

    system (attrib.c_str());

} // метод сохранения файла конфига

const std::string Class_Settings::Load_Labs_Path (void) const {

    std::string Str = "\0";
    std::string LabsPath = "\0";

    ConfigFile_Open ();

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == SaveTag_Path_to_Labs) {

                    Read >> Str;
                    Read >> LabsPath;

                }

            }

        }

        else
            Exception ("File Settings didnt open");

        if (LabsPath.length () == 0)
            Exception ("Not found Path_to_Labs in settings file");

    Read.close ();

    ConfigFile_Close ();

    return LabsPath;

} // метод получения пути хранения заказов

const bool Class_Settings::Load_Order_Start (void) const {

    std::string Str = "\0";
    bool Found = false;
    bool Flag = false;

    ConfigFile_Open ();

    std::ifstream Read (Config_Path.c_str ());

        if (Read.is_open ()) {

            while (Read >> Str) {

                if (Str == SaveTag_Order_Start) {

                    Read >> Str;
                    Read >> Flag;
                    Found = true;

                }

            }

        }

        else
            Exception ("File Settings didnt open");

        if (Found == false)
            Exception ("Not found Automatic_Order_Start in settings file");

    Read.close ();

    ConfigFile_Close ();

    return Flag;

} // метод получения значения для автоматического запуска создания лаб

const void Class_Settings::SaveSettings (void) const {

    ConfigFile_Open ();

    std::ofstream Write (Config_Path.c_str ());

    Write   << SaveTag_Path_to_Labs << " = " << getLabs_Path () << "\n"
            << SaveTag_Order_Start << " = " << getAutomatic_Order_Start () << "\n";

    Write.close ();

    ConfigFile_Close ();

    Delay (3000);

}

#endif // _settings_class_h_
