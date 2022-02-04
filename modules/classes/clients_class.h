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
		std::string TypeWork; // ������������ ���� ������

		bool MenuFunctional; // ������� ���������� ��� ���������� ����
		unsigned short int TasksCount; // ���������� �������� �������
		unsigned short int Available_TasksCount; // ���������� ��� ��������� � ���� ������� ��� ����� �������
		unsigned short int MenuItems_Count; // ���������� ������� � ���� (��� ��������������� ���������� ����������)

		std::vector <std::string> MenuItems_Title; // ������ ���������� � ������� ����
		std::vector <int> Order_Costs; // ��������� ������ ������ �� �����������
		std::vector <std::string> Keywords; // �������� ����� � ������ ������ �� �����������

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
			this->MenuItems_Count = 3; // 3 ������ ���� �� ���������

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

	const void setTypeWork (const std::string Str) {

			this->TypeWork = Str;

		} // ������ ��� TypeWork

		const std::string getTypeWork (void) const {

			return this->TypeWork;

		} // ������ ��� TypeWork

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

        const void setOrder_Costs (const unsigned short int Sum) {

            this->Order_Costs.push_back (Sum);

        } // ������ ��� Order_Costs

        const int getOrder_Costs (const unsigned short int Index) const {

            return this->Order_Costs[Index];

        } // ������ ��� Order_Costs

        const void Clear_Order_Costs (void) {

            this->Order_Costs.clear ();

        } // clear ��� Order_Costs

        const void setKeywords (const std::string Str) {

            this->Keywords.push_back (Str);

        } // ������ ��� Keywords

        const std::string getKeywords (const unsigned short int Index) const {

            return this->Keywords[Index];

        } // ������ ��� Keywords

        const void Clear_Keywords (void) {

            this->Keywords.clear ();

        } // clear ��� Keywords

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

        } // ������� ���������� �������

}; // ����� ������ � �������� �������

#endif // _client_class_h_


