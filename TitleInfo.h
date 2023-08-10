//
// Created by zhu123 on 2023/8/9.
//

#ifndef FIVESTAR_TITLEINFO_H
#define FIVESTAR_TITLEINFO_H


class TitleInfo {
protected:
    char bookTitle[51], author[31], publisher[31], isbn[14];
public:
    TitleInfo(char *isbn, char *title, char *author, char *pub);

    TitleInfo();

    char *getISBN();

    void setISBN(char *isbn);

    char *getTitle();

    void setTitle(char *title);

    char *getAuthor();

    void setAuthor(char *author);

    char *getPub();

    void setPub(char *pub);

    bool isEmpty();

    void removeBook();
};


#endif //FIVESTAR_TITLEINFO_H
