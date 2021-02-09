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
		std::string TypeWork; // наименование типа работы

		bool MenuFunctional; // базовый функционал для управления меню
		unsigned short int TasksCount; // количество заданных заданий
		unsigned short int Available_TasksCount; // количество уже имеющихся в базе заданий для этого клиента
		unsigned short int MenuItems_Count; // количество пунктов в меню (для функционального управления программой)

		std::vector <std::string> MenuItems_Title; // вектор заголовков к пунктам меню
		std::vector <int> Order_Costs; // стоимость каждой задаче по отдельности
		std::vector <std::string> Keywords; // ключевые слова к каждой задаче по отдельности

	public:

		Class_Clients (void) {

            this->Name = "\0";
			this->Technology_Name = "\0";
			this->IDE_Name = "\0";
			this->OS_Name = "\0";
			this->TypeWork = "\0";
			this->MenuFunctional = false;
			this->TasksCount = 0;
			this->Available_TasksCount = 0;
			this->MenuItems_Count = 3; // 3 пункта меню по умолчанию

                if (this->MenuItems_Title.size () > 0)
                    this->MenuItems_Title.clear ();

                for (unsigned short int i = 0; i < this->MenuItems_Count; i++)
                    this->MenuItems_Title.push_back ("");

                if (this->Order_Costs.size () > 0)
                    Order_Costs.clear ();

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

	const void setTypeWork (const std::string Str) {

			this->TypeWork = Str;

		} // сеттер для TypeWork

		const std::string getTypeWork (void) const {

			return this->TypeWork;

		} // геттер для TypeWork

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

        const void setOrder_Costs (const unsigned short int Sum) {

            this->Order_Costs.push_back (Sum);

        } // сеттер для Order_Costs

        const int getOrder_Costs (const unsigned short int Index) const {

            return this->Order_Costs[Index];

        } // геттер для Order_Costs

        const void Clear_Order_Costs (void) {

            this->Order_Costs.clear ();

        } // clear для Order_Costs

        const void setKeywords (const std::string Str) {

            this->Keywords.push_back (Str);

        } // сеттер для Keywords

        const std::string getKeywords (const unsigned short int Index) const {

            return this->Keywords[Index];

        } // геттер для Keywords

        const void Clear_Keywords (void) {

            this->Keywords.clear ();

        } // clear для Keywords

	//////////////////////////////////////////////

        const void Clear_Client_Parameters (void) {

            this->Name = "\0";
			this->Technology_Name = "\0";
			this->IDE_Name = "\0";
			this->OS_Name = "\0";
			this->TypeWork = "\0";
			this->MenuFunctional = false;
			this->TasksCount = 0;
			this->Available_TasksCount = 0;
			this->MenuItems_Count = 3;

                if (this->MenuItems_Title.size () > 0)
                    Clear_MenuItems_Title ();

                for (unsigned short int i = 0; i < this->MenuItems_Count; i++)
                    this->MenuItems_Title.push_back ("");

                if (this->Order_Costs.size () > 0)
                    Clear_Order_Costs ();

                if (this->Keywords.size () > 0)
                    Clear_Keywords ();

        } // очистка параметров клиента

}; // класс данных о вводимом клиенте

#endif // _client_class_h_
