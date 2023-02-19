#include <iostream>
#include <cstring>
#include "1905084_ArrayList.hpp"

using namespace std;

class SymbolInfo {    
    char *name, *type, *semanticType;
    SymbolInfo *next;
    ArrayList<SymbolInfo*> *children, *params;
    bool isArrayType, isFunctionType, hasZeroValue, isGlobalVar;
    int arraySize, startLine, endLine, stackOffset, varDecCount, nextLabel, trueLabel, falseLabel;
public:
    SymbolInfo (char* name, char* type) {
        this->name = name, this->type = type;
        this->next = nullptr, this->children = nullptr, this->params = nullptr;
        this->isArrayType = false, this->isFunctionType = false, this->hasZeroValue = false, this->isGlobalVar = false;
        this->arraySize = 0, this->varDecCount = 0;
        this->nextLabel = 0; this->trueLabel = 0; this->falseLabel = 0;
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
    void setSemanticType (char* stype) {
        this->semanticType = stype;
    };
    char* getSemanticType() {
        return this->semanticType;
    }
    void setParams (ArrayList<SymbolInfo*> *params) {
        this->params = params;
    };
    ArrayList<SymbolInfo*> *getParams() {
        return this->params;
    };
    void setStackOffset (int stackOffset) {
        this->stackOffset = stackOffset;
    };
    int getStackOffset() {
        return this->stackOffset;
    };
    void setVarDecCount (int varDecCount) {
        this->varDecCount = varDecCount;
    };
    int getVarDecCount() {
        return this->varDecCount;
    };
    void setNextLabel (int label) {
        this->nextLabel = label;
    };
    int getNextLabel() {
        return this->nextLabel;
    };
    void setTrueLabel (int label) {
        this->trueLabel = label;
    };
    int getTrueLabel() {
        return this->trueLabel;
    };
    void setFalseLabel (int label) {
        this->falseLabel = label;
    };
    int getFalseLabel() {
        return this->falseLabel;
    };

    void addChild (SymbolInfo* c) {
        if (!this->children) this->children = new ArrayList<SymbolInfo*>();
        this->children->append(c);
    };

    ArrayList<SymbolInfo*> *getChildren() {
        return this->children;
    };

    SymbolInfo* getChild (int i) {
        this->children->moveToPos(i);
        return this->children->getValue();
    };

    SymbolInfo* getFirstChild() {
        this->children->moveToStart();
        return this->children->getValue();
    };

    SymbolInfo* getLastChild() {
        this->children->moveToEnd(), this->children->prev();
        return this->children->getValue();
    };

    int getChildrenCount() {
        return this->children->length();
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
    void setFunction() {
        this->isFunctionType = true;
    };
    bool isFunction() {
        return this->isFunctionType;
    };
    void setZero() {
        this->hasZeroValue = true;
    };
    bool isZero() {
        return this->hasZeroValue;
    };
    void setGlobal() {
        this->isGlobalVar = true;
    };
    bool isGlobal() {
        return this->isGlobalVar;
    };

};
