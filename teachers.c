#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.c"
#include "student.c"
#include "attendanceTeacher.c"
#include "attendanceStudent.c"


// Teachers Module

void displayMessageTeacher()
{
  displayName();
}

int teachersChoice(struct node *teacherhead)
{
  int choice;
  while (1)
  {
    printf("1: Generate QR\n");
    printf("2: View Attendance\n");
    printf("3: View Attendance Summary\n");
    printf("4:LogOut\n");
    printf("Enter your Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      generateQR();
      break;
    case 2:
      displayAttendance(teacherhead);
      break;
    case 3:
      viewAttendanceSummary(teacherhead);
      break;
    case 4:
      printf("Logging out..\n");
      return 0;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}
