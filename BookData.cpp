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
        cout << "日期格式错误！" << endl;
}

void BookData::setQty(int qty) {
    if (qty >= 0)
        qtyOnHand = qty;
    else
        cout << "数量不能为负！" << endl;
}

void BookData::setWholesale(double wholesale) {
    if (wholesale >= 0)
        this->wholesale = wholesale;
    else
        cout << "批发价不能为负！" << endl;
}

void BookData::setRetail(double retail) {
    if (retail >= 0)
        this->retail = retail;
    else
        cout << "零售价不能为负！" << endl;
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
    header("书的资料");
    cout << "ISBN号: " << isbn << endl;
    cout << "书   名: " << bookTitle << endl;
    cout << "作   者: " << author << endl;
    cout << "出 版 社: " << publisher << endl;
    cout << "进书日期: " << dateAdded << endl;
    cout << "库 存 量: " << qtyOnHand << endl;
    cout << "批 发 价: " << wholesale << endl;
    cout << "零 售 价: " << retail << endl;
}

void BookData::editBook() {
    while (true) {
        cout << "当前信息：" << endl;
        BookInfo();
        cout << "请选择要修改的信息：" << endl;
        cout << "1. ISBN号" << endl;
        cout << "2. 书   名" << endl;
        cout << "3. 作   者" << endl;
        cout << "4. 出 版 社" << endl;
        cout << "5. 进书日期" << endl;
        cout << "6. 库 存 量" << endl;
        cout << "7. 批 发 价" << endl;
        cout << "8. 零 售 价" << endl;
        cout << "9. 退出" << endl;
        cout << "输入选择(1-9): ";
        char choice = getch();
        cout << endl;
        switch (choice) {
            case '1': {
                cout << "请输入新的ISBN号：";
                char isbn[14];
                cin >> isbn;
                setISBN(isbn);
                break;
            }
            case '2': {
                cout << "请输入新的书名：";
                char bookTitle[51];
                cin >> bookTitle;
                setTitle(bookTitle);
                break;
            }
            case '3': {
                cout << "请输入新的作者：";
                char author[31];
                cin >> author;
                setAuthor(author);
                break;
            }
            case '4': {
                cout << "请输入新的出版社：";
                char publisher[31];
                cin >> publisher;
                setPub(publisher);
                break;
            }
            case '5': {
                cout << "请输入新的进书日期：";
                char dateAdded[11];
                cin >> dateAdded;
                setDateAdded(dateAdded);
                break;
            }
            case '6': {
                cout << "请输入新的库存量：";
                int qtyOnHand;
                cin >> qtyOnHand;
                setQty(qtyOnHand);
                break;
            }
            case '7': {
                cout << "请输入新的批发价：";
                double wholesale;
                cin >> wholesale;
                setWholesale(wholesale);
                break;
            }
            case '8': {
                cout << "请输入新的零售价：";
                double retail;
                cin >> retail;
                setRetail(retail);
                break;
            }
            case '9':
                return;
            default:
                cout << "输入错误！" << endl;
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
