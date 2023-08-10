//
// Created by zhu123 on 2023/8/9.
//

#include <iostream>
#include <conio.h>
#include "Management.h"
#include "globals.h"
#include "menu.h"

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

void Management::lookUpBook() {
    cout << "��������: ";
    string title;
    cin >> title;
    for (auto &book: books) {
        if (book.getTitle() == title && !book.isEmpty()) {
            cout << "�ҵ�������:" << endl;
            book.BookInfo();
            return;
        }
    }
    cout << "δ�ҵ�!" << endl;
}

void Management::lookUp() {
    while (true) {
        cout << "ѡ�����ģʽ:" << endl;
        cout << "1. ����" << endl;
        cout << "2. �ؼ���" << endl;
        cout << "3. ģ������" << endl;
        cout << "4. �˳�" << endl;
        cout << "������: ";
        char choice = getch();
        cout << endl;
        switch (choice) {
            case '1':
                lookUpBook();
                break;
            case '2':
                lookUpKeyword();
                break;
            case '3':
                lookUpFuzzy();
                break;
            case '4':
                return;
            default:
                cout << "�������!" << endl;
        }
    }
}

void Management::lookUpKeyword() {
    cout << "����ؼ���: ";
    string keyword;
    cin >> keyword;
    vector<int> result;
    for (int i = 0; i < books.size(); i++) {
        if (string(books[i].getTitle()).find(keyword) != string::npos && !books[i].isEmpty()) {
            result.emplace_back(i);
        }
    }
    if (result.empty()) {
        cout << "δ�ҵ�!" << endl;
        return;
    } else {
        cout << "�ҵ�������:" << endl;
        for (auto &i: result) {
            books[i].BookInfo();
        }
    }
}

void Management::lookUpFuzzy() {
    cout << "����ؼ���: ";
    string keyword;
    cin >> keyword;
    vector<int> result;
    for (int i = 0; i < books.size(); i++) {
        if ((string(books[i].getTitle()).find(keyword) != string::npos ||
             string(books[i].getAuthor()).find(keyword) != string::npos ||
             string(books[i].getPub()).find(keyword) != string::npos) && !books[i].isEmpty()) {
            result.emplace_back(i);
        }
    }
    if (result.empty()) {
        cout << "δ�ҵ�!" << endl;
        return;
    } else {
        cout << "�ҵ�������:" << endl;
        for (auto &i: result) {
            books[i].BookInfo();
        }
    }
}

void Management::editBook() {
    cout << "����ؼ���: ";
    string keyword;
    cin >> keyword;
    vector<int> result;
    for (int i = 0; i < books.size(); i++) {
        if (string(books[i].getTitle()).find(keyword) != string::npos && !books[i].isEmpty()) {
            result.emplace_back(i);
        }
    }
    if (result.empty()) {
        cout << "δ�ҵ�!" << endl;
        return;
    } else {
        cout << "�ҵ�������,��������:" << endl;
        for (auto &i: result) {
            cout << books[i].getTitle() << endl;
        }
        cout << "���������: ";
        int index;
        cin >> index;
        if (index < 0 || index > result.size()) {
            cout << "������Χ!" << endl;
            return;
        } else {
            books[result[index - 1]].editBook();
        }
    }

}

void Management::deleteBook() {
    cout << "��������: ";
    string title;
    cin >> title;
    for (auto &book: books) {
        if (book.getTitle() == title && !book.isEmpty()) {
            book.removeBook();
            cout << "ɾ���ɹ�!" << endl;
            return;
        }
    }
    cout << "δ�ҵ�!" << endl;
}

void Management::removeBook() {
    cout << "����ISBN: ";
    string isbn;
    cin >> isbn;
    for (auto &book: books) {
        if (book.getISBN() == isbn && !book.isEmpty()) {
            book.removeBook();
            cout << "ɾ���ɹ�!" << endl;
            return;
        }
    }
    cout << "δ�ҵ�!" << endl;

}

void Management::menu() {
    header("������ģ��");
    cout << "1. ����ĳ�������Ϣ" << endl;
    cout << "2. ������" << endl;
    cout << "3. �޸������Ϣ" << endl;
    cout << "4. ɾ����" << endl;
    cout << "5. ���ص����˵�" << endl;
    cout << "����ѡ��(1~5): ";
    char choice = getch();
    cout << endl;
    switch (choice) {
        case '1':
            lookUp();
            break;
        case '2':
            addBook();
            break;
        case '3':
            editBook();
            break;
        case '4':
            deleteBook();
            break;
        case '5':
            return;
        default:
            cout << "�������!" << endl;
    }

}

void Management::addBook() {
    cout << "�Ƿ����ͼ��?(y/n): ";
    char choice = getch();
    cout << endl;
    switch (toupper(choice)) {
        case 'Y': {
            BookData book;
            cout << "�������µ�ISBN�ţ�";
            char isbn[14];
            cin >> isbn;
            for (auto &i: books) {
                if (i.getISBN() == isbn) {
                    cout << "ISBN�Ѵ���!" << endl;
                    return;
                }
            }
            book.setISBN(isbn);
            cout << "�������µ�������";
            char bookTitle[51];
            cin >> bookTitle;
            for (auto &i: books) {
                if (i.getTitle() == bookTitle) {
                    cout << "�����Ѵ���!" << endl;
                    return;
                }
            }
            book.setTitle(bookTitle);
            cout << "�������µ����ߣ�";
            char author[31];
            cin >> author;
            book.setAuthor(author);
            cout << "�������µĳ����磺";
            char publisher[31];
            cin >> publisher;
            book.setPub(publisher);
            cout << "�������µĽ������ڣ�";
            char date[11];
            cin >> date;
            if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) && date[4] == '-' &&
                isdigit(date[5]) && isdigit(date[6]) && date[7] == '-' && isdigit(date[8]) && isdigit(date[9])) {
                book.setDateAdded(date);
            } else {
                cout << "���ڸ�ʽ����" << endl;
                return;
            }
            cout << "�������µĿ������";
            int qtyOnHand;
            cin >> qtyOnHand;
            book.setQty(qtyOnHand);
            cout << "�������µ������ۣ�";
            double wholesale;
            cin >> wholesale;
            book.setWholesale(wholesale);
            cout << "�������µ����ۼۣ�";
            double retail;
            cin >> retail;
            book.setRetail(retail);
            books.emplace_back(book);
            cout << "��ӳɹ�!" << endl;
        }
            break;
        case 'n':
            return;
        default:
            cout << "�������!" << endl;
            return;
    }
}
