//
// Created by zhu123 on 2023/8/9.
//

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cstring>
#include "Report.h"
#include "globals.h"
#include "menu.h"

void Report::display() {
    for (int i = 0; i < books.size(); i++) {
        books[i].BookInfo();
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
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
            case '2':
                listByWholeSale();
                break;
            case '3':
                listByRetail();
                break;
            case '4':
                listByQty();
                break;
            case '5':
                listByTotal();
                break;
            case '6':
                listByDate();
                break;
            case '7':
                return;
            default:
                cout << "输入错误！" << endl;
        }
    }
}

void Report::listByWholeSale() {
    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getWholesale() > b.getWholesale(); });
    for (int i = 0; i < books.size(); i++) {
        header("书的资料");
        cout << "ISBN号: " << books[i].getISBN() << endl;
        cout << "书   名: " << books[i].getTitle() << endl;
        cout << "库 存 量: " << books[i].getQty() << endl;
        cout << "批 发 价: " << books[i].getWholesale() << endl;
        cout << "批发价总额: " << books[i].getWholesale() * books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByRetail() {

    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getRetail() > b.getRetail(); });
    for (int i = 0; i < books.size(); i++) {
        header("书的资料");
        cout << "ISBN号: " << books[i].getISBN() << endl;
        cout << "书   名: " << books[i].getTitle() << endl;
        cout << "库 存 量: " << books[i].getQty() << endl;
        cout << "零 售 价: " << books[i].getRetail() << endl;
        cout << "零售价总额: " << books[i].getRetail() * books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByQty() {
    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getQty() > b.getQty(); });
    for (int i = 0; i < books.size(); i++) {
        header("书的资料");
        cout << "ISBN号: " << books[i].getISBN() << endl;
        cout << "书   名: " << books[i].getTitle() << endl;
        cout << "库 存 量: " << books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByTotal() {
    sort(books.begin(), books.end(),
         [](BookData a, BookData b) { return a.getWholesale() * a.getQty() > b.getWholesale() * b.getQty(); });
    for (int i = 0; i < books.size(); i++) {
        header("书的资料");
        cout << "ISBN号: " << books[i].getISBN() << endl;
        cout << "书   名: " << books[i].getTitle() << endl;
        cout << "库 存 量: " << books[i].getQty() << endl;
        cout << "批 发 价: " << books[i].getWholesale() << endl;
        cout << "批发价总额: " << books[i].getWholesale() * books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByDate() {
    sort(books.begin(), books.end(),
         [](BookData a, BookData b) { return strcmp(a.getDateAdded(), b.getDateAdded()) > 0; });
    for (int i = 0; i < books.size(); i++) {
        header("书的资料");
        cout << "ISBN号: " << books[i].getISBN() << endl;
        cout << "书   名: " << books[i].getTitle() << endl;
        cout << "进书日期: " << books[i].getDateAdded() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }

}
