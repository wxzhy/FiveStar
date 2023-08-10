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
                return;
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
    double total = 0.0, tax = 0.0, money = 0.0;
    for (auto &sale: sales) {
        if (!sale.isEmpty())
            total += sale.getSubtotal();
    }
    tax = total * taxRate;
    money = total + tax;
    cout << "���ۺϼ�: RMB " << setprecision(1) << total << endl;
    cout << "����˰:  RMB " << setprecision(1) << tax << endl;
    cout << "Ӧ���ܶ�: RMB " << setprecision(1) << money << endl;
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
    for (auto &book: books) {
        if (book.getISBN() == isbn && !book.isEmpty()) {
            if (book.getQty() <= 0)
                cout << "����������" << endl;
            else {
                cout << "�ҵ�������:" << endl;
                book.BookInfo();
                cout << "���빺������: ";
                int qty;
                cin >> qty;
                if (qty <= 0) {
                    cout << "�������! " << endl;
                } else if (qty > book.getQty())
                    cout << "��治�㣡" << endl;
                else {
                    sales.emplace_back(book, qty);
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

