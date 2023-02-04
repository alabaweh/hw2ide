//
// Created by alaba on 2/4/2023.
//

//ISBN
//Author

#ifndef TEST_BOOK_H
#define TEST_BOOK_H

#include <sstream>
#include <iomanip>
#include "Product.h"
#include "util.h"


class Book : public Product {


    protected:
        std::string ISBN_;
        std::string Author_;


public:
        Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
        virtual ~Book();

        /**
         * Returns the appropriate keywords that this product should be associated with
         */
        virtual std::set<std::string> keywords() const ;


        /**
         * Returns a string to display the product info for hits of the search
         */
        virtual std::string displayString() const;

        /**
         * Outputs the product info in the database format
         */
        virtual void dump(std::ostream& os) const;

};


#endif //TEST_BOOK_H
