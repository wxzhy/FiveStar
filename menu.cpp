//
// Created by zhu123 on 2023/8/9.
//
#include <iostream>

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
            saleMenu();
            break;
        default:
            cout << "�������" << endl;
            break;
    }
}

void saleMenu() {
    cout << ' ' * 30 << "ǰ̨����ģ��" << endl;

}

void checkoutMenu() {
    cout << endl;
}