//
// Created by zhu123 on 2023/8/9.
//

#include <cstring>
#include <iostream>
#include <conio.h>
#include "BookData.h"
#include "menu.h"

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
                                                                                 isdigit(dateAdded[8]) &&
                                                                                 isdigit(dateAdded[9])) {
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
    if (retail >= 0)
        this->retail = retail;
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
    header("�������");
    cout << "ISBN��: " << isbn << endl;
    cout << "��   ��: " << bookTitle << endl;
    cout << "��   ��: " << author << endl;
    cout << "�� �� ��: " << publisher << endl;
    cout << "��������: " << dateAdded << endl;
    cout << "�� �� ��: " << qtyOnHand << endl;
    cout << "�� �� ��: " << wholesale << endl;
    cout << "�� �� ��: " << retail << endl;
}

void BookData::editBook() {
    while (true) {
        cout << "��ǰ��Ϣ��" << endl;
        BookInfo();
        cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1. ISBN��" << endl;
        cout << "2. ��   ��" << endl;
        cout << "3. ��   ��" << endl;
        cout << "4. �� �� ��" << endl;
        cout << "5. ��������" << endl;
        cout << "6. �� �� ��" << endl;
        cout << "7. �� �� ��" << endl;
        cout << "8. �� �� ��" << endl;
        cout << "9. �˳�" << endl;
        cout << "����ѡ��(1-9): ";
        char choice = getch();
        cout << endl;
        switch (choice) {
            case '1': {
                cout << "�������µ�ISBN�ţ�";
                char isbn[14];
                cin >> isbn;
                setISBN(isbn);
                break;
            }
            case '2': {
                cout << "�������µ�������";
                char bookTitle[51];
                cin >> bookTitle;
                setTitle(bookTitle);
                break;
            }
            case '3': {
                cout << "�������µ����ߣ�";
                char author[31];
                cin >> author;
                setAuthor(author);
                break;
            }
            case '4': {
                cout << "�������µĳ����磺";
                char publisher[31];
                cin >> publisher;
                setPub(publisher);
                break;
            }
            case '5': {
                cout << "�������µĽ������ڣ�";
                char dateAdded[11];
                cin >> dateAdded;
                setDateAdded(dateAdded);
                break;
            }
            case '6': {
                cout << "�������µĿ������";
                int qtyOnHand;
                cin >> qtyOnHand;
                setQty(qtyOnHand);
                break;
            }
            case '7': {
                cout << "�������µ������ۣ�";
                double wholesale;
                cin >> wholesale;
                setWholesale(wholesale);
                break;
            }
            case '8': {
                cout << "�������µ����ۼۣ�";
                double retail;
                cin >> retail;
                setRetail(retail);
                break;
            }
            case '9':
                return;
            default:
                cout << "�������" << endl;
        }
    }

}

istream &operator>>(istream &in, BookData &book) {
    in >> book.isbn >> book.bookTitle >> book.author >> book.publisher >> book.dateAdded >> book.qtyOnHand
       >> book.wholesale >> book.retail;
    return in;
}

ostream &operator<<(ostream &out, BookData &book) {
    out << book.isbn << '\t' << book.bookTitle << '\t' << book.author << '\t' << book.publisher << '\t'
        << book.dateAdded << '\t' << book.qtyOnHand << '\t' << book.wholesale << '\t' << book.retail << endl;
    return out;
}
