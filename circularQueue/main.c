#include "circularQueue.h"

enum{
    UNSELECTED_OP,
    GENERATENUMBER_OP,
    CALLTICKET_OP,
    PRINTOUT_OP,
    EXIT_OP
};

int menu(void);

int main(){
    srand(time(NULL));
    int option = UNSELECTED_OP;
    int serviceNumber = UNSELECTED_OP;
    while (option != EXIT_OP){
        option = menu();
        serviceNumber = (rand() % 1000) + 1;
        switch (option){
            case GENERATENUMBER_OP:
                if(!generateServiceNumber(serviceNumber)){
                    printf("\nQueue is full. Come back later. Thank you.");
                } else{
                    printf("\nYour service number is: %d.\n", serviceNumber);
                }
                break;

            case CALLTICKET_OP:
                if(callTicketN(&serviceNumber)){
                    printf("\n%d, head to the service counter.", serviceNumber);
                } else{
                    printf("\nQueue is currently empty.");
                }
                break;

            case EXIT_OP:
                break;

            case PRINTOUT_OP:
                totalToday();
                break;
            default:
                printf("Invalid choice. Try again.");

        }
    }

    return 0;
}

int menu(){

    int op = UNSELECTED_OP;
    printf("\n%d - Generate ticket ", GENERATENUMBER_OP);
    printf("\n%d - Service ticket ", CALLTICKET_OP);
    printf("\n%d - Clients of the day ", PRINTOUT_OP);
    printf("\n%d - Exit ", EXIT_OP );
    printf("\nChoose one of the above options: ");
    scanf("%d", &op);
    printf("\n");

    return op;
}