#include <stdio.h>
#include "EmployeeData.h"

void enterEmployeeData(struct Employee emps[], struct Employee *emp, int totalEmployees) { 
  printf("\nEnter employee no (100000 - 999999): ");
  scanf("%d", &emp->empNo);
  while(emp->empNo < 100000 || emp->empNo >= 1000000 || 
  !empNoUnique(emps, emp->empNo, totalEmployees)) {
    printf("\nPlease enter valid employee no.!");
    printf("\nEnter employee no (100000 - 999999): ");
    scanf("%d", &emp->empNo);
  }
  printf("\nEnter employee first name: ");
  scanf("%s", emp->empFirstName);
  while(!correctFirstName(emp->empFirstName)) {
    printf("Please enter correct first name!\n");
    scanf("%s", emp->empFirstName);
  }
  printf("\nEnter employee last name: ");
  scanf("%s", emp->empLastName);
  while(!correctLastName(emp->empLastName)) {
    printf("Please enter correct last name!\n");
    scanf("%s", emp->empLastName);
  }
  printf("\nEnter employee hire day(dd): ");
  scanf("%d", &emp->hiredate.dd);
  printf("\nEnter employee month(mm): ");
  scanf("%d", &emp->hiredate.mm);
  printf("\nEnter employee year(yyyy): ");
  scanf("%d", &emp->hiredate.yy);
  while(!validDate(emp->hiredate.dd,
    emp->hiredate.mm, 
    emp->hiredate.yy)) {
    printf("\nPlease enter valid date!"); 
    printf("\nEnter employee hire day(dd): ");
    scanf("%d", &emp->hiredate.dd);
    printf("\nEnter employee month(mm): ");
    scanf("%d", &emp->hiredate.mm);
    printf("\nEnter employee year(yyyy): ");
    scanf("%d", &emp->hiredate.yy);
  }
  printf("\nEnter employee basic salary: ");
  scanf("%d", &emp->basicSalary);
  while(emp->basicSalary < 1000 || emp->basicSalary > 
    10000000) {
    printf("\nPlease enter valid salary!")  ;
    printf("\nEnter employee basic salary: ");
    scanf("%d", &emp->basicSalary);
  }
}

int calculateNetPay(int basicSalary) {
  float da, ta, pf;
  da = 0.4 * basicSalary;
  ta = 0.1 * basicSalary;
  pf = 0.05 * basicSalary;
  return basicSalary + da + ta - pf;
}

void showData(struct Employee emp) {
  printf("\nEmployee No: %d", emp.empNo);
  printf("\nEmployee Name: %s %s", emp.empFirstName, emp.empLastName);
  printf("\nEmployee hire date: %d/%d/%d", emp.hiredate.dd, emp.hiredate.mm, emp.hiredate.yy);
  printf("\nEmployee basic salary: %d", emp.basicSalary); 
  printf("\nEmployee net salary: %d \n", calculateNetPay(emp.basicSalary));
}

int correctLastName(char lastName[20]) {
  for (int i = 0; lastName[i] != '\0'; i++) {
    if (!((lastName[i] >= 65 && lastName[i] <= 90)
      || (lastName[i] >= 97 && lastName[i] <= 122)
      )) {
        return 0;
      } else if (lastName[i] == ' ') {
        return 0;
      }
  }
  return 1;
}

int correctFirstName(char firstName[20]) {
  for (int i = 0; firstName[i] != '\0'; i++) {
    if (!((firstName[i] >= 65 && firstName[i] <= 90)
      || (firstName[i] >= 97 && firstName[i] <= 122)
      )) {
        return 0;
      } else if (firstName[i] == ' ') {
        return 0;
      }
  }
  return 1;
}

int leapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0)
    || year % 400 == 0) {
      return 1;
    } return 0;
}

int validDate(int dd, int mm, int yy) {
  if (yy > 2023 || yy < 1983 || 
    mm < 1 || mm > 12) return 0;
  switch(mm) {
    case 1:
      if (dd < 1 || dd > 31) return 0;
      break;
    
    case 2:
      if (dd < 1 || dd > 29 && leapYear(yy)
        ) return 0;
      else if (dd < 1 || dd > 28) return 0;
      break;

    case 3:
      if (dd < 1 || dd > 31) return 0;
      break;

    case 4:
      if (dd < 1 || dd > 30) return 0;
      break;

    case 5:
      if (dd < 1 || dd > 31) return 0;
      break;

    case 6:
      if (dd < 1 || dd > 30) return 0;
      break;

    case 7:
      if (dd < 1 || dd > 31) return 0;
      break;

    case 8:
      if (dd < 1 || dd > 31) return 0;
      break;

    case 9:
      if (dd < 1 || dd > 30) return 0;
      break;

    case 10:
      if (dd < 1 || dd > 31) return 0;
      break;

    case 11:
      if (dd < 1 || dd > 30) return 0;
      break;

    case 12:
      if (dd < 1 || dd > 31) return 0;
      break;
  }
  return 1;
}

int empNoUnique(struct Employee emp[], int empNo, int totalEmployees) {
  for (int i = 0; i < totalEmployees; i++) {
      if (emp[i].empNo == empNo) {
        printf("\nEmployee no. already allotted.");
        return 0;
      }
  }
  return 1;
}