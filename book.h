#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
class Book : public Product{
public:
    //constructors
    Book();
    Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author);
    //methods to implement
    std::set<std::string> keywords() const;
     std::string displayString() const;
    void dump(std::ostream& os) const;
    //getters
    double getPrice() const;
    std::string getName() const;
    int getQty() const;
    std::string getISBN() const;
    std::string getAuthor() const;
protected:
    std::string name_;
    std::string ISBN;
    std::string author;
    double price_;
    int qty_;


};
#endif //BOOK_H