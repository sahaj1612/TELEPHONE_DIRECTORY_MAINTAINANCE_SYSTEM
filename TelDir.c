// The main file of telephone directory system. Contains code 
// for the main menu and department menu. 

#include <stdio.h>
#include <string.h>
#include "FileFunctions.h"

void TelephoneEnquiryMenu(){
    int choice;

    do{
        printf("\n\n");
        printf("Telephone Directory Maintenance System\n");
        printf("=======================================\n\n");

        printf("Telephone Enquiry Menu\n");
        printf("======================\n\n");

        printf("1. Enquiry on Employee Name\n");
        printf("2. Enquiry on Telephone Number\n");
        printf("3. Goto Main Menu\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 3){
            mainMenu();
            return;
        }

        if (choice != 1 && choice != 2){
            printf("Invalid choice\n");
            continue;
        }

        char searchValue[50];
        char line[256];
        char employeeName[50];
        char employeeId[20];
        char deptCode[20];
        char deptName[50];
        char location[50];
        char telephoneNumber[20];
        int found = 0;

        if (choice == 1){

            FILE *listFp = fopen("emp.txt", "r");

            if (listFp == NULL){
                printf("emp.txt file not found\n");
                continue;
            }

            printf("\nName                Location        DeptName                 TelNumber\n");
            printf("-----------------------------------------------------------------------\n");
            
            while (fgets(line, sizeof(line), listFp) != NULL){

                telephoneNumber[0] = '\0';
                int fields = sscanf(line, "%s %s %s %s %s %s", employeeName, employeeId, deptCode, deptName, location, telephoneNumber);

                if (fields >= 5){
                    printf("%-19s %-15s %-24s ", employeeName, location, deptName);
                    
                    if (fields == 6){
                        printf("%s\n", telephoneNumber);
                    }
                    else{
                        printf("N/A\n");
                    }
                }
            }
            fclose(listFp);
        }

        if (choice == 2){
            printf("\nTelephone Number Enquiry\n");
            printf("========================\n\n");
        }

        if (choice == 1){
            printf("\nEnter Employee Name: ");
        }
        else
        {
            printf("Enter Telephone Number: ");
        }
        scanf("%s", searchValue);

        FILE *fp = fopen("emp.txt", "r");
        if (fp == NULL){
            printf("emp.txt file not found\n");
            continue;
        }

        while (fgets(line, sizeof(line), fp) != NULL) {

            int fields = sscanf(line, "%s %s %s %s %s %s",employeeName, employeeId, deptCode, deptName, location, telephoneNumber);

            if (fields == 6 && ((choice == 1 && strcmp(searchValue, employeeName) == 0) || (choice == 2 && strcmp(searchValue, telephoneNumber) == 0))){
                
                    if (choice == 1){
                    printf("\nName                Location        DeptName                 TelNumber\n");
                        printf("%-19s %-15s %-24s %s\n",
                           employeeName, location, deptName, telephoneNumber);
                }
                else{
                    printf("\nEmployee Name       : %s\n", employeeName);
                    printf("Location            : %s\n", location);
                    printf("Department Name     : %s\n", deptName);
                }
                found = 1;
                break;
            }
        }

        fclose(fp);

        if (!found){
            printf("\nNo matching employee found\n");
        }
    } while (choice != 3);
}

void mainMenu(){

    int choice;

    printf("\n\n");

    printf("Telephone Directory Maintenance System\n");
    printf("======================================\n\n");

    printf("Main Menu\n");
    printf("=========\n\n");

    printf("1. Department Maintenance\n");
    printf("2. Employee Maintenance\n");
    printf("3. Telephone Directory Maintenance\n");
    printf("4. Telephone Enquiry\n");
    printf("5. Exit\n\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            DeptMenu();
            break;

        case 2:
            EmpMenu();
            break;

        case 3:
            TelMenu();
            break;

        case 4:
            TelephoneEnquiryMenu();
            break;

        case 5:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Invalid choice\n");
    }

}


void DeptMenu(){
    int choice;

    do{
        printf("\n\n");
        printf("Telephone Directory Maintenance System\n");
        printf("=======================================\n\n");

        printf("Department Maintenance Menu\n");
        printf("===========================\n\n");

        printf("1. Add Department\n");
        printf("2. Print Department Details\n");
        printf("3. Goto Main Menu\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addDepartment();
                break;

            case 2:
                printDepartments();
                break;

            case 3:
                mainMenu();
                return;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);
}

