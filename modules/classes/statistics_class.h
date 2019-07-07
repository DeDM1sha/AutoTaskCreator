// Класс базы данных всех клиентов и заказов, имеющихся в базе

#pragma once

#ifndef _statistics_class_h
#define _statistics_class_h

class Class_Statistics : public AbstractClass_Clients {

    private:

        unsigned short int TotalNumber_ClientsInBD_Count; // общее кол-во клиентов в базе
        unsigned short int TotalNumber_CompletedTasks_Count; // общее кол-во выполненных заданий со всех клиентов

    public:

        Class_Statistics () {

            TotalNumber_ClientsInBD_Count = 0;
			TotalNumber_CompletedTasks_Count = 0;

        }

        ~Class_Statistics (void) {



        }

        const void setTotalNumber_CompletedTasks_Count (const unsigned short int Number) {

			this->TotalNumber_CompletedTasks_Count = Number;

		} // сеттер для TotalNumber_CompletedTasks_Count

		const unsigned short int getTotalNumber_CompletedTasks_Count (void) const {

			return this->TotalNumber_CompletedTasks_Count;

		} // геттер для TotalNumber_CompletedTasks_Count

	//////////////////////////////////////////////

        const void setTotalNumber_ClientsInBD_Count (const unsigned short int Number) {

			this->TotalNumber_ClientsInBD_Count = Number;

		} // сеттер для TotalNumber_ClientsInBD_Count

		const unsigned short int getTotalNumber_ClientsInBD_Count (void) const {

			return this->TotalNumber_ClientsInBD_Count;

		} // геттер для TotalNumber_ClientsInBD_Count

	//////////////////////////////////////////////

        const unsigned short int Load_TotalNumber_ClientsInBD_Count (void) const;
        const unsigned short int Load_TotalNumber_CompletedTasks_Count (void) const;


}; // класс базы данных всех заказов

const unsigned short int Class_Statistics::Load_TotalNumber_ClientsInBD_Count (void) const {


    return 0;

} // метод подсчета кол-ва клиентов в базе

const unsigned short int Class_Statistics::Load_TotalNumber_CompletedTasks_Count (void) const {

    return 0;

} // метод подсчета кол-ва выполненных заданий в базе

#endif // _statistics_class_h
