#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "attendance.h"
#include "authentication.h"


// Student Dashboard


int studentChoice()
{
  int choice;
  while (1)
  {
    printf("1:View My Attendance\n");
    printf("2:Logout\n");
    printf("Enter Your Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    viewMyAttendance();
      break;
    case 2:
     printf("Logging out..\n");
     return 0;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}
