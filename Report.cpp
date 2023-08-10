//
// Created by zhu123 on 2023/8/9.
//

#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Report.h"
#include "globals.h"
#include "menu.h"

void Report::display() {
    for (int i = 0; i < books.size(); i++) {
        books[i].BookInfo();
        if (i % 2 == 1) {
            getch();
        }
    }
}

void Report::menu() {
    while (true) {
        header("报表模块");
        cout << "1. 书库列表" << endl;
        cout << "2. 批发价列表" << endl;
        cout << "3. 零售价列表" << endl;
        cout << "4. 按书的数量列表" << endl;
        cout << "5. 按书的价值额列表" << endl;
        cout << "6. 按进书日期列表" << endl;
        cout << "7. 返回到主菜单" << endl;
        cout << "   输入选择(1~7): ";
        char choice = getch();
        cout << endl;
        switch (choice) {
            case '1':
                display();
                break;
            default:
                cout << "输入错误！" << endl;
        }
    }
}

void Report::listByWholeSale() {


}
