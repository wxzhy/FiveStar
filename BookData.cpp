//
// Created by zhu123 on 2023/8/9.
//

#include <cstring>
#include <iostream>
#include "BookData.h"

using namespace std;

BookData::BookData() {
    qtyOnHand = 0;
    wholesale = 0;
    retail = 0;
}

BookData::BookData(char *isbn, char *title, char *author, char *pub, char *dateAdded, int qty,
                   double wholesale, double retail) : TitleInfo(isbn, title, author, pub) {
    if (isdigit(dateAdded[0]) && isdigit(dateAdded[1]) && isdigit(dateAdded[2]) && isdigit(dateAdded[3]) &&
        dateAdded[4] == '-' && isdigit(dateAdded[5]) && isdigit(dateAdded[6]) && dateAdded[7] == '-' &&
        isdigit(dateAdded[8]) && isdigit(dateAdded[9]) && isdigit(dateAdded[10])) {
        strcpy(this->dateAdded, dateAdded);
        qtyOnHand = qty;
        this->wholesale = wholesale;
        this->retail = retail;
    }
}

void BookData::setDateAdded(char *dateAdded) {
    if (isdigit(dateAdded[0]) && isdigit(dateAdded[1]) && isdigit(dateAdded[2]) && isdigit(dateAdded[3]) &&
        dateAdded[4] == '-' && isdigit(dateAdded[5]) && isdigit(dateAdded[6]) && dateAdded[7] == '-' &&
        isdigit(dateAdded[8]) && isdigit(dateAdded[9]) && isdigit(dateAdded[10])) {
        strcpy(this->dateAdded, dateAdded);
    } else
        cout << "���ڸ�ʽ����" << endl;
}

void BookData::setQty(int qty) {
    if (qty >= 0)
        qtyOnHand = qty;
    else
        cout << "��������Ϊ����" << endl;
}

void BookData::setWholesale(double wholesale) {
    if (wholesale >= 0)
        this->wholesale = wholesale;
    else
        cout << "�����۲���Ϊ����" << endl;
}

void BookData::setRetail(double retail) {
if(retail>=0)
    this->retail=retail;
else
    cout << "���ۼ۲���Ϊ����" << endl;
}

char *BookData::getDateAdded() {
    return this->dateAdded;
}

int BookData::getQty() {
    return qtyOnHand;
}

double BookData::getWholesale() {
    return wholesale;
}

double BookData::getRetail() {
    return retail;
}

void BookData::BookInfo() {
    cout << "ISBN��: " << isbn << endl;
    cout << "��   ��: " << bookTitle << endl;
    cout << "��   ��: " << author << endl;
    cout << "�� �� ��: " << publisher << endl;
    cout << "��������: " << dateAdded << endl;
    cout << "�� �� ��: " << qtyOnHand << endl;
    cout << "�� �� ��: " << wholesale << endl;
    cout << "�� �� ��: " << retail << endl;
}
