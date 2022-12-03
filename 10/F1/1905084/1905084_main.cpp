#include <iostream>
#include <fstream>
#include <cstring>
#include "1905084_SymbolTable.hpp"

using namespace std;

int main() {

    const int lSym = 64, lInput = 256;
    const char mismatchStr[64] = "\tNumber of parameters mismatch for the command ";

    int bSize, c, i, j;
    char *opt, *line = new char[lInput], *name, *type;
    ofstream fout;
    fout.open ("output.txt");
    ifstream fin;
    fin.open ("input.txt");
    cout.rdbuf(fout.rdbuf());
    cin.rdbuf(fin.rdbuf());

    
    cin.getline (line, lInput);
    bSize = atoi(line);
    SymbolTable* T = new SymbolTable(bSize);

    for (i=1; true; i++) {
        cin.getline (line, lInput);
        char* l = new char [lInput];
        strcpy(l, line), l[strcspn (l, "\n\r")] = '\0', opt = strtok(l, " ");
        cout << "Cmd " << i << ": " << line << endl;

        if (!strcasecmp(opt, "I")) {
            name = new char[lSym];
            char* token = strtok(nullptr, " ");
            if (!token) cout << mismatchStr << opt << endl;
            else {
                strcpy (name, token);
                type = new char[lSym];
                token = strtok(nullptr, " ");
                if (!token) cout << mismatchStr << opt << endl;
                else {
                    strcpy (type, token);
                    token = strtok(nullptr, " ");
                    if (token) cout << mismatchStr << opt << endl;
                    else {
                        if (!T->insert(name, type)) 
                            cout << "\t'" <<  name << "' already exists in the current ScopeTable" << endl;
                    };
                };
            };
        } else if (!strcasecmp(opt, "L")) {
            name = new char[lSym];
            char* token = strtok(nullptr, " ");
            if (!token) cout << mismatchStr << opt << endl;
            else {
                strcpy (name, token);
                token = strtok(nullptr, " ");
                if (token) cout << mismatchStr << opt << endl;
                else {
                    if (!T->lookUp(name)) 
                        cout << "\t'" <<  name << "' not found in any of the ScopeTables" << endl;
                };
            };
        } else if (!strcasecmp(opt, "D")) {
            name = new char[lSym];
            char* token = strtok(nullptr, " ");
            if (!token) cout << mismatchStr << opt << endl;
            else {
                strcpy (name, token);
                token = strtok(nullptr, " ");
                if (token) cout << mismatchStr << opt << endl;
                else {
                    if (!T->remove(name)) cout << "\tNot found in the current ScopeTable" << endl;
                };
            };
        } else if (!strcasecmp(opt, "P")) {
            name = new char[lSym];
            char* token = strtok(nullptr, " ");
            if (!token) cout << mismatchStr << opt << endl;
            else {
                strcpy (name, token);
                token = strtok(nullptr, " ");
                if (token) cout << mismatchStr << opt << endl;
                else {
                    if (!strcasecmp(name, "A")) T->printAllScope();
                    else if (!strcasecmp(name, "C")) T->printCurrScope();
                };
            };
        } else if (!strcasecmp(opt, "S")) {
            char* token = strtok(nullptr, " ");
            if (token) cout << mismatchStr << opt << endl;
            else T->enterScope();
        } else if (!strcasecmp(opt, "E")) {
            char* token = strtok(nullptr, " ");
            if (token) cout << mismatchStr << opt << endl;
            else {
                int cs = T->getCurrScopeId();
                if (!T->exitScope()) cout << "\tScopeTable# " << cs << " cannot be removed" << endl;
            };
        } else if (!strcasecmp(opt, "Q")) {
            char* token = strtok(nullptr, " ");
            if (token) cout << mismatchStr << opt << endl;
            else {
                delete T;
                fout.close();
                fin.close();
                break;
            };
        } else cout << mismatchStr << opt << endl;
    };

    return 0;
};