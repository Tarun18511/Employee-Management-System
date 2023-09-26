#include <stdio.h>

struct Employee {
  int empNo;
  char empFirstName[20];
  char empLastName[20];
  struct Date {
    int dd;
    int mm;
    int yy;
  } hiredate;
  int basicSalary;
};

void enterEmployeeData(struct Employee emps[], struct Employee *emp, int totalEmployees);
int calculateNetPay();
void showData(struct Employee emp);
int correctFirstName(char firstName[20]);
int correctLastName(char firstName[20]);
int leapYear(int year);
int validDate(int dd, int mm, int yy);
int empNoUnique(struct Employee emp[], int empNo, int totalEmployees);
