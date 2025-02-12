#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "funtion.h"
 
void displayMenu();
void displayStudents();
void addStudent();

int main(int argc, char *argv[]) {
	
	

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: displayStudents(); break;
            case 2: addStudent(); break;
            case 3: editStudent(); break;
            case 4:
                	printf("updating");
                	break;
                	case 5:
                	printf("updating");
                	break;
            case 6: exit(0);
            default: printf("L?a ch?n không h?p l?!\n");
        }
    }
}
	
	
                
                
    //}while(choice != 0);
//	return 0;
//}
