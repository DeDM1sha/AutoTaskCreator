#pragma once

#ifndef _client_class_H_
#define _client_class_H_

void Delay (unsigned short int Time) {

	const clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time) {};

} // функция задержки

class Clients {

	private:

		std::string Name; // имя клиента
		std::string Technology_Name; // название технологии
		std::string IDE_Name; // название IDE
		std::string OS_Name; // название операционной системы
		bool MenuFunctional; // базовый функционал для управления меню
		unsigned short int TasksCount; // количество заданных заданий
		unsigned short int FinishedWorksCount; // количество уже имеющихся в базе заданий для этого клиента
		std::string UserNamePath; // имя профиля на пк исполнителя
		// добавить string для пути сохранения лаб

	public:

		Clients (void) {

			Name = "\0";
			Technology_Name = "\0";
			IDE_Name = "\0";
			OS_Name = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			FinishedWorksCount = 0;
			UserNamePath = Get_PK_UserName ();  // переписать

		}

		~Clients (void) {

            remove ("PK_UserName.txt");

		}

		std::string Get_PK_UserName (void) const {

            std::string Str = "\0";

            system ("@echo %UserName% > PK_UserName.txt");

            std::ifstream Read ("PK_UserName.txt");

                if (Read.is_open ())
                    Read >> Str;

                //else
                    // написать реализацию своего экспешина


            Read.close ();

            return Str;

		}

		void setName (const std::string Str) {

			this->Name = Str;

		} // сеттер для Name

		std::string getName (void) const {

			return this->Name;

		} // геттер для Name

	//////////////////////////////////////////////

		void setTechnology_Name (const std::string Str) {

			this->Technology_Name = Str;

		} // сеттер для Technology_Name

		std::string getTechnology_Name (void) const {

			return this->Technology_Name;

		} // геттер для Technology_Name

	//////////////////////////////////////////////

		void setIDE_Name (const std::string Str) {

			this->IDE_Name = Str;

		} // сеттер для setIDE_Name

		std::string getIDE_Name (void) const {

			return this->IDE_Name;

		} // геттер для IDE_Name

	//////////////////////////////////////////////

		void setOS_Name (const std::string Str) {

			this->OS_Name = Str;

		} // сеттер для OS_Name

		std::string getOS_Name (void) const {

			return this->OS_Name;

		} // геттер для OS_Name

	//////////////////////////////////////////////

		void setMenuFunctional (const bool Flag) {

			this->MenuFunctional = Flag;

		} // сеттер для MenuFunctional

		bool getMenuFunctional (void) const {

			return this->MenuFunctional;

		} // геттер для MenuFunctional

	//////////////////////////////////////////////

		void setTasksCount (const unsigned short int Number) {

			this->TasksCount = Number;

		} // сеттер для TasksCount

		unsigned short int getTasksCount (void) const {

			return this->TasksCount;

		} // геттер для TasksCount

	//////////////////////////////////////////////

		void setFinishedWorksCount (const unsigned short int Number) {

			this->FinishedWorksCount = Number;

		} // сеттер для FinishedWorksCount

		unsigned short int getFinishedWorksCount (void) const {

			return this->FinishedWorksCount;

		} // геттер для FinishedWorksCount

	//////////////////////////////////////////////

		void setUserNamePath (const std::string Str) {

			this->UserNamePath = Str;

		} // сеттер для UserNamePath

		std::string getUserNamePath (void) const {

			return this->UserNamePath;

		} // геттер для UserNamePath;

	//////////////////////////////////////////////


};

#endif // _client_class_H_
