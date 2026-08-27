// File containing code to add and view departments in the 
// department file 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileFunctions.h"

void addDepartment(){
    char deptName[50];
    char fileDept[50];
    char fileCode[20];
    int lastCode = 2000;
    int newCode;

    printf("\n\n");
    printf("Telephone Directory Maintenance System\n");
    printf("=======================================\n\n");

    printf("                 Add a Department\n");
    printf("                 ================\n\n");

    printf("Enter Department Name   : ");
    scanf("%s", deptName);

    FILE *fp = fopen("dept.txt", "r");

    if (fp == NULL){
        printf("dept.txt file not found\n");
        return;
    }

    while (fscanf(fp, "%s %s", fileDept, fileCode) != EOF){
        if (strcmp(deptName, fileDept) == 0){
            printf("\nDepartment already exists\n");
            fclose(fp);
            return;
        }

        lastCode = atoi(fileCode); // Converts string to integer
    }

    fclose(fp);

    newCode = lastCode + 1;

    printf("Department Code        : %d\n", newCode);

    fp = fopen("dept.txt", "a");

    if (fp == NULL){
        printf("dept.txt file not found\n");
        return;
    }

    fprintf(fp, "%s %d\n", deptName, newCode);

    fclose(fp);

    printf("\nDepartment added successfully\n");
}

void printDepartments(){

    char deptName[50];
    char deptCode[20];

    FILE *fp = fopen("dept.txt", "r");

    if (fp == NULL){
        printf("dept.txt file not found\n");
        return;
    }

    printf("\nDepartment List\n");
    printf("================\n");
    printf("%-20s %-15s\n", "Department Name", "Department Code");
    printf("-----------------------------------\n");

    while (fscanf(fp, "%s %s", deptName, deptCode) != EOF){
        printf("%-20s %-15s\n", deptName, deptCode);
    }

    fclose(fp);
    
}