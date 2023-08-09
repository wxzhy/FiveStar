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
        cout << "数量必须大于0！" << endl;
    else if (getQty() <= 0)
        cout << "库存不足！" << endl;
    else if (quantity > getQty())
        cout << "数量超过库存！" << endl;
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
