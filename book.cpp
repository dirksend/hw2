#include <sstream>
#include <iomanip>
#include "util.cpp"
#include "product.cpp"
#include "book.h"

using namespace std;

Book::Book(
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

Book::~Book()
{

}

std::set<std::string> Book::keywords() const {
    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> authorWords = parseStringToWords(name_);
    std::set<std::string> words = setUnion(nameWords, authorWords);
    words.insert(isbn_);
    return words;
};

bool Book::isMatch(std::vector<std::string>& searchTerms) const {
    return false;
};

std::string Book::displayString() const {
    return ""
				+ category_ + ": " + name_ + " | (" + std::to_string(qty_) + ")\n"
        +  "  ISBN: " + isbn_ + "\n";
};

void Book::dump(std::ostream& os) const
{
    os << category_ << endl
       << name_ << endl
       << price_ << endl
       << qty_ << endl
       << isbn_ << endl
       << author_ << endl;
}