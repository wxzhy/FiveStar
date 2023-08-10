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
    cout << "  " << setw(6) << quantity << setw(13) << isbn << setw(20) << bookTitle << "RMB " << setw(8)
         << setprecision(1) << fixed << retail << "RMB " << setprecision(1) << fixed << subtotal << endl;

}

double Sale::getSubtotal() {
    if (subtotal > 0)
        return subtotal;
    else {
        cout << "С�Ʋ���Ϊ����" << endl;
        return 0;
    }
}

Sale::Sale(BookData book, int quantity) {
    if (quantity <= 0)
        cout << "�����������0��" << endl;
    else if (book.getQty() <= 0)
        cout << "��治�㣡" << endl;
    else if (quantity > book.getQty())
        cout << "����������棡" << endl;
    else {
        this->quantity = quantity;
        book.setQty(book.getQty() - quantity);
        subtotal = quantity * book.getRetail();
    }
}
