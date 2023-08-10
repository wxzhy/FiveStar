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
        header("���˵�");
        cout << "1. ����ģ��" << endl;
        cout << "2. ������ģ��" << endl;
        cout << "3. ����ģ��" << endl;
        cout << "4. �˳�ϵͳ" << endl;
        cout << "   ����ѡ��(1~4): ";
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
                break;
            case '4':
                return;
            default:
                cout << "�������" << endl;
        }
    }
}

void salesMenu() {
    while (true) {
//        system("timeout /t 1 && cls");
        header("����ģ��");
        if (sales.empty()) {
            cout << "�Ƿ���ͼ��(y/n): ";
        } else {
            cout << "�Ƿ��������ͼ��(y/n): ";
        }
        char choice = getch();
        cout << endl;
        switch (toupper(choice)) {
            case 'Y':
                finder();
                break;
            case 'N': {
                if (sales.empty()) {
                    cout << "δ�����κ�ͼ�飡" << endl;
                    return;
                } else {
                    totalMenu();
                    return;
                }
            }
            default:
                cout << "�������" << endl;
//                system("pause");
        }
    }

}

void totalMenu() {
    cout << "                              ǰ̨����ģ��" << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "����: " << 1900 + ltm->tm_year << "��" << 1 + ltm->tm_mon << "��" << ltm->tm_mday << "��" << endl;
    cout << setw(10) << left << "����"
         << setw(15) << left << "ISBN��"
         << setw(30) << left << "����"
         << setw(10) << left << "����"
         << setw(10) << left << "���" << endl;
    double total = 0.0, tax = 0.0, money = 0.0;
    for (auto &sale: sales) {
        if (!sale.isEmpty())
            sale.print();
            total += sale.getSubtotal();
    }
    tax = total * taxRate;
    money = total + tax;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "���ۺϼ�: RMB " << setprecision(1) << fixed << total << endl;
    cout << "����˰:  RMB " << setprecision(1) << fixed << tax << endl;
    cout << "Ӧ���ܶ�: RMB " << setprecision(1) << fixed << money << endl;
    sales.clear();
}

void header(const char *str) {
    cout << endl;
    cout << "    FIVESTARͼ�����ϵͳ" << endl;
    cout << "            " << str << endl;
}

void finder() {
    cout << endl << "����ISBN: ";
    string isbn;
    cin >> isbn;
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].getISBN() == isbn && !books[i].isEmpty()) {
            if (books[i].getQty() <= 0)
                cout << "����������" << endl;
            else {
                cout << "�ҵ�������:" << endl;
                books[i].BookInfo();
                cout << "���빺������: ";
                int qty;
                cin >> qty;
                if (qty <= 0) {
                    cout << "�������! " << endl;
                } else if (qty > books[i].getQty())
                    cout << "��治�㣡" << endl;
                else {
                    sales.emplace_back(i, qty);
                    cout << "��ӳɹ�" << endl;
                }
            }
//            system("timeout /t 1 >nul");
            return;
        }
    }
    cout << "δ�ҵ�����" << endl;
//    system("pause>nul");
}

