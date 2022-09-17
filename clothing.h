#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
class Clothing : public Product{
public:
    Clothing();
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
    double getPrice() const;
    std::string getName() const;
    int getQty() const;
    std::string getSize() const;
    std::string getBrand() const;
protected:
    std::string name_;
    std::string size;
    std::string brand;
    double price_;
    int qty_;


};
#endif //CLOTHING_H