
#ifndef CIRCULARQUEUE_CIRCULARQUEUE_H
#define CIRCULARQUEUE_CIRCULARQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum{
    SIZE = 5
};

extern int queue[SIZE];
extern int beginning;
extern int ending;
extern bool isEmpty;
extern int totalClients;

bool generateServiceNumber(int value);
bool callTicketN(int *value);
void totalToday();







#endif //CIRCULARQUEUE_CIRCULARQUEUE_H
