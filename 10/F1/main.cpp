#include <iostream>
#include <cstring>
#define SYM_LEN 100

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


class ScopeTable {

    int N, id;
    SymbolInfo** T;
    ScopeTable* parentScope;

    inline static int currId = 0;

    static unsigned long long int h1 (char* a) {
        unsigned long long int h = 0, i, len = strlen(a);
        for (i=0; i<len; i++) h = a[i] + (h<<6) + (h<<16) - h;
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
        unsigned long long int i = h1(x->getName()) % N;
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
        unsigned long long int i = h1(key) % N;
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
        unsigned long long int i = h1(key) % N;
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

    bool insert (SymbolInfo* symbol) {
        return curr->insert(symbol);
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

    void printCurrScope() {
        curr->print();
    };

    void printAllScope() {
        ScopeTable* scope = curr;
        while (scope) {
            scope->print();
            scope = scope->getParent();
        }; 
    };
};



// int main() {
//     srand (time(0));
//     const int SIZE = 23;
//     int i, j;
//     ScopeTable* T = new ScopeTable (30);
//     for (i=0; i<23; i++) {
//         char *s = new char[8], *ss = new char[8];
//         for (j=0; j<7; j++) ss[6-j] = s[j] = 97 + abs(rand()) % 25;
//         s[7] = '\0', ss[7] = '\0';
//         cout << T->add (s, ss) + 1 << endl;
//     };
//     T->print();
//     for (i=0; i<4; i++) { 
//         cout << "find/delete who? " << endl;
//         char* f = new char[8];
//         cin >> f;
//         SymbolInfo* r = T->lookUp(f);
//         T->deleteKey(r->getName());
//         // T->deleteKey(f);
//         T->print();
//     };
//     for (i=0; i<3; i++) {
//         cout << "insert: ";
//         char *f = new char[8], *ff = new char[8];
//         cin >> f >> ff;
//         cout << T->add(f, ff) << endl;
//         T->print();
//     };
//     delete T;
//     return 0;
// };

int main() {
    int bSize, i, j;
    char *opt = new char[5];

    cin >> bSize;
    SymbolTable* T = new SymbolTable(bSize);

    while (true) {
        cin >> opt;
        if (!strcasecmp(opt, "I")) {
            char *name = new char[SYM_LEN], *type = new char[SYM_LEN];
            cin >> name >> type;
            if (!T->insert(name, type)) cout << "\t'" <<  name << "' already exists in the current ScopeTable" << endl;
        } else if (!strcasecmp(opt, "L")) {
            char *name = new char[SYM_LEN];
            cin >> name;
            if (!T->lookUp(name)) cout << "\t'" <<  name << "' not found in any of the ScopeTables" << endl;
        } else if (!strcasecmp(opt, "D")) {
            char *name = new char[SYM_LEN];
            cin >> name;
            if (!T->remove(name)) cout << "\tNot found in the current ScopeTable" << endl;
        } else if (!strcasecmp(opt, "P")) {
            cin >> opt;
            if (!strcasecmp(opt, "A")) T->printAllScope();
            else if (!strcasecmp(opt, "C")) T->printCurrScope();
        } else if (!strcasecmp(opt, "S")) {
            T->enterScope();
        } else if (!strcasecmp(opt, "E")) {
            int cs = T->getCurrScopeId();
            if (!T->exitScope()) cout << "\tScopeTable# " << cs << " cannot be removed" << endl;
        } else if (!strcasecmp(opt, "Q")) {
            delete T;
            break;
        };
    };

    return 0;
};