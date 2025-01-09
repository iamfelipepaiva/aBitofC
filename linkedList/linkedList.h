#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Constants
struct node {
    int data;
    struct node* nextOne;

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
void addItToTheStart();
void addItToTheEnd();
void addItToTheMiddle();
void deleteIt(int data);
void deleteItFromStart();
void deleteItFromEnd();
void deleteItFromMiddle();

void toTheStart();
bool actual(int *data);
bool toTheNext();

#endif //LINKEDLIST_LINKEDLIST_H
