//
// Created by zhu123 on 2023/8/9.
//

#include <iostream>
#include "Management.h"
#include "globals.h"

void Management::setTitle(char *title, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else if (title[0] == '\0')
        cout << "��������Ϊ��" << endl;
    else
        books[index].setTitle(title);
}

void Management::setISBN(char *isbn, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else
        books[index].setISBN(isbn);
}

void Management::setAuthor(char *author, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;

    else
        books[index].setAuthor(author);
}

void Management::setPub(char *pub, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else
        books[index].setPub(pub);
}

void Management::setDateAdded(char *date, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) && date[4] == '-' &&
             isdigit(date[5]) && isdigit(date[6]) && date[7] == '-' && isdigit(date[8]) && isdigit(date[9]))
        books[index].setDateAdded(date);
    else
        cout << "���ڸ�ʽ����" << endl;
}

void Management::setQty(int qty, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else if (qty < 0)
        cout << "��������С��0��" << endl;
    else
        books[index].setQty(qty);
}

void Management::setWholesale(double wholesale, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else if (wholesale < 0)
        cout << "�����۲���С��0��" << endl;
    else
        books[index].setWholesale(wholesale);
}

void Management::setRetail(double retail, int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else if (retail < 0)
        cout << "���ۼ۲���С��0��" << endl;
    else
        books[index].setRetail(retail);
}

bool Management::isEmpty(int index) {
    if (index < 0 || index > books.size()) {
        cout << "������Χ" << endl;
        return true;
    } else
        return books[index].isEmpty();
}

void Management::removeBook(int index) {
    if (index < 0 || index > books.size())
        cout << "������Χ" << endl;
    else
        books[index].removeBook();
}
