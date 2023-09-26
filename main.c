#include <stdio.h>
#include <conio.h>
#include "EmployeeData.h"

int main() {
  printf("Welcome to Employee Management System!!!");
  printf("\nPlease enter employee details...");
  int totalEmployees = 0;
  struct Employee emps[1000];
  int itr = 0;
  int proceed = 1;
  for (int i = 0; proceed; i++) {
    enterEmployeeData(emps, &emps[i], totalEmployees);
    totalEmployees++;
    char yesno;
    printf("Do you want to add more employees ? (y/n)\n");
    scanf(" %c", &yesno);
    while(!(yesno == 'Y' || yesno == 'N'
      || yesno == 'n' || yesno == 'y')) {
       printf("\n Please enter valid input!!! \n");
       scanf(" %c", &yesno);
    }
    if (yesno == 'N' || yesno == 'n') {
      proceed = 0;
    }
  }

  printf("\nAll the employee details: \n");
  for (int i = 0; i < totalEmployees; i++) {
    showData(emps[i]);
  }
  return 0;
}