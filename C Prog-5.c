#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SymbolEntry {
    char name[50];
    int address;
    int value;
    char datatype[20];
    struct SymbolEntry* next;
};
struct SymbolEntry* symbolTable = NULL;
void insertSymbol(char name[], int address, int value, char datatype[]) {
    struct SymbolEntry* newSymbol = (struct SymbolEntry*)malloc(sizeof(struct SymbolEntry));
    strcpy(newSymbol->name, name);
    newSymbol->address = address;
    newSymbol->value = value;
    strcpy(newSymbol->datatype, datatype);
    newSymbol->next = symbolTable;
    symbolTable = newSymbol;
}
struct SymbolEntry* searchSymbol(char name[]) {
    struct SymbolEntry* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

int main() {
    insertSymbol("variable1", 0x1000, 42, "int");
    insertSymbol("variable2", 0x2000, 3.14, "double");
    char symbolName[] = "variable1";
    struct SymbolEntry* symbol = searchSymbol(symbolName);
    if (symbol != NULL) {
        printf("Symbol: %s, Address: 0x%X, Value: %d, Data Type: %s\n", symbol->name, symbol->address, symbol->value, symbol->datatype);
    } else {
        printf("Symbol not found\n");
    }

    return 0;
}
