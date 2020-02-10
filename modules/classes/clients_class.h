// Класс клиента

#pragma once

#ifndef _client_class_h_
#define _client_class_h_

class Class_Clients {

	private:

        std::string Name; // имя клиента
		std::string Technology_Name; // название технологии
		std::string IDE_Name; // название IDE
		std::string OS_Name; // название операционной системы
		bool MenuFunctional; // базовый функционал для управления меню
		unsigned short int TasksCount; // количество заданных заданий
		unsigned short int Available_TasksCount; // количество уже имеющихся в базе заданий для этого клиента
		unsigned short int MenuItems_Count; // количество пунктов в меню (для функционального управления программой)
		std::vector <std::string> MenuItems_Title; // вектор заголовков к пунктам меню

	public:

		Class_Clients (void) {

            Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			Available_TasksCount = 0;
			MenuItems_Count = 3; // 3 пункта меню по умолчанию

                if (MenuItems_Title.size () > 0)
                    MenuItems_Title.clear ();

                for (unsigned short int i = 0; i < MenuItems_Count; i++)
                    MenuItems_Title.push_back ("");

		}

		~Class_Clients (void) {}

    //////////////////////////////////////////////

		const void setName (const std::string Str) {

			this->Name = Str;

		} // сеттер для Name

		 const std::string getName (void) const {

			return this->Name;

		} // геттер для Name

	//////////////////////////////////////////////

		const void setTechnology_Name (const std::string Str) {

			this->Technology_Name = Str;

		} // сеттер для Technology_Name

		const std::string getTechnology_Name (void) const {

			return this->Technology_Name;

		} // геттер для Technology_Name

	//////////////////////////////////////////////

		const void setIDE_Name (const std::string Str) {

			this->IDE_Name = Str;

		} // сеттер для setIDE_Name

		const std::string getIDE_Name (void) const {

            return this->IDE_Name;

		} // геттер для IDE_Name

	//////////////////////////////////////////////

		const void setOS_Name (const std::string Str) {

			this->OS_Name = Str;

		} // сеттер для OS_Name

		const std::string getOS_Name (void) const {

			return this->OS_Name;

		} // геттер для OS_Name

	//////////////////////////////////////////////

		const void setMenuFunctional (const bool Flag) {

			this->MenuFunctional = Flag;

		} // сеттер для MenuFunctional

		const bool getMenuFunctional (void) const {

			return this->MenuFunctional;

		} // геттер для MenuFunctional

	//////////////////////////////////////////////

		const void setTasksCount (const unsigned short int Number) {

			this->TasksCount = Number;

		} // сеттер для TasksCount

		const unsigned short int getTasksCount (void) const {

			return this->TasksCount;

		} // геттер для TasksCount

	//////////////////////////////////////////////

        const void setAvailable_TasksCount (const unsigned short int Number) {

			this->Available_TasksCount = Number;

		} // сеттер для Available_TasksCount

		const unsigned short int getAvailable_TasksCount (void) const {

			return this->Available_TasksCount;

		} // геттер для Available_TasksCount

    //////////////////////////////////////////////

        const void setMenuItems_Count (const unsigned short int Number) {

			this->MenuItems_Count = Number;

		} // сеттер для MenuItems_Count

		const unsigned short int getMenuItems_Count (void) const {

			return this->MenuItems_Count;

		} // геттер для MenuItems_Count

	//////////////////////////////////////////////

        const void setMenuItems_Title (const std::string Str) {

            this->MenuItems_Title.push_back (Str);

        } // сеттер для MenuItems_Title

        const std::string getMenuItems_Title (const unsigned short int Index) const {

            return this->MenuItems_Title[Index];

        } // геттер для MenuItems_Title

        const void Clear_MenuItems_Title (void) {

            this->MenuItems_Title.clear ();

        } // clear для MenuItems_Title

	//////////////////////////////////////////////

        const void Clear_Client_Parameters (void) {

            Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			Available_TasksCount = 0;
			MenuItems_Count = 3;

                if (MenuItems_Title.size () > 0)
                    MenuItems_Title.clear ();

                for (unsigned short int i = 0; i < MenuItems_Count; i++)
                    MenuItems_Title.push_back ("");

        } // очистка параметров клиента

}; // класс данных о вводимом клиенте

#endif // _client_class_h_
