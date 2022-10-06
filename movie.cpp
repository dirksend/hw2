#include <sstream>
#include <iomanip>
#include "util.cpp"
#include "product.cpp"
#include "movie.h"

using namespace std;

Movie::Movie(
    const std::string name,
    double price,
    int qty,
    std::string genre,
    std::string rating
) :
	Product("Movie", name, price, qty),
	genre_(genre),
	rating_(rating)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const {
    std::set<std::string> words = parseStringToWords(name_);
    words.insert(genre_));
    return words;
};

bool ProductBook::isMatch(std::vector<std::string>& searchTerms) const {
    return false;
};

std::string ProductBook::displayString() const {
    return ""
		+ category_ + ": " + name_ + " | (" + genre_ + ")\n"
        +  "  Rating: " + rating_ + "\n";
};

void ProductBook::dump(std::ostream& os) const
{
    os << category_ << endl
       << name_ << endl
       << price_ << endl
       << qty_ << endl
       << genre_ << endl
       << rating_ << endl;
}