//
// Created by Felipe
//

#include "binaryTree.h"

// variables
struct node *beginning;
struct node *aux;
struct node *previous;

// functions
void inicializeIt() {
    beginning = NULL;
}

void finishIt(struct node *currentNode) {
    if(currentNode == NULL) {
        return;
    }
    if(currentNode->toTheLeft != NULL) {
        printf("Moving to the left!\n");
        finishIt(currentNode->toTheLeft);
    }
    if(currentNode->toTheRight != NULL) {
        printf("Moving to the right!\n");
        finishIt(currentNode->toTheRight);
    }
    printf("Deleting %d...\n",currentNode->data);
    free(currentNode);
}

struct node *newNode(int data){
    struct node *p = malloc(sizeof(struct node));
    if(!p){
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    p->toTheLeft = NULL;
    p->data = data;
    p->toTheRight = NULL;

    return p;
}

void addIt(struct node *newNode, struct node *currentN) {
    if(beginning == NULL) {
        printf("Adding %d to the start.\n",newNode->data);
        beginning = newNode;
    }
    else {
        if(newNode->data > currentN->data) {
            // adicionar na direita
            if(currentN->toTheRight == NULL) {
                printf("Adding %d to the right of %d.\n",newNode->data, currentN->data);
                currentN->toTheRight = newNode;
            }
            else {
                printf("Moving to the right of %d!\n", currentN->data);
                addIt(newNode, currentN->toTheRight);
            }
        }
        else {
            // adicionar na esquerda
            if(currentN->toTheLeft == NULL) {
                printf(" Adding %d to the left of %d.\n",newNode->data, currentN->data);
                currentN->toTheLeft = newNode;
            }
            else {
                printf("Moving to the left of %d!\n", currentN->data);
                addIt(newNode, currentN->toTheLeft);
            }
        }
    }
}

struct node *locateIt(int data, struct node *where) {
    if(where->data == data) {
        printf("%d is in a branch of the tree!\n", data);
        return where;
    }
    else {
        if(data > where->data) {
            if(where->toTheRight != NULL) {
                previous = where;
                printf("Moving to the right of %d!\n", where->data);
                return locateIt(data, where->toTheRight);
            }
            else {
                printf("%d is not in any branch of the tree!\n", data);
                return NULL;
            }
        }
        else {
            if(where->toTheLeft != NULL) {
                previous = where;
                printf(" Moving to the left of %d!\n", where->data);
                return locateIt(data, where->toTheLeft);
            }
            else {
                printf("%d is not in any branch of the tree!\n", data);
                return NULL;
            }
        }
    }
}

void deleteIt(int data) {
    if(beginning == NULL) {
        return;
    }
    else {
        aux = locateIt(data, beginning);
        if(aux != NULL) {
            if(aux == beginning) {
                beginning = NULL;
            }
            else {
                if(aux->data > previous->data) {
                    previous->toTheRight = NULL;
                }
                else {
                    previous->toTheLeft = NULL;
                }
            }
            if(aux->toTheLeft != NULL) {
                addIt(aux->toTheLeft, beginning);
            }
            if(aux->toTheRight != NULL) {
                addIt(aux->toTheRight, beginning);
            }
            free(aux);
        }
    }
}