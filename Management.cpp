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
        cout << "超出范围" << endl;
    else if (title[0] == '\0')
        cout << "书名不能为空" << endl;
    else
        books[index].setTitle(title);
}

void Management::setISBN(char *isbn, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else
        books[index].setISBN(isbn);
}

void Management::setAuthor(char *author, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;

    else
        books[index].setAuthor(author);
}

void Management::setPub(char *pub, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else
        books[index].setPub(pub);
}

void Management::setDateAdded(char *date, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) && date[4] == '-' &&
             isdigit(date[5]) && isdigit(date[6]) && date[7] == '-' && isdigit(date[8]) && isdigit(date[9]))
        books[index].setDateAdded(date);
    else
        cout << "日期格式错误！" << endl;
}

void Management::setQty(int qty, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else if (qty < 0)
        cout << "数量不能小于0！" << endl;
    else
        books[index].setQty(qty);
}

void Management::setWholesale(double wholesale, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else if (wholesale < 0)
        cout << "批发价不能小于0！" << endl;
    else
        books[index].setWholesale(wholesale);
}

void Management::setRetail(double retail, int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else if (retail < 0)
        cout << "零售价不能小于0！" << endl;
    else
        books[index].setRetail(retail);
}

bool Management::isEmpty(int index) {
    if (index < 0 || index > books.size()) {
        cout << "超出范围" << endl;
        return true;
    } else
        return books[index].isEmpty();
}

void Management::removeBook(int index) {
    if (index < 0 || index > books.size())
        cout << "超出范围" << endl;
    else
        books[index].removeBook();
}

void Management::lookUpBook() {
    cout << "输入书名: ";
    string title;
    cin >> title;
    for (auto &book: books) {
        if (book.getTitle() == title && !book.isEmpty()) {
            cout << "找到以下书:" << endl;
            book.BookInfo();
            return;
        }
    }
    cout << "未找到!" << endl;
}

void Management::lookUp() {
    while (true) {
        cout << "选择查找模式:" << endl;
        cout << "1. 书名" << endl;
        cout << "2. 关键字" << endl;
        cout << "3. 模糊查找" << endl;
        cout << "4. 退出" << endl;
        cout << "请输入: ";
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
                cout << "输入错误!" << endl;
        }
    }
}

void Management::lookUpKeyword() {
    cout << "输入关键字: ";
    string keyword;
    cin >> keyword;
    vector<int> result;
    for (int i = 0; i < books.size(); i++) {
        if (string(books[i].getTitle()).find(keyword) != string::npos && !books[i].isEmpty()) {
            result.emplace_back(i);
        }
    }
    if (result.empty()) {
        cout << "未找到!" << endl;
        return;
    } else {
        cout << "找到以下书:" << endl;
        for (auto &i: result) {
            books[i].BookInfo();
        }
    }
}

void Management::lookUpFuzzy() {
    cout << "输入关键字: ";
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
        cout << "未找到!" << endl;
        return;
    } else {
        cout << "找到以下书:" << endl;
        for (auto &i: result) {
            books[i].BookInfo();
        }
    }
}

void Management::editBook() {
    cout << "输入关键字: ";
    string keyword;
    cin >> keyword;
    vector<int> result;
    for (int i = 0; i < books.size(); i++) {
        if (string(books[i].getTitle()).find(keyword) != string::npos && !books[i].isEmpty()) {
            result.emplace_back(i);
        }
    }
    if (result.empty()) {
        cout << "未找到!" << endl;
        return;
    } else {
        cout << "找到以下书,书名如下:" << endl;
        for (auto &i: result) {
            cout << books[i].getTitle() << endl;
        }
        cout << "请输入序号: ";
        int index;
        cin >> index;
        if (index < 0 || index > result.size()) {
            cout << "超出范围!" << endl;
            return;
        } else {
            books[result[index - 1]].editBook();
        }
    }

}

void Management::deleteBook() {
    cout << "输入书名: ";
    string title;
    cin >> title;
    for (auto &book: books) {
        if (book.getTitle() == title && !book.isEmpty()) {
            book.removeBook();
            cout << "删除成功!" << endl;
            return;
        }
    }
    cout << "未找到!" << endl;
}

void Management::removeBook() {
    cout << "输入ISBN: ";
    string isbn;
    cin >> isbn;
    for (auto &book: books) {
        if (book.getISBN() == isbn && !book.isEmpty()) {
            book.removeBook();
            cout << "删除成功!" << endl;
            return;
        }
    }
    cout << "未找到!" << endl;

}

void Management::menu() {
    header("书库管理模块");
    cout << "1. 查找某本书的信息" << endl;
    cout << "2. 增加书" << endl;
    cout << "3. 修改书的信息" << endl;
    cout << "4. 删除书" << endl;
    cout << "5. 返回到主菜单" << endl;
    cout << "输入选择(1~5): ";
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
            cout << "输入错误!" << endl;
    }

}

void Management::addBook() {
    cout << "是否添加图书?(y/n): ";
    char choice = getch();
    cout << endl;
    switch (toupper(choice)) {
        case 'Y': {
            BookData book;
            cout << "请输入新的ISBN号：";
            char isbn[14];
            cin >> isbn;
            for (auto &i: books) {
                if (i.getISBN() == isbn) {
                    cout << "ISBN已存在!" << endl;
                    return;
                }
            }
            book.setISBN(isbn);
            cout << "请输入新的书名：";
            char bookTitle[51];
            cin >> bookTitle;
            for (auto &i: books) {
                if (i.getTitle() == bookTitle) {
                    cout << "书名已存在!" << endl;
                    return;
                }
            }
            book.setTitle(bookTitle);
            cout << "请输入新的作者：";
            char author[31];
            cin >> author;
            book.setAuthor(author);
            cout << "请输入新的出版社：";
            char publisher[31];
            cin >> publisher;
            book.setPub(publisher);
            cout << "请输入新的进书日期：";
            char date[11];
            cin >> date;
            if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) && date[4] == '-' &&
                isdigit(date[5]) && isdigit(date[6]) && date[7] == '-' && isdigit(date[8]) && isdigit(date[9])) {
                book.setDateAdded(date);
            } else {
                cout << "日期格式错误！" << endl;
                return;
            }
            cout << "请输入新的库存量：";
            int qtyOnHand;
            cin >> qtyOnHand;
            book.setQty(qtyOnHand);
            cout << "请输入新的批发价：";
            double wholesale;
            cin >> wholesale;
            book.setWholesale(wholesale);
            cout << "请输入新的零售价：";
            double retail;
            cin >> retail;
            book.setRetail(retail);
            books.emplace_back(book);
            cout << "添加成功!" << endl;
        }
            break;
        case 'n':
            return;
        default:
            cout << "输入错误!" << endl;
            return;
    }
}
