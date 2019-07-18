#pragma once

#ifndef _Menu_Statistics_h_
#define _Menu_Statistics_h_

const void Menu_Statistics (void) {

    Show_Text_ForExit ();

        while (true) {

            ButtonNumber = getch ();

                if (ClickCatch ("Esc", ButtonNumber))
                    return;

        }

} // функция статистики базы заказов и клиентов

#endif // _Menu_Statistics_h_
