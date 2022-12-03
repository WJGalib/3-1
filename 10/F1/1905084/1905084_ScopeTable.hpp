#include <iostream>
#include <cstring>
#include "1905084_SymbolInfo.hpp"

using namespace std;

class ScopeTable {

    int N, id;
    SymbolInfo** T;
    ScopeTable* parentScope;

    inline static int currId = 0;

    static unsigned int h1 (char* a, int N) {
        unsigned int h = 0, i, len = strlen(a);
        for (i=0; i<len; i++) h = (a[i] + (h<<6) + (h<<16) - h) % N;
        return h;
    };

    static void deleteChain (SymbolInfo* s) {
        SymbolInfo* next = s->getNext();
        delete s;
        if (next) deleteChain(next);
    };

public:

    ScopeTable (int N) {
        this->N = N;
        this->id = ++currId;
        this->parentScope = nullptr;
        this->T = new SymbolInfo* [N];
        for (int i=0; i<N; i++) T[i] = nullptr;
        cout << "\tScopeTable# " << this->id << " created" << endl;
    };

    ~ScopeTable() {
        for (int i=0; i<N; i++) if (T[i]) deleteChain(T[i]);
        delete[] T;
        cout << "\tScopeTable# " << this->id << " removed" << endl;
        //cout << "table destroyed!!" << endl;
    };

    void setParent (ScopeTable* parent) {
        this->parentScope = parent;
    };

    ScopeTable* getParent() {
        return this->parentScope;
    };

    int getId() {
        return this->id;
    };

    bool insert (SymbolInfo* x) {
        unsigned int i = h1(x->getName(), N) % N;
        int j = 0;
        if (!T[i]) T[i] = x;
        else {
            SymbolInfo* r = T[i];
            while (r->getNext()) r = r->getNext(), j++;
            r->setNext(x), j++;
        };
        cout << "\tInserted in ScopeTable# " << this->id << " at position " << i+1 << ", " << j+1 << endl;
        return true;
    };

    bool insert (char* name, char* type) {
        if (lookUp(name, true)) return false;
        SymbolInfo* x = new SymbolInfo (name, type);
        return insert(x);
    };

    SymbolInfo* lookUp (char* key, bool quiet = false) {
        unsigned int i = h1(key, N) % N;
        int j = 0;
        if (!T[i]) return nullptr;
        for (SymbolInfo* r = T[i]; r; r = r->getNext(), j++) 
            if (!strcmp(r->getName(), key)) {
                if (!quiet) cout << "\t'" << key << "' found in ScopeTable# " 
                                 << this->id << " at position " << i+1 << ", " << j+1 << endl;
                return r;
            };
        return nullptr;
    };

    bool deleteKey (char* key) {
        unsigned int i = h1(key, N) % N;
        int j = 0;
        if (!T[i]) return false;
        if (!strcmp(T[i]->getName(), key)) {
            SymbolInfo* d = T[i];
            T[i] = d->getNext();
            delete d;
            cout << "\tDeleted '" << key << "' from ScopeTable# " 
                     << this->id << " at position " << i+1 << ", " << j+1 << endl;
            return true;
        };
        for (SymbolInfo* r = T[i]; r->getNext(); r = r->getNext(), j++) {
            if (!strcmp(r->getNext()->getName(), key)) {
                //cout << __LINE__ << endl;
                SymbolInfo* d = r->getNext();
                r->setNext (d->getNext());
                delete d;
                //cout << __LINE__ << endl;
                cout << "\tDeleted '" << key << "' from ScopeTable# " 
                     << this->id << " at position " << i+1 << ", " << j+1 << endl;
                return true;
            };
        };
        return false;
        //delete f;
    };

    void print() {
        cout << "\tScopeTable# " << this->id << endl;
        for (int i=0; i<N; i++) {
            cout << "\t" << i+1 << "--> ";
            if (!T[i]) cout << endl;
            else {
                // cout << T[i]->getName() << "  ";
                for (SymbolInfo* r = T[i]; r; r = r->getNext())
                    cout << "<" << r->getName() << "," << r->getType() << "> ";
                cout << endl;
            };
        };
    };
};
