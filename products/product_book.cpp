#include <sstream>
#include <iomanip>
#include "../util.cpp"
#include "../product.cpp"
#include "product_book.h"

using namespace std;

ProductBook::ProductBook(
    const std::string name,
    double price,
    int qty,
    std::string isbn,
    std::string author
) :
	Product("Book", name, price, qty),
	isbn_(isbn),
	author_(author)
{

}

ProductBook::~ProductBook()
{

}

std::set<std::string> ProductBook::keywords() const {
    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> authorWords = parseStringToWords(name_);
    std::set<std::string> words = setUnion(nameWords, authorWords);
    words.insert(isbn_);
    return words;
};

bool ProductBook::isMatch(std::vector<std::string>& searchTerms) const {
    return false;
};

std::string ProductBook::displayString() const {
    return ""
				+ category_ + ": " + name_ + " | (" + std::to_string(qty_) + ")\n"
        +  "  ISBN: " + isbn_ + "\n";
};

void ProductBook::dump(std::ostream& os) const
{
    os << category_ << endl
       << name_ << endl
       << price_ << endl
       << qty_ << endl
       << isbn_ << endl
       << author_ << endl;
}