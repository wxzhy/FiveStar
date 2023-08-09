//
// Created by zhu123 on 2023/8/9.
//

#include "TitleInfo.h"
#include <cstring>

using namespace std;

TitleInfo::TitleInfo(char *isbn, char *title, char *author, char *pub) {
    if (title[0] != '\0') {
        strcpy(this->bookTitle, title);
        strcpy(this->isbn, isbn);
        strcpy(this->author, author);
        strcpy(this->publisher, pub);
    }
}

TitleInfo::TitleInfo() {
    bookTitle[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
}

void TitleInfo::setTitle(char *title) {
    if (title[0] != '\0')
        strcpy(bookTitle, title);
}

void TitleInfo::setIsbn(char *isbn) {
    strcpy(this->isbn, isbn);
}

void TitleInfo::setAuthor(char *author) {
    strcpy(this->author, author);
}

void TitleInfo::setPub(char *pub) {
    strcpy(publisher, pub);
}

char *TitleInfo::getIsbn() {
    return isbn;
}

char *TitleInfo::getTitle() {
    return bookTitle;
}

char *TitleInfo::getAuthor() {
    return author;
}

char *TitleInfo::getPub() {
    return publisher;
}

bool TitleInfo::isEmpty() {
    if (bookTitle[0] == '\0')
        return true;
    else
        return false;
}

void TitleInfo::removeBook() {
    bookTitle[0] = '\0';
}

