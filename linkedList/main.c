#include "linkedList.h"
// Constants
enum {
    UNSELECTED_OP = 0,
    ADD_OP,
    DELETE_OP,
    LIST_OP,
    EXIT_OP
};

// Prototypes
int menu();
void printIt();

int main(void)
{
    int option = UNSELECTED_OP;
    int value = 0;

    initializeIt();

    while(option != EXIT_OP) {
        option = menu();

        switch (option) {
            case ADD_OP:
                printf("Type a number: ");
                scanf("%d", &value);
                addToIt(value);
                break;
            case DELETE_OP:
                printf("Type the number: ");
                scanf("%d", &value);
                deleteIt(value);
                break;
            case LIST_OP:
                printIt();
                break;
            case EXIT_OP:
                printf("Bye! See you!");
                break;
            default:
                printf("Invalid option! Sorry!\n");
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
    printf("%d - Sequential printing\n", LIST_OP);
    printf("%d - Exit\n", EXIT_OP);
    printf("Select an option: ");
    scanf("%d", &op);

    return op;
}

void printIt() {
    int value = 0;
    if(beginning != NULL) {
        toTheStart();
        while(actual(&value)) {
            printf("%d ",value);
            toTheNext();
        }
        printf("\n");//
    } else if(!actual(&value)){
        printf("There's nothing to be printed out. The list needs to be feeded!\n");
    }
}