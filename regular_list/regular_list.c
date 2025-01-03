//
// Created by User on 03/01/2025.
//

#include "regular_list.h"

// Variáveis
int list[SIZE];
int position = 0;

// Funções
bool add(int value) {
    if(position == SIZE) {
        // irá mudar quando formos deixar dinâmico
        return false;
    }
    list[position] = value;
    position++;
    return true;
}

int size() {
    return position;
}


bool searchByIndex(int indexToSearch, int *value)
{
    if(indexToSearch < 0 || indexToSearch >= position) {
        return false;
    }
    *value = list[indexToSearch];
    return true;
}


int searchByValue(int value){
    int returning = -1;
    for(int i = 0; i < position; i++){
        if(list[i] == value) {
            returning = i;
            break;
        }
    }
    return returning;
}
//my search by value

void delete(int value){
    int indice = searchByValue(value);
    if(indice == -1){
        return;
    }
    for(int i = indice; i < position - 1; i++) {
        list[i] = list[i + 1];
    }
    position--;
}

void sort(){
    int temp;
    for(int i = 0; i < position - 1; i++) {
        for(int j = i + 1; j < position; j++) {
            if(list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

bool set(int altIndex, int value) {
    if(altIndex < 0 || altIndex >= position) {
        return false;
    }
    list[altIndex] = value;
    return true;
}

