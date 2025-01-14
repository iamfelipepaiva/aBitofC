#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Constants
struct node {
    struct node *previousOne;
    int data;
    struct node *nextOne;
};

// Variables
extern struct node *beginning;
extern struct node *newOne;
extern struct node *aux;
extern struct node *previousOne;
extern struct node *nextOne;
extern struct node *currentNode;

// Prototypes
void initializeIt();
void finishIt(struct node *quem);
struct node *newNode(int data);
void addToIt(int data);
void addToTheStart();
void addToTheEnd();
void addToTheMiddle();
void deleteIt(int data);
void deleteFromStart();
void deleteFromEnd();
void deleteFromMiddle();

void totheStart();
void totheEnd();
bool current(int *data);
bool toNext();
bool toPrevious();

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
