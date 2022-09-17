#include "movie.h"
#include <sstream>
#include <iomanip>
#include "product.h"
#include "util.h"
using namespace std;
Movie::Movie(const std::string category, const std::string name1, double price1, int qty1, const std::string genre,
                   const std::string rating) :
        Product(category, name1, price1, qty1), genre(genre), rating(rating)
{

}

double Movie::getPrice() const
{
    return price_;
}

std::string Movie::getName() const
{
    return name_;
}


int Movie::getQty() const
{
    return qty_;
}
std::set<std::string> Movie::keywords() const{
    std::string keywords = genre + " " + rating;
    return parseStringToWords(keywords);
}
std::string Movie::displayString() const{
    return name_ + "\n" + "Genre: " + genre + " Rating: " + rating + "\n" + "Price: " + to_string(price_) + " " + to_string(qty_) + " left";
}
void Movie::dump(std::ostream& os) const{
    os << "book" << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre << "\n" << rating << endl;
}