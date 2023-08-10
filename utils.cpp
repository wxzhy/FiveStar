//
// Created by zhu123 on 2023/8/9.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include "globals.h"

using namespace std;

char *strUpper(char *str) {
    char *p = str;
    while (*p != '\0') {
        if (islower(*p))
            *p = toupper(*p);
        p++;
    }
    return str;
}

void loadBooks() {
    ifstream in("books.txt");
    if (in.fail()) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        exit(1);
    } else {
        while (!in.eof()) {
            BookData book;
            in >> book;
            books.emplace_back(book);
            cout << "���سɹ���" << endl;
        }
    }
}

void saveBooks() {
    ofstream out("books.txt");
    if (out.fail()) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        exit(1);
    } else {
        for (auto &book: books) {
            out << book;
        }
        cout << "����ɹ���" << endl;
    }
}

