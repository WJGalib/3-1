#include <iostream>
#include <cstring>
using namespace std;

class SymbolInfo {
    
    char* name;
    char* type;
    SymbolInfo *next;

public:
    void setName (char* name) {
        strcpy (this->name, name);
    };

    char* getName() {
        return this->name;
    };

    void setType (char* type) {
        strcpy (this->type, type);
    };

    char* getType() {
        return this->type;
    };
    
};

int main() {

}