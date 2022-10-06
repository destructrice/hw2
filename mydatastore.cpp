
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "mydatastore.h"
#include "util.h"
using namespace std;
MyDataStore::MyDataStore() { }

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p){
    //only one iterator needed for this
    std::map<std::string, std::set<Product>>::iterator iter1;
    //loop through one set
    bool flag = false;
    for (iter1 = products.begin(); iter1 != products.end(); iter1++){
        //if there is a common product
        if(products.find(p->getName()) != products.end()) {
            //insert it in the set
            (products.at(p->getName())).insert(*p);
            flag = true;
        }
    }
    if(!flag){
        std::set<Product> toInsert;
        toInsert.insert(*p);
        std::map<std::string, std::set<Product>>::iterator it = products.begin();
        products.insert( std::pair<std::string, std::set<Product>>(p->getName(),toInsert) );
    }
}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u){
    std::map<std::string, User>::iterator iter1;
    //loop through one set
    bool flag = false;
    for (iter1 = users.begin(); iter1 != users.end(); iter1++){
        //if there is a common product
        if(users.find(u->getName()) != users.end()) {
            //don't do anything
            break;
        }

    }
    if(!flag){
        users.insert(std::pair<std::string, User>(u->getName(),*u));
    }
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::set<std::string> productKeys;
    std::set<std::string> termsSet;
    std::vector<Product*> productsToReturnForReal;
    std::map<std::string, std::set<Product>>::iterator iter1;
    for (iter1 = products.begin(); iter1 != products.end(); iter1++){
        productKeys.insert(iter1->first);
    }
    for (int i = 0; i < terms.size(); i++){
        termsSet.insert(terms.at(i));
    }
    std::set<std::string> results;
    if(type == 0){
        results = setIntersection(productKeys, termsSet);
    }
    else{
        results = setUnion(productKeys, termsSet);
    }
    std::set<std::string>::iterator iter2;
    for (iter2 = results.begin(); iter2 != results.end(); iter2++){
        string t = *iter2;
        if(products.find(t) != products.end()){
            std::copy(products.find(t)->second.begin(), products.find(t)->second.end(), productsToReturnForReal.begin());
        }
    }
    return productsToReturnForReal;



}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile){
    ofile << "<Products>" << endl;
    std::map<std::string, std::set<Product>>::iterator iter1;
    for (iter1 = products.begin(); iter1 != products.end(); iter1++){
        ofile << iter1->first << endl;
    }
}