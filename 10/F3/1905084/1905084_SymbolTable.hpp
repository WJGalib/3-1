#include <iostream>
#include <cstring>
#include "1905084_ScopeTable.hpp"

using namespace std;

class SymbolTable {

    ScopeTable* curr;
    int bSize;

    SymbolInfo* lookUpScope (char* name, ScopeTable* scope) {
        SymbolInfo* s = scope->lookUp(name);
        if (s) return s;
        ScopeTable* scopeParent = scope->getParent();
        if (scopeParent) s = lookUpScope (name, scopeParent);
        return s; 
    };

    static void deleteList (ScopeTable* s) {
        ScopeTable* p = s->getParent();
        delete s;
        if (p) deleteList(p);
    };

    // bool insert (SymbolInfo* symbol) {
    //     return curr->insert(symbol);
    // };

public:

    SymbolTable (int bSize) {
        this->bSize = bSize;
        curr = new ScopeTable (bSize);
    };

    ~SymbolTable() {
        deleteList(curr);
    };

    void enterScope() {
        ScopeTable* newScope;
        newScope = new ScopeTable (bSize);
        newScope->setParent (curr);
        curr = newScope;
    };

    bool exitScope(bool redundant = false) {
        if (redundant) ScopeTable::notifyRedundant();
        cout << "exiting scope " << endl;
        ScopeTable* currParent = curr->getParent();
        if (currParent) {
            delete curr;
            this->curr = currParent;
            return true;
        };
        return false;
    };

    int getCurrScopeId() {
        return curr->getId();
    };

    bool insert (char* name, char* type) {
        return curr->insert (name, type);
    };

    bool insert (SymbolInfo* x) {
        return curr->insert(x);
    };

    bool insertToParentScope (SymbolInfo* x) {
        //cout << __LINE__ << endl;
        return curr->getParent()->insert(x);
    };  

    bool remove (char* name) {
        return curr->deleteKey(name);
    };

    SymbolInfo* lookUp (char* name) {
        return lookUpScope (name, this->curr);
    };

    SymbolInfo* lookUpCurrentScope (char* name) {
        SymbolInfo* s = curr->lookUp(name);
        return s; 
    };

    void printCurrScope(FILE* logout = stdout) {
        curr->print(logout);
    };

    void printAllScope(FILE* logout = stdout) {
        ScopeTable* scope = curr;
        while (scope) {
            scope->print(logout);
            scope = scope->getParent();
        }; 
    };
};