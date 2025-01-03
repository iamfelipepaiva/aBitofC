#include <stdio.h>

#include "regular_list.h"

// constantes
enum {
    UNSELECTED_OP = 0,
    ADDIT_OP,
    SIZE_OP,
    INDEXSEARCH_OP,
    VALUESEARCH_OP,
    DELETEIT_OP,
    ORDERIT_OP,
    ALTERIT_OP,
    LISTIT_OP,
    EXIT_OP
};

// protótipos
int menu();
void listIt();

int main(void)
{
    int option = UNSELECTED_OP;
    int indexMain;
    int valueMain;

    while(option != EXIT_OP) {
        option = menu();
        switch(option) {
            case ADDIT_OP:
                printf("Insert a number: ");
                scanf("%d", &valueMain);
                if(!add(valueMain)) {
                    printf("Current list is already full.\n");
                }
                break;
            case SIZE_OP:
                printf("The current list contains %d elements.\n", size());
                break;
            case INDEXSEARCH_OP:
                printf("Insert the position: ");
                scanf("%d", &indexMain);
                if(searchByIndex(indexMain, &valueMain)) {
                    printf("Element %d found.\n", valueMain);
                }
                else {
                    printf("Invalid index!\n");
                }
                break;
            case VALUESEARCH_OP:
                printf("Insert the value: ");
                scanf("%d", &valueMain);
                indexMain = searchByValue(valueMain);
                if(indexMain != -1) {
                    printf("Element at position %d.\n", indexMain);
                }
                else {
                    printf("Element not found!\n");
                }
                break;
            case DELETEIT_OP:
                printf("Type the value: ");
                scanf("%d", &valueMain);
                delete(valueMain);
                break;
            case ORDERIT_OP:
                sort();
                break;
            case ALTERIT_OP:
                printf("Type the value: ");
                scanf("%d", &valueMain);
                printf("Type the index: ");
                scanf("%d", &indexMain);
                if(set(indexMain, valueMain)) {
                    printf("Successfully altered.\n");
                }
                else {
                    printf("Invalid index.\n");
                }
                break;
            case LISTIT_OP:
                listIt();
                break;
            case EXIT_OP:
                break;
            default:
                printf("Invalid option. Try again!\n");
        }
    }
    return 0;
}

int menu() {
    int op = UNSELECTED_OP;
    printf("Menu\n");
    printf("%d - Add\n",ADDIT_OP);
    printf("%d - Size check\n",SIZE_OP);
    printf("%d - Search by index\n",INDEXSEARCH_OP);
    printf("%d - Search by value\n",VALUESEARCH_OP);
    printf("%d - Delete\n",DELETEIT_OP);
    printf("%d - Order\n",ORDERIT_OP);
    printf("%d - Alter\n",ALTERIT_OP);
    printf("%d - List\n",LISTIT_OP);
    printf("%d - Exit\n",EXIT_OP);
    printf("Insert your option: ");
    scanf("%d", &op);

    return op;
}

void listIt() {
    int value;
    if(size() == 0) {
        printf("Lista vazia\n");
    }
    else {
        for(int i = 0; i < size(); i++) {
            searchByIndex(i, &value);
            printf("%d\n", value);
        }
    }
}
