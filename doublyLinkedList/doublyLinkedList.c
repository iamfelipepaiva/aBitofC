#include "doublyLinkedList.h"

// Variables
struct node *beginning = NULL;
struct node *newOne = NULL;
struct node *aux = NULL;
struct node *previousOne = NULL;
struct node *nextOne = NULL;
struct node *currentNode = NULL;

// Functions
void initializeIt() {
    beginning = NULL;
}

void finishIt(struct node *quem) {
    if(quem->nextOne != NULL) {
        finishIt(quem->nextOne);
    }
    free(quem);
}

struct node* newNode(int data) {
    struct node *p = malloc(sizeof(struct node));
    if(!p) {
        printf("Erro na alocacao de memoria!\n");
        exit(EXIT_FAILURE);
    }
    p->previousOne = NULL;
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
            addToTheStart();
        }
        else {
            aux = beginning;
            previousOne = beginning;
            while(aux->data < newOne->data && aux->nextOne != NULL) {
                previousOne = aux;
                aux = aux->nextOne;
            }
            if(newOne->data > aux->data) {
                addToTheEnd();
            }
            else {
                addToTheMiddle();
            }
        }
    }
}

void addToTheStart() {
    newOne->nextOne = beginning;
    beginning->previousOne = newOne;
    beginning = newOne;
}

void addToTheEnd() {
    aux->nextOne = newOne;
    newOne->previousOne = aux;
}

void addToTheMiddle() {
    previousOne = aux->previousOne;

    newOne->nextOne = aux;
    aux->previousOne = newOne;
    previousOne->nextOne = newOne;
    newOne->previousOne = previousOne;
}

void deleteIt(int data) {
    if(beginning != NULL){
        if(data == beginning->data) {
            deleteFromStart();
            printf("%d successfully deleted!\n", data);
        } else {
            aux = beginning;
            previousOne = beginning;
            while (aux->data != data && aux->nextOne != NULL) {
                previousOne = aux;
                aux = aux->nextOne;
            }

            if(aux->data == data) {
                if(aux->nextOne == NULL){
                    deleteFromEnd();
                    printf("%d successfully deleted!\n", data);
                }
                else {
                    deleteFromMiddle();
                    printf("%d successfully deleted!\n", data);
                }
            }
        }
    }
}

void deleteFromStart() {
    if(beginning->nextOne == NULL) {
        free(beginning);
        beginning = NULL;
    }
    else {
        aux = beginning;
        free(aux);
        beginning = beginning->nextOne;

    }
}

void deleteFromEnd() {
    previousOne->nextOne = NULL;
    free(aux);
}

void deleteFromMiddle() {
    nextOne = aux->nextOne;
    previousOne->nextOne = nextOne;
    free(aux);
}

void totheStart() {
    currentNode = beginning;
}

void totheEnd() {
    currentNode = beginning;
    while(currentNode->nextOne != NULL) {
        currentNode = currentNode->nextOne;
    }
}

bool current(int *data) {
    if(currentNode == NULL) {
        return false;
    }
    *data = currentNode->data;

    return true;
}

bool toNext() {
    if(currentNode == NULL) {
        return false;
    }
    currentNode = currentNode->nextOne;

    return true;
}

bool toPrevious() {
    if(currentNode == NULL) {
        return false;
    }
    currentNode = currentNode->previousOne;

    return true;
}
