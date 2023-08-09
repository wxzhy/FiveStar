//
// Created by zhu123 on 2023/8/9.
//

#ifndef FIVESTAR_TITLEINFO_H
#define FIVESTAR_TITLEINFO_H


class TitleInfo {
protected:
    char isbn[14], bookTitle[51], author[31], publisher[31];
public:
    TitleInfo(char *isbn, char *title, char *author, char *pub);

    TitleInfo();

    char *getIsbn();

    void setIsbn(char *isbn);

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
