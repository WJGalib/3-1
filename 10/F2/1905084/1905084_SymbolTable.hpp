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
        ScopeTable* newScope = new ScopeTable (bSize);
        newScope->setParent (curr);
        curr = newScope;
    };

    bool exitScope() {
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

    bool remove (char* name) {
        return curr->deleteKey(name);
    };

    SymbolInfo* lookUp (char* name) {
        return lookUpScope (name, this->curr);
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