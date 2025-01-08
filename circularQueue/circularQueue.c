#include "circularQueue.h"

int queue[SIZE] = {0};
int beginning = 0;
int ending = 0;
bool isEmpty = true;
int totalClients = 0;

bool generateServiceNumber(int value){
    if(isEmpty){
        isEmpty = false;
    } else{
        if(ending == beginning){
            return false;
        }
    }
    queue[ending] = value;
    ending++;
    totalClients++;

    if(ending == SIZE){
        ending = 0;
    }

    return true;
}

bool callTicketN(int *value){
    if(isEmpty){
        return false;
    }
    *value = queue[beginning];
    beginning++;

    if(beginning == SIZE){
        beginning = 0;
    }
    if(beginning == ending){
        isEmpty = true;
    }

    return true;
}

void totalToday(){
    printf("Total of clients services today: %d", totalClients);
}