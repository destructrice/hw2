#include "clothing.h"
#include <sstream>
#include <iomanip>
#include "product.h"
#include "util.h"
using namespace std;
Clothing::Clothing(const std::string category, const std::string name1, double price1, int qty1, const std::string size,
           const std::string brand) :
        Product(category, name1, price1, qty1), size(size), brand(brand)
{

}
Product::~Product()
{

}
double Clothing::getPrice() const
{
    return price_;
}

std::string Clothing::getName() const
{
    return name_;
}


int Clothing::getQty() const
{
    return qty_;
}
std::set<std::string> Clothing::keywords() const{
    std::string keywords = size + " " + brand;
    return parseStringToWords(keywords);
}
std::string Clothing::displayString() const{
    return name_ + "\n" + "Size: " + size + " Brand: " + brand + "\n" + "Price: " + to_string(price_) + " " + to_string(qty_) + " left";
}
void Clothing::dump(std::ostream& os) const{
    os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << brand << "\n" << size << endl;
}