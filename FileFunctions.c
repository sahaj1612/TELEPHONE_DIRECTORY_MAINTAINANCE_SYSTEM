// Source file which contains all the functions required to 
// handle records in file. Functions also have documentation in 
// function header comment blocks. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileFunctions.h"

int main(){
    char userID[50];
    char fileID[50];
    int found = 0;

    printf("\n\n");
    printf("Telephone Directory Maintenance System\n");
    printf("======================================\n\n");
    printf("         Login Screen\n");
    printf("         ============\n\n");

    printf("Enter User ID   : ");
    scanf("%s", userID);

    FILE *fp = fopen("emp.txt", "r");

    if (fp == NULL){
        printf("\nemp.txt file not found\n");
        return 1;
    }

    while (fscanf(fp, "%s", fileID) == 1){
        if (strcmp(userID, fileID) == 0){
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found){
        mainMenu();
    }
    else{
        printf("\nUser ID not found\n");
    }

    return 0;
}

void addEmployee(){
    char employeeName[50];
    char deptCode[20];
    char deptName[50];
    char location[50];

    char fileEmpName[50];
    char fileEmpId[20];
    char fileDeptCode[20];
    char fileDeptName[50];
    char fileLocation[50];

    int lastId = 1000;
    int newId;

    printf("\n\n");
    printf("Telephone Directory Maintenance System\n");
    printf("=======================================\n\n");

    printf("                 Add an Employee\n");
    printf("                 ===============\n\n");

    printf("Enter Employee Name     : ");
    scanf("%s", employeeName);

    FILE *fp = fopen("emp.txt", "r");

    if (fp == NULL){
        printf("emp.txt file not found\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)){

        char fileTel[20] = "";
        int x = sscanf(line, "%s %s %s %s %s %s",fileEmpName,fileEmpId,fileDeptCode,fileDeptName,fileLocation,fileTel);

        if (x >= 5){
            if (strcmp(employeeName, fileEmpName) == 0){
                printf("\nEmployee already exists\n");
                fclose(fp);
                return;
            }
            lastId = atoi(fileEmpId);
        }
    }

    fclose(fp);

    newId = lastId + 1;

    printf("Employee Id             : %d\n", newId);

    printf("Enter Department Code   : ");
    scanf("%s", deptCode);

    FILE *deptFp = fopen("dept.txt", "r");

    if (deptFp == NULL){
        printf("dept.txt file not found\n");
        return;
    }

    int found = 0;

    while (fscanf(deptFp, "%s %s", fileDeptName, fileDeptCode) != EOF){
        if (strcmp(deptCode, fileDeptCode) == 0){
            strcpy(deptName, fileDeptName);
            found = 1;
            break;
        }
    }

    fclose(deptFp);

    if (found == 0){
        printf("Department Code does not exist\n");
        return;
    }

    printf("Department Name         : %s\n", deptName);

    printf("Enter Location          : ");
    scanf("%s", location);

    fp = fopen("emp.txt", "a");

    if (fp == NULL){
        printf("emp.txt file not found\n");
        return;
    }

    fprintf(fp, "%s %d %s %s %s\n",employeeName,newId,deptCode,deptName,location);

    fclose(fp);

    printf("\nEmployee added successfully\n");
}

void printEmployee(){
    char employeeName[50];
    char employeeId[20];
    char deptCode[20];
    char deptName[50];
    char location[50];

    FILE *fp = fopen("emp.txt", "r");

    printf("\n\n");
    printf("Telephone Directory Maintenance System\n");
    printf("=======================================\n\n");

    printf("                 Employee List\n");
    printf("                 =============\n\n");
        printf("%-15s %-12s %-17s %-17s %-12s %s\n",
            "Employee Name", "Employee ID", "Dept Code", "Dept Name",
            "Location", "Telephone Number");
        printf("--------------------------------------------------------------------------------\n");

    char line[256];
    char telNo[20];

    if (fp == NULL){
        printf("emp.txt file not found\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)){
        telNo[0] = '\0';
        int x = sscanf(line, "%s %s %s %s %s %s",employeeName,employeeId,deptCode,deptName,location,telNo);
        if (x >= 5){
            if (x == 6){
                printf("%-15s %-12s %-17s %-17s %-12s %s\n",employeeName,employeeId,deptCode,deptName,location,telNo);
            }
            else{
                printf("%-15s %-12s %-17s %-17s %-12s %s\n",employeeName,employeeId,deptCode,deptName,location,"N/A");
            }
        }
    }

    fclose(fp);
}

void EmpMenu(){

    int choice;

    do{

        printf("\n\n");
        printf("Telephone Directory Maintenance System\n");
        printf("=======================================\n\n");

        printf("Employee Maintenance Menu\n");
        printf("===========================\n\n");

        printf("1. Add Employee\n");
        printf("2. Print Employee Details\n");
        printf("3. Goto Main Menu\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addEmployee();
                EmpMenu();
                break;

            case 2:
                printEmployee();
                EmpMenu();
                break;

            case 3:
                mainMenu();
                return;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);
}
