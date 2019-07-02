#pragma once

#ifndef _client_class_H_
#define _client_class_H_

#include <fstream>
#include <time.h>

void Delay (unsigned short int Time) {

	clock_t end_time = clock () + Time * CLOCKS_PER_SEC / 1000;

		while (clock () < end_time) {};

} // функция задержки

class Clients {

	private:

		std::string Name; // имя клиента
		std::string TechnologyName; // название технологии
		std::string IDEName; // название IDE
		std::string OSName; // название операционной системы
		bool MenuFunctional; // базовый функционал для управления меню
		unsigned short int TasksCount; // количество заданных заданий
		unsigned short int FinishedWorksCount; // количество уже имеющихся в базе заданий для этого клиента
		std::string UserNamePath; // имя профиля на пк исполнителя
		// добавить string для пути сохранения лаб

	public:

		Clients (void) {

			Name = "\0";
			TechnologyName = "\0";
			IDEName = "\0";
			OSName = "\0";
			MenuFunctional = false;
			TasksCount = 0;
			FinishedWorksCount = 0;
			UserNamePath = Get_UserName ();

		}

		~Clients (void) {}

		std::string Get_UserName (void) {

			std::string Stroke = "\0";

			system ("echo %UserName% > log.txt");
			std::ifstream Read ("log.txt");
			Read >> Stroke;
			Read.close ();
			remove ("log.txt");

			return Stroke;

		} // метод получения имени пк-пользователя

		void setName (std::string Str) {

			this->Name = Str;

		}

		std::string getName (void) const {

			return this->Name;

		} // set и get для Name

	//////////////////////////////////////////////

		void setTechnologyName (std::string Str) {

			this->TechnologyName = Str;

		}

		std::string getTechnologyName (void) const {

			return this->TechnologyName;

		} // set и get для TechnologyName

	//////////////////////////////////////////////

		void setIDEName (std::string Str) {

			this->IDEName = Str;

		}

		std::string getIDEName (void) const {

			return this->IDEName;

		} // set и get для IDEName

	//////////////////////////////////////////////

		void setOSName (std::string Str) {

			this->OSName = Str;

		}

		std::string getOSName (void) const {

			return this->OSName;

		} // set и get для OSName

	//////////////////////////////////////////////

		void setMenuFunctional (bool Flag) {

			this->MenuFunctional = Flag;

		}

		bool getMenuFunctional (void) const {

			return this->MenuFunctional;

		} // set и get для MenuFunctional

	//////////////////////////////////////////////

		void setTasksCount (unsigned short int Number) {

			this->TasksCount = Number;

		}

		unsigned short int getTasksCount (void) const {

			return this->TasksCount;

		} // set и get для TasksCount

	//////////////////////////////////////////////

		void setFinishedWorksCount (unsigned short int Number) {

			this->FinishedWorksCount = Number;

		}

		unsigned short int getFinishedWorksCount (void) const {

			return this->FinishedWorksCount;

		} // set и get для FinishedWorksCount

	//////////////////////////////////////////////

		void setUserNamePath (std::string Str) {

			this->UserNamePath = Str;

		}

		std::string getUserNamePath (void) const {

			return this->UserNamePath;

		} // set и get для UserNamePath;

	//////////////////////////////////////////////



};

#endif // _client_class_H_
