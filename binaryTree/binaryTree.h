//
// Created by Felipe
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include <stdio.h>
#include <stdlib.h>

// constants
struct node {
    struct node *toTheLeft;
    int data;
    struct node *toTheRight;
};

// variables
extern struct node *beginning;
extern struct node *aux;
extern struct node *previous;

// prototypes
void inicializeIt();
void finishIt(struct node *currentNode);
struct node *newNode(int data);
void addIt(struct node *newNode, struct node *currentN);
struct node *locateIt(int data, struct node *where);
void deleteIt(int data);







#endif //BINARYTREE_BINARYTREE_H
