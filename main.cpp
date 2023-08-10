#include <iostream>
#include "globals.h"
#include "menu.h"
#include "utils.h"

vector<BookData> books;
vector<Sale> sales;
double taxRate = 0.06;
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    check();
    loadBooks();
    mainMenu();
    saveBooks();
    system("pause");
    return 0;
}
