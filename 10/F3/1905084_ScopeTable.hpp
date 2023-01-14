#include <iostream>
#include <cstring>
#include "1905084_SymbolInfo.hpp"

using namespace std;

class ScopeTable {

    int N, id;
    SymbolInfo** T;
    ScopeTable* parentScope;

    inline static int currId = 0;

    static unsigned long long int h1 (char* a, int N) {
        unsigned long long int h = 0, i, len = strlen(a);
        for (i=0; i<len; i++) h = (a[i] + (h<<6) + (h<<16) - h);
        return h % N;
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
        //cout << "\tScopeTable# " << this->id << " created" << endl;
    };

    ~ScopeTable() {
        //for (int i=0; i<N; i++) if (T[i]) deleteChain(T[i]);
        delete[] T;
        //cout << "\tScopeTable# " << this->id << " removed" << endl;
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
        if (lookUp(x->getName(), true)) return false;
        unsigned long long int i = h1(x->getName(), N) % N;
        int j = 0;
        if (!T[i]) T[i] = x;
        else {
            SymbolInfo* r = T[i];
            while (r->getNext()) r = r->getNext(), j++;
            r->setNext(x), j++;
        };
        //cout << "\tInserted in ScopeTable# " << this->id << " at position " << i+1 << ", " << j+1 << endl;
        return true;
    };

    bool insert (char* name, char* type) {
        if (lookUp(name, true)) return false;
        SymbolInfo* x = new SymbolInfo (name, type);
        return insert(x);
    };

    SymbolInfo* lookUp (char* key, bool quiet = false) {
        unsigned long long int i = h1(key, N) % N;
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
        unsigned long long int i = h1(key, N) % N;
        int j = 0;
        if (!T[i]) return false;
        if (!strcmp(T[i]->getName(), key)) {
            SymbolInfo* d = T[i];
            T[i] = d->getNext();
            delete d;
            //cout << "\tDeleted '" << key << "' from ScopeTable# " 
            //         << this->id << " at position " << i+1 << ", " << j+1 << endl;
            return true;
        };
        for (SymbolInfo* r = T[i]; r->getNext(); r = r->getNext(), j++) {
            if (!strcmp(r->getNext()->getName(), key)) {
                //cout << __LINE__ << endl;
                SymbolInfo* d = r->getNext();
                r->setNext (d->getNext());
                delete d;
                //cout << __LINE__ << endl;
                //cout << "\tDeleted '" << key << "' from ScopeTable# " 
                //     << this->id << " at position " << i+1 << ", " << j+1 << endl;
                return true;
            };
        };
        return false;
        //delete f;
    };

    void print (FILE* logout = stdout) {
        //cout << "\tScopeTable# " << this->id << endl;
        fprintf (logout, "\tScopeTable# %d\n", this->id);
        for (int i=0; i<N; i++) { 
            if (T[i]) {
                //cout << "\t" << i+1 << "--> ";
                fprintf (logout, "\t%d--> ", i+1);
                for (SymbolInfo* r = T[i]; r; r = r->getNext())
                    //cout << "<" << r->getName() << "," << r->getType() << "> ";
                    if (r->isFunction()) fprintf (logout, "<%s, FUNCTION, %s> ", r->getName(), r->getSemanticType());
                    else if (r->isArray()) fprintf (logout, "<%s, ARRAY, %s> ", r->getName(), r->getSemanticType());
                    else fprintf (logout, "<%s, %s> ", r->getName(), r->getSemanticType());
                //cout << endl;
                fprintf (logout, "\n");
            };
        };
    };
};
