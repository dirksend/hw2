#ifndef PRODUCT_BOOK_H
#define PRODUCT_BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "../product.h"

class ProductBook : public Product {
public:
    ProductBook(
				const std::string name,
				double price,
				int qty,
				std::string isbn,
				std::string author
		);
    ~ProductBook();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    std::set<std::string> keywords() const;

    /**
     * Allows for a more detailed search beyond simple keywords
     */
    bool isMatch(std::vector<std::string>& searchTerms) const;

    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const;

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const;

protected:
    std::string isbn_;
    std::string author_;
};
#endif
