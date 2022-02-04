// Модуль для формирования заказа. Именно здесь описан весь функционал кнопки "Создать заказ".

#pragma once

#ifndef _Menu_formation_order_h_
#define _Menu_formation_order_h_

const static bool Fill_InputData (Class_Clients& Client, const Class_BanLists& Banlists, const Class_Settings& Settings) {

	unsigned short int New_TasksCount = 0; // переменная отвечающая за созданное кол-во новых тасков
	unsigned short int ButtonNumber = 0; // переменная для обработки нажатий в меню
	unsigned short int OrderCost = 0; // стоимость заказа

        while (true) {

            cls ();
            Client.Clear_Client_Parameters ();

            CenterText ("Создание нового заказа\n");
            Show_Text_ForExit ();
            Show_Text_In_Right_Corner ("Press F5 to reload formation order");

            std::string Stroke = Show_Text_Input ("Имя клиента:   ", true);
            //Exception("Name0: " + Stroke);
                if (Check_Input_ForExit (Stroke)){
                        //Exception("Name1: " + Stroke);
                    return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

                }
                else if (Check_Input_ForReload (Stroke)){
                         //Exception("Name2: " + Stroke);
                    continue;

                }
            //Exception("Name3: " + Stroke);
            Stroke = GetExist_ClientName (Stroke, Settings, true);
           // Exception("Name4: " + Stroke);


                if (Banlists.Check_Client_inBanlists (Settings, Stroke)) {

                    Exception ("This person in ban-list");
                    return false;

                }

            Client.setName (Stroke);

            std::cout << "\n\nВыбор технологии: C / C++ / Another (C / + / A) ?:   ";

                while (true) {

                    ButtonNumber = getch ();

                        if (ClickCatch ("C", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_C ());
                            Show_Text_Output (Settings.getTechnology_Name_C ());
                            break;

                        }

                        else if (ClickCatch ("+", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_CPlusPlus ());
                            Show_Text_Output (Settings.getTechnology_Name_CPlusPlus ());
                            break;

                        }

                        else if (ClickCatch ("A", &ButtonNumber)) {

                            Client.setTechnology_Name (Settings.getTechnology_Name_Another());
                            Show_Text_Output (Settings.getTechnology_Name_Another());
                            break;

                        }

                        else if (ClickCatch ("Esc", &ButtonNumber))
                            return false;

                        else if (ClickCatch ("F5", &ButtonNumber))
                            break;

                }

                if (ClickCatch ("F5", &ButtonNumber))
                    continue;

                if (Client.getTechnology_Name () != Settings.getTechnology_Name_Another()) {

                    std::cout << "\n\n\nВыбор IDE: Visual Studio / Geany / Code::Blocks / QtCreator (V / G / C / Q) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("V", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_VisualStudio ());
                                    Show_Text_Output (Settings.getIDE_Name_VisualStudio ());
                                    break;

                                }

                                else if (ClickCatch ("G", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_Geany ());
                                    Show_Text_Output (Settings.getIDE_Name_Geany ());
                                    break;

                                }

                                else if (ClickCatch ("C", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_CodeBlocks ());
                                    Show_Text_Output (Settings.getIDE_Name_CodeBlocks ());
                                    break;

                                }

                                else if (ClickCatch ("Q", &ButtonNumber)) {

                                    Client.setIDE_Name (Settings.getIDE_Name_QtCreator ());
                                    Show_Text_Output (Settings.getIDE_Name_QtCreator ());
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\nВыбор ОС: Linux / Windows (L / W) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("L", &ButtonNumber)) {

                                    Client.setOS_Name (Settings.getOS_Name_Linux ());
                                    Show_Text_Output (Settings.getOS_Name_Linux ());
                                    break;

                                }

                                else if (ClickCatch ("W", &ButtonNumber)) {

                                    Client.setOS_Name (Settings.getOS_Name_Windows ());
                                    Show_Text_Output (Settings.getOS_Name_Windows ());
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                    std::cout << "\n\n\nДобавить базовый функционал для управления меню (Y / N) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("Y", &ButtonNumber)) {

                                    Client.setMenuFunctional (true);
                                    Show_Text_Output ("Yes\n");
                                    break;

                                }

                                else if (ClickCatch ("N", &ButtonNumber)) {

                                    Client.setMenuFunctional (false);
                                    Show_Text_Output ("No\n");
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                }

                else {

                    printf ("\n");
                    Client.setOS_Name (Settings.getOS_Name_Windows ());
                    Client.setIDE_Name (Settings.getIDE_Name_NoneIDE ());

                }

            GetNormal_Number_Value (&New_TasksCount, Stroke, "Количество заданий:   ", -1, 1000);

                if (Check_Input_ForReload (Stroke))
                    continue;

                if (Check_Input_ForExit (Stroke) || New_TasksCount == 0)
                    return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

            Client.setTasksCount (New_TasksCount);

                if (Client.getTasksCount () == 1) {

                    std::cout << "\n\nВыберите тип работы - лабораторная / курсовая / диплом (L / C / D) ?:   ";

                        while (true) {

                            ButtonNumber = getch ();

                                if (ClickCatch ("L", &ButtonNumber)) {

                                    Client.setTypeWork (Settings.getTypeWork_Name_LabWork ());
                                    Show_Text_Output ("лабораторная\n");
                                    break;

                                }

                                else if (ClickCatch ("C", &ButtonNumber)) {

                                    Client.setTypeWork (Settings.getTypeWork_Name_CourseWork ());
                                    Show_Text_Output ("курсовая\n");
                                    break;

                                }

                                else if (ClickCatch ("D", &ButtonNumber)) {

                                    Client.setTypeWork (Settings.getTypeWork_Name_Diploma ());
                                    Show_Text_Output ("диплом\n");
                                    break;

                                }

                                else if (ClickCatch ("Esc", &ButtonNumber))
                                    return false;

                                else if (ClickCatch ("F5", &ButtonNumber))
                                    break;

                        }

                        if (ClickCatch ("F5", &ButtonNumber))
                            continue;

                }

                else
                    Client.setTypeWork (Settings.getTypeWork_Name_LabWork ());

                for (unsigned short int i = 0; i < Client.getTasksCount (); i++) {

                        if (Client.getTasksCount () == 1)
                            GetNormal_Number_Value (&OrderCost, Stroke, "Введите стоимость заказа:   ", -1, 32000);

                        else if (Client.getTasksCount () > 1)
                            GetNormal_Number_Value (&OrderCost, Stroke, "Введите стоимость заказа (Task № " + Convert_Int_toString(i + 1) + "):   ", -1, 32000);

                    Show_Text_Output ("  руб");

                        if (Check_Input_ForReload (Stroke))
                            break;

                        if (Check_Input_ForExit (Stroke) || OrderCost == 0)
                            return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

                    Client.setOrder_Costs (OrderCost);

                }

                if (Check_Input_ForReload (Stroke))
                    continue;

                for (unsigned short int i = 0; i < Client.getTasksCount (); i++) {

                     Stroke = Show_Text_Input ("\n\nЗадайте через запятую ключевые слова (Task № " + Convert_Int_toString(i + 1) + "):   ", true);

                        if (Check_Input_ForExit (Stroke))
                            return false; // если было введено одно из службных слов для выхода - возврат в главное меню программы

                        else if (Check_Input_ForReload (Stroke))
                            break;

                     Client.setKeywords(Stroke);

                }

                if (Check_Input_ForReload (Stroke))
                    continue;

                if (Client.getMenuFunctional () == true && Client.getTasksCount () == 1) {

                    unsigned short int Count_MenuItems = 0;

                    GetNormal_Number_Value (&Count_MenuItems, Stroke, "Количество пунктов в меню:   ", -1, 100);

                        if (Check_Input_ForReload (Stroke))
                            break;

                        if (Check_Input_ForExit (Stroke) || Count_MenuItems == 0)
                            return false;

                    Client.setMenuItems_Count (Count_MenuItems);

                    Client.Clear_MenuItems_Title ();

                    std::cout << "\n\nНазвания к каждому пункту меню:\n";

                        for (unsigned short int i = 0; i < Count_MenuItems; i++) {

                            Stroke = Show_Text_Input (Convert_Int_toString (i + 1) + ")   ", true);

                                    if (Check_Input_ForReload (Stroke))
                                        break;

                                    if (Check_Input_ForExit (Stroke))
                                        return false;

                            Client.setMenuItems_Title (Stroke);

                        }

                        if (Check_Input_ForReload (Stroke))
                            continue;

                } // если в программе будет меню, и всего 1 задача по заказу

                if (Check_Input_ForReload (Stroke))
                    continue;

            break;

        } // конец жизненного цикла создания заказа

    return true;

} // функция заполнения данных по клиенту

const static void Menu_Formation_Order (const Class_Settings& Settings, const Class_BanLists& Banlists, bool* FirstOrderCreated) {

    Show_Text_ForExit ();
    Class_Clients Client; // инициализация объекта Client
    Class_Formation_Order Order; // инициализация объекта Order

        if (!Fill_InputData (Client, Banlists, Settings)) // заполнение данных по заказу
            return;

    Order.Create_NewOrder (Client, Settings);

        if (*FirstOrderCreated == false)
            *FirstOrderCreated = true;

} // функция формирования заказа

#endif // _Menu_formation_order_h_


