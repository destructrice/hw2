#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
class Movie : public Product{
public:
    Movie();
    Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
    std::set<std::string> keywords() const;
     std::string displayString() const;
    void dump(std::ostream& os) const;

    double getPrice() const;
    std::string getName() const;
    int getQty() const;
    std::string getGenre() const;
    std::string getRating() const;
protected:
    std::string name_;
    std::string genre;
    std::string rating;
    double price_;
    int qty_;


};
#endif //MOVIE_H