//
// Created by zhu123 on 2023/8/9.
//

#ifndef FIVESTAR_MANAGEMENT_H
#define FIVESTAR_MANAGEMENT_H


class Management {
    void setTitle(char *title, int index);

    void setISBN(char *isbn, int index);

    void setAuthor(char *author, int index);

    void setPub(char *pub, int index);

    void setDateAdded(char *date, int index);

    void setQty(int qty, int index);

    void setWholesale(double wholesale, int index);

    void setRetail(double retail, int index);

    bool isEmpty(int index);

    void removeBook(int index);

};


#endif //FIVESTAR_MANAGEMENT_H
