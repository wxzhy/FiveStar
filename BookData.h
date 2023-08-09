//
// Created by zhu123 on 2023/8/9.
//

#ifndef FIVESTAR_BOOKDATA_H
#define FIVESTAR_BOOKDATA_H


#include "TitleInfo.h"

class BookData: public TitleInfo{
protected:
    char dateAdded[11];
    int qtyOnHand;
    double wholesale,retail;
public:
    BookData();
    BookData(char *isbn, char *title, char *author, char *pub, char *dateAdded, int qty, double wholesale,
             double retail);
    void setDateAdded(char *dateAdded);
    void setQty(int qty);
    void setWholesale(double wholesale);
    void setRetail(double retail);
    char *getDateAdded();
    int getQty();
    double getWholesale();
    double getRetail();
};



#endif //FIVESTAR_BOOKDATA_H
