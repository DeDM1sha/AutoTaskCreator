#pragma once

#ifndef _Menu_Search_tasks_h_
#define _Menu_Search_tasks_h_

const void Menu_Search_Tasks (void) {

    Show_Text_ForExit ();

        while (true) {

            ButtonNumber = getch ();

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

        }



} // функция поиска заказа / задания

#endif // _Menu_Search_tasks_h_
