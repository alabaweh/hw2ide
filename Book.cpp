//
// Created by alaba on 2/4/2023.
//

#include "Book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, string isbn, string author ):
        Product("book", name, price, qty), ISBN_(isbn), Author_(author){};


Book::~Book(){

};

/**
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Book::keywords() const {
    std::set<std::string> keywords;

    std::set<std::string> name_keywords=parseStringToWords(name_);
    std::set<std::string> author_keywords=parseStringToWords(Author_);

   return setUnion(name_keywords,author_keywords);

};


/**
 * Returns a string to display the product info for hits of the search
 */
std::string Book::displayString() const{

    std::ostringstream ss;

    ss << name_ << endl;
    ss <<"Author: "<< Author_ << endl;
    ss <<"ISBN: "<< ISBN_ << endl;
    ss <<"Price: "<< price_ << endl;
    ss <<"Quantity: "<< qty_ << endl;


    return ss.str();

};

/**
 * Outputs the product info in the database format
 */
void Book::dump(std::ostream& os) const {

    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ <<
   ISBN_ << "\n" << Author_ <<endl;

};
