#include <iostream>
#include <cstring>
#include "ArrayList.hpp"

using namespace std;

class SymbolInfo {    
    char *name, *type;
    SymbolInfo *next;
    ArrayList<SymbolInfo*> *children;
    bool isArrayType;
    int arraySize, startLine, endLine;
public:
    SymbolInfo (char* name, char* type) {
        this->name = name, this->type = type;
        this->next = nullptr, this->children = nullptr;
        this->isArrayType = false;
        this->arraySize = 0;
    };
    
    ~SymbolInfo() {
        delete[] name;
        delete[] type;
        //delete[] children;
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
    void setStartLine (int line) {
        this->startLine = line;
    };
    int getStartLine() {
        return this->startLine;
    };
    void setEndLine (int line) {
        this->endLine = line;
    };
    int getEndLine() {
        return this->endLine;
    };


    void addChild (SymbolInfo* c) {
        if (!this->children) this->children = new ArrayList<SymbolInfo*>();
        this->children->append(c);
    };

    ArrayList<SymbolInfo*> *getChildren() {
        return this->children;
    };

    void setArray (int size = 0) {
        this->isArrayType = true;
        this->arraySize = size;
    };
    bool isArray() {
        return this->isArrayType;
    };
    int getArraySize() {
        return this->arraySize;
    };

};
