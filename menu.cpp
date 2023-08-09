//
// Created by zhu123 on 2023/8/9.
//
#include <iostream>

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
            saleMenu();
            break;
        default:
            cout << "输入错误！" << endl;
            break;
    }
}

void saleMenu() {
    cout << ' ' * 30 << "前台销售模块" << endl;

}

void checkoutMenu() {
    cout << endl;
}