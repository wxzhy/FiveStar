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
            default:
                cout << "�������" << endl;
        }
    }
}

void Report::listByWholeSale() {


}
