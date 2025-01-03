
#ifndef REGULAR_LIST_REGULAR_LIST_H
#define REGULAR_LIST_REGULAR_LIST_H
#include <stdbool.h>

// Constantes
enum {
    SIZE = 10
};

// Variáveis
extern int list[];
extern int position;

// Funções
bool add(int value);
int size();
bool searchByIndex(int indexToSearch, int *value);
int searchByValue(int value);
void delete(int value);
void sort();
bool set(int altIndex, int value);


#endif //REGULAR_LIST_REGULAR_LIST_H
