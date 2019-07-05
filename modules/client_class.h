#pragma once

#ifndef _client_class_H_
#define _client_class_H_

class Clients {

	private:

		std::string Name; // имя клиента
		std::string Technology_Name; // название технологии
		std::string IDE_Name; // название IDE
		std::string OS_Name; // название операционной системы
		bool MenuFunctional; // базовый функционал для управления меню
		unsigned short int TasksCount; // количество заданных заданий
		unsigned short int FinishedWorksCount; // количество уже имеющихся в базе заданий для этого клиента
		std::string PK_Name; // имя профиля на пк исполнителя
		std::string Labs_Path; // место сохранения лаб

	public:

		Clients (void) {

			Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			FinishedWorksCount = 0;
			PK_Name = Get_PK_UserName ();
			Labs_Path = "\0";

		}

		~Clients (void) {

            remove ("PK_UserName.txt");

		}

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

		const void setFinishedWorksCount (const unsigned short int Number) {

			this->FinishedWorksCount = Number;

		} // сеттер для FinishedWorksCount

		const unsigned short int getFinishedWorksCount (void) const {

			return this->FinishedWorksCount;

		} // геттер для FinishedWorksCount

	//////////////////////////////////////////////

		const void setPK_Name (const std::string Str) {

			this->PK_Name = Str;

		} // сеттер для PK_Name

		const std::string getPK_Name (void) const {

			return this->PK_Name;

		} // геттер для PK_Name;

	//////////////////////////////////////////////

	const std::string Get_PK_UserName (void) const;
	const std::string Get_Labs_Path (void) const;

};

const std::string Clients::Get_PK_UserName (void) const {

    std::string Str = "\0";

    system ("@echo %UserName% > PK_UserName.txt");

    std::ifstream Read ("PK_UserName.txt");

        if (Read.is_open ())
            Read >> Str;

  //      else
//            Exception ("File PK_UserName.txt didnt open"); // переписать

    Read.close ();

    return Str;

} // метод получения названия имени пользователя-пк

/*const std::string Clients::Get_Labs_Path (void) const {


}*/

#endif // _client_class_H_
