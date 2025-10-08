#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "authentication.c"
#include "teachers.c"
#include "attendanceTeacher.c"
#include "attendanceStudent.c"

void displayMessageStudent()
{
  displayName();
}

// Student Dashboard

int studentChoice(struct node *studenthead)
{
  int choice;
  while (1)
  {
    printf("1:Scan QR\n");
    printf("2:View My Attendance\n");
    printf("3:Logout\n");
    printf("Enter Your Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      scanQRCode();
      break;
    case 2:
      viewMyAttendance(studenthead);
      break;
    case 3:
      printf("Logging out..\n");
      return 0;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}