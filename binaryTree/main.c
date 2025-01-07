#include <stdio.h>
#include "binaryTree.h"
// contants
enum {
    UNSELECTED_OP = 0,
    ADDIT_OP,
    LOCATEIT_OP,
    DELETEIT_OP,
    EXIT_OP
};

// prototypes
int menu();

int main(void) {
    int option = UNSELECTED_OP;
    int number;

    inicializeIt();

    while (option != EXIT_OP) {
        option = menu();

        switch (option) {
            case ADDIT_OP:
                printf("Insert a number: ");
                scanf("%d", &number);
                aux = newNode(number);
                addIt(aux, beginning);
                break;
            case LOCATEIT_OP:
                printf("Insert a number: ");
                scanf("%d", &number);
                aux = locateIt(number, beginning);
                /* if (aux == NULL) {
                     printf("Nao encontrado!\n");
                 }
                 else {
                     printf("Achei %d\n", aux->data);

                 }*/
                break;
            case DELETEIT_OP:
                printf("Insert a number: ");
                scanf("%d", &number);
                deleteIt(number);
                break;
            case EXIT_OP:
                break;
            default:
                printf("Invalid choice! Try again!\n");
        }
    }

    finishIt(beginning);

    return 0;
}

int menu() {
    int op = UNSELECTED_OP;

    printf("Menu\n");
    printf("%d - Add\n", ADDIT_OP);
    printf("%d - Locate\n", LOCATEIT_OP);
    printf("%d - Delete\n", DELETEIT_OP);
    printf("%d - Exit\n", EXIT_OP);
    printf("Type your option: ");
    scanf("%d", &op);

    return op;
}