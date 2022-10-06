#ifndef DATASTORE_AMAZON_H
#define DATASTORE_AMAZON_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"

class DataStoreAmazon : DataStore {
public:
    ~DataStoreAmazon() { }
    void addProduct(Product* p) = 0;
    void addUser(User* u) = 0;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) = 0;
    void dump(std::ostream& ofile) = 0;
    
private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::map<std::string, std::vector<Product*>> keywords_;
};

#endif
