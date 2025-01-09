#include "linkedList.h"

// Variables
struct node* beginning = NULL;
struct node* newOne = NULL;
struct node* aux = NULL; //Temporary pointer to help moving through the list
struct node* previousOne = NULL;
struct node* nextOne = NULL;
struct node* currentNode = NULL;

// Functions
void initializeIt() {
    beginning = NULL;
}

// Gets to the last container and then goes back freeing each of them
void finishIt(struct node* quem) {
    if(quem->nextOne != NULL) {
        finishIt(quem->nextOne);
    }
    free(quem);
}

struct node* newNode(int data){
    struct node* p = malloc(sizeof(struct node));
    if(!p) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    p->data = data;
    p->nextOne = NULL;

    return p;
}

void addToIt(int data) {
    newOne = newNode(data);

    if(beginning == NULL) {
        beginning = newOne;
    }
    else {
        if(newOne->data < beginning->data) {
            addItToTheStart();
        }
        else {
            aux = beginning;
            previousOne = beginning;
            while(aux->data < newOne->data && aux->nextOne != NULL) {
                previousOne = aux;
                aux = aux->nextOne;
            }
            if(newOne->data > aux->data) {
                addItToTheEnd();
            }
            else {
                addItToTheMiddle();
            }
        }
    }
}

void addItToTheStart() {
    newOne->nextOne = beginning;
    beginning = newOne;
}

void addItToTheEnd() {
    aux->nextOne = newOne;
}

void addItToTheMiddle() {
    newOne->nextOne = aux;
    previousOne->nextOne = newOne;
}

void deleteIt(int data) {
    if(beginning != NULL) {
        if(data == beginning->data) {
            deleteItFromStart();
        }
        else {
            aux = beginning;
            previousOne = beginning;
            while(aux->data != data && aux->nextOne != NULL) {
                previousOne = aux;
                aux = aux->nextOne;
            }
            if(aux->data == data) {
                if(aux->nextOne == NULL) {
                    deleteItFromEnd();
                }
                else {
                    deleteItFromMiddle();
                }
            }
        }
    }
}

void deleteItFromStart() {
    if(beginning->nextOne == NULL) {
        free(beginning);
        beginning = NULL;
    }
    else {
        aux = beginning;
        beginning = beginning->nextOne;
        free(aux);
    }
}

void deleteItFromEnd() {
    previousOne->nextOne = NULL;
    free(aux);
}

void deleteItFromMiddle() {
    nextOne = aux->nextOne;

    previousOne->nextOne = nextOne;
    free(aux);
}

void toTheStart() {
    currentNode = beginning;
}

bool actual(int *data) {
    if(currentNode == NULL) {
        return false;
    }
    *data = currentNode->data;

    return true;
}

bool toTheNext() {
    if(currentNode == NULL) {
        return false;
    }
    currentNode = currentNode->nextOne;

    return true;
}