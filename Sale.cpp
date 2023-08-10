//
// Created by zhu123 on 2023/8/9.
//

#include <iostream>
#include <iomanip>
#include "Sale.h"
#include "globals.h"

using namespace std;

Sale::Sale(int index, int quantity) : BookData(books[index]) {
    if (quantity <= 0)
        cout << "�����������0��" << endl;
    else if (getQty() <= 0)
        cout << "��治�㣡" << endl;
    else if (quantity > getQty())
        cout << "����������棡" << endl;
    else {
        this->quantity = quantity;
        books[index].setQty(getQty() - quantity);
        subtotal = quantity * getRetail();
    }
}

Sale::Sale() {
    quantity = 0;
    subtotal = 0;
}

void Sale::print() {
    cout << setw(10) << left << quantity
         << setw(15) << left << isbn
         << setw(30) << left << bookTitle << "RMB "
         << setw(6) << fixed << left << setprecision(2) << retail << "RMB "
         << setw(6) << fixed << left << setprecision(2) << subtotal << endl;

}

double Sale::getSubtotal() {
    if (subtotal > 0)
        return subtotal;
    else {
        cout << "С�Ʋ���Ϊ����" << endl;
        return 0;
    }
}

