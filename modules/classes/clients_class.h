// ����� �������

#pragma once

#ifndef _client_class_h_
#define _client_class_h_

class Class_Clients {

	private:

        std::string Name; // ��� �������
		std::string Technology_Name; // �������� ����������
		std::string IDE_Name; // �������� IDE
		std::string OS_Name; // �������� ������������ �������
		bool MenuFunctional; // ������� ���������� ��� ���������� ����
		unsigned short int TasksCount; // ���������� �������� �������
		unsigned short int Available_TasksCount; // ���������� ��� ��������� � ���� ������� ��� ����� �������
		unsigned short int MenuItems_Count; // ���������� ������� � ���� (��� ��������������� ���������� ����������)
		std::vector <std::string> MenuItems_Title; // ������ ���������� � ������� ����

	public:

		Class_Clients (void) {

            Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			Available_TasksCount = 0;
			MenuItems_Count = 3; // 3 ������ ���� �� ���������

                if (MenuItems_Title.size () > 0)
                    MenuItems_Title.clear ();

                for (unsigned short int i = 0; i < MenuItems_Count; i++)
                    MenuItems_Title.push_back ("");

		}

		~Class_Clients (void) {}

    //////////////////////////////////////////////

		const void setName (const std::string Str) {

			this->Name = Str;

		} // ������ ��� Name

		 const std::string getName (void) const {

			return this->Name;

		} // ������ ��� Name

	//////////////////////////////////////////////

		const void setTechnology_Name (const std::string Str) {

			this->Technology_Name = Str;

		} // ������ ��� Technology_Name

		const std::string getTechnology_Name (void) const {

			return this->Technology_Name;

		} // ������ ��� Technology_Name

	//////////////////////////////////////////////

		const void setIDE_Name (const std::string Str) {

			this->IDE_Name = Str;

		} // ������ ��� setIDE_Name

		const std::string getIDE_Name (void) const {

            return this->IDE_Name;

		} // ������ ��� IDE_Name

	//////////////////////////////////////////////

		const void setOS_Name (const std::string Str) {

			this->OS_Name = Str;

		} // ������ ��� OS_Name

		const std::string getOS_Name (void) const {

			return this->OS_Name;

		} // ������ ��� OS_Name

	//////////////////////////////////////////////

		const void setMenuFunctional (const bool Flag) {

			this->MenuFunctional = Flag;

		} // ������ ��� MenuFunctional

		const bool getMenuFunctional (void) const {

			return this->MenuFunctional;

		} // ������ ��� MenuFunctional

	//////////////////////////////////////////////

		const void setTasksCount (const unsigned short int Number) {

			this->TasksCount = Number;

		} // ������ ��� TasksCount

		const unsigned short int getTasksCount (void) const {

			return this->TasksCount;

		} // ������ ��� TasksCount

	//////////////////////////////////////////////

        const void setAvailable_TasksCount (const unsigned short int Number) {

			this->Available_TasksCount = Number;

		} // ������ ��� Available_TasksCount

		const unsigned short int getAvailable_TasksCount (void) const {

			return this->Available_TasksCount;

		} // ������ ��� Available_TasksCount

    //////////////////////////////////////////////

        const void setMenuItems_Count (const unsigned short int Number) {

			this->MenuItems_Count = Number;

		} // ������ ��� MenuItems_Count

		const unsigned short int getMenuItems_Count (void) const {

			return this->MenuItems_Count;

		} // ������ ��� MenuItems_Count

	//////////////////////////////////////////////

        const void setMenuItems_Title (const std::string Str) {

            this->MenuItems_Title.push_back (Str);

        } // ������ ��� MenuItems_Title

        const std::string getMenuItems_Title (const unsigned short int Index) const {

            return this->MenuItems_Title[Index];

        } // ������ ��� MenuItems_Title

        const void Clear_MenuItems_Title (void) {

            this->MenuItems_Title.clear ();

        } // clear ��� MenuItems_Title

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

        } // ������� ���������� �������

}; // ����� ������ � �������� �������

#endif // _client_class_h_
