//
// Created by zhu123 on 2023/8/9.
//
#include <iostream>
#include<ctime>
#include"bookData.h"
#include"menu.h"
#include "globals.h"

void saleMenu();

using namespace std;

void mainMenu() {
    cout << "1. 收银模块" << endl;
    cout << "2. 书库管理模块" << endl;
    cout << "3. 报表模块" << endl;
    cout << "4. 退出系统" << endl;
    cout << "   输入选择(1~4): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "收银模块" << endl;
            salesMenu();
            break;
        default:
            cout << "输入错误！" << endl;
            break;
    }
}

void salesMenu() {
    cout << "                              前台销售模块" << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "日期: " << 1900 + ltm->tm_year << "年" << 1 + ltm->tm_mon << "月" << ltm->tm_mday << "日" << endl;

}

void checkoutMenu() {
    double total = 0.0, tax = 0.0, money = 0.0;
    for (auto &sale: sales) {
        if (!sale.isEmpty())
            total += sale.getSubtotal();
    }
    tax = total * taxRate;
    money = total + tax;
}