#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"

DataStoreAmazon::~DataStoreAmazon() { }

void DataStoreAmazon::addProduct(Product* p) {
    products_.push_back(p);

    std::set<std::string> terms = p->keywords();

    for (auto term : terms) {
				std::vector<Product*> prodList = keywords_.find(term);
        if (prodList == keywords_.end()) {
            terms.insert({std::pair{term, p}});
        } else {
            prodList.push_back(p);
        }
    }
}

void DataStoreAmazon::addUser(User* u) {
    users_.insert(u);
}

std::vector<Product*> DataStoreAmazon::search(std::vector<std::string>& terms, int type) {
    std::vector<Product*> matches;

    // for term in terms, matches = (union or intersection) of matches and term
    return matches;
}

void DataStoreAmazon::dump(std::ostream& ofile) {

};