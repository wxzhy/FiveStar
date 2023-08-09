//
// Created by zhu123 on 2023/8/9.
//

#ifndef FIVESTAR_SALE_H
#define FIVESTAR_SALE_H


#include "BookData.h"

class Sale: public BookData{
protected:
    int quantity;
    double subtotal;
public:
    Sale(int index, int quantity);

    Sale();

    void print();
};


#endif //FIVESTAR_SALE_H
