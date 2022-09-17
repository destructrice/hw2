#include <sstream>
#include <iomanip>
#include "product.h"
#include "book.h"
#include "util.h"
using namespace std;
Book::Book(const std::string category, const std::string name1, double price1, int qty1, const std::string ISBN,
           const std::string author):
        Product(category, name1, price1, qty1), ISBN(ISBN), author(author)
{

}

double Book::getPrice() const
{
    return price_;
}

std::string Book::getName() const
{
    return name_;
}
std::string Book::getISBN() const
{
    return ISBN;
}
std::string Book::getAuthor() const
{
    return name_;
}


int Book::getQty() const
{
    return qty_;
}
std::set<std::string> Book::keywords() const{
    std::string keywords = ISBN + " " + author;
    return parseStringToWords(keywords);
}
std::string Book::displayString() const{
    return name_ + "\n" + "Author: " + author + " ISBN: " + ISBN + "\n" + "Price: " + to_string(price_) + " " + to_string(qty_) + " left";
}
void Book::dump(std::ostream& os) const{
    os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN << "\n" << author << endl;
}