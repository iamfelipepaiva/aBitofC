#include "doublyLinkedList.h"
//Couldn't find a solution to when a value is deleted from the middle or start of the list and function backward printing gets activated.
//For some reason it keeps on falling into an endless loop.
// Constants
enum {
    UNSELECTED_OP = 0,
    ADD_OP,
    DELETE_OP,
    LISTIT_OP,
    BACKWARDLISTING_OP,
    EXIT_OP
};

// Prototypes
int menu();
void printIt();
void backwardsPrinting();

int main(void)
{
    int option = UNSELECTED_OP;
    int value = 0;

    initializeIt();

    while(option != EXIT_OP) {
        option = menu();

        switch (option) {
            case ADD_OP:
                printf("Insert the number to be added: ");
                scanf("%d", &value);
                addToIt(value);
                printf("%d properly added to the list.\n", value);
                break;
            case DELETE_OP:
                if(beginning == NULL){
                    printf("List is empty. Nothing to be deleted!\n");
                } else {
                printf("Type the number to be deleted: ");
                scanf("%d", &value);
                deleteIt(value);
                }
                break;
            case LISTIT_OP:
                printIt();
                break;
            case BACKWARDLISTING_OP:
                backwardsPrinting();
                break;
            case EXIT_OP:
                printf("Bye! See you!");
                break;
            default:
                printf("Invalid option! Try again!\n");
        }
    }

    if(beginning != NULL) {
        finishIt(beginning);
    }

    return EXIT_SUCCESS;
}

int menu() {
    int op = UNSELECTED_OP;
    printf("Menu\n");
    printf("%d - Add\n", ADD_OP);
    printf("%d - Delete\n", DELETE_OP);
    printf("%d - Print\n", LISTIT_OP);
    printf("%d - Backward printing\n", BACKWARDLISTING_OP);
    printf("%d - Exit\n", EXIT_OP);
    printf("Choose an option: ");
    scanf("%d", &op);

    return op;
}

void printIt() {
    int valor = 0;
    if(beginning != NULL) {
        totheStart();
        while(current(&valor)) {
            printf("%d ",valor);
            toNext();
        }
        printf("\n");
    } else{
        printf("List is empty. Nothing to be printed!\n");
    }
}

void backwardsPrinting() {
    int valor = 0;
    if(beginning != NULL) {
        totheEnd();
        while(current(&valor)) {
            printf("%d ",valor);
            toPrevious();
        }
        printf("\n");
    } else if(!toPrevious()){
        printf("Nothing to be printed! List is empty.\n");
        return;
    }
}