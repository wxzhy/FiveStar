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
    cout << "1. ����ģ��" << endl;
    cout << "2. ������ģ��" << endl;
    cout << "3. ����ģ��" << endl;
    cout << "4. �˳�ϵͳ" << endl;
    cout << "   ����ѡ��(1~4): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "����ģ��" << endl;
            salesMenu();
            break;
        default:
            cout << "�������" << endl;
            break;
    }
}

void salesMenu() {
    cout << "                              ǰ̨����ģ��" << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "����: " << 1900 + ltm->tm_year << "��" << 1 + ltm->tm_mon << "��" << ltm->tm_mday << "��" << endl;

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