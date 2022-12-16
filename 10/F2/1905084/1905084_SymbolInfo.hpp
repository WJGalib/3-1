#include <iostream>
#include <cstring>

using namespace std;

class SymbolInfo {    
    char *name, *type;
    SymbolInfo* next;
public:
    SymbolInfo (char* name, char* type) {
        this->name = name, this->type = type;
        this->next = nullptr;
    };
    ~SymbolInfo() {
        delete[] name;
        delete[] type;
        //cout << "symbol deleted!!!" << endl;
    };
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
    SymbolInfo* getNext() {
        return this->next;
    }; 
    void setNext (SymbolInfo* x) {
        this->next = x;
    };
};
