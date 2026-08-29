Telephone Directory Maintenance System

======================================

A console-based C application for maintaining departments, employees, and telephone numbers using text files for storage.

Project Files

------------

FileFunctions.c - Program entry point and employee functions.
DeptMaint.c - Department maintenance functions.
TelDir.c - Telephone-number maintenance, main menu, and telephone enquiry functions.
FileFunctions.h - Function declarations shared by the source files.
emp.txt - Employee records.
dept.txt - Department records.

Requirements

------------

GCC compiler, such as MinGW on Windows.
A terminal opened in the project directory.

Compile and Run

--------------

Compile the source files into dbms.exe:

gcc -Wall -Wextra -std=c11 FileFunctions.c DeptMaint.c TelDir.c -o dbms.exe

Run the program:

.\dbms.exe

Remove the generated executable when finished:

Remove-Item dbms.exe

The program must be run from this directory so it can find emp.txt and dept.txt.

Login

-----

Enter an employee name listed in the first column of emp.txt. For example:

Sahaj

Main Menu

---------

After login, the application provides these operations:

1 - Add or display departments.
2 - Add or display employees.
3 - Allocate a telephone number to an employee.
4 - Search the directory by employee name or telephone number.
5 - Exit the application.

Data Format

-----------

Each employee record contains five or six space-separated fields:

EmployeeName EmployeeId DepartmentCode DepartmentName Location [TelephoneNumber]

Each department record contains two space-separated fields:

DepartmentName DepartmentCode

Names and locations should not contain spaces because the program reads each value as one field.
