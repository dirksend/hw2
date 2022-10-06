#include <sstream>
#include <iomanip>
#include "../util.cpp"
#include "../product.cpp"
#include "product_clothing.h"

using namespace std;

ProductClothing::ProductClothing(
    const std::string name,
    double price,
    int qty,
    std::string size,
    std::string brand
) :
	Product("Clothing", name, price, qty),
	size_(size),
	brand_(brand)
{

}

ProductClothing::~ProductClothing()
{

}

std::set<std::string> ProductClothing::keywords() const {
    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> brandWords = parseStringToWords(brand_);
    std::set<std::string> words = setUnion(nameWords, brandWords);
    return words;
};

bool ProductBook::isMatch(std::vector<std::string>& searchTerms) const {
    return false;
};

std::string ProductBook::displayString() const {
    return ""
		+ category_ + ": " + name_ + " | (" + size_ + ")\n"
        +  "  Size: " + size_ + "\n";
};

void ProductBook::dump(std::ostream& os) const
{
    os << category_ << endl
       << name_ << endl
       << price_ << endl
       << qty_ << endl
       << size_ << endl
       << brand_ << endl;
}