#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "mydatastore.h"

MyDataStore::~MyDataStore() { }

void MyDataStore::addProduct(Product* p) {
    products_.push_back(p);

    std::set<std::string> terms = p->keywords();

    for (std::string term : terms) {
        auto search = keywords_.find(term);
        if (search == keywords_.end()) {
            auto newVec = std::set<Product*>({p});
            auto newPair = std::pair<std::string, std::set<Product*>>(term, newVec);
            keywords_.insert(newPair);
        } else {
            search->second.insert(p);
        }
    }
}

void MyDataStore::addUser(User* u) {
    users_.push_back(u);
}

// AND=0, OR=1
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    std::set<Product*> matches;

    for (std::string term : terms) {
        auto search = keywords_.find(term);
        if (search != keywords_.end()) {
            std::set<Product*> prodSet = search->second;
            if (type == 0) {
                // AND
                matches = setIntersection(matches, prodSet);
            } else {
                // AND
                matches = setUnion(matches, prodSet);
            }
        }
    }

    std::vector<Product*> matchesVec(matches.size());
    std::copy(matches.begin(), matches.end(), matchesVec.begin());
    return matchesVec;
}

void MyDataStore::dump(std::ostream& ofile) {

};