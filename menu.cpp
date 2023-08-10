//
// Created by zhu123 on 2023/8/9.
//
#include <iostream>
#include<ctime>
#include <iomanip>
#include<conio.h>
#include"bookData.h"
#include"menu.h"
#include "globals.h"
#include "Management.h"
#include "Report.h"

void saleMenu();

using namespace std;

void mainMenu() {
    while (true) {
        header("主菜单");
        cout << "1. 收银模块" << endl;
        cout << "2. 书库管理模块" << endl;
        cout << "3. 报表模块" << endl;
        cout << "4. 退出系统" << endl;
        cout << "   输入选择(1~4): ";
        char choice = getch();
        cout << endl;
        switch (choice) {
            case '1':
                salesMenu();
                break;
            case '2':
                Management().menu();
                break;
            case '3':
                Report().menu();
                return;
            case '4':
                return;
            default:
                cout << "输入错误！" << endl;
        }
    }
}

void salesMenu() {
    while (true) {
//        system("timeout /t 1 && cls");
        header("收银模块");
        if (sales.empty()) {
            cout << "是否购买图书(y/n): ";
        } else {
            cout << "是否继续购买图书(y/n): ";
        }
        char choice = getch();
        cout << endl;
        switch (toupper(choice)) {
            case 'Y':
                finder();
                break;
            case 'N': {
                if (sales.empty()) {
                    cout << "未购买任何图书！" << endl;
                    return;
                } else {
                    totalMenu();
                    return;
                }
            }
            default:
                cout << "输入错误！" << endl;
//                system("pause");
        }
    }

}

void totalMenu() {
    cout << "                              前台销售模块" << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "日期: " << 1900 + ltm->tm_year << "年" << 1 + ltm->tm_mon << "月" << ltm->tm_mday << "日" << endl;
    double total = 0.0, tax = 0.0, money = 0.0;
    for (auto &sale: sales) {
        if (!sale.isEmpty())
            total += sale.getSubtotal();
    }
    tax = total * taxRate;
    money = total + tax;
    cout << "销售合计: RMB " << setprecision(1) << total << endl;
    cout << "零售税:  RMB " << setprecision(1) << tax << endl;
    cout << "应付总额: RMB " << setprecision(1) << money << endl;
}

void header(const char *str) {
    cout << endl;
    cout << "    FIVESTAR图书管理系统" << endl;
    cout << "            " << str << endl;
}

void finder() {
    cout << endl << "输入ISBN: ";
    string isbn;
    cin >> isbn;
    for (auto &book: books) {
        if (book.getISBN() == isbn && !book.isEmpty()) {
            if (book.getQty() <= 0)
                cout << "该书已售完" << endl;
            else {
                cout << "找到以下书:" << endl;
                book.BookInfo();
                cout << "输入购买数量: ";
                int qty;
                cin >> qty;
                if (qty <= 0) {
                    cout << "输入错误! " << endl;
                } else if (qty > book.getQty())
                    cout << "库存不足！" << endl;
                else {
                    sales.emplace_back(book, qty);
                    cout << "添加成功" << endl;
                }
            }
//            system("timeout /t 1 >nul");
            return;
        }
    }
    cout << "未找到该书" << endl;
//    system("pause>nul");
}

