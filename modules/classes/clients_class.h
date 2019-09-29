// ����� �������

#pragma once

#ifndef _client_class_h_
#define _client_class_h_

#include "../libs/additional_functions.h"

class Class_Clients {

	private:

        std::string Name; // ��� �������
		std::string PK_Name; // ��� ������� �� �� �����������
		std::string Technology_Name; // �������� ����������
		std::string IDE_Name; // �������� IDE
		std::string OS_Name; // �������� ������������ �������
		bool MenuFunctional; // ������� ���������� ��� ���������� ����
		unsigned short int TasksCount; // ���������� �������� �������
		unsigned short int Available_TasksCount; // ���������� ��� ��������� � ���� ������� ��� ����� �������

	public:

		Class_Clients (void) {

            Name = "\0";
			PK_Name = Load_PK_UserName ();
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			Available_TasksCount = 0;

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

        const void setPK_Name (const std::string Str) {

			this->PK_Name = Str;

		} // ������ ��� PK_Name

		const std::string getPK_Name (void) const {

			return this->PK_Name;

		} // ������ ��� PK_Name

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

        const void Clear_Client_Parameters (void) {

            Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			Available_TasksCount = 0;

        } // ������� ���������� �������

		const std::string Load_PK_UserName (void) const;


}; // ����� ������ � �������� �������

const std::string Class_Clients::Load_PK_UserName (void) const {

    const std::string PathPK_UserName = "C:\\Windows\\Temp\\PK_UserName.txt";
    std::string Command = "@echo %UserName% > " + PathPK_UserName;
    std::string PK_Name = "\0";

    system (Command.c_str ());

    std::ifstream Read (PathPK_UserName.c_str ());

        if (Read.is_open ())
            Read >> PK_Name;

        else
            Exception ("File PK_UserName.txt didnt open"); // ����������

    Read.close ();

    remove (PathPK_UserName.c_str ());

    return PK_Name;

} // ����� ��������� �������� ����� ������������-��


#endif // _client_class_h_
