#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attendance.h"
#include "authentication.h"


void teachersChoice()
{
  int choice;
  while(1)
  {
    printf("1:Mark Attendance\n");
    printf("2:View Attendance\n");
    printf("3:View Attendance Summary\n");
    printf("4:LogOut\n");
    printf("Enter your Choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    addAttendance();
    break;
    case 2:
      displayAttendance();
      break;
    case 3:
      viewAttendanceSummary();
      break;
    case 4:
      printf("Logging out..\n");
      return;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}
