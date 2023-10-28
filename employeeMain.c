#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void)
{
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int tableSize, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration

    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    // Example found
    if (matchPtr != NULL)

        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");


    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    //Example found
    if (matchPtr != NULL)
        printf("Employee with phone #(909-555-2134) is in the record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone #(909-555-2134) is NOT found in the record\n");


    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "111-000-1212");
    //Example not found
    if (matchPtr != NULL)
        printf("Employee with phone #111-000-1212 is in the record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with phone #111-000-1212 is NOT found in the record\n");


    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    //Example found
    if (matchPtr != NULL)
        printf("Employee with salary 8.32 is in the record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 8.32 is NOT found in the record\n");


    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.94);
    //Example not found
    if (matchPtr != NULL)
        printf("Employee with salary 6.94 is in the record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee with salary 6.94 is NOT found in the record\n");

    return EXIT_SUCCESS;
}