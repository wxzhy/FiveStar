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
        header("����ģ��");
        cout << "1. ����б�" << endl;
        cout << "2. �������б�" << endl;
        cout << "3. ���ۼ��б�" << endl;
        cout << "4. ����������б�" << endl;
        cout << "5. ����ļ�ֵ���б�" << endl;
        cout << "6. �����������б�" << endl;
        cout << "7. ���ص����˵�" << endl;
        cout << "   ����ѡ��(1~7): ";
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
                cout << "�������" << endl;
        }
    }
}

void Report::listByWholeSale() {
    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getWholesale() > b.getWholesale(); });
    for (int i = 0; i < books.size(); i++) {
        header("�������");
        cout << "ISBN��: " << books[i].getISBN() << endl;
        cout << "��   ��: " << books[i].getTitle() << endl;
        cout << "�� �� ��: " << books[i].getQty() << endl;
        cout << "�� �� ��: " << books[i].getWholesale() << endl;
        cout << "�������ܶ�: " << books[i].getWholesale() * books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByRetail() {

    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getRetail() > b.getRetail(); });
    for (int i = 0; i < books.size(); i++) {
        header("�������");
        cout << "ISBN��: " << books[i].getISBN() << endl;
        cout << "��   ��: " << books[i].getTitle() << endl;
        cout << "�� �� ��: " << books[i].getQty() << endl;
        cout << "�� �� ��: " << books[i].getRetail() << endl;
        cout << "���ۼ��ܶ�: " << books[i].getRetail() * books[i].getQty() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }
}

void Report::listByQty() {
    sort(books.begin(), books.end(), [](BookData a, BookData b) { return a.getQty() > b.getQty(); });
    for (int i = 0; i < books.size(); i++) {
        header("�������");
        cout << "ISBN��: " << books[i].getISBN() << endl;
        cout << "��   ��: " << books[i].getTitle() << endl;
        cout << "�� �� ��: " << books[i].getQty() << endl;
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
        header("�������");
        cout << "ISBN��: " << books[i].getISBN() << endl;
        cout << "��   ��: " << books[i].getTitle() << endl;
        cout << "�� �� ��: " << books[i].getQty() << endl;
        cout << "�� �� ��: " << books[i].getWholesale() << endl;
        cout << "�������ܶ�: " << books[i].getWholesale() * books[i].getQty() << endl;
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
        header("�������");
        cout << "ISBN��: " << books[i].getISBN() << endl;
        cout << "��   ��: " << books[i].getTitle() << endl;
        cout << "��������: " << books[i].getDateAdded() << endl;
        if (i % 2 == 1) {
            if (toupper(getch()) == 'Q')
                return;
        }
    }

}
